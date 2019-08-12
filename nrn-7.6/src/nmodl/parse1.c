/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:339  */

/* /local/src/master/nrn/src/nmodl/parse1.y,v 4.11 1999/03/24 18:34:08 hines Exp */

#include <../../nmodlconf.h>
#include "modl.h"
#include <stdlib.h>

#if defined(__STDC__)
#define sdebug(arg1,arg2) {}
#define qdebug(arg1,arg2) {}
#else
#define sdebug(arg1,arg2) {Fprintf(stderr,"arg1:%s\n", arg2); Fflush(stderr);}
#define qdebug(arg1,arg2) {Item *q; Fprintf(stderr,"arg1:");Fflush(stderr);\
	for (q=arg2; q->type != 0; q=q->next){\
		if (q->type == SYMBOL)\
			Fprintf(stderr,"%s\n", SYM(q)->name);\
		else if (q->type == STRING)\
			Fprintf(stderr,"%s\n", STR(q);\
		else\
			Fprintf(stderr,"Illegal Item type\n");\
		Fflush(stderr);}\
		Fprintf(stderr,"\n");Fflush(stderr);}
#endif

#define ldebug(arg1, arg2) qdebug(arg1, arg2->next)

extern int yylex(), yyparse();
static void yyerror();

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++))yyerror(arg); --yyps; --yypv; YYERROR
#endif

int brkpnt_exists;
int assert_threadsafe;
int usederivstatearray;
extern int protect_;
extern int vectorize;
extern int in_comment_; /* allow non-ascii in a COMMENT */
extern char *modelline;
extern Item* protect_astmt(Item*, Item*);
extern List* toplocal_;
static List* toplocal1_;
extern List *firstlist; /* NAME symbols in order that they appear in file */
extern int lexcontext; /* ':' can return 3 different tokens */
extern List *solveforlist; /* List of symbols that are actually to be solved
				for in a block. See in_solvefor() */
static int stateblock; /* 0 if dependent, 1 if state */
static int blocktype;
static int saw_verbatim_; /* only print the notice once */
static int inequation; /* inside an equation?*/
static int nstate;	/* number of states seen in an expression */
static int leftside;	/* inside left hand side of equation? */
static int pstate;	/* number of state in a primary expression */
static int tstate;	/* number of states in a term */
static Item *lastok;	/* last token accepted by expr */
static int sensused;	/* a SENS statement occurred in this block */
static Symbol *matchindex; /* local symbol for implied MATCH loop */
static int model_level = 0; /* the model level prepended to declaration
				blocks by merge */
static int scopindep = 0;/* SCoP independent explicitly declared if 1 */
static int extdef2 = 0; /* flag that says we are in an EXTDEF2 function */
static List *table_list = LIST0; /* table information for TABLE statement */
static int forallindex = 0;	/* 0 not in FORALL, -1 just starting, 
					>0 index of arrays used (must all
					be the same */
static Item* astmt_end_;	/* see kinetic.c vectorizing */
static int nr_argcnt_, argcnt_; /* for matching number of args in NET_RECEIVE
				 and FOR_NETCONS */

#line 141 "parse1.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_PARSE_H_INCLUDED
# define YY_YY_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VERBATIM = 258,
    COMMENT = 259,
    MODEL = 260,
    CONSTANT = 261,
    INDEPENDENT = 262,
    DEPENDENT = 263,
    STATE = 264,
    INITIAL1 = 265,
    DERIVATIVE = 266,
    SOLVE = 267,
    USING = 268,
    WITH = 269,
    STEPPED = 270,
    DISCRETE = 271,
    FROM = 272,
    FORALL1 = 273,
    TO = 274,
    BY = 275,
    WHILE = 276,
    IF = 277,
    ELSE = 278,
    START1 = 279,
    STEP = 280,
    SENS = 281,
    SOLVEFOR = 282,
    PROCEDURE = 283,
    PARTIAL = 284,
    DEL = 285,
    DEL2 = 286,
    DEFINE1 = 287,
    IFERROR = 288,
    PARAMETER = 289,
    DERFUNC = 290,
    EQUATION = 291,
    TERMINAL = 292,
    LINEAR = 293,
    NONLINEAR = 294,
    FUNCTION1 = 295,
    LOCAL = 296,
    METHOD = 297,
    LIN1 = 298,
    NONLIN1 = 299,
    PUTQ = 300,
    GETQ = 301,
    TABLE = 302,
    DEPEND = 303,
    BREAKPOINT = 304,
    INCLUDE1 = 305,
    FUNCTION_TABLE = 306,
    PROTECT = 307,
    NRNMUTEXLOCK = 308,
    NRNMUTEXUNLOCK = 309,
    OR = 310,
    AND = 311,
    GT = 312,
    LT = 313,
    LE = 314,
    EQ = 315,
    NE = 316,
    NOT = 317,
    NAME = 318,
    PRIME = 319,
    REAL = 320,
    INTEGER = 321,
    DEFINEDVAR = 322,
    STRING = 323,
    PLOT = 324,
    VS = 325,
    LAG = 326,
    RESET = 327,
    MATCH = 328,
    MODEL_LEVEL = 329,
    SWEEP = 330,
    FIRST = 331,
    LAST = 332,
    KINETIC = 333,
    CONSERVE = 334,
    REACTION = 335,
    REACT1 = 336,
    COMPARTMENT = 337,
    UNITS = 338,
    UNITSON = 339,
    UNITSOFF = 340,
    LONGDIFUS = 341,
    NEURON = 342,
    SUFFIX = 343,
    NONSPECIFIC = 344,
    READ = 345,
    WRITE = 346,
    USEION = 347,
    VALENCE = 348,
    THREADSAFE = 349,
    GLOBAL = 350,
    SECTION = 351,
    RANGE = 352,
    POINTER = 353,
    BBCOREPOINTER = 354,
    EXTERNAL = 355,
    BEFORE = 356,
    AFTER = 357,
    WATCH = 358,
    ELECTRODE_CURRENT = 359,
    CONSTRUCTOR = 360,
    DESTRUCTOR = 361,
    NETRECEIVE = 362,
    FOR_NETCONS = 363,
    CONDUCTANCE = 364,
    GE = 365,
    UNARYMINUS = 366
  };
#endif
/* Tokens.  */
#define VERBATIM 258
#define COMMENT 259
#define MODEL 260
#define CONSTANT 261
#define INDEPENDENT 262
#define DEPENDENT 263
#define STATE 264
#define INITIAL1 265
#define DERIVATIVE 266
#define SOLVE 267
#define USING 268
#define WITH 269
#define STEPPED 270
#define DISCRETE 271
#define FROM 272
#define FORALL1 273
#define TO 274
#define BY 275
#define WHILE 276
#define IF 277
#define ELSE 278
#define START1 279
#define STEP 280
#define SENS 281
#define SOLVEFOR 282
#define PROCEDURE 283
#define PARTIAL 284
#define DEL 285
#define DEL2 286
#define DEFINE1 287
#define IFERROR 288
#define PARAMETER 289
#define DERFUNC 290
#define EQUATION 291
#define TERMINAL 292
#define LINEAR 293
#define NONLINEAR 294
#define FUNCTION1 295
#define LOCAL 296
#define METHOD 297
#define LIN1 298
#define NONLIN1 299
#define PUTQ 300
#define GETQ 301
#define TABLE 302
#define DEPEND 303
#define BREAKPOINT 304
#define INCLUDE1 305
#define FUNCTION_TABLE 306
#define PROTECT 307
#define NRNMUTEXLOCK 308
#define NRNMUTEXUNLOCK 309
#define OR 310
#define AND 311
#define GT 312
#define LT 313
#define LE 314
#define EQ 315
#define NE 316
#define NOT 317
#define NAME 318
#define PRIME 319
#define REAL 320
#define INTEGER 321
#define DEFINEDVAR 322
#define STRING 323
#define PLOT 324
#define VS 325
#define LAG 326
#define RESET 327
#define MATCH 328
#define MODEL_LEVEL 329
#define SWEEP 330
#define FIRST 331
#define LAST 332
#define KINETIC 333
#define CONSERVE 334
#define REACTION 335
#define REACT1 336
#define COMPARTMENT 337
#define UNITS 338
#define UNITSON 339
#define UNITSOFF 340
#define LONGDIFUS 341
#define NEURON 342
#define SUFFIX 343
#define NONSPECIFIC 344
#define READ 345
#define WRITE 346
#define USEION 347
#define VALENCE 348
#define THREADSAFE 349
#define GLOBAL 350
#define SECTION 351
#define RANGE 352
#define POINTER 353
#define BBCOREPOINTER 354
#define EXTERNAL 355
#define BEFORE 356
#define AFTER 357
#define WATCH 358
#define ELECTRODE_CURRENT 359
#define CONSTRUCTOR 360
#define DESTRUCTOR 361
#define NETRECEIVE 362
#define FOR_NETCONS 363
#define CONDUCTANCE 364
#define GE 365
#define UNARYMINUS 366

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 76 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:355  */

	Item	*qp;
	char	*str;
	List	*lp;
	int	i;

#line 410 "parse1.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 427 "parse1.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  129
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  166
/* YYNRULES -- Number of rules.  */
#define YYNRULES  392
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  769

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   366

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   127,     2,     2,
      57,    58,    63,    62,    69,    64,     2,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,     2,
       2,    66,     2,     2,    61,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,    70,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   128
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   136,   137,   138,   151,   152,   153,
     153,   156,   155,   161,   170,   177,   178,   181,   185,   187,
     196,   198,   204,   204,   204,   204,   204,   205,   205,   205,
     205,   207,   209,   210,   214,   218,   220,   225,   227,   228,
     230,   230,   234,   235,   238,   239,   245,   247,   248,   251,
     255,   256,   258,   259,   261,   262,   269,   269,   271,   272,
     274,   275,   281,   283,   284,   286,   286,   291,   296,   298,
     300,   300,   302,   303,   306,   310,   316,   320,   326,   330,
     331,   334,   335,   340,   340,   342,   347,   349,   357,   361,
     362,   365,   365,   367,   367,   368,   368,   369,   369,   370,
     370,   371,   371,   372,   372,   373,   373,   374,   374,   375,
     375,   376,   376,   377,   377,   378,   378,   379,   379,   380,
     380,   381,   381,   382,   382,   384,   387,   390,   393,   393,
     394,   397,   399,   403,   402,   412,   414,   429,   444,   445,
     448,   449,   449,   451,   453,   454,   455,   456,   457,   458,
     459,   460,   470,   472,   473,   474,   475,   476,   477,   478,
     480,   481,   482,   486,   487,   488,   489,   490,   491,   492,
     495,   498,   498,   502,   502,   505,   509,   533,   542,   549,
     564,   587,   590,   594,   602,   603,   604,   605,   606,   607,
     608,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   633,   635,   640,   642,   645,   648,   651,   655,   661,
     667,   673,   674,   675,   677,   680,   685,   684,   702,   703,
     704,   705,   706,   708,   708,   731,   734,   735,   737,   737,
     756,   759,   761,   763,   764,   771,   772,   779,   783,   783,
     789,   795,   799,   804,   808,   810,   812,   815,   815,   817,
     845,   844,   873,   874,   874,   876,   880,   885,   904,   903,
     921,   923,   931,   934,   936,   939,   940,   944,   948,   950,
     954,   956,   958,   962,   965,   967,   969,   971,   973,   975,
     977,   979,   981,   984,   985,   987,   987,   997,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1010,  1011,  1014,
    1019,  1021,  1024,  1028,  1028,  1032,  1035,  1034,  1038,  1042,
    1041,  1045,  1048,  1049,  1051,  1058,  1058,  1060,  1062,  1064,
    1066,  1067,  1068,  1069,  1071,  1073,  1075,  1076,  1078,  1078,
    1081,  1082,  1084,  1086,  1093,  1097,  1099,  1104,  1108,  1109,
    1110,  1112,  1114,  1116,  1122,  1136,  1145,  1151,  1153,  1154,
    1161,  1176,  1179,  1180,  1182,  1184,  1188,  1189,  1192,  1195,
    1196,  1198,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,
    1215,  1218,  1220,  1222,  1224,  1227,  1228,  1230,  1234,  1235,
    1238,  1239,  1241
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VERBATIM", "COMMENT", "MODEL",
  "CONSTANT", "INDEPENDENT", "DEPENDENT", "STATE", "INITIAL1",
  "DERIVATIVE", "SOLVE", "USING", "WITH", "STEPPED", "DISCRETE", "FROM",
  "FORALL1", "TO", "BY", "WHILE", "IF", "ELSE", "START1", "STEP", "SENS",
  "SOLVEFOR", "PROCEDURE", "PARTIAL", "DEL", "DEL2", "DEFINE1", "IFERROR",
  "PARAMETER", "DERFUNC", "EQUATION", "TERMINAL", "LINEAR", "NONLINEAR",
  "FUNCTION1", "LOCAL", "METHOD", "LIN1", "NONLIN1", "PUTQ", "GETQ",
  "TABLE", "DEPEND", "BREAKPOINT", "INCLUDE1", "FUNCTION_TABLE", "PROTECT",
  "NRNMUTEXLOCK", "NRNMUTEXUNLOCK", "'{'", "'}'", "'('", "')'", "'['",
  "']'", "'@'", "'+'", "'*'", "'-'", "'/'", "'='", "'^'", "':'", "','",
  "'~'", "OR", "AND", "GT", "LT", "LE", "EQ", "NE", "NOT", "NAME", "PRIME",
  "REAL", "INTEGER", "DEFINEDVAR", "STRING", "PLOT", "VS", "LAG", "RESET",
  "MATCH", "MODEL_LEVEL", "SWEEP", "FIRST", "LAST", "KINETIC", "CONSERVE",
  "REACTION", "REACT1", "COMPARTMENT", "UNITS", "UNITSON", "UNITSOFF",
  "LONGDIFUS", "NEURON", "SUFFIX", "NONSPECIFIC", "READ", "WRITE",
  "USEION", "VALENCE", "THREADSAFE", "GLOBAL", "SECTION", "RANGE",
  "POINTER", "BBCOREPOINTER", "EXTERNAL", "BEFORE", "AFTER", "WATCH",
  "ELECTRODE_CURRENT", "CONSTRUCTOR", "DESTRUCTOR", "NETRECEIVE",
  "FOR_NETCONS", "CONDUCTANCE", "GE", "'%'", "UNARYMINUS", "$accept",
  "top", "all", "$@1", "$@2", "model", "line", "define1", "Name",
  "declare", "parmblk", "parmbody", "parmasgn", "units", "unit", "@3",
  "uniton", "limits", "stepblk", "stepbdy", "stepped", "numlist", "name",
  "number", "NUMBER", "integer", "real", "indepblk", "indepbody", "$@4",
  "indepdef", "withby", "depblk", "$@5", "depbody", "depdef", "opstart",
  "abstol", "stateblk", "$@6", "plotdecl", "pvlist", "optindex", "proc",
  "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "initblk", "constructblk", "destructblk", "stmtlist", "$@24",
  "conducthint", "locallist", "$@25", "locallist1", "locoptarray",
  "stmtlist1", "$@26", "ostmt", "astmt", "$@27", "$@28", "asgn", "varname",
  "intexpr", "expr", "nonlineqn", "lineqn", "leftlinexpr", "linexpr",
  "primary", "term", "funccall", "$@29", "exprlist", "fromstmt", "$@30",
  "opinc", "forallstmt", "$@31", "whilestmt", "ifstmt", "optelseif",
  "optelse", "derivblk", "linblk", "$@32", "nonlinblk", "discretblk",
  "partialblk", "pareqn", "firstlast", "functableblk", "funcblk", "$@33",
  "arglist", "$@34", "arglist1", "procedblk", "netrecblk", "$@35",
  "initstmt", "solveblk", "ifsolerr", "solvefor", "solvefor1", "brkptblk",
  "terminalblk", "bablk", "watchstmt", "watch1", "watchdir", "fornetcon",
  "$@36", "aexpr", "sens", "senslist", "conserve", "$@37", "compart",
  "$@38", "ldifus", "$@39", "namelist", "kineticblk", "reaction", "$@40",
  "react", "lagstmt", "queuestmt", "matchblk", "$@41", "matchlist",
  "match", "matchname", "unitblk", "unitbody", "unitdef", "factordef",
  "constblk", "conststmt", "tablestmt", "tablst", "tablst1", "dependlst",
  "neuronblk", "nrnstmt", "nrnuse", "nrnlist", "optnrnlist", "valence", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   123,   125,    40,    41,    91,
      93,    64,    43,    42,    45,    47,    61,    94,    58,    44,
     126,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,    37,   366
};
# endif

