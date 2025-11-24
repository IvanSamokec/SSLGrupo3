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
#include "tabla_simbolos.h"

int yylex(void);
void yyerror(const char *s);

int errorCount = 0;
extern int lexicalErrors;
Symbol *currentFunction = NULL;
bool hasReturnStatement = false;

#line 86 "parser.tab.c"

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
  YYSYMBOL_IDENTIFICADOR = 3,              /* IDENTIFICADOR  */
  YYSYMBOL_TIPO_DATO = 4,                  /* TIPO_DATO  */
  YYSYMBOL_CADENA = 5,                     /* CADENA  */
  YYSYMBOL_ENTERO = 6,                     /* ENTERO  */
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_REAL = 9,                       /* REAL  */
  YYSYMBOL_CARACTER = 10,                  /* CARACTER  */
  YYSYMBOL_PACKAGE = 11,                   /* PACKAGE  */
  YYSYMBOL_IMPORT = 12,                    /* IMPORT  */
  YYSYMBOL_FUNC = 13,                      /* FUNC  */
  YYSYMBOL_VAR = 14,                       /* VAR  */
  YYSYMBOL_CONST = 15,                     /* CONST  */
  YYSYMBOL_TYPE = 16,                      /* TYPE  */
  YYSYMBOL_STRUCT = 17,                    /* STRUCT  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_ELSE = 19,                      /* ELSE  */
  YYSYMBOL_FOR = 20,                       /* FOR  */
  YYSYMBOL_SWITCH = 21,                    /* SWITCH  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_DEFAULT = 23,                   /* DEFAULT  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_BREAK = 25,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 26,                  /* CONTINUE  */
  YYSYMBOL_DECLARACION_CORTA = 27,         /* DECLARACION_CORTA  */
  YYSYMBOL_INCREMENTO = 28,                /* INCREMENTO  */
  YYSYMBOL_DECREMENTO = 29,                /* DECREMENTO  */
  YYSYMBOL_MAS_IGUAL = 30,                 /* MAS_IGUAL  */
  YYSYMBOL_MENOS_IGUAL = 31,               /* MENOS_IGUAL  */
  YYSYMBOL_POR_IGUAL = 32,                 /* POR_IGUAL  */
  YYSYMBOL_DIV_IGUAL = 33,                 /* DIV_IGUAL  */
  YYSYMBOL_MOD_IGUAL = 34,                 /* MOD_IGUAL  */
  YYSYMBOL_IGUALDAD = 35,                  /* IGUALDAD  */
  YYSYMBOL_DIFERENTE = 36,                 /* DIFERENTE  */
  YYSYMBOL_MENOR_IGUAL = 37,               /* MENOR_IGUAL  */
  YYSYMBOL_MAYOR_IGUAL = 38,               /* MAYOR_IGUAL  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_OR = 40,                        /* OR  */
  YYSYMBOL_41_ = 41,                       /* '<'  */
  YYSYMBOL_42_ = 42,                       /* '>'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_48_ = 48,                       /* '!'  */
  YYSYMBOL_UNARIO = 49,                    /* UNARIO  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ')'  */
  YYSYMBOL_54_ = 54,                       /* '='  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_57_ = 57,                       /* '{'  */
  YYSYMBOL_58_ = 58,                       /* '}'  */
  YYSYMBOL_59_ = 59,                       /* ';'  */
  YYSYMBOL_60_ = 60,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_programa = 62,                  /* programa  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_64_2 = 64,                      /* $@2  */
  YYSYMBOL_imports = 65,                   /* imports  */
  YYSYMBOL_import_stmt = 66,               /* import_stmt  */
  YYSYMBOL_import_list = 67,               /* import_list  */
  YYSYMBOL_declaraciones_top = 68,         /* declaraciones_top  */
  YYSYMBOL_declaracion_top = 69,           /* declaracion_top  */
  YYSYMBOL_type_decl = 70,                 /* type_decl  */
  YYSYMBOL_variable_top = 71,              /* variable_top  */
  YYSYMBOL_var_block = 72,                 /* var_block  */
  YYSYMBOL_var_spec = 73,                  /* var_spec  */
  YYSYMBOL_constante_top = 74,             /* constante_top  */
  YYSYMBOL_const_block = 75,               /* const_block  */
  YYSYMBOL_const_spec = 76,                /* const_spec  */
  YYSYMBOL_funcion = 77,                   /* funcion  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_opt_tipo_retorno = 79,          /* opt_tipo_retorno  */
  YYSYMBOL_parametros = 80,                /* parametros  */
  YYSYMBOL_lista_parametros = 81,          /* lista_parametros  */
  YYSYMBOL_parametro = 82,                 /* parametro  */
  YYSYMBOL_tipo_retorno = 83,              /* tipo_retorno  */
  YYSYMBOL_lista_tipos = 84,               /* lista_tipos  */
  YYSYMBOL_variable = 85,                  /* variable  */
  YYSYMBOL_lista_ids = 86,                 /* lista_ids  */
  YYSYMBOL_lista_expresiones = 87,         /* lista_expresiones  */
  YYSYMBOL_constante = 88,                 /* constante  */
  YYSYMBOL_tipo = 89,                      /* tipo  */
  YYSYMBOL_bloque = 90,                    /* bloque  */
  YYSYMBOL_91_4 = 91,                      /* $@4  */
  YYSYMBOL_sentencias = 92,                /* sentencias  */
  YYSYMBOL_sentencia = 93,                 /* sentencia  */
  YYSYMBOL_94_5 = 94,                      /* $@5  */
  YYSYMBOL_95_6 = 95,                      /* $@6  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_97_8 = 97,                      /* $@8  */
  YYSYMBOL_declaracion_corta = 98,         /* declaracion_corta  */
  YYSYMBOL_declaracion_corta_multiple = 99, /* declaracion_corta_multiple  */
  YYSYMBOL_asignacion = 100,               /* asignacion  */
  YYSYMBOL_asignacion_multiple = 101,      /* asignacion_multiple  */
  YYSYMBOL_inicializacion = 102,           /* inicializacion  */
  YYSYMBOL_condicion = 103,                /* condicion  */
  YYSYMBOL_post_iteracion = 104,           /* post_iteracion  */
  YYSYMBOL_casos = 105,                    /* casos  */
  YYSYMBOL_caso = 106,                     /* caso  */
  YYSYMBOL_expresion = 107,                /* expresion  */
  YYSYMBOL_argumentos = 108,               /* argumentos  */
  YYSYMBOL_lista_argumentos = 109          /* lista_argumentos  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   597

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  271

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      51,    53,    45,    43,    55,    44,    50,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    60,    59,
      41,    54,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    68,    87,    86,   108,   109,   113,   114,
     118,   119,   123,   124,   128,   129,   130,   131,   135,   144,
     158,   167,   173,   177,   178,   179,   183,   196,   205,   214,
     227,   236,   240,   241,   242,   246,   259,   268,   274,   284,
     283,   304,   307,   311,   312,   316,   317,   321,   330,   346,
     350,   357,   358,   362,   375,   384,   390,   391,   395,   399,
     407,   408,   412,   425,   437,   442,   454,   458,   466,   465,
     476,   477,   481,   493,   503,   502,   511,   510,   519,   518,
     527,   526,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   550,   567,   571,   578,   585,
     592,   599,   606,   616,   620,   621,   622,   623,   624,   628,
     629,   633,   634,   635,   639,   640,   644,   645,   649,   661,
     665,   669,   673,   678,   682,   686,   690,   698,   706,   714,
     722,   730,   734,   738,   742,   746,   750,   754,   762,   770,
     778,   786,   794,   802,   810,   818,   826,   830,   838,   843,
     848,   864,   865,   869,   870
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFICADOR",
  "TIPO_DATO", "CADENA", "ENTERO", "TRUE", "FALSE", "REAL", "CARACTER",
  "PACKAGE", "IMPORT", "FUNC", "VAR", "CONST", "TYPE", "STRUCT", "IF",
  "ELSE", "FOR", "SWITCH", "CASE", "DEFAULT", "RETURN", "BREAK",
  "CONTINUE", "DECLARACION_CORTA", "INCREMENTO", "DECREMENTO", "MAS_IGUAL",
  "MENOS_IGUAL", "POR_IGUAL", "DIV_IGUAL", "MOD_IGUAL", "IGUALDAD",
  "DIFERENTE", "MENOR_IGUAL", "MAYOR_IGUAL", "AND", "OR", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UNARIO", "'.'", "'('", "'['",
  "')'", "'='", "','", "']'", "'{'", "'}'", "';'", "':'", "$accept",
  "programa", "$@1", "$@2", "imports", "import_stmt", "import_list",
  "declaraciones_top", "declaracion_top", "type_decl", "variable_top",
  "var_block", "var_spec", "constante_top", "const_block", "const_spec",
  "funcion", "$@3", "opt_tipo_retorno", "parametros", "lista_parametros",
  "parametro", "tipo_retorno", "lista_tipos", "variable", "lista_ids",
  "lista_expresiones", "constante", "tipo", "bloque", "$@4", "sentencias",
  "sentencia", "$@5", "$@6", "$@7", "$@8", "declaracion_corta",
  "declaracion_corta_multiple", "asignacion", "asignacion_multiple",
  "inicializacion", "condicion", "post_iteracion", "casos", "caso",
  "expresion", "argumentos", "lista_argumentos", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-250)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    29,    45,    96,  -250,   105,  -250,   114,   105,  -250,
     166,  -250,   110,  -250,   166,   115,     1,    25,   117,  -250,
    -250,  -250,  -250,  -250,  -250,    88,  -250,    40,   118,    75,
     122,     3,  -250,  -250,    84,  -250,  -250,    31,   304,    86,
      93,    77,  -250,   304,    90,   103,   108,  -250,  -250,   139,
      94,     3,    98,   100,  -250,  -250,  -250,  -250,  -250,  -250,
     304,   304,   304,   304,   304,   304,   485,   304,   304,    99,
    -250,  -250,   485,   304,   304,   102,  -250,  -250,    17,   101,
     104,  -250,     3,  -250,   304,   304,   -35,   -35,   144,   144,
     144,   445,  -250,  -250,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   172,   304,   304,
     485,   485,   304,   485,   485,   304,   174,  -250,   133,   139,
    -250,   485,   137,   136,   465,  -250,   545,   545,   158,   158,
     525,   505,   158,   158,   209,   209,   144,   144,   144,  -250,
     140,   372,   485,   485,     3,     3,   135,  -250,  -250,  -250,
    -250,   304,  -250,  -250,  -250,  -250,    59,  -250,  -250,  -250,
     485,  -250,     3,  -250,  -250,   221,   -17,   195,   196,   304,
      95,   304,   304,  -250,  -250,  -250,  -250,   -13,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,   425,   304,   210,    -1,    36,
     106,   485,  -250,  -250,  -250,  -250,  -250,   155,   425,   347,
     485,   304,   304,   212,   304,   304,   304,   304,   304,   304,
     485,  -250,   304,   162,   304,  -250,   304,   164,   135,   135,
     135,   304,   135,    27,   165,   397,   165,  -250,   485,   485,
     485,   485,   485,   485,   485,   304,   165,   485,   304,  -250,
     200,   202,   163,   485,  -250,   304,   180,   -10,  -250,   304,
     304,   485,   485,   135,   277,   304,   321,  -250,  -250,  -250,
     485,   485,  -250,  -250,  -250,   135,   425,  -250,   277,  -250,
     277
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     1,     0,    13,     0,    13,     7,
       5,     8,     0,     6,     3,     0,     0,     0,     0,    12,
      17,    15,    16,    14,    11,     0,    39,     0,    25,     0,
      34,     0,    10,     9,     0,    65,    64,     0,     0,    21,
       0,     0,    24,     0,     0,    38,     0,    33,    18,    44,
       0,     0,   118,     0,   122,   119,   123,   124,   120,   121,
       0,     0,     0,     0,     0,     0,    20,     0,     0,    28,
      22,    23,    30,     0,     0,    37,    31,    32,     0,     0,
      43,    46,     0,    67,   152,     0,   144,   145,   141,   140,
     139,     0,   142,   143,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
      19,    27,     0,    29,    36,     0,     0,    47,    42,     0,
      66,   154,     0,   151,     0,   125,   131,   132,   135,   136,
     137,   138,   133,   134,   126,   127,   128,   129,   130,   148,
       0,     0,    26,    35,     0,     0,     0,    41,    49,    45,
     150,     0,   149,   146,   147,    48,     0,    52,    68,    40,
     153,    50,     0,    71,    51,     0,   118,     0,     0,     0,
     108,     0,    73,    92,    93,    69,    90,     0,    91,    94,
      70,    86,    87,    88,    89,    85,     0,     0,     0,     0,
       0,    74,    82,   104,   105,   106,   107,     0,    80,     0,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    59,     0,    55,     0,    56,     0,     0,     0,     0,
       0,   110,     0,     0,    96,     0,   103,    58,    98,    99,
     100,   101,   102,    97,    54,     0,    57,    63,     0,    75,
       0,     0,     0,   109,    81,     0,     0,     0,   115,     0,
       0,    53,    62,     0,     0,   113,     0,    71,    84,   114,
      60,    61,    77,    79,   112,     0,   111,    71,   117,    83,
     116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -250,  -250,  -250,  -250,  -250,   215,  -250,   235,  -250,  -250,
    -250,  -250,   203,  -250,  -250,   205,  -250,  -250,  -250,  -250,
    -250,   129,  -250,  -250,  -250,    85,  -183,  -250,    44,  -137,
    -250,  -249,     4,  -250,  -250,  -250,  -250,    83,    87,  -169,
      92,  -250,  -250,  -250,  -250,    16,   -38,   159,  -250
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     5,     6,     8,     9,    25,    10,    19,    20,
      21,    41,    42,    22,    46,    47,    23,    34,   146,    79,
      80,    81,   147,   156,   176,   177,   224,   178,    39,   179,
     163,   165,   180,   218,   219,   220,   222,   181,   182,   183,
     184,   197,   242,   265,   247,   248,   185,   122,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,   195,    35,    36,    27,    72,    35,    36,   268,   159,
     186,     1,   245,   246,   201,   107,   108,   109,   270,   226,
      35,    36,    86,    87,    88,    89,    90,    91,    29,   110,
     111,   236,     3,   192,    84,   113,   114,    50,   187,    35,
      36,   202,   203,    35,    36,     4,   121,   124,   258,   245,
     246,    37,    28,   212,   187,    37,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,    37,
     121,   141,   116,    44,   142,    48,    30,   143,    35,    36,
      40,   239,   240,   241,    69,   244,   264,    51,    37,    75,
     214,   203,    37,    32,    38,    83,    35,    36,   166,    53,
      54,    55,    56,    57,    58,    59,    35,    36,    -2,    35,
      36,    45,   161,   160,   162,    24,   262,     7,    26,    11,
      31,    40,   117,    60,    61,    45,   120,    37,   269,    43,
      70,   191,   198,   199,   200,    49,    35,    36,    62,    63,
      67,    33,    78,    64,    73,    37,    65,    68,   210,    84,
      82,    85,   158,   112,   118,    37,   115,    74,    37,   119,
     216,    76,   148,   225,   225,    12,   228,   229,   230,   231,
     232,   233,    92,    93,   234,   139,   225,   144,   237,    15,
      16,    17,    18,   243,   145,    37,    92,    93,   155,   157,
     150,   151,   158,   153,   107,   108,   109,   251,   188,   190,
     252,   102,   103,   104,   105,   106,   164,   256,   107,   108,
     109,   260,   261,   211,   221,   227,   235,   266,   238,   253,
     249,   254,   255,    13,   166,    53,    54,    55,    56,    57,
      58,    59,   213,   215,   217,   167,   168,    92,    93,   169,
     257,   170,   171,    14,    71,   172,   173,   174,   149,    60,
      61,    77,   189,   193,   104,   105,   106,   194,   263,   107,
     108,   109,   196,   259,    62,    63,     0,   140,     0,    64,
       0,     0,    65,     0,     0,     0,     0,     0,   158,   175,
     166,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,   167,   168,     0,     0,   169,     0,   170,   171,     0,
       0,   172,   173,   174,     0,    60,    61,    52,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
      62,    63,     0,     0,     0,    64,     0,     0,    65,     0,
       0,     0,    60,    61,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    63,    92,
      93,     0,    64,     0,     0,    65,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       0,   107,   108,   109,     0,    92,    93,     0,     0,     0,
       0,   267,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,   107,   108,   109,
      92,    93,     0,     0,   223,     0,     0,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,     0,   107,   108,   109,    92,    93,     0,   154,     0,
       0,     0,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     0,   107,   108,   109,
       0,     0,   250,    92,    93,   204,   205,   206,   207,   208,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,     0,   209,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,   125,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,   152,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,     0,     0,
      94,    95,    96,    97,    98,     0,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,     0,     0,
      94,    95,    96,    97,     0,     0,   100,   101,   102,   103,
     104,   105,   106,    92,    93,   107,   108,   109,     0,     0,
       0,     0,    96,    97,     0,     0,   100,   101,   102,   103,
     104,   105,   106,     0,     0,   107,   108,   109
};

static const yytype_int16 yycheck[] =
{
      38,   170,     3,     4,     3,    43,     3,     4,   257,   146,
      27,    11,    22,    23,    27,    50,    51,    52,   267,   202,
       3,     4,    60,    61,    62,    63,    64,    65,     3,    67,
      68,   214,     3,   170,    51,    73,    74,     6,    55,     3,
       4,    54,    55,     3,     4,     0,    84,    85,    58,    22,
      23,    52,    51,    54,    55,    52,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    52,
     108,   109,    55,    29,   112,    31,    51,   115,     3,     4,
       3,   218,   219,   220,    40,   222,   255,    56,    52,    45,
      54,    55,    52,     5,    54,    51,     3,     4,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,    12,     3,
       4,     3,    53,   151,    55,     5,   253,    12,     3,     5,
       3,     3,    78,    28,    29,     3,    82,    52,   265,    54,
      53,   169,   170,   171,   172,    51,     3,     4,    43,    44,
      54,    53,     3,    48,    54,    52,    51,    54,   186,    51,
      56,    51,    57,    54,    53,    52,    54,    54,    52,    55,
      54,    53,   118,   201,   202,    51,   204,   205,   206,   207,
     208,   209,    28,    29,   212,     3,   214,     3,   216,    13,
      14,    15,    16,   221,    51,    52,    28,    29,   144,   145,
      53,    55,    57,    53,    50,    51,    52,   235,     3,     3,
     238,    43,    44,    45,    46,    47,   162,   245,    50,    51,
      52,   249,   250,     3,    59,     3,    54,   255,    54,    19,
      55,    19,    59,     8,     3,     4,     5,     6,     7,     8,
       9,    10,   188,   189,   190,    14,    15,    28,    29,    18,
      60,    20,    21,     8,    41,    24,    25,    26,   119,    28,
      29,    46,   167,   170,    45,    46,    47,   170,   254,    50,
      51,    52,   170,   247,    43,    44,    -1,   108,    -1,    48,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    58,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    14,    15,    -1,    -1,    18,    -1,    20,    21,    -1,
      -1,    24,    25,    26,    -1,    28,    29,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    -1,
      -1,    -1,    28,    29,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    28,
      29,    -1,    48,    -1,    -1,    51,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    -1,
      -1,    50,    51,    52,    -1,    28,    29,    -1,    -1,    -1,
      -1,    60,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    50,    51,    52,
      28,    29,    -1,    -1,    57,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      -1,    -1,    50,    51,    52,    28,    29,    -1,    56,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    -1,    -1,    50,    51,    52,
      -1,    -1,    55,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    -1,    54,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    53,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    53,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    -1,    -1,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    28,    29,    50,    51,    52,    -1,    -1,
      -1,    -1,    37,    38,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    -1,    -1,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    62,     3,     0,    63,    64,    12,    65,    66,
      68,     5,    51,    66,    68,    13,    14,    15,    16,    69,
      70,    71,    74,    77,     5,    67,     3,     3,    51,     3,
      51,     3,     5,    53,    78,     3,     4,    52,    54,    89,
       3,    72,    73,    54,    89,     3,    75,    76,    89,    51,
       6,    56,     3,     4,     5,     6,     7,     8,     9,    10,
      28,    29,    43,    44,    48,    51,   107,    54,    54,    89,
      53,    73,   107,    54,    54,    89,    53,    76,     3,    80,
      81,    82,    56,    89,    51,    51,   107,   107,   107,   107,
     107,   107,    28,    29,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    50,    51,    52,
     107,   107,    54,   107,   107,    54,    55,    89,    53,    55,
      89,   107,   108,   109,   107,    53,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,     3,
     108,   107,   107,   107,     3,    51,    79,    83,    89,    82,
      53,    55,    53,    53,    56,    89,    84,    89,    57,    90,
     107,    53,    55,    91,    89,    92,     3,    14,    15,    18,
      20,    21,    24,    25,    26,    58,    85,    86,    88,    90,
      93,    98,    99,   100,   101,   107,    27,    55,     3,    86,
       3,   107,    90,    98,    99,   100,   101,   102,   107,   107,
     107,    27,    54,    55,    30,    31,    32,    33,    34,    54,
     107,     3,    54,    89,    54,    89,    54,    89,    94,    95,
      96,    59,    97,    57,    87,   107,    87,     3,   107,   107,
     107,   107,   107,   107,   107,    54,    87,   107,    54,    90,
      90,    90,   103,   107,    90,    22,    23,   105,   106,    55,
      55,   107,   107,    19,    19,    59,   107,    60,    58,   106,
     107,   107,    90,    93,   100,   104,   107,    60,    92,    90,
      92
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    63,    62,    64,    62,    65,    65,    66,    66,
      67,    67,    68,    68,    69,    69,    69,    69,    70,    71,
      71,    71,    71,    72,    72,    72,    73,    73,    73,    74,
      74,    74,    75,    75,    75,    76,    76,    76,    76,    78,
      77,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    91,    90,
      92,    92,    93,    93,    94,    93,    95,    93,    96,    93,
      97,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    98,    99,   100,   100,   100,
     100,   100,   100,   101,   102,   102,   102,   102,   102,   103,
     103,   104,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     0,     4,     2,     1,     2,     4,
       2,     1,     2,     0,     1,     1,     1,     1,     3,     5,
       4,     3,     4,     2,     1,     0,     4,     3,     2,     5,
       4,     4,     2,     1,     0,     4,     3,     2,     1,     0,
       8,     1,     0,     1,     0,     3,     1,     2,     4,     1,
       3,     3,     1,     5,     4,     3,     3,     4,     3,     3,
       3,     3,     5,     4,     1,     1,     4,     3,     0,     4,
       2,     0,     2,     1,     0,     4,     0,     6,     0,     6,
       0,     4,     2,     7,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     0,     1,
       0,     1,     1,     0,     2,     1,     4,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     2,     2,     2,     4,     4,     3,     4,
       4,     1,     0,     3,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 69 "parser.y"
    {
        initSymbolTable();
    }
#line 1559 "parser.tab.c"
    break;

  case 3: /* programa: PACKAGE IDENTIFICADOR $@1 imports declaraciones_top  */
#line 73 "parser.y"
    {
    if (errorCount == 0 && semanticErrors == 0 && lexicalErrors == 0) {
        printf("\nAnalisis completado exitosamente.\n");
    } else {
        printf("\nSe encontraron:\n");
        if (lexicalErrors > 0) 
            printf("  - %d error(es) lexico(s)\n", lexicalErrors);
        if (errorCount > 0) 
            printf("  - %d error(es) sintactico(s)\n", errorCount);
        if (semanticErrors > 0) 
            printf("  - %d error(es) semantico(s)\n", semanticErrors);
    }
    }
#line 1577 "parser.tab.c"
    break;

  case 4: /* $@2: %empty  */
#line 87 "parser.y"
{
    initSymbolTable();
}
#line 1585 "parser.tab.c"
    break;

  case 5: /* programa: PACKAGE IDENTIFICADOR $@2 declaraciones_top  */
#line 91 "parser.y"
{
    if (errorCount == 0 && semanticErrors == 0 && lexicalErrors == 0) {
        printf("\nAnalisis completado exitosamente.\n");
    } else {
        printf("\nAnalisis finalizado.\n");
        printf("\nSe encontraron:\n");
        if (lexicalErrors > 0) 
            printf("  - %d error(es) lexico(s)\n", lexicalErrors);
        if (errorCount > 0) 
            printf("  - %d error(es) sintactico(s)\n", errorCount);
        if (semanticErrors > 0) 
            printf("  - %d error(es) semantico(s)\n", semanticErrors);
    }
}
#line 1604 "parser.tab.c"
    break;

  case 18: /* type_decl: TYPE IDENTIFICADOR tipo  */
#line 136 "parser.y"
    {
        insertSymbol((yyvsp[-1].cadena), SYM_TYPE, (yyvsp[0].tipo), 
            (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        free((yyvsp[-1].cadena));
    }
#line 1614 "parser.tab.c"
    break;

  case 19: /* variable_top: VAR IDENTIFICADOR tipo '=' expresion  */
#line 145 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_VARIABLE, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en inicializacion de '%s': esperado %s, obtenido %s",
                    (yyvsp[-3].cadena), dataTypeToString((yyvsp[-2].tipo)), dataTypeToString((yyvsp[0].tipo)));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1632 "parser.tab.c"
    break;

  case 20: /* variable_top: VAR IDENTIFICADOR '=' expresion  */
#line 159 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1645 "parser.tab.c"
    break;

  case 21: /* variable_top: VAR IDENTIFICADOR tipo  */
#line 168 "parser.y"
    {
        insertSymbol((yyvsp[-1].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        free((yyvsp[-1].cadena));
    }
#line 1655 "parser.tab.c"
    break;

  case 26: /* var_spec: IDENTIFICADOR tipo '=' expresion  */
#line 184 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_VARIABLE, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en inicializacion de '%s'", (yyvsp[-3].cadena));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1672 "parser.tab.c"
    break;

  case 27: /* var_spec: IDENTIFICADOR '=' expresion  */
#line 197 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1685 "parser.tab.c"
    break;

  case 28: /* var_spec: IDENTIFICADOR tipo  */
#line 206 "parser.y"
    {
        insertSymbol((yyvsp[-1].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        free((yyvsp[-1].cadena));
    }
#line 1695 "parser.tab.c"
    break;

  case 29: /* constante_top: CONST IDENTIFICADOR tipo '=' expresion  */
#line 215 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_CONSTANT, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en constante '%s'", (yyvsp[-3].cadena));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1712 "parser.tab.c"
    break;

  case 30: /* constante_top: CONST IDENTIFICADOR '=' expresion  */
#line 228 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_CONSTANT, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1725 "parser.tab.c"
    break;

  case 35: /* const_spec: IDENTIFICADOR tipo '=' expresion  */
#line 247 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_CONSTANT, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en constante '%s'", (yyvsp[-3].cadena));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1742 "parser.tab.c"
    break;

  case 36: /* const_spec: IDENTIFICADOR '=' expresion  */
#line 260 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_CONSTANT, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1755 "parser.tab.c"
    break;

  case 37: /* const_spec: IDENTIFICADOR tipo  */
#line 269 "parser.y"
    {
        semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
            "Las constantes deben ser inicializadas: '%s'", (yyvsp[-1].cadena));
        free((yyvsp[-1].cadena));
    }
#line 1765 "parser.tab.c"
    break;

  case 38: /* const_spec: IDENTIFICADOR  */
#line 275 "parser.y"
    {
        semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
            "Las constantes deben tener tipo e inicializacion: '%s'", (yyvsp[0].cadena));
        free((yyvsp[0].cadena));
    }
#line 1775 "parser.tab.c"
    break;

  case 39: /* $@3: %empty  */
#line 284 "parser.y"
    {
        currentFunction = insertSymbol((yyvsp[0].cadena), SYM_FUNCTION, TYPE_VOID, 
                                       (yylsp[0]).first_line, (yylsp[0]).first_column);
        hasReturnStatement = false;
    }
#line 1785 "parser.tab.c"
    break;

  case 40: /* funcion: FUNC IDENTIFICADOR $@3 '(' parametros ')' opt_tipo_retorno bloque  */
#line 290 "parser.y"
    {
        if (currentFunction && (yyvsp[-1].cadena)) {
            DataType retType = stringToDataType((yyvsp[-1].cadena));
            setReturnType(currentFunction, retType);
           
        }
        currentFunction = NULL;
        free((yyvsp[-6].cadena));
        if ((yyvsp[-1].cadena)) free((yyvsp[-1].cadena));
        (yyval.simbolo) = currentFunction;
    }
#line 1801 "parser.tab.c"
    break;

  case 41: /* opt_tipo_retorno: tipo_retorno  */
#line 305 "parser.y"
    { (yyval.cadena) = (yyvsp[0].cadena); }
#line 1807 "parser.tab.c"
    break;

  case 42: /* opt_tipo_retorno: %empty  */
#line 307 "parser.y"
    { (yyval.cadena) = NULL; }
#line 1813 "parser.tab.c"
    break;

  case 47: /* parametro: IDENTIFICADOR tipo  */
#line 322 "parser.y"
    {
        Symbol *param = insertSymbol((yyvsp[-1].cadena), SYM_PARAMETER, (yyvsp[0].tipo), 
                                     (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        if (param && currentFunction) {
            addParameter(currentFunction, (yyvsp[-1].cadena), (yyvsp[0].tipo));
        }
        free((yyvsp[-1].cadena));
    }
#line 1826 "parser.tab.c"
    break;

  case 48: /* parametro: IDENTIFICADOR ',' IDENTIFICADOR tipo  */
#line 331 "parser.y"
    {
        Symbol *param1 = insertSymbol((yyvsp[-3].cadena), SYM_PARAMETER, (yyvsp[0].tipo), 
                                      (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        Symbol *param2 = insertSymbol((yyvsp[-1].cadena), SYM_PARAMETER, (yyvsp[0].tipo), 
                                      (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        if (currentFunction) {
            if (param1) addParameter(currentFunction, (yyvsp[-3].cadena), (yyvsp[0].tipo));
            if (param2) addParameter(currentFunction, (yyvsp[-1].cadena), (yyvsp[0].tipo));
        }
        free((yyvsp[-3].cadena));
        free((yyvsp[-1].cadena));
    }
#line 1843 "parser.tab.c"
    break;

  case 49: /* tipo_retorno: tipo  */
#line 347 "parser.y"
    {
        (yyval.cadena) = strdup(dataTypeToString((yyvsp[0].tipo)));
    }
#line 1851 "parser.tab.c"
    break;

  case 50: /* tipo_retorno: '(' lista_tipos ')'  */
#line 351 "parser.y"
    {
        (yyval.cadena) = strdup("multiple");
    }
#line 1859 "parser.tab.c"
    break;

  case 53: /* variable: VAR IDENTIFICADOR tipo '=' expresion  */
#line 363 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_VARIABLE, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en inicializacion de '%s'", (yyvsp[-3].cadena));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1876 "parser.tab.c"
    break;

  case 54: /* variable: VAR IDENTIFICADOR '=' expresion  */
#line 376 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1889 "parser.tab.c"
    break;

  case 55: /* variable: VAR IDENTIFICADOR tipo  */
#line 385 "parser.y"
    {
        insertSymbol((yyvsp[-1].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                   (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        free((yyvsp[-1].cadena));
    }
#line 1899 "parser.tab.c"
    break;

  case 58: /* lista_ids: lista_ids ',' IDENTIFICADOR  */
#line 396 "parser.y"
    {
        free((yyvsp[0].cadena));
    }
#line 1907 "parser.tab.c"
    break;

  case 59: /* lista_ids: IDENTIFICADOR ',' IDENTIFICADOR  */
#line 400 "parser.y"
    {
        free((yyvsp[-2].cadena));
        free((yyvsp[0].cadena));
    }
#line 1916 "parser.tab.c"
    break;

  case 62: /* constante: CONST IDENTIFICADOR tipo '=' expresion  */
#line 413 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-3].cadena), SYM_CONSTANT, (yyvsp[-2].tipo), 
                                   (yylsp[-3]).first_line, (yylsp[-3]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
            if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo incompatible en constante '%s'", (yyvsp[-3].cadena));
            }
        }
        free((yyvsp[-3].cadena));
    }
#line 1933 "parser.tab.c"
    break;

  case 63: /* constante: CONST IDENTIFICADOR '=' expresion  */
#line 426 "parser.y"
    {
        Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_CONSTANT, (yyvsp[0].tipo), 
                                   (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        if (sym) {
            setSymbolInitialized(sym);
        }
        free((yyvsp[-2].cadena));
    }
#line 1946 "parser.tab.c"
    break;

  case 64: /* tipo: TIPO_DATO  */
#line 438 "parser.y"
    {
        (yyval.tipo) = stringToDataType((yyvsp[0].cadena));
        free((yyvsp[0].cadena));
    }
#line 1955 "parser.tab.c"
    break;

  case 65: /* tipo: IDENTIFICADOR  */
#line 443 "parser.y"
    {
        Symbol *typeSym = lookupSymbol((yyvsp[0].cadena));
        if (typeSym && typeSym->kind == SYM_TYPE) {
            (yyval.tipo) = typeSym->type;
        } else {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipo no definido: '%s'", (yyvsp[0].cadena));
            (yyval.tipo) = TYPE_UNKNOWN;
        }
        free((yyvsp[0].cadena));
    }
#line 1971 "parser.tab.c"
    break;

  case 66: /* tipo: '[' ENTERO ']' tipo  */
#line 455 "parser.y"
    {
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 1979 "parser.tab.c"
    break;

  case 67: /* tipo: '[' ']' tipo  */
#line 459 "parser.y"
    {
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 1987 "parser.tab.c"
    break;

  case 68: /* $@4: %empty  */
#line 466 "parser.y"
    {
        enterScope();
    }
#line 1995 "parser.tab.c"
    break;

  case 69: /* bloque: '{' $@4 sentencias '}'  */
#line 470 "parser.y"
    {
        exitScope();
    }
#line 2003 "parser.tab.c"
    break;

  case 72: /* sentencia: RETURN expresion  */
#line 482 "parser.y"
    {
        hasReturnStatement = true;
        if (currentFunction) {
            if (!areTypesCompatible(currentFunction->returnType, (yyvsp[0].tipo))) {
                semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                    "Tipo de retorno incompatible: esperado %s, obtenido %s",
                    dataTypeToString(currentFunction->returnType),
                    dataTypeToString((yyvsp[0].tipo)));
            }
        }
    }
#line 2019 "parser.tab.c"
    break;

  case 73: /* sentencia: RETURN  */
#line 494 "parser.y"
    {
        hasReturnStatement = true;
        if (currentFunction && currentFunction->returnType != TYPE_VOID) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "La funcion debe retornar un valor de tipo %s",
                dataTypeToString(currentFunction->returnType));
        }
    }
#line 2032 "parser.tab.c"
    break;

  case 74: /* $@5: %empty  */
#line 503 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_BOOL && (yyvsp[0].tipo) != TYPE_UNKNOWN) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
#line 2043 "parser.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 511 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_BOOL && (yyvsp[0].tipo) != TYPE_UNKNOWN) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
#line 2054 "parser.tab.c"
    break;

  case 78: /* $@7: %empty  */
#line 519 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_BOOL && (yyvsp[0].tipo) != TYPE_UNKNOWN) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "La condicion del if debe ser de tipo bool");
        }
    }
#line 2065 "parser.tab.c"
    break;

  case 80: /* $@8: %empty  */
#line 527 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_BOOL && (yyvsp[0].tipo) != TYPE_UNKNOWN) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "La condicion del for debe ser de tipo bool");
        }
    }
#line 2076 "parser.tab.c"
    break;

  case 95: /* declaracion_corta: IDENTIFICADOR DECLARACION_CORTA expresion  */
#line 551 "parser.y"
    {
        if (isDeclaredInCurrentScope((yyvsp[-2].cadena))) {
            semanticError((yylsp[-2]).first_line, (yylsp[-2]).first_column,
                "Redeclaracion de '%s' con :=", (yyvsp[-2].cadena));
        } else {
            Symbol *sym = insertSymbol((yyvsp[-2].cadena), SYM_VARIABLE, (yyvsp[0].tipo), 
                                       (yylsp[-2]).first_line, (yylsp[-2]).first_column);
            if (sym) {
                setSymbolInitialized(sym);
            }
        }
        free((yyvsp[-2].cadena));
    }
#line 2094 "parser.tab.c"
    break;

  case 97: /* asignacion: expresion '=' expresion  */
#line 572 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en asignacion");
        }
    }
#line 2105 "parser.tab.c"
    break;

  case 98: /* asignacion: expresion MAS_IGUAL expresion  */
#line 579 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en operacion +=");
        }
    }
#line 2116 "parser.tab.c"
    break;

  case 99: /* asignacion: expresion MENOS_IGUAL expresion  */
#line 586 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en operacion -=");
        }
    }
#line 2127 "parser.tab.c"
    break;

  case 100: /* asignacion: expresion POR_IGUAL expresion  */
#line 593 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en operacion *=");
        }
    }
#line 2138 "parser.tab.c"
    break;

  case 101: /* asignacion: expresion DIV_IGUAL expresion  */
#line 600 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en operacion /=");
        }
    }
#line 2149 "parser.tab.c"
    break;

  case 102: /* asignacion: expresion MOD_IGUAL expresion  */
#line 607 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Tipos incompatibles en operacion %=");
        }
    }
#line 2160 "parser.tab.c"
    break;

  case 118: /* expresion: IDENTIFICADOR  */
#line 650 "parser.y"
    {
        Symbol *sym = lookupSymbol((yyvsp[0].cadena));
        if (!sym) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "Variable no declarada: '%s'", (yyvsp[0].cadena));
            (yyval.tipo) = TYPE_UNKNOWN;
        } else {           
            (yyval.tipo) = sym->type;
        }
        free((yyvsp[0].cadena));
    }
#line 2176 "parser.tab.c"
    break;

  case 119: /* expresion: ENTERO  */
#line 662 "parser.y"
    {
        (yyval.tipo) = TYPE_INT;
    }
#line 2184 "parser.tab.c"
    break;

  case 120: /* expresion: REAL  */
#line 666 "parser.y"
    {
        (yyval.tipo) = TYPE_FLOAT64;
    }
#line 2192 "parser.tab.c"
    break;

  case 121: /* expresion: CARACTER  */
#line 670 "parser.y"
    {
        (yyval.tipo) = TYPE_RUNE;
    }
#line 2200 "parser.tab.c"
    break;

  case 122: /* expresion: CADENA  */
#line 674 "parser.y"
    {
        (yyval.tipo) = TYPE_STRING;
        free((yyvsp[0].cadena));
    }
#line 2209 "parser.tab.c"
    break;

  case 123: /* expresion: TRUE  */
#line 679 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2217 "parser.tab.c"
    break;

  case 124: /* expresion: FALSE  */
#line 683 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2225 "parser.tab.c"
    break;

  case 125: /* expresion: '(' expresion ')'  */
#line 687 "parser.y"
    {
        (yyval.tipo) = (yyvsp[-1].tipo);
    }
#line 2233 "parser.tab.c"
    break;

  case 126: /* expresion: expresion '+' expresion  */
#line 691 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "Tipos incompatibles en operacion +");
        }
        (yyval.tipo) = getResultType((yyvsp[-2].tipo), (yyvsp[0].tipo), "+");
    }
#line 2245 "parser.tab.c"
    break;

  case 127: /* expresion: expresion '-' expresion  */
#line 699 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "Tipos incompatibles en operacion -");
        }
        (yyval.tipo) = getResultType((yyvsp[-2].tipo), (yyvsp[0].tipo), "-");
    }
#line 2257 "parser.tab.c"
    break;

  case 128: /* expresion: expresion '*' expresion  */
#line 707 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "Tipos incompatibles en operacion *");
        }
        (yyval.tipo) = getResultType((yyvsp[-2].tipo), (yyvsp[0].tipo), "*");
    }
#line 2269 "parser.tab.c"
    break;

  case 129: /* expresion: expresion '/' expresion  */
#line 715 "parser.y"
    {
        if (!areTypesCompatible((yyvsp[-2].tipo), (yyvsp[0].tipo))) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "Tipos incompatibles en operacion /");
        }
        (yyval.tipo) = getResultType((yyvsp[-2].tipo), (yyvsp[0].tipo), "/");
    }
#line 2281 "parser.tab.c"
    break;

  case 130: /* expresion: expresion '%' expresion  */
#line 723 "parser.y"
    {
        if ((yyvsp[-2].tipo) != TYPE_INT || (yyvsp[0].tipo) != TYPE_INT) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador %% requiere operandos enteros");
        }
        (yyval.tipo) = TYPE_INT;
    }
#line 2293 "parser.tab.c"
    break;

  case 131: /* expresion: expresion IGUALDAD expresion  */
#line 731 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2301 "parser.tab.c"
    break;

  case 132: /* expresion: expresion DIFERENTE expresion  */
#line 735 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2309 "parser.tab.c"
    break;

  case 133: /* expresion: expresion '<' expresion  */
#line 739 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2317 "parser.tab.c"
    break;

  case 134: /* expresion: expresion '>' expresion  */
#line 743 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2325 "parser.tab.c"
    break;

  case 135: /* expresion: expresion MENOR_IGUAL expresion  */
#line 747 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2333 "parser.tab.c"
    break;

  case 136: /* expresion: expresion MAYOR_IGUAL expresion  */
#line 751 "parser.y"
    {
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2341 "parser.tab.c"
    break;

  case 137: /* expresion: expresion AND expresion  */
#line 755 "parser.y"
    {
        if ((yyvsp[-2].tipo) != TYPE_BOOL || (yyvsp[0].tipo) != TYPE_BOOL) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador && requiere operandos booleanos");
        }
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2353 "parser.tab.c"
    break;

  case 138: /* expresion: expresion OR expresion  */
#line 763 "parser.y"
    {
        if ((yyvsp[-2].tipo) != TYPE_BOOL || (yyvsp[0].tipo) != TYPE_BOOL) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador || requiere operandos booleanos");
        }
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2365 "parser.tab.c"
    break;

  case 139: /* expresion: '!' expresion  */
#line 771 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_BOOL) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador ! requiere un operando booleano");
        }
        (yyval.tipo) = TYPE_BOOL;
    }
