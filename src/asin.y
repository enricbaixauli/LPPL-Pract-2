%{
#include <stdio.h>
#include <string.h>
#include "header.h"
#include "asin.h"
#include "libtds.h"

int mainDeclarada = 0;
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
%type <cent> paramAct listParamAct

%%

programa
  : { dvar=0; niv=0; cargaContexto(niv); }
    listDecla
    { if(verTdS) mostrarTdS(); }
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
  : tipoSimp ID_ PCOMA_ {
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) yyerror("Identificador repetido");
      else {
        if (!insTdS($2, VARIABLE, $1, niv, dvar, -1))
          yyerror("Error al insertar la variable en la tabla de símbolos");
        else dvar += TALLA_TIPO_SIMPLE;
      }
    }
  | tipoSimp ID_ ASIG_ const PCOMA_ {
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) yyerror("Identificador repetido");
      else {
         if ($1 != $4) {  
            yyerror("Error: Tipo incompatible entre la variable y la constante asignada");
        } else {
            if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la Tabla de Símbolos");
            } else {
                dvar += TALLA_TIPO_SIMPLE;  
            }
    }
  | tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_ {
      int numelem = $4;
      if (numelem <= 0) {
        yyerror("Talla inapropiada del array");
        numelem = 0;
      }
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) yyerror("Identificador repetido");
      else {
        int refe = insTdA($1, numelem);
        if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe))
          yyerror("Error al insertar el array en la tabla de símbolos");
        else dvar += numelem * TALLA_TIPO_SIMPLE;
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
  : tipoSimp ID_ PARA_ paramForm PARC_ bloque {
      niv++;
      cargaContexto(niv);
      if (strcmp($2, "main") == 0) {
        if (mainDeclarada) yyerror("La función 'main' ya ha sido declarada");
        else mainDeclarada = 1;
      }
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) yyerror("La función ya está declarada");
      else {
        int refDom = insTdD(-1, $1);
        if (!insTdS($2, FUNCION, $1, niv, dvar, refDom))
          yyerror("Función repetida");
      }
      
      descargaContexto(niv);
      niv--;
    }
;

paramForm
  : /*empty*/
  | listParamForm
;

listParamForm
  : tipoSimp ID_ { insTdS($2, PARAMETRO, $1, niv, dvar, -1); }
  | tipoSimp ID_ COMA_ listParamForm { insTdS($2, PARAMETRO, $1, niv, dvar, -1); }
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
  : READ_ PARA_ ID_ PARC_ PCOMA_ {
      SIMB sim = obtTdS($3);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != T_ENTERO) yyerror("Error: La variable a 'read' tiene que ser de tipo entero");
    }
  | PRINT_ PARA_ expre PARC_ PCOMA_ {
      if ($3 != T_ENTERO) yyerror("Error: La expresión a 'write' tiene que ser de tipo entero");
    }
;

instSelec
  : IF_ PARA_ expre PARC_ inst ELSE_ inst {
      if ($3 != T_LOGICO) yyerror("Error: La condición a 'if-else' tiene que ser de tipo lógico");
    }
;

instIter
  : FOR_ PARA_ expreOP PCOMA_ expre PCOMA_ expreOP PARC_ inst {
      if ($5 != T_LOGICO) yyerror("Error: La condición del 'for' tiene que ser de tipo lógico");
    }
;

expreOP
  : /*empty*/ { $$ = T_ERROR; }
  | expre     { $$ = $1; }
;

expre
  : expreLogic { $$ = $1; }
  | ID_ ASIG_ expre {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != $3) yyerror("Error de tipos en la asignación");
      $$ = sim.t;
    }
  | ID_ ACORCH_ expre CCORCH_ ASIG_ expre {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("Asignación a un elemento que no es un array");
      else if ($3 != T_ENTERO) yyerror("El índice debe ser entero");
      else if ($6 != T_ENTERO) yyerror("El valor asignado debe ser entero");
      $$ = T_ENTERO;
    }
;

expreLogic
  : expreIgual { $$ = $1; }
  | expreLogic opLogic expreIgual {
      if ($1 != T_LOGICO || $3 != T_LOGICO) yyerror("Operación lógica con tipos no booleanos");
      $$ = T_LOGICO;
    }
;

expreIgual
  : expreRel { $$ = $1; }
  | expreIgual opIgual expreRel {
      if ($1 != T_ERROR && $3 != T_ERROR) {
        if ($1 != $3) yyerror("No son del mismo tipo");
        else if ($3 != T_ENTERO && $3 != T_LOGICO) yyerror("Operación de igualdad no entre enteros o lógicos");
      }
      $$ = T_LOGICO;
    }
;

expreRel
  : expreAd { $$ = $1; }
  | expreRel opRel expreAd {
      if ($1 != T_ERROR && $3 != T_ERROR) {
        if ($1 != T_ENTERO || $3 != T_ENTERO) yyerror("Operación relacional no entre enteros");
      }
      $$ = T_LOGICO;
    }
;

expreAd
  : expreMul { $$ = $1; }
  | expreAd opAd expreMul {
      if ($1 != T_ERROR && $3 != T_ERROR) {
        if ($1 != T_ENTERO || $3 != T_ENTERO) yyerror("Operación aritmética no entre enteros");
      }
      $$ = T_ENTERO;
    }
;

expreMul
  : expreUna { $$ = $1; }
  | expreMul opMul expreUna {
      if ($1 != T_ERROR && $3 != T_ERROR) {
        if ($1 != T_ENTERO || $3 != T_ENTERO) yyerror("Operación aritmética no entre enteros");
      }
      $$ = T_ENTERO;
    }
;

expreUna
  : expreSufi { $$ = $1; }
  | opUna expreUna {
      $$ = $2;
    }
;

expreSufi
  : const { $$ = $1; }
  | PARA_ expre PARC_ { $$ = $2; }
  | ID_ {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      $$ = sim.t;
    }
  | ID_ ACORCH_ expre CCORCH_ {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("Uso inapropiado de una variable no array");
      $$ = T_ENTERO;
    }
  | ID_ PARA_ paramAct PARC_ {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Función no declarada");
      else if (sim.t != FUNCION) yyerror("No es una función");
      $$ = T_ENTERO;
    }
;

paramAct
  : /*empty*/ { $$ = T_ERROR; }
  | listParamAct
;

listParamAct
  : expre { $$ = $1; }
  | expre COMA_ listParamAct { $$ = $1; }
;

opLogic
  : LOGICOAND_ { $$ = OP_AND; }
  | LOGICOOR_  { $$ = OP_OR; }
;

opIgual
  : IGUALDAD_ { $$ = OP_IGUAL; }
  | DISTINTO_ { $$ = DISTINTO_; }
;

opRel
  : MAYOR_    { $$ = OP_MAYOR; }
  | MENOR_    { $$ = OP_MENOR; }
  | MAYORIGU_ { $$ = OP_MAYORIG; }
  | MENORIGU_ { $$ = OP_MENORIG; }
;

opAd
  : MAS_   { $$ = OP_SUMA; }
  | MENOS_ { $$ = OP_RESTA; }
;

opMul
  : POR_ { $$ = POR_; }
  | DIV_ { $$ = OP_DIV; }
;

opUna
  : MAS_   { $$ = MAS_; }
  | MENOS_ { $$ = MENOS_; }
  | OPNEG_ { $$ = OPNEG_; }
;

%%