#define YYPACT_NINF -553

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-553)))

#define YYTABLE_NINF -389

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     770,  -553,   134,   827,  -553,  -553,  -553,  -553,   -26,   -23,
    -553,  -553,    85,    82,   129,    93,   106,   157,   126,   287,
    -553,  -553,   305,   443,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,   309,   331,  -553,  -553,   210,  -553,  -553,   176,  -553,
    -553,  -553,  -553,  -553,   346,   137,  -553,  -553,  -553,  -553,
     407,   415,   391,   446,   464,   488,   510,   417,   513,   538,
     527,   465,   450,   453,   521,   459,   470,   -28,    29,  -553,
    -553,    -3,  -553,    65,   508,   533,   541,  -553,   239,   239,
     241,   237,  1170,   535,  -553,   546,  -553,   535,  -553,   553,
    -553,   556,  -553,   557,  -553,   559,  -553,    12,  -553,   535,
    -553,   560,  -553,   145,  -553,   569,  -553,   535,  -553,   535,
    -553,   579,  -553,   185,   185,  -553,   584,  -553,  -553,   650,
    -553,  -553,    99,   101,  -553,   602,  -553,  -553,  -553,   411,
    -553,   347,  -553,   595,   628,   346,   346,  -553,  -553,  -553,
    -553,   624,    48,  -553,  -553,  -553,   612,   149,   195,   431,
     149,   149,   149,   149,   149,   149,   149,  -553,   654,   641,
     535,   642,   673,   673,   662,   672,  -553,   663,   674,   535,
    -553,   535,   673,   675,   677,   678,  -553,   535,   535,   535,
     535,  -553,  -553,   414,   414,   200,  -553,  -553,   445,  -553,
    -553,   414,   347,   414,   668,  -553,  -553,  -553,   676,   508,
    -553,  -553,  -553,   680,   496,  -553,   690,  -553,  -553,  -553,
     693,  -553,   113,   693,  -553,   693,   693,   693,   693,   693,
     693,   693,  -553,  -553,  -553,   705,  -553,   226,  -553,   703,
     535,   663,   663,   724,   239,  -553,   727,   728,   535,  -553,
    -553,   663,   732,   734,   739,   741,   571,  -553,   690,  -553,
    -553,   781,  -553,   414,   414,   347,   690,   -10,   744,   743,
     690,   581,  -553,  -553,  -553,  -553,  -553,   400,  -553,   690,
    -553,   722,   149,   149,   603,   664,  -553,  -553,  -553,   535,
     736,   760,   759,   764,  -553,   690,   754,  -553,  -553,   769,
     768,  -553,  -553,  -553,  -553,  -553,  -553,   414,   809,  -553,
     777,   765,   414,  -553,   414,   690,   668,   771,   772,  -553,
    -553,  -553,   -61,   130,  -553,  -553,  -553,     4,   779,   639,
    -553,   745,  -553,   778,   342,   232,  -553,   787,  -553,  -553,
     690,   690,   535,  -553,   239,  -553,   690,   832,   414,   462,
     581,  -553,  -553,  -553,   668,  -553,   581,   690,   149,   426,
    -553,  -553,   322,  -553,   347,    66,  -553,  -553,  -553,   535,
     230,   262,   290,   790,   791,   182,   239,   239,   280,  -553,
    -553,    -9,   197,  -553,  -553,    33,   623,   632,    30,    32,
     774,  -553,   794,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,   782,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,    87,  -553,   342,  -553,   342,   342,   342,   690,
    -553,  1130,  -553,  -553,   342,   161,  -553,  -553,   788,   321,
     291,  -553,  -553,  -553,  -553,   535,   800,   690,  -553,  -553,
     347,   833,   414,   690,   785,  -553,   792,  -553,   130,   581,
    -553,   802,  -553,   516,   807,  -553,    66,  -553,  -553,   543,
     811,  -553,    47,  -553,  -553,  -553,  -553,   342,   342,  -553,
    -553,   803,  -553,  -553,  -553,  -553,   826,   806,   797,   819,
     813,  -553,   860,   828,  -553,   359,   278,   834,   292,   869,
    -553,   354,  -553,  -553,   663,   773,  -553,   825,  -553,   396,
    -553,   460,  1166,   935,   817,   817,  -553,   342,   342,   342,
     342,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   957,   291,   232,   161,   161,   161,   161,   535,   829,
    -553,  -553,   833,   690,   867,   765,  -553,  -553,  -553,  -553,
    -553,  1166,    83,    66,   660,  -553,    66,    66,    66,    66,
    -553,   848,   535,  -553,   836,   535,   980,  1000,   396,   774,
     877,   774,   841,   413,   816,   824,   220,   192,  -553,   835,
    -553,   835,  -553,   354,   354,   690,  -553,  -553,   519,   846,
     837,  -553,  -553,   359,   840,   844,  -553,  -553,   458,   817,
     458,   817,  1166,   817,  1185,   692,   614,   614,   614,   614,
     614,   614,  -553,   321,   291,   291,  -553,  -553,   859,  -553,
     690,   765,   414,  -553,  -553,   294,   688,  -553,   402,  -553,
     402,  -553,   886,   864,    66,   865,   535,   535,  -553,   806,
     342,  -553,   413,  -553,  -553,   862,   866,  -553,  -553,   434,
     173,  -553,   868,   342,   342,  -553,     2,   342,   248,   608,
     856,  -553,   354,   354,   354,   354,   354,  -553,  -553,   354,
    -553,  -553,   396,  -553,   878,   880,   359,  -553,  -553,  -553,
     833,  -553,  1166,  -553,  -553,  -553,   333,  -553,   882,   883,
     317,   888,   884,   918,   872,  -553,  -553,   342,  1166,   892,
    -553,  -553,   915,  -553,  -553,   524,   856,   524,   856,   856,
     729,   535,  -553,   342,   342,   245,   690,    66,  -553,  -553,
     342,   887,   342,   895,   898,  1022,   835,   835,   581,   905,
    1045,  1065,   342,   765,   383,   939,   140,   342,  1166,   893,
    -553,   907,   250,   252,  -553,  -553,  -553,  -553,  1147,  -553,
      66,   535,    -5,  -553,   889,  1166,   916,   342,  -553,  -553,
     342,   449,   919,   924,   920,  -553,   921,  1166,  1087,  -553,
     342,  -553,   906,  -553,  1110,  -553,   535,   928,  -553
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     3,     0,    11,     1,    13,    14,    18,     0,     0,
      70,    83,     0,     0,     0,     0,     0,     0,     0,     0,
      42,    43,     0,    91,     5,     7,     8,    22,    15,    26,
      23,    24,    25,    27,     6,    29,    30,    28,    17,   358,
      63,     0,     0,    47,    20,     0,    32,   135,     0,    16,
      86,    21,    53,    52,    89,     0,     9,   348,   369,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      72,     0,    19,     0,   138,   134,     0,    87,     0,     0,
       0,     0,     0,     0,    92,     0,    94,     0,    96,     0,
      98,     0,   100,     0,   102,     0,   104,     0,   106,     0,
     108,     0,   110,     0,   112,     0,   114,     0,   116,     0,
     118,     0,   120,     0,     0,   357,     0,    68,    62,     0,
      65,    64,     0,     0,    46,     0,    48,    37,    31,    38,
      33,     0,   136,     0,     0,    89,    89,    10,   356,   347,
      40,     0,     0,   349,   350,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,   128,     0,
       0,     0,   277,   277,     0,     0,   270,   263,     0,     0,
     253,     0,   277,     0,     0,     0,   288,     0,     0,     0,
       0,   122,   124,     0,     0,     0,    78,    71,    79,    73,
      84,     0,     0,     0,    44,    39,    58,    59,     0,   138,
      90,    88,    85,     0,     0,   352,     0,   370,   387,   385,
     372,   384,     0,   389,   380,   376,   374,   375,   377,   378,
     379,   373,   140,   140,   125,     0,   282,     0,   248,   278,
       0,   263,   263,     0,     0,   283,     0,     0,     0,   126,
     127,   263,     0,     0,     0,     0,     0,    57,    38,    54,
      56,     0,    66,     0,     0,     0,    38,    38,     0,     0,
      38,     0,    35,   139,   137,    41,    60,     0,    61,     0,
     351,     0,     0,     0,   141,   141,   247,   281,   279,     0,
       0,     0,     0,     0,   268,    38,   264,   251,   252,     0,
       0,   286,   285,   287,   284,    55,   359,     0,     0,    80,
       0,    81,     0,    49,     0,    38,    44,     0,     0,   354,
     353,   386,   390,   390,   212,   211,   171,    21,   179,     0,
     143,     0,   170,     0,     0,     0,   175,     0,   280,   250,
      38,    38,     0,   265,     0,   324,    38,     0,     0,    79,
       0,    74,    51,    50,    44,    34,     0,     0,     0,     0,
     381,   382,     0,   226,     0,     0,   169,   151,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167,
     168,     0,     0,   159,   338,     0,     0,     0,     0,     0,
       0,   163,     0,   150,   142,   144,   145,   146,   147,   161,
     164,   149,   165,   166,   153,   156,   154,   155,   157,   158,
     160,   162,     0,   174,     0,   210,     0,     0,     0,    38,
     191,     0,   193,   225,     0,     0,   222,   221,     0,   213,
     214,   218,   223,   249,   260,     0,     0,    38,   259,    69,
       0,    79,     0,    38,     0,    36,     0,   355,   390,     0,
     391,    21,   172,     0,   181,   190,     0,   183,   184,     0,
       0,   274,   275,   235,   233,   240,   238,     0,     0,   310,
     311,   309,   336,   337,   361,   364,   366,   363,     0,     0,
       0,   335,     0,     0,   315,     0,    21,     0,    21,     0,
     291,     0,   289,   297,   263,   131,   148,     0,   329,     0,
     330,     0,   176,     0,   209,   208,   192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
     269,   266,    79,    38,     0,    81,    82,    45,   383,   392,
     230,   229,     0,     0,     0,   180,     0,     0,     0,     0,
     271,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   316,     0,
     319,     0,   308,     0,     0,    38,   298,   300,     0,     0,
       0,   290,   331,     0,     0,     0,   325,   194,   195,   197,
     196,   198,   177,   199,   200,   201,   202,   203,   205,   206,
     207,   204,   224,   178,   216,   217,   219,   220,     0,   267,
      38,    81,     0,    75,   227,     0,     0,   185,   186,   188,
     187,   189,   275,     0,     0,     0,     0,     0,   312,   367,
       0,   365,     0,   257,   258,     0,     0,   334,   344,   342,
       0,   340,     0,     0,     0,   322,     0,     0,     0,     0,
     307,   299,     0,     0,     0,     0,     0,   293,   294,     0,
     295,   132,     0,   332,     0,     0,     0,   261,    67,    76,
      79,   232,   231,   182,   273,   276,     0,   239,     0,     0,
       0,     0,     0,     0,     0,   339,   341,     0,   314,     0,
     318,   323,     0,   321,   301,   302,   304,   303,   305,   306,
       0,     0,   333,     0,     0,     0,    38,     0,   241,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,   236,   245,     0,     0,   256,     0,
     346,     0,     0,     0,   292,   296,   328,   327,     0,    77,
       0,     0,     0,   242,     0,   255,     0,     0,   317,   320,
       0,   237,     0,     0,     0,   360,     0,   343,     0,   234,
       0,   246,     0,   326,     0,   254,     0,     0,   244
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -279,   904,
    -553,  -553,  -553,  -243,   -86,  -553,   667,  -183,  -553,  -553,
    -553,  -553,   -14,  -185,   747,  -139,  -203,  -553,  -553,  -553,
     810,  -553,  -553,  -553,   933,  -553,  -345,  -534,  -553,  -553,
    -553,  -553,   386,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,  -553,   -97,  -553,  -553,   849,  -553,  -553,
     795,   783,  -553,  -553,  -553,  -553,  -553,   652,   -25,  -442,
     102,  -553,  -553,  -553,   478,  -415,    36,  -240,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,   393,  -553,  -553,  -553,
    -216,  -553,  -553,  -553,  -553,  -553,  -553,  -553,   401,   175,
    -553,  -553,  -553,   902,  -553,   530,  -553,  -553,  -553,  -517,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -552,  -553,
    -553,  -553,  -478,  -553,  -553,  -553,  -553,  -553,   395,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,   477,  -553,
    -553,  -553,  -553,  -123,  -553,  -317
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    90,    23,    24,    38,    25,    53,    26,
      27,    83,   140,   204,   205,   213,    28,   272,    29,    81,
     136,   267,   328,   258,   259,   278,   419,    30,    78,   195,
     131,   440,    31,    41,   132,   199,   266,   351,    32,    42,
      33,    55,    87,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    94,   118,   120,   169,   232,   393,    34,    48,    85,
     142,   284,   329,   394,   330,   362,   331,   332,   420,   459,
     421,   334,   335,   428,   429,   430,   431,   422,   453,   542,
     395,   554,   741,   396,   555,   397,   398,   725,   743,    96,
     100,   289,   102,   112,   114,   399,   635,   122,   104,   528,
     243,   244,   296,   106,   108,   342,   400,   401,   553,   238,
     239,    98,   110,   191,   402,   492,   659,   403,   701,   578,
     404,   471,   405,   485,   406,   644,   407,   647,   646,   116,
     413,   666,   501,   408,   409,   410,   483,   640,   641,   642,
      35,    91,   153,   154,    36,    77,   411,   476,   477,   560,
      37,    92,   167,   220,   224,   360
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     171,   613,   208,    54,   443,   152,   361,   567,   281,   261,
     522,   279,   178,   176,   544,   306,   268,   753,   270,   648,
     183,   478,   184,   311,   313,   292,   293,   316,   125,    39,
     127,   490,    40,   493,   484,   300,   223,   225,   226,   227,
     228,   229,   230,   231,   336,   336,   358,   150,   359,   215,
     168,   126,   343,   134,   260,   260,   649,   650,   690,   312,
     551,   363,   260,   269,   260,   364,   137,   455,   317,   177,
     479,   480,   354,   235,   145,   146,   135,   669,   308,   309,
     552,   691,   246,    44,   247,   128,   457,   491,   498,   494,
     252,   253,   254,   255,    47,   432,   533,   434,   435,   475,
     196,   616,   196,   438,   618,   619,   620,   621,   129,   604,
     605,   495,  -313,  -313,   216,  -313,  -313,   260,   198,   198,
     130,   138,   347,   456,   260,   260,   310,   352,   277,   353,
     280,   538,   426,   355,     4,   695,   696,   697,   698,   699,
      43,   614,   700,   291,   139,    51,   180,   444,   206,   207,
     218,   299,   615,   446,   744,   197,   450,   200,    50,   322,
     323,    45,   423,   441,   732,   733,   451,    52,   260,   206,
     207,   445,  -133,   260,   638,   260,   506,   457,    51,    52,
      51,    52,   676,   469,    46,   432,   186,   610,   705,   739,
      49,   319,   337,   320,   531,   187,   221,   188,   481,   281,
     535,   127,   507,   508,   509,   510,    88,   512,    56,   260,
     189,   513,   514,   515,   516,   517,   518,   519,   424,   282,
     283,   638,   426,    89,   181,   454,   458,   287,   219,   685,
     295,   461,   392,   423,   190,   448,    51,    52,   148,   359,
     327,    52,   276,   206,   207,   436,   539,     8,     9,    10,
      11,   577,    51,    52,   583,    84,    12,   534,   643,   333,
     333,   451,    52,   463,   457,   724,   520,   457,   457,   457,
     457,   447,   460,   499,   222,    14,    51,    52,   579,   129,
     475,   474,   631,   432,   432,   432,   432,   432,   575,   424,
     611,   465,    82,   149,   150,   415,   425,  -362,   751,    51,
      52,   532,   722,   260,   693,   288,   748,   583,   749,   462,
     427,   327,    52,   276,   206,   207,   151,   458,    51,    52,
     426,   426,   426,   426,   426,   706,    17,   691,  -362,   691,
     437,   691,   651,   577,   577,   363,   710,   333,   529,   364,
      19,   464,    57,   415,    22,   457,   499,   568,   240,   363,
     470,   416,   707,   364,   526,   572,   527,   248,   417,    51,
      58,   570,   472,   473,    79,   324,   325,   668,   482,   466,
     575,   575,   418,   327,    52,   276,   206,   207,   671,   507,
     508,   509,   510,   524,   512,   525,    80,   500,   513,   514,
     515,   516,   517,   518,   519,   546,   547,   548,   549,   416,
     427,   451,    52,   740,   458,    86,   417,   458,   458,   458,
     458,   573,   577,   577,   577,   577,   577,    93,   574,   577,
     418,   327,    52,   276,   206,   207,    95,   670,   457,   206,
     207,   608,   218,   327,    52,   276,   206,   207,   451,    52,
      97,   206,   207,   520,   662,   546,   547,   548,   549,   575,
     575,   575,   575,   575,   -93,   623,   575,   150,   625,  -109,
     500,   457,   263,   723,   318,   547,   576,   549,   150,   264,
     202,  -103,  -111,   260,   582,   451,    52,   203,   256,   442,
    -107,   -97,   -99,  -101,    99,   458,   264,  -388,   487,   489,
     449,  -345,   -95,   684,  -119,   257,   206,   207,   427,   427,
     427,   427,   427,   101,   265,   633,   634,   276,   206,   207,
     219,   546,   547,   548,   549,   734,   502,   415,   503,   504,
     505,   508,   583,   510,   584,   512,   521,   499,   103,   678,
     679,   211,   212,   628,   585,  -388,  -388,  -113,   105,  -388,
     107,  -388,  -388,  -388,  -388,  -388,  -388,  -388,   576,   576,
     109,  -388,   639,   150,   111,   541,   113,   586,   663,   115,
    -121,  -123,   606,   607,  -115,  -117,  -105,   141,   458,   556,
     557,   117,   121,   416,  -228,   119,   123,   276,   206,   207,
     417,   652,   653,   654,   655,  -228,   656,   653,   124,   655,
     168,   656,   657,   658,   418,   327,    52,   276,   206,   207,
     540,   458,   143,   545,   719,   546,   547,   548,   549,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   600,   601,   144,   415,   170,   639,   576,   576,   576,
     576,   576,   172,   415,   576,   173,   174,   702,   175,   179,
     366,   500,   367,   368,   752,   754,   324,   325,   182,   369,
     193,   370,   257,   206,   207,   326,   371,   372,   185,  -129,
     373,   374,   276,   206,   207,   375,   694,   194,   201,   767,
     652,   653,   654,   655,   209,   656,   507,   508,   509,   510,
     416,   512,   327,    52,   376,   377,   378,   417,   210,   416,
     214,   217,   379,   380,   168,    15,   417,   234,   236,  -173,
     237,   418,   486,    52,   276,   206,   207,   324,   325,   381,
     418,   488,    52,   276,   206,   207,   326,   672,   617,   241,
    -130,  -262,   546,   547,   548,   549,   382,   383,   384,   242,
     245,   249,   680,   250,   385,   251,   273,   386,   275,    20,
      21,   387,   271,   327,    52,   688,   689,   150,   673,   692,
     546,   547,   548,   549,   507,   508,   509,   510,   388,   512,
    -173,   286,   281,   389,   390,   515,   516,   517,   518,   519,
      -4,     1,   290,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,   294,   297,   298,    -4,    -4,   718,   301,   715,
     302,   652,   653,   654,   655,   303,   656,   304,    -4,    -4,
     307,   321,    -4,   315,    -4,   720,   721,    -4,    -4,    -4,
      -4,    -4,   726,   314,   728,   338,   339,   340,   520,    -4,
      -4,    -4,   341,   344,   738,   345,   346,    -2,   348,   745,
       5,     6,     7,     8,     9,    10,    11,   349,   365,   350,
     356,   412,    12,   433,   414,   357,   439,   467,   468,   757,
     496,   497,   758,    51,   523,    -4,   530,   264,   536,    13,
      -4,    14,   764,   364,    -4,   537,   543,   550,    15,    -4,
      -4,    -4,   558,    -4,   559,   561,   562,    16,   563,   564,
     565,   580,   491,   566,   512,   609,   612,    -4,    -4,   569,
     622,    -4,    -4,    -4,   630,   636,   507,   508,   509,   510,
     632,   512,   624,   637,   660,   513,   514,   515,   516,   517,
     518,   519,    17,   664,   645,   667,   661,    18,   665,   552,
     675,   677,   682,   656,   571,   687,    19,    20,    21,   683,
      22,   507,   508,   509,   510,   703,   512,   704,   708,   709,
     513,   514,   515,   516,   517,   518,   519,   716,   711,   713,
     712,   714,   729,   727,   507,   508,   509,   510,   730,   512,
     520,   735,   742,   513,   514,   515,   516,   517,   518,   519,
     717,   755,   746,   747,   756,   759,   761,   507,   508,   509,
     510,   760,   512,   762,   768,   765,   513,   514,   515,   516,
     517,   518,   519,   587,   147,   520,   391,   507,   508,   509,
     510,   603,   512,   305,   274,   262,   513,   514,   515,   516,
     517,   518,   519,   133,   452,   602,   285,   233,   520,   507,
     508,   509,   510,   674,   512,   681,   192,   581,   513,   514,
     515,   516,   517,   518,   519,   686,   629,     0,   626,     0,
       0,   520,   507,   508,   509,   510,     0,   512,     0,     0,
       0,   513,   514,   515,   516,   517,   518,   519,   627,     0,
       0,   520,   507,   508,   509,   510,     0,   512,     0,     0,
       0,   513,   514,   515,   516,   517,   518,   519,     0,     0,
     731,     0,     0,   520,   507,   508,   509,   510,     0,   512,
       0,     0,     0,   513,   514,   515,   516,   517,   518,   519,
       0,     0,     0,   736,     0,     0,   520,   507,   508,   509,
     510,     0,   512,     0,     0,     0,   513,   514,   515,   516,
     517,   518,   519,   737,     0,     0,   520,   507,   508,   509,
     510,     0,   512,     0,     0,     0,   513,   514,   515,   516,
     517,   518,   519,     0,     0,   763,     0,     0,   520,   507,
     508,   509,   510,     0,   512,     0,     0,     0,   513,   514,
     515,   516,   517,   518,   519,     0,     0,     0,   766,     0,
       0,   520,   507,   508,   509,   510,     0,   512,     0,     0,
       0,   513,   514,   515,   516,   517,   518,   519,     0,     0,
       0,   520,   507,   508,   509,   510,   511,   512,     0,     0,
       0,   513,   514,   515,   516,   517,   518,   519,     0,   507,
     508,   509,   510,   520,   512,     0,   750,     0,   513,   514,
     515,   516,   517,   518,   519,     0,   155,     0,   507,   508,
     509,   510,     0,   512,     0,     0,   520,   513,   514,   515,
     516,   517,   518,   519,     0,     0,     0,   507,   508,   509,
     510,     0,   512,     0,     0,     0,   520,   514,   515,   516,
     517,   518,   519,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   520,   156,   157,     0,     0,   158,     0,
     159,   160,   161,   162,   163,   164,   165,     0,     0,     0,
     166,     0,   520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   520
};

