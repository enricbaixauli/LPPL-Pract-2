/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/asin.y"


#include <stdio.h>

#include <string.h>

#include "header.h"

#include "asin.h"

#include "libtds.h"



int mainDeclarada = 0;

int tipoRetornoActual = T_ERROR;  // Valor inicial para tipo desconocido 12-12


#line 91 "asin.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PARA_ = 3,                      /* PARA_  */
  YYSYMBOL_PARC_ = 4,                      /* PARC_  */
  YYSYMBOL_MAS_ = 5,                       /* MAS_  */
  YYSYMBOL_MENOS_ = 6,                     /* MENOS_  */
  YYSYMBOL_POR_ = 7,                       /* POR_  */
  YYSYMBOL_DIV_ = 8,                       /* DIV_  */
  YYSYMBOL_ASIGSUMA_ = 9,                  /* ASIGSUMA_  */
  YYSYMBOL_ASIGRESTA_ = 10,                /* ASIGRESTA_  */
  YYSYMBOL_ASIGPRODUCTO_ = 11,             /* ASIGPRODUCTO_  */
  YYSYMBOL_ASIGDIVISION_ = 12,             /* ASIGDIVISION_  */
  YYSYMBOL_LOGICOAND_ = 13,                /* LOGICOAND_  */
  YYSYMBOL_LOGICOOR_ = 14,                 /* LOGICOOR_  */
  YYSYMBOL_IGUALDAD_ = 15,                 /* IGUALDAD_  */
  YYSYMBOL_DISTINTO_ = 16,                 /* DISTINTO_  */
  YYSYMBOL_MAYORIGU_ = 17,                 /* MAYORIGU_  */
  YYSYMBOL_MENORIGU_ = 18,                 /* MENORIGU_  */
  YYSYMBOL_INCREMENTO_ = 19,               /* INCREMENTO_  */
  YYSYMBOL_DECREMENTO_ = 20,               /* DECREMENTO_  */
  YYSYMBOL_ASIG_ = 21,                     /* ASIG_  */
  YYSYMBOL_OPRESTO_ = 22,                  /* OPRESTO_  */
  YYSYMBOL_MAYOR_ = 23,                    /* MAYOR_  */
  YYSYMBOL_MENOR_ = 24,                    /* MENOR_  */
  YYSYMBOL_OPNEG_ = 25,                    /* OPNEG_  */
  YYSYMBOL_IDENTIFICADOR_ = 26,            /* IDENTIFICADOR_  */
  YYSYMBOL_TRUE_ = 27,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 28,                    /* FALSE_  */
  YYSYMBOL_BOOL_ = 29,                     /* BOOL_  */
  YYSYMBOL_RETURN_ = 30,                   /* RETURN_  */
  YYSYMBOL_READ_ = 31,                     /* READ_  */
  YYSYMBOL_PRINT_ = 32,                    /* PRINT_  */
  YYSYMBOL_IF_ = 33,                       /* IF_  */
  YYSYMBOL_FOR_ = 34,                      /* FOR_  */
  YYSYMBOL_ACORCH_ = 35,                   /* ACORCH_  */
  YYSYMBOL_CCORCH_ = 36,                   /* CCORCH_  */
  YYSYMBOL_IBLOCK_ = 37,                   /* IBLOCK_  */
  YYSYMBOL_FBLOCK_ = 38,                   /* FBLOCK_  */
  YYSYMBOL_PCOMA_ = 39,                    /* PCOMA_  */
  YYSYMBOL_COMA_ = 40,                     /* COMA_  */
  YYSYMBOL_INT_ = 41,                      /* INT_  */
  YYSYMBOL_ELSE_ = 42,                     /* ELSE_  */
  YYSYMBOL_CTE_ = 43,                      /* CTE_  */
  YYSYMBOL_ID_ = 44,                       /* ID_  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_programa = 46,                  /* programa  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_listDecla = 48,                 /* listDecla  */
  YYSYMBOL_decla = 49,                     /* decla  */
  YYSYMBOL_declaVar = 50,                  /* declaVar  */
  YYSYMBOL_const = 51,                     /* const  */
  YYSYMBOL_tipoSimp = 52,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 53,                 /* declaFunc  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_paramForm = 56,                 /* paramForm  */
  YYSYMBOL_listParamForm = 57,             /* listParamForm  */
  YYSYMBOL_bloque = 58,                    /* bloque  */
  YYSYMBOL_declaVarLocal = 59,             /* declaVarLocal  */
  YYSYMBOL_listInst = 60,                  /* listInst  */
  YYSYMBOL_inst = 61,                      /* inst  */
  YYSYMBOL_instExpre = 62,                 /* instExpre  */
  YYSYMBOL_instEntSal = 63,                /* instEntSal  */
  YYSYMBOL_instSelec = 64,                 /* instSelec  */
  YYSYMBOL_65_4 = 65,                      /* $@4  */
  YYSYMBOL_instIter = 66,                  /* instIter  */
  YYSYMBOL_67_5 = 67,                      /* $@5  */
  YYSYMBOL_expreOP = 68,                   /* expreOP  */
  YYSYMBOL_expre = 69,                     /* expre  */
  YYSYMBOL_expreLogic = 70,                /* expreLogic  */
  YYSYMBOL_expreIgual = 71,                /* expreIgual  */
  YYSYMBOL_expreRel = 72,                  /* expreRel  */
  YYSYMBOL_expreAd = 73,                   /* expreAd  */
  YYSYMBOL_expreMul = 74,                  /* expreMul  */
  YYSYMBOL_expreUna = 75,                  /* expreUna  */
  YYSYMBOL_expreSufi = 76,                 /* expreSufi  */
  YYSYMBOL_paramAct = 77,                  /* paramAct  */
  YYSYMBOL_listParamAct = 78,              /* listParamAct  */
  YYSYMBOL_opLogic = 79,                   /* opLogic  */
  YYSYMBOL_opIgual = 80,                   /* opIgual  */
  YYSYMBOL_opRel = 81,                     /* opRel  */
  YYSYMBOL_opAd = 82,                      /* opAd  */
  YYSYMBOL_opMul = 83,                     /* opMul  */
  YYSYMBOL_opUna = 84                      /* opUna  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    69,    87,    89,    97,    99,   107,   121,
     147,   181,   183,   185,   193,   195,   205,   209,   205,   247,
     248,   256,   267,   298,   349,   351,   359,   361,   369,   371,
     373,   375,   377,   385,   387,   395,   405,   417,   417,   431,
     431,   479,   481,   489,   491,   503,   527,   529,   543,   545,
     565,   567,   585,   587,   605,   607,   625,   627,   639,   641,
     643,   653,   665,   691,   692,   696,   697,   706,   708,   716,
     718,   726,   728,   730,   732,   740,   742,   750,   752,   760,
     762,   764
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PARA_", "PARC_",
  "MAS_", "MENOS_", "POR_", "DIV_", "ASIGSUMA_", "ASIGRESTA_",
  "ASIGPRODUCTO_", "ASIGDIVISION_", "LOGICOAND_", "LOGICOOR_", "IGUALDAD_",
  "DISTINTO_", "MAYORIGU_", "MENORIGU_", "INCREMENTO_", "DECREMENTO_",
  "ASIG_", "OPRESTO_", "MAYOR_", "MENOR_", "OPNEG_", "IDENTIFICADOR_",
  "TRUE_", "FALSE_", "BOOL_", "RETURN_", "READ_", "PRINT_", "IF_", "FOR_",
  "ACORCH_", "CCORCH_", "IBLOCK_", "FBLOCK_", "PCOMA_", "COMA_", "INT_",
  "ELSE_", "CTE_", "ID_", "$accept", "programa", "$@1", "listDecla",
  "decla", "declaVar", "const", "tipoSimp", "declaFunc", "$@2", "$@3",
  "paramForm", "listParamForm", "bloque", "declaVarLocal", "listInst",
  "inst", "instExpre", "instEntSal", "instSelec", "$@4", "instIter", "$@5",
  "expreOP", "expre", "expreLogic", "expreIgual", "expreRel", "expreAd",
  "expreMul", "expreUna", "expreSufi", "paramAct", "listParamAct",
  "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -117,     5,    19,  -117,  -117,  -117,    19,  -117,  -117,   -37,
    -117,  -117,    26,  -117,   -18,   -40,  -117,    19,  -117,  -117,
    -117,   -28,   -22,   -21,  -117,  -117,  -117,    11,    17,    50,
    -117,    19,    27,  -117,  -117,  -117,    19,  -117,    22,    12,
     -13,   119,  -117,  -117,  -117,   119,    65,    70,    71,    75,
    -117,  -117,    -2,  -117,  -117,  -117,  -117,  -117,  -117,    40,
      14,    47,    35,    66,    69,  -117,  -117,   148,    78,    44,
      41,   119,   119,   119,    64,   119,   119,   119,  -117,  -117,
    -117,   148,  -117,  -117,   148,  -117,  -117,  -117,  -117,   148,
    -117,  -117,   148,  -117,  -117,   148,     3,  -117,  -117,    46,
      82,    83,    84,    55,  -117,  -117,    59,    96,  -117,  -117,
      68,    47,    35,    66,    69,  -117,   119,  -117,    67,    74,
    -117,   119,   119,  -117,    89,    79,  -117,  -117,   106,    77,
    -117,   119,  -117,    63,   119,  -117,   106,  -117,  -117,   110,
     106,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    15,    14,     3,     4,     6,     0,
       7,     5,     0,    16,     0,     0,     8,    19,    12,    13,
      11,     0,     0,     0,    17,    20,     9,     0,    21,     0,
      10,     0,     0,    22,    24,    18,    26,    25,     0,     0,
       0,     0,    79,    80,    81,     0,     0,     0,     0,     0,
      26,    34,    60,    58,    27,    29,    30,    31,    32,     0,
      43,    46,    48,    50,    52,    54,    56,     0,     0,     0,
       0,     0,     0,    41,     0,    63,     0,     0,    33,    67,
      68,     0,    69,    70,     0,    73,    74,    71,    72,     0,
      75,    76,     0,    77,    78,     0,    60,    57,    59,     0,
       0,     0,     0,     0,    42,    28,    65,     0,    64,    44,
       0,    47,    49,    51,    53,    55,     0,    23,     0,     0,
      37,     0,     0,    62,    61,     0,    35,    36,     0,     0,
      66,     0,    61,     0,    41,    45,     0,    39,    38,     0,
       0,    40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -117,  -117,  -117,  -117,   111,    85,   104,   -15,  -117,  -117,
    -117,  -117,    88,  -117,  -117,    73,  -116,  -117,  -117,  -117,
    -117,  -117,  -117,   -14,   -41,  -117,    45,    43,    39,    37,
     -54,  -117,  -117,     8,  -117,  -117,  -117,  -117,  -117,  -117
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    53,     9,    10,    17,
      29,    24,    25,    35,    36,    39,    54,    55,    56,    57,
     128,    58,   139,   103,    59,    60,    61,    62,    63,    64,
      65,    66,   107,   108,    81,    84,    89,    92,    95,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,    75,    23,    22,    69,     3,    75,    12,    14,    18,
      19,    26,   133,    97,    27,    41,    23,    42,    43,    76,
     138,    38,    15,    28,   141,    20,    16,    79,    80,    13,
     101,   102,   104,    77,   106,   109,   110,    44,   116,    18,
      19,   115,    45,    46,    47,    48,    49,    14,     4,    50,
      30,    51,    85,    86,    32,    20,    52,    31,    87,    88,
       5,    15,    82,    83,    34,    16,    40,    41,    70,    42,
      43,    90,    91,    71,    72,   125,    93,    94,    73,    78,
     129,   106,    98,    99,   117,   100,   118,   119,   120,    44,
     135,    18,    19,   104,   121,    46,    47,    48,    49,   122,
     123,    50,   105,    51,   124,   136,   126,    20,    52,    41,
     131,    42,    43,   127,   140,   132,   134,    11,    21,    33,
     137,    37,    41,    74,    42,    43,   111,   112,   113,   114,
     130,    44,     0,    18,    19,     0,     0,    46,    47,    48,
      49,     0,     0,    50,    44,    51,    18,    19,     0,    20,
      52,    41,     0,    42,    43,     0,     0,     0,     0,     0,
       0,     0,    20,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    18,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    96
};

static const yytype_int16 yycheck[] =
{
      41,     3,    17,    43,    45,     0,     3,    44,    21,    27,
      28,    39,   128,    67,    36,     3,    31,     5,     6,    21,
     136,    36,    35,    44,   140,    43,    39,    13,    14,     3,
      71,    72,    73,    35,    75,    76,    77,    25,    35,    27,
      28,    95,    30,    31,    32,    33,    34,    21,    29,    37,
      39,    39,    17,    18,     4,    43,    44,    40,    23,    24,
      41,    35,    15,    16,    37,    39,    44,     3,     3,     5,
       6,     5,     6,     3,     3,   116,     7,     8,     3,    39,
     121,   122,     4,    39,    38,    44,     4,     4,     4,    25,
     131,    27,    28,   134,    39,    31,    32,    33,    34,    40,
       4,    37,    38,    39,    36,    42,    39,    43,    44,     3,
      21,     5,     6,    39,     4,    36,    39,     6,    14,    31,
     134,    36,     3,    50,     5,     6,    81,    84,    89,    92,
     122,    25,    -1,    27,    28,    -1,    -1,    31,    32,    33,
      34,    -1,    -1,    37,    25,    39,    27,    28,    -1,    43,
      44,     3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,     0,    29,    41,    48,    49,    50,    52,
      53,    49,    44,     3,    21,    35,    39,    54,    27,    28,
      43,    51,    43,    52,    56,    57,    39,    36,    44,    55,
      39,    40,     4,    57,    37,    58,    59,    50,    52,    60,
      44,     3,     5,     6,    25,    30,    31,    32,    33,    34,
      37,    39,    44,    51,    61,    62,    63,    64,    66,    69,
      70,    71,    72,    73,    74,    75,    76,    84,    69,    69,
       3,     3,     3,     3,    60,     3,    21,    35,    39,    13,
      14,    79,    15,    16,    80,    17,    18,    23,    24,    81,
       5,     6,    82,     7,     8,    83,    44,    75,     4,    39,
      44,    69,    69,    68,    69,    38,    69,    77,    78,    69,
      69,    71,    72,    73,    74,    75,    35,    38,     4,     4,
       4,    39,    40,     4,    36,    69,    39,    39,    65,    69,
      78,    21,    36,    61,    39,    69,    42,    68,    61,    67,
       4,    61
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    51,    52,    52,    54,    55,    53,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    65,    64,    67,
      66,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    82,    82,    83,    83,    84,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     0,     0,     8,     0,
       1,     2,     4,     7,     0,     2,     0,     2,     3,     1,
       1,     1,     1,     2,     1,     5,     5,     0,     8,     0,
      10,     0,     1,     1,     3,     6,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     2,     1,     3,
       1,     4,     4,     0,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 69 "src/asin.y"
    { dvar=0; niv=0; cargaContexto(niv); }
#line 1274 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 73 "src/asin.y"
    { if(1==1) mostrarTdS();

      if(!mainDeclarada){

            yyerror("El programa no tiene una función main ");}

    }
#line 1286 "asin.c"
    break;

  case 4: /* listDecla: decla  */
