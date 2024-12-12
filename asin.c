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

#line 82 "asin.c"

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
  YYSYMBOL_paramForm = 54,                 /* paramForm  */
  YYSYMBOL_listParamForm = 55,             /* listParamForm  */
  YYSYMBOL_bloque = 56,                    /* bloque  */
  YYSYMBOL_declaVarLocal = 57,             /* declaVarLocal  */
  YYSYMBOL_listInst = 58,                  /* listInst  */
  YYSYMBOL_inst = 59,                      /* inst  */
  YYSYMBOL_instExpre = 60,                 /* instExpre  */
  YYSYMBOL_instEntSal = 61,                /* instEntSal  */
  YYSYMBOL_instSelec = 62,                 /* instSelec  */
  YYSYMBOL_63_2 = 63,                      /* $@2  */
  YYSYMBOL_instIter = 64,                  /* instIter  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_expreOP = 66,                   /* expreOP  */
  YYSYMBOL_expre = 67,                     /* expre  */
  YYSYMBOL_expreLogic = 68,                /* expreLogic  */
  YYSYMBOL_expreIgual = 69,                /* expreIgual  */
  YYSYMBOL_expreRel = 70,                  /* expreRel  */
  YYSYMBOL_expreAd = 71,                   /* expreAd  */
  YYSYMBOL_expreMul = 72,                  /* expreMul  */
  YYSYMBOL_expreUna = 73,                  /* expreUna  */
  YYSYMBOL_expreSufi = 74,                 /* expreSufi  */
  YYSYMBOL_paramAct = 75,                  /* paramAct  */
  YYSYMBOL_listParamAct = 76,              /* listParamAct  */
  YYSYMBOL_opLogic = 77,                   /* opLogic  */
  YYSYMBOL_opIgual = 78,                   /* opIgual  */
  YYSYMBOL_opRel = 79,                     /* opRel  */
  YYSYMBOL_opAd = 80,                      /* opAd  */
  YYSYMBOL_opMul = 81,                     /* opMul  */
  YYSYMBOL_opUna = 82                      /* opUna  */
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
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  140

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
       0,    35,    35,    35,    44,    45,    49,    50,    54,    64,
      81,   105,   106,   107,   111,   112,   118,   170,   171,   177,
     184,   199,   224,   225,   229,   230,   234,   235,   236,   237,
     238,   242,   243,   247,   252,   258,   258,   265,   265,   289,
     290,   294,   295,   301,   313,   314,   321,   322,   332,   333,
     342,   343,   352,   353,   362,   363,   369,   370,   371,   376,
     382,   391,   392,   396,   397,   401,   402,   406,   407,   411,
     412,   413,   414,   418,   419,   423,   424,   428,   429,   430
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
  "decla", "declaVar", "const", "tipoSimp", "declaFunc", "paramForm",
  "listParamForm", "bloque", "declaVarLocal", "listInst", "inst",
  "instExpre", "instEntSal", "instSelec", "$@2", "instIter", "$@3",
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

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -77,    11,   -17,   -77,   -77,   -77,   -17,   -77,   -77,   -41,
     -77,   -77,    26,   -17,   -20,   -29,   -77,   -22,    21,   -77,
     -77,   -77,   -77,     9,    16,    17,    29,   -77,    32,   -17,
     -77,   -77,   -77,   -77,   -17,   -77,    24,    12,   -19,   119,
     -77,   -77,   -77,   119,    71,    73,    74,    75,   -77,   -77,
      -2,   -77,   -77,   -77,   -77,   -77,   -77,    40,    -4,    48,
      36,    22,    65,   -77,   -77,   148,    78,    44,    41,   119,
     119,   119,    64,   119,   119,   119,   -77,   -77,   -77,   148,
     -77,   -77,   148,   -77,   -77,   -77,   -77,   148,   -77,   -77,
     148,   -77,   -77,   148,     3,   -77,   -77,    46,    82,    83,
      84,    55,   -77,   -77,    59,    96,   -77,   -77,    68,    48,
      36,    22,    65,   -77,   119,   -77,    66,    67,   -77,   119,
     119,   -77,    89,    77,   -77,   -77,   106,    76,   -77,   119,
     -77,    72,   119,   -77,   106,   -77,   -77,   112,   106,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    15,    14,     3,     4,     6,     0,
       7,     5,     0,    17,     0,     0,     8,     0,     0,    18,
      12,    13,    11,     0,     0,    19,     0,     9,     0,     0,
      22,    16,    10,    20,    24,    23,     0,     0,     0,     0,
      77,    78,    79,     0,     0,     0,     0,     0,    24,    32,
      58,    56,    25,    27,    28,    29,    30,     0,    41,    44,
      46,    48,    50,    52,    54,     0,     0,     0,     0,     0,
       0,    39,     0,    61,     0,     0,    31,    65,    66,     0,
      67,    68,     0,    71,    72,    69,    70,     0,    73,    74,
       0,    75,    76,     0,    58,    55,    57,     0,     0,     0,
       0,     0,    40,    26,    63,     0,    62,    42,     0,    45,
      47,    49,    51,    53,     0,    21,     0,     0,    35,     0,
       0,    60,    59,     0,    33,    34,     0,     0,    64,     0,
      59,     0,    39,    43,     0,    37,    36,     0,     0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -77,   111,    85,   104,    -8,   -77,   -77,
      91,   -77,   -77,    79,   -76,   -77,   -77,   -77,   -77,   -77,
     -77,   -11,   -39,   -77,    47,    50,    42,    33,   -52,   -77,
     -77,     8,   -77,   -77,   -77,   -77,   -77,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,    51,     9,    10,    18,
      19,    31,    34,    37,    52,    53,    54,    55,   126,    56,
     137,   101,    57,    58,    59,    60,    61,    62,    63,    64,
     105,   106,    79,    82,    87,    90,    93,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,    73,    14,    12,    67,    17,    73,    20,    21,    77,
      78,     3,     4,    95,    24,    39,    15,    40,    41,    74,
      16,    17,    25,    22,     5,    26,    36,    88,    89,    13,
      99,   100,   102,    75,   104,   107,   108,    42,   114,    20,
      21,   113,    43,    44,    45,    46,    47,    14,    27,    48,
     131,    49,    28,    83,    84,    22,    50,    29,   136,    85,
      86,    15,   139,    80,    81,    16,    30,    39,    38,    40,
      41,    32,    91,    92,    68,   123,    69,    70,    71,    76,
     127,   104,    96,    97,   115,    98,   116,   117,   118,    42,
     133,    20,    21,   102,   119,    44,    45,    46,    47,   120,
     121,    48,   103,    49,   122,   124,   125,    22,    50,    39,
     129,    40,    41,   130,   134,   132,   138,    11,    23,    35,
      33,   135,    39,   112,    40,    41,   109,    72,   128,   111,
       0,    42,   110,    20,    21,     0,     0,    44,    45,    46,
      47,     0,     0,    48,    42,    49,    20,    21,     0,    22,
      50,    39,     0,    40,    41,     0,     0,     0,     0,     0,
       0,     0,    22,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,    94
};