static const yytype_int16 yycheck[] =
{
      97,   535,   141,    17,   349,    91,   323,   485,    69,   194,
     425,   214,   109,     1,   456,   258,   201,    22,   203,   571,
     117,    30,   119,   266,   267,   241,   242,   270,    56,    55,
       1,     1,    55,     1,     1,   251,   159,   160,   161,   162,
     163,   164,   165,   166,   284,   285,   107,    57,   109,     1,
      55,    79,   295,    56,   193,   194,   573,   574,    56,    69,
      13,    57,   201,   202,   203,    61,     1,     1,   271,    57,
      79,    80,   315,   170,    88,    89,    79,   611,   263,   264,
      33,    79,   179,     1,   181,    56,   365,    57,     1,    57,
     187,   188,   189,   190,     1,   335,   441,   340,   341,   378,
       1,   543,     1,   346,   546,   547,   548,   549,    79,   524,
     525,   390,    79,    80,    66,    82,    83,   256,   132,   133,
      91,    56,   307,    57,   263,   264,   265,   312,   214,   314,
     216,   448,   335,   316,     0,   652,   653,   654,   655,   656,
      55,    58,   659,   240,    79,    79,     1,   350,    82,    83,
       1,   248,    69,   356,    14,    56,   359,    56,     1,   282,
     283,    79,     1,   348,   716,   717,    79,    80,   307,    82,
      83,   354,    79,   312,     1,   314,   419,   456,    79,    80,
      79,    80,   624,     1,    55,   425,     1,   532,   666,   723,
      84,   277,   289,   279,   437,    10,     1,    12,     1,    69,
     443,     1,    62,    63,    64,    65,    69,    67,    82,   348,
      25,    71,    72,    73,    74,    75,    76,    77,    57,   106,
     107,     1,   425,    86,    79,   364,   365,     1,    79,    56,
     244,     1,   329,     1,    49,   358,    79,    80,     1,   109,
      79,    80,    81,    82,    83,   342,   449,     6,     7,     8,
       9,   491,    79,    80,    62,    79,    15,   442,    66,   284,
     285,    79,    80,     1,   543,   707,   126,   546,   547,   548,
     549,   357,   369,   412,    79,    34,    79,    80,   494,    79,
     559,     1,   561,   523,   524,   525,   526,   527,   491,    57,
     533,     1,    82,    56,    57,     1,    64,    17,   740,    79,
      80,   440,    57,   442,    56,    79,    56,    62,    56,    79,
     335,    79,    80,    81,    82,    83,    79,   456,    79,    80,
     523,   524,   525,   526,   527,   670,    85,    79,    48,    79,
     344,    79,   575,   573,   574,    57,    19,   362,   435,    61,
      99,    79,    55,     1,   103,   624,   485,    69,   173,    57,
     375,    57,    19,    61,    63,     1,    65,   182,    64,    79,
      55,    69,   376,   377,    55,    43,    44,   610,   382,    79,
     573,   574,    78,    79,    80,    81,    82,    83,    84,    62,
      63,    64,    65,    62,    67,    64,    55,   412,    71,    72,
      73,    74,    75,    76,    77,    62,    63,    64,    65,    57,
     425,    79,    80,    20,   543,    59,    64,   546,   547,   548,
     549,    57,   652,   653,   654,   655,   656,    10,    64,   659,
      78,    79,    80,    81,    82,    83,    11,   612,   707,    82,
      83,   528,     1,    79,    80,    81,    82,    83,    79,    80,
      49,    82,    83,   126,   583,    62,    63,    64,    65,   652,
     653,   654,   655,   656,    11,   552,   659,    57,   555,    16,
     485,   740,    17,   706,    64,    63,   491,    65,    57,    24,
      59,    28,    29,   612,   499,    79,    80,    66,    64,    17,
      37,    38,    39,    40,    38,   624,    24,    56,   386,   387,
      64,    57,    49,    59,    51,    81,    82,    83,   523,   524,
     525,   526,   527,    39,    59,    92,    93,    81,    82,    83,
      79,    62,    63,    64,    65,   718,   414,     1,   416,   417,
     418,    63,    62,    65,    64,    67,   424,   666,    40,   626,
     627,   145,   146,   558,    74,   104,   105,    94,    28,   108,
     123,   110,   111,   112,   113,   114,   115,   116,   573,   574,
      37,   120,   566,    57,    16,   453,    29,    97,   583,    94,
     117,   118,   526,   527,   121,   122,   123,    59,   707,   467,
     468,   121,    51,    57,    58,   122,   117,    81,    82,    83,
      64,    62,    63,    64,    65,    69,    67,    63,   118,    65,
      55,    67,    73,    74,    78,    79,    80,    81,    82,    83,
      84,   740,    69,    60,   701,    62,    63,    64,    65,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,    82,     1,    79,   640,   652,   653,   654,
     655,   656,    79,     1,   659,    79,    79,   662,    79,    79,
       1,   666,     3,     4,   741,   742,    43,    44,    79,    10,
      66,    12,    81,    82,    83,    52,    17,    18,    79,    56,
      21,    22,    81,    82,    83,    26,    58,    17,    66,   766,
      62,    63,    64,    65,    79,    67,    62,    63,    64,    65,
      57,    67,    79,    80,    45,    46,    47,    64,    60,    57,
      66,    79,    53,    54,    55,    41,    64,    56,    56,    96,
      27,    78,    79,    80,    81,    82,    83,    43,    44,    70,
      78,    79,    80,    81,    82,    83,    52,   615,    58,    57,
      56,    58,    62,    63,    64,    65,    87,    88,    89,    57,
      56,    56,   630,    56,    95,    57,    60,    98,    58,   100,
     101,   102,    74,    79,    80,   643,   644,    57,    60,   647,
      62,    63,    64,    65,    62,    63,    64,    65,   119,    67,
      96,    56,    69,   124,   125,    73,    74,    75,    76,    77,
       0,     1,    69,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    58,    56,    56,    15,    16,    58,    56,   687,
      56,    62,    63,    64,    65,    56,    67,    56,    28,    29,
      19,    79,    32,    60,    34,   703,   704,    37,    38,    39,
      40,    41,   710,    69,   712,    79,    56,    58,   126,    49,
      50,    51,    58,    69,   722,    56,    58,     0,    19,   727,
       3,     4,     5,     6,     7,     8,     9,    60,    59,    74,
      69,    96,    15,    56,    66,    73,    14,    57,    57,   747,
      56,    69,   750,    79,    66,    85,    56,    24,    73,    32,
      90,    34,   760,    61,    94,    73,    59,    56,    41,    99,
     100,   101,    69,   103,    48,    69,    79,    50,    59,    66,
      20,   108,    57,    55,    67,    56,    19,   117,   118,    55,
      42,   121,   122,   123,    17,    79,    62,    63,    64,    65,
      59,    67,    66,    79,    58,    71,    72,    73,    74,    75,
      76,    77,    85,    73,    79,    56,    79,    90,    74,    33,
      56,    56,    60,    67,    55,    57,    99,   100,   101,    63,
     103,    62,    63,    64,    65,    57,    67,    57,    56,    56,
      71,    72,    73,    74,    75,    76,    77,    55,    60,    31,
      66,    79,    57,    66,    62,    63,    64,    65,    60,    67,
     126,    56,    23,    71,    72,    73,    74,    75,    76,    77,
      55,    82,    79,    66,    58,    56,    56,    62,    63,    64,
      65,    57,    67,    62,    56,    79,    71,    72,    73,    74,
      75,    76,    77,    58,    90,   126,   329,    62,    63,    64,
      65,   523,    67,   256,   209,   195,    71,    72,    73,    74,
      75,    76,    77,    80,   362,    58,   233,   168,   126,    62,
      63,    64,    65,   622,    67,   632,   124,   497,    71,    72,
      73,    74,    75,    76,    77,   640,   559,    -1,    58,    -1,
      -1,   126,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    58,    -1,
      -1,   126,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      58,    -1,    -1,   126,    62,    63,    64,    65,    -1,    67,
      -1,    -1,    -1,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    58,    -1,    -1,   126,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    58,    -1,    -1,   126,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    58,    -1,    -1,   126,    62,
      63,    64,    65,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    58,    -1,
      -1,   126,    62,    63,    64,    65,    -1,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,   126,    62,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    71,    72,    73,    74,    75,    76,    77,    -1,    62,
      63,    64,    65,   126,    67,    -1,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    -1,    56,    -1,    62,    63,
      64,    65,    -1,    67,    -1,    -1,   126,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    67,    -1,    -1,    -1,   126,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   104,   105,    -1,    -1,   108,    -1,
     110,   111,   112,   113,   114,   115,   116,    -1,    -1,    -1,
     120,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     1,   130,   131,     0,     3,     4,     5,     6,     7,
       8,     9,    15,    32,    34,    41,    50,    85,    90,    99,
     100,   101,   103,   133,   134,   136,   138,   139,   145,   147,
     156,   161,   167,   169,   196,   279,   283,   289,   135,    55,
      55,   162,   168,    55,     1,    79,    55,     1,   197,    84,
       1,    79,    80,   137,   151,   170,    82,    55,    55,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   284,   157,    55,
      55,   148,    82,   140,    79,   198,    59,   171,    69,    86,
     132,   280,   290,    10,   190,    11,   228,    49,   250,    38,
     229,    39,   231,    40,   237,    28,   242,   123,   243,    37,
     251,    16,   232,    29,   233,    94,   268,   121,   191,   122,
     192,    51,   236,   117,   118,    56,    79,     1,    56,    79,
      91,   159,   163,   163,    56,    79,   149,     1,    56,    79,
     141,    59,   199,    69,    82,   151,   151,   138,     1,    56,
      57,    79,   143,   281,   282,    56,   104,   105,   108,   110,
     111,   112,   113,   114,   115,   116,   120,   291,    55,   193,
      79,   193,    79,    79,    79,    79,     1,    57,   193,    79,
       1,    79,    79,   193,   193,    79,     1,    10,    12,    25,
      49,   252,   252,    66,    17,   158,     1,    56,   151,   164,
      56,    66,    59,    66,   142,   143,    82,    83,   154,    79,
      60,   171,   171,   144,    66,     1,    66,    79,     1,    79,
     292,     1,    79,   292,   293,   292,   292,   292,   292,   292,
     292,   292,   194,   196,    56,   193,    56,    27,   248,   249,
     248,    57,    57,   239,   240,    56,   193,   193,   248,    56,
      56,    57,   193,   193,   193,   193,    64,    81,   152,   153,
     154,   152,   159,    17,    24,    59,   165,   150,   152,   154,
     152,    74,   146,    60,   199,    58,    81,   143,   154,   155,
     143,    69,   106,   107,   200,   200,    56,     1,    79,   230,
      69,   193,   239,   239,    58,   151,   241,    56,    56,   193,
     239,    56,    56,    56,    56,   153,   142,    19,   152,   152,
     154,   142,    69,   142,    69,    60,   142,   155,    64,   143,
     143,    79,   292,   292,    43,    44,    52,    79,   151,   201,
     203,   205,   206,   207,   210,   211,   216,   193,    79,    56,
      58,    58,   244,   142,    69,    56,    58,   152,    19,    60,
      74,   166,   152,   152,   142,   146,    69,    73,   107,   109,
     294,   294,   204,    57,    61,    59,     1,     3,     4,    10,
      12,    17,    18,    21,    22,    26,    45,    46,    47,    53,
      54,    70,    87,    88,    89,    95,    98,   102,   119,   124,
     125,   145,   193,   195,   202,   219,   222,   224,   225,   234,
     245,   246,   253,   256,   259,   261,   263,   265,   272,   273,
     274,   285,    96,   269,    66,     1,    57,    64,    78,   155,
     207,   209,   216,     1,    57,    64,   155,   207,   212,   213,
     214,   215,   216,    56,   142,   142,   193,   151,   142,    14,
     160,   152,    17,   165,   155,   146,   155,   143,   292,    64,
     155,    79,   206,   217,   154,     1,    57,   137,   154,   208,
     193,     1,    79,     1,    79,     1,    79,    57,    57,     1,
     207,   260,   151,   151,     1,   137,   286,   287,    30,    79,
      80,     1,   151,   275,     1,   262,    79,   209,    79,   209,
       1,    57,   254,     1,    57,   137,    56,    69,     1,   154,
     207,   271,   209,   209,   209,   209,   142,    62,    63,    64,
      65,    66,    67,    71,    72,    73,    74,    75,    76,    77,
     126,   209,   214,    66,    62,    64,    63,    65,   238,   193,
      56,   142,   154,   165,   152,   142,    73,    73,   294,   155,
      84,   209,   218,    59,   208,    60,    62,    63,    64,    65,
      56,    13,    33,   247,   220,   223,   209,   209,    69,    48,
     288,    69,    79,    59,    66,    20,    55,   271,    69,    55,
      69,    55,     1,    57,    64,   155,   207,   216,   258,   239,
     108,   254,   207,    62,    64,    74,    97,    58,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,    58,   213,   214,   214,   215,   215,   193,    56,
     165,   142,    19,   166,    58,    69,   208,    58,   208,   208,
     208,   208,    42,   193,    66,   193,    58,    58,   207,   287,
      17,   137,    59,    92,    93,   235,    79,    79,     1,   151,
     276,   277,   278,    66,   264,    79,   267,   266,   267,   258,
     258,   142,    62,    63,    64,    65,    67,    73,    74,   255,
      58,    79,   154,   207,    73,    74,   270,    56,   142,   166,
     152,    84,   209,    60,   247,    56,   208,    56,   193,   193,
     209,   235,    60,    63,    59,    56,   277,    57,   209,   209,
      56,    79,   209,    56,    58,   258,   258,   258,   258,   258,
     258,   257,   207,    57,    57,   271,   165,    19,    56,    56,
      19,    60,    66,    31,    79,   209,    55,    55,    58,   193,
     209,   209,    57,   142,   208,   226,   209,    66,   209,    57,
      60,    58,   267,   267,   155,    56,    58,    58,   209,   166,
      20,   221,    23,   227,    14,   209,    79,    66,    56,    56,
      69,   208,   193,    22,   193,    82,    58,   209,   209,    56,
      57,    56,    62,    58,   209,    79,    58,   193,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   129,   130,   130,   131,   131,   131,   131,   131,   132,
     131,   133,   131,   131,   131,   131,   131,   134,   135,   136,
     136,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   139,   140,   140,   141,   141,   141,   141,   142,   142,
     144,   143,   145,   145,   146,   146,   147,   148,   148,   149,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   156,   157,   157,   158,   157,   159,   159,   160,
     162,   161,   163,   163,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   168,   167,   169,   169,   170,   170,   171,
     171,   173,   172,   174,   172,   175,   172,   176,   172,   177,
     172,   178,   172,   179,   172,   180,   172,   181,   172,   182,
     172,   183,   172,   184,   172,   185,   172,   186,   172,   187,
     172,   188,   172,   189,   172,   190,   191,   192,   194,   193,
     193,   195,   195,   197,   196,   196,   198,   198,   199,   199,
     200,   201,   200,   200,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     203,   204,   203,   205,   203,   203,   206,   206,   206,   207,
     207,   207,   207,   208,   208,   208,   208,   208,   208,   208,
     208,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   210,   211,   212,   213,   213,   213,   213,   214,   214,
     214,   215,   215,   215,   215,   215,   217,   216,   218,   218,
     218,   218,   218,   220,   219,   219,   221,   221,   223,   222,
     222,   224,   225,   226,   226,   227,   227,   228,   230,   229,
     231,   232,   233,   233,   234,   234,   234,   235,   235,   236,
     238,   237,   239,   240,   239,   241,   241,   242,   244,   243,
     243,   245,   246,   246,   246,   247,   247,   248,   248,   249,
     249,   249,   250,   251,   252,   252,   252,   252,   252,   253,
     253,   253,   254,   255,   255,   257,   256,   256,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   259,
     259,   260,   260,   262,   261,   261,   264,   263,   263,   266,
     265,   265,   267,   267,   268,   270,   269,   269,   269,   269,
     271,   271,   271,   271,   272,   272,   273,   273,   275,   274,
     276,   276,   277,   277,   277,   278,   278,   279,   280,   280,
     280,   281,   281,   282,   282,   282,   282,   283,   284,   284,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   291,   291,   291,   291,   292,   292,   292,   293,   293,
     294,   294,   294
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     2,     2,     2,     0,
       5,     0,     3,     2,     2,     2,     3,     2,     0,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     2,     5,     3,     6,     1,     0,     1,
       0,     3,     1,     1,     0,     5,     4,     0,     2,     4,
       3,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     4,     0,     2,     0,     4,     9,     1,     1,
       0,     5,     0,     2,     4,     7,     8,    11,     1,     0,
       2,     0,     3,     0,     5,     5,     2,     2,     4,     0,
       3,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     0,     2,     0,
       2,     0,     3,     0,     3,     3,     3,     3,     0,     3,
       3,     2,     4,     0,     3,     2,     2,     4,     0,     3,
       0,     0,     3,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     2,     1,     3,     4,     4,     1,
       4,     3,     6,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       1,     1,     1,     1,     1,     2,     3,     3,     1,     3,
       3,     1,     1,     1,     3,     1,     0,     5,     0,     1,
       1,     3,     3,     0,    10,     2,     0,     2,     0,     5,
       2,     6,     8,     0,     8,     0,     3,     4,     0,     6,
       5,     4,     4,     2,    11,     8,     7,     1,     1,     6,
       0,     9,     0,     0,     2,     2,     4,     8,     0,     7,
       2,     3,     3,     5,     2,     0,     3,     0,     1,     2,
       3,     2,     3,     3,     3,     3,     3,     3,     1,     2,
       3,     2,     6,     1,     1,     0,     7,     2,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     2,     1,     2,
       2,     1,     3,     0,     5,     2,     0,     8,     5,     0,
       8,     5,     1,     2,     5,     0,    10,     7,     7,     2,
       1,     2,     3,     4,     4,     2,     2,     2,     0,     5,
       1,     2,     1,     6,     1,     1,     4,     4,     0,     2,
       2,     3,     2,     4,     4,     6,     1,     4,     0,     5,
       9,     2,     0,     1,     1,     3,     0,     2,     4,     0,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     5,     7,     2,     1,     3,     1,     0,     1,
       0,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 133 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {/*ldebug(top, intoken)*/;}
#line 2196 "parse1.c" /* yacc.c:1646  */
    break;

  case 3:
#line 134 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {diag("Illegal block", (char *)0);}
#line 2202 "parse1.c" /* yacc.c:1646  */
    break;

  case 6:
#line 140 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {Item* q; replacstr((yyvsp[0].qp), "static double");
		vectorize_substitute((yyvsp[0].qp), "/*Top LOCAL");
		vectorize_substitute(lastok->next, "*/\n");
		movelist((yyvsp[0].qp), lastok->next, firstlist);
		if (!toplocal_) {toplocal_ = newlist();}
		ITERATE(q, toplocal1_) {
			assert(SYM(q)->name[0] == '_' && SYM(q)->name[1] == 'l');
			SYM(q)->name[1] = 'z';
		}
		movelist(toplocal1_->next, toplocal1_->prev, toplocal_);
		}
