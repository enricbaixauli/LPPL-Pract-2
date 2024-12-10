%{

#include <stdio.h>

#include "header.h"



int mainDeclarada = 0;

int TALLA_TIPO_SIMPLE = 1;

%}



%union {

  int cent;

  char *ident;

}



%token PARA_ PARC_ MAS_ MENOS_ POR_ DIV_ 

%token ASIGSUMA_ ASIGRESTA_ ASIGPRODUCTO_ ASIGDIVISION_ LOGICOAND_ LOGICOOR_

%token IGUALDAD_ DISTINTO_ MAYORIGU_ MENORIGU_ INCREMENTO_ DECREMENTO_ ASIG_

%token OPRESTO_ MAYOR_ MENOR_ OPNEG_ IDENTIFICADOR_ TRUE_ FALSE_ BOOL_ RETURN_

%token READ_ PRINT_ IF_ FOR_ ACORCH_ CCORCH_ IBLOCK_ FBLOCK_ PCOMA_ COMA_ INT_

%token ELSE_



%token <cent> CTE_

%token <ident> ID_



%type <cent> tipoSimp const

%type <cent> expre expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi expreOP

%type <cent> opLogic opIgual opRel opAd opMul opUna



%%



programa

  : listDecla

  ;



listDecla

  : decla

  | listDecla decla

  ;



decla

  : declaVar

  | declaFunc

  ;



declaVar

  : tipoSimp ID_ PCOMA_

    {

      int talla = ($1 == T_ENTERO || $1 == T_LOGICO) ? TALLA_TIPO_SIMPLE : 1;

      SIMB sim = obtTdS($2);

      if (sim.t != T_ERROR) {

        yyerror("Identificador repetido");

      } else {

        if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {

          yyerror("Error al insertar la variable");

        } else {

          dvar += talla;

        }

      }

    }

  | tipoSimp ID_ ASIG_ const PCOMA_

    {

      int talla = ($1 == T_ENTERO || $1 == T_LOGICO) ? 1 : 1;

      SIMB sim = obtTdS($2);

      if (sim.t != T_ERROR) {

        yyerror("Identificador repetido");

      } else {

        if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {

          yyerror("Error al insertar la variable");

        } else {

          dvar += talla;

        }

      }

    }

  ;



const

  : CTE_   { $$ = T_ENTERO; }

  | TRUE_  { $$ = T_LOGICO; }

  | FALSE_ { $$ = T_LOGICO; }

  ;



tipoSimp

  : INT_  { $$ = T_ENTERO; }

  | BOOL_ { $$ = T_LOGICO; }

  ;



declaFunc

  : tipoSimp ID_ PARA_ paramForm PARC_ bloque

    {

      if (strcmp($2, "main") == 0) {

        if (mainDeclarada) {

          yyerror("La función 'main' ya ha sido declarada");

        } else {

          mainDeclarada = 1;

        }

      }



      SIMB sim = obtTdS($2);

      if (sim.t != T_ERROR) {

        yyerror("La función ya está declarada");

      } else {

        int refDom = insTdD(-1, $1);

        if (!insTdS($2, FUNCION, $1, niv, dvar, refDom)) {

          yyerror("Función repetida");

        } else {

          // Insertar parámetros si necesario

        }

      }



      cargaContexto(niv);

      // $$ = $6;  <-- Remove this line if we don't need a return value

      descargaContexto(niv);

    }

  ;



paramForm

  : /*empty*/

  | listParamForm

  ;



listParamForm

  : tipoSimp ID_ { insTdS($2, PARAMETRO, $1, niv, dvar); }

  | tipoSimp ID_ COMA_ listParamForm { insTdS($2, PARAMETRO, $1, niv, dvar); }

  ;



bloque

  : IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_

  ;



declaVarLocal

  : /*empty*/

  | declaVarLocal declaVar

  ;



listInst

  : /*empty*/

  | listInst inst

  ;



inst

  : IBLOCK_ listInst FBLOCK_

  | instExpre

  | instEntSal

  | instSelec

  | instIter

  ;



instExpre

  : expre PCOMA_

  | PCOMA_

  ;



instEntSal

  : READ_ PARA_ ID_ PARC_ PCOMA_

    {

      SIMB sim = obtTdS($3);

      if (sim.t == T_ERROR) {

        yyerror("Variable no declarada");

      }

    }

  | PRINT_ PARA_ expre PARC_ PCOMA_

  ;



instSelec

  : IF_ PARA_ expre PARC_ inst ELSE_ inst

  ;



instIter

  : FOR_ PARA_ expreOP PCOMA_ expre PCOMA_ expreOP PARC_ inst

  ;



expreOP

  : /*empty*/ { $$ = T_ERROR; }

  | expre     { $$ = $1; }

  ;



