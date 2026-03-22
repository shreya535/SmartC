%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

extern int  yylex();
extern int  line;
extern FILE *yyin;

void yyerror(const char *s);

int   error_count   = 0;
int   warning_count = 0;
FILE *report;

char current_type[32] = "";

void report_error(const char *msg){
    fprintf(stderr, "ERROR   line %d: %s\n", line, msg);
    if(report) fprintf(report, "ERROR at line %d: %s\n", line, msg);
    error_count++;
}

void report_warning(const char *msg){
    fprintf(stderr, "WARNING line %d: %s\n", line, msg);
    if(report) fprintf(report, "WARNING at line %d: %s\n", line, msg);
    warning_count++;
}
%}

%union {
    int   ival;
    float fval;
    char *sval;
}

%token <sval> IDENTIFIER STRING_LITERAL CHAR_LITERAL
%token <ival> INTEGER HEX_INT OCTAL_INT BINARY_INT
%token <fval> FLOAT_NUM

%token AUTO BREAK CASE CHAR_KW CONST CONTINUE DEFAULT DO
%token DOUBLE ELSE ENUM EXTERN FLOAT_KW FOR GOTO IF
%token INLINE INT LONG REGISTER RESTRICT RETURN SHORT
%token SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION
%token UNSIGNED VOID VOLATILE WHILE
%token BOOL TRUE_KW FALSE_KW NULLVAL

%token PLUS MINUS STAR SLASH PERCENT
%token ASSIGN EQ NEQ LT GT LE GE
%token AND OR NOT AMP PIPE CARET TILDE
%token LSHIFT RSHIFT
%token PLUSEQ MINUSEQ STAREQ SLASHEQ PERCENTEQ
%token AMPEQ PIPEEQ CARETEQ LSHIFTEQ RSHIFTEQ
%token INC DEC ARROW DOT_OP ELLIPSIS QUESTION
%token COLON SEMICOLON COMMA HASH DHASH
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token PREPROCESSOR UNKNOWN

%right ASSIGN PLUSEQ MINUSEQ STAREQ SLASHEQ PERCENTEQ
%right AMPEQ PIPEEQ CARETEQ LSHIFTEQ RSHIFTEQ
%right QUESTION COLON
%left  OR
%left  AND
%left  PIPE
%left  CARET
%left  AMP
%left  EQ NEQ
%left  LT GT LE GE
%left  LSHIFT RSHIFT
%left  PLUS MINUS
%left  STAR SLASH PERCENT
%right NOT TILDE INC DEC
%left  ARROW DOT_OP

%type <sval> declarator direct_declarator
%type <sval> unary_expression postfix_expression
%type <sval> primary_expression
%type <sval> assignment_expression
%type <sval> conditional_expression

%start translation_unit

%%

translation_unit
    : external_declaration
    | translation_unit external_declaration
    ;

external_declaration
    : function_definition
    | declaration
    | PREPROCESSOR
    | error SEMICOLON
    | error RBRACE
    ;

function_definition
    : declaration_specifiers declarator LBRACE RBRACE
        { if($2) sym_declare($2, current_type, line, 1); }
    | declaration_specifiers declarator LBRACE block_item_list RBRACE
        { if($2) sym_declare($2, current_type, line, 1); }
    ;

declaration
    : declaration_specifiers SEMICOLON
    | declaration_specifiers init_declarator_list SEMICOLON
    | typedef_decl
    | struct_decl_stmt
    | enum_decl_stmt
    | IDENTIFIER IDENTIFIER SEMICOLON
        { sym_declare($2, $1, line, 0); }
    | IDENTIFIER IDENTIFIER ASSIGN initializer SEMICOLON
        { sym_declare($2, $1, line, 1); }
    | IDENTIFIER STAR IDENTIFIER SEMICOLON
        { sym_declare($3, $1, line, 0); }
    ;

typedef_decl
    : TYPEDEF declaration_specifiers IDENTIFIER SEMICOLON
        { sym_declare($3, "typedef", line, 1); }
    | TYPEDEF struct_or_union_specifier IDENTIFIER SEMICOLON
        { sym_declare($3, "typedef", line, 1); }
    | TYPEDEF enum_specifier IDENTIFIER SEMICOLON
        { sym_declare($3, "typedef", line, 1); }
    | TYPEDEF struct_or_union_specifier declarator SEMICOLON
        { if($3) sym_declare($3, "typedef", line, 1); }
    | TYPEDEF declaration_specifiers declarator SEMICOLON
        { if($3) sym_declare($3, "typedef", line, 1); }
    ;

struct_decl_stmt
    : struct_or_union_specifier SEMICOLON
    | struct_or_union_specifier IDENTIFIER SEMICOLON
    ;