#line 2218 "parse1.c" /* yacc.c:1646  */
    break;

  case 9:
#line 153 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {model_level = atoi(STR((yyvsp[0].qp)));}
#line 2224 "parse1.c" /* yacc.c:1646  */
    break;

  case 10:
#line 154 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {model_level = 0;}
#line 2230 "parse1.c" /* yacc.c:1646  */
    break;

  case 11:
#line 156 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (sensused)
			diag("sensitivity analysis not implemented for",
				" this block type");
		}
#line 2239 "parse1.c" /* yacc.c:1646  */
    break;

  case 13:
#line 163 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name); replacstr((yyvsp[0].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		movelist((yyvsp[0].qp),intoken->prev, procfunc);}
#line 2251 "parse1.c" /* yacc.c:1646  */
    break;

  case 14:
#line 172 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		in_comment_ = 1;
		inblock(SYM((yyvsp[0].qp))->name); deltokens((yyvsp[0].qp), intoken->prev);
		in_comment_ = 0;
		}
#line 2261 "parse1.c" /* yacc.c:1646  */
    break;

  case 16:
#line 179 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {include_file((yyvsp[0].qp));}
#line 2267 "parse1.c" /* yacc.c:1646  */
    break;

  case 17:
#line 182 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (modelline == NULL) modelline = (yyvsp[0].str);
			deltokens((yyvsp[-1].qp), intoken->prev);}