static const yytype_int16 yycheck[] =
{
      39,     3,    21,    44,    43,    13,     3,    27,    28,    13,
      14,     0,    29,    65,    43,     3,    35,     5,     6,    21,
      39,    29,    44,    43,    41,     4,    34,     5,     6,     3,
      69,    70,    71,    35,    73,    74,    75,    25,    35,    27,
      28,    93,    30,    31,    32,    33,    34,    21,    39,    37,
     126,    39,    36,    17,    18,    43,    44,    40,   134,    23,
      24,    35,   138,    15,    16,    39,    37,     3,    44,     5,
       6,    39,     7,     8,     3,   114,     3,     3,     3,    39,
     119,   120,     4,    39,    38,    44,     4,     4,     4,    25,
     129,    27,    28,   132,    39,    31,    32,    33,    34,    40,
       4,    37,    38,    39,    36,    39,    39,    43,    44,     3,
      21,     5,     6,    36,    42,    39,     4,     6,    14,    34,
      29,   132,     3,    90,     5,     6,    79,    48,   120,    87,
      -1,    25,    82,    27,    28,    -1,    -1,    31,    32,    33,
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
      53,    49,    44,     3,    21,    35,    39,    52,    54,    55,
      27,    28,    43,    51,    43,    44,     4,    39,    36,    40,
      37,    56,    39,    55,    57,    50,    52,    58,    44,     3,
       5,     6,    25,    30,    31,    32,    33,    34,    37,    39,
      44,    51,    59,    60,    61,    62,    64,    67,    68,    69,
      70,    71,    72,    73,    74,    82,    67,    67,     3,     3,
       3,     3,    58,     3,    21,    35,    39,    13,    14,    77,
      15,    16,    78,    17,    18,    23,    24,    79,     5,     6,
      80,     7,     8,    81,    44,    73,     4,    39,    44,    67,
      67,    66,    67,    38,    67,    75,    76,    67,    67,    69,
      70,    71,    72,    73,    35,    38,     4,     4,     4,    39,
      40,     4,    36,    67,    39,    39,    63,    67,    76,    21,
      36,    59,    39,    67,    42,    66,    59,    65,     4,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    63,    62,    65,    64,    66,
      66,    67,    67,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     1,     1,     1,     6,     0,     1,     2,
       4,     7,     0,     2,     0,     2,     3,     1,     1,     1,
       1,     2,     1,     5,     5,     0,     8,     0,    10,     0,
       1,     1,     3,     6,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     1,     3,     1,     4,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 35 "src/asin.y"
    { dvar=0; niv=0; cargaContexto(niv); }
#line 1257 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 37 "src/asin.y"
    { //if(verTdS) mostrarTdS();
      if(!mainDeclarada){
            yyerror("El programa no tiene una función main ");}
    }
#line 1266 "asin.c"
    break;

  case 4: /* listDecla: decla  */
#line 44 "src/asin.y"
          { (yyval.cent) = (yyvsp[0].cent);}
#line 1272 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 45 "src/asin.y"
                    { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent);}
