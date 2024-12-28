/*****************************************************************************/
/**                       You You You feliz Navidad                         **/
/*****************************************************************************/

%{
#include <stdio.h>
#include <string.h>

#include "header.h"    // <-- AQUI tienes tu "typedef struct texp { ... } Expresion;"
#include "libgci.h"    // <-- Para las funciones de generación de código intermedio
#include "libtds.h"    // <-- Para la tabla de símbolos, tipos, etc.

// Variables globales que ya usabas
int mainDeclarada = 0;
int tipoRetornoActual = T_ERROR;  // Valor inicial para tipo desconocido (12-12)

// En la parte de declaraciones del .y (antes de %union o después):
int ifRefSalto;  // variable global (o estática) para guardar la lista de saltos
int ifRefGoto;   // para el goto final, si lo necesitas
int forRefCond;

int si;
// Otras variables globales para la TdS (ya declaradas en libtds.h):
//   extern int dvar;
//   extern int niv;


%}

/* --------------------------------------------------------------------------
   Declaración de la unión, usando la definición de Expresion que tienes en 
   "header.h"
   -------------------------------------------------------------------------- */
%union {
  int cent;
  char *ident;
  Expresion texp;  // AÑADIDO: aquí usamos tu struct { int t; int pos; }
  Aux aux;
}

/* --------------------------------------------------------------------------
   Declaración de tokens y tipos no terminales
   -------------------------------------------------------------------------- */
%token PARA_ PARC_ MAS_ MENOS_ POR_ DIV_
%token ASIGSUMA_ ASIGRESTA_ ASIGPRODUCTO_ ASIGDIVISION_ LOGICOAND_ LOGICOOR_
%token IGUALDAD_ DISTINTO_ MAYORIGU_ MENORIGU_ INCREMENTO_ DECREMENTO_ ASIG_
%token OPRESTO_ MAYOR_ MENOR_ OPNEG_ IDENTIFICADOR_ TRUE_ FALSE_ BOOL_ RETURN_
%token READ_ PRINT_ IF_ FOR_ ACORCH_ CCORCH_ IBLOCK_ FBLOCK_ PCOMA_ COMA_ INT_
%token ELSE_

%token <cent>  CTE_
%token <ident> ID_

%type  <cent>  tipoSimp listDecla decla declaFunc declaVar opUna opMul opAd opLogic opIgual opRel
%type  <cent>  paramAct listParamAct
%type  <texp>  expre expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi const expreOP
%type  <cent>  paramForm listParamForm  // Para que coincida con tu código

%type  <aux> instSelec instIter
%%

/* --------------------------------------------------------------------------
   Inicio de tu programa
   -------------------------------------------------------------------------- */
programa
  : { dvar=0; niv=0; cargaContexto(niv); }
    listDecla
    {
      if(verTdS) mostrarTdS();
      if(!mainDeclarada){
          yyerror("El programa no tiene una función main ");
      }
    }
  ;

/* --------------------------------------------------------------------------
   listDecla: secuencia de declaraciones
   -------------------------------------------------------------------------- */
listDecla
  : decla { $$ = $1; }
  | listDecla decla { $$ = $1 + $2; }
  ;

/* --------------------------------------------------------------------------
   decla: o bien declaración de variable o bien declaración de función
   -------------------------------------------------------------------------- */
decla
  : declaVar
  | declaFunc
  ;

/* --------------------------------------------------------------------------
   declaVar: declaración de variable (con o sin asignación, array, etc.)
   -------------------------------------------------------------------------- */
declaVar
  : tipoSimp ID_ PCOMA_
    {
      if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
        yyerror("Identificador repetido");
      } else {
        dvar += TALLA_TIPO_SIMPLE;
      }
    }

  | tipoSimp ID_ ASIG_ const PCOMA_
    {
      // Verificamos compatibilidad
      if (!(($1 == T_ENTERO && $4.t == T_ENTERO) ||
            ($1 == T_LOGICO && $4.t == T_LOGICO))) {
        yyerror("Error: Tipo incompatible entre la variable y la constante asignada");
      }

      // Insertar la variable en la TDS
      if (!insTdS($2, VARIABLE, $1, niv, dvar, -1)) {
        yyerror("Identificador repetido");
      } else {
        dvar += TALLA_TIPO_SIMPLE;
      }

      // AÑADIDO: Generación de código: asignar la constante a la variable
      SIMB sim = obtTdS($2);
      emite(EASIG, crArgPos(niv, $4.pos), crArgNul(), crArgPos(sim.n, sim.d));
    }

  | tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_
    {
      int numelem = $4;
      if (numelem <= 0) {
        yyerror("Talla inapropiada del array");
        numelem = 0;
      }
      int refe = insTdA($1, numelem);
      if (!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, refe)) {
        yyerror("Identificador repetido");
      } else {
        dvar += numelem * TALLA_TIPO_SIMPLE;
      }
    }
  ;