#line 2274 "parse1.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.str) = inputline();}
#line 2280 "parse1.c" /* yacc.c:1646  */
    break;

  case 19:
#line 190 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Symbol *sp = SYM((yyvsp[-1].qp));
	 if (sp->subtype)
		diag(sp->name, " used before DEFINEed");
	 sp->u.str = STR((yyvsp[0].qp));
	 sp->type = DEFINEDVAR;
	 deltokens((yyvsp[-2].qp), (yyvsp[0].qp));}
#line 2291 "parse1.c" /* yacc.c:1646  */
    break;

  case 20:
#line 196 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("syntax: DEFINE name integer");}
#line 2297 "parse1.c" /* yacc.c:1646  */
    break;

  case 21:
#line 199 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Symbol *checklocal();
		  SYM((yyvsp[0].qp)) = checklocal(SYM((yyvsp[0].qp)));  /* it was a bug
			when this was done to the lookahead token in lex */
		}
#line 2306 "parse1.c" /* yacc.c:1646  */
    break;

  case 31:
#line 207 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2312 "parse1.c" /* yacc.c:1646  */
    break;

  case 33:
#line 211 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));}
#line 2318 "parse1.c" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {parminstall(SYM((yyvsp[-4].qp)), STR((yyvsp[-2].qp)), (yyvsp[-1].str), (yyvsp[0].str));}
#line 2324 "parse1.c" /* yacc.c:1646  */
    break;

  case 35:
#line 219 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {parminstall(SYM((yyvsp[-2].qp)), "0", (yyvsp[-1].str), (yyvsp[0].str));}
#line 2330 "parse1.c" /* yacc.c:1646  */
    break;

  case 36:
#line 221 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { int i = atoi(STR((yyvsp[-3].qp)));
		  if (i < 1) diag("Array index must be > 0", (char*)0);
		  parm_array_install(SYM((yyvsp[-5].qp)), "0", (yyvsp[-1].str), (yyvsp[0].str), i);
		}
#line 2339 "parse1.c" /* yacc.c:1646  */
    break;

  case 37:
#line 225 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {diag("name = number", (char *)0);}
#line 2345 "parse1.c" /* yacc.c:1646  */
    break;

  case 38:
#line 227 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.str) = stralloc("", (char *)0);}
#line 2351 "parse1.c" /* yacc.c:1646  */
    break;

  case 40:
#line 230 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.str) = inputtopar();}
#line 2357 "parse1.c" /* yacc.c:1646  */
    break;

  case 41:
#line 232 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-1].str); delete((yyvsp[-2].qp)); delete((yyvsp[0].qp));}
#line 2363 "parse1.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), "");}
#line 2369 "parse1.c" /* yacc.c:1646  */
    break;

  case 43:
#line 235 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), "");}
#line 2375 "parse1.c" /* yacc.c:1646  */
    break;

  case 44:
#line 238 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.str) = stralloc("", (char*)0);}
#line 2381 "parse1.c" /* yacc.c:1646  */
    break;

  case 45:
#line 240 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		 Sprintf(buf, "%s %s", STR((yyvsp[-3].qp)), STR((yyvsp[-1].qp)));
		 (yyval.str) = stralloc(buf, (char*)0);
		}
#line 2390 "parse1.c" /* yacc.c:1646  */
    break;

  case 46:
#line 245 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2396 "parse1.c" /* yacc.c:1646  */
    break;

  case 48:
#line 249 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp)); }
#line 2402 "parse1.c" /* yacc.c:1646  */
    break;

  case 49:
#line 253 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {steppedinstall(SYM((yyvsp[-3].qp)), (yyvsp[-1].qp), lastok, (yyvsp[0].str));}
#line 2408 "parse1.c" /* yacc.c:1646  */
    break;

  case 54:
#line 261 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 2414 "parse1.c" /* yacc.c:1646  */
    break;

  case 55:
#line 264 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Sprintf(buf, "-%s", STR((yyvsp[0].qp)));
		 STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp))); (yyval.qp) = (yyvsp[0].qp);
		delete((yyvsp[-1].qp)); lastok = (yyvsp[0].qp);
		}
#line 2423 "parse1.c" /* yacc.c:1646  */
    break;

  case 59:
#line 272 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[0].qp), SYM((yyvsp[0].qp))->u.str);}
#line 2429 "parse1.c" /* yacc.c:1646  */
    break;

  case 60:
#line 274 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 2435 "parse1.c" /* yacc.c:1646  */
    break;

  case 61:
#line 276 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {Sprintf(buf, "%s.0", STR((yyvsp[0].qp)));
		STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp)));
		lastok = (yyvsp[0].qp);
		}
#line 2444 "parse1.c" /* yacc.c:1646  */
    break;

  case 62:
#line 281 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2450 "parse1.c" /* yacc.c:1646  */
    break;

  case 64:
#line 285 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp)); }
#line 2456 "parse1.c" /* yacc.c:1646  */
    break;

  case 65:
#line 286 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {scopindep = 1;}
#line 2462 "parse1.c" /* yacc.c:1646  */
    break;

  case 66:
#line 287 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));
		  scopindep = 0;
		}
#line 2470 "parse1.c" /* yacc.c:1646  */
    break;

  case 67:
#line 293 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {indepinstall(SYM((yyvsp[-8].qp)), STR((yyvsp[-6].qp)),
		 STR((yyvsp[-4].qp)), STR((yyvsp[-2].qp)), (yyvsp[-1].qp), (yyvsp[0].str), scopindep);
		}
#line 2478 "parse1.c" /* yacc.c:1646  */
    break;

  case 68:
#line 296 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {diag("name FROM number TO number WITH integer\n", (char *)0);}
#line 2484 "parse1.c" /* yacc.c:1646  */
    break;

  case 70:
#line 300 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {stateblock = 0;}
#line 2490 "parse1.c" /* yacc.c:1646  */
    break;

  case 71:
#line 300 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 2496 "parse1.c" /* yacc.c:1646  */
    break;

  case 73:
#line 304 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { explicit_decl(model_level, (yyvsp[0].qp));}
#line 2502 "parse1.c" /* yacc.c:1646  */
    break;

  case 74:
#line 308 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {depinstall(stateblock, SYM((yyvsp[-3].qp)), 0, "0", "1", (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		 }
#line 2509 "parse1.c" /* yacc.c:1646  */
    break;

  case 75:
#line 311 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {int i = atoi(STR((yyvsp[-4].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[-6].qp)), i,
			 "0", "1", (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2519 "parse1.c" /* yacc.c:1646  */
    break;

  case 76:
#line 317 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {depinstall(stateblock, SYM((yyvsp[-7].qp)), 0, STR((yyvsp[-5].qp)),
		 STR((yyvsp[-3].qp)), (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2527 "parse1.c" /* yacc.c:1646  */
    break;

  case 77:
#line 321 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {int i = atoi(STR((yyvsp[-8].qp)));
		 if (i < 1) diag("Array index must be > 0", (char *)0);
		 depinstall(stateblock, SYM((yyvsp[-10].qp)), i,
		 STR((yyvsp[-5].qp)), STR((yyvsp[-3].qp)), (yyvsp[-1].str), (yyvsp[-2].qp), 1, (yyvsp[0].str));
		}
#line 2537 "parse1.c" /* yacc.c:1646  */
    break;

  case 78:
#line 326 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
diag("name FROM number TO number START number\n",
"FROM...TO and START are optional, name can be name[integer]\n");}
#line 2545 "parse1.c" /* yacc.c:1646  */
    break;

  case 79:
#line 330 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 2551 "parse1.c" /* yacc.c:1646  */
    break;

  case 80:
#line 331 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp);}
#line 2557 "parse1.c" /* yacc.c:1646  */
    break;

  case 81:
#line 334 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.str) = stralloc("", (char*)0);}
#line 2563 "parse1.c" /* yacc.c:1646  */
    break;

  case 82:
#line 336 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
			(yyval.str) = stralloc(STR((yyvsp[-1].qp)), (char*)0);
		}
#line 2571 "parse1.c" /* yacc.c:1646  */
    break;

  case 83:
#line 340 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {stateblock = 1;}
#line 2577 "parse1.c" /* yacc.c:1646  */
    break;

  case 84:
#line 340 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 2583 "parse1.c" /* yacc.c:1646  */
    break;

  case 85:
#line 344 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Item *q;
		 q = linsertsym(plotlist, SYM((yyvsp[-1].qp))); Insertstr(q->next, (yyvsp[0].str)); }
#line 2590 "parse1.c" /* yacc.c:1646  */
    break;

  case 86:
#line 347 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { diag("PLOT namelist VS name", (char *)0);}
#line 2596 "parse1.c" /* yacc.c:1646  */
    break;

  case 87:
#line 350 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (plotlist->next == plotlist) {
			Lappendsym(plotlist, SYM((yyvsp[-1].qp)));
			Lappendstr(plotlist, (yyvsp[0].str));
		  }else{
			diag("Only one PLOT declaration allowed", (char *)0);
		  }
		}
#line 2608 "parse1.c" /* yacc.c:1646  */
    break;

  case 88:
#line 358 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Lappendsym(plotlist, SYM((yyvsp[-1].qp))); Lappendstr(plotlist, (yyvsp[0].str));}
#line 2614 "parse1.c" /* yacc.c:1646  */
    break;

  case 89:
#line 361 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.str) = "-1";}
#line 2620 "parse1.c" /* yacc.c:1646  */
    break;

  case 90:
#line 363 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.str) = STR((yyvsp[-1].qp));}
#line 2626 "parse1.c" /* yacc.c:1646  */
    break;

  case 91:
#line 365 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = INITIAL1;}
#line 2632 "parse1.c" /* yacc.c:1646  */
    break;

  case 93:
#line 367 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lexcontext = NONLINEAR; blocktype = DERIVATIVE;}
#line 2638 "parse1.c" /* yacc.c:1646  */
    break;

  case 95:
#line 368 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = BREAKPOINT;}
#line 2644 "parse1.c" /* yacc.c:1646  */
    break;

  case 97:
#line 369 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = LINEAR;}
#line 2650 "parse1.c" /* yacc.c:1646  */
    break;

  case 99:
#line 370 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = NONLINEAR;}
#line 2656 "parse1.c" /* yacc.c:1646  */
    break;

  case 101:
#line 371 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = FUNCTION1;}
#line 2662 "parse1.c" /* yacc.c:1646  */
    break;

  case 103:
#line 372 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = PROCEDURE;}
#line 2668 "parse1.c" /* yacc.c:1646  */
    break;

  case 105:
#line 373 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = NETRECEIVE;}
#line 2674 "parse1.c" /* yacc.c:1646  */
    break;

  case 107:
#line 374 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = TERMINAL;}
#line 2680 "parse1.c" /* yacc.c:1646  */
    break;

  case 109:
#line 375 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = DISCRETE;}
#line 2686 "parse1.c" /* yacc.c:1646  */
    break;

  case 111:
#line 376 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = PARTIAL;}
#line 2692 "parse1.c" /* yacc.c:1646  */
    break;

  case 113:
#line 377 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lexcontext = blocktype = KINETIC;ostmt_start();}
#line 2698 "parse1.c" /* yacc.c:1646  */
    break;

  case 114:
