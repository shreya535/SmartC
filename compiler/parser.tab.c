/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 102 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LITERAL = 4,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 5,               /* CHAR_LITERAL  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_HEX_INT = 7,                    /* HEX_INT  */
  YYSYMBOL_OCTAL_INT = 8,                  /* OCTAL_INT  */
  YYSYMBOL_BINARY_INT = 9,                 /* BINARY_INT  */
  YYSYMBOL_FLOAT_NUM = 10,                 /* FLOAT_NUM  */
  YYSYMBOL_AUTO = 11,                      /* AUTO  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_CASE = 13,                      /* CASE  */
  YYSYMBOL_CHAR_KW = 14,                   /* CHAR_KW  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_CONTINUE = 16,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_DOUBLE = 19,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_ENUM = 21,                      /* ENUM  */
  YYSYMBOL_EXTERN = 22,                    /* EXTERN  */
  YYSYMBOL_FLOAT_KW = 23,                  /* FLOAT_KW  */
  YYSYMBOL_FOR = 24,                       /* FOR  */
  YYSYMBOL_GOTO = 25,                      /* GOTO  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_INLINE = 27,                    /* INLINE  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_LONG = 29,                      /* LONG  */
  YYSYMBOL_REGISTER = 30,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 31,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_SHORT = 33,                     /* SHORT  */
  YYSYMBOL_SIGNED = 34,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 35,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 36,                    /* STATIC  */
  YYSYMBOL_STRUCT = 37,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 38,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 39,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 40,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 41,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 42,                      /* VOID  */
  YYSYMBOL_VOLATILE = 43,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_BOOL = 45,                      /* BOOL  */
  YYSYMBOL_TRUE_KW = 46,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 47,                  /* FALSE_KW  */
  YYSYMBOL_NULLVAL = 48,                   /* NULLVAL  */
  YYSYMBOL_PLUS = 49,                      /* PLUS  */
  YYSYMBOL_MINUS = 50,                     /* MINUS  */
  YYSYMBOL_STAR = 51,                      /* STAR  */
  YYSYMBOL_SLASH = 52,                     /* SLASH  */
  YYSYMBOL_PERCENT = 53,                   /* PERCENT  */
  YYSYMBOL_ASSIGN = 54,                    /* ASSIGN  */
  YYSYMBOL_EQ = 55,                        /* EQ  */
  YYSYMBOL_NEQ = 56,                       /* NEQ  */
  YYSYMBOL_LT = 57,                        /* LT  */
  YYSYMBOL_GT = 58,                        /* GT  */
  YYSYMBOL_LE = 59,                        /* LE  */
  YYSYMBOL_GE = 60,                        /* GE  */
  YYSYMBOL_AND = 61,                       /* AND  */
  YYSYMBOL_OR = 62,                        /* OR  */
  YYSYMBOL_NOT = 63,                       /* NOT  */
  YYSYMBOL_AMP = 64,                       /* AMP  */
  YYSYMBOL_PIPE = 65,                      /* PIPE  */
  YYSYMBOL_CARET = 66,                     /* CARET  */
  YYSYMBOL_TILDE = 67,                     /* TILDE  */
  YYSYMBOL_LSHIFT = 68,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 69,                    /* RSHIFT  */
  YYSYMBOL_PLUSEQ = 70,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 71,                   /* MINUSEQ  */
  YYSYMBOL_STAREQ = 72,                    /* STAREQ  */
  YYSYMBOL_SLASHEQ = 73,                   /* SLASHEQ  */
  YYSYMBOL_PERCENTEQ = 74,                 /* PERCENTEQ  */
  YYSYMBOL_AMPEQ = 75,                     /* AMPEQ  */
  YYSYMBOL_PIPEEQ = 76,                    /* PIPEEQ  */
  YYSYMBOL_CARETEQ = 77,                   /* CARETEQ  */
  YYSYMBOL_LSHIFTEQ = 78,                  /* LSHIFTEQ  */
  YYSYMBOL_RSHIFTEQ = 79,                  /* RSHIFTEQ  */
  YYSYMBOL_INC = 80,                       /* INC  */
  YYSYMBOL_DEC = 81,                       /* DEC  */
  YYSYMBOL_ARROW = 82,                     /* ARROW  */
  YYSYMBOL_DOT_OP = 83,                    /* DOT_OP  */
  YYSYMBOL_ELLIPSIS = 84,                  /* ELLIPSIS  */
  YYSYMBOL_QUESTION = 85,                  /* QUESTION  */
  YYSYMBOL_COLON = 86,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 87,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 88,                     /* COMMA  */
  YYSYMBOL_HASH = 89,                      /* HASH  */
  YYSYMBOL_DHASH = 90,                     /* DHASH  */
  YYSYMBOL_LPAREN = 91,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 92,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 93,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 94,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 95,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 96,                  /* RBRACKET  */
  YYSYMBOL_PREPROCESSOR = 97,              /* PREPROCESSOR  */
  YYSYMBOL_UNKNOWN = 98,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 99,                  /* $accept  */
  YYSYMBOL_translation_unit = 100,         /* translation_unit  */
  YYSYMBOL_external_declaration = 101,     /* external_declaration  */
  YYSYMBOL_function_definition = 102,      /* function_definition  */
  YYSYMBOL_declaration = 103,              /* declaration  */
  YYSYMBOL_typedef_decl = 104,             /* typedef_decl  */
  YYSYMBOL_struct_decl_stmt = 105,         /* struct_decl_stmt  */
  YYSYMBOL_enum_decl_stmt = 106,           /* enum_decl_stmt  */
  YYSYMBOL_init_declarator_list = 107,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 108,          /* init_declarator  */
  YYSYMBOL_initializer = 109,              /* initializer  */
  YYSYMBOL_initializer_list = 110,         /* initializer_list  */
  YYSYMBOL_declaration_specifiers = 111,   /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 112,  /* storage_class_specifier  */
  YYSYMBOL_type_qualifier = 113,           /* type_qualifier  */
  YYSYMBOL_type_specifier = 114,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 115, /* struct_or_union_specifier  */
  YYSYMBOL_struct_declaration_list = 116,  /* struct_declaration_list  */
  YYSYMBOL_struct_member = 117,            /* struct_member  */
  YYSYMBOL_struct_declarator_list = 118,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 119,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 120,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 121,          /* enumerator_list  */
  YYSYMBOL_enumerator = 122,               /* enumerator  */
  YYSYMBOL_declarator = 123,               /* declarator  */
  YYSYMBOL_direct_declarator = 124,        /* direct_declarator  */
  YYSYMBOL_pointer = 125,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 126,      /* type_qualifier_list  */
  YYSYMBOL_parameter_list = 127,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 128,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator = 129,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 130, /* direct_abstract_declarator  */
  YYSYMBOL_compound_statement = 131,       /* compound_statement  */
  YYSYMBOL_block_item_list = 132,          /* block_item_list  */
  YYSYMBOL_block_item = 133,               /* block_item  */
  YYSYMBOL_statement = 134,                /* statement  */
  YYSYMBOL_labeled_statement = 135,        /* labeled_statement  */
  YYSYMBOL_expression_statement = 136,     /* expression_statement  */
  YYSYMBOL_selection_statement = 137,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 138,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 139,           /* jump_statement  */
  YYSYMBOL_expression = 140,               /* expression  */
  YYSYMBOL_assignment_expression = 141,    /* assignment_expression  */
  YYSYMBOL_conditional_expression = 142,   /* conditional_expression  */
  YYSYMBOL_constant_expression = 143,      /* constant_expression  */
  YYSYMBOL_logical_or_expression = 144,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 145,   /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 146,  /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 147,  /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 148,           /* and_expression  */
  YYSYMBOL_equality_expression = 149,      /* equality_expression  */
  YYSYMBOL_relational_expression = 150,    /* relational_expression  */
  YYSYMBOL_shift_expression = 151,         /* shift_expression  */
  YYSYMBOL_additive_expression = 152,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 153, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 154,          /* cast_expression  */
  YYSYMBOL_unary_expression = 155,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 156,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 157, /* argument_expression_list  */
  YYSYMBOL_primary_expression = 158        /* primary_expression  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2089

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  427

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   353


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    88,    92,    93,    94,    95,    96,   100,
     102,   107,   108,   109,   110,   111,   112,   114,   116,   121,
     123,   125,   127,   129,   134,   135,   139,   140,   142,   144,
     149,   150,   154,   164,   179,   180,   181,   185,   186,   190,
     191,   192,   193,   194,   195,   199,   199,   199,   199,   199,
     203,   203,   203,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   223,   224,   225,   226,
     227,   228,   232,   233,   237,   238,   239,   243,   244,   248,
     249,   250,   254,   255,   256,   257,   258,   262,   263,   267,
     269,   274,   275,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   300,   301,   302,   303,   307,   308,   312,   313,
     314,   318,   323,   324,   328,   329,   330,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   346,   347,   351,   352,
     356,   357,   361,   362,   363,   364,   365,   366,   370,   371,
     372,   376,   377,   381,   382,   383,   387,   388,   389,   390,
     391,   392,   396,   397,   398,   399,   400,   404,   405,   409,
     411,   413,   415,   417,   419,   421,   423,   425,   427,   429,
     431,   436,   438,   443,   447,   448,   452,   453,   457,   458,
     462,   463,   467,   468,   472,   473,   474,   478,   479,   480,
     481,   482,   486,   487,   488,   492,   493,   494,   498,   499,
     500,   501,   505,   506,   507,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   525,   527,   529,   531,
     533,   535,   537,   539,   544,   545,   549,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LITERAL", "CHAR_LITERAL", "INTEGER", "HEX_INT", "OCTAL_INT",
  "BINARY_INT", "FLOAT_NUM", "AUTO", "BREAK", "CASE", "CHAR_KW", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN",
  "FLOAT_KW", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER",
  "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE",
  "BOOL", "TRUE_KW", "FALSE_KW", "NULLVAL", "PLUS", "MINUS", "STAR",
  "SLASH", "PERCENT", "ASSIGN", "EQ", "NEQ", "LT", "GT", "LE", "GE", "AND",
  "OR", "NOT", "AMP", "PIPE", "CARET", "TILDE", "LSHIFT", "RSHIFT",
  "PLUSEQ", "MINUSEQ", "STAREQ", "SLASHEQ", "PERCENTEQ", "AMPEQ", "PIPEEQ",
  "CARETEQ", "LSHIFTEQ", "RSHIFTEQ", "INC", "DEC", "ARROW", "DOT_OP",
  "ELLIPSIS", "QUESTION", "COLON", "SEMICOLON", "COMMA", "HASH", "DHASH",
  "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "PREPROCESSOR", "UNKNOWN", "$accept", "translation_unit",
  "external_declaration", "function_definition", "declaration",
  "typedef_decl", "struct_decl_stmt", "enum_decl_stmt",
  "init_declarator_list", "init_declarator", "initializer",
  "initializer_list", "declaration_specifiers", "storage_class_specifier",
  "type_qualifier", "type_specifier", "struct_or_union_specifier",
  "struct_declaration_list", "struct_member", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_list", "parameter_declaration", "abstract_declarator",
  "direct_abstract_declarator", "compound_statement", "block_item_list",
  "block_item", "statement", "labeled_statement", "expression_statement",
  "selection_statement", "iteration_statement", "jump_statement",
  "expression", "assignment_expression", "conditional_expression",
  "constant_expression", "logical_or_expression", "logical_and_expression",
  "inclusive_or_expression", "exclusive_or_expression", "and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "cast_expression",
  "unary_expression", "postfix_expression", "argument_expression_list",
  "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-282)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     360,    25,    36,  -282,  -282,  -282,  -282,    47,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,    56,  1544,
      61,  -282,  -282,  -282,  -282,  -282,   315,  -282,  -282,  -282,
    -282,  -282,  -282,  1585,  -282,  -282,  -282,    85,    86,  -282,
    -282,    -3,    24,    62,    42,   -39,   637,    63,  -282,  1620,
      96,    79,    20,   637,  -282,  -282,  -282,   218,  -282,   162,
     -16,  -282,  -282,  -282,  -282,  -282,  -282,   -14,   119,    77,
      13,  -282,    64,  -282,  1149,  -282,   122,    -2,    42,   158,
      16,  -282,   637,   136,  1511,   403,  -282,   144,   156,   161,
     167,   190,   193,   637,   440,  -282,  -282,   218,   137,  -282,
     162,  1149,   683,  1939,    70,   119,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  1771,  -282,  -282,  -282,
    1779,  1779,  1779,  1779,  1779,  1779,  1868,  1868,  1440,  1149,
     198,  -282,  -282,     7,    29,   194,   166,   229,   145,   251,
     244,   270,   280,  -282,   681,   124,  -282,  -282,  1779,  -282,
     102,  1779,    54,  -282,   477,  -282,  1779,  -282,   237,  -282,
     231,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   514,  -282,
    -282,  -282,  -282,  -282,   247,  -282,    35,   217,  1779,   248,
     255,  1100,   256,   347,   262,  1674,   268,   271,  -282,   775,
    -282,  -282,  1585,  -282,   867,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,   240,  -282,  -282,   590,   139,  -282,   274,   282,
     284,   290,  -282,  1440,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  1779,  -282,  -282,     2,   146,  -282,   142,  -282,
    1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,
    1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,
    1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,  1779,
    -282,  -282,   373,   389,  1198,  1779,   308,    59,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,   160,  1779,  -282,  1100,
    -282,   312,  -282,  1100,   320,   363,  1375,   321,  1779,  -282,
     252,  1779,  1779,  -282,   959,  -282,  -282,  -282,  1779,   555,
      68,  -282,     6,  -282,   150,  2005,  -282,  -282,  -282,  -282,
    -282,   317,  1779,   318,  -282,  1008,  -282,    29,    28,   194,
     166,   229,   145,   251,   251,   244,   244,   244,   244,   270,
     270,   280,   280,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,   172,   -33,  -282,  -282,  -282,  -282,  -282,  1100,  -282,
     322,    36,  1682,  1682,  -282,   174,  -282,   179,   186,  -282,
    -282,  -282,   187,   319,   323,  -282,   150,  1972,    75,  -282,
    -282,  -282,  -282,  1779,  -282,  -282,  1779,  1779,  -282,  -282,
    -282,  1779,  1247,  1296,  1100,  1100,  1100,  -282,  -282,  -282,
    -282,   200,   324,  -282,  -282,  -282,  -282,   208,  1100,   214,
    1100,   215,   395,  -282,  -282,  -282,  -282,   329,  -282,  1100,
    -282,  1100,  1100,  -282,  -282,  -282,  -282
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    45,    54,    50,    56,     0,    48,    55,
      63,    53,    59,    46,    52,    58,    60,    47,     0,    49,
       0,    61,    57,    51,    62,     6,     0,     2,     4,     5,
      13,    14,    15,     0,    41,    40,    39,    64,    65,     7,
       8,     0,     0,    86,     0,    68,     0,     0,    49,     0,
      64,    65,    71,     0,     1,     3,    93,   102,    11,     0,
       0,    30,    44,    43,    42,    64,    65,    32,    91,     0,
       0,    24,     0,    26,     0,    16,     0,     0,     0,    89,
       0,    87,     0,     0,     0,     0,    72,    86,    93,     0,
      93,     0,     0,     0,     0,   106,   104,   103,     0,    12,
       0,     0,     0,     0,     0,    92,    25,    27,   226,   232,
     233,   227,   228,   229,   230,   231,     0,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,   159,   171,   174,   176,   178,   180,   182,   184,
     187,   192,   195,   198,   202,   205,   216,    18,     0,    28,
       0,     0,     0,    83,     0,    76,     0,    75,     0,    77,
      79,    67,    73,    19,    23,    20,    22,    21,     0,    70,
     107,   105,    94,    31,    32,    33,   226,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       9,   130,     0,   133,     0,   128,   131,   137,   132,   134,
     135,   136,     0,   157,   101,   112,     0,   108,     0,     0,
       0,     0,    95,     0,   214,   210,   202,   211,   208,   212,
     209,   213,     0,   206,   207,     0,     0,    37,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     222,   223,     0,     0,     0,     0,     0,     0,    82,   173,
      90,    85,    88,    66,    81,    74,     0,     0,    69,     0,
     154,     0,   153,     0,   226,     0,     0,     0,     0,   155,
       0,     0,     0,   126,     0,    10,   129,   142,     0,     0,
       0,   111,   114,   113,   115,     0,   100,    97,    96,    98,
      99,     0,     0,     0,   237,     0,    35,   175,     0,   177,
     179,   181,   183,   185,   186,   188,   189,   190,   191,   193,
     194,   196,   197,   199,   200,   201,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   221,   220,   218,
     224,     0,     0,    29,    84,    78,    80,   138,     0,   140,
       0,   226,     0,     0,   152,     0,   156,     0,     0,   127,
     158,   120,     0,     0,     0,   118,   116,     0,     0,   110,
     109,   215,   203,     0,    36,    38,     0,     0,   219,   217,
     139,     0,     0,     0,     0,     0,     0,   121,   117,   119,
     124,     0,     0,   122,   204,   172,   225,     0,     0,     0,
       0,     0,   143,   145,   146,   125,   123,     0,   150,     0,
     148,     0,     0,   147,   151,   149,   144
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,   397,  -282,     5,  -282,  -282,  -282,  -282,   327,
     -80,  -282,     0,    58,    60,    34,     3,   135,   114,  -282,
     152,     4,   343,  -128,    11,   -62,   -55,  -282,  -281,   133,
     148,   127,  -282,   246,  -186,  -138,  -282,  -188,  -282,  -282,
    -282,   -70,   -73,  -131,  -108,  -282,   219,   220,   223,   216,
     225,   132,   126,   130,   140,   -88,  -110,  -282,  -282,  -282
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,    27,    28,   191,    30,    31,    32,    60,    61,
     130,   228,    84,    34,    35,    36,    65,    85,    86,   158,
     159,    66,    80,    81,    98,    68,    69,    97,   206,   207,
     303,   304,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   132,   270,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   351,   146
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,   131,    96,    37,    38,    29,   214,   105,   296,    56,
     216,   216,   216,   216,   216,   216,   223,   224,   372,    49,
     269,   175,    50,    51,   272,   269,    33,    76,   131,    37,
      38,    29,   215,   217,   218,   219,   220,   221,    41,    41,
     101,   216,   171,   285,    67,    79,   216,   269,   274,   227,
      43,    74,   148,    57,    82,   298,   131,    79,   226,    45,
      89,    91,    79,   389,    52,    77,    87,    64,   216,   230,
     281,    99,   100,   208,   374,   266,   209,   210,   211,   102,
      56,   402,    92,    64,    75,   149,    42,    42,    70,    72,
     232,    62,   231,    63,   312,   160,   401,   299,   363,    90,
     106,   300,   192,   205,   152,    37,    38,    62,   296,    63,
     153,   174,    39,    93,   386,   290,   298,    95,    64,    40,
     216,   279,   216,   216,   216,   216,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   272,
      44,   357,    62,   226,    63,   359,   269,    57,   271,    46,
     302,   107,   226,   354,    53,    78,    44,   170,   333,   334,
     335,   318,   225,    56,   375,    56,   212,   216,    59,   356,
     313,   403,    71,    73,   392,   393,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,    59,    94,   192,
     267,   350,    37,    38,   192,   352,   268,    37,    38,   162,
     236,   237,   216,   174,   260,   261,   262,   263,   162,   147,
     103,    57,   151,    57,   104,   264,   301,   154,   365,   265,
     390,   367,   368,   155,   382,   370,    64,   305,   168,   172,
     315,   306,   234,     5,   298,   385,   316,    78,   314,    64,
     105,   377,   131,   163,   302,   378,   156,   311,   164,    14,
      62,    59,    63,    59,   165,   405,   412,   413,   414,   233,
     387,    23,   298,    62,   388,    63,   394,   298,   162,    57,
     418,   395,   420,   216,   298,   305,   216,   166,   396,   397,
     167,   424,   162,   425,   426,   229,   192,   160,   305,    37,
      38,   362,   415,   235,   192,   404,   298,    37,    38,   205,
     417,   101,   298,   298,   280,   205,   419,   421,   238,   239,
     240,   241,   242,   243,   406,    54,     1,   277,     2,   244,
     245,   407,   409,   411,   275,   276,     3,   297,   298,     4,
       5,   246,   247,   248,     6,   282,     7,     8,     9,   366,
     298,   283,    10,    11,    12,    13,    14,   286,    15,    16,
     287,    17,    18,   288,    19,    20,    21,    22,    23,   291,
      24,     1,   292,     2,   325,   326,   327,   328,   323,   324,
     307,     3,   329,   330,     4,     5,   347,   205,   308,     6,
     309,     7,     8,     9,   331,   332,   310,    10,    11,    12,
      13,    14,   348,    15,    16,   353,    17,    18,   358,    19,
      20,    21,    22,    23,    83,    24,   279,   360,   364,   381,
     383,   398,    25,   391,     3,   422,   423,     4,     5,   399,
     416,   150,     6,    55,    47,     8,     9,   173,   355,   376,
      10,    11,    12,    13,    14,   294,    15,    16,   380,    17,
      18,    83,    48,    20,    21,    22,    23,   373,    24,   317,
     321,     3,   319,     0,     4,     5,   320,    25,     0,     6,
     322,    47,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,     0,    15,    16,     0,    17,    18,    83,    48,
      20,    21,    22,    23,     0,    24,     0,     0,     3,     0,
       0,     4,     5,     0,     0,     0,     6,   161,    47,     8,
       9,     0,     0,     0,    10,    11,    12,    13,    14,     0,
      15,    16,     0,    17,    18,    83,    48,    20,    21,    22,
      23,     0,    24,     0,     0,     3,     0,     0,     4,     5,
       0,     0,     0,     6,   169,    47,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,     0,    15,    16,     0,
      17,    18,     0,    48,    20,    21,    22,    23,    56,    24,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     4,
       5,   273,     0,     0,     6,     0,    47,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    15,    16,
       0,    17,    18,    56,    48,    20,    21,    22,    23,     0,
      24,     3,     0,     0,     4,     5,    57,     0,   278,     6,
       0,    47,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,     0,    15,    16,     0,    17,    18,     0,    48,
      20,    21,    22,    23,     0,    24,     0,     0,    83,     0,
       0,    57,     0,     0,     0,     0,   299,   371,     3,     0,
     300,     4,     5,     0,     0,     0,     6,     0,    47,     8,
       9,     0,     0,     0,    10,    11,    12,    13,    14,     0,
      15,    16,     0,    17,    18,     0,    48,    20,    21,    22,
      23,   299,    24,     0,     0,   300,   176,   109,   110,   111,
     112,   113,   114,   115,     3,   177,   178,     4,     5,   179,
     180,   181,     6,     0,     7,     8,     9,   182,   183,   184,
      10,    11,    12,    13,    14,   185,    15,    16,   116,    17,
      18,   186,    19,    20,    21,    22,    23,   187,    24,   117,
     118,   119,   120,   121,   122,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,   124,     0,     0,
     125,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,     0,     0,   126,   127,     0,     0,     0,     0,     0,
     188,     0,     0,     0,   128,     0,   189,   190,   176,   109,
     110,   111,   112,   113,   114,   115,     3,   177,   178,     4,
       5,   179,   180,   181,     6,     0,     7,     8,     9,   182,
     183,   184,    10,    11,    12,    13,    14,   185,    15,    16,
     116,    17,    18,   186,    19,    20,    21,    22,    23,   187,
      24,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,   188,     0,     0,     0,   128,     0,   189,   293,
     176,   109,   110,   111,   112,   113,   114,   115,     3,   177,
     178,     4,     5,   179,   180,   181,     6,     0,     7,     8,
       9,   182,   183,   184,    10,    11,    12,    13,    14,   185,
      15,    16,   116,    17,    18,   186,    19,    20,    21,    22,
      23,   187,    24,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,   124,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,   188,     0,     0,     0,   128,     0,
     189,   295,   176,   109,   110,   111,   112,   113,   114,   115,
       3,   177,   178,     4,     5,   179,   180,   181,     6,     0,
       7,     8,     9,   182,   183,   184,    10,    11,    12,    13,
      14,   185,    15,    16,   116,    17,    18,   186,    19,    20,
      21,    22,    23,   187,    24,   117,   118,   119,   120,   121,
     122,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   123,   124,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,   116,     0,     0,   188,     0,     0,     0,
     128,     0,   189,   369,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   384,   284,   109,   110,   111,   112,   113,   114,
     115,     0,   177,   178,     0,     0,   179,   180,   181,     0,
       0,     0,     0,     0,   182,   183,   184,     0,     0,     0,
       0,     0,   185,     0,     0,   116,     0,     0,   186,     0,
       0,     0,     0,     0,   187,     0,   117,   118,   119,   120,
     121,   122,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,   123,   124,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,   127,     0,     0,   116,     0,     0,   188,     0,     0,
       0,   128,     0,   189,     0,   117,   118,   119,   120,   121,
     122,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,   123,   124,     0,     0,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,   116,     0,     0,     0,     0,     0,     0,
     128,     0,   129,     0,   117,   118,   119,   120,   121,   122,
     108,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   123,   124,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
       0,     0,   116,     0,     0,     0,     0,     0,     0,   128,
     349,     0,     0,   117,   118,   119,   120,   121,   122,   108,
     109,   110,   111,   112,   113,   114,   115,     0,     0,     0,
     123,   124,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,   116,     0,     0,     0,     0,     0,     0,   128,   408,
       0,     0,   117,   118,   119,   120,   121,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     124,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,   127,   361,   109,
     110,   111,   112,   113,   114,   115,     3,   128,   410,     4,
       5,     0,     0,     0,     6,     0,     7,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    15,    16,
     116,    17,    18,     0,    19,    20,    21,    22,    23,     0,
      24,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,   124,
       0,     0,   125,   108,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     4,   126,   127,     0,     0,     6,
       0,    47,   188,     9,     0,     0,   128,    10,    11,    12,
       0,     0,     0,    15,    16,   116,     0,    18,     0,     0,
      20,    21,    22,     0,     0,    24,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   123,   124,     0,     0,   125,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
     126,   127,     3,     0,     0,     4,     5,     0,     0,     0,
       6,   128,    47,     8,     9,     0,     0,     0,    10,    11,
      12,    13,    14,     0,    15,    16,     0,    17,    18,     0,
      48,    20,    21,    22,    23,     3,    24,     0,     4,     5,
       0,     0,    57,     6,     0,    47,     8,     9,     0,     0,
       0,    10,    11,    12,    13,    14,     0,    15,    16,     0,
      17,    18,     0,    48,    20,    21,    22,    23,    56,    24,
       0,     0,     0,     0,     0,     0,     3,   156,   157,     4,
       5,     0,    59,     0,     6,     0,    47,     8,     9,     0,
       0,     0,    10,    11,    12,    13,    14,     0,    15,    16,
       0,    17,    18,    88,    48,    20,    21,    22,    23,     0,
      24,     3,     0,     0,     4,     5,    57,     0,     0,     6,
       0,    47,     8,     9,     0,     0,     0,    10,    11,    12,
      13,    14,     0,    15,    16,     0,    17,    18,     0,    48,
      20,    21,    22,    23,     0,    24,     0,     0,     0,     0,
       0,    57,    58,     0,     0,     0,    59,   108,   109,   110,
     111,   112,   113,   114,   115,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,    59,     0,     0,     0,     0,     0,   116,     0,     0,
     117,   118,   119,   120,   121,   122,     0,     0,   117,   118,
     119,   120,   121,   122,     0,     0,     0,   123,   124,     0,
       0,   125,     0,     0,     0,   123,   124,     0,     0,   125,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
       0,   289,   126,   127,     0,   128,     0,     0,     0,   188,
       0,     0,     0,   128,   108,   109,   110,   111,   112,   113,
     114,   115,   108,   109,   110,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,   117,   118,   119,
     120,   121,   122,     0,     0,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   123,   124,     0,     0,   125,     0,
       0,     0,   123,   124,     0,     0,   125,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   126,
     127,     0,   213,     0,     0,     0,     0,     0,     0,     0,
     128,   108,   109,   110,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   123,   124,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   126,   127,
       3,     0,     0,     4,     5,     0,     0,     0,     6,   222,
      47,     8,     9,     0,     0,     0,    10,    11,    12,    13,
      14,     0,    15,    16,     0,    17,    18,     0,    48,    20,
      21,    22,    23,     3,    24,     0,     4,     5,     0,     0,
       0,     6,     0,    47,     8,     9,     0,     0,     0,    10,
      11,    12,    13,    14,     0,    15,    16,     0,    17,    18,
       0,    48,    20,    21,    22,    23,     3,    24,     0,     4,
       5,     0,     0,     0,     6,     0,    47,     8,     9,     0,
       0,   204,    10,    11,    12,    13,    14,     0,    15,    16,
       0,    17,    18,     0,    48,    20,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   400,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   379
};

static const yytype_int16 yycheck[] =
{
       0,    74,    57,     0,     0,     0,   116,    69,   194,     3,
     120,   121,   122,   123,   124,   125,   126,   127,   299,    19,
     151,   101,    19,    19,   152,   156,    26,     3,   101,    26,
      26,    26,   120,   121,   122,   123,   124,   125,     3,     3,
      54,   151,    97,   181,    33,     3,   156,   178,   156,   129,
       3,    54,    54,    51,    93,    88,   129,     3,   128,     3,
      49,    50,     3,    96,     3,     3,     3,    33,   178,    62,
     178,    87,    88,     3,     6,   148,     6,     7,     8,    93,
       3,     6,     3,    49,    87,    87,    51,    51,     3,     3,
      61,    33,    85,    33,    92,    84,   377,    91,   286,     3,
      87,    95,   102,   103,    88,   102,   102,    49,   294,    49,
      94,   100,    87,    93,    86,   185,    88,    57,    84,    94,
     230,    86,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   267,
      93,   279,    84,   213,    84,   283,   277,    51,    94,    93,
     205,    87,   222,    94,    93,    93,    93,    97,   246,   247,
     248,   231,   128,     3,    96,     3,    96,   277,    91,   277,
     225,    96,    87,    87,   362,   363,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    91,    53,   189,
      88,   264,   189,   189,   194,   265,    94,   194,   194,    85,
      55,    56,   312,   192,    80,    81,    82,    83,    94,    87,
      91,    51,    54,    51,    95,    91,   205,    82,   288,    95,
     358,   291,   292,    87,   312,   298,   192,    88,    93,    92,
      88,    92,    66,    15,    88,   315,    94,    93,    92,   205,
     302,    91,   315,    87,   299,    95,    86,   213,    87,    31,
     192,    91,   192,    91,    87,   386,   394,   395,   396,    65,
      88,    43,    88,   205,    92,   205,    92,    88,   154,    51,
     408,    92,   410,   383,    88,    88,   386,    87,    92,    92,
      87,   419,   168,   421,   422,    87,   286,   276,    88,   286,
     286,   286,    92,    64,   294,   383,    88,   294,   294,   299,
      92,    54,    88,    88,    87,   305,    92,    92,    57,    58,
      59,    60,    68,    69,   387,     0,     1,    86,     3,    49,
      50,   391,   392,   393,    87,    88,    11,    87,    88,    14,
      15,    51,    52,    53,    19,    87,    21,    22,    23,    87,
      88,    86,    27,    28,    29,    30,    31,    91,    33,    34,
       3,    36,    37,    91,    39,    40,    41,    42,    43,    91,
      45,     1,    91,     3,   238,   239,   240,   241,   236,   237,
      96,    11,   242,   243,    14,    15,     3,   377,    96,    19,
      96,    21,    22,    23,   244,   245,    96,    27,    28,    29,
      30,    31,     3,    33,    34,    87,    36,    37,    86,    39,
      40,    41,    42,    43,     1,    45,    86,    44,    87,    92,
      92,    92,    97,    91,    11,    20,    87,    14,    15,    96,
      96,    78,    19,    26,    21,    22,    23,   100,   276,   302,
      27,    28,    29,    30,    31,   189,    33,    34,   305,    36,
      37,     1,    39,    40,    41,    42,    43,   299,    45,   230,
     234,    11,   232,    -1,    14,    15,   233,    97,    -1,    19,
     235,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    36,    37,     1,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    11,    -1,
      -1,    14,    15,    -1,    -1,    -1,    19,    94,    21,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    -1,    36,    37,     1,    39,    40,    41,    42,
      43,    -1,    45,    -1,    -1,    11,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    94,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,     3,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    14,
      15,    94,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,     3,    39,    40,    41,    42,    43,    -1,
      45,    11,    -1,    -1,    14,    15,    51,    -1,    94,    19,
      -1,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,     1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    91,    92,    11,    -1,
      95,    14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    31,    -1,
      33,    34,    -1,    36,    37,    -1,    39,    40,    41,    42,
      43,    91,    45,    -1,    -1,    95,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      67,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    91,    -1,    93,    94,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    93,    94,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      93,    94,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    35,    -1,    -1,    87,    -1,    -1,    -1,
      91,    -1,    93,    94,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    93,    94,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    46,    47,    48,    49,
      50,    51,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      80,    81,    -1,    -1,    35,    -1,    -1,    87,    -1,    -1,
      -1,    91,    -1,    93,    -1,    46,    47,    48,    49,    50,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      91,    -1,    93,    -1,    46,    47,    48,    49,    50,    51,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    91,
      92,    -1,    -1,    46,    47,    48,    49,    50,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    -1,    -1,
      63,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    -1,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,
      -1,    -1,    46,    47,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    80,    81,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    91,    92,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    67,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    14,    80,    81,    -1,    -1,    19,
      -1,    21,    87,    23,    -1,    -1,    91,    27,    28,    29,
      -1,    -1,    -1,    33,    34,    35,    -1,    37,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,
      80,    81,    11,    -1,    -1,    14,    15,    -1,    -1,    -1,
      19,    91,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    -1,    33,    34,    -1,    36,    37,    -1,
      39,    40,    41,    42,    43,    11,    45,    -1,    14,    15,
      -1,    -1,    51,    19,    -1,    21,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    -1,    33,    34,    -1,
      36,    37,    -1,    39,    40,    41,    42,    43,     3,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    86,    87,    14,
      15,    -1,    91,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,     3,    39,    40,    41,    42,    43,    -1,
      45,    11,    -1,    -1,    14,    15,    51,    -1,    -1,    19,
      -1,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    -1,    33,    34,    -1,    36,    37,    -1,    39,
      40,    41,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    51,    87,    -1,    -1,    -1,    91,     3,     4,     5,
       6,     7,     8,     9,    10,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      46,    47,    48,    49,    50,    51,    -1,    -1,    46,    47,
      48,    49,    50,    51,    -1,    -1,    -1,    63,    64,    -1,
      -1,    67,    -1,    -1,    -1,    63,    64,    -1,    -1,    67,
      -1,    -1,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    87,    80,    81,    -1,    91,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    91,     3,     4,     5,     6,     7,     8,
       9,    10,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    46,    47,    48,
      49,    50,    51,    -1,    -1,    46,    47,    48,    49,    50,
      51,    -1,    -1,    -1,    63,    64,    -1,    -1,    67,    -1,
      -1,    -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      91,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,
      11,    -1,    -1,    14,    15,    -1,    -1,    -1,    19,    91,
      21,    22,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    -1,    33,    34,    -1,    36,    37,    -1,    39,    40,
      41,    42,    43,    11,    45,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    -1,    33,    34,    -1,    36,    37,
      -1,    39,    40,    41,    42,    43,    11,    45,    -1,    14,
      15,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    92,    27,    28,    29,    30,    31,    -1,    33,    34,
      -1,    36,    37,    -1,    39,    40,    41,    42,    43,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    11,    14,    15,    19,    21,    22,    23,
      27,    28,    29,    30,    31,    33,    34,    36,    37,    39,
      40,    41,    42,    43,    45,    97,   100,   101,   102,   103,
     104,   105,   106,   111,   112,   113,   114,   115,   120,    87,
      94,     3,    51,     3,    93,     3,    93,    21,    39,   111,
     115,   120,     3,    93,     0,   101,     3,    51,    87,    91,
     107,   108,   112,   113,   114,   115,   120,   123,   124,   125,
       3,    87,     3,    87,    54,    87,     3,     3,    93,     3,
     121,   122,    93,     1,   111,   116,   117,     3,     3,   123,
       3,   123,     3,    93,   116,   113,   125,   126,   123,    87,
      88,    54,    93,    91,    95,   124,    87,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    35,    46,    47,    48,
      49,    50,    51,    63,    64,    67,    80,    81,    91,    93,
     109,   141,   142,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   158,    87,    54,    87,
     121,    54,    88,    94,   116,    87,    86,    87,   118,   119,
     123,    94,   117,    87,    87,    87,    87,    87,   116,    94,
     113,   125,    92,   108,   123,   109,     3,    12,    13,    16,
      17,    18,    24,    25,    26,    32,    38,    44,    87,    93,
      94,   103,   111,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    92,   111,   127,   128,     3,     6,
       7,     8,    96,    91,   155,   154,   155,   154,   154,   154,
     154,   154,    91,   155,   155,   114,   140,   109,   110,    87,
      62,    85,    61,    65,    66,    64,    55,    56,    57,    58,
      59,    60,    68,    69,    49,    50,    51,    52,    53,    54,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    91,    95,   141,    88,    94,   142,
     143,    94,   122,    94,   143,    87,    88,    86,    94,    86,
      87,   143,    87,    86,     3,   134,    91,     3,    91,    87,
     140,    91,    91,    94,   132,    94,   133,    87,    88,    91,
      95,   123,   125,   129,   130,    88,    92,    96,    96,    96,
      96,   114,    92,   125,    92,    88,    94,   145,   140,   146,
     147,   148,   149,   150,   150,   151,   151,   151,   151,   152,
     152,   153,   153,   154,   154,   154,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,     3,     3,    92,
     141,   157,   140,    87,    94,   119,   143,   134,    86,   134,
      44,     3,   103,   136,    87,   140,    87,   140,   140,    94,
     141,    92,   127,   129,     6,    96,   130,    91,    95,    84,
     128,    92,   154,    92,    94,   109,    86,    88,    92,    96,
     134,    91,   136,   136,    92,    92,    92,    92,    92,    96,
      92,   127,     6,    96,   154,   142,   141,   140,    92,   140,
      92,   140,   134,   134,   134,    92,    96,    92,   134,    92,
     134,    92,    20,    87,   134,   134,   134
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   105,   105,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   112,   112,
     113,   113,   113,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   115,   115,
     115,   115,   116,   116,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   125,   125,   125,   126,   126,   127,   127,
     127,   128,   128,   128,   129,   129,   129,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   134,   134,   134,   135,   135,
     135,   136,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   138,   139,   139,   139,   139,   139,   140,   140,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   142,   142,   143,   144,   144,   145,   145,   146,   146,
     147,   147,   148,   148,   149,   149,   149,   150,   150,   150,
     150,   150,   151,   151,   151,   152,   152,   152,   153,   153,
     153,   153,   154,   154,   154,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,   155,   156,   156,   156,   156,
     156,   156,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     2,     4,
       5,     2,     3,     1,     1,     1,     3,     5,     4,     4,
       4,     4,     4,     4,     2,     3,     2,     3,     4,     6,
       1,     3,     1,     3,     1,     3,     4,     1,     3,     1,
       1,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     2,     5,
       4,     2,     1,     2,     3,     2,     2,     1,     3,     1,
       3,     2,     5,     4,     6,     5,     2,     1,     3,     1,
       3,     1,     2,     1,     3,     3,     4,     4,     4,     4,
       4,     3,     1,     2,     2,     3,     1,     2,     1,     3,
       3,     2,     1,     2,     1,     1,     2,     3,     2,     3,
       2,     3,     3,     4,     3,     4,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     4,     5,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     4,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 9: /* function_definition: declaration_specifiers declarator LBRACE RBRACE  */
