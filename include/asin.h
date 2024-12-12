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

#ifndef YY_YY_ASIN_H_INCLUDED
# define YY_YY_ASIN_H_INCLUDED
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
    PARA_ = 258,                   /* PARA_  */
    PARC_ = 259,                   /* PARC_  */
    MAS_ = 260,                    /* MAS_  */
    MENOS_ = 261,                  /* MENOS_  */
    POR_ = 262,                    /* POR_  */
    DIV_ = 263,                    /* DIV_  */
    ASIGSUMA_ = 264,               /* ASIGSUMA_  */
    ASIGRESTA_ = 265,              /* ASIGRESTA_  */
    ASIGPRODUCTO_ = 266,           /* ASIGPRODUCTO_  */
    ASIGDIVISION_ = 267,           /* ASIGDIVISION_  */
    LOGICOAND_ = 268,              /* LOGICOAND_  */
    LOGICOOR_ = 269,               /* LOGICOOR_  */
    IGUALDAD_ = 270,               /* IGUALDAD_  */
    DISTINTO_ = 271,               /* DISTINTO_  */
    MAYORIGU_ = 272,               /* MAYORIGU_  */
    MENORIGU_ = 273,               /* MENORIGU_  */
    INCREMENTO_ = 274,             /* INCREMENTO_  */
    DECREMENTO_ = 275,             /* DECREMENTO_  */
    ASIG_ = 276,                   /* ASIG_  */
    OPRESTO_ = 277,                /* OPRESTO_  */
    MAYOR_ = 278,                  /* MAYOR_  */
    MENOR_ = 279,                  /* MENOR_  */
    OPNEG_ = 280,                  /* OPNEG_  */
    IDENTIFICADOR_ = 281,          /* IDENTIFICADOR_  */
    TRUE_ = 282,                   /* TRUE_  */
    FALSE_ = 283,                  /* FALSE_  */
    BOOL_ = 284,                   /* BOOL_  */
    RETURN_ = 285,                 /* RETURN_  */
    READ_ = 286,                   /* READ_  */
    PRINT_ = 287,                  /* PRINT_  */
    IF_ = 288,                     /* IF_  */
    FOR_ = 289,                    /* FOR_  */
    ACORCH_ = 290,                 /* ACORCH_  */
    CCORCH_ = 291,                 /* CCORCH_  */
    IBLOCK_ = 292,                 /* IBLOCK_  */
    FBLOCK_ = 293,                 /* FBLOCK_  */
    PCOMA_ = 294,                  /* PCOMA_  */
    COMA_ = 295,                   /* COMA_  */
    INT_ = 296,                    /* INT_  */
    ELSE_ = 297,                   /* ELSE_  */
    CTE_ = 298,                    /* CTE_  */
    ID_ = 299                      /* ID_  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "src/asin.y"

  int cent;
  char *ident;

#line 113 "asin.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ASIN_H_INCLUDED  */