#line 377 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {see_ostmt();}
#line 2704 "parse1.c" /* yacc.c:1646  */
    break;

  case 115:
#line 378 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = CONSTRUCTOR;}
#line 2710 "parse1.c" /* yacc.c:1646  */
    break;

  case 117:
#line 379 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = DESTRUCTOR;}
#line 2716 "parse1.c" /* yacc.c:1646  */
    break;

  case 119:
#line 380 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = FUNCTION_TABLE;}
#line 2722 "parse1.c" /* yacc.c:1646  */
    break;

  case 121:
#line 381 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = BEFORE;}
#line 2728 "parse1.c" /* yacc.c:1646  */
    break;

  case 123:
#line 382 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {blocktype = AFTER;}
#line 2734 "parse1.c" /* yacc.c:1646  */
    break;

  case 125:
#line 385 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), initfunc);}
#line 2740 "parse1.c" /* yacc.c:1646  */
    break;

  case 126:
#line 388 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), constructorfunc);}
#line 2746 "parse1.c" /* yacc.c:1646  */
    break;

  case 127:
#line 391 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), destructorfunc);}
#line 2752 "parse1.c" /* yacc.c:1646  */
    break;

  case 128:
#line 393 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal();}
#line 2758 "parse1.c" /* yacc.c:1646  */
    break;

  case 129:
#line 393 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {poplocal();}
#line 2764 "parse1.c" /* yacc.c:1646  */
    break;

  case 130:
#line 395 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {poplocal();}
#line 2770 "parse1.c" /* yacc.c:1646  */
    break;

  case 131:
#line 398 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {conductance_hint(blocktype, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 2776 "parse1.c" /* yacc.c:1646  */
    break;

  case 132:
#line 400 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {conductance_hint(blocktype, (yyvsp[-3].qp), (yyvsp[0].qp));}
#line 2782 "parse1.c" /* yacc.c:1646  */
    break;

  case 133:
#line 403 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		  if (toplocal1_) {freelist(&toplocal1_);}
		  toplocal1_ = newlist();
		}
#line 2791 "parse1.c" /* yacc.c:1646  */
    break;

  case 134:
#line 408 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-2].qp), "double");
		  Insertstr(lastok->next, ";\n");
		  possible_local_current(blocktype, toplocal1_);
		}
#line 2800 "parse1.c" /* yacc.c:1646  */
    break;

  case 135:
#line 412 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal LOCAL declaration");}
#line 2806 "parse1.c" /* yacc.c:1646  */
    break;

  case 136:
#line 417 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {int a2; pushlocal();
		 a2 = SYM((yyvsp[-1].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));
		 SYM((yyvsp[-1].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[-1].qp)));
		 if ((yyvsp[0].i)) {
			SYM((yyvsp[-1].qp))->araydim = (yyvsp[0].i);
			SYM((yyvsp[-1].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[-1].qp);
		 }
		}
#line 2823 "parse1.c" /* yacc.c:1646  */
    break;

  case 137:
#line 430 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		 int a2 = SYM((yyvsp[-1].qp))->assigned_to_; /* in case marked threadsafe */
		 SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));
		 SYM((yyvsp[-1].qp))->assigned_to_ = a2;
		 lappendsym(toplocal1_, SYM((yyvsp[-1].qp)));
		 if ((yyvsp[0].i)) {
			SYM((yyvsp[-1].qp))->araydim = (yyvsp[0].i);
			SYM((yyvsp[-1].qp))->subtype |= ARRAY;
		 }else{
			lastok = (yyvsp[-1].qp);
		 }
		}
#line 2840 "parse1.c" /* yacc.c:1646  */
    break;

  case 138:
#line 444 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.i) = 0;}
#line 2846 "parse1.c" /* yacc.c:1646  */
    break;

  case 139:
#line 446 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.i) = atoi(STR((yyvsp[-1].qp))); lastok = (yyvsp[0].qp);}
#line 2852 "parse1.c" /* yacc.c:1646  */
    break;

  case 141:
#line 449 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) see_ostmt();}
#line 2858 "parse1.c" /* yacc.c:1646  */
    break;

  case 142:
#line 450 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) see_ostmt();}
#line 2864 "parse1.c" /* yacc.c:1646  */
    break;

  case 143:
#line 451 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (blocktype == KINETIC) { see_astmt((yyvsp[0].qp), astmt_end_); }}
#line 2870 "parse1.c" /* yacc.c:1646  */
    break;

  case 151:
#line 461 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name);
		replacstr((yyvsp[0].qp), "\n/*VERBATIM*/\n");
		if (!assert_threadsafe && !saw_verbatim_) {
 		 fprintf(stderr, "Notice: VERBATIM blocks are not thread safe\n");
		 saw_verbatim_ = 1;
		 vectorize = 0;
		}
		}
#line 2883 "parse1.c" /* yacc.c:1646  */
    break;

  case 152:
#line 471 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inblock(SYM((yyvsp[0].qp))->name); deltokens((yyvsp[0].qp), intoken->prev);}
#line 2889 "parse1.c" /* yacc.c:1646  */
    break;

  case 154:
#line 473 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "COMPARTMENT");}
#line 2895 "parse1.c" /* yacc.c:1646  */
    break;

  case 155:
#line 474 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "LONGDIFUS");}
#line 2901 "parse1.c" /* yacc.c:1646  */
    break;

  case 156:
#line 475 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {check_block(KINETIC, blocktype, "CONSERVE");}
#line 2907 "parse1.c" /* yacc.c:1646  */
    break;

  case 159:
#line 479 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[0].qp), " _reset = 1;\n"); }
#line 2913 "parse1.c" /* yacc.c:1646  */
    break;

  case 162:
#line 483 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (blocktype !=FUNCTION1 && blocktype != PROCEDURE) {
			diag("TABLE valid only for FUNCTION or PROCEDURE", (char *)0);
		}}
#line 2921 "parse1.c" /* yacc.c:1646  */
    break;

  case 167:
#line 490 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrnmutex(1,(yyvsp[0].qp)); }
#line 2927 "parse1.c" /* yacc.c:1646  */
    break;

  case 168:
#line 491 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrnmutex(0,(yyvsp[0].qp)); }
#line 2933 "parse1.c" /* yacc.c:1646  */
    break;

  case 169:
#line 493 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal statement");}
#line 2939 "parse1.c" /* yacc.c:1646  */
    break;

  case 170:
#line 497 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {astmt_end_ = insertsym(lastok->next, semi);}
#line 2945 "parse1.c" /* yacc.c:1646  */
    break;

  case 171:
#line 498 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {protect_ = 1;}
#line 2951 "parse1.c" /* yacc.c:1646  */
    break;

  case 172:
#line 499 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {protect_ = 0; astmt_end_ = insertsym(lastok->next, semi);
			astmt_end_ = protect_astmt((yyvsp[-2].qp), astmt_end_);
		}
#line 2959 "parse1.c" /* yacc.c:1646  */
    break;

  case 173:
#line 502 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inequation = 1;}
#line 2965 "parse1.c" /* yacc.c:1646  */
    break;

  case 174:
#line 502 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		(yyval.qp) = (yyvsp[0].qp); inequation = 0;
		astmt_end_ = insertstr(lastok->next->next->next, "");}
#line 2973 "parse1.c" /* yacc.c:1646  */
    break;

  case 175:
#line 506 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {astmt_end_ = insertsym(lastok->next, semi);}
#line 2979 "parse1.c" /* yacc.c:1646  */
    break;

  case 176:
#line 511 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (blocktype == DERIVATIVE && SYM((yyvsp[-2].qp))->type == PRIME) {
			/* put Dvar in a derivative used list */
			deriv_used(SYM((yyvsp[-2].qp)), (yyvsp[0].qp), lastok);
			}
		  if (blocktype == DERIVATIVE && (SYM((yyvsp[-2].qp))->subtype & STAT)) {
			Fprintf(stderr,
"WARNING: %s (a STATE) is assigned a value\
 in a DERIVATIVE block.\n Multistep integrators (such as Runge) may not\
 work correctly.\n", SYM((yyvsp[-2].qp))->name);
		  }
		  if (blocktype == DISCRETE && SYM((yyvsp[-2].qp))->type == NAME
			&& (SYM((yyvsp[-2].qp))->subtype & STAT)) {
			SYM((yyvsp[-2].qp))->used++;
			}
		  if (blocktype == NETRECEIVE) {
			/* STATE discontinuity adjustment */
			netrec_asgn((yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp), lastok);
		  }
#if NOCMODL
		  nrn_var_assigned(SYM((yyvsp[-2].qp)));
#endif
		}
#line 3006 "parse1.c" /* yacc.c:1646  */
    break;

  case 177:
#line 535 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { inequation = 0;
		Insertstr((yyvsp[-2].qp), " -(");
		replacstr((yyvsp[-1].qp), ") + ");
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		 eqnqueue((yyvsp[-3].qp));
		}
#line 3018 "parse1.c" /* yacc.c:1646  */
    break;

  case 178:
#line 543 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { inequation = 0;
		delete((yyvsp[-1].qp));
		if (nstate == 0)
{yyerror("previous equation contains no state variables"); YYERROR;}
		}
#line 3028 "parse1.c" /* yacc.c:1646  */
    break;

  case 179:
#line 551 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		if (!extdef2){SYM((yyvsp[0].qp))->usage |= DEP;}
		if (SYM((yyvsp[0].qp))->subtype & ARRAY && !extdef2)
			{myerr("variable needs an index");}
		if (inequation && (SYM((yyvsp[0].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[0].qp)))) {
			SYM((yyvsp[0].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		if (SYM((yyvsp[0].qp))->subtype & INTGER) {
			lastok = insertstr((yyvsp[0].qp)->next, ")");
			(yyvsp[0].qp) = insertstr((yyvsp[0].qp), "((double)");
		}
		}
#line 3046 "parse1.c" /* yacc.c:1646  */
    break;

  case 180:
#line 565 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		if (SYM((yyvsp[-3].qp))->type == PRIME) {
			usederivstatearray = 1;
		}
		SYM((yyvsp[-3].qp))->usage |= DEP;
		if ((SYM((yyvsp[-3].qp))->subtype & ARRAY) == 0)
			{myerr("variable is not an array");}
		if (inequation && (SYM((yyvsp[-3].qp))->subtype & STAT) && in_solvefor(SYM((yyvsp[-3].qp)))) {
			SYM((yyvsp[-3].qp))->used++;
			nstate++; pstate++; tstate++;
		}
		  if (forallindex) {
			if (forallindex == -1) {
				forallindex = SYM((yyvsp[-3].qp))->araydim;
			}
			if (forallindex != SYM((yyvsp[-3].qp))->araydim) {
Sprintf(buf, "%s dimension not same as other dimensions used in FORALL statement",
SYM((yyvsp[-3].qp))->name);
				diag(buf, (char *)0);
			}
		  }
		}
#line 3073 "parse1.c" /* yacc.c:1646  */
    break;

  case 181:
#line 588 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		SYM((yyvsp[-2].qp))->usage |= DEP; disc_var_seen((yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp), 0);}
#line 3080 "parse1.c" /* yacc.c:1646  */
    break;

  case 182:
#line 591 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		SYM((yyvsp[-5].qp))->usage |= DEP; disc_var_seen((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-3].qp), ARRAY);}
#line 3087 "parse1.c" /* yacc.c:1646  */
    break;

  case 183:
#line 595 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);
		 SYM((yyvsp[0].qp))->usage |= DEP;
		 if (!(SYM((yyvsp[0].qp))->subtype & INTGER)) {
		 	lastok = insertstr((yyvsp[0].qp)->next, ")");
			(yyvsp[0].qp) = insertstr((yyvsp[0].qp), "((int)");
		 }
		}
#line 3099 "parse1.c" /* yacc.c:1646  */
    break;

  case 184:
#line 602 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);}
#line 3105 "parse1.c" /* yacc.c:1646  */
    break;

  case 185:
#line 603 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);}
#line 3111 "parse1.c" /* yacc.c:1646  */
    break;

  case 190:
#line 608 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal integer expression");}
#line 3117 "parse1.c" /* yacc.c:1646  */
    break;

  case 194:
#line 613 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 3123 "parse1.c" /* yacc.c:1646  */
    break;

  case 199:
#line 619 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = insertstr((yyvsp[-2].qp), "pow("); replacstr((yyvsp[-1].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
#line 3130 "parse1.c" /* yacc.c:1646  */
    break;

  case 200:
#line 621 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " ||");}
#line 3136 "parse1.c" /* yacc.c:1646  */
    break;

  case 201:
#line 622 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " &&");}
#line 3142 "parse1.c" /* yacc.c:1646  */
    break;

  case 206:
#line 627 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " ==");}
#line 3148 "parse1.c" /* yacc.c:1646  */
    break;

  case 207:
#line 628 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " !=");}
#line 3154 "parse1.c" /* yacc.c:1646  */
    break;

  case 208:
#line 629 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {replacstr((yyvsp[-1].qp), " !");}
#line 3160 "parse1.c" /* yacc.c:1646  */
    break;

  case 210:
#line 631 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal expression");}
#line 3166 "parse1.c" /* yacc.c:1646  */
    break;

  case 211:
#line 633 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inequation = 1; nstate = 0;}
#line 3172 "parse1.c" /* yacc.c:1646  */
    break;

  case 212:
#line 637 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {inequation = 1; nstate = 0;
		pstate = 0; tstate = 0; init_lineq((yyvsp[0].qp)); leftside = -1;}
#line 3179 "parse1.c" /* yacc.c:1646  */
    break;

  case 213:
#line 640 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {leftside = 1;}
#line 3185 "parse1.c" /* yacc.c:1646  */
    break;

  case 214:
#line 644 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {linterm((yyvsp[0].qp), lastok, pstate, leftside); pstate = 0;}
#line 3191 "parse1.c" /* yacc.c:1646  */
    break;

  case 215:
#line 646 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, -leftside); pstate = 0;}
#line 3198 "parse1.c" /* yacc.c:1646  */
    break;

  case 216:
#line 649 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, leftside); pstate = 0;}
#line 3205 "parse1.c" /* yacc.c:1646  */
    break;

  case 217:
#line 652 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));
		linterm((yyvsp[0].qp), lastok, pstate, -leftside); pstate = 0;}