#line 101 "parser.y"
        { if((yyvsp[-2].sval)) sym_declare((yyvsp[-2].sval), current_type, line, 1); }
#line 1896 "parser.tab.c"
    break;

  case 10: /* function_definition: declaration_specifiers declarator LBRACE block_item_list RBRACE  */
#line 103 "parser.y"
        { if((yyvsp[-3].sval)) sym_declare((yyvsp[-3].sval), current_type, line, 1); }
#line 1902 "parser.tab.c"
    break;

  case 16: /* declaration: IDENTIFIER IDENTIFIER SEMICOLON  */
#line 113 "parser.y"
        { sym_declare((yyvsp[-1].sval), (yyvsp[-2].sval), line, 0); }
#line 1908 "parser.tab.c"
    break;

  case 17: /* declaration: IDENTIFIER IDENTIFIER ASSIGN initializer SEMICOLON  */
#line 115 "parser.y"
        { sym_declare((yyvsp[-3].sval), (yyvsp[-4].sval), line, 1); }
#line 1914 "parser.tab.c"
    break;

  case 18: /* declaration: IDENTIFIER STAR IDENTIFIER SEMICOLON  */
#line 117 "parser.y"
        { sym_declare((yyvsp[-1].sval), (yyvsp[-3].sval), line, 0); }