#line 87 "src/asin.y"
          { (yyval.cent) = (yyvsp[0].cent);}
#line 1292 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 89 "src/asin.y"
                    { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1298 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ PCOMA_  */
#line 107 "src/asin.y"
                        {

      if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) {

        yyerror("Identificador repetido");

      } else {

        dvar += TALLA_TIPO_SIMPLE;

      }

    }
#line 1316 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const PCOMA_  */
#line 121 "src/asin.y"
                                    {

      // Primero verificas la compatibilidad de tipos

      if (!(((yyvsp[-4].cent) == T_ENTERO && (yyvsp[-1].cent) == T_ENTERO) || 

            ((yyvsp[-4].cent) == T_LOGICO && (yyvsp[-1].cent) == T_LOGICO))) {

        yyerror("Error: Tipo incompatible entre la variable y la constante asignada");

      }

      // Independientemente de lo anterior, tratas de insertar la variable

      if (!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1)) {

        yyerror("Identificador repetido");

      } else {

        dvar += TALLA_TIPO_SIMPLE;

      }

    }
#line 1346 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_  */
#line 147 "src/asin.y"
                                             {

      int numelem = (yyvsp[-2].cent);

      if (numelem <= 0) {

        yyerror("Talla inapropiada del array");

        numelem = 0;

      }

      int refe = insTdA((yyvsp[-5].cent), numelem);

      if (!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe)) {

        yyerror("Identificador repetido");

      } else {

        dvar += numelem * TALLA_TIPO_SIMPLE;

      }

    }
#line 1376 "asin.c"
    break;

  case 11: /* const: CTE_  */
#line 181 "src/asin.y"
           { (yyval.cent) = T_ENTERO; }
#line 1382 "asin.c"
    break;

  case 12: /* const: TRUE_  */
#line 183 "src/asin.y"
           { (yyval.cent) = T_LOGICO; }
#line 1388 "asin.c"
    break;

  case 13: /* const: FALSE_  */
#line 185 "src/asin.y"
           { (yyval.cent) = T_LOGICO; }
#line 1394 "asin.c"
    break;

  case 14: /* tipoSimp: INT_  */
#line 193 "src/asin.y"
          { (yyval.cent) = T_ENTERO; }
#line 1400 "asin.c"
    break;

  case 15: /* tipoSimp: BOOL_  */
#line 195 "src/asin.y"
          { (yyval.cent) = T_LOGICO; }
#line 1406 "asin.c"
    break;

  case 16: /* $@2: %empty  */
#line 205 "src/asin.y"
                       {
      niv++;  // Aumenta el nivel de anidación
      cargaContexto(niv);
  }
#line 1415 "asin.c"
    break;

  case 17: /* $@3: %empty  */
#line 209 "src/asin.y"
             {
      tipoRetornoActual = (yyvsp[-4].cent);  // Asigna el tipo de retorno
      SIMB sim = obtTdS((yyvsp[-3].ident));

      if (sim.t != T_ERROR) {
          yyerror("La función ya está declarada");
          tipoRetornoActual = T_ERROR;
      }
	int dominioParametros = (yyvsp[0].cent);
      if (tipoRetornoActual != T_ERROR) {
          if (!insTdS((yyvsp[-3].ident), FUNCION, tipoRetornoActual, niv, dvar, dominioParametros)) {
              yyerror("Error al insertar la función");
          }
      }
  }
#line 1435 "asin.c"
    break;

  case 18: /* declaFunc: tipoSimp ID_ PARA_ $@2 paramForm $@3 PARC_ bloque  */
#line 224 "src/asin.y"
               {
      if (strcmp((yyvsp[-6].ident), "main") == 0) {
          if (mainDeclarada) {
              yyerror("La función 'main' ya ha sido declarada");
          } else {
              mainDeclarada = 1;
          }
      }
      descargaContexto(niv);
      niv--;
  }
#line 1451 "asin.c"
    break;

  case 19: /* paramForm: %empty  */
#line 247 "src/asin.y"
              { (yyval.cent) = insTdD(-1, T_VACIO); }
#line 1457 "asin.c"
    break;

  case 20: /* paramForm: listParamForm  */
#line 248 "src/asin.y"
                  { (yyval.cent) = (yyvsp[0].cent); }
#line 1463 "asin.c"
    break;

  case 21: /* listParamForm: tipoSimp ID_  */
#line 256 "src/asin.y"
                 {
      SIMB sim = obtTdS((yyvsp[0].ident));
      if (sim.t != T_ERROR) {
          yyerror("Identificador de parámetro repetido");
      } else {
          int refDom = insTdD(-1, (yyvsp[-1].cent));  // Crear dominio para el primer parámetro
          insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, dvar, -1);
          dvar += TALLA_TIPO_SIMPLE;
          (yyval.cent) = refDom;
      }
  }
#line 1479 "asin.c"
    break;

  case 22: /* listParamForm: tipoSimp ID_ COMA_ listParamForm  */
#line 267 "src/asin.y"
                                     {
      SIMB sim = obtTdS((yyvsp[-2].ident));
      if (sim.t != T_ERROR) {
          yyerror("Identificador de parámetro repetido");
      } else {
          int refDom = insTdD((yyvsp[0].cent), (yyvsp[-3].cent));  // Insertar más parámetros
          insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, dvar, -1);
          dvar += TALLA_TIPO_SIMPLE;
          (yyval.cent) = refDom;
      }
  }
#line 1495 "asin.c"
    break;

  case 23: /* bloque: IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_  */
#line 298 "src/asin.y"
                                                                {

      // Verificar compatibilidad del tipo de retorno

      if (tipoRetornoActual == T_ERROR) {

          yyerror("Error: Declaración incompleta de la función. No se puede validar el tipo de 'return'.");
      
      } else if (tipoRetornoActual != (yyvsp[-2].cent)) {
        
          yyerror("Error: Incompatibilidad de tipos en el 'return'.");
          
      }  else if ((yyvsp[-2].cent) == T_ARRAY) {

          yyerror("No se puede retornar un array directamente.");

      }
  }
#line 1518 "asin.c"
    break;

  case 35: /* instEntSal: READ_ PARA_ ID_ PARC_ PCOMA_  */
#line 395 "src/asin.y"
                                 {

      SIMB sim = obtTdS((yyvsp[-2].ident));

      if (sim.t == T_ERROR) yyerror("Variable no declarada");

      else if (sim.t != T_ENTERO) yyerror("Error: La variable a 'read' tiene que ser de tipo entero");

    }
#line 1532 "asin.c"
    break;

  case 36: /* instEntSal: PRINT_ PARA_ expre PARC_ PCOMA_  */
#line 405 "src/asin.y"
                                    {

      if ((yyvsp[-2].cent) != T_ENTERO) yyerror("Error: La expresión a 'write' tiene que ser de tipo entero");

    }
#line 1542 "asin.c"
    break;

  case 37: /* $@4: %empty  */
#line 417 "src/asin.y"
                          {

      if ((yyvsp[-1].cent) != T_LOGICO) yyerror("Error: La condición a 'if-else' tiene que ser de tipo lógico");

    }
#line 1552 "asin.c"
    break;

  case 39: /* $@5: %empty  */
#line 431 "src/asin.y"
                                                    {

      if ((yyvsp[-4].cent) != T_ERROR && (yyvsp[-4].cent) != T_ENTERO && (yyvsp[-4].cent) != T_LOGICO)

        yyerror("La inicialización del 'for' debe ser de tipo simple");



      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[-2].cent) != T_LOGICO)

        yyerror("Error: La condición del 'for' debe ser de tipo lógico");



      if ((yyvsp[0].cent) != T_ERROR && (yyvsp[0].cent) != T_ENTERO && (yyvsp[0].cent) != T_LOGICO)

        yyerror("La actualización del 'for' debe ser de tipo simple");

    }
#line 1576 "asin.c"
    break;

  case 41: /* expreOP: %empty  */
#line 479 "src/asin.y"
              { (yyval.cent) = T_ERROR; }
#line 1582 "asin.c"
    break;

  case 42: /* expreOP: expre  */
#line 481 "src/asin.y"
              { (yyval.cent) = (yyvsp[0].cent); }
#line 1588 "asin.c"
    break;

  case 43: /* expre: expreLogic  */
#line 489 "src/asin.y"
               { (yyval.cent) = (yyvsp[0].cent); }
#line 1594 "asin.c"
    break;

  case 44: /* expre: ID_ ASIG_ expre  */
#line 491 "src/asin.y"
                    {

      SIMB sim = obtTdS((yyvsp[-2].ident));

      if (sim.t == T_ERROR) yyerror("Variable no declarada");

      else if (sim.t != (yyvsp[0].cent)) yyerror("Error de tipos en la asignación");

      (yyval.cent) = sim.t;

    }
#line 1610 "asin.c"
    break;

  case 45: /* expre: ID_ ACORCH_ expre CCORCH_ ASIG_ expre  */
#line 503 "src/asin.y"
                                          {

      SIMB sim = obtTdS((yyvsp[-5].ident));

      if (sim.t == T_ERROR) yyerror("Array no declarado");

      else if (sim.t != T_ARRAY) yyerror("La variable debe ser de tipo array");

      else if ((yyvsp[-3].cent) != T_ENTERO) yyerror("El índice debe ser entero");

      else if ((yyvsp[0].cent) != T_ENTERO) yyerror("El valor asignado debe ser entero");

      //else if (sim.ref != T_ENTERO) yyerror("La variable debe ser de tipo array");

      (yyval.cent) = T_ENTERO;

    }
#line 1632 "asin.c"
    break;

  case 46: /* expreLogic: expreIgual  */
#line 527 "src/asin.y"
               { (yyval.cent) = (yyvsp[0].cent); }
#line 1638 "asin.c"
    break;

  case 47: /* expreLogic: expreLogic opLogic expreIgual  */
#line 529 "src/asin.y"
                                  {

      if ((yyvsp[-2].cent) != T_LOGICO || (yyvsp[0].cent) != T_LOGICO) yyerror("Operación lógica con tipos no booleanos");

      (yyval.cent) = T_LOGICO;

    }
#line 1650 "asin.c"
    break;

  case 48: /* expreIgual: expreRel  */
#line 543 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1656 "asin.c"
    break;

  case 49: /* expreIgual: expreIgual opIgual expreRel  */
#line 545 "src/asin.y"
                                {

      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {

        if ((yyvsp[-2].cent) != (yyvsp[0].cent)) yyerror("No son del mismo tipo");

        else if ((yyvsp[0].cent) != T_ENTERO && (yyvsp[0].cent) != T_LOGICO) yyerror("Operación de igualdad no entre enteros o lógicos");

      }

      (yyval.cent) = T_LOGICO;

    }
#line 1674 "asin.c"
    break;

  case 50: /* expreRel: expreAd  */
#line 565 "src/asin.y"
            { (yyval.cent) = (yyvsp[0].cent); }
#line 1680 "asin.c"
    break;

  case 51: /* expreRel: expreRel opRel expreAd  */
#line 567 "src/asin.y"
                           {

      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {

        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación relacional no entre enteros");

      }

      (yyval.cent) = T_LOGICO;

    }
#line 1696 "asin.c"
    break;

  case 52: /* expreAd: expreMul  */
#line 585 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1702 "asin.c"
    break;

  case 53: /* expreAd: expreAd opAd expreMul  */
#line 587 "src/asin.y"
                          {

      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {

        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación aritmética no entre enteros");

      }

      (yyval.cent) = T_ENTERO;

    }
#line 1718 "asin.c"
    break;

  case 54: /* expreMul: expreUna  */
#line 605 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1724 "asin.c"
    break;

  case 55: /* expreMul: expreMul opMul expreUna  */
#line 607 "src/asin.y"
                            {

      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {

        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación aritmética no entre enteros");

      }

      (yyval.cent) = T_ENTERO;

    }
#line 1740 "asin.c"
    break;

  case 56: /* expreUna: expreSufi  */
#line 625 "src/asin.y"
              { (yyval.cent) = (yyvsp[0].cent); }
#line 1746 "asin.c"
    break;

  case 57: /* expreUna: opUna expreUna  */
#line 627 "src/asin.y"
                   {

      (yyval.cent) = (yyvsp[0].cent);

    }
#line 1756 "asin.c"
    break;

  case 58: /* expreSufi: const  */
#line 639 "src/asin.y"
          { (yyval.cent) = (yyvsp[0].cent); }
#line 1762 "asin.c"
    break;

  case 59: /* expreSufi: PARA_ expre PARC_  */
#line 641 "src/asin.y"
                      { (yyval.cent) = (yyvsp[-1].cent); }
#line 1768 "asin.c"
    break;

  case 60: /* expreSufi: ID_  */
#line 643 "src/asin.y"
        {

      SIMB sim = obtTdS((yyvsp[0].ident));

      if (sim.t == T_ERROR) yyerror("Variable no declarada");

      (yyval.cent) = sim.t;

    }
#line 1782 "asin.c"
    break;

  case 61: /* expreSufi: ID_ ACORCH_ expre CCORCH_  */
#line 653 "src/asin.y"
                              {

      SIMB sim = obtTdS((yyvsp[-3].ident));

      if (sim.t == T_ERROR) yyerror("Array no declarado");

      else if (sim.t != T_ARRAY) yyerror("Uso inapropiado de una variable no array");

      (yyval.cent) = T_ENTERO;

    }
#line 1798 "asin.c"
    break;

  case 62: /* expreSufi: ID_ PARA_ paramAct PARC_  */
