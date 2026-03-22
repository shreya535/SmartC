/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING_LITERAL = 259,          /* STRING_LITERAL  */
    CHAR_LITERAL = 260,            /* CHAR_LITERAL  */
    INTEGER = 261,                 /* INTEGER  */
    HEX_INT = 262,                 /* HEX_INT  */
    OCTAL_INT = 263,               /* OCTAL_INT  */
    BINARY_INT = 264,              /* BINARY_INT  */
    FLOAT_NUM = 265,               /* FLOAT_NUM  */
    AUTO = 266,                    /* AUTO  */
    BREAK = 267,                   /* BREAK  */
    CASE = 268,                    /* CASE  */
    CHAR_KW = 269,                 /* CHAR_KW  */
    CONST = 270,                   /* CONST  */
    CONTINUE = 271,                /* CONTINUE  */
    DEFAULT = 272,                 /* DEFAULT  */
    DO = 273,                      /* DO  */
    DOUBLE = 274,                  /* DOUBLE  */
    ELSE = 275,                    /* ELSE  */
    ENUM = 276,                    /* ENUM  */
    EXTERN = 277,                  /* EXTERN  */
    FLOAT_KW = 278,                /* FLOAT_KW  */
    FOR = 279,                     /* FOR  */
    GOTO = 280,                    /* GOTO  */
    IF = 281,                      /* IF  */
    INLINE = 282,                  /* INLINE  */
    INT = 283,                     /* INT  */
    LONG = 284,                    /* LONG  */
    REGISTER = 285,                /* REGISTER  */
    RESTRICT = 286,                /* RESTRICT  */
    RETURN = 287,                  /* RETURN  */
    SHORT = 288,                   /* SHORT  */
    SIGNED = 289,                  /* SIGNED  */
    SIZEOF = 290,                  /* SIZEOF  */
    STATIC = 291,                  /* STATIC  */
    STRUCT = 292,                  /* STRUCT  */
    SWITCH = 293,                  /* SWITCH  */
    TYPEDEF = 294,                 /* TYPEDEF  */
    UNION = 295,                   /* UNION  */
    UNSIGNED = 296,                /* UNSIGNED  */
    VOID = 297,                    /* VOID  */
    VOLATILE = 298,                /* VOLATILE  */
    WHILE = 299,                   /* WHILE  */
    BOOL = 300,                    /* BOOL  */
    TRUE_KW = 301,                 /* TRUE_KW  */
    FALSE_KW = 302,                /* FALSE_KW  */
    NULLVAL = 303,                 /* NULLVAL  */
    PLUS = 304,                    /* PLUS  */
    MINUS = 305,                   /* MINUS  */
    STAR = 306,                    /* STAR  */
    SLASH = 307,                   /* SLASH  */
    PERCENT = 308,                 /* PERCENT  */
    ASSIGN = 309,                  /* ASSIGN  */
    EQ = 310,                      /* EQ  */
    NEQ = 311,                     /* NEQ  */
    LT = 312,                      /* LT  */
    GT = 313,                      /* GT  */
    LE = 314,                      /* LE  */
    GE = 315,                      /* GE  */
    AND = 316,                     /* AND  */
    OR = 317,                      /* OR  */
    NOT = 318,                     /* NOT  */
    AMP = 319,                     /* AMP  */
    PIPE = 320,                    /* PIPE  */
    CARET = 321,                   /* CARET  */
    TILDE = 322,                   /* TILDE  */
    LSHIFT = 323,                  /* LSHIFT  */
    RSHIFT = 324,                  /* RSHIFT  */
    PLUSEQ = 325,                  /* PLUSEQ  */
    MINUSEQ = 326,                 /* MINUSEQ  */
    STAREQ = 327,                  /* STAREQ  */
    SLASHEQ = 328,                 /* SLASHEQ  */
    PERCENTEQ = 329,               /* PERCENTEQ  */
    AMPEQ = 330,                   /* AMPEQ  */
    PIPEEQ = 331,                  /* PIPEEQ  */
    CARETEQ = 332,                 /* CARETEQ  */
    LSHIFTEQ = 333,                /* LSHIFTEQ  */
    RSHIFTEQ = 334,                /* RSHIFTEQ  */
    INC = 335,                     /* INC  */
    DEC = 336,                     /* DEC  */
    ARROW = 337,                   /* ARROW  */
    DOT_OP = 338,                  /* DOT_OP  */
    ELLIPSIS = 339,                /* ELLIPSIS  */
    QUESTION = 340,                /* QUESTION  */
    COLON = 341,                   /* COLON  */
    SEMICOLON = 342,               /* SEMICOLON  */
    COMMA = 343,                   /* COMMA  */
    HASH = 344,                    /* HASH  */
    DHASH = 345,                   /* DHASH  */
    LPAREN = 346,                  /* LPAREN  */
    RPAREN = 347,                  /* RPAREN  */
    LBRACE = 348,                  /* LBRACE  */
    RBRACE = 349,                  /* RBRACE  */
    LBRACKET = 350,                /* LBRACKET  */
    RBRACKET = 351,                /* RBRACKET  */
    PREPROCESSOR = 352,            /* PREPROCESSOR  */
    UNKNOWN = 353                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parser.y"

    int   ival;
    float fval;
    char *sval;

#line 168 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
