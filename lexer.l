%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"

int line = 1;
%}

%x COMMENT LINECOMMENT

%%

\n                  { line++; }
[ \t\r\v\f]+        { }

"//"                { BEGIN(LINECOMMENT); }
<LINECOMMENT>\n     { line++; BEGIN(INITIAL); }
<LINECOMMENT>.      { }

"/*"                { BEGIN(COMMENT); }
<COMMENT>"*/"       { BEGIN(INITIAL); }
<COMMENT>\n         { line++; }
<COMMENT>.          { }

^[ \t]*"#"[^\n]*    { return PREPROCESSOR; }

\"([^\\\"\n]|\\.)*\"   { yylval.sval = strdup(yytext); return STRING_LITERAL; }
L?\'([^\\\'\n]|\\.)*\' { yylval.sval = strdup(yytext); return CHAR_LITERAL; }

"auto"          { return AUTO; }
"break"         { return BREAK; }
"case"          { return CASE; }
"char"          { return CHAR_KW; }
"const"         { return CONST; }
"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"do"            { return DO; }
"double"        { return DOUBLE; }
"else"          { return ELSE; }
"enum"          { return ENUM; }
"extern"        { return EXTERN; }
"float"         { return FLOAT_KW; }
"for"           { return FOR; }
"goto"          { return GOTO; }
"if"            { return IF; }
"inline"        { return INLINE; }
"int"           { return INT; }
"long"          { return LONG; }
"register"      { return REGISTER; }
"restrict"      { return RESTRICT; }
"return"        { return RETURN; }
"short"         { return SHORT; }
"signed"        { return SIGNED; }
"sizeof"        { return SIZEOF; }
"static"        { return STATIC; }
"struct"        { return STRUCT; }
"switch"        { return SWITCH; }
"typedef"       { return TYPEDEF; }
"union"         { return UNION; }
"unsigned"      { return UNSIGNED; }
"void"          { return VOID; }
"volatile"      { return VOLATILE; }
"while"         { return WHILE; }
"bool"          { return BOOL; }
"true"          { return TRUE_KW; }
"false"         { return FALSE_KW; }
"NULL"          { return NULLVAL; }

0[xX][0-9a-fA-F]+  { yylval.ival = (int)strtol(yytext,NULL,16); return HEX_INT; }
0[0-7]+            { yylval.ival = (int)strtol(yytext,NULL,8);  return OCTAL_INT; }
0[bB][01]+         { yylval.ival = (int)strtol(yytext+2,NULL,2); return BINARY_INT; }
[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?[fFlL]? { yylval.fval = atof(yytext); return FLOAT_NUM; }
\.[0-9]+([eE][+-]?[0-9]+)?[fFlL]?       { yylval.fval = atof(yytext); return FLOAT_NUM; }
[0-9]+[eE][+-]?[0-9]+[fFlL]?            { yylval.fval = atof(yytext); return FLOAT_NUM; }
[0-9]+             { yylval.ival = atoi(yytext); return INTEGER; }

[A-Za-z_][A-Za-z0-9_]*  { yylval.sval = strdup(yytext); return IDENTIFIER; }

"<<="  { return LSHIFTEQ; }
">>="  { return RSHIFTEQ; }
"..."  { return ELLIPSIS; }
"->"   { return ARROW; }
"++"   { return INC; }
"--"   { return DEC; }
"<<"   { return LSHIFT; }
">>"   { return RSHIFT; }
"<="   { return LE; }
">="   { return GE; }
"=="   { return EQ; }
"!="   { return NEQ; }
"&&"   { return AND; }
"||"   { return OR; }
"+="   { return PLUSEQ; }
"-="   { return MINUSEQ; }
"*="   { return STAREQ; }
"/="   { return SLASHEQ; }
"%="   { return PERCENTEQ; }
"&="   { return AMPEQ; }
"^="   { return CARETEQ; }
"|="   { return PIPEEQ; }
"+"    { return PLUS; }
"-"    { return MINUS; }
"*"    { return STAR; }
"/"    { return SLASH; }
"%"    { return PERCENT; }
"="    { return ASSIGN; }
"<"    { return LT; }
">"    { return GT; }
"!"    { return NOT; }
"&"    { return AMP; }
"|"    { return PIPE; }
"^"    { return CARET; }
"~"    { return TILDE; }
"?"    { return QUESTION; }
";"    { return SEMICOLON; }
","    { return COMMA; }
"("    { return LPAREN; }
")"    { return RPAREN; }
"{"    { return LBRACE; }
"}"    { return RBRACE; }
"["    { return LBRACKET; }
"]"    { return RBRACKET; }
":"    { return COLON; }
"."    { return DOT_OP; }
"#"    { return HASH; }

.      { return UNKNOWN; }

%%

int yywrap(){ return 1; }