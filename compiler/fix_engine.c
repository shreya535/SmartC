#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fix_engine.h"

Error errors[MAX_ERRORS];

Fix   fixes[MAX_FIXES];
int   fix_count = 0;

char source_lines[MAX_LINES][MAX_LINE_LEN];
char fixed_lines[MAX_LINES][MAX_LINE_LEN];
int  total_lines = 0;

/* ── helpers ── */

void trim(char *s){
    int i = strlen(s) - 1;
    while(i >= 0 && (s[i]=='\n'||s[i]=='\r'||s[i]==' '||s[i]=='\t'))
        s[i--] = '\0';
}

int starts_with(const char *s, const char *prefix){
    return strncmp(s, prefix, strlen(prefix)) == 0;
}

int line_has(const char *line, const char *token){
    return strstr(line, token) != NULL;
}

void add_fix(int line_num, const char *desc, const char *fixed){
    if(fix_count >= MAX_FIXES) return;
    fixes[fix_count].line_num = line_num;
    strncpy(fixes[fix_count].description, desc, 255);
    strncpy(fixes[fix_count].fixed_line, fixed, MAX_LINE_LEN-1);
    fix_count++;
}

/* ── load source file ── */

void load_source(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){ printf("Cannot open %s\n", filename); return; }
    total_lines = 0;
    while(fgets(source_lines[total_lines], MAX_LINE_LEN, f)){
        strncpy(fixed_lines[total_lines],
                source_lines[total_lines], MAX_LINE_LEN-1);
        total_lines++;
        if(total_lines >= MAX_LINES) break;
    }
    fclose(f);
}

/* ── parse report.txt ── */

void load_errors(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){ printf("Cannot open %s\n", filename); return; }
    error_count = 0;
    char line[512];
    while(fgets(line, sizeof(line), f)){
        trim(line);
        if(starts_with(line, "ERROR at line") ||
           starts_with(line, "SYNTAX ERROR at line") ||
           starts_with(line, "WARNING at line")){
            int ln = 0;
            char type[64] = "";
            char desc[256] = "";
            if(starts_with(line, "SYNTAX ERROR")){
                sscanf(line, "SYNTAX ERROR at line %d: %255[^\n]", &ln, desc);
                strcpy(type, "SYNTAX");
            } else if(starts_with(line, "ERROR")){
                sscanf(line, "ERROR at line %d: %255[^\n]", &ln, desc);
                strcpy(type, "ERROR");
            } else {
                sscanf(line, "WARNING at line %d: %255[^\n]", &ln, desc);
                strcpy(type, "WARNING");
            }
            if(ln > 0 && error_count < MAX_ERRORS){
                errors[error_count].line_num = ln;
                strncpy(errors[error_count].type, type, 63);
                strncpy(errors[error_count].description, desc, 255);
                error_count++;
            }
        }
    }
    fclose(f);
}

/* ── fix rules ── */

/* Rule 1: missing semicolon */
void fix_missing_semicolon(int idx){
    int ln = errors[idx].line_num - 1;
    if(ln < 0 || ln >= total_lines) return;
    char *line = fixed_lines[ln];
    int len = strlen(line);
    /* trim trailing whitespace */
    int end = len - 1;
    while(end >= 0 && (line[end]=='\n'||line[end]=='\r'||
                        line[end]==' '||line[end]=='\t'))
        end--;
    if(end >= 0 && line[end] != ';' && line[end] != '{' &&
       line[end] != '}' && line[end] != ','){
        line[end+1] = ';';
        line[end+2] = '\n';
        line[end+3] = '\0';
        char desc[256];
        sprintf(desc, "Added missing semicolon at line %d",
                errors[idx].line_num);
        add_fix(errors[idx].line_num, desc, fixed_lines[ln]);
    }
}

/* Rule 2: undeclared variable — add declaration at top of block */
void fix_undeclared_variable(int idx){
    char varname[64] = "";
    char *desc = errors[idx].description;
    /* parse: "undeclared variable 'x'" */
    char *p = strstr(desc, "'");
    if(!p) return;
    p++;
    int i = 0;
    while(*p && *p != '\'' && i < 63) varname[i++] = *p++;
    varname[i] = '\0';
    if(strlen(varname) == 0) return;

    /* find nearest opening brace above error line */
    int ln = errors[idx].line_num - 2;
    int insert_at = -1;
    for(int j = ln; j >= 0; j--){
        if(strstr(fixed_lines[j], "{")){
            insert_at = j + 1;
            break;
        }
    }
    if(insert_at == -1) insert_at = 0;

    /* shift lines down to make room */
    if(total_lines < MAX_LINES - 1){
        for(int j = total_lines; j > insert_at; j--)
            strncpy(fixed_lines[j], fixed_lines[j-1], MAX_LINE_LEN-1);
        total_lines++;
    }

    /* insert declaration */
    char decl[MAX_LINE_LEN];
    sprintf(decl, "    int %s = 0; /* AUTO-FIXED: declared missing variable */\n",
            varname);
    strncpy(fixed_lines[insert_at], decl, MAX_LINE_LEN-1);

    char fixdesc[256];
    sprintf(fixdesc, "Declared missing variable '%s' as int", varname);
    add_fix(errors[idx].line_num, fixdesc, decl);
}