#line 2377 "parser.tab.c"
    break;

  case 140: /* expresion: '-' expresion  */
#line 779 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_INT && (yyvsp[0].tipo) != TYPE_FLOAT32 && (yyvsp[0].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador unario - requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 2389 "parser.tab.c"
    break;

  case 141: /* expresion: '+' expresion  */
#line 787 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_INT && (yyvsp[0].tipo) != TYPE_FLOAT32 && (yyvsp[0].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador unario + requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 2401 "parser.tab.c"
    break;

  case 142: /* expresion: expresion INCREMENTO  */
#line 795 "parser.y"
    {
        if ((yyvsp[-1].tipo) != TYPE_INT && (yyvsp[-1].tipo) != TYPE_FLOAT32 && (yyvsp[-1].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "El operador ++ requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[-1].tipo);
    }
#line 2413 "parser.tab.c"
    break;

  case 143: /* expresion: expresion DECREMENTO  */
#line 803 "parser.y"
    {
        if ((yyvsp[-1].tipo) != TYPE_INT && (yyvsp[-1].tipo) != TYPE_FLOAT32 && (yyvsp[-1].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[0]).first_line, (yylsp[0]).first_column,
                "El operador -- requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[-1].tipo);
    }
#line 2425 "parser.tab.c"
    break;

  case 144: /* expresion: INCREMENTO expresion  */
#line 811 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_INT && (yyvsp[0].tipo) != TYPE_FLOAT32 && (yyvsp[0].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador ++ requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 2437 "parser.tab.c"
    break;

  case 145: /* expresion: DECREMENTO expresion  */
#line 819 "parser.y"
    {
        if ((yyvsp[0].tipo) != TYPE_INT && (yyvsp[0].tipo) != TYPE_FLOAT32 && (yyvsp[0].tipo) != TYPE_FLOAT64) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El operador -- requiere un operando numerico");
        }
        (yyval.tipo) = (yyvsp[0].tipo);
    }
#line 2449 "parser.tab.c"
    break;

  case 146: /* expresion: expresion '(' argumentos ')'  */
#line 827 "parser.y"
    {
        (yyval.tipo) = TYPE_UNKNOWN;
    }
#line 2457 "parser.tab.c"
    break;

  case 147: /* expresion: expresion '[' expresion ']'  */
#line 831 "parser.y"
    {
        if ((yyvsp[-1].tipo) != TYPE_INT) {
            semanticError((yylsp[-1]).first_line, (yylsp[-1]).first_column,
                "El indice del arreglo debe ser de tipo int");
        }
        (yyval.tipo) = (yyvsp[-3].tipo);
    }
#line 2469 "parser.tab.c"
    break;

  case 148: /* expresion: expresion '.' IDENTIFICADOR  */
#line 839 "parser.y"
    {
        (yyval.tipo) = TYPE_UNKNOWN;
        free((yyvsp[0].cadena));
    }
#line 2478 "parser.tab.c"
    break;

  case 149: /* expresion: TIPO_DATO '(' expresion ')'  */
#line 844 "parser.y"
    {
        (yyval.tipo) = stringToDataType((yyvsp[-3].cadena));
        free((yyvsp[-3].cadena));
    }
#line 2487 "parser.tab.c"
    break;

  case 150: /* expresion: IDENTIFICADOR '(' argumentos ')'  */
#line 849 "parser.y"
    {
        /* Accept zero or more arguments for function calls
           and treat result as unknown for now (could be refined
           using symbol table / signature checking). */
        Symbol *funcSym = lookupSymbol((yyvsp[-3].cadena));
        if (funcSym && funcSym->kind == SYM_FUNCTION) {
            (yyval.tipo) = funcSym->returnType;
        } else {
            (yyval.tipo) = TYPE_UNKNOWN;
        }
        free((yyvsp[-3].cadena));
    }
#line 2504 "parser.tab.c"
    break;


#line 2508 "parser.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 873 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error sintactico en linea %d, columna %d: %s\n", 
            yylloc.first_line, yylloc.first_column, s);
    errorCount++;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <archivo.go>\n", argv[0]);
        return 1;
    }

    extern FILE *yyin;
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    extern void iniciarUbicaciones();
    iniciarUbicaciones();

    yyparse();
    
    fclose(yyin);
    return (errorCount > 0 || semanticErrors > 0 || lexicalErrors > 0) ? 1 : 0;
}