#line 1920 "parser.tab.c"
    break;

  case 19: /* typedef_decl: TYPEDEF declaration_specifiers IDENTIFIER SEMICOLON  */
#line 122 "parser.y"
        { sym_declare((yyvsp[-1].sval), "typedef", line, 1); }
#line 1926 "parser.tab.c"
    break;

  case 20: /* typedef_decl: TYPEDEF struct_or_union_specifier IDENTIFIER SEMICOLON  */
#line 124 "parser.y"
        { sym_declare((yyvsp[-1].sval), "typedef", line, 1); }
#line 1932 "parser.tab.c"
    break;

  case 21: /* typedef_decl: TYPEDEF enum_specifier IDENTIFIER SEMICOLON  */
#line 126 "parser.y"
        { sym_declare((yyvsp[-1].sval), "typedef", line, 1); }
#line 1938 "parser.tab.c"
    break;

  case 22: /* typedef_decl: TYPEDEF struct_or_union_specifier declarator SEMICOLON  */
#line 128 "parser.y"
        { if((yyvsp[-1].sval)) sym_declare((yyvsp[-1].sval), "typedef", line, 1); }
#line 1944 "parser.tab.c"
    break;

  case 23: /* typedef_decl: TYPEDEF declaration_specifiers declarator SEMICOLON  */