/* Rule 3: variable used before initialization */
void fix_uninitialized(int idx){
    char varname[64] = "";
    char *desc = errors[idx].description;
    char *p = strstr(desc, "'");
    if(!p) return;
    p++;
    int i = 0;
    while(*p && *p != '\'' && i < 63) varname[i++] = *p++;
    varname[i] = '\0';
    if(strlen(varname) == 0) return;

    /* find declaration of this variable and add = 0 */
    for(int j = 0; j < total_lines; j++){
        char *found = strstr(fixed_lines[j], varname);
        if(found && strstr(fixed_lines[j], "int") &&
           !strstr(fixed_lines[j], "=")){
            /* add = 0 initialization */
            char newline[MAX_LINE_LEN];
            char *semi = strstr(fixed_lines[j], ";");
            if(semi){
                *semi = '\0';
                sprintf(newline, "%s = 0; /* AUTO-FIXED: initialized */\n",
                        fixed_lines[j]);
                strncpy(fixed_lines[j], newline, MAX_LINE_LEN-1);
                char fixdesc[256];
                sprintf(fixdesc,
                    "Initialized variable '%s' to 0", varname);
                add_fix(j+1, fixdesc, fixed_lines[j]);
            }
            break;
        }
    }
}

/* Rule 4: missing return statement */
void fix_missing_return(int idx){
    int ln = errors[idx].line_num - 1;
    if(ln < 0 || ln >= total_lines) return;

    /* find closing brace of function */
    int brace = -1;
    for(int j = ln; j < total_lines; j++){
        if(strstr(fixed_lines[j], "}")){
            brace = j;
            break;
        }
    }
    if(brace == -1) return;

    /* insert return 0 before closing brace */
    if(total_lines < MAX_LINES - 1){
        for(int j = total_lines; j > brace; j--)
            strncpy(fixed_lines[j], fixed_lines[j-1], MAX_LINE_LEN-1);
        total_lines++;
    }
    strncpy(fixed_lines[brace],
            "    return 0; /* AUTO-FIXED: added missing return */\n",
            MAX_LINE_LEN-1);

    char fixdesc[256];
    sprintf(fixdesc, "Added missing return statement at line %d", ln+1);
    add_fix(ln+1, fixdesc, fixed_lines[brace]);
}

/* ── apply all fixes ── */

void apply_fixes(){
    for(int i = 0; i < error_count; i++){
        char *desc = errors[i].description;

        if(strstr(desc, "undeclared variable")){
            fix_undeclared_variable(i);
        }
        else if(strstr(desc, "used before initialization")){
            fix_uninitialized(i);
        }
        else if(strstr(desc, "missing return")){
            fix_missing_return(i);
        }
        else if(strstr(errors[i].type, "SYNTAX")){
            fix_missing_semicolon(i);
        }
    }
}

/* ── write fixed output ── */

void write_output(const char *filename){
    FILE *f = fopen(filename, "w");
    if(!f){ printf("Cannot create %s\n", filename); return; }
    for(int i = 0; i < total_lines; i++)
        fputs(fixed_lines[i], f);
    fclose(f);
}

/* ── print fix report ── */

void fix_engine_print_report(){
    printf("\n==============================================\n");
    printf("           FIX ENGINE REPORT\n");
    printf("==============================================\n");
    if(fix_count == 0){
        printf("  No automatic fixes applied.\n");
    } else {
        for(int i = 0; i < fix_count; i++){
            printf("  Fix %d (line %d): %s\n",
                   i+1, fixes[i].line_num,
                   fixes[i].description);
        }
    }
    printf("  Total fixes : %d\n", fix_count);
    printf("==============================================\n");
}

/* ── main entry point ── */

void fix_engine_run(const char *source_file,
                    const char *report_file,
                    const char *output_file){
    load_source(source_file);
    load_errors(report_file);
    apply_fixes();
    write_output(output_file);
    fix_engine_print_report();
}