#line 1278 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ PCOMA_  */
#line 54 "src/asin.y"
                        {

      SIMB sim = obtTdS((yyvsp[-1].ident));
      if (sim.t != T_ERROR) yyerror("Identificador repetido");
      else {
        if (!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1))
          yyerror("Error al insertar la variable en la tabla de símbolos");
        else dvar += TALLA_TIPO_SIMPLE;
      }
    }
#line 1293 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const PCOMA_  */
#line 64 "src/asin.y"
                                    {
      //printf("DEBUG: Entrando en declaVar con tipoSimp='%d', ID_='%s' y const='%d'\n", $1, $2, $4);
      SIMB sim = obtTdS((yyvsp[-3].ident));
      if (sim.t != T_ERROR) yyerror("Identificador repetido");
      else {
         if (! (((yyvsp[-4].cent) == T_ENTERO && (yyvsp[-1].cent) == T_ENTERO) || ((yyvsp[-4].cent) == T_LOGICO && (yyvsp[-1].cent) == T_LOGICO)) ) {
            yyerror("Error: Tipo incompatible entre la variable y la constante asignada");
            if (!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1))
              yyerror("Error al insertar la variable en la tabla de símbolos");
            else dvar += TALLA_TIPO_SIMPLE;
        } else {
            if (!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1)) {
                yyerror("Error al insertar la variable en la Tabla de Símbolos");
            } else {
                dvar += TALLA_TIPO_SIMPLE;  
            }
    }}}
#line 1315 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ ACORCH_ CTE_ CCORCH_ PCOMA_  */
#line 81 "src/asin.y"
                                             {
      int numelem = (yyvsp[-2].cent);
      if (numelem <= 0) {
        yyerror("Talla inapropiada del array");
        numelem = 0;
      }
      SIMB sim = obtTdS((yyvsp[-4].ident));
      if (sim.t != T_ERROR) {
        if (sim.t != T_ARRAY) yyerror("Identificador del array repetido");
        else yyerror("Identificador repetido");

      }


      else {
        int refe = insTdA((yyvsp[-5].cent), numelem);
        if (!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, refe))
          yyerror("Error al insertar el array en la tabla de símbolos");
        else dvar += numelem * TALLA_TIPO_SIMPLE;
      }
    }
#line 1341 "asin.c"
    break;

  case 11: /* const: CTE_  */
#line 105 "src/asin.y"
           { (yyval.cent) = T_ENTERO; }
#line 1347 "asin.c"
    break;

  case 12: /* const: TRUE_  */
#line 106 "src/asin.y"
           { (yyval.cent) = T_LOGICO; }
#line 1353 "asin.c"
    break;

  case 13: /* const: FALSE_  */
#line 107 "src/asin.y"
           { (yyval.cent) = T_LOGICO; }
#line 1359 "asin.c"
    break;

  case 14: /* tipoSimp: INT_  */
#line 111 "src/asin.y"
          { (yyval.cent) = T_ENTERO; }
#line 1365 "asin.c"
    break;

  case 15: /* tipoSimp: BOOL_  */
#line 112 "src/asin.y"
          { (yyval.cent) = T_LOGICO; }
#line 1371 "asin.c"
    break;

  case 16: /* declaFunc: tipoSimp ID_ PARA_ paramForm PARC_ bloque  */
#line 118 "src/asin.y"
                                              {
      tipoRetornoActual = (yyvsp[-5].cent);  // Guarda el tipo de retorno
      niv++;
      cargaContexto(niv);

      if (strcmp((yyvsp[-4].ident), "main") == 0) {
          if (mainDeclarada) {
              yyerror("La función 'main' ya ha sido declarada");
          } else {
              mainDeclarada = 1;
          }
      }

      SIMB sim = obtTdS((yyvsp[-4].ident));
      if (sim.t != T_ERROR) {
          yyerror("La función ya está declarada");
      } else {
          int refDom = insTdD(-1, (yyvsp[-5].cent));
          if (!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), niv, dvar, refDom)) {
              yyerror("Función repetida");
          }
      }

      descargaContexto(niv);
      niv--;
  }
#line 1402 "asin.c"
    break;

  case 19: /* listParamForm: tipoSimp ID_  */
#line 177 "src/asin.y"
                 {
      SIMB sim = obtTdS((yyvsp[0].ident));
      if (sim.t != T_ERROR)
        yyerror("Identificador de parámetro repetido");
      else
        insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, dvar, -1);
    }
#line 1414 "asin.c"
    break;

  case 20: /* listParamForm: tipoSimp ID_ COMA_ listParamForm  */
#line 184 "src/asin.y"
                                     {
      SIMB sim = obtTdS((yyvsp[-2].ident));
      if (sim.t != T_ERROR)
        yyerror("Identificador de parámetro repetido");
      else
        insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, dvar, -1);
    }
#line 1426 "asin.c"
    break;

  case 21: /* bloque: IBLOCK_ declaVarLocal listInst RETURN_ expre PCOMA_ FBLOCK_  */
#line 199 "src/asin.y"
                                                                {
      if (tipoRetornoActual != T_ERROR) {
          if (tipoRetornoActual != (yyvsp[-2].cent)) {
              yyerror("Error de tipos en el 'return'.");
          } else if ((yyvsp[-2].cent) == T_ARRAY) {
              yyerror("No se puede retornar un array directamente.");
          }
      }
  }
#line 1440 "asin.c"
    break;

  case 33: /* instEntSal: READ_ PARA_ ID_ PARC_ PCOMA_  */
#line 247 "src/asin.y"
                                 {
      SIMB sim = obtTdS((yyvsp[-2].ident));
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != T_ENTERO) yyerror("Error: La variable a 'read' tiene que ser de tipo entero");
    }
#line 1450 "asin.c"
    break;

  case 34: /* instEntSal: PRINT_ PARA_ expre PARC_ PCOMA_  */
#line 252 "src/asin.y"
                                    {
      if ((yyvsp[-2].cent) != T_ENTERO) yyerror("Error: La expresión a 'write' tiene que ser de tipo entero");
    }
#line 1458 "asin.c"
    break;

  case 35: /* $@2: %empty  */
#line 258 "src/asin.y"
                          {
      if ((yyvsp[-1].cent) != T_LOGICO) yyerror("Error: La condición a 'if-else' tiene que ser de tipo lógico");
    }
#line 1466 "asin.c"
    break;

  case 37: /* $@3: %empty  */
#line 265 "src/asin.y"
                                                    {
      if ((yyvsp[-4].cent) != T_ERROR && (yyvsp[-4].cent) != T_ENTERO && (yyvsp[-4].cent) != T_LOGICO)
        yyerror("La inicialización del 'for' debe ser de tipo simple");

      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[-2].cent) != T_LOGICO)
        yyerror("Error: La condición del 'for' debe ser de tipo lógico");

      if ((yyvsp[0].cent) != T_ERROR && (yyvsp[0].cent) != T_ENTERO && (yyvsp[0].cent) != T_LOGICO)
        yyerror("La actualización del 'for' debe ser de tipo simple");
    }
#line 1481 "asin.c"
    break;

  case 39: /* expreOP: %empty  */
#line 289 "src/asin.y"
              { (yyval.cent) = T_ERROR; }
#line 1487 "asin.c"
    break;

  case 40: /* expreOP: expre  */
#line 290 "src/asin.y"
              { (yyval.cent) = (yyvsp[0].cent); }
#line 1493 "asin.c"
    break;

  case 41: /* expre: expreLogic  */
#line 294 "src/asin.y"
               { (yyval.cent) = (yyvsp[0].cent); }
#line 1499 "asin.c"
    break;

  case 42: /* expre: ID_ ASIG_ expre  */