/* --------------------------------------------------------------------------
   const: constants (entera, true, false)
   -------------------------------------------------------------------------- */
const
  : CTE_
    {
      $$.t = T_ENTERO;
      // Creamos un temporal y emitimos su carga
      $$.pos = creaVarTemp();
      emite(EASIG, crArgEnt($1), crArgNul(), crArgPos(niv, $$.pos));
    }
  | TRUE_
    {
      $$.t = T_LOGICO;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
    }
  | FALSE_
    {
      $$.t = T_LOGICO;
      $$.pos = creaVarTemp();
      emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.pos));
    }
  ;

/* --------------------------------------------------------------------------
   tipoSimp: INT_ o BOOL_
   -------------------------------------------------------------------------- */
tipoSimp
  : INT_  { $$ = T_ENTERO; }
  | BOOL_ { $$ = T_LOGICO; }
  ;

/* --------------------------------------------------------------------------
   declaFunc: declaración de función con parámetros y bloque
   -------------------------------------------------------------------------- */
declaFunc
  : tipoSimp ID_ PARA_
    {
      niv++;
      cargaContexto(niv);
    }
    paramForm
    {
      tipoRetornoActual = $1;
      SIMB sim = obtTdS($2);

      if (sim.t != T_ERROR) {
          yyerror("La función ya está declarada");
          tipoRetornoActual = T_ERROR;
      }
      int dominioParametros = $5;

      if (tipoRetornoActual != T_ERROR) {
          if (!insTdS($2, FUNCION, tipoRetornoActual, niv, dvar, dominioParametros)) {
              yyerror("Error al insertar la función");
          }
      }
    }
    PARC_
    bloque
    {
      if (strcmp($2, "main") == 0) {
        if (mainDeclarada) {
          yyerror("La función 'main' ya ha sido declarada");
        } else {
          mainDeclarada = 1;
        }
      }
      descargaContexto(niv);
      niv--;
    }
  ;

/* --------------------------------------------------------------------------
   paramForm: lista de parámetros formales o vacío
   -------------------------------------------------------------------------- */
paramForm
  : /*empty*/ { $$ = insTdD(-1, T_VACIO); }
  | listParamForm { $$ = $1; }
  ;

/* --------------------------------------------------------------------------
   listParamForm: tipoSimp ID_ (COMA tipoSimp ID_)*
   -------------------------------------------------------------------------- */
listParamForm
  : tipoSimp ID_
    {
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) {
        yyerror("Identificador de parámetro repetido");
      } else {
        int refDom = insTdD(-1, $1);
        insTdS($2, PARAMETRO, $1, niv, dvar, -1);
        dvar += TALLA_TIPO_SIMPLE;
        $$ = refDom;
      }
    }
  | tipoSimp ID_ COMA_ listParamForm
    {
      SIMB sim = obtTdS($2);
      if (sim.t != T_ERROR) {
        yyerror("Identificador de parámetro repetido");
      } else {
        int refDom = insTdD($4, $1);
        insTdS($2, PARAMETRO, $1, niv, dvar, -1);
        dvar += TALLA_TIPO_SIMPLE;
        $$ = refDom;
      }
    }
  ;

/* --------------------------------------------------------------------------
   bloque: IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_
   -------------------------------------------------------------------------- */
bloque
  : IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_
    {
      // Comprobamos el return
      if (tipoRetornoActual == T_ERROR) {
        yyerror("Error: Declaración incompleta de la función. No se puede validar el tipo de 'return'.");
      } else if (tipoRetornoActual != $5.t) {
        yyerror("Error: Incompatibilidad de tipos en el 'return'.");
      } else if ($5.t == T_ARRAY) {
        yyerror("No se puede retornar un array directamente.");
      }

      // AÑADIDO: generar la instrucción de retorno
      // Se podría mover a la posición de retorno, etc.
      emite(EASIG, crArgPos(niv, $5.pos), crArgNul(), crArgPos(niv, 0)); // Ejemplo
      emite(RET, crArgNul(), crArgNul(), crArgNul());
    }
  ;

