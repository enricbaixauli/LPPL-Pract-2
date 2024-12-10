/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          <jbenedi@dsic.upv.es>   V.24    **/
/*****************************************************************************/
%{
#include <stdio.h>
#include <string.h>
#include "asin.h"
#include "header.h"

#define  retornar(x) {if (verbosidad) ECHO ; return (x) ; }
%}
/*----------------------------------------------------------------------
  Dado que las funciones "input()" y "unput(c)" son costosas y no las
  utilizaremos, evitaremos que se generen automaticamente sus rutinas
  correspondientes desactivandolas mediante las siguientes opciones:
----------------------------------------------------------------------*/
%option noinput
%option nounput
/*----------------------------------------------------------------------
  Para mantener el numero de linea actual en la variable global yylineno
----------------------------------------------------------------------*/
%option yylineno

delimitador     [ \t\n]+
digito          [0-9]
entero          {digito}+
real            ({digito}+"."{digito}*|"."{digito}+)
letra           [a-zA-Z]
letra_minuscula [a-z]
letra_mayuscula [A-Z]
identificador      {letra}({letra}|{digito}|"_")*


%%
{delimitador}   { if (verbosidad) ECHO ;}
"//".*          { if (verbosidad) ECHO; }
"true" { retornar(TRUE_); }
"false" { retornar(FALSE_); }
"int" { retornar(INT_); }
"bool" { retornar(BOOL_); }
"return" { retornar(RETURN_); }
"read" { retornar(READ_); } 
"print" { retornar(PRINT_); }
"if" { retornar(IF_); }
"else" { retornar(ELSE_); }
"for" { retornar(FOR_); }
"+="        {retornar(ASIGSUMA_);}
"-="        {retornar(ASIGRESTA_);}
"*="        {retornar(ASIGPRODUCTO_);}
"/="        {retornar(ASIGDIVISION_);}
"&&"        {retornar(LOGICOAND_);}
"||"        {retornar(LOGICOOR_);}
"=="        {retornar(IGUALDAD_);}
"!="        {retornar(DISTINTO_);}
">="        {retornar(MAYORIGU_);}
"<="        {retornar(MENORIGU_);}
"++"        {retornar(INCREMENTO_);}
"--"        {retornar(DECREMENTO_);}
"="                 {retornar(ASIG_);}
"%"                 {retornar(OPRESTO_);}
">"                  {retornar(MAYOR_);}
"<"                 {retornar(MENOR_);}
"!"                 {retornar(OPNEG_);}
"+"             { retornar (MAS_) ;}
"-"             { retornar (MENOS_) ; }
"*"             { retornar (POR_) ; }
"/"             { retornar (DIV_) ; }
"["                 {retornar(ACORCH_);}
"]"                 {retornar(CCORCH_);}
"("                 {retornar(PARA_);}
")"                 {retornar(PARC_);}
"{"                 {retornar(IBLOCK_);}
"}"                 {retornar(FBLOCK_);}
";"                 {retornar(PCOMA_);}
","                 {retornar(COMA_);}
{real}              { 
                      double real = atof(yytext); 
                      int entero = (int) real;     
                      yylval.cent = entero;       
                      retornar (CTE_); 
                    }
{entero}            { 
                      yylval.cent = atoi(yytext);
                      retornar (CTE_);
                    }

{identificador}     {
                      yylval.ident = strdup(yytext);
                      retornar(ID_);
                    }
.				{ yyerror("Caracter desconocido") ;}
%%