#line 130 "parser.y"
        { if((yyvsp[-1].sval)) sym_declare((yyvsp[-1].sval), "typedef", line, 1); }
#line 1950 "parser.tab.c"
    break;

  case 27: /* enum_decl_stmt: enum_specifier IDENTIFIER SEMICOLON  */
#line 141 "parser.y"
        { sym_declare((yyvsp[-1].sval), "enum", line, 0); }
#line 1956 "parser.tab.c"
    break;

  case 28: /* enum_decl_stmt: ENUM IDENTIFIER IDENTIFIER SEMICOLON  */
#line 143 "parser.y"
        { sym_declare((yyvsp[-1].sval), "enum", line, 0); }
#line 1962 "parser.tab.c"
    break;

  case 29: /* enum_decl_stmt: ENUM IDENTIFIER IDENTIFIER ASSIGN assignment_expression SEMICOLON  */
#line 145 "parser.y"
        { sym_declare((yyvsp[-3].sval), "enum", line, 1); }
#line 1968 "parser.tab.c"
    break;

  case 32: /* init_declarator: declarator  */
#line 155 "parser.y"
        {
            if((yyvsp[0].sval) && strlen((yyvsp[0].sval)) > 0){
                if(!sym_declare((yyvsp[0].sval), current_type, line, 0)){
                    char msg[128];
                    sprintf(msg, "variable '%s' already declared in this scope", (yyvsp[0].sval));
                    report_error(msg);
                }
            }
        }