/* --------------------------------------------------------------------------
   declaVarLocal: cero o más declaraciones locales
   -------------------------------------------------------------------------- */
declaVarLocal
  : /*empty*/
  | declaVarLocal declaVar
  ;

/* --------------------------------------------------------------------------
   listInst: cero o más instrucciones
   -------------------------------------------------------------------------- */
listInst
  : /*empty*/
  | listInst inst
  ;

/* --------------------------------------------------------------------------
   inst: un bloque, una instExpre, E/S, if, for...
   -------------------------------------------------------------------------- */
inst
  : IBLOCK_ listInst FBLOCK_
  | instExpre
  | instEntSal
  | instSelec
  | instIter
  ;

/* --------------------------------------------------------------------------
   instExpre: expre ;  o  ;
   -------------------------------------------------------------------------- */
instExpre
  : expre PCOMA_
  | PCOMA_
  ;

/* --------------------------------------------------------------------------
   instEntSal: READ(...) ;  o  PRINT(...) ;
   -------------------------------------------------------------------------- */
instEntSal
  : READ_ PARA_ ID_ PARC_ PCOMA_
    {
      SIMB sim = obtTdS($3);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != T_ENTERO) yyerror("Error: La variable a 'read' tiene que ser de tipo entero");
      emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.n, sim.d));
    }
  | PRINT_ PARA_ expre PARC_ PCOMA_
    {
      if ($3.t != T_ENTERO) yyerror("Error: La expresión a 'print' debe ser de tipo entero");
      emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.pos));
    }
  ;

/* --------------------------------------------------------------------------
   instSelec: IF(...) inst ELSE inst
   -------------------------------------------------------------------------- */
instSelec
  : IF_ PARA_ expre PARC_
    {
      if ($3.t != T_LOGICO)
        yyerror("Error: la condición del IF debe ser lógica");

      // mid-rule action
      // en vez de "$$ = creaLans(si);", usas una variable global:
      ifRefSalto = creaLans(si);

      // emite la instrucción condicional incompleta
      emite(EIGUAL, crArgPos(niv, $3.pos), crArgEnt(0), crArgEtq(-1));
    }
    inst
    {
      // aquí, antes del ELSE, hacemos un goto 
      ifRefGoto = creaLans(si);
      emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));

      // completamos la primera lista de saltos (del IF)
      completaLans(ifRefSalto, crArgEtq(si));
    }
    ELSE_
    inst
    {
      // completamos la lista del goto final
      completaLans(ifRefGoto, crArgEtq(si));
    }
  ;


/* --------------------------------------------------------------------------
   instIter: FOR( expreOP ; expre ; expreOP ) inst
   -------------------------------------------------------------------------- */
instIter
  : FOR_ PARA_ expreOP PCOMA_ expre PCOMA_ expreOP
    {
          
      /* Chequeos de tipos */
      if ($3.t != T_ERROR && $3.t != T_ENTERO && $3.t != T_LOGICO) {
        yyerror("La inicialización del 'for' debe ser de tipo simple");
      }
      if ($5.t != T_ERROR && $5.t != T_LOGICO) {
        yyerror("La condición del 'for' debe ser de tipo lógico");
      }
      if ($7.t != T_ERROR && $7.t != T_ENTERO && $7.t != T_LOGICO) {
        yyerror("La actualización del 'for' debe ser de tipo simple");
      }

      /* mid-rule action sin '$$':
         Guardamos en 'forRefCond' un lans si lo necesitáramos
      */
      forRefCond = creaLans(si);
      emite(EIGUAL, crArgPos(niv, $5.pos), crArgEnt(0), crArgEtq(-1));
    }
    PARC_
    inst
    {
      completaLans(forRefCond, crArgEtq(si));
    }
  ;

/* --------------------------------------------------------------------------
   expreOP: opción vacía o expre
   -------------------------------------------------------------------------- */
expreOP
  : /*empty*/
    {
      $$.t = T_ERROR;
      $$.pos = -1;
    }
  | expre
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  ;

/* --------------------------------------------------------------------------
   expre: expreLogic | ID ASIG expre | ID[...] ASIG expre
   -------------------------------------------------------------------------- */
expre
  : expreLogic
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | ID_ ASIG_ expre
    {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != $3.t) yyerror("Error de tipos en la asignación");

      emite(EASIG, crArgPos(niv, $3.pos), crArgNul(), crArgPos(sim.n, sim.d));

      // Guardar el valor asignado en un temporal para que expre devuelva un offset
      int tmp = creaVarTemp();
      emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, tmp));

      $$.t = sim.t;
      $$.pos = tmp;
    }
  | ID_ ACORCH_ expre CCORCH_ ASIG_ expre
    {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("La variable debe ser de tipo array");
      else if ($3.t != T_ENTERO) yyerror("El índice debe ser entero");
      else if ($6.t != T_ENTERO) yyerror("El valor asignado debe ser entero");

      // EVA => array[pos] = valor
      emite(EVA, crArgPos(sim.n, sim.d), crArgPos(niv, $3.pos), crArgPos(niv, $6.pos));

      // Ponemos en un temporal el valor final
      int tmp = creaVarTemp();
      emite(EASIG, crArgPos(niv, $6.pos), crArgNul(), crArgPos(niv, tmp));

      $$.t = T_ENTERO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreLogic: expreIgual (opLogic expreIgual)*
   -------------------------------------------------------------------------- */
expreLogic
  : expreIgual
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | expreLogic opLogic expreIgual
    {
      if ($1.t != T_LOGICO || $3.t != T_LOGICO)
        yyerror("Operación lógica con tipos no booleanos");
      int tmp = creaVarTemp();

      // Ejemplo: AND => EMULT, OR => ESUM (más algo para forzar booleano)
      if ($2 == OP_AND) {
        emite(EMULT, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, tmp));
      } else {
        // OR
        emite(ESUM, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, tmp));
      }

      $$.t = T_LOGICO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreIgual: expreRel (opIgual expreRel)*
   -------------------------------------------------------------------------- */
expreIgual
  : expreRel
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | expreIgual opIgual expreRel
    {
      // Control de tipos
      if ($1.t != T_ERROR && $3.t != T_ERROR) {
        if ($1.t != $3.t) yyerror("No son del mismo tipo");
        else if ($3.t != T_ENTERO && $3.t != T_LOGICO)
          yyerror("Operación de igualdad no entre enteros o lógicos");
      }
      int tmp = creaVarTemp();
      emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, tmp));

      if ($2 == OP_IGUAL) {
        emite(EIGUAL, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si+2));
      } else {
        // DISTINTO_
        emite(EDIST, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si+2));
      }
      emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, tmp));

      $$.t = T_LOGICO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreRel: expreAd (opRel expreAd)*
   -------------------------------------------------------------------------- */
expreRel
  : expreAd
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | expreRel opRel expreAd
    {
      if ($1.t != T_ERROR && $3.t != T_ERROR) {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO)
          yyerror("Operación relacional no entre enteros");
      }
      int tmp = creaVarTemp();
      emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, tmp));

      emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si+2));
      emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, tmp));

      $$.t = T_LOGICO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreAd: expreMul (opAd expreMul)*
   -------------------------------------------------------------------------- */
expreAd
  : expreMul
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | expreAd opAd expreMul
    {
      if ($1.t != T_ERROR && $3.t != T_ERROR) {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO)
          yyerror("Operación aritmética no entre enteros");
      }
      int tmp = creaVarTemp();
      emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, tmp));

      $$.t = T_ENTERO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreMul: expreUna (opMul expreUna)*
   -------------------------------------------------------------------------- */
expreMul
  : expreUna
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | expreMul opMul expreUna
    {
      if ($1.t != T_ERROR && $3.t != T_ERROR) {
        if ($1.t != T_ENTERO || $3.t != T_ENTERO)
          yyerror("Operación aritmética no entre enteros");
      }
      int tmp = creaVarTemp();
      emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, tmp));

      $$.t = T_ENTERO;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreUna: expreSufi | opUna expreUna
   -------------------------------------------------------------------------- */