#line 3212 "parse1.c" /* yacc.c:1646  */
    break;

  case 218:
#line 656 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (tstate == 1) {
			lin_state_term((yyvsp[0].qp), lastok);
		  }
		  tstate = 0;
		}
#line 3222 "parse1.c" /* yacc.c:1646  */
    break;

  case 219:
#line 662 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (tstate == 1) {
			lin_state_term((yyvsp[0].qp), lastok);
		  }
		  tstate = 0;
		}
#line 3232 "parse1.c" /* yacc.c:1646  */
    break;

  case 220:
#line 668 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (tstate) {
			diag("state ocurs in denominator", (char *)0);
		  }
		}
#line 3241 "parse1.c" /* yacc.c:1646  */
    break;

  case 223:
#line 675 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {if (tstate) diag("states not permitted in function calls",
			(char *)0);}
#line 3248 "parse1.c" /* yacc.c:1646  */
    break;

  case 224:
#line 677 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { lastok = (yyvsp[0].qp);
			if (tstate) diag("states not permitted between ",
				"parentheses");}
#line 3256 "parse1.c" /* yacc.c:1646  */
    break;

  case 225:
#line 681 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {diag("Some operators are not permitted in linear\n",
"expressions unless the terms containing them are\nenclosed in parentheses");}
#line 3263 "parse1.c" /* yacc.c:1646  */
    break;

  case 226:
#line 685 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (SYM((yyvsp[-1].qp))->subtype & EXTDEF2) { extdef2 = 1;}}
#line 3269 "parse1.c" /* yacc.c:1646  */
    break;

  case 227:
#line 687 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp); SYM((yyvsp[-4].qp))->usage |= FUNCT;
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF2) { extdef2 = 0;}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF3) { add_reset_args((yyvsp[-3].qp));}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF4) { add_nrnthread_arg((yyvsp[-3].qp));}
		 if (SYM((yyvsp[-4].qp))->subtype & EXTDEF5) {
			if (!assert_threadsafe) {
fprintf(stderr, "Notice: %s is not thread safe\n", SYM((yyvsp[-4].qp))->name);
				vectorize = 0;
			}
		 }
#if VECTORIZE
		 vectorize_use_func((yyvsp[-4].qp),(yyvsp[-3].qp),(yyvsp[-1].qp),(yyvsp[0].qp),blocktype);
#endif
		}
#line 3288 "parse1.c" /* yacc.c:1646  */
    break;

  case 228:
#line 702 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 3294 "parse1.c" /* yacc.c:1646  */
    break;

  case 233:
#line 708 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[0].qp)) = copylocal(SYM((yyvsp[0].qp)));
			SYM((yyvsp[0].qp))->subtype |= INTGER;}
#line 3301 "parse1.c" /* yacc.c:1646  */
    break;

  case 234:
#line 712 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-9].qp), "{int ");
		poplocal();
		Insertstr((yyvsp[-6].qp), ";for (");
		Insertstr((yyvsp[-6].qp), SYM((yyvsp[-8].qp))->name);
		Insertstr((yyvsp[-4].qp), ";");
		Insertstr((yyvsp[-4].qp), SYM((yyvsp[-8].qp))->name);
		replacstr((yyvsp[-4].qp), "<=");
		if ((yyvsp[-2].qp)) {
			Insertstr((yyvsp[-2].qp), ";");
			Insertstr((yyvsp[-2].qp), SYM((yyvsp[-8].qp))->name);
			replacstr((yyvsp[-2].qp), "+=");
		} else {
			Insertstr((yyvsp[-1].qp), ";");
			Insertstr((yyvsp[-1].qp), SYM((yyvsp[-8].qp))->name);
			Insertstr((yyvsp[-1].qp), "++");
		}
		Insertstr((yyvsp[-1].qp), ")");
		Insertstr((yyvsp[0].qp), "}");
		}
#line 3325 "parse1.c" /* yacc.c:1646  */
    break;

  case 235:
#line 731 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
myerr("FROM intvar = intexpr TO intexpr BY intexpr { statements }");}
#line 3332 "parse1.c" /* yacc.c:1646  */
    break;

  case 236:
#line 734 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 3338 "parse1.c" /* yacc.c:1646  */
    break;

  case 238:
#line 737 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[0].qp)) = copylocal(SYM((yyvsp[0].qp)));
			  SYM((yyvsp[0].qp))->subtype |= INTGER;
			  if (forallindex) {
diag("Nested FORALL statements not allowed", (char *)0);
			  }
			  forallindex = -1;
			}
#line 3350 "parse1.c" /* yacc.c:1646  */
    break;

  case 239:
#line 746 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { replacstr((yyvsp[-4].qp), "{int ");
		poplocal();
		if (forallindex == -1) {
diag("FORALL range is undefined since no arrays used", " within the statement");
		}
		Sprintf(buf, "; for (%s=0; %s<%d; %s++)", SYM((yyvsp[-3].qp))->name,
			SYM((yyvsp[-3].qp))->name, forallindex, SYM((yyvsp[-3].qp))->name);
		Insertstr((yyvsp[-1].qp), buf);
		Insertstr((yyvsp[0].qp), "}");
		}
#line 3365 "parse1.c" /* yacc.c:1646  */
    break;

  case 240:
#line 756 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
myerr("FORALL intvar { statements }");}
#line 3372 "parse1.c" /* yacc.c:1646  */
    break;

  case 244:
#line 765 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
#line 3382 "parse1.c" /* yacc.c:1646  */
    break;

  case 246:
#line 773 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
#if VECTORIZE
			vectorize_if_else_stmt(blocktype);
#endif
		}
#line 3392 "parse1.c" /* yacc.c:1646  */
    break;

  case 247:
#line 781 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagederiv((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused); sensused = 0;}
#line 3398 "parse1.c" /* yacc.c:1646  */
    break;

  case 248:
#line 783 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {init_linblk((yyvsp[-1].qp));}
#line 3404 "parse1.c" /* yacc.c:1646  */
    break;

  case 249:
#line 785 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massage_linblk((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3412 "parse1.c" /* yacc.c:1646  */
    break;

  case 250:
#line 791 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagenonlin((yyvsp[-4].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3420 "parse1.c" /* yacc.c:1646  */
    break;

  case 251:
#line 797 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagediscblk((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3426 "parse1.c" /* yacc.c:1646  */
    break;

  case 252:
#line 801 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagepartial((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[-1].qp), (yyvsp[0].qp));
		lexcontext = 0;
		}
#line 3434 "parse1.c" /* yacc.c:1646  */
    break;

  case 253:
#line 804 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
diag("within the PARTIAL block must occur an equation with the syntax ---\n",
"~ V' = F*DEL2(V) + G\n"); }
#line 3442 "parse1.c" /* yacc.c:1646  */
    break;

  case 254:
#line 809 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {partial_eqn((yyvsp[-9].qp), (yyvsp[-7].qp), (yyvsp[-3].qp), (yyvsp[0].qp));}
#line 3448 "parse1.c" /* yacc.c:1646  */
    break;

  case 255:
#line 811 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {partial_bndry(0, (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[0].qp), lastok);}
#line 3454 "parse1.c" /* yacc.c:1646  */
    break;

  case 256:
#line 813 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {partial_bndry(2, (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[0].qp), lastok);}
#line 3460 "parse1.c" /* yacc.c:1646  */
    break;

  case 259:
#line 818 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {Item *b1, *b2;
		Symbol* s = SYM((yyvsp[-4].qp));
		s->varnum = argcnt_;
		b1 = insertstr((yyvsp[-1].qp)->next, "{\n");
		b2 = insertstr(b1->next, "}\n");

#define GLOBFUNCT 1
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[-5].qp), "\ndouble");
#else
		replacstr((yyvsp[-5].qp), "\nstatic double");
#endif
		defarg((yyvsp[-3].qp), (yyvsp[-1].qp));
		movelist((yyvsp[-5].qp), b2, procfunc);
		if (SYM((yyvsp[-4].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[-4].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[-4].qp))->subtype |= FUNCT;
		SYM((yyvsp[-4].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-3].qp), (yyvsp[-1].qp));
#endif
		function_table(s, (yyvsp[-3].qp), (yyvsp[-1].qp), b1, b2);
		poplocal();
		}
#line 3490 "parse1.c" /* yacc.c:1646  */
    break;

  case 260:
#line 845 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {IGNORE(copylocal(SYM((yyvsp[-4].qp))));}
#line 3496 "parse1.c" /* yacc.c:1646  */
    break;

  case 261:
#line 849 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Symbol *s = SYM((yyvsp[-7].qp));
		s->varnum = argcnt_;
		table_massage(table_list, (yyvsp[-8].qp), (yyvsp[-7].qp), (yyvsp[-5].lp)); freelist(&table_list);
#if GLOBFUNCT && NMODL
		replacstr((yyvsp[-8].qp), "\ndouble");
#else
		replacstr((yyvsp[-8].qp), "\nstatic double");
#endif
		defarg((yyvsp[-6].qp), (yyvsp[-4].qp));
		Sprintf(buf, "double _l%s;\n", s->name);
		Insertstr((yyvsp[-1].qp)->next, buf);
		Sprintf(buf, "\nreturn _l%s;\n", s->name);
		Insertstr((yyvsp[0].qp), buf);
		movelist((yyvsp[-8].qp), (yyvsp[0].qp), procfunc);
		if (SYM((yyvsp[-7].qp))->subtype & FUNCT) {
			diag(SYM((yyvsp[-7].qp))->name, " declared as FUNCTION twice");
		}
		SYM((yyvsp[-7].qp))->subtype |= FUNCT;
		SYM((yyvsp[-7].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-6].qp), (yyvsp[-4].qp));
#endif
		poplocal(); freelist(&(yyvsp[-5].lp));}
#line 3524 "parse1.c" /* yacc.c:1646  */
    break;

  case 262:
#line 873 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal(); (yyval.lp) = LIST0; argcnt_ = 0;}
#line 3530 "parse1.c" /* yacc.c:1646  */
    break;

  case 263:
#line 874 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal();}
#line 3536 "parse1.c" /* yacc.c:1646  */
    break;

  case 264:
#line 874 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = (yyvsp[0].lp);}
#line 3542 "parse1.c" /* yacc.c:1646  */
    break;

  case 265:
#line 877 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp))); argcnt_ = 1;
		 (yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[-1].qp)));
		}
#line 3550 "parse1.c" /* yacc.c:1646  */
    break;

  case 266:
#line 881 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp))); Lappendsym((yyval.lp), SYM((yyvsp[-1].qp)));
		 ++argcnt_;
		}
#line 3558 "parse1.c" /* yacc.c:1646  */
    break;

  case 267:
#line 886 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {Symbol *s = SYM((yyvsp[-6].qp));
		s->u.i = 0; 	/* avoid objectcenter warning if solved */
		s->varnum = argcnt_; /* allow proper number of "double" in prototype */
		table_massage(table_list, (yyvsp[-7].qp), (yyvsp[-6].qp), (yyvsp[-4].lp)); freelist(&table_list);
		replacstr((yyvsp[-7].qp), "\nstatic int "); defarg((yyvsp[-5].qp), (yyvsp[-3].qp));
		Insertstr((yyvsp[0].qp), " return 0;");
		movelist((yyvsp[-7].qp), (yyvsp[0].qp), procfunc);
		if (SYM((yyvsp[-6].qp))->subtype & PROCED) {
			diag(SYM((yyvsp[-6].qp))->name, " declared as PROCEDURE twice");
		}
		SYM((yyvsp[-6].qp))->subtype |= PROCED;
		SYM((yyvsp[-6].qp))->usage |= FUNCT;
#if HMODL || NMODL
		hocfunc(s, (yyvsp[-5].qp), (yyvsp[-3].qp));
#endif
		poplocal(); freelist(&(yyvsp[-4].lp));}
#line 3579 "parse1.c" /* yacc.c:1646  */
    break;

  case 268:
#line 904 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
			nr_argcnt_ = argcnt_;
			/* add flag arg */
			if ((yyvsp[-1].lp) == LIST0) {
diag("NET_RECEIVE block"," must have at least one argument");
			}
			Lappendsym((yyvsp[-1].lp), copylocal(install("flag", NAME)));
		}
#line 3592 "parse1.c" /* yacc.c:1646  */
    break;

  case 269:
#line 913 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
		replacstr((yyvsp[-6].qp), "\nstatic void _net_receive");
		movelist((yyvsp[-6].qp), (yyvsp[0].qp), procfunc);
#if NMODL
		net_receive((yyvsp[-4].lp), (yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp));
#endif
		poplocal(); freelist(&(yyvsp[-4].lp));
		}
#line 3605 "parse1.c" /* yacc.c:1646  */
    break;

  case 270:
#line 921 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { myerr("syntax: NET_RECEIVE ( weight ) {stmtlist}");}
#line 3611 "parse1.c" /* yacc.c:1646  */
    break;

  case 271:
#line 924 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
			check_block(NETRECEIVE, blocktype, "INITIAL");
#if NMODL
			net_init((yyvsp[-2].qp), (yyvsp[0].qp));
#endif
		}
#line 3622 "parse1.c" /* yacc.c:1646  */
    break;

  case 272:
#line 933 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { solvequeue((yyvsp[-1].qp), ITEM0, blocktype, (yyvsp[0].qp)); }
#line 3628 "parse1.c" /* yacc.c:1646  */
    break;

  case 273:
#line 935 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { solvequeue((yyvsp[-3].qp), (yyvsp[-1].qp), blocktype, (yyvsp[0].qp)); }
#line 3634 "parse1.c" /* yacc.c:1646  */
    break;

  case 274:
#line 936 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { myerr("Illegal SOLVE statement");}
#line 3640 "parse1.c" /* yacc.c:1646  */
    break;

  case 275:
#line 939 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = ITEM0; }
#line 3646 "parse1.c" /* yacc.c:1646  */
    break;

  case 276:
#line 941 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = (yyvsp[0].qp); }
#line 3652 "parse1.c" /* yacc.c:1646  */
    break;

  case 277:
#line 944 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { if (solveforlist) {
			freelist(&solveforlist);
		  }
		}
#line 3661 "parse1.c" /* yacc.c:1646  */
    break;

  case 279:
#line 951 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { solveforlist = newlist(); Lappendsym(solveforlist, SYM((yyvsp[0].qp)));
		  delete((yyvsp[-1].qp)); delete((yyvsp[0].qp));
		}
