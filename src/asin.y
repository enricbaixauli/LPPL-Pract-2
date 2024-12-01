/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          jbenedi@dsic.upv.es>     V. 24  **/
/*****************************************************************************/
%{
#include <stdio.h>
#include "header.h"

int mainDeclarada = 0; // Variable global para controlar la declaración de main
%}

%token PARA_ PARC_ MAS_ MENOS_ POR_ DIV_ CTE_ 
%token ASIGSUMA_ ASIGRESTA_ ASIGPRODUCTO_ ASIGDIVISION_ LOGICOAND_ LOGICOOR_ IGUALDAD_ DISTINTO_ MAYORIGU_ MENORIGU_ INCREMENTO_ DECREMENTO_ ASIG_ OPRESTO_ MAYOR_ MENOR_ OPNEG_ IDENTIFICADOR_ ID_ TRUE_ FALSE_ BOOL_ RETURN_ READ_ PRINT_ IF_ FOR_ ACORCH_ CCORCH_ IBLOCK_ FBLOCK_ PCOMA_ COMA_ INT_ ELSE_

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
    : tipoSimp ID_ PCOMA_ {
        SIMB sim = obtTdS($2);
        if (sim.tipo != T_ERROR) {
            yyerror("Identificador repetido");
        } else {
            if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la tabla de símbolos");
            } else {
                dvar += TALLA_TIPO_SIMPLE; // Ajustar desplazamiento
            }
        }
    }
    | tipoSimp ID_ ASIG_ const PCOMA_ {
        SIMB sim = obtTdS($2);
        if (sim.tipo != T_ERROR) {
            yyerror("Identificador repetido");
        } else {
            if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la tabla de símbolos");
            } else {
                dvar += TALLA_TIPO_SIMPLE; // Ajustar desplazamiento
            }
        }
    }
    | tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_ {
        int numelem = $4;
        if (numelem <= 0) {
            yyerror("Talla inapropiada del array");
            numelem = 0;
        }

        SIMB sim = obtTdS($2);
        if (sim.tipo != T_ERROR) {
            yyerror("Identificador repetido");
        } else {
            int refe = insTdA($1, numelem);  // Insertar array en la TdA
            if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe)) {
                yyerror("Error al insertar el array en la tabla de símbolos");
            } else {
                dvar += numelem * TALLA_TIPO_SIMPLE; // Ajustar desplazamiento
            }
        }
    }
;


const 
    : CTE_ 
    | TRUE_ 
    | FALSE_
;

tipoSimp 
    : INT_ 
    | BOOL_
;

declaFunc 
    : tipoSimp ID_ PARA_ paramForm PARC_ bloque {
        if (strcmp($2, "main") == 0) {
            if (mainDeclarada) {
                yyerror("La función 'main' ya ha sido declarada");
            } else {
                mainDeclarada = 1; // Marca que la función main ha sido declarada
            }
        }
        if (!insTdS($2, FUNCION, $1, niv, dvar)) {
            yyerror("Función repetida");
        }
    }
;

paramForm 
    :  
    | listParamForm
;

listParamForm 
    : tipoSimp ID_ {
        insTdS($2, PARAMETRO, $1, niv, dvar);
    }
    | tipoSimp ID_ COMA_ listParamForm {
        insTdS($2, PARAMETRO, $1, niv, dvar);
    }
;

bloque 
    : IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_
;

declaVarLocal 
    :  
    | declaVarLocal declaVar
;

listInst 
    :  
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
        if (sim.tipo == T_ERROR) {
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
    : 
    | expre
;

expre
    : expreLogic
    | ID_ ASIG_ expre {
        SIMB sim = obtTdS($1);
        if (sim.tipo == T_ERROR) {
            yyerror("Variable no declarada");
        } else if (sim.tipo != $3.tipo) {
            yyerror("Error de tipos en la asignación");
        }
    }
    | ID_ ACORCH_ expre CCORCH_ ASIG_ expre {
        SIMB sim = obtTdS($1);
        if (sim.tipo == T_ERROR) {
            yyerror("Array no declarado");
        } else if (sim.tipo != T_ARRAY) {
            yyerror("Asignación inapropiada a un elemento que no es un array");
        } else if ($3.tipo != T_ENTERO) {
            yyerror("El índice del array debe ser de tipo entero");
        } else if ($6.tipo != T_ENTERO) {
            yyerror("El valor asignado al array debe ser de tipo entero");
        }
    }
;


expreLogic 
    : expreIgual 
    | expreLogic opLogic expreIgual
;

expreIgual 
    : expreRel 
    | expreIgual opIgual expreRel
;

expreRel 
    : expreAd 
    | expreRel opRel expreAd
;

expreAd 
    : expreMul 
    | expreAd opAd expreMul
;

expreMul 
    : expreUna 
    | expreMul opMul expreUna
;

expreUna 
    : expreSufi 
    | opUna expreUna
;

expreSufi
    : const
    | PARA_ expre PARC_
    | ID_ {
        SIMB sim = obtTdS($1);
        if (sim.tipo == T_ERROR) {
            yyerror("Variable no declarada");
        }
    }
    | ID_ ACORCH_ expre CCORCH_ {
        SIMB sim = obtTdS($1);
        if (sim.tipo == T_ERROR) {
            yyerror("Array no declarado");
        } else if (sim.tipo != T_ARRAY) {
            yyerror("Uso inapropiado de una variable no array como array");
        }
    }
    | ID_ PARA_ paramAct PARC_ {
        SIMB sim = obtTdS($1);
        if (sim.tipo == T_ERROR) {
            yyerror("Llamada a función no declarada");
        } else if (sim.tipo != FUNCION) {
            yyerror("El identificador no es una función");
        }
    }
;


paramAct 
    : 
    | listParamAct
;

listParamAct 
    : expre 
    | expre COMA_ listParamAct
;

opLogic 
    : LOGICOAND_  
    | LOGICOOR_
;

opIgual 
    : IGUALDAD_ 
    | DISTINTO_
;

opRel 
    : MAYOR_ 
    | MENOR_ 
    | MAYORIGU_ 
    | MENORIGU_
;

opAd 
    : MAS_ 
    | MENOS_
;

opMul 
    : POR_ 
    | DIV_
;

opUna 
    : MAS_ 
    | MENOS_ 
    | OPNEG_
;

%%