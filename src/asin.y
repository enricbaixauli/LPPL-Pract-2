/*****************************************************************************/
/**  Ejemplo de BISON-I: S E M - 2          jbenedi@dsic.upv.es>     V. 24  **/
/*****************************************************************************/
%{
#include <stdio.h>
#include "header.h"
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
: tipoSimp ID_ PCOMA_ 
| tipoSimp ID_ ASIG_ const PCOMA_ 
| tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_
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
: tipoSimp ID_ PARA_ paramForm PARC_ bloque
;

paramForm 
:  
| listParamForm
;

listParamForm 
: tipoSimp ID_ 
| tipoSimp ID_ COMA_ listParamForm
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
: READ_ PARA_ ID_ PARC_ PCOMA_ 
| PRINT_ PARA_ expre PARC_ PCOMA_
;

instSelec 
: IF_ PARA_ expre PARC_ inst ELSE_ inst
;

instIter : FOR_ PARA_ expreOP PCOMA_ expre PCOMA_ expreOP PARC_ inst
;

expreOP 
: 
| expre
;

expre 
: expreLogic 
| ID_ ASIG_ expre 
| ID_ ACORCH_ expre CCORCH_ ASIG_ expre
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
| ID_ 
| ID_ ACORCH_ expre CCORCH_ 
| ID_ PARA_ paramAct PARC_
;

paramAct 
: 
| listParamAct
;

listParamAct 
: expre 
| expre COMA_ listParamAct
;

opLogic : LOGICOAND_  
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