#line 1982 "parser.tab.c"
    break;

  case 33: /* init_declarator: declarator ASSIGN initializer  */
#line 165 "parser.y"
        {
            if((yyvsp[-2].sval) && strlen((yyvsp[-2].sval)) > 0){
                if(!sym_declare((yyvsp[-2].sval), current_type, line, 1)){
                    char msg[128];
                    sprintf(msg, "variable '%s' already declared in this scope", (yyvsp[-2].sval));
                    report_error(msg);
                } else {
                    sym_mark_initialized((yyvsp[-2].sval));
                }
            }
        }
#line 1998 "parser.tab.c"
    break;

  case 53: /* type_specifier: INT  */
#line 207 "parser.y"
                   { strcpy(current_type, "int");      }
#line 2004 "parser.tab.c"
    break;

  case 54: /* type_specifier: CHAR_KW  */
#line 208 "parser.y"
                   { strcpy(current_type, "char");     }
#line 2010 "parser.tab.c"
    break;

  case 55: /* type_specifier: FLOAT_KW  */
#line 209 "parser.y"
                   { strcpy(current_type, "float");    }
#line 2016 "parser.tab.c"
    break;

  case 56: /* type_specifier: DOUBLE  */
#line 210 "parser.y"
                   { strcpy(current_type, "double");   }