#line 295 "src/asin.y"
                    {
      SIMB sim = obtTdS((yyvsp[-2].ident));
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      else if (sim.t != (yyvsp[0].cent)) yyerror("Error de tipos en la asignación");
      (yyval.cent) = sim.t;
    }
#line 1510 "asin.c"
    break;

  case 43: /* expre: ID_ ACORCH_ expre CCORCH_ ASIG_ expre  */
#line 301 "src/asin.y"
                                          {
      SIMB sim = obtTdS((yyvsp[-5].ident));
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("La variable debe ser de tipo array");
      else if ((yyvsp[-3].cent) != T_ENTERO) yyerror("El índice debe ser entero");
      else if ((yyvsp[0].cent) != T_ENTERO) yyerror("El valor asignado debe ser entero");
      //else if (sim.ref != T_ENTERO) yyerror("La variable debe ser de tipo array");
      (yyval.cent) = T_ENTERO;
    }
#line 1524 "asin.c"
    break;

  case 44: /* expreLogic: expreIgual  */
#line 313 "src/asin.y"
               { (yyval.cent) = (yyvsp[0].cent); }
#line 1530 "asin.c"
    break;

  case 45: /* expreLogic: expreLogic opLogic expreIgual  */
#line 314 "src/asin.y"
                                  {
      if ((yyvsp[-2].cent) != T_LOGICO || (yyvsp[0].cent) != T_LOGICO) yyerror("Operación lógica con tipos no booleanos");
      (yyval.cent) = T_LOGICO;
    }
#line 1539 "asin.c"
    break;

  case 46: /* expreIgual: expreRel  */
#line 321 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1545 "asin.c"
    break;

  case 47: /* expreIgual: expreIgual opIgual expreRel  */
#line 322 "src/asin.y"
                                {
      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
        if ((yyvsp[-2].cent) != (yyvsp[0].cent)) yyerror("No son del mismo tipo");
        else if ((yyvsp[0].cent) != T_ENTERO && (yyvsp[0].cent) != T_LOGICO) yyerror("Operación de igualdad no entre enteros o lógicos");
      }
      (yyval.cent) = T_LOGICO;
    }
#line 1557 "asin.c"
    break;

  case 48: /* expreRel: expreAd  */
#line 332 "src/asin.y"
            { (yyval.cent) = (yyvsp[0].cent); }
#line 1563 "asin.c"
    break;

  case 49: /* expreRel: expreRel opRel expreAd  */
#line 333 "src/asin.y"
                           {
      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación relacional no entre enteros");
      }
      (yyval.cent) = T_LOGICO;
    }
#line 1574 "asin.c"
    break;

  case 50: /* expreAd: expreMul  */
#line 342 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1580 "asin.c"
    break;

  case 51: /* expreAd: expreAd opAd expreMul  */
#line 343 "src/asin.y"
                          {
      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación aritmética no entre enteros");
      }
      (yyval.cent) = T_ENTERO;
    }
#line 1591 "asin.c"
    break;

  case 52: /* expreMul: expreUna  */
#line 352 "src/asin.y"
             { (yyval.cent) = (yyvsp[0].cent); }
#line 1597 "asin.c"
    break;

  case 53: /* expreMul: expreMul opMul expreUna  */
#line 353 "src/asin.y"
                            {
      if ((yyvsp[-2].cent) != T_ERROR && (yyvsp[0].cent) != T_ERROR) {
        if ((yyvsp[-2].cent) != T_ENTERO || (yyvsp[0].cent) != T_ENTERO) yyerror("Operación aritmética no entre enteros");
      }
      (yyval.cent) = T_ENTERO;
    }
#line 1608 "asin.c"
    break;

  case 54: /* expreUna: expreSufi  */
#line 362 "src/asin.y"
              { (yyval.cent) = (yyvsp[0].cent); }
#line 1614 "asin.c"
    break;

  case 55: /* expreUna: opUna expreUna  */
#line 363 "src/asin.y"
                   {
      (yyval.cent) = (yyvsp[0].cent);
    }
#line 1622 "asin.c"
    break;

  case 56: /* expreSufi: const  */
#line 369 "src/asin.y"
          { (yyval.cent) = (yyvsp[0].cent); }
#line 1628 "asin.c"
    break;

  case 57: /* expreSufi: PARA_ expre PARC_  */
#line 370 "src/asin.y"
                      { (yyval.cent) = (yyvsp[-1].cent); }
#line 1634 "asin.c"
    break;

  case 58: /* expreSufi: ID_  */
