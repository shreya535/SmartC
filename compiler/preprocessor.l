%{
#include <stdio.h>
#include <string.h>

FILE *yyin;
FILE *out;

#define MAX_MACROS 100

char macro_names[MAX_MACROS][50];
char macro_values[MAX_MACROS][200];
int macro_count = 0;

int find_macro(char *id){
    int i;
    for(i=0;i<macro_count;i++){
        if(strcmp(id, macro_names[i])==0)
            return i;
    }
    return -1;
}
%}

%x COMMENT STRING CHARLIT

ID  [A-Za-z_][A-Za-z0-9_]*

%%

^[ \t]*#define[ \t]+{ID}[ \t]+.* {
    if(macro_count < MAX_MACROS){
        sscanf(yytext, "#define %s %[^\n]",
               macro_names[macro_count],
               macro_values[macro_count]);
        macro_count++;
    }
}

"//".*        { fprintf(out,"%s",yytext); }
"/*"          { BEGIN(COMMENT); fprintf(out,"/*"); }
<COMMENT>"*/" { BEGIN(INITIAL); fprintf(out,"*/"); }
<COMMENT>\n   { fprintf(out,"\n"); }
<COMMENT>.    { fprintf(out,"%s",yytext); }

\"            { BEGIN(STRING); fprintf(out,"\""); }
<STRING>\"    { BEGIN(INITIAL); fprintf(out,"\""); }
<STRING>\n    { fprintf(out,"\n"); }
<STRING>.     { fprintf(out,"%s",yytext); }

\'            { BEGIN(CHARLIT); fprintf(out,"\'"); }
<CHARLIT>\'   { BEGIN(INITIAL); fprintf(out,"\'"); }
<CHARLIT>\n   { fprintf(out,"\n"); }
<CHARLIT>.    { fprintf(out,"%s",yytext); }

{ID} {
    int idx = find_macro(yytext);
    if(idx!=-1)
        fprintf(out,"%s", macro_values[idx]);
    else
        fprintf(out,"%s", yytext);
}

\n { fprintf(out,"\n"); }
.  { fprintf(out,"%s",yytext); }

%%
int main() {

    yyin = fopen("input.c", "r");
    if(!yyin){
        perror("Cannot open input.c");
        return 1;
    }

    out = fopen("output.c", "w");
    if(!out){
        perror("Cannot create output.c");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);

    printf(" Preprocessing complete. Check output.c\n");
    return 0;
}
