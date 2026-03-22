%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *yyin;
FILE *out;

#define MAX_MACROS 500

char names[MAX_MACROS][64];
char values[MAX_MACROS][512];
int count = 0;
int line = 1;
int skipping = 0;

#define MAX_STACK 64
int ifdef_stack[MAX_STACK];
int ifdef_top = 0;

int find_macro(char *id){
    for(int i=0;i<count;i++)
        if(strcmp(id,names[i])==0) return i;
    return -1;
}

void expand(char *text){
    int idx = find_macro(text);
    if(idx==-1){ fprintf(out,"%s",text); return; }
    if(strcmp(values[idx],text)==0){ fprintf(out,"%s",text); return; }
    char *p = values[idx];
    char word[256];
    int wi=0;
    while(*p){
        if((*p>='A'&&*p<='Z')||(*p>='a'&&*p<='z')||(*p>='0'&&*p<='9')||*p=='_'){
            word[wi++]=*p++;
        } else {
            if(wi){ word[wi]='\0'; wi=0; expand(word); }
            fputc(*p++,out);
        }
    }
    if(wi){ word[wi]='\0'; expand(word); }
}

void define_macro(char *text){
    char n[64]={0};
    char v[512]={0};
    char *p = strstr(text,"define");
    if(!p) return;
    p+=6;
    while(*p==' '||*p=='\t') p++;
    int i=0;
    while(*p && *p!=' ' && *p!='\t') n[i++]=*p++;
    n[i]='\0';
    while(*p==' '||*p=='\t') p++;
    strncpy(v,p,511);
    int len=strlen(v);
    while(len>0&&(v[len-1]=='\n'||v[len-1]=='\r'||v[len-1]==' ')) v[--len]='\0';
    int idx=find_macro(n);
    if(idx==-1&&count<MAX_MACROS) idx=count++;
    strcpy(names[idx],n);
    strcpy(values[idx],v);
}
%}

%x COMMENT STRING_LIT CHARLIT

%%

\n      { line++; if(!skipping) fprintf(out,"\n"); }

"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"       { BEGIN(INITIAL); }
<COMMENT>\n         { line++; if(!skipping) fprintf(out,"\n"); }
<COMMENT>.          { }

"//"[^\n]*          { }

^[ \t]*"#"[ \t]*"define"[^\n]* {
    if(!skipping) define_macro(yytext);
}

^[ \t]*"#"[ \t]*"undef"[ \t]+[A-Za-z_][A-Za-z0-9_]* {
    if(!skipping){
        char n[64]={0};
        char *p=strstr(yytext,"undef");
        if(p){ p+=5; while(*p==' '||*p=='\t') p++; strncpy(n,p,63); }
        int idx=find_macro(n);
        if(idx!=-1){
            for(int i=idx;i<count-1;i++){
                strcpy(names[i],names[i+1]);
                strcpy(values[i],values[i+1]);
            }
            count--;
        }
    }
}

^[ \t]*"#"[ \t]*"ifdef"[ \t]+[A-Za-z_][A-Za-z0-9_]* {
    if(ifdef_top<MAX_STACK){
        char n[64]={0};
        char *p=strstr(yytext,"ifdef");
        if(p){ p+=5; while(*p==' '||*p=='\t') p++; strncpy(n,p,63); }
        ifdef_stack[ifdef_top++]=skipping;
        if(find_macro(n)==-1) skipping=1;
    }
}

^[ \t]*"#"[ \t]*"ifndef"[ \t]+[A-Za-z_][A-Za-z0-9_]* {
    if(ifdef_top<MAX_STACK){
        char n[64]={0};
        char *p=strstr(yytext,"ifndef");
        if(p){ p+=6; while(*p==' '||*p=='\t') p++; strncpy(n,p,63); }
        ifdef_stack[ifdef_top++]=skipping;
        if(find_macro(n)!=-1) skipping=1;
    }
}

^[ \t]*"#"[ \t]*"if"[^\n]* {
    if(ifdef_top<MAX_STACK)
        ifdef_stack[ifdef_top++]=skipping;
}

^[ \t]*"#"[ \t]*"elif"[^\n]*   { }

^[ \t]*"#"[ \t]*"else"[^\n]* {
    if(ifdef_top>0) skipping=!skipping;
}

^[ \t]*"#"[ \t]*"endif"[^\n]* {
    if(ifdef_top>0) skipping=ifdef_stack[--ifdef_top];
}

^[ \t]*"#"[ \t]*"include"[^\n]* {
    if(!skipping) fprintf(out,"/* %s */\n",yytext);
}

^[ \t]*"#"[ \t]*"pragma"[^\n]* {
    if(!skipping) fprintf(out,"/* %s */\n",yytext);
}

^[ \t]*"#"[ \t]*"error"[^\n]* {
    if(!skipping) fprintf(stderr,"Error: %s\n",yytext);
}

^[ \t]*"#"[ \t]*"warning"[^\n]* {
    if(!skipping) fprintf(stderr,"Warning: %s\n",yytext);
}

^[ \t]*"#"[ \t]*"line"[^\n]* {
    if(!skipping) fprintf(out,"/* %s */\n",yytext);
}

\"                  { BEGIN(STRING_LIT); if(!skipping) fputc('"',out); }
<STRING_LIT>\"      { BEGIN(INITIAL);   if(!skipping) fputc('"',out); }
<STRING_LIT>\\.     { if(!skipping) fprintf(out,"%s",yytext); }
<STRING_LIT>\n      { line++; if(!skipping) fputc('\n',out); }
<STRING_LIT>.       { if(!skipping) fputc(yytext[0],out); }

\'                  { BEGIN(CHARLIT); if(!skipping) fputc('\'',out); }
<CHARLIT>\'         { BEGIN(INITIAL); if(!skipping) fputc('\'',out); }
<CHARLIT>\\.        { if(!skipping) fprintf(out,"%s",yytext); }
<CHARLIT>.          { if(!skipping) fputc(yytext[0],out); }

"__LINE__"  { if(!skipping) fprintf(out,"%d",line); }
"__FILE__"  { if(!skipping) fprintf(out,"\"input.c\""); }

[A-Za-z_][A-Za-z0-9_]*  { if(!skipping) expand(yytext); }

\\\n        { line++; }

[ \t]+      { if(!skipping) fprintf(out,"%s",yytext); }
.           { if(!skipping) fputc(yytext[0],out); }

%%

int main(int argc, char **argv){
    const char *infile  = (argc>1) ? argv[1] : "input.c";
    const char *outfile = (argc>2) ? argv[2] : "output.c";

    yyin = fopen(infile,"r");
    if(!yyin){ perror("Cannot open input"); return 1; }

    out = fopen(outfile,"w");
    if(!out){ perror("Cannot create output"); return 1; }

    printf("Running SmartC Preprocessor...\n");
    yylex();
    fclose(yyin);
    fclose(out);
    printf("Done. Output -> %s\n",outfile);
    return 0;
}

int yywrap(){ return 1; }