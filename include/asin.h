/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PARA_ = 258,
     PARC_ = 259,
     MAS_ = 260,
     MENOS_ = 261,
     POR_ = 262,
     DIV_ = 263,
     ASIGSUMA_ = 264,
     ASIGRESTA_ = 265,
     ASIGPRODUCTO_ = 266,
     ASIGDIVISION_ = 267,
     LOGICOAND_ = 268,
     LOGICOOR_ = 269,
     IGUALDAD_ = 270,
     DISTINTO_ = 271,
     MAYORIGU_ = 272,
     MENORIGU_ = 273,
     INCREMENTO_ = 274,
     DECREMENTO_ = 275,
     ASIG_ = 276,
     OPRESTO_ = 277,
     MAYOR_ = 278,
     MENOR_ = 279,
     OPNEG_ = 280,
     IDENTIFICADOR_ = 281,
     TRUE_ = 282,
     FALSE_ = 283,
     BOOL_ = 284,
     RETURN_ = 285,
     READ_ = 286,
     PRINT_ = 287,
     IF_ = 288,
     FOR_ = 289,
     ACORCH_ = 290,
     CCORCH_ = 291,
     IBLOCK_ = 292,
     FBLOCK_ = 293,
     PCOMA_ = 294,
     COMA_ = 295,
     INT_ = 296,
     ELSE_ = 297,
     CTE_ = 298,
     ID_ = 299
   };
#endif
/* Tokens.  */
#define PARA_ 258
#define PARC_ 259
#define MAS_ 260
#define MENOS_ 261
#define POR_ 262
#define DIV_ 263
#define ASIGSUMA_ 264
#define ASIGRESTA_ 265
#define ASIGPRODUCTO_ 266
#define ASIGDIVISION_ 267
#define LOGICOAND_ 268
#define LOGICOOR_ 269
#define IGUALDAD_ 270
#define DISTINTO_ 271
#define MAYORIGU_ 272
#define MENORIGU_ 273
#define INCREMENTO_ 274
#define DECREMENTO_ 275
#define ASIG_ 276
#define OPRESTO_ 277
#define MAYOR_ 278
#define MENOR_ 279
#define OPNEG_ 280
#define IDENTIFICADOR_ 281
#define TRUE_ 282
#define FALSE_ 283
#define BOOL_ 284
#define RETURN_ 285
#define READ_ 286
#define PRINT_ 287
#define IF_ 288
#define FOR_ 289
#define ACORCH_ 290
#define CCORCH_ 291
#define IBLOCK_ 292
#define FBLOCK_ 293
#define PCOMA_ 294
#define COMA_ 295
#define INT_ 296
#define ELSE_ 297
#define CTE_ 298
#define ID_ 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "src/asin.y"
{

  int cent;

  char *ident;

}
/* Line 1529 of yacc.c.  */
#line 145 "asin.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