#line 2022 "parser.tab.c"
    break;

  case 57: /* type_specifier: VOID  */
#line 211 "parser.y"
                   { strcpy(current_type, "void");     }
#line 2028 "parser.tab.c"
    break;

  case 58: /* type_specifier: SHORT  */
#line 212 "parser.y"
                   { strcpy(current_type, "short");    }
#line 2034 "parser.tab.c"
    break;

  case 59: /* type_specifier: LONG  */
#line 213 "parser.y"
                   { strcpy(current_type, "long");     }
#line 2040 "parser.tab.c"
    break;

  case 60: /* type_specifier: SIGNED  */
#line 214 "parser.y"
                   { strcpy(current_type, "signed");   }
#line 2046 "parser.tab.c"
    break;

  case 61: /* type_specifier: UNSIGNED  */
#line 215 "parser.y"
                   { strcpy(current_type, "unsigned"); }
#line 2052 "parser.tab.c"
    break;

  case 62: /* type_specifier: BOOL  */
#line 216 "parser.y"
                   { strcpy(current_type, "bool");     }
#line 2058 "parser.tab.c"
    break;

  case 63: /* type_specifier: INLINE  */
#line 217 "parser.y"
                   { strcpy(current_type, "inline");   }
#line 2064 "parser.tab.c"
    break;

  case 64: /* type_specifier: struct_or_union_specifier  */
#line 218 "parser.y"
                                { strcpy(current_type, "struct"); }
#line 2070 "parser.tab.c"
    break;

  case 65: /* type_specifier: enum_specifier  */
#line 219 "parser.y"
                                { strcpy(current_type, "enum");   }
#line 2076 "parser.tab.c"
    break;

  case 89: /* enumerator: IDENTIFIER  */
#line 268 "parser.y"
        { sym_declare((yyvsp[0].sval), "enum_const", line, 1); }
#line 2082 "parser.tab.c"
    break;

  case 90: /* enumerator: IDENTIFIER ASSIGN constant_expression  */
#line 270 "parser.y"
        { sym_declare((yyvsp[-2].sval), "enum_const", line, 1); }
#line 2088 "parser.tab.c"
    break;

  case 91: /* declarator: direct_declarator  */
#line 274 "parser.y"
                                 { (yyval.sval) = (yyvsp[0].sval); }
#line 2094 "parser.tab.c"
    break;

  case 92: /* declarator: pointer direct_declarator  */
#line 275 "parser.y"
                                 { (yyval.sval) = (yyvsp[0].sval); }
#line 2100 "parser.tab.c"
    break;

  case 93: /* direct_declarator: IDENTIFIER  */
#line 280 "parser.y"
        { (yyval.sval) = (yyvsp[0].sval); }
#line 2106 "parser.tab.c"
    break;

  case 94: /* direct_declarator: LPAREN declarator RPAREN  */
#line 282 "parser.y"
        { (yyval.sval) = (yyvsp[-1].sval); }
#line 2112 "parser.tab.c"
    break;

  case 95: /* direct_declarator: direct_declarator LBRACKET RBRACKET  */
#line 284 "parser.y"
        { (yyval.sval) = (yyvsp[-2].sval); }
#line 2118 "parser.tab.c"
    break;

  case 96: /* direct_declarator: direct_declarator LBRACKET INTEGER RBRACKET  */
#line 286 "parser.y"
        { (yyval.sval) = (yyvsp[-3].sval); }
#line 2124 "parser.tab.c"
    break;

  case 97: /* direct_declarator: direct_declarator LBRACKET IDENTIFIER RBRACKET  */
#line 288 "parser.y"
        { (yyval.sval) = (yyvsp[-3].sval); }
#line 2130 "parser.tab.c"
    break;

  case 98: /* direct_declarator: direct_declarator LBRACKET HEX_INT RBRACKET  */
#line 290 "parser.y"
        { (yyval.sval) = (yyvsp[-3].sval); }
#line 2136 "parser.tab.c"
    break;

  case 99: /* direct_declarator: direct_declarator LBRACKET OCTAL_INT RBRACKET  */
#line 292 "parser.y"
        { (yyval.sval) = (yyvsp[-3].sval); }
#line 2142 "parser.tab.c"
    break;

  case 100: /* direct_declarator: direct_declarator LPAREN parameter_list RPAREN  */
#line 294 "parser.y"
        { (yyval.sval) = (yyvsp[-3].sval); }
#line 2148 "parser.tab.c"
    break;

  case 101: /* direct_declarator: direct_declarator LPAREN RPAREN  */
#line 296 "parser.y"
        { (yyval.sval) = (yyvsp[-2].sval); }
#line 2154 "parser.tab.c"
    break;

  case 111: /* parameter_declaration: declaration_specifiers declarator  */
#line 319 "parser.y"
        {
            if((yyvsp[0].sval) && strlen((yyvsp[0].sval)) > 0)
                sym_declare((yyvsp[0].sval), current_type, line, 1);
        }
#line 2163 "parser.tab.c"
    break;

  case 159: /* assignment_expression: conditional_expression  */
#line 410 "parser.y"
        { (yyval.sval) = (yyvsp[0].sval); }
#line 2169 "parser.tab.c"
    break;

  case 160: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 412 "parser.y"
        { if((yyvsp[-2].sval)) sym_mark_initialized((yyvsp[-2].sval)); (yyval.sval) = (yyvsp[-2].sval); }
#line 2175 "parser.tab.c"
    break;

  case 161: /* assignment_expression: unary_expression PLUSEQ assignment_expression  */
#line 414 "parser.y"
        { (yyval.sval) = NULL; }
#line 2181 "parser.tab.c"
    break;

  case 162: /* assignment_expression: unary_expression MINUSEQ assignment_expression  */
#line 416 "parser.y"
        { (yyval.sval) = NULL; }
#line 2187 "parser.tab.c"
    break;

  case 163: /* assignment_expression: unary_expression STAREQ assignment_expression  */
#line 418 "parser.y"
        { (yyval.sval) = NULL; }
