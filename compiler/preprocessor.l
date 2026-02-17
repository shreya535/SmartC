%{
#include <stdio.h>
#include <string.h>

FILE *yyin;
FILE *out;

char macro_name[50] = "";
char macro_value[200] = "";
%}

ID  [A-Za-z_][A-Za-z0-9_]*

%%

^#define[ \t]+{ID}[ \t]+.*    {
    sscanf(yytext, "#define %s %[^\n]", macro_name, macro_value);
}

{ID}    {
    if(strlen(macro_name) > 0 && strcmp(yytext, macro_name) == 0)
        fprintf(out, "%s", macro_value);
    else
        fprintf(out, "%s", yytext);
}

\n      { fprintf(out, "\n"); }
.       { fprintf(out, "%s", yytext); }

%%

int main() {
    yyin = fopen("../input.c", "r");
    out  = fopen("output.c", "w");

    if(!yyin || !out){
        printf("File error\n");
        return 1;
    }

    yylex();

    fclose(yyin);
    fclose(out);

    printf("Simple preprocessing done.\n");
    return 0;
}

int yywrap(){ return 1; }
