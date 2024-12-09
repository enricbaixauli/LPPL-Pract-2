/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          jbenedi@dsic.upv.es>     V. 24  **/
/*****************************************************************************/
%{
#include <stdio.h>
#include "header.h"

int mainDeclarada = 0; // Variable global para controlar la declaración de main
int TALLA_TIPO_SIMPLE = 1;
%}

%union{
	int cent;
	char *ident;
}

%token PARA_ PARC_ MAS_ MENOS_ POR_ DIV_ CTE_ 
%token ASIGSUMA_ ASIGRESTA_ ASIGPRODUCTO_ ASIGDIVISION_ LOGICOAND_ LOGICOOR_ IGUALDAD_ DISTINTO_ MAYORIGU_ MENORIGU_ INCREMENTO_ DECREMENTO_ ASIG_ OPRESTO_ MAYOR_ MENOR_ OPNEG_ IDENTIFICADOR_ ID_ TRUE_ FALSE_ BOOL_ RETURN_ READ_ PRINT_ IF_ FOR_ ACORCH_ CCORCH_ IBLOCK_ FBLOCK_ PCOMA_ COMA_ INT_ ELSE_

%token <cent>  CTE_
%token <ident> ID_

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
        int talla = $1.t;
        if ($1.t == INT_) {
            talla = TALLA_TIPO_SIMPLE;  // La talla de los enteros es 1 = TALLA_TIPO_SIMPLE
        } else if ($1.t == BOOL_) {
            talla = TALLA_TIPO_SIMPLE;  // La talla de los lógicos también es 1 = TALLA_TIPO_SIMPLE
        }
        
        SIMB sim = obtTdS($2);
        if (sim.t != T_ERROR) {
            yyerror("Identificador repetido");
        } else {
            if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la tabla de símbolos");
            } else {
                dvar += talla;  // Ajustar desplazamiento con la talla correcta
            }
        }
    }
    | tipoSimp ID_ ASIG_ const PCOMA_ {
        int talla = $1.t;
        if ($1.t == INT_) {
            talla = 1;
        } else if ($1.t == BOOL_) {
            talla = 1;
        }

        SIMB sim = obtTdS($2);
        if (sim.t != T_ERROR) {
            yyerror("Identificador repetido");
        } else {
            if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la tabla de símbolos");
            } else {
                dvar += talla;
            }
        }
    }
;



const 
    : CTE_ {$$.t = T_ENTERO;}
    | TRUE_ {$$.t = T_LOGICO;}
    | FALSE_ {$$.t = T_LOGICO;}
;

tipoSimp 
    : INT_ {$$.t = T_ENTERO;}
    | BOOL_ {$$.t = T_LOGICO;}
;

declaFunc 
    : tipoSimp ID_ PARA_ paramForm PARC_ bloque
    {
        // Comprobar si la función es 'main'
        if (strcmp($2, "main") == 0) {
            if (mainDeclarada) {
                yyerror("La función 'main' ya ha sido declarada");
            } else {
                mainDeclarada = 1;  // Marcar que la función 'main' ha sido declarada
            }
        }

        // Comprobamos si la función ya está declarada en la TdS
        SIMB sim = obtTdS($2);
        if (sim.tipo != T_ERROR) {
            yyerror("La función ya está declarada");
        } else {
            // Insertamos la función en la TdS antes de procesar su cuerpo
            int refDom = insTdD(-1, $1);  // Crear un dominio vacío para los parámetros
            if (!insTdS($2, FUNCION, $1, niv, dvar, refDom)) {
                yyerror("Función repetida");
            } else {
                // Insertamos los parámetros en la TdS (si los hay)
                int refParam = refDom;
                for (int i = 0; i < numParams; i++) {
                    refParam = insTdS(paramList[i], VARIABLE, tipoParam[i], niv + 1, dvar, refParam);
                }
            }
        }

        // Procesar el cuerpo de la función ahora que ya está en la TdS
        cargaContexto(niv);  // Cargar el contexto local para el bloque de la función
        $$ = $6;  // Procesar el bloque de la función
        descargaContexto(niv);  // Descargar el contexto local
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
    : 
    | expre
;

expre
    : expreLogic
    | ID_ ASIG_ expre {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Variable no declarada");
	} else if ((sim.t == T_ENTERO && $3.t == T_LOGICO) || 
                   (sim.t == T_LOGICO && $3.t == T_ENTERO)) {
            yyerror("Error: No se permite la conversión entre 'int' i 'bool'");
        } else if (sim.t != $3.t) {
            yyerror("Error de tipos en la asignación");
        }
    }
    | ID_ ACORCH_ expre CCORCH_ ASIG_ expre {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Array no declarado");
        } else if (sim.t != T_ARRAY) {
            yyerror("Asignación inapropiada a un elemento que no es un array");
        } else if ($3.t != T_ENTERO) {
            yyerror("El índice del array debe ser de tipo entero");
        } else if ($6.t != T_ENTERO) {
            yyerror("El valor asignado al array debe ser de tipo entero");
        }
    }
;



expreLogic 
    : expreIgual 
    | expreLogic opLogic expreIgual {
        if ($1.t != T_LOGICO || $3.t != T_LOGICO) {
            yyerror("Error: operación lógica entre tipos no booleanos");
        }
        $$.t = T_LOGICO;  
    }
;

expreIgual 
    : expreRel 
    | expreIgual opIgual expreRel{
        if (!($1.t == T_ERROR || $3.t == T_ERROR)){
            if ($1.t!=$3.t){yyerror("Error: No son del mismo tipo");}
            else if ($3.t != T_ENTERO || $3.t != T_LOGICO) {
            yyerror("Error: operación de igualdad entre tipos no enteros ni lógicos");
            }
        $$.t = T_LOGICO;
        } 
    }
;

expreRel 
    : expreAd 
    | expreRel opRel expreAd{
        if (!($1.t == T_ERROR || $3.t == T_ERROR)){
            if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error: operación de relación entre tipos no enteros");
            }
        $$.t = T_LOGICO;
        } 
    }
;

expreAd 
    : expreMul 
    | expreAd opAd expreMul{
        if (!($1.t = T_ERROR || $3.t = T_ERROR)){
            if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error: operación aritmética entre tipos no enteros");
        }
        $$.t = T_ENTERO;
        } 
    }
;

expreMul 
    : expreUna 
    | expreMul opMul expreUna{
        if (!($1.t == T_ERROR || $3.t == T_ERROR)){
            if ($1.t != T_ENTERO || $3.t != T_ENTERO) {
            yyerror("Error: operación aritmética entre tipos no enteros");
        }
        $$.t = T_ENTERO;
        } 
    }
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
        if (sim.t == T_ERROR) {
            yyerror("Variable no declarada");
        }
    }
    | ID_ ACORCH_ expre CCORCH_ {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Array no declarado");
        } else if (sim.t != T_ARRAY) {
            yyerror("Uso inapropiado de una variable no array como array");
        }else if ($3.t != T_ENTERO) {
            yyerror("Error: El índice del vector ha de ser de tipo entero");
        } else {
            DIM infoArray = obtTdA(sim.ref);  
            $$.t = infoArray.telem;  
        }
    }
    | ID_ PARA_ paramAct PARC_ {
        SIMB sim = obtTdS($1);
        if (sim.t == T_ERROR) {
            yyerror("Llamada a función no declarada");
        } else if (sim.t != FUNCION) {
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
    : LOGICOAND_  {$$ = OP_AND;}
    | LOGICOOR_   {$$ = OP_OR;}
;

opIgual 
    : IGUALDAD_  {$$ = OP_IGUAL;}
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