#line 371 "src/asin.y"
        {
      SIMB sim = obtTdS((yyvsp[0].ident));
      if (sim.t == T_ERROR) yyerror("Variable no declarada");
      (yyval.cent) = sim.t;
    }
#line 1644 "asin.c"
    break;

  case 59: /* expreSufi: ID_ ACORCH_ expre CCORCH_  */
#line 376 "src/asin.y"
                              {
      SIMB sim = obtTdS((yyvsp[-3].ident));
      if (sim.t == T_ERROR) yyerror("Array no declarado");
      else if (sim.t != T_ARRAY) yyerror("Uso inapropiado de una variable no array");
      (yyval.cent) = T_ENTERO;
    }
#line 1655 "asin.c"
    break;

  case 60: /* expreSufi: ID_ PARA_ paramAct PARC_  */
#line 382 "src/asin.y"
                             {
      SIMB sim = obtTdS((yyvsp[-3].ident));
      if (sim.t == T_ERROR) yyerror("Función no declarada");
      else if (sim.t != FUNCION) yyerror("No es una función");
      (yyval.cent) = T_ENTERO;
    }
#line 1666 "asin.c"
    break;

  case 61: /* paramAct: %empty  */
#line 391 "src/asin.y"
              { (yyval.cent) = T_ERROR; }
#line 1672 "asin.c"
    break;

  case 63: /* listParamAct: expre  */
#line 396 "src/asin.y"
          { (yyval.cent) = (yyvsp[0].cent); }
#line 1678 "asin.c"
    break;

  case 64: /* listParamAct: expre COMA_ listParamAct  */
#line 397 "src/asin.y"
                             { (yyval.cent) = (yyvsp[-2].cent); }
#line 1684 "asin.c"
    break;

  case 65: /* opLogic: LOGICOAND_  */
#line 401 "src/asin.y"
               { (yyval.cent) = OP_AND; }
#line 1690 "asin.c"
    break;

  case 66: /* opLogic: LOGICOOR_  */
#line 402 "src/asin.y"
               { (yyval.cent) = OP_OR; }
#line 1696 "asin.c"
    break;

  case 67: /* opIgual: IGUALDAD_  */
#line 406 "src/asin.y"
              { (yyval.cent) = OP_IGUAL; }
#line 1702 "asin.c"
    break;

  case 68: /* opIgual: DISTINTO_  */
#line 407 "src/asin.y"
              { (yyval.cent) = DISTINTO_; }
#line 1708 "asin.c"
    break;

  case 69: /* opRel: MAYOR_  */
#line 411 "src/asin.y"
              { (yyval.cent) = OP_MAYOR; }
#line 1714 "asin.c"
    break;

  case 70: /* opRel: MENOR_  */
#line 412 "src/asin.y"
              { (yyval.cent) = OP_MENOR; }
#line 1720 "asin.c"
    break;

  case 71: /* opRel: MAYORIGU_  */
#line 413 "src/asin.y"
              { (yyval.cent) = OP_MAYORIG; }
#line 1726 "asin.c"
    break;

  case 72: /* opRel: MENORIGU_  */
#line 414 "src/asin.y"
              { (yyval.cent) = OP_MENORIG; }
#line 1732 "asin.c"
    break;

  case 73: /* opAd: MAS_  */
#line 418 "src/asin.y"
           { (yyval.cent) = OP_SUMA; }
#line 1738 "asin.c"
    break;

  case 74: /* opAd: MENOS_  */
#line 419 "src/asin.y"
           { (yyval.cent) = OP_RESTA; }
#line 1744 "asin.c"
    break;

  case 75: /* opMul: POR_  */
#line 423 "src/asin.y"
         { (yyval.cent) = POR_; }
#line 1750 "asin.c"
    break;

  case 76: /* opMul: DIV_  */
#line 424 "src/asin.y"
         { (yyval.cent) = OP_DIV; }
#line 1756 "asin.c"
    break;

  case 77: /* opUna: MAS_  */
#line 428 "src/asin.y"
           { (yyval.cent) = MAS_; }
#line 1762 "asin.c"
    break;

  case 78: /* opUna: MENOS_  */
#line 429 "src/asin.y"
           { (yyval.cent) = MENOS_; }
#line 1768 "asin.c"
    break;

  case 79: /* opUna: OPNEG_  */
#line 430 "src/asin.y"
           { (yyval.cent) = OPNEG_; }
#line 1774 "asin.c"
    break;


#line 1778 "asin.c"

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

#line 433 "src/asin.y"