#line 665 "src/asin.y"
                             {

      SIMB sim = obtTdS((yyvsp[-3].ident));

      if (sim.t == T_ERROR) yyerror("Función no declarada");

      else if (sim.t != T_ENTERO && sim.t !=T_LOGICO  ) {yyerror("No es una función");}
      else {
        if (!cmpDom(sim.ref, (yyvsp[-1].cent))) {
            yyerror("Error: Arguments incorrectes a la crida de funció");
          }
      }
     (yyval.cent) = sim.t;
       
    }
#line 1818 "asin.c"
    break;

  case 63: /* paramAct: %empty  */
#line 691 "src/asin.y"
              { (yyval.cent) = insTdD(-1, T_VACIO); }
#line 1824 "asin.c"
    break;

  case 64: /* paramAct: listParamAct  */
#line 692 "src/asin.y"
                 { (yyval.cent) = (yyvsp[0].cent); }
#line 1830 "asin.c"
    break;

  case 65: /* listParamAct: expre  */
#line 696 "src/asin.y"
          { (yyval.cent) = insTdD(-1, (yyvsp[0].cent)); }
#line 1836 "asin.c"
    break;

  case 66: /* listParamAct: expre COMA_ listParamAct  */
#line 697 "src/asin.y"
                             { (yyval.cent) = insTdD((yyvsp[0].cent), (yyvsp[-2].cent)); }
#line 1842 "asin.c"
    break;

  case 67: /* opLogic: LOGICOAND_  */
#line 706 "src/asin.y"
               { (yyval.cent) = OP_AND; }
#line 1848 "asin.c"
    break;

  case 68: /* opLogic: LOGICOOR_  */
#line 708 "src/asin.y"
               { (yyval.cent) = OP_OR; }
#line 1854 "asin.c"
    break;

  case 69: /* opIgual: IGUALDAD_  */
#line 716 "src/asin.y"
              { (yyval.cent) = OP_IGUAL; }
#line 1860 "asin.c"
    break;

  case 70: /* opIgual: DISTINTO_  */
#line 718 "src/asin.y"
              { (yyval.cent) = DISTINTO_; }
#line 1866 "asin.c"
    break;

  case 71: /* opRel: MAYOR_  */
#line 726 "src/asin.y"
              { (yyval.cent) = OP_MAYOR; }
#line 1872 "asin.c"
    break;

  case 72: /* opRel: MENOR_  */
#line 728 "src/asin.y"
              { (yyval.cent) = OP_MENOR; }
#line 1878 "asin.c"
    break;

  case 73: /* opRel: MAYORIGU_  */
#line 730 "src/asin.y"
              { (yyval.cent) = OP_MAYORIG; }
#line 1884 "asin.c"
    break;

  case 74: /* opRel: MENORIGU_  */
#line 732 "src/asin.y"
              { (yyval.cent) = OP_MENORIG; }
#line 1890 "asin.c"
    break;

  case 75: /* opAd: MAS_  */
#line 740 "src/asin.y"
           { (yyval.cent) = OP_SUMA; }
#line 1896 "asin.c"
    break;

  case 76: /* opAd: MENOS_  */
#line 742 "src/asin.y"
           { (yyval.cent) = OP_RESTA; }
#line 1902 "asin.c"
    break;

  case 77: /* opMul: POR_  */
#line 750 "src/asin.y"
         { (yyval.cent) = POR_; }
#line 1908 "asin.c"
    break;

  case 78: /* opMul: DIV_  */
#line 752 "src/asin.y"
         { (yyval.cent) = OP_DIV; }
#line 1914 "asin.c"
    break;

  case 79: /* opUna: MAS_  */
#line 760 "src/asin.y"
           { (yyval.cent) = MAS_; }
#line 1920 "asin.c"
    break;

  case 80: /* opUna: MENOS_  */
#line 762 "src/asin.y"
           { (yyval.cent) = MENOS_; }
#line 1926 "asin.c"
    break;

  case 81: /* opUna: OPNEG_  */
#line 764 "src/asin.y"
           { (yyval.cent) = OPNEG_; }
#line 1932 "asin.c"
    break;


#line 1936 "asin.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 770 "src/asin.y"