enum_decl_stmt
    : enum_specifier SEMICOLON
    | enum_specifier IDENTIFIER SEMICOLON
        { sym_declare($2, "enum", line, 0); }
    | ENUM IDENTIFIER IDENTIFIER SEMICOLON
        { sym_declare($3, "enum", line, 0); }
    | ENUM IDENTIFIER IDENTIFIER ASSIGN assignment_expression SEMICOLON
        { sym_declare($3, "enum", line, 1); }
    ;

init_declarator_list
    : init_declarator
    | init_declarator_list COMMA init_declarator
    ;

init_declarator
    : declarator
        {
            if($1 && strlen($1) > 0){
                if(!sym_declare($1, current_type, line, 0)){
                    char msg[128];
                    sprintf(msg, "variable '%s' already declared in this scope", $1);
                    report_error(msg);
                }
            }
        }
    | declarator ASSIGN initializer
        {
            if($1 && strlen($1) > 0){
                if(!sym_declare($1, current_type, line, 1)){
                    char msg[128];
                    sprintf(msg, "variable '%s' already declared in this scope", $1);
                    report_error(msg);
                } else {
                    sym_mark_initialized($1);
                }
            }
        }
    ;

initializer
    : assignment_expression
    | LBRACE initializer_list RBRACE
    | LBRACE initializer_list COMMA RBRACE
    ;

initializer_list
    : initializer
    | initializer_list COMMA initializer
    ;

declaration_specifiers
    : type_specifier
    | type_qualifier
    | storage_class_specifier
    | declaration_specifiers type_specifier
    | declaration_specifiers type_qualifier
    | declaration_specifiers storage_class_specifier
    ;

storage_class_specifier
    : AUTO | REGISTER | STATIC | EXTERN | TYPEDEF
    ;

type_qualifier
    : CONST | VOLATILE | RESTRICT
    ;

type_specifier
    : INT          { strcpy(current_type, "int");      }
    | CHAR_KW      { strcpy(current_type, "char");     }
    | FLOAT_KW     { strcpy(current_type, "float");    }
    | DOUBLE       { strcpy(current_type, "double");   }
    | VOID         { strcpy(current_type, "void");     }
    | SHORT        { strcpy(current_type, "short");    }
    | LONG         { strcpy(current_type, "long");     }
    | SIGNED       { strcpy(current_type, "signed");   }
    | UNSIGNED     { strcpy(current_type, "unsigned"); }
    | BOOL         { strcpy(current_type, "bool");     }
    | INLINE       { strcpy(current_type, "inline");   }
    | struct_or_union_specifier { strcpy(current_type, "struct"); }
    | enum_specifier            { strcpy(current_type, "enum");   }
    ;

struct_or_union_specifier
    : STRUCT IDENTIFIER LBRACE struct_declaration_list RBRACE
    | STRUCT LBRACE struct_declaration_list RBRACE
    | STRUCT IDENTIFIER
    | UNION IDENTIFIER LBRACE struct_declaration_list RBRACE
    | UNION LBRACE struct_declaration_list RBRACE
    | UNION IDENTIFIER
    ;

struct_declaration_list
    : struct_member
    | struct_declaration_list struct_member
    ;

struct_member
    : declaration_specifiers struct_declarator_list SEMICOLON
    | declaration_specifiers SEMICOLON
    | error SEMICOLON
    ;

struct_declarator_list
    : struct_declarator
    | struct_declarator_list COMMA struct_declarator
    ;

struct_declarator
    : declarator
    | declarator COLON constant_expression
    | COLON constant_expression
    ;

enum_specifier
    : ENUM IDENTIFIER LBRACE enumerator_list RBRACE
    | ENUM LBRACE enumerator_list RBRACE
    | ENUM IDENTIFIER LBRACE enumerator_list COMMA RBRACE
    | ENUM LBRACE enumerator_list COMMA RBRACE
    | ENUM IDENTIFIER
    ;

enumerator_list
    : enumerator
    | enumerator_list COMMA enumerator
    ;

enumerator
    : IDENTIFIER
        { sym_declare($1, "enum_const", line, 1); }
    | IDENTIFIER ASSIGN constant_expression
        { sym_declare($1, "enum_const", line, 1); }
    ;

declarator
    : direct_declarator          { $$ = $1; }
    | pointer direct_declarator  { $$ = $2; }
    ;

direct_declarator
    : IDENTIFIER
        { $$ = $1; }
    | LPAREN declarator RPAREN
        { $$ = $2; }
    | direct_declarator LBRACKET RBRACKET
        { $$ = $1; }
    | direct_declarator LBRACKET INTEGER RBRACKET
        { $$ = $1; }
    | direct_declarator LBRACKET IDENTIFIER RBRACKET
        { $$ = $1; }
    | direct_declarator LBRACKET HEX_INT RBRACKET
        { $$ = $1; }
    | direct_declarator LBRACKET OCTAL_INT RBRACKET
        { $$ = $1; }
    | direct_declarator LPAREN parameter_list RPAREN
        { $$ = $1; }
    | direct_declarator LPAREN RPAREN
        { $$ = $1; }
    ;

pointer
    : STAR
    | STAR type_qualifier_list
    | STAR pointer
    | STAR type_qualifier_list pointer
    ;

type_qualifier_list
    : type_qualifier
    | type_qualifier_list type_qualifier
    ;

parameter_list
    : parameter_declaration
    | parameter_list COMMA parameter_declaration
    | parameter_list COMMA ELLIPSIS
    ;

parameter_declaration
    : declaration_specifiers declarator
        {
            if($2 && strlen($2) > 0)
                sym_declare($2, current_type, line, 1);
        }
    | declaration_specifiers
    | declaration_specifiers abstract_declarator
    ;

abstract_declarator
    : pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator
    : LPAREN abstract_declarator RPAREN
    | LBRACKET RBRACKET
    | LBRACKET INTEGER RBRACKET
    | LPAREN RPAREN
    | LPAREN parameter_list RPAREN
    | direct_abstract_declarator LBRACKET RBRACKET
    | direct_abstract_declarator LBRACKET INTEGER RBRACKET
    | direct_abstract_declarator LPAREN RPAREN
    | direct_abstract_declarator LPAREN parameter_list RPAREN
    ;

compound_statement
    : LBRACE RBRACE
    | LBRACE block_item_list RBRACE
    ;

block_item_list
    : block_item
    | block_item_list block_item
    ;

block_item
    : declaration
    | statement
    ;

statement
    : expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | labeled_statement
    ;

labeled_statement
    : IDENTIFIER COLON statement
    | CASE constant_expression COLON statement
    | DEFAULT COLON statement
    ;

expression_statement
    : SEMICOLON
    | expression SEMICOLON
    ;

selection_statement
    : IF LPAREN expression RPAREN statement
    | IF LPAREN expression RPAREN statement ELSE statement
    | SWITCH LPAREN expression RPAREN statement
    ;

iteration_statement
    : WHILE LPAREN expression RPAREN statement
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON
    | FOR LPAREN expression_statement expression_statement RPAREN statement
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement
    | FOR LPAREN declaration expression_statement RPAREN statement
    | FOR LPAREN declaration expression_statement expression RPAREN statement
    ;

jump_statement
    : GOTO IDENTIFIER SEMICOLON
    | CONTINUE SEMICOLON
    | BREAK SEMICOLON
    | RETURN SEMICOLON
    | RETURN expression SEMICOLON
    ;

expression
    : assignment_expression
    | expression COMMA assignment_expression
    ;

assignment_expression
    : conditional_expression
        { $$ = $1; }
    | unary_expression ASSIGN assignment_expression
        { if($1) sym_mark_initialized($1); $$ = $1; }
    | unary_expression PLUSEQ assignment_expression
        { $$ = NULL; }
    | unary_expression MINUSEQ assignment_expression
        { $$ = NULL; }
    | unary_expression STAREQ assignment_expression
        { $$ = NULL; }
    | unary_expression SLASHEQ assignment_expression
        { $$ = NULL; }
    | unary_expression PERCENTEQ assignment_expression
        { $$ = NULL; }
    | unary_expression AMPEQ assignment_expression
        { $$ = NULL; }
    | unary_expression PIPEEQ assignment_expression
        { $$ = NULL; }
    | unary_expression CARETEQ assignment_expression
        { $$ = NULL; }
    | unary_expression LSHIFTEQ assignment_expression
        { $$ = NULL; }
    | unary_expression RSHIFTEQ assignment_expression
        { $$ = NULL; }
    ;

conditional_expression
    : logical_or_expression
        { $$ = NULL; }
    | logical_or_expression QUESTION expression COLON conditional_expression
        { $$ = NULL; }
    ;

constant_expression
    : conditional_expression
    ;

logical_or_expression
    : logical_and_expression
    | logical_or_expression OR logical_and_expression
    ;

logical_and_expression
    : inclusive_or_expression
    | logical_and_expression AND inclusive_or_expression
    ;

inclusive_or_expression
    : exclusive_or_expression
    | inclusive_or_expression PIPE exclusive_or_expression
    ;

exclusive_or_expression
    : and_expression
    | exclusive_or_expression CARET and_expression
    ;

and_expression
    : equality_expression
    | and_expression AMP equality_expression
    ;

equality_expression
    : relational_expression
    | equality_expression EQ relational_expression
    | equality_expression NEQ relational_expression
    ;

relational_expression
    : shift_expression
    | relational_expression LT shift_expression
    | relational_expression GT shift_expression
    | relational_expression LE shift_expression
    | relational_expression GE shift_expression
    ;

shift_expression
    : additive_expression
    | shift_expression LSHIFT additive_expression
    | shift_expression RSHIFT additive_expression
    ;

additive_expression
    : multiplicative_expression
    | additive_expression PLUS multiplicative_expression
    | additive_expression MINUS multiplicative_expression
    ;

multiplicative_expression
    : cast_expression
    | multiplicative_expression STAR cast_expression
    | multiplicative_expression SLASH cast_expression
    | multiplicative_expression PERCENT cast_expression
    ;

cast_expression
    : unary_expression
    | LPAREN type_specifier RPAREN cast_expression
    | LPAREN type_specifier pointer RPAREN cast_expression
    ;

unary_expression
    : postfix_expression        { $$ = $1; }
    | INC unary_expression      { $$ = $2; }
    | DEC unary_expression      { $$ = $2; }
    | STAR cast_expression      { $$ = NULL; }
    | AMP cast_expression       { $$ = NULL; }
    | PLUS cast_expression      { $$ = NULL; }
    | MINUS cast_expression     { $$ = NULL; }
    | NOT cast_expression       { $$ = NULL; }
    | TILDE cast_expression     { $$ = NULL; }
    | SIZEOF unary_expression   { $$ = NULL; }
    | SIZEOF LPAREN type_specifier RPAREN { $$ = NULL; }
    ;

postfix_expression
    : primary_expression
        { $$ = $1; }
    | postfix_expression LBRACKET expression RBRACKET
        { $$ = NULL; }
    | postfix_expression LPAREN RPAREN
        { $$ = NULL; }
    | postfix_expression LPAREN argument_expression_list RPAREN
        { $$ = NULL; }
    | postfix_expression DOT_OP IDENTIFIER
        { $$ = NULL; }
    | postfix_expression ARROW IDENTIFIER
        { $$ = NULL; }
    | postfix_expression INC
        { $$ = NULL; }
    | postfix_expression DEC
        { $$ = NULL; }
    ;

argument_expression_list
    : assignment_expression
    | argument_expression_list COMMA assignment_expression
    ;

primary_expression
    : IDENTIFIER
        {
            int idx = sym_lookup($1);
            if(idx == -1){
                char msg[128];
                sprintf(msg, "undeclared variable '%s'", $1);
                report_error(msg);
                $$ = NULL;
            } else {
                sym_mark_used($1);
                if(!table[idx].initialized &&
                   strcmp(table[idx].type,"builtin")    != 0 &&
                   strcmp(table[idx].type,"typedef")    != 0 &&
                   strcmp(table[idx].type,"enum_const") != 0 &&
                   strcmp(table[idx].type,"enum")       != 0 &&
                   strcmp(table[idx].type,"int")        != 0){
                    char msg[128];
                    sprintf(msg, "variable '%s' used before initialization", $1);
                    report_warning(msg);
                }
                $$ = $1;
            }
        }
    | INTEGER        { $$ = NULL; }
    | HEX_INT        { $$ = NULL; }
    | OCTAL_INT      { $$ = NULL; }
    | BINARY_INT     { $$ = NULL; }
    | FLOAT_NUM      { $$ = NULL; }
    | STRING_LITERAL { $$ = NULL; }
    | CHAR_LITERAL   { $$ = NULL; }
    | TRUE_KW        { $$ = NULL; }
    | FALSE_KW       { $$ = NULL; }
    | NULLVAL        { $$ = NULL; }
    | LPAREN expression RPAREN { $$ = NULL; }
    ;

%%

void yyerror(const char *s){
    fprintf(stderr, "SYNTAX ERROR at line %d: %s\n", line, s);
    if(report)
        fprintf(report, "SYNTAX ERROR at line %d: %s\n", line, s);
    error_count++;
}

int main(int argc, char **argv){
    const char *infile = (argc > 1) ? argv[1] : "output.c";
    yyin = fopen(infile, "r");
    if(!yyin){ printf("Error opening %s\n", infile); return 1; }
    report = fopen("report.txt", "w");
    if(!report){ printf("Error creating report.txt\n"); return 1; }
    sym_init();
    printf("\n==============================================\n");
    printf("   SmartC - Parser + Semantic Analysis\n");
    printf("==============================================\n");
    yyparse();
    sym_print();
    sym_check_unused(report);
    printf("\n==============================================\n");
    printf("  Errors   : %d\n", error_count);
    printf("  Warnings : %d\n", warning_count);
    printf("==============================================\n");
    printf("Report saved to report.txt\n");
    fclose(yyin);
    fclose(report);
    return 0;
}