expre

  : expreLogic { $$ = $1; }

  | ID_ ASIG_ expre

    {

      SIMB sim = obtTdS($1);

      if (sim.t == T_ERROR) {

        yyerror("Variable no declarada");

      } else if (sim.t != $3) {

        yyerror("Error de tipos en la asignación");

      }

      $$ = sim.t; 

    }

  | ID_ ACORCH_ expre CCORCH_ ASIG_ expre

    {

      SIMB sim = obtTdS($1);

      if (sim.t == T_ERROR) {

        yyerror("Array no declarado");

      } else if (sim.t != T_ARRAY) {

        yyerror("Asignación a un elemento que no es un array");

      } else if ($3 != T_ENTERO) {

        yyerror("El índice debe ser entero");

      } else if ($6 != T_ENTERO) {

        yyerror("El valor asignado debe ser entero");

      }

      $$ = T_ENTERO;

    }

  ;



expreLogic

  : expreIgual       { $$ = $1; }

  | expreLogic opLogic expreIgual

    {

      if ($1 != T_LOGICO || $3 != T_LOGICO) {

        yyerror("Operación lógica con tipos no booleanos");

      }

      $$ = T_LOGICO;  

    }

  ;



expreIgual

  : expreRel         { $$ = $1; }

  | expreIgual opIgual expreRel

    {

      if ($1 != T_ERROR && $3 != T_ERROR) {

        if ($1 != $3) {

          yyerror("No son del mismo tipo");

        } else if ($3 != T_ENTERO && $3 != T_LOGICO) {

          yyerror("Operación de igualdad no entre enteros o lógicos");

        }

      }

      $$ = T_LOGICO;

    }

  ;



expreRel

  : expreAd          { $$ = $1; }

  | expreRel opRel expreAd

    {

      if ($1 != T_ERROR && $3 != T_ERROR) {

        if ($1 != T_ENTERO || $3 != T_ENTERO) {

          yyerror("Operación relacional no entre enteros");

        }

      }

      $$ = T_LOGICO;

    }

  ;



expreAd

  : expreMul         { $$ = $1; }

  | expreAd opAd expreMul

    {

      if ($1 != T_ERROR && $3 != T_ERROR) {

        if ($1 != T_ENTERO || $3 != T_ENTERO) {

          yyerror("Operación aritmética no entre enteros");

        }

      }

      $$ = T_ENTERO;

    }

  ;



expreMul

  : expreUna         { $$ = $1; }

  | expreMul opMul expreUna

    {

      if ($1 != T_ERROR && $3 != T_ERROR) {

        if ($1 != T_ENTERO || $3 != T_ENTERO) {

          yyerror("Operación aritmética no entre enteros");

        }

      }

      $$ = T_ENTERO;

    }

  ;



expreUna

  : expreSufi        { $$ = $1; }

  | opUna expreUna

    {

      // Suponiendo opUna aplicable sobre enteros/lógicos

      // Ajustar según la operación unaria.

      $$ = $2; 

    }

  ;



expreSufi

  : const            { $$ = $1; }

  | PARA_ expre PARC_ { $$ = $2; }

  | ID_

    {

      SIMB sim = obtTdS($1);

      if (sim.t == T_ERROR) {

        yyerror("Variable no declarada");

      }

      $$ = sim.t;

    }

  | ID_ ACORCH_ expre CCORCH_

    {

      SIMB sim = obtTdS($1);

      if (sim.t == T_ERROR) {

        yyerror("Array no declarado");

      } else if (sim.t != T_ARRAY) {

        yyerror("Uso inapropiado de una variable no array");

      }

      $$ = T_ENTERO; // asumiendo arrays de enteros

    }

  | ID_ PARA_ paramAct PARC_

    {

      SIMB sim = obtTdS($1);

      if (sim.t == T_ERROR) {

        yyerror("Función no declarada");

      } else if (sim.t != FUNCION) {

        yyerror("No es una función");

      }

      // Asumimos retorno entero:

      $$ = T_ENTERO;

    }

  ;



paramAct

  : /*empty*/ { $$ = T_ERROR; }

  | listParamAct

  ;



listParamAct

  : expre        { $$ = $1; }

  | expre COMA_ listParamAct { $$ = $1; }

  ;



opLogic

  : LOGICOAND_ { $$ = OP_AND; }

  | LOGICOOR_  { $$ = OP_OR; }

  ;



opIgual

  : IGUALDAD_ { $$ = OP_IGUAL; }

  | DISTINTO_ { $$ = OP_DIST; }

  ;



opRel

  : MAYOR_   { $$ = OP_MAYOR; }

  | MENOR_   { $$ = OP_MENOR; }

  | MAYORIGU_{ $$ = OP_MAYORIG; }

  | MENORIGU_{ $$ = OP_MENORIG; }

  ;



opAd

  : MAS_   { $$ = OP_SUMA; }

  | MENOS_ { $$ = OP_RESTA; }

  ;



opMul

  : POR_ { $$ = OP_MUL; }

  | DIV_ { $$ = OP_DIV; }

  ;



opUna

  : MAS_   { $$ = OP_UPLUS; }

  | MENOS_ { $$ = OP_UMENOS; }

  | OPNEG_ { $$ = OP_NEG; }

  ;



%%

