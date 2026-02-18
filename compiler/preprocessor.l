%{
#include <stdio.h>

FILE *yyin;
int line = 1;
int kw=0,id=0,num=0,str=0,chr=0,op=0,sym=0,err=0;
%}

%x COMMENT

%%

\n { line++; }
"//".* ;
"/*" { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>\n { line++; }
<COMMENT>. ;

\"([^\\\"\n]|(\\.))*\" { printf("Line %d : STRING : %s\n", line, yytext); str++; }
\'([^\\\'\n]|(\\.))\' { printf("Line %d : CHAR : %s\n", line, yytext); chr++; }

"int"|"float"|"char"|"double"|"void"|"if"|"else"|"for"|"while"|"return" { printf("Line %d : KEYWORD : %s\n", line, yytext); kw++; }

[0-9]+\.[0-9]+ { printf("Line %d : FLOAT : %s\n", line, yytext); num++; }
[0-9]+ { printf("Line %d : INTEGER : %s\n", line, yytext); num++; }

[A-Za-z_][A-Za-z0-9_]* { printf("Line %d : IDENTIFIER : %s\n", line, yytext); id++; }

"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"<"|">" { printf("Line %d : OPERATOR : %s\n", line, yytext); op++; }

";"|","|"("|")"|"{"|"}"|"["|"]" { printf("Line %d : SYMBOL : %s\n", line, yytext); sym++; }

[ \t]+ ;

. { printf("Line %d : UNKNOWN : %s\n", line, yytext); err++; }

%%

int main(){
    yyin = fopen("output.c","r");
    if(!yyin){ printf("Error opening input.c\n"); return 1; }

    printf("\n===== SmartC Lexical Analysis =====\n\n");
    yylex();

    printf("\n===== TOKEN SUMMARY =====\n");
    printf("Keywords     : %d\n", kw);
    printf("Identifiers  : %d\n", id);
    printf("Numbers      : %d\n", num);
    printf("Strings      : %d\n", str);
    printf("Characters   : %d\n", chr);
    printf("Operators    : %d\n", op);
    printf("Symbols      : %d\n", sym);
    printf("Unknown      : %d\n", err);

    fclose(yyin);
    return 0;
}

int yywrap(){ return 1; }

//instead of pi we should give value in     lexer open output.c     
