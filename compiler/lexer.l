%{
#include <stdio.h>

int line = 1;
int kw=0,id=0,num=0,op=0,sym=0,unk=0;
%}

%%

\n { line++; }

"int"|"float"|"if"|"while"|"return"     { printf("Line %d : KEYWORD : %s\n", line, yytext); kw++; }

[0-9]+                                  { printf("Line %d : NUMBER : %s\n", line, yytext); num++; }

[a-zA-Z_][a-zA-Z0-9_]*                  { printf("Line %d : IDENTIFIER : %s\n", line, yytext); id++; }

[+\-*/=<>]                              { printf("Line %d : OPERATOR : %s\n", line, yytext); op++; }

[;(){}]                                 { printf("Line %d : SYMBOL : %s\n", line, yytext); sym++; }

[ \t]+                                  ;

.                                       { printf("Line %d : UNKNOWN TOKEN : %s\n", line, yytext); unk++; }

%%

int main()
{
    printf("----- TOKEN OUTPUT -----\n\n");
    yylex();

    printf("\n----- SUMMARY -----\n");
    printf("Keywords    : %d\n", kw);
    printf("Identifiers : %d\n", id);
    printf("Numbers     : %d\n", num);
    printf("Operators   : %d\n", op);
    printf("Symbols     : %d\n", sym);
    printf("Unknown     : %d\n", unk);

    return 0;
}