#line 2193 "parser.tab.c"
    break;

  case 164: /* assignment_expression: unary_expression SLASHEQ assignment_expression  */
#line 420 "parser.y"
        { (yyval.sval) = NULL; }
#line 2199 "parser.tab.c"
    break;

  case 165: /* assignment_expression: unary_expression PERCENTEQ assignment_expression  */
#line 422 "parser.y"
        { (yyval.sval) = NULL; }
#line 2205 "parser.tab.c"
    break;

  case 166: /* assignment_expression: unary_expression AMPEQ assignment_expression  */
#line 424 "parser.y"
        { (yyval.sval) = NULL; }
#line 2211 "parser.tab.c"
    break;

  case 167: /* assignment_expression: unary_expression PIPEEQ assignment_expression  */
#line 426 "parser.y"
        { (yyval.sval) = NULL; }
#line 2217 "parser.tab.c"
    break;

  case 168: /* assignment_expression: unary_expression CARETEQ assignment_expression  */
#line 428 "parser.y"
        { (yyval.sval) = NULL; }
#line 2223 "parser.tab.c"
    break;

  case 169: /* assignment_expression: unary_expression LSHIFTEQ assignment_expression  */
#line 430 "parser.y"
        { (yyval.sval) = NULL; }
#line 2229 "parser.tab.c"
    break;

  case 170: /* assignment_expression: unary_expression RSHIFTEQ assignment_expression  */
#line 432 "parser.y"
        { (yyval.sval) = NULL; }
#line 2235 "parser.tab.c"
    break;

  case 171: /* conditional_expression: logical_or_expression  */
#line 437 "parser.y"
        { (yyval.sval) = NULL; }
#line 2241 "parser.tab.c"
    break;

  case 172: /* conditional_expression: logical_or_expression QUESTION expression COLON conditional_expression  */
#line 439 "parser.y"
        { (yyval.sval) = NULL; }
#line 2247 "parser.tab.c"
    break;

  case 205: /* unary_expression: postfix_expression  */
#line 511 "parser.y"
                                { (yyval.sval) = (yyvsp[0].sval); }
#line 2253 "parser.tab.c"
    break;

  case 206: /* unary_expression: INC unary_expression  */
#line 512 "parser.y"
                                { (yyval.sval) = (yyvsp[0].sval); }
#line 2259 "parser.tab.c"
    break;

  case 207: /* unary_expression: DEC unary_expression  */
#line 513 "parser.y"
                                { (yyval.sval) = (yyvsp[0].sval); }
#line 2265 "parser.tab.c"
    break;

  case 208: /* unary_expression: STAR cast_expression  */
#line 514 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2271 "parser.tab.c"
    break;

  case 209: /* unary_expression: AMP cast_expression  */
#line 515 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2277 "parser.tab.c"
    break;

  case 210: /* unary_expression: PLUS cast_expression  */
#line 516 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2283 "parser.tab.c"
    break;

  case 211: /* unary_expression: MINUS cast_expression  */
#line 517 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2289 "parser.tab.c"
    break;

  case 212: /* unary_expression: NOT cast_expression  */
#line 518 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2295 "parser.tab.c"
    break;

  case 213: /* unary_expression: TILDE cast_expression  */
#line 519 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2301 "parser.tab.c"
    break;

  case 214: /* unary_expression: SIZEOF unary_expression  */
#line 520 "parser.y"
                                { (yyval.sval) = NULL; }
#line 2307 "parser.tab.c"
    break;

  case 215: /* unary_expression: SIZEOF LPAREN type_specifier RPAREN  */
#line 521 "parser.y"
                                          { (yyval.sval) = NULL; }
#line 2313 "parser.tab.c"
    break;

  case 216: /* postfix_expression: primary_expression  */
#line 526 "parser.y"
        { (yyval.sval) = (yyvsp[0].sval); }
#line 2319 "parser.tab.c"
    break;

  case 217: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 528 "parser.y"
        { (yyval.sval) = NULL; }
#line 2325 "parser.tab.c"
    break;

  case 218: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 530 "parser.y"
        { (yyval.sval) = NULL; }
#line 2331 "parser.tab.c"
    break;

  case 219: /* postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN  */
#line 532 "parser.y"
        { (yyval.sval) = NULL; }
#line 2337 "parser.tab.c"
    break;

  case 220: /* postfix_expression: postfix_expression DOT_OP IDENTIFIER  */
#line 534 "parser.y"
        { (yyval.sval) = NULL; }
#line 2343 "parser.tab.c"
    break;

  case 221: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 536 "parser.y"
        { (yyval.sval) = NULL; }
#line 2349 "parser.tab.c"
    break;

  case 222: /* postfix_expression: postfix_expression INC  */
#line 538 "parser.y"
        { (yyval.sval) = NULL; }
#line 2355 "parser.tab.c"
    break;

  case 223: /* postfix_expression: postfix_expression DEC  */
#line 540 "parser.y"
        { (yyval.sval) = NULL; }
#line 2361 "parser.tab.c"
    break;

  case 226: /* primary_expression: IDENTIFIER  */
#line 550 "parser.y"
        {
            int idx = sym_lookup((yyvsp[0].sval));
            if(idx == -1){
                char msg[128];
                sprintf(msg, "undeclared variable '%s'", (yyvsp[0].sval));
                report_error(msg);
                (yyval.sval) = NULL;
            } else {
                sym_mark_used((yyvsp[0].sval));
                if(!table[idx].initialized &&
                   strcmp(table[idx].type,"builtin")    != 0 &&
                   strcmp(table[idx].type,"typedef")    != 0 &&
                   strcmp(table[idx].type,"enum_const") != 0 &&
                   strcmp(table[idx].type,"enum")       != 0 &&
                   strcmp(table[idx].type,"int")        != 0){
                    char msg[128];
                    sprintf(msg, "variable '%s' used before initialization", (yyvsp[0].sval));
                    report_warning(msg);
                }
                (yyval.sval) = (yyvsp[0].sval);
            }
        }
#line 2388 "parser.tab.c"
    break;

  case 227: /* primary_expression: INTEGER  */
#line 572 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2394 "parser.tab.c"
    break;

  case 228: /* primary_expression: HEX_INT  */
#line 573 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2400 "parser.tab.c"
    break;

  case 229: /* primary_expression: OCTAL_INT  */
#line 574 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2406 "parser.tab.c"
    break;

  case 230: /* primary_expression: BINARY_INT  */
#line 575 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2412 "parser.tab.c"
    break;

  case 231: /* primary_expression: FLOAT_NUM  */
#line 576 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2418 "parser.tab.c"
    break;

  case 232: /* primary_expression: STRING_LITERAL  */
#line 577 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2424 "parser.tab.c"
    break;

  case 233: /* primary_expression: CHAR_LITERAL  */
#line 578 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2430 "parser.tab.c"
    break;

  case 234: /* primary_expression: TRUE_KW  */
#line 579 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2436 "parser.tab.c"
    break;

  case 235: /* primary_expression: FALSE_KW  */
#line 580 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2442 "parser.tab.c"
    break;

  case 236: /* primary_expression: NULLVAL  */
#line 581 "parser.y"
                     { (yyval.sval) = NULL; }
#line 2448 "parser.tab.c"
    break;

  case 237: /* primary_expression: LPAREN expression RPAREN  */
#line 582 "parser.y"
                               { (yyval.sval) = NULL; }
#line 2454 "parser.tab.c"
    break;


#line 2458 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 585 "parser.y"


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