#line 3669 "parse1.c" /* yacc.c:1646  */
    break;

  case 280:
#line 955 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Lappendsym(solveforlist, SYM((yyvsp[0].qp))); delete((yyvsp[-1].qp)); delete((yyvsp[0].qp));}
#line 3675 "parse1.c" /* yacc.c:1646  */
    break;

  case 281:
#line 956 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { myerr("Syntax: SOLVEFOR name, name, ...");}
#line 3681 "parse1.c" /* yacc.c:1646  */
    break;

  case 282:
#line 960 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {brkpnt_exists = 1; movelist((yyvsp[-1].qp), (yyvsp[0].qp), modelfunc);}
#line 3687 "parse1.c" /* yacc.c:1646  */
    break;

  case 283:
#line 963 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {movelist((yyvsp[-1].qp), (yyvsp[0].qp), termfunc);}
#line 3693 "parse1.c" /* yacc.c:1646  */
    break;

  case 284:
#line 966 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, BREAKPOINT, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3699 "parse1.c" /* yacc.c:1646  */
    break;

  case 285:
#line 968 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, SOLVE, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3705 "parse1.c" /* yacc.c:1646  */
    break;

  case 286:
#line 970 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, INITIAL1, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3711 "parse1.c" /* yacc.c:1646  */
    break;

  case 287:
#line 972 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {bablk(blocktype, STEP, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3717 "parse1.c" /* yacc.c:1646  */
    break;

  case 288:
#line 973 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("[BEFORE AFTER] [BREAKPOINT SOLVE INITIAL STEP] { stmt }");}
#line 3723 "parse1.c" /* yacc.c:1646  */
    break;

  case 289:
#line 976 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp); delete((yyvsp[-1].qp));}
#line 3729 "parse1.c" /* yacc.c:1646  */
    break;

  case 290:
#line 978 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {delete((yyvsp[-1].qp));}
#line 3735 "parse1.c" /* yacc.c:1646  */
    break;

  case 291:
#line 979 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("WATCH (expr > expr) flag");}
#line 3741 "parse1.c" /* yacc.c:1646  */
    break;

  case 292:
#line 982 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {watchstmt((yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), blocktype); (yyval.qp)=(yyvsp[0].qp);}
#line 3747 "parse1.c" /* yacc.c:1646  */
    break;

  case 295:
#line 987 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {
			if (blocktype != NETRECEIVE) {
				diag("\"FOR_NETCONS\" statement only allowed in NET_RECEIVE block", (char*)0);
			}
			if (argcnt_ != nr_argcnt_) {
				diag("FOR_NETCONS and NET_RECEIVE do not have same number of arguments", (char*)0);
			}
		}
#line 3760 "parse1.c" /* yacc.c:1646  */
    break;

  case 296:
#line 996 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {fornetcon((yyvsp[-6].qp), (yyvsp[-5].qp), (yyvsp[-4].lp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp)); (yyval.qp) = (yyvsp[0].qp); }
#line 3766 "parse1.c" /* yacc.c:1646  */
    break;

  case 297:
#line 997 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { myerr("syntax: FOR_NETCONS(args,like,netreceive) { stmtlist}");}
#line 3772 "parse1.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1002 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lastok = (yyvsp[0].qp);}
#line 3778 "parse1.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1008 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { (yyval.qp) = insertstr((yyvsp[-2].qp), "pow("); replacstr((yyvsp[-1].qp), ",");
			lastok = insertstr(lastok->next, ")"); }
#line 3785 "parse1.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1011 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal expression");}
#line 3791 "parse1.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1016 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { sensused = 1;
		  delete((yyvsp[-1].qp));
		}
#line 3799 "parse1.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1019 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("syntax is SENS var1, var2, var3, etc");}
#line 3805 "parse1.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1023 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { sensparm((yyvsp[0].qp)); delete((yyvsp[0].qp));}
#line 3811 "parse1.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1025 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { sensparm((yyvsp[0].qp)); deltokens((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3817 "parse1.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1028 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {extdef2 = 0; }
#line 3823 "parse1.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1029 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {/* react originally designed for reactions and is unchanged*/
		extdef2 = 0;
		massageconserve((yyvsp[-4].qp), (yyvsp[-1].qp), lastok);}
#line 3831 "parse1.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1032 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal CONSERVE syntax");}
#line 3837 "parse1.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1035 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));}
#line 3843 "parse1.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1037 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagecompart((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM((yyvsp[-6].qp))); poplocal();}
#line 3849 "parse1.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1039 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagecompart((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM0);}
#line 3855 "parse1.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1042 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {pushlocal(); SYM((yyvsp[-1].qp)) = copylocal(SYM((yyvsp[-1].qp)));}
#line 3861 "parse1.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1044 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massageldifus((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM((yyvsp[-6].qp))); poplocal();}
#line 3867 "parse1.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1046 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massageldifus((yyvsp[-3].qp), (yyvsp[-2].qp), (yyvsp[0].qp), SYM0);}
#line 3873 "parse1.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1054 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagekinetic((yyvsp[-4].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp), sensused);
		lexcontext = 0; sensused = 0;
		}
#line 3881 "parse1.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1058 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {leftreact();}
#line 3887 "parse1.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1059 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {massagereaction((yyvsp[-9].qp),(yyvsp[-7].qp),(yyvsp[-4].qp),(yyvsp[-2].qp),(yyvsp[0].qp));}
#line 3893 "parse1.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1061 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {flux((yyvsp[-6].qp), (yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3899 "parse1.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1063 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {flux((yyvsp[-6].qp), (yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3905 "parse1.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1064 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Illegal reaction syntax");}
#line 3911 "parse1.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1066 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, ITEM0);}
#line 3917 "parse1.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1067 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, (yyvsp[-1].qp));}
#line 3923 "parse1.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1068 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, ITEM0);}
#line 3929 "parse1.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1069 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {reactname((yyvsp[0].qp), lastok, (yyvsp[-1].qp));}
#line 3935 "parse1.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1072 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {lag_stmt((yyvsp[-3].qp), blocktype);}
#line 3941 "parse1.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1073 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Lag syntax is: LAG name BY const");}
#line 3947 "parse1.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1075 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {queue_stmt((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3953 "parse1.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1076 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {queue_stmt((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 3959 "parse1.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1078 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {checkmatch(blocktype);}
#line 3965 "parse1.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1079 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {deltokens((yyvsp[-4].qp), (yyvsp[0].qp));}
#line 3971 "parse1.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1085 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {matchinitial((yyvsp[0].qp));}
#line 3977 "parse1.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1087 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { matchbound((yyvsp[-5].qp), (yyvsp[-4].qp), (yyvsp[-2].qp), (yyvsp[0].qp), lastok, matchindex);
		  if (matchindex) {
			poplocal();
			matchindex = SYM0;
		  }
		}
#line 3988 "parse1.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1094 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("MATCH syntax is state0 or state(expr)=expr or\
state[i](expr(i)) = expr(i)");}
#line 3995 "parse1.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1098 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {matchindex = SYM0;}
#line 4001 "parse1.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1100 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { pushlocal();
		  matchindex = copylocal(SYM((yyvsp[-1].qp)));
		}
#line 4009 "parse1.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1105 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { deltokens((yyvsp[-3].qp),(yyvsp[0].qp));}
#line 4015 "parse1.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1108 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {modl_units();}
#line 4021 "parse1.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1113 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {install_units((yyvsp[-2].str), (yyvsp[0].str));}
#line 4027 "parse1.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1114 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Unit definition syntax: (units) = (units)");}
#line 4033 "parse1.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1117 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[-3].qp))->name,
			STR((yyvsp[-1].qp)));
		  Lappendstr(firstlist, buf);
		}
#line 4043 "parse1.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1123 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {Item *q; double d, unit_mag();
		    Unit_push((yyvsp[-1].str));
			Unit_push((yyvsp[0].str)); unit_div();
		    SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
#if defined(LegacyFR) && LegacyFR == 1
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[-3].qp))->name,
#else
		    Sprintf(buf, "static double %s = %.12g;\n", SYM((yyvsp[-3].qp))->name,
#endif
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
#line 4061 "parse1.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1137 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { double unit_mag();
		    Unit_push((yyvsp[-3].str)); Unit_push((yyvsp[0].str)); unit_div();
		    SYM((yyvsp[-5].qp))->subtype |= nmodlCONST;
		    Sprintf(buf, "static double %s = %g;\n", SYM((yyvsp[-5].qp))->name,
			unit_mag());
		    Lappendstr(firstlist, buf);
		    unit_pop();
		}
#line 4074 "parse1.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1145 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("Unit factor syntax: examples:\n\
foot2inch = (foot) -> (inch)\n\
F = 96520 (coulomb)\n\
R = (k-mole) (joule/degC)");
		}
#line 4084 "parse1.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1155 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { SYM((yyvsp[-3].qp))->subtype |= nmodlCONST;
		  Sprintf(buf, "static double %s = %s;\n", SYM((yyvsp[-3].qp))->name,
			STR((yyvsp[-1].qp)));
		  Lappendstr(firstlist, buf);
		}
#line 4094 "parse1.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1162 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Item *q;
		  if (table_list) {
			diag("only one TABLE per function", (char *)0);
		  }
		  table_list = newlist();
		  Lappendlst(table_list, (yyvsp[-7].lp));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[-5].qp)->next, (yyvsp[-3].qp)->prev, LST(q));
		  q = lappendlst(table_list, newlist());
		  movelist((yyvsp[-3].qp)->next, (yyvsp[-1].qp)->prev, LST(q));
		  Lappendstr(table_list, STR((yyvsp[0].qp)));
		  Lappendlst(table_list, (yyvsp[-6].lp));
		  deltokens((yyvsp[-8].qp), (yyvsp[0].qp));
		}
#line 4113 "parse1.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1176 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { myerr("syntax: TABLE [list] [DEPEND list] FROM expr TO expr WITH integer");}
#line 4119 "parse1.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1179 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = LIST0;}
#line 4125 "parse1.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1183 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = newlist(); Lappendsym((yyval.lp), SYM((yyvsp[0].qp)));}
#line 4131 "parse1.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1185 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Lappendsym((yyvsp[-2].lp), SYM((yyvsp[0].qp)));}
#line 4137 "parse1.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1188 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = LIST0;}
#line 4143 "parse1.c" /* yacc.c:1646  */
    break;

  case 367:
#line 1190 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.lp) = (yyvsp[0].lp);}
#line 4149 "parse1.c" /* yacc.c:1646  */
    break;

  case 368:
#line 1193 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { deltokens((yyvsp[-3].qp),(yyvsp[0].qp));}
#line 4155 "parse1.c" /* yacc.c:1646  */
    break;

  case 370:
#line 1197 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4161 "parse1.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1200 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp),(yyvsp[0].qp));}
#line 4167 "parse1.c" /* yacc.c:1646  */
    break;

  case 373:
#line 1202 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp),(yyvsp[0].qp));}
#line 4173 "parse1.c" /* yacc.c:1646  */
    break;

  case 374:
#line 1204 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4179 "parse1.c" /* yacc.c:1646  */
    break;

  case 375:
#line 1206 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4185 "parse1.c" /* yacc.c:1646  */
    break;

  case 376:
#line 1208 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4191 "parse1.c" /* yacc.c:1646  */
    break;

  case 377:
#line 1210 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4197 "parse1.c" /* yacc.c:1646  */
    break;

  case 378:
#line 1212 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4203 "parse1.c" /* yacc.c:1646  */
    break;

  case 379:
#line 1214 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { nrn_list((yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4209 "parse1.c" /* yacc.c:1646  */
    break;

  case 380:
#line 1216 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { threadsafe_seen((yyvsp[-1].qp), (yyvsp[0].qp)); }
#line 4215 "parse1.c" /* yacc.c:1646  */
    break;

  case 381:
#line 1219 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-3].qp), (yyvsp[-1].qp), ITEM0, (yyvsp[0].qp));}
#line 4221 "parse1.c" /* yacc.c:1646  */
    break;

  case 382:
#line 1221 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-3].qp), ITEM0, (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4227 "parse1.c" /* yacc.c:1646  */
    break;

  case 383:
#line 1223 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {nrn_use((yyvsp[-5].qp), (yyvsp[-3].qp), (yyvsp[-1].qp), (yyvsp[0].qp));}
#line 4233 "parse1.c" /* yacc.c:1646  */
    break;

  case 384:
#line 1225 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("syntax is: USEION ion READ list WRITE list");}
#line 4239 "parse1.c" /* yacc.c:1646  */
    break;

  case 386:
#line 1229 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { delete((yyvsp[-1].qp)); (yyval.qp) = (yyvsp[0].qp);}
#line 4245 "parse1.c" /* yacc.c:1646  */
    break;

  case 387:
#line 1231 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {myerr("syntax is: keyword name , name, ..., name");}
#line 4251 "parse1.c" /* yacc.c:1646  */
    break;

  case 388:
#line 1234 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = NULL;}
#line 4257 "parse1.c" /* yacc.c:1646  */
    break;

  case 390:
#line 1238 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = ITEM0;}
#line 4263 "parse1.c" /* yacc.c:1646  */
    break;

  case 391:
#line 1240 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    {(yyval.qp) = (yyvsp[0].qp);}
#line 4269 "parse1.c" /* yacc.c:1646  */
    break;

  case 392:
#line 1243 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1646  */
    { Sprintf(buf, "-%s", STR((yyvsp[0].qp)));
		 STR((yyvsp[0].qp)) = stralloc(buf, STR((yyvsp[0].qp))); (yyval.qp) = (yyvsp[0].qp);
		delete((yyvsp[-1].qp)); lastok = (yyvsp[0].qp);
		}
#line 4278 "parse1.c" /* yacc.c:1646  */
    break;


#line 4282 "parse1.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1248 "../../../nrn/src/nmodl/parse1.y" /* yacc.c:1906  */

void yyerror(s)	/* called for yacc syntax error */
	char *s;
{
	Fprintf(stderr, "%s:\n ", s);
}


#if !NMODL
void nrn_list(q1, q2)
	Item *q1, *q2;
{
	/*ARGSUSED*/
}
void nrn_use(q1, q2, q3, q4)
	Item *q1, *q2, *q3, *q4;
{
	/*ARGSUSED*/
}
#endif
