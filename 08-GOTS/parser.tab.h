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
/* "%code requires" blocks.  */
#line 16 "parser.y"

    #include "tabla_simbolos.h"

#line 53 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFICADOR = 258,           /* IDENTIFICADOR  */
    TIPO_DATO = 259,               /* TIPO_DATO  */
    CADENA = 260,                  /* CADENA  */
    ENTERO = 261,                  /* ENTERO  */
    TRUE = 262,                    /* TRUE  */
    FALSE = 263,                   /* FALSE  */
    REAL = 264,                    /* REAL  */
    CARACTER = 265,                /* CARACTER  */
    PACKAGE = 266,                 /* PACKAGE  */
    IMPORT = 267,                  /* IMPORT  */
    FUNC = 268,                    /* FUNC  */
    VAR = 269,                     /* VAR  */
    CONST = 270,                   /* CONST  */
    TYPE = 271,                    /* TYPE  */
    STRUCT = 272,                  /* STRUCT  */
    IF = 273,                      /* IF  */
    ELSE = 274,                    /* ELSE  */
    FOR = 275,                     /* FOR  */
    SWITCH = 276,                  /* SWITCH  */
    CASE = 277,                    /* CASE  */
    DEFAULT = 278,                 /* DEFAULT  */
    RETURN = 279,                  /* RETURN  */
    BREAK = 280,                   /* BREAK  */
    CONTINUE = 281,                /* CONTINUE  */
    DECLARACION_CORTA = 282,       /* DECLARACION_CORTA  */
    INCREMENTO = 283,              /* INCREMENTO  */
    DECREMENTO = 284,              /* DECREMENTO  */
    MAS_IGUAL = 285,               /* MAS_IGUAL  */
    MENOS_IGUAL = 286,             /* MENOS_IGUAL  */
    POR_IGUAL = 287,               /* POR_IGUAL  */
    DIV_IGUAL = 288,               /* DIV_IGUAL  */
    MOD_IGUAL = 289,               /* MOD_IGUAL  */
    IGUALDAD = 290,                /* IGUALDAD  */
    DIFERENTE = 291,               /* DIFERENTE  */
    MENOR_IGUAL = 292,             /* MENOR_IGUAL  */
    MAYOR_IGUAL = 293,             /* MAYOR_IGUAL  */
    AND = 294,                     /* AND  */
    OR = 295,                      /* OR  */
    UNARIO = 296                   /* UNARIO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "parser.y"

    int ival;
    double dval;
    char cval;
    char *cadena;
    DataType tipo;
    Symbol *simbolo;

#line 120 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