expreUna
  : expreSufi
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | opUna expreUna
    {
      // Por ejemplo, +expre => nada especial, -expre => EDIF(0,expre), !expre => ESIG(1,expre)
      int tmp = creaVarTemp();
      if ($1 == OPNEG_) {
        // Negación lógica
        emite(ESIG, crArgEnt(1), crArgPos(niv, $2.pos), crArgPos(niv, tmp));
      }
      else if ($1 == MAS_) {
        // +expre => copiamos tal cual
        emite(EASIG, crArgPos(niv, $2.pos), crArgNul(), crArgPos(niv, tmp));
      }
      else {
        // MENOS_
        emite(EDIF, crArgEnt(0), crArgPos(niv, $2.pos), crArgPos(niv, tmp));
      }
      $$.t = $2.t;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   expreSufi: const | (expre) | ID | ID[...] | ID(paramAct)
   -------------------------------------------------------------------------- */
expreSufi
  : const
    {
      $$.t = $1.t;
      $$.pos = $1.pos;
    }
  | PARA_ expre PARC_
    {
      $$.t = $2.t;
      $$.pos = $2.pos;
    }
  | ID_
    {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Variable no declarada");

      int tmp = creaVarTemp();
      emite(EASIG, crArgPos(niv, sim.d), crArgNul(), crArgPos(niv, tmp));

      $$.t = sim.t;
      $$.pos = tmp;
    }
  | ID_ ACORCH_ expre CCORCH_
    {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("Uso inapropiado de una variable no array");

      int tmp = creaVarTemp();
      emite(EAV, crArgPos(sim.n, sim.d), crArgPos(niv, $3.pos), crArgPos(niv, tmp));
      $$.t = T_ENTERO; // Asumiendo array de enteros
      $$.pos = tmp;
    }
  | ID_ PARA_ paramAct PARC_
    {
      SIMB sim = obtTdS($1);
      if (sim.t == T_ERROR) yyerror("Función no declarada");
      else if (sim.t != T_ENTERO && sim.t != T_LOGICO) {
        yyerror("No es una función o su tipo no es entero/lógico");
      } else {
        if (!cmpDom(sim.ref, $3)) {
          yyerror("Error: Argumentos incorrectos en la llamada de función");
        }
      }
      emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d));
      INF inf = obtTdD(sim.ref);
      emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));

      int tmp = creaVarTemp();
      emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, tmp));

      $$.t = sim.t;
      $$.pos = tmp;
    }
  ;

/* --------------------------------------------------------------------------
   paramAct: listaParamAct o vacío
   -------------------------------------------------------------------------- */
paramAct
  : /*empty*/
    {
      $$ = insTdD(-1, T_VACIO);
    }
  | listParamAct
    {
      $$ = $1;
    }
  ;

/* --------------------------------------------------------------------------
   listParamAct: expre (, expre)*
   -------------------------------------------------------------------------- */
listParamAct
  : expre
    {
      // Un solo parámetro
      $$ = insTdD(-1, $1.t);
      emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.pos));
    }
  | expre COMA_
    {
      // Hacemos push antes de procesar la lista
      emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.pos));
    }
    listParamAct
    {
      $$ = insTdD($4, $1.t);
    }
  ;

/* --------------------------------------------------------------------------
   opLogic: LOGICOAND_ | LOGICOOR_
   -------------------------------------------------------------------------- */
opLogic
  : LOGICOAND_ { $$ = OP_AND; }
  | LOGICOOR_  { $$ = OP_OR; }
  ;

/* --------------------------------------------------------------------------
   opIgual: IGUALDAD_ | DISTINTO_
   -------------------------------------------------------------------------- */
opIgual
  : IGUALDAD_ { $$ = OP_IGUAL; }
  | DISTINTO_ { $$ = DISTINTO_; }
  ;

/* --------------------------------------------------------------------------
   opRel: MAYOR_ | MENOR_ | MAYORIGU_ | MENORIGU_
   -------------------------------------------------------------------------- */
opRel
  : MAYOR_    { $$ = OP_MAYOR; }
  | MENOR_    { $$ = OP_MENOR; }
  | MAYORIGU_ { $$ = OP_MAYORIG; }
  | MENORIGU_ { $$ = OP_MENORIG; }
  ;

/* --------------------------------------------------------------------------
   opAd: MAS_ | MENOS_
   -------------------------------------------------------------------------- */
opAd
  : MAS_   { $$ = ESUM; }
  | MENOS_ { $$ = EDIF; }
  ;

/* --------------------------------------------------------------------------
   opMul: POR_ | DIV_
   -------------------------------------------------------------------------- */
opMul
  : POR_ { $$ = EMULT; }
  | DIV_ { $$ = EDIVI; }
  ;

/* --------------------------------------------------------------------------
   opUna: MAS_ | MENOS_ | OPNEG_
   -------------------------------------------------------------------------- */
opUna
  : MAS_   { $$ = MAS_; }
  | MENOS_ { $$ = MENOS_; }
  | OPNEG_ { $$ = OPNEG_; }
  ;

%%
