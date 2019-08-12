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
#line 2 "../../../nrn/src/oc/parse.y" /* yacc.c:339  */


#include <../../nrnconf.h>
/* changes as of 2-jan-89 */
/*  version 7.2.1 2-jan-89 short form of the for statement */

#if AIX
#pragma alloca
#endif

#include "hoc.h"
#include "ocmisc.h"
#include "hocparse.h"
#include "code.h"
#include "equation.h"
#include "nrnfilewrap.h"

void* nrn_parsing_pysec_;

#if LINT
Inst *inlint;
#define code	inlint = Code
#else
#define code	Code
#endif

#define paction(arg) fprintf(stderr, "%s\n", arg)

/* maintain a list of ierr addresses so we can clear them */
#define HOCERRSIZE 20
static int** hoc_err;
static int hoc_errp;
static int localcnt;

static void clean_err(void) {
	int i;
	for (i=0; i < hoc_errp; ++i) {
		*hoc_err[i] = 0;
	}
	hoc_errp = 0;
}

static void pusherr(int* ip) {
	if (!hoc_err) {
		hoc_err = (int**)ecalloc(HOCERRSIZE, sizeof(int*));
		hoc_errp = 0;
	}
	if (hoc_errp >= HOCERRSIZE) {
		clean_err();
		hoc_execerror("error stack full", (char*)0);
	}
	hoc_err[hoc_errp++] = ip;
}

static void yyerror(const char* s);

#if YYBISON
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} --yyssp; --yyvsp; YYERROR
#else
#define myerr(arg) static int ierr=0;\
if (!(ierr++)){pusherr(&ierr);yyerror(arg);} YYERROR
#endif

#define code2(c1,c2)	code(c1); codein(c2)
#define code3(c1,c2,c3)	code(c1); codesym(c2); code(c3)
#define relative(ip1,ip2,offset)	((ip1-ip2) - offset)
#define CHECK 1	/* check syntactically the consistency of arrays */
#define NOCHECK 0 /* don't check syntactically. For object components */
#define PN pushi(NUMBER)	/* for type checking. expressions are usually numbers */
#define TPD hoc_ob_check(NUMBER);
#define TPDYNAM hoc_ob_check(0);

static Inst *prog_error;			/* needed for stmtlist loc if error */
static int ntab;			/* auto indentation */

static Inst* argrefcode(Pfrv pfrv, int i, int j);
static Inst* argcode(Pfrv pfrv, int i);
static void hoc_opasgn_invalid(int op);
 

#line 148 "parse.c" /* yacc.c:339  */

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
    EQNEQ = 258,
    NUMBER = 259,
    STRING = 260,
    PRINT = 261,
    parseDELETE = 262,
    VAR = 263,
    BLTIN = 264,
    UNDEF = 265,
    WHILE = 266,
    IF = 267,
    ELSE = 268,
    FOR = 269,
    FUNCTION = 270,
    PROCEDURE = 271,
    RETURN = 272,
    FUNC = 273,
    parsePROC = 274,
    HOCOBJFUNC = 275,
    READ = 276,
    parseDOUBLE = 277,
    DEBUG = 278,
    EDIT = 279,
    FUN_BLTIN = 280,
    DEPENDENT = 281,
    EQUATION = 282,
    LOCAL = 283,
    HOCOBJFUNCTION = 284,
    BREAK = 285,
    CONTINUE = 286,
    AUTO = 287,
    STRDEF = 288,
    STOPSTMT = 289,
    CSTRING = 290,
    PARALLEL = 291,
    HELP = 292,
    ITERATOR = 293,
    ITERKEYWORD = 294,
    ITERSTMT = 295,
    STRINGFUNC = 296,
    OBJECTFUNC = 297,
    LOCALOBJ = 298,
    AUTOOBJ = 299,
    ARG = 300,
    NUMZERO = 301,
    ARGREF = 302,
    INTERNALSECTIONNAME = 303,
    PYSEC = 304,
    PYSECNAME = 305,
    PYSECOBJ = 306,
    SECTIONKEYWORD = 307,
    SECTION = 308,
    CONNECTKEYWORD = 309,
    ACCESSKEYWORD = 310,
    RANGEVAR = 311,
    MECHANISM = 312,
    INSERTKEYWORD = 313,
    FORALL = 314,
    NRNPNTVAR = 315,
    FORSEC = 316,
    IFSEC = 317,
    UNINSERTKEYWORD = 318,
    SETPOINTERKEYWORD = 319,
    SECTIONREF = 320,
    BEGINTEMPLATE = 321,
    ENDTEMPLATE = 322,
    NEW = 323,
    OBJECTVAR = 324,
    TEMPLATE = 325,
    OBJVARDECL = 326,
    PUBLICDECL = 327,
    EXTERNALDECL = 328,
    OBFUNCTION = 329,
    STRFUNCTION = 330,
    OBJECTARG = 331,
    STRINGARG = 332,
    ROP = 333,
    OR = 334,
    AND = 335,
    GT = 336,
    GE = 337,
    LT = 338,
    LE = 339,
    EQ = 340,
    NE = 341,
    UNARYMINUS = 342,
    NOT = 343
  };
#endif
/* Tokens.  */
#define EQNEQ 258
#define NUMBER 259
#define STRING 260
#define PRINT 261
#define parseDELETE 262
#define VAR 263
#define BLTIN 264
#define UNDEF 265
#define WHILE 266
#define IF 267
#define ELSE 268
#define FOR 269
#define FUNCTION 270
#define PROCEDURE 271
#define RETURN 272
#define FUNC 273
#define parsePROC 274
#define HOCOBJFUNC 275
#define READ 276
#define parseDOUBLE 277
#define DEBUG 278
#define EDIT 279
#define FUN_BLTIN 280
#define DEPENDENT 281
#define EQUATION 282
#define LOCAL 283
#define HOCOBJFUNCTION 284
#define BREAK 285
#define CONTINUE 286
#define AUTO 287
#define STRDEF 288
#define STOPSTMT 289
#define CSTRING 290
#define PARALLEL 291
#define HELP 292
#define ITERATOR 293
#define ITERKEYWORD 294
#define ITERSTMT 295
#define STRINGFUNC 296
#define OBJECTFUNC 297
#define LOCALOBJ 298
#define AUTOOBJ 299
#define ARG 300
#define NUMZERO 301
#define ARGREF 302
#define INTERNALSECTIONNAME 303
#define PYSEC 304
#define PYSECNAME 305
#define PYSECOBJ 306
#define SECTIONKEYWORD 307
#define SECTION 308
#define CONNECTKEYWORD 309
#define ACCESSKEYWORD 310
#define RANGEVAR 311
#define MECHANISM 312
#define INSERTKEYWORD 313
#define FORALL 314
#define NRNPNTVAR 315
#define FORSEC 316
#define IFSEC 317
#define UNINSERTKEYWORD 318
#define SETPOINTERKEYWORD 319
#define SECTIONREF 320
#define BEGINTEMPLATE 321
#define ENDTEMPLATE 322
#define NEW 323
#define OBJECTVAR 324
#define TEMPLATE 325
#define OBJVARDECL 326
#define PUBLICDECL 327
#define EXTERNALDECL 328
#define OBFUNCTION 329
#define STRFUNCTION 330
#define OBJECTARG 331
#define STRINGARG 332
#define ROP 333
#define OR 334
#define AND 335
#define GT 336
#define GE 337
#define LT 338
#define LE 339
#define EQ 340
#define NE 341
#define UNARYMINUS 342
#define NOT 343

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 84 "../../../nrn/src/oc/parse.y" /* yacc.c:355  */
				/* stack type */
	Symbol	*sym;			/* symbol table pointer */
	Inst	*inst;			/* machine instruction */
	int	narg;			/* number of arguments */
	void*	ptr;

#line 371 "parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 388 "parse.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2903

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  108
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  553

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      96,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    92,   107,     2,
      97,    98,    90,    88,   102,    89,   101,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   105,   106,
       2,    79,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    99,     2,   100,    95,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   103,     2,   104,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    80,    81,    82,    83,    84,    85,
      86,    87,    93,    94
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   141,   141,   142,   143,   144,   146,   148,   150,   152,
     154,   158,   164,   164,   165,   175,   179,   181,   184,   188,
     194,   200,   204,   204,   206,   208,   210,   212,   215,   220,
     223,   224,   224,   234,   237,   238,   241,   242,   243,   244,
     245,   247,   250,   252,   254,   256,   259,   269,   271,   274,
     276,   281,   283,   288,   290,   293,   294,   296,   300,   302,
     306,   308,   310,   323,   325,   326,   328,   330,   331,   333,
     335,   337,   346,   350,   356,   358,   360,   362,   364,   366,
     371,   382,   386,   381,   393,   397,   392,   405,   409,   413,
     419,   418,   424,   427,   428,   430,   432,   434,   434,   437,
     439,   441,   443,   445,   447,   450,   454,   459,   458,   467,
     470,   466,   476,   475,   483,   482,   489,   488,   495,   494,
     502,   501,   513,   518,   518,   524,   524,   526,   531,   539,
     543,   544,   548,   549,   549,   559,   561,   563,   565,   568,
     576,   578,   580,   580,   583,   585,   587,   589,   590,   596,
     598,   602,   604,   607,   609,   612,   615,   618,   622,   625,
     628,   629,   640,   641,   646,   648,   650,   652,   654,   657,
     659,   663,   666,   667,   669,   671,   673,   675,   677,   679,
     681,   683,   685,   687,   689,   691,   693,   695,   697,   699,
     701,   703,   705,   707,   709,   712,   713,   714,   715,   717,
     720,   725,   728,   730,   733,   736,   739,   738,   745,   753,
     788,   795,   796,   800,   802,   804,   806,   809,   814,   813,
     820,   819,   826,   825,   832,   831,   838,   844,   845,   846,
     847,   849,   849,   856,   857,   859,   861,   864,   866,   868,
     869,   874,   877,   876,   882,   884,   887,   888,   890,   889,
     894,   894,   899,   899,   904,   905,   907,   914,   926,   927,
     929,   939,   950,   958,   958,   958,   958,   958,   958,   958,
     958,   959,   959,   959,   959,   959,   959,   959,   960,   960,
     960,   960,   960,   960,   961
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "EQNEQ", "NUMBER", "STRING", "PRINT",
  "parseDELETE", "VAR", "BLTIN", "UNDEF", "WHILE", "IF", "ELSE", "FOR",
  "FUNCTION", "PROCEDURE", "RETURN", "FUNC", "parsePROC", "HOCOBJFUNC",
  "READ", "parseDOUBLE", "DEBUG", "EDIT", "FUN_BLTIN", "DEPENDENT",
  "EQUATION", "LOCAL", "HOCOBJFUNCTION", "BREAK", "CONTINUE", "AUTO",
  "STRDEF", "STOPSTMT", "CSTRING", "PARALLEL", "HELP", "ITERATOR",
  "ITERKEYWORD", "ITERSTMT", "STRINGFUNC", "OBJECTFUNC", "LOCALOBJ",
  "AUTOOBJ", "ARG", "NUMZERO", "ARGREF", "INTERNALSECTIONNAME", "PYSEC",
  "PYSECNAME", "PYSECOBJ", "SECTIONKEYWORD", "SECTION", "CONNECTKEYWORD",
  "ACCESSKEYWORD", "RANGEVAR", "MECHANISM", "INSERTKEYWORD", "FORALL",
  "NRNPNTVAR", "FORSEC", "IFSEC", "UNINSERTKEYWORD", "SETPOINTERKEYWORD",
  "SECTIONREF", "BEGINTEMPLATE", "ENDTEMPLATE", "NEW", "OBJECTVAR",
  "TEMPLATE", "OBJVARDECL", "PUBLICDECL", "EXTERNALDECL", "OBFUNCTION",
  "STRFUNCTION", "OBJECTARG", "STRINGARG", "ROP", "'='", "OR", "AND", "GT",
  "GE", "LT", "LE", "EQ", "NE", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UNARYMINUS", "NOT", "'^'", "'\\n'", "'('", "')'", "'['", "']'", "'.'",
  "','", "'{'", "'}'", "':'", "';'", "'&'", "$accept", "list", "$@1",
  "asgn", "object", "$@2", "ob", "ob1", "$@3", "func_or_range_array_case",
  "template", "objvarlist", "objvarlst1", "obvarname", "publiclist",
  "externallist", "strnasgn", "string1", "string2", "strlist", "string",
  "stmt", "@4", "@5", "@6", "@7", "$@8", "$@9", "@10", "$@11", "@12",
  "@13", "@14", "@15", "@16", "@17", "iterator", "$@18", "section", "$@19",
  "pysec", "pysec1", "section_or_ob", "@20", "sectiondecl", "sectionname",
  "rangevar", "rangevar1", "$@21", "pointer", "for_init", "for_st",
  "for_cond", "for_inc", "cond", "while", "if", "begin", "end", "stmtlist",
  "expr", "function", "doublelist", "newarray", "numdimen", "newname",
  "varname", "$@22", "wholearray", "argrefdim", "array", "prlist",
  "delsym", "defn", "$@23", "$@24", "$@25", "$@26", "procname", "procstmt",
  "$@27", "arglist", "arglist1", "arglist2", "eqn_list", "$@28",
  "dep_list", "equation", "$@29", "lhs", "$@30", "rhs", "$@31", "local",
  "local1", "localobj", "local2", "ckvar", "anyname", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    61,
     334,   335,   336,   337,   338,   339,   340,   341,    43,    45,
      42,    47,    37,   342,   343,    94,    10,    40,    41,    91,
      93,    46,    44,   123,   125,    58,    59,    38
};
# endif

#define YYPACT_NINF -444

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-444)))

#define YYTABLE_NINF -161

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -444,  1134,  -444,  -444,  -444,  -444,  2159,    16,  -444,   -81,
    -444,  -444,     7,  -444,  -444,  2217,    80,    80,    80,   -80,
    -444,   -70,   -62,  -444,    27,    27,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,    28,  -444,    80,  -444,  -444,  -444,  -444,
     -24,  -444,  -444,  -444,   -33,  -444,  -444,    76,    -4,  -444,
      14,  -444,  -444,  -444,    17,   122,  2435,  2498,   921,   -22,
    -444,  2498,    71,  -444,  -444,  -444,  -444,  2329,  2329,  -444,
    1987,  -444,    -9,  -444,  1910,   -74,     3,  -444,    10,    18,
    -444,    12,  1027,    20,    32,  1710,  -444,   -49,  -444,  -444,
      38,    38,  2791,  -444,    48,   -47,    56,  -444,  -444,  -444,
     -48,  -444,  -444,    52,   -16,  2808,    54,  -444,  -444,  -444,
    2329,  -444,  1405,    53,   121,  -444,    64,  2498,  -444,  2808,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,    27,
     156,  -444,  -444,  -444,    70,    61,    79,  -444,  -444,  -444,
    2498,  -444,    27,    77,  -444,  -444,    83,    84,  2329,   108,
      90,   -18,  2498,  -444,    94,    91,    73,  -444,    95,  -444,
    -444,  -444,  -444,   177,   177,  -444,    96,    97,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  2329,  2498,  -444,  -444,
     100,   100,  -444,  2601,  1234,  -444,  -444,  -444,  2808,  2101,
    2498,  -444,  2498,   190,  -444,  -444,   177,  2498,  -444,     5,
    -444,  2329,  2329,  2329,  2329,  1910,  1910,  2329,  2329,  2329,
    2329,  2329,  2329,  2329,  2329,  2329,  2329,  2329,  2329,  2329,
    2329,  -444,   104,   156,  2043,  1311,  -444,  2273,  2329,  2159,
    -444,  2620,  -444,    98,    29,   194,   106,  1910,    73,   127,
    1311,   110,   111,   113,   114,   115,  -444,   117,  -444,    27,
    -444,  1311,  -444,  -444,  -444,  -444,   120,  1311,  1311,  2808,
    2329,  2329,  -444,   125,  -444,   112,   117,  -444,  -444,  -444,
    2329,  2329,  -444,  -444,  1910,  -444,  -444,  -444,  -444,   166,
    2329,    73,  -444,  2517,   126,   117,  -444,  -444,  -444,  1508,
    -444,  2498,  -444,  2808,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  2808,   192,   130,  2808,  2639,  -444,  -444,   681,
    1130,    49,    49,    49,    49,    49,    49,    93,    93,   100,
     100,   100,   100,  1311,  -444,  -444,  2808,  2498,   484,  -444,
    2808,   129,   131,  -444,  2658,  -444,  2808,  -444,  -444,  -444,
    -444,  -444,  1311,  -444,  -444,  2329,   139,  1311,   140,   141,
     142,  -444,  2329,   124,  -444,     8,   144,   165,   147,   150,
     151,  2808,  2538,   201,  2498,   124,    90,  2677,   -34,  2808,
    -444,  1910,  1910,  1910,  1910,  2696,   153,  -444,  2498,   124,
    -444,  -444,  -444,   161,  -444,   181,  2329,  1810,  1910,  -444,
    -444,   247,   167,   170,  -444,  -444,     6,  -444,  -444,  -444,
    1311,  -444,  1910,  2329,   171,  -444,   777,  -444,   187,   183,
     183,   183,  2559,  2329,  -444,  -444,  -444,   261,  2329,  -444,
    2329,   183,  -444,  -444,  -444,  -444,   117,  -444,  2329,  -444,
    -444,  -444,  -444,  -444,   186,   484,   117,  1311,   195,  2329,
    2715,  -444,   191,  -444,  1910,  -444,  1311,  -444,  2329,  -444,
    -444,  2734,  -444,  2329,  -444,   240,  -444,  -444,  -444,  -444,
    2580,  -444,  2329,  -444,  -444,  2808,  2494,  -444,   124,  2753,
    -444,  -444,  -444,  -444,   484,  -444,   124,   196,  1311,  -444,
    2808,   217,  -444,  -444,  -444,   198,  2772,  -444,  -444,  2808,
    2498,   256,   199,  -444,  2808,   301,  2329,  -444,  -444,  -444,
     208,  2329,  -444,  -444,  -444,  1910,  1910,  -444,  2498,  -444,
     205,  2498,  -444,  2808,  -444,   620,  -444,  -444,  -444,  1234,
    2498,  -444,  -444,  1910,  2329,  -444,  -444,  1609,  -444,  -444,
    2808,  -444,  -444
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,    14,   164,    58,     0,     0,   158,     0,
     151,   157,   158,   195,   158,   158,     0,     0,     0,     0,
     158,     0,     0,   196,     0,     0,   158,   158,   158,   158,
     158,   158,    56,     0,    12,     0,   158,   158,   158,    25,
     167,   165,   211,   127,     0,   158,   125,   133,     0,   142,
       0,   158,   158,   158,     0,   158,     0,     0,     0,     0,
     158,     0,     0,   197,   198,    24,    59,     0,     0,     3,
       0,    90,   172,    30,   171,    29,     0,    66,    37,    38,
      67,     0,     0,    64,     0,     0,   128,   169,   140,   151,
       0,     0,     0,   158,    65,   166,     0,    92,   172,   171,
      29,   214,    55,     0,   169,   213,    78,   217,    69,   206,
       0,   156,     0,     0,   123,    81,     0,     0,    70,    71,
     262,   227,   228,   230,   229,   218,   226,   220,   224,     0,
       0,     8,     9,   244,   241,     0,     0,    74,    76,   205,
       0,    75,     0,     0,   222,    73,     0,     0,     0,   168,
     210,     0,     0,   158,     0,     0,     0,   100,    29,    99,
     158,   101,   112,     0,     0,   102,     0,     0,    97,    40,
     263,   264,   279,   265,   266,   267,   268,   281,   275,   282,
     283,   284,   276,   269,   270,   278,   271,   277,   272,   273,
     274,   280,    36,    39,    33,   158,     0,     0,    47,    49,
     185,   194,   178,     0,     0,     5,    68,   159,    63,     0,
       0,    11,     0,     0,    10,    54,     0,     0,     6,     0,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,   233,     4,     0,     0,     0,
     158,     0,   150,     0,   166,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,   199,     0,   204,     0,
     242,   233,    60,    62,    84,    13,     0,   233,   233,    16,
       0,     0,   130,     0,   129,    93,   135,   139,   211,   126,
       0,     0,   134,   143,     0,   118,   114,   120,   116,     0,
       0,     0,    23,     0,    41,    42,    46,   177,   163,     0,
     104,     0,    52,    20,    31,    48,    50,    53,    51,    61,
     208,   141,    18,     0,     0,   152,     0,   159,   159,   193,
     192,   186,   187,   188,   189,   190,   191,   179,   180,   181,
     182,   183,   184,   233,   200,    21,    15,     0,     0,   237,
     238,     0,   234,   235,     0,   216,   215,   207,   176,   149,
     107,   109,   233,   159,   124,     0,     0,   233,     0,     0,
       0,   175,     0,   201,   245,   250,     0,     0,     0,     0,
       0,    17,     0,     0,     0,   136,   209,     0,     0,    94,
     159,     0,     0,     0,     0,     0,     0,    26,     0,    43,
     161,    91,   162,     0,   158,   170,     0,     0,     0,   155,
      87,    88,     0,     0,   148,   146,     0,   239,   144,   174,
       0,   170,     0,     0,     0,    79,     0,    77,     0,     0,
       0,     0,     0,     0,   252,   248,   243,     0,     0,    28,
       0,     0,    57,    27,   212,   131,   137,   132,     0,   113,
     159,   159,   159,   159,     0,     0,    44,   233,    34,     0,
       0,   154,     0,   159,     0,   173,   233,   147,     0,   236,
     159,     0,   122,     0,    72,   254,   219,   221,   225,   202,
       0,   247,     0,   250,   246,   251,     0,   223,   138,     0,
     119,   115,   121,   117,     0,    98,    45,     0,   233,    32,
     106,     0,   153,    80,   159,     0,     0,   108,   110,    82,
       0,   258,   255,   203,   253,     0,     0,    95,    96,    19,
       0,     0,    89,   240,   145,     0,     0,   256,     0,   231,
     259,     0,   252,    85,    35,     0,   159,   159,   260,     0,
       0,   257,   249,     0,     0,   111,    83,     0,   261,   159,
     105,   232,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -444,  -444,  -444,   308,  -444,  -444,    -1,     4,  -444,  -444,
    -444,  -444,  -444,   -88,  -444,  -444,  -444,   483,   416,  -444,
      99,   249,  -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,
    -444,  -444,  -444,  -444,  -444,  -444,  -444,  -444,    45,  -444,
    -444,  -444,  -444,  -444,  -444,   -73,     9,  -217,  -444,  -443,
    -444,   223,  -444,  -444,   224,  -444,  -444,  2401,  -305,  -222,
     373,  -444,  -444,    78,  -277,  -444,    -6,  -444,  -152,  -444,
      31,  -444,  -444,  -444,  -444,  -444,  -444,  -444,   116,  -340,
    -444,  -257,  -444,  -100,  -444,  -444,  -444,  -444,  -444,  -161,
    -444,  -208,  -444,  -444,  -444,  -444,  -444,  -129,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   143,    98,    73,   195,    99,   100,   404,   499,
      76,    77,   304,   305,    78,    79,    80,   206,    82,    83,
     272,   402,   259,   526,   377,   543,   204,   301,   422,   423,
     525,   294,   392,   394,   391,   393,   257,   258,   103,   153,
      86,   284,   155,   156,   285,   286,   104,    88,   160,   417,
      89,   111,   324,   408,   225,    90,    91,   288,   310,   309,
     208,    93,    94,   266,   373,   267,    95,   250,   289,   149,
     150,   106,   108,    96,   262,   263,   276,   264,   125,   476,
     539,   351,   352,   353,    97,   375,   134,   436,   483,   437,
     438,   481,   482,   511,   512,   529,   530,   126,   273
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,   268,   321,   366,   209,    75,   115,   467,   293,   385,
      87,   434,   495,   320,   376,     8,   110,   129,   133,   135,
     379,   380,   410,   411,   107,    26,   131,   210,   399,   221,
     247,   244,   282,   283,   132,     8,   192,   193,    38,    29,
      39,   198,   142,   302,    43,    44,    85,   157,   222,    46,
     245,   518,   158,   210,   148,    43,    44,   113,   425,    29,
      46,    49,   221,   448,   167,    58,    59,   219,   151,   113,
     113,   161,    65,    74,   165,    43,    44,   196,    75,   199,
      46,   248,   321,    87,    74,   449,   412,   205,   120,    75,
     477,   478,   154,   159,    87,   121,   122,   261,   357,   211,
     166,   487,    26,   468,   112,   424,   254,   244,   214,   123,
     428,    74,   212,   435,   268,    38,    75,    39,   124,    85,
     213,    87,   217,   265,    43,    44,   245,   360,   218,    46,
      85,   361,   287,   127,   128,   224,   274,   235,   236,   237,
     238,   239,    58,    59,   240,   490,   491,   492,   493,    65,
     243,   144,   246,   219,   255,   292,   249,    85,   503,   256,
     158,   260,   295,   297,   120,   507,   270,   158,   158,   488,
      43,    44,   269,   275,   113,    46,   271,   306,    49,   496,
     277,   278,     5,   237,   238,   239,   280,   113,   240,   281,
     314,   290,   315,   291,   300,   240,   210,   299,   316,   522,
     497,   343,   320,   362,   359,   365,    26,   367,   368,   505,
     369,   370,    32,   371,   384,   317,   372,   378,    37,    38,
     158,    39,    49,   433,    74,    74,   383,   419,   398,    75,
      75,   545,   546,   420,    87,    87,   407,   427,   429,   430,
     431,   520,   439,   440,   552,   441,    58,    59,   442,   443,
      84,   445,   458,    65,    66,   455,    74,   364,   457,   459,
     464,    75,   158,   374,   484,   465,    87,   466,   510,   472,
      85,    85,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   474,   475,   240,   494,   502,
     405,   403,   498,    74,   519,   521,   523,   406,    75,   528,
     396,   531,    85,    87,   532,   158,   534,   540,    74,    72,
     456,   446,   223,    75,   113,   226,   319,   547,    87,   386,
     469,   344,   515,   207,   542,     0,     0,   413,     0,     0,
       0,     0,     0,     0,   220,     0,   388,     0,     0,    85,
       0,     0,   418,     0,     0,     0,     0,   415,     0,     0,
       0,     0,   158,     0,    85,     0,     0,   416,     0,     0,
       0,   253,     0,     0,   287,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,   306,   105,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
      74,    74,    74,    74,     0,    75,    75,    75,    75,     0,
      87,    87,    87,    87,     0,     0,    74,    74,     0,     0,
       0,    75,    75,     0,     0,     0,    87,    87,     0,     0,
       0,    74,   102,     0,     0,     0,    75,     0,     0,     0,
       0,    87,     0,     0,     0,     0,    85,    85,    85,    85,
     200,   201,     0,   203,     0,     0,     0,     0,     0,   418,
       0,     0,    85,    85,   415,     0,     0,     0,     0,   158,
       0,     0,     0,    74,   416,     0,     0,    85,    75,     0,
       0,     0,     0,    87,   327,   328,     0,     0,     0,     0,
       0,     0,     0,   251,    81,     0,     0,     0,   418,   101,
     527,     0,     8,   415,     0,     0,     0,     0,   158,     0,
       0,     0,     0,   416,     0,     0,   363,     0,   538,    85,
       0,   541,     0,    26,     0,     0,    29,     0,     0,     0,
     548,   279,     0,     0,    74,    74,    38,     0,    39,    75,
      75,   414,    43,    44,    87,    87,     0,    46,     0,     0,
      49,     0,    74,   390,     0,     0,    74,    75,     0,     0,
       0,    75,    87,    58,    59,     0,    87,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,   303,
      85,    85,     0,     0,     0,     0,     0,     0,     0,   102,
     102,     0,   313,     0,     0,     0,     0,     0,    85,     0,
       0,     0,    85,     0,   322,   323,   325,   326,     0,     0,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,     0,     0,     0,   346,   350,     0,
     313,   354,   356,     0,     0,   102,     0,     0,     0,     0,
       0,     0,   102,   350,     0,     0,     0,     0,     0,     0,
     450,   451,   452,   453,   350,     0,   296,   298,     0,     0,
     350,   350,     0,   381,   382,     0,   462,   463,     0,     0,
       0,   102,     0,   387,   389,   102,     0,     0,     0,     0,
       0,   470,     0,   395,     0,     0,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,     0,     0,
       0,     0,   312,   102,   102,     0,     0,     0,     0,   318,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   504,     0,   240,   350,     0,     0,     0,
       0,     0,     0,     0,     0,   544,     0,     0,   349,     0,
       0,     0,   355,     0,     0,   350,     0,     0,   426,     0,
     350,     0,     0,   349,     0,   432,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,     0,     0,   102,
     349,   349,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   536,   537,   240,     0,   102,   460,
       0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
       0,     0,   549,   350,     0,     0,   471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,   485,     0,   486,     0,     0,     0,     0,     0,     0,
       0,   489,     0,     0,     0,     0,   349,     0,     0,     0,
     350,     0,   500,     0,     0,     0,   102,     0,     0,   350,
       0,   506,     0,     0,     0,   349,   509,     0,     0,     0,
     349,     0,     0,     0,     0,   514,     0,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,   350,   240,   102,     0,     0,     0,     0,     0,   473,
       0,     0,   102,     0,     0,     0,     0,     0,     0,   533,
       0,     0,     0,     0,   535,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   102,     0,     0,   550,     0,     0,
       0,     0,   194,     0,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,
     349,     0,   -22,   -22,     0,     0,   -22,   -22,   -22,   349,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,     0,
       0,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
     -22,     0,     0,   -22,   -22,   -22,   -22,   -22,     0,   -22,
     -22,   349,   -22,   -22,   -22,   -22,     0,     0,     0,     0,
     -22,   -22,   -22,     0,     0,   -22,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,   -22,   215,     0,
       0,   -55,   -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,   -55,   -55,
       0,     0,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,     0,     0,     0,   -55,   -55,   -55,
       0,   -55,   -55,   -55,   -55,   -55,   -55,     0,     0,   -55,
     -55,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,
     -55,   -55,     0,     0,     0,     0,   -55,   -55,   -55,     0,
       0,   -55,   -55,   -55,   -55,   216,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -55,     0,     0,     0,
       0,   -55,     0,   -55,   -55,   -55,     0,     0,     0,     0,
     -55,   -55,     0,   -55,     2,     3,     0,     0,     4,     5,
       6,     7,     8,     9,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,    29,    30,    31,    32,
      33,    34,     0,    35,    36,    37,    38,     0,    39,    40,
      41,    42,    43,    44,     0,     0,    45,    46,    47,    48,
      49,     0,    50,    51,     0,    52,    53,    54,    55,     0,
      56,    57,     0,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,    67,     0,   240,     0,     0,    68,     0,
      69,    70,     0,     0,     0,   308,     0,    71,  -160,  -160,
    -160,  -160,  -160,  -160,     0,  -160,  -160,     0,  -160,  -160,
    -160,  -160,     0,     0,     0,  -160,  -160,     0,     0,  -160,
    -160,  -160,     0,  -160,  -160,  -160,  -160,  -160,  -160,  -160,
    -160,     0,     0,     0,  -160,  -160,  -160,     0,  -160,  -160,
    -160,  -160,  -160,  -160,     0,     0,  -160,  -160,  -160,  -160,
    -160,     0,  -160,  -160,     0,  -160,  -160,  -160,  -160,     0,
       0,     0,     0,  -160,  -160,  -160,     0,     0,  -160,  -160,
    -160,  -160,     0,     0,     0,     4,     5,     0,     0,     8,
       9,     0,     0,  -160,     0,     0,    13,     0,  -160,     0,
    -160,  -160,    19,     0,     0,     0,    23,  -160,  -160,     0,
      26,     0,     0,    29,     0,     0,    32,     0,     0,     0,
       0,     0,    37,    38,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    46,     0,     0,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
      58,    59,     0,     0,     0,    63,    64,    65,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,     0,    68,     0,     0,    70,     4,
       5,     6,     7,     8,     9,     0,    10,    11,   348,    12,
      13,    14,    15,     0,     0,     0,    19,    20,     0,     0,
      23,    24,    25,     0,    26,    27,    28,    29,    30,    31,
      32,    33,     0,     0,     0,    36,    37,    38,     0,    39,
      40,    41,    42,    43,    44,     0,     0,    45,    46,    47,
      48,    49,     0,    50,    51,     0,    52,    53,    54,    55,
       0,     0,     0,     0,    58,    59,    60,     0,     0,    63,
      64,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,    68,
       0,     0,    70,     0,     0,     0,     0,     0,    71,     0,
       0,   252,     4,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    12,    13,    14,    15,     0,     0,     0,    19,
      20,     0,     0,    23,    24,    25,     0,    26,    27,    28,
      29,    30,    31,    32,    33,     0,     0,     0,    36,    37,
      38,     0,    39,    40,    41,    42,    43,    44,     0,     0,
      45,    46,    47,    48,    49,     0,    50,    51,     0,    52,
      53,    54,    55,     0,     0,     0,     0,    58,    59,    60,
       0,     0,    63,    64,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
       0,     0,    68,     0,   400,    70,     0,     0,     0,     0,
       0,    71,   401,     4,     5,     6,     7,     8,     9,     0,
      10,    11,     0,    12,    13,    14,    15,     0,     0,     0,
      19,    20,     0,     0,    23,    24,    25,     0,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,     0,    36,
      37,    38,     0,    39,    40,    41,    42,    43,    44,     0,
       0,    45,    46,    47,    48,    49,     0,    50,    51,     0,
      52,    53,    54,    55,     0,     0,     0,     0,    58,    59,
      60,     0,     0,    63,    64,    65,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,    68,     0,   400,    70,     0,     0,     0,
       0,     0,    71,   551,     4,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    12,    13,    14,    15,     0,     0,
       0,    19,    20,     0,     0,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
       0,     0,    45,    46,    47,    48,    49,     0,    50,    51,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    58,
      59,    60,     0,     0,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,     0,    68,     0,     0,    70,     0,     0,
       0,   219,     0,    71,     4,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    12,    13,    14,    15,     0,     0,
       0,    19,    20,     0,     0,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
       0,     0,    45,    46,    47,    48,    49,     0,    50,    51,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    58,
      59,    60,     0,     0,    63,    64,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,     0,    68,     0,     0,    70,   461,     0,
       0,     0,     0,    71,     4,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    12,    13,    14,    15,     0,     0,
       0,    19,    20,     0,     0,    23,    24,    25,     0,    26,
      27,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      36,    37,    38,     0,    39,    40,    41,    42,    43,    44,
       0,     0,    45,    46,    47,    48,    49,     0,    50,    51,
       0,    52,    53,    54,    55,     0,     0,     0,     0,    58,
      59,    60,     0,     0,    63,    64,    65,    66,   202,     0,
       0,     4,     0,     0,     0,     8,     9,     0,     0,    67,
       0,     0,    13,     0,    68,     0,     0,    70,    19,     0,
       0,     0,    23,    71,     0,     0,    26,     0,     0,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
      46,     0,     0,    49,   345,     0,     0,     4,     0,     0,
       0,     8,     9,     0,     0,     0,    58,    59,    13,     0,
       0,    63,    64,    65,    19,     0,     0,     0,    23,     0,
       0,     0,    26,     0,     0,    29,    67,     0,     0,     0,
       0,    68,     0,     0,    70,    38,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,    46,     0,     0,    49,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     8,
       9,     0,    58,    59,     0,     0,    13,    63,    64,    65,
       0,     0,    19,     0,     0,     0,    23,     0,     0,     0,
      26,     0,    67,    29,     0,     0,    32,    68,     0,     0,
      70,     0,    37,    38,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,    46,     0,     0,    49,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     8,     9,   311,
      58,    59,     0,     0,    13,    63,    64,    65,    66,     0,
      19,     0,     0,     0,    23,     0,     0,     0,    26,     0,
      67,    29,     0,     0,    32,    68,     0,     0,    70,     0,
      37,    38,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,    46,     0,     0,    49,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     8,     9,     0,    58,    59,
       0,     0,    13,    63,    64,    65,    66,     0,    19,     0,
       0,     0,    23,     0,     0,     0,    26,     0,    67,    29,
       0,     0,     0,    68,     0,     0,    70,     0,     0,    38,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
      46,     0,     0,    49,     0,     0,     0,     4,     0,     0,
       0,     8,     9,     0,     0,   117,    58,    59,    13,     0,
       0,    63,    64,    65,    19,     0,     0,     0,    23,     0,
       0,     0,    26,     0,     0,    29,    67,     0,     0,     0,
       0,    68,     0,     0,    70,    38,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,    46,     0,     0,    49,
       0,     0,     0,     4,     0,     0,     0,     8,     9,     0,
       0,   311,    58,    59,    13,     0,     0,    63,    64,    65,
      19,     0,     0,     0,    23,     0,     0,     0,    26,     0,
       0,    29,    67,     0,     0,     0,     0,    68,     0,     0,
      70,    38,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,    46,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
       0,     0,     0,    63,    64,    65,     0,     0,     0,   109,
       0,     0,     0,   114,     0,   116,   118,     0,    67,     0,
       0,   130,     0,    68,     0,     0,    70,   136,   137,   138,
     139,   140,   141,     0,     0,     0,   169,   145,   146,   147,
     170,     0,     0,   171,   172,   173,   152,     0,     0,     0,
     174,   175,   162,   163,   164,     0,   168,     0,     0,     0,
     176,   197,     0,     0,   177,     0,     0,   178,     0,     0,
       0,     0,     0,   179,     0,     0,   180,   181,     0,   182,
       0,     0,     0,     0,     0,     0,     0,     0,   183,     0,
       0,   184,   185,     0,   242,   186,     0,     0,     0,     0,
     187,     0,     0,   170,   188,   189,   171,   172,   173,   190,
     191,     0,     0,   174,   175,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,   177,     0,     0,
     178,     0,     0,     0,     0,     0,   179,     0,     0,   180,
     181,     0,   182,     0,     0,     0,     0,     0,     0,     0,
       0,   183,     0,     0,   184,   185,     0,     0,   186,     0,
       0,     0,     0,   187,     0,     0,     0,   188,   189,     0,
       0,     0,   190,   191,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,   240,
       0,     0,     0,     0,     0,     0,   516,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,   240,     0,     0,     0,     0,   397,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,   240,     0,     0,     0,     0,   444,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,   240,     0,     0,     0,     0,   479,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,   240,     0,     0,     0,     0,
     513,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,   240,     0,     0,   307,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,   240,     0,     0,   358,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,   240,     0,     0,   409,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,   240,     0,     0,   421,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,   240,     0,     0,   447,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,   240,     0,     0,   454,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
     240,     0,     0,   501,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,   240,
       0,     0,   508,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,   240,     0,
       0,   517,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,   240,     0,     0,
     524,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,   240,   241,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,   240
};

static const yytype_int16 yycheck[] =
{
       1,   130,   219,   260,    78,     1,    12,     1,   160,   286,
       1,     3,   455,     8,   271,     8,    97,    97,    24,    25,
     277,   278,   327,   328,     8,    29,    96,   101,   305,    78,
      78,    78,    50,    51,    96,     8,    56,    57,    42,    32,
      44,    61,    14,   195,    48,    49,     1,    48,    97,    53,
      97,   494,    48,   101,    78,    48,    49,    12,   363,    32,
      53,    56,    78,    97,    55,    69,    70,   101,   101,    24,
      25,    57,    76,    74,    57,    48,    49,    99,    74,     8,
      53,    97,   299,    74,    85,   390,   343,    96,     8,    85,
     430,   431,    47,    48,    85,    15,    16,   117,   250,    96,
      55,   441,    29,    97,    97,   362,   112,    78,    96,    29,
     367,   112,   102,   105,   243,    42,   112,    44,    38,    74,
     102,   112,   102,   129,    48,    49,    97,    98,    96,    53,
      85,   102,   152,    17,    18,    97,   142,    88,    89,    90,
      91,    92,    69,    70,    95,   450,   451,   452,   453,    76,
     102,    35,    96,   101,   101,   156,   102,   112,   463,    38,
     156,    97,   163,   164,     8,   470,   105,   163,   164,   446,
      48,    49,   102,    96,   129,    53,    97,   197,    56,   456,
      97,    97,     5,    90,    91,    92,    78,   142,    95,    99,
     210,    97,   212,   102,    97,    95,   101,   101,     8,   504,
     457,    97,     8,    97,   106,    78,    29,    97,    97,   466,
      97,    97,    35,    98,   102,   216,    99,    97,    41,    42,
     216,    44,    56,    99,   225,   226,   101,    98,   102,   225,
     226,   536,   537,   102,   225,   226,   106,    98,    98,    98,
      98,   498,    98,    78,   549,    98,    69,    70,    98,    98,
       1,    50,   404,    76,    77,   102,   257,   258,    97,    78,
      13,   257,   258,   269,     3,    98,   257,    97,    28,    98,
     225,   226,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    98,   103,    95,   102,    98,
      98,   311,    97,   294,    98,    78,    98,   105,   294,    43,
     301,   102,   257,   294,     3,   301,    98,   102,   309,     1,
     398,   384,    89,   309,   269,    91,   217,   539,   309,   288,
     420,   243,   483,    74,   532,    -1,    -1,   347,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,   291,    -1,    -1,   294,
      -1,    -1,   348,    -1,    -1,    -1,    -1,   348,    -1,    -1,
      -1,    -1,   348,    -1,   309,    -1,    -1,   348,    -1,    -1,
      -1,   112,    -1,    -1,   384,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,   398,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,
     391,   392,   393,   394,    -1,   391,   392,   393,   394,    -1,
     391,   392,   393,   394,    -1,    -1,   407,   408,    -1,    -1,
      -1,   407,   408,    -1,    -1,    -1,   407,   408,    -1,    -1,
      -1,   422,     6,    -1,    -1,    -1,   422,    -1,    -1,    -1,
      -1,   422,    -1,    -1,    -1,    -1,   391,   392,   393,   394,
      67,    68,    -1,    70,    -1,    -1,    -1,    -1,    -1,   455,
      -1,    -1,   407,   408,   455,    -1,    -1,    -1,    -1,   455,
      -1,    -1,    -1,   464,   455,    -1,    -1,   422,   464,    -1,
      -1,    -1,    -1,   464,   225,   226,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   110,     1,    -1,    -1,    -1,   494,     6,
     510,    -1,     8,   494,    -1,    -1,    -1,    -1,   494,    -1,
      -1,    -1,    -1,   494,    -1,    -1,   257,    -1,   528,   464,
      -1,   531,    -1,    29,    -1,    -1,    32,    -1,    -1,    -1,
     540,   148,    -1,    -1,   525,   526,    42,    -1,    44,   525,
     526,    47,    48,    49,   525,   526,    -1,    53,    -1,    -1,
      56,    -1,   543,   294,    -1,    -1,   547,   543,    -1,    -1,
      -1,   547,   543,    69,    70,    -1,   547,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     525,   526,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
     164,    -1,   209,    -1,    -1,    -1,    -1,    -1,   543,    -1,
      -1,    -1,   547,    -1,   221,   222,   223,   224,    -1,    -1,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,    -1,    -1,    -1,   244,   245,    -1,
     247,   248,   249,    -1,    -1,   209,    -1,    -1,    -1,    -1,
      -1,    -1,   216,   260,    -1,    -1,    -1,    -1,    -1,    -1,
     391,   392,   393,   394,   271,    -1,   163,   164,    -1,    -1,
     277,   278,    -1,   280,   281,    -1,   407,   408,    -1,    -1,
      -1,   245,    -1,   290,   291,   249,    -1,    -1,    -1,    -1,
      -1,   422,    -1,   300,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   271,    -1,    -1,
      -1,    -1,   209,   277,   278,    -1,    -1,    -1,    -1,   216,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   464,    -1,    95,   343,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,   245,    -1,
      -1,    -1,   249,    -1,    -1,   362,    -1,    -1,   365,    -1,
     367,    -1,    -1,   260,    -1,   372,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,   343,
     277,   278,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   525,   526,    95,    -1,   362,   406,
      -1,    -1,    -1,   367,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   543,   420,    -1,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   433,    -1,    -1,    -1,
      -1,   438,    -1,   440,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   448,    -1,    -1,    -1,    -1,   343,    -1,    -1,    -1,
     457,    -1,   459,    -1,    -1,    -1,   420,    -1,    -1,   466,
      -1,   468,    -1,    -1,    -1,   362,   473,    -1,    -1,    -1,
     367,    -1,    -1,    -1,    -1,   482,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,   498,    95,   457,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   466,    -1,    -1,    -1,    -1,    -1,    -1,   516,
      -1,    -1,    -1,    -1,   521,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,   544,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,    17,    -1,
     457,    -1,    21,    22,    -1,    -1,    25,    26,    27,   466,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    53,    54,    55,    56,    -1,    58,
      59,   498,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      69,    70,    71,    -1,    -1,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    21,    22,
      -1,    -1,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    40,    41,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    52,
      53,    54,    55,    56,    -1,    58,    59,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,    -1,
      -1,    74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,    98,    -1,    -1,    -1,    -1,
     103,   104,    -1,   106,     0,     1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    64,    -1,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    89,    -1,    95,    -1,    -1,    94,    -1,
      96,    97,    -1,    -1,    -1,     1,    -1,   103,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    14,    15,
      16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    69,    70,    71,    -1,    -1,    74,    75,
      76,    77,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,
       9,    -1,    -1,    89,    -1,    -1,    15,    -1,    94,    -1,
      96,    97,    21,    -1,    -1,    -1,    25,   103,   104,    -1,
      29,    -1,    -1,    32,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,   107,    14,
      15,    16,    17,    -1,    -1,    -1,    21,    22,    -1,    -1,
      25,    26,    27,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    -1,    -1,    52,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    69,    70,    71,    -1,    -1,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,    -1,
      -1,   106,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,    21,
      22,    -1,    -1,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    44,    45,    46,    47,    48,    49,    -1,    -1,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,    71,
      -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    94,    -1,    96,    97,    -1,    -1,    -1,    -1,
      -1,   103,   104,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    -1,    14,    15,    16,    17,    -1,    -1,    -1,
      21,    22,    -1,    -1,    25,    26,    27,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    40,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    52,    53,    54,    55,    56,    -1,    58,    59,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,    70,
      71,    -1,    -1,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    94,    -1,    96,    97,    -1,    -1,    -1,
      -1,    -1,   103,   104,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,   101,    -1,   103,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    98,    -1,
      -1,    -1,    -1,   103,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    14,    15,    16,    17,    -1,    -1,
      -1,    21,    22,    -1,    -1,    25,    26,    27,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    69,
      70,    71,    -1,    -1,    74,    75,    76,    77,     1,    -1,
      -1,     4,    -1,    -1,    -1,     8,     9,    -1,    -1,    89,
      -1,    -1,    15,    -1,    94,    -1,    -1,    97,    21,    -1,
      -1,    -1,    25,   103,    -1,    -1,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,     1,    -1,    -1,     4,    -1,    -1,
      -1,     8,     9,    -1,    -1,    -1,    69,    70,    15,    -1,
      -1,    74,    75,    76,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    89,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    42,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,     8,
       9,    -1,    69,    70,    -1,    -1,    15,    74,    75,    76,
      -1,    -1,    21,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    -1,    89,    32,    -1,    -1,    35,    94,    -1,    -1,
      97,    -1,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    -1,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,     8,     9,    68,
      69,    70,    -1,    -1,    15,    74,    75,    76,    77,    -1,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      89,    32,    -1,    -1,    35,    94,    -1,    -1,    97,    -1,
      41,    42,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,     4,    -1,    -1,    -1,     8,     9,    -1,    69,    70,
      -1,    -1,    15,    74,    75,    76,    77,    -1,    21,    -1,
      -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    89,    32,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    42,
      -1,    44,    45,    46,    47,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    56,    -1,    -1,    -1,     4,    -1,    -1,
      -1,     8,     9,    -1,    -1,    68,    69,    70,    15,    -1,
      -1,    74,    75,    76,    21,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    29,    -1,    -1,    32,    89,    -1,    -1,    -1,
      -1,    94,    -1,    -1,    97,    42,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,    56,
      -1,    -1,    -1,     4,    -1,    -1,    -1,     8,     9,    -1,
      -1,    68,    69,    70,    15,    -1,    -1,    74,    75,    76,
      21,    -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,
      -1,    32,    89,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      97,    42,    -1,    44,    45,    46,    47,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    -1,     8,
      -1,    -1,    -1,    12,    -1,    14,    15,    -1,    89,    -1,
      -1,    20,    -1,    94,    -1,    -1,    97,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,     1,    36,    37,    38,
       5,    -1,    -1,     8,     9,    10,    45,    -1,    -1,    -1,
      15,    16,    51,    52,    53,    -1,    55,    -1,    -1,    -1,
      25,    60,    -1,    -1,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    93,    60,    -1,    -1,    -1,    -1,
      65,    -1,    -1,     5,    69,    70,     8,     9,    10,    74,
      75,    -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    -1,    -1,    -1,    29,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    -1,    69,    70,    -1,
      -1,    -1,    74,    75,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    -1,    -1,    -1,   100,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    -1,    -1,    -1,   100,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,   100,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
     100,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    -1,    -1,    98,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    -1,    95,    -1,    -1,    98,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    -1,    95,    -1,    -1,    98,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95,    -1,    -1,    98,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    -1,    95,    -1,    -1,    98,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      -1,    95,    -1,    -1,    98,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    -1,
      95,    -1,    -1,    98,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    -1,    95,
      -1,    -1,    98,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    -1,    95,    -1,
      -1,    98,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    -1,    95,    -1,    -1,
      98,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    -1,    95,    96,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    -1,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   109,     0,     1,     4,     5,     6,     7,     8,     9,
      11,    12,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    39,    40,    41,    42,    44,
      45,    46,    47,    48,    49,    52,    53,    54,    55,    56,
      58,    59,    61,    62,    63,    64,    66,    67,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    89,    94,    96,
      97,   103,   111,   112,   114,   115,   118,   119,   122,   123,
     124,   125,   126,   127,   129,   146,   148,   154,   155,   158,
     163,   164,   168,   169,   170,   174,   181,   192,   111,   114,
     115,   125,   126,   146,   154,   168,   179,     8,   180,   165,
      97,   159,    97,   146,   165,   174,   165,    68,   165,   168,
       8,    15,    16,    29,    38,   186,   205,   186,   186,    97,
     165,    96,    96,   174,   194,   174,   165,   165,   165,   165,
     165,   165,    14,   110,   186,   165,   165,   165,    78,   177,
     178,   101,   165,   147,   146,   150,   151,   114,   115,   146,
     156,    57,   165,   165,   165,    57,   146,   154,   165,     1,
       5,     8,     9,    10,    15,    16,    25,    29,    32,    38,
      41,    42,    44,    53,    56,    57,    60,    65,    69,    70,
      74,    75,   206,   206,     1,   113,    99,   165,   206,     8,
     168,   168,     1,   168,   134,    96,   125,   129,   168,    78,
     101,    96,   102,   102,    96,     1,    78,   102,    96,   101,
     129,    78,    97,   159,    97,   162,   162,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      95,    96,   165,   102,    78,    97,    96,    78,    97,   102,
     175,   168,   106,   129,   174,   101,    38,   144,   145,   130,
      97,   206,   182,   183,   185,   174,   171,   173,   205,   102,
     105,    97,   128,   206,   174,    96,   184,    97,    97,   168,
      78,    99,    50,    51,   149,   152,   153,   206,   165,   176,
      97,   102,   114,   176,   139,   114,   125,   114,   125,   101,
      97,   135,   176,   168,   120,   121,   206,    98,     1,   167,
     166,    68,   125,   168,   206,   206,     8,   114,   125,   128,
       8,   155,   168,   168,   160,   168,   168,   129,   129,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,    97,   171,     1,   168,    68,   107,   125,
     168,   189,   190,   191,   168,   125,   168,   176,    98,   106,
      98,   102,    97,   129,   114,    78,   189,    97,    97,    97,
      97,    98,    99,   172,   174,   193,   189,   132,    97,   189,
     189,   168,   168,   101,   102,   172,   178,   168,   146,   168,
     129,   142,   140,   143,   141,   168,   114,   100,   102,   172,
      96,   104,   129,   206,   116,    98,   105,   106,   161,    98,
     166,   166,   189,   206,    47,   114,   154,   157,   174,    98,
     102,    98,   136,   137,   189,   166,   168,    98,   189,    98,
      98,    98,   168,    99,     3,   105,   195,   197,   198,    98,
      78,    98,    98,    98,   100,    50,   153,    98,    97,   166,
     129,   129,   129,   129,    98,   102,   121,    97,   176,    78,
     168,    98,   129,   129,    13,    98,    97,     1,    97,   191,
     129,   168,    98,   102,    98,   103,   187,   187,   187,   100,
     168,   199,   200,   196,     3,   168,   168,   187,   172,   168,
     166,   166,   166,   166,   102,   157,   172,   189,    97,   117,
     168,    98,    98,   166,   129,   189,   168,   166,    98,   168,
      28,   201,   202,   100,   168,   197,   102,    98,   157,    98,
     189,    78,   166,    98,    98,   138,   131,   206,    43,   203,
     204,   102,     3,   168,    98,   168,   129,   129,   206,   188,
     102,   206,   199,   133,   105,   166,   166,   167,   206,   129,
     168,   104,   166
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   109,   109,   111,   111,   111,   111,   111,
     111,   111,   113,   112,   112,   112,   112,   112,   112,   114,
     115,   116,   115,   115,   117,   117,   118,   118,   118,   118,
     118,   119,   120,   120,   120,   120,   121,   122,   122,   123,
     123,   124,   124,   124,   124,   125,   125,   125,   126,   126,
     127,   127,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   131,   129,   132,   133,   129,   129,   129,   129,
     134,   129,   129,   129,   129,   129,   129,   135,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   136,   129,   137,
     138,   129,   139,   129,   140,   129,   141,   129,   142,   129,
     143,   129,   144,   145,   144,   147,   146,   146,   146,   148,
     149,   149,   150,   151,   150,   152,   152,   152,   152,   153,
     154,   154,   156,   155,   157,   157,   157,   157,   157,   158,
     158,   159,   160,   161,   161,   162,   163,   164,   165,   166,
     167,   167,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   169,   169,   169,   169,   170,
     170,   171,   172,   172,   173,   174,   175,   174,   174,   176,
     177,   178,   178,   179,   179,   179,   179,   180,   182,   181,
     183,   181,   184,   181,   185,   181,   186,   186,   186,   186,
     186,   188,   187,   189,   189,   190,   190,   191,   191,   191,
     191,   192,   193,   192,   194,   194,   195,   195,   196,   195,
     198,   197,   200,   199,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     4,     2,     3,     3,     4,     3,     7,
       3,     3,     0,     3,     1,     1,     4,     5,     5,     1,
       1,     0,     6,     2,     0,     3,     2,     1,     1,     2,
       2,     3,     1,     2,     3,     4,     1,     2,     3,     2,
       3,     3,     3,     3,     2,     1,     1,     5,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     6,     2,     2,     2,     2,     5,     2,     5,
       6,     0,     0,    10,     0,     0,    11,     4,     4,     7,
       0,     4,     1,     3,     4,     7,     7,     0,     6,     2,
       2,     2,     2,     2,     3,    10,     6,     0,     7,     0,
       0,    10,     0,     5,     0,     6,     0,     6,     0,     6,
       0,     6,     4,     0,     2,     0,     3,     1,     1,     3,
       1,     3,     4,     0,     2,     1,     2,     3,     4,     1,
       1,     3,     0,     3,     1,     4,     1,     2,     1,     4,
       3,     0,     1,     3,     2,     3,     2,     1,     0,     0,
       0,     2,     2,     1,     1,     1,     1,     1,     2,     1,
       4,     1,     1,     5,     4,     4,     4,     3,     2,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     1,     3,
       3,     2,     3,     4,     1,     2,     0,     4,     3,     2,
       1,     0,     4,     1,     1,     3,     3,     1,     0,     6,
       0,     6,     0,     6,     0,     6,     1,     1,     1,     1,
       1,     0,     6,     0,     1,     1,     3,     1,     1,     2,
       5,     2,     0,     5,     1,     3,     2,     2,     0,     5,
       0,     2,     0,     2,     0,     1,     2,     3,     0,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 141 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { ntab = 0;}
#line 2348 "parse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 142 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2354 "parse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 143 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2360 "parse.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); code2(nopop, STOP); return 1; }
#line 2366 "parse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { codein(STOP); return 1; }
#line 2372 "parse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 149 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPDYNAM; code2(print, STOP); return 1; }
#line 2378 "parse.c" /* yacc.c:1646  */
    break;

  case 8:
#line 151 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { debug(); return '\n';}
#line 2384 "parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 153 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { return 'e';}
#line 2390 "parse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 155 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(prstr); code2(hoc_newline, STOP); return 1; }
#line 2396 "parse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 158 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { return '\n';}
#line 2402 "parse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_help();}
#line 2408 "parse.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { return '\n'; }
#line 2414 "parse.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {clean_err(); hoc_execerror("parse error", (char*)0);
#if LINT
if (0) {
if(yydebug);
goto yynewstate;
}
#endif
		}
#line 2427 "parse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 176 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; TPD; s = spop();
		hoc_obvar_declare(s, VAR, 1);
		code3(varpush, s, assign); codei((yyvsp[-1].narg)); PN;}
#line 2435 "parse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  TPD; defnonly("$"); argcode(argassign, (yyvsp[-2].narg)); codei((yyvsp[-1].narg)); (yyval.inst)=(yyvsp[0].inst); PN;}
#line 2441 "parse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 182 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; defnonly("$&"); argrefcode(hoc_argrefasgn, (yyvsp[-3].narg), (yyvsp[-2].narg)); codei((yyvsp[-1].narg)); (yyval.inst)=(yyvsp[0].inst); PN;}
#line 2447 "parse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; code(range_const); codesym(spop()); codei((yyvsp[-1].narg)); PN;}
#line 2453 "parse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { Inst* p; hoc_opasgn_invalid((yyvsp[-5].narg));
		 code(hoc_newobj); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
#line 2463 "parse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Inst* p; TPDYNAM; code(hoc_object_asgn); codei((yyvsp[-1].narg));
		 p = (Inst*)spop();
		 if (p) { p->i += 2; }
		}
#line 2472 "parse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("assignment to variable, make sure right side is a number");}
#line 2478 "parse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {pushi(OBJECTVAR);pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 2484 "parse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 205 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst); code(hoc_objectvar); spop(); codesym((yyvsp[-2].sym));}
#line 2490 "parse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 207 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {defnonly("$o"); (yyval.inst) = argcode(hoc_objectarg, (yyvsp[0].narg)); pushi(OBJECTVAR);}
#line 2496 "parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 209 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_autoobject); codesym((yyvsp[0].sym)); pushi(OBJECTVAR);}
#line 2502 "parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 211 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {TPD; (yyval.inst) = (yyvsp[-1].inst); code(hoc_constobject); codesym((yyvsp[-3].sym)); pushi(OBJECTVAR);}
#line 2508 "parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 213 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
#line 2515 "parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 216 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));
		  code(hoc_known_type); codei(OBJECTVAR); pushi(OBJECTVAR);}
#line 2522 "parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 220 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { spop(); }
#line 2528 "parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 223 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { pushs((Symbol*)0); }
#line 2534 "parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 224 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym));pushi(NOCHECK);}
#line 2540 "parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 225 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {int isfunc; Inst* p;
		 isfunc = ipop();
		 code(hoc_object_component); codesym(spop()); codei(ipop());
		 codei((yyvsp[0].narg));
		 codei(0); codesym(0);
		 p = codei(isfunc); /* for USE_PYTHON */
		 spop();
		 pushs((Symbol*)p); /* in case assigning to a PythonObject we will want to update isfunc to 2 */
		}
#line 2554 "parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 234 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("object syntax is o1.o2.o3.");}
#line 2560 "parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 237 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.narg) = 0; pushi(0);}
#line 2566 "parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 239 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.narg) = (yyvsp[-1].narg); pushi(1);}
#line 2572 "parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 241 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_begintemplate((yyvsp[0].sym));}
#line 2578 "parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_endtemplate((yyvsp[0].sym));}
#line 2584 "parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 245 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("begintemplate Name\npublic namelist\nexternal namelist\n...\nendtemplate Name");}
#line 2590 "parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[-1].inst);}
#line 2596 "parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[0].sym)); codei(0);}
#line 2602 "parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 253 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 2608 "parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 255 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[0].sym)); codei(0);}
#line 2614 "parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 257 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_objvardecl); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 2620 "parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 260 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		  Symbol* s;
		  s = hoc_decl((yyvsp[0].sym));
		  if (s->type != UNDEF && s->type != OBJECTVAR) {
			acterror(s->name, " already declared");
		  }
		  (yyval.sym) = s;
		}
#line 2633 "parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 270 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_add_publiclist((yyvsp[0].sym));}
#line 2639 "parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 272 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_add_publiclist((yyvsp[0].sym));}
#line 2645 "parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 275 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_external_var((yyvsp[0].sym));}
#line 2651 "parse.c" /* yacc.c:1646  */
    break;

  case 50:
#line 277 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_external_var((yyvsp[0].sym));}
#line 2657 "parse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 282 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_opasgn_invalid((yyvsp[-1].narg)); code(assstr);}
#line 2663 "parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 284 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Inst* p = (Inst*) spop(); pushi(STRING); TPDYNAM; code(hoc_object_asgn);
		 hoc_opasgn_invalid((yyvsp[-1].narg)); codei((yyvsp[-1].narg)); hoc_ob_check(-1); code(nopop);
		 if (p) { p->i += 2; }
		}
#line 2672 "parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 289 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_asgn_obj_to_str); hoc_opasgn_invalid((yyvsp[-1].narg)); }
#line 2678 "parse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 290 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("string assignment: both sides need to be a string");}
#line 2684 "parse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 295 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[0].sym));}
#line 2690 "parse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 297 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg));}
#line 2696 "parse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 301 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_push_string); codesym((yyvsp[0].sym));}
#line 2702 "parse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 303 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {defnonly("$s"); (yyval.inst) = argcode(hoc_stringarg, (yyvsp[0].narg));}
#line 2708 "parse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 307 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 2714 "parse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 311 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
			Symbol* s = hoc_decl((yyvsp[0].sym));
			if (s->type == UNDEF) {
				hoc_obvar_declare(s, STRING, 0);
				OPSTR(s) = (char**)emalloc(sizeof(char*));
				*OPSTR(s) = 0;
			}else if (s->type != STRING) {
				acterror(s->name, " already declared");
			}
			hoc_assign_str(OPSTR(s), "");
		}
#line 2730 "parse.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(nopop); hoc_ob_check(-1); /*don't check*/}
#line 2736 "parse.c" /* yacc.c:1646  */
    break;

  case 68:
#line 332 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(nopop); }
#line 2742 "parse.c" /* yacc.c:1646  */
    break;

  case 69:
#line 334 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst);}
#line 2748 "parse.c" /* yacc.c:1646  */
    break;

  case 70:
#line 336 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { defnonly("return"); (yyval.inst)=(yyvsp[0].inst); code(procret); }
#line 2754 "parse.c" /* yacc.c:1646  */
    break;

  case 71:
#line 338 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  if (indef == 3) {
			TPDYNAM; (yyval.inst) = (yyvsp[0].inst);
			code(hocobjret);
		   }else{
			TPD; defnonly("return"); (yyval.inst)=(yyvsp[0].inst);
			code(funcret);
		   }
		}
#line 2767 "parse.c" /* yacc.c:1646  */
    break;

  case 72:
#line 347 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = code(hoc_newobj_ret); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		 code(hocobjret);
		}
#line 2775 "parse.c" /* yacc.c:1646  */
    break;

  case 73:
#line 351 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { if (indef != 2) {
acterror("iterator_statement used outside an iterator declaration", 0);
		  }
			code(hoc_iterator_stmt);
		}
#line 2785 "parse.c" /* yacc.c:1646  */
    break;

  case 74:
#line 357 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(Break); (yyval.inst) = (yyvsp[0].inst); }
#line 2791 "parse.c" /* yacc.c:1646  */
    break;

  case 75:
#line 359 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(Stop); (yyval.inst) = (yyvsp[0].inst); }
#line 2797 "parse.c" /* yacc.c:1646  */
    break;

  case 76:
#line 361 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(Continue); (yyval.inst) = (yyvsp[0].inst); }
#line 2803 "parse.c" /* yacc.c:1646  */
    break;

  case 77:
#line 363 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg)); code(nopop); }
#line 2809 "parse.c" /* yacc.c:1646  */
    break;

  case 78:
#line 365 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); code(hoc_newline); }
#line 2815 "parse.c" /* yacc.c:1646  */
    break;

  case 79:
#line 367 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst);
		  ((yyvsp[-2].inst))[0].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 0); /* body */
		  ((yyvsp[-2].inst))[1].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 1); /* exit */
		}
#line 2824 "parse.c" /* yacc.c:1646  */
    break;

  case 80:
#line 372 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
			((yyvsp[-4].inst))[1].i =relative((yyvsp[-1].inst), (yyvsp[-4].inst), 1);	/* body */
			((yyvsp[-4].inst))[2].i =relative((yyvsp[0].inst), (yyvsp[-4].inst), 2); /* exit from the for */
			((yyvsp[-4].inst))[3].i  =relative((yyvsp[-2].inst), (yyvsp[-4].inst), 3);	/* increment */
			(yyval.inst) = (yyvsp[-5].inst);
#if LINT
if (0){YYERROR;}
#endif
			}
#line 2838 "parse.c" /* yacc.c:1646  */
    break;

  case 81:
#line 382 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
#line 2846 "parse.c" /* yacc.c:1646  */
    break;

  case 82:
#line 386 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[-3].narg)); 
		    (yyval.inst) = code(shortfor); codei(0); codei(0);}
#line 2853 "parse.c" /* yacc.c:1646  */
    break;

  case 83:
#line 389 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-8].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			   ((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		  }
#line 2861 "parse.c" /* yacc.c:1646  */
    break;

  case 84:
#line 393 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { Symbol *s; (yyval.inst) = Code(varpush); codesym(s = spop());
			hoc_obvar_declare(s, VAR, 1);
		  }
#line 2869 "parse.c" /* yacc.c:1646  */
    break;

  case 85:
#line 397 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {TPD; TPD; hoc_opasgn_invalid((yyvsp[-3].narg)); 
		     code(hoc_parallel_begin);
		     (yyval.inst) = code(shortfor); codei(0); codei(0);}
#line 2877 "parse.c" /* yacc.c:1646  */
    break;

  case 86:
#line 401 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-8].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			   ((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
			code(hoc_parallel_end);
		  }
#line 2886 "parse.c" /* yacc.c:1646  */
    break;

  case 87:
#line 406 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-3].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-3].inst), 1);	/* body of loop */
		((yyvsp[-3].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-3].inst), 2); }
#line 2894 "parse.c" /* yacc.c:1646  */
    break;

  case 88:
#line 410 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-3].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-3].inst), 1);	/* thenpart */
		((yyvsp[-3].inst))[3].i = relative((yyvsp[0].inst), (yyvsp[-3].inst), 3); }
#line 2902 "parse.c" /* yacc.c:1646  */
    break;

  case 89:
#line 414 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		((yyvsp[-6].inst))[1].i = relative((yyvsp[-4].inst), (yyvsp[-6].inst), 1);	/* thenpart */
		((yyvsp[-6].inst))[2].i = relative((yyvsp[-1].inst), (yyvsp[-6].inst), 2);	/* elsepart */
		((yyvsp[-6].inst))[3].i = relative((yyvsp[0].inst), (yyvsp[-6].inst), 3); }
#line 2911 "parse.c" /* yacc.c:1646  */
    break;

  case 90:
#line 419 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { ntab++;}
#line 2917 "parse.c" /* yacc.c:1646  */
    break;

  case 91:
#line 421 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		ntab--; (yyval.inst) = (yyvsp[-1].inst);
		}
#line 2925 "parse.c" /* yacc.c:1646  */
    break;

  case 93:
#line 427 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 2931 "parse.c" /* yacc.c:1646  */
    break;

  case 94:
#line 429 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-2].inst); code(connectsection);}
#line 2937 "parse.c" /* yacc.c:1646  */
    break;

  case 95:
#line 431 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-5].inst); code(simpleconnectsection);}
#line 2943 "parse.c" /* yacc.c:1646  */
    break;

  case 96:
#line 433 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-5].inst); code(connectpointer); codesym(spop());}
#line 2949 "parse.c" /* yacc.c:1646  */
    break;

  case 97:
#line 434 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(nrn_cppp);}
#line 2955 "parse.c" /* yacc.c:1646  */
    break;

  case 98:
#line 435 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); code(connect_point_process_pointer);
			 hoc_ob_check(-1);}
#line 2962 "parse.c" /* yacc.c:1646  */
    break;

  case 99:
#line 438 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); code(sec_access);}
#line 2968 "parse.c" /* yacc.c:1646  */
    break;

  case 100:
#line 440 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); hoc_ob_check(SECTION); code(sec_access_object);}
#line 2974 "parse.c" /* yacc.c:1646  */
    break;

  case 101:
#line 442 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = Code(mech_access); codesym((yyvsp[0].sym));}
#line 2980 "parse.c" /* yacc.c:1646  */
    break;

  case 102:
#line 444 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = Code(mech_uninsert); codesym((yyvsp[0].sym));}
#line 2986 "parse.c" /* yacc.c:1646  */
    break;

  case 103:
#line 446 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(sec_access_pop);}
#line 2992 "parse.c" /* yacc.c:1646  */
    break;

  case 104:
#line 448 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(sec_access_pop); hoc_ob_check(-1);
			insertcode((yyvsp[-1].inst), (yyvsp[0].inst), ob_sec_access);}
#line 2999 "parse.c" /* yacc.c:1646  */
    break;

  case 105:
#line 451 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; TPD; TPD; code(range_interpolate); codesym(spop());
		  codei((yyvsp[-3].narg));
		}
#line 3007 "parse.c" /* yacc.c:1646  */
    break;

  case 106:
#line 455 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(range_interpolate_single); codesym(spop());
		  codei((yyvsp[-1].narg));
		}
#line 3015 "parse.c" /* yacc.c:1646  */
    break;

  case 107:
#line 459 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		 hoc_obvar_declare(s, VAR, 1);
		 (yyval.inst) = code(for_segment); codei(0); codei(0);}
#line 3023 "parse.c" /* yacc.c:1646  */
    break;

  case 108:
#line 463 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3031 "parse.c" /* yacc.c:1646  */
    break;

  case 109:
#line 467 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		hoc_obvar_declare(s, VAR, 1);}
#line 3038 "parse.c" /* yacc.c:1646  */
    break;

  case 110:
#line 470 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = code(for_segment1); codei(0); codei(0);}
#line 3044 "parse.c" /* yacc.c:1646  */
    break;

  case 111:
#line 472 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-7].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3052 "parse.c" /* yacc.c:1646  */
    break;

  case 112:
#line 476 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {	code(hoc_push_string); codesym((Symbol*)0);
			(yyval.inst) = code(forall_section); codei(0); codei(0);}
#line 3059 "parse.c" /* yacc.c:1646  */
    break;

  case 113:
#line 479 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3067 "parse.c" /* yacc.c:1646  */
    break;

  case 114:
#line 483 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(forall_section); codei(0); codei(0);}
#line 3073 "parse.c" /* yacc.c:1646  */
    break;

  case 115:
#line 485 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3081 "parse.c" /* yacc.c:1646  */
    break;

  case 116:
#line 489 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(hoc_ifsec); codei(0); codei(0);}
#line 3087 "parse.c" /* yacc.c:1646  */
    break;

  case 117:
#line 491 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3095 "parse.c" /* yacc.c:1646  */
    break;

  case 118:
#line 495 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_ob_check(-1);
		(yyval.inst) = code(forall_sectionlist); codei(0); codei(0); }
#line 3102 "parse.c" /* yacc.c:1646  */
    break;

  case 119:
#line 498 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3110 "parse.c" /* yacc.c:1646  */
    break;

  case 120:
#line 502 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1);
		 (yyval.inst) = code(hoc_ifseclist); codei(0); codei(0);
		}
#line 3118 "parse.c" /* yacc.c:1646  */
    break;

  case 121:
#line 507 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-4].inst); ((yyvsp[-2].inst))[1].i = relative((yyvsp[-1].inst), (yyvsp[-2].inst), 1); /* body */
			((yyvsp[-2].inst))[2].i = relative((yyvsp[0].inst), (yyvsp[-2].inst), 2); /* exit */
		}
#line 3126 "parse.c" /* yacc.c:1646  */
    break;

  case 122:
#line 514 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		  code(hoc_iterator); codesym((yyvsp[-3].sym)); codei((yyvsp[-1].narg));
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
#line 3135 "parse.c" /* yacc.c:1646  */
    break;

  case 123:
#line 518 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_push_current_object);}
#line 3141 "parse.c" /* yacc.c:1646  */
    break;

  case 124:
#line 519 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {codei(ITERATOR);
		  (yyval.inst) = progp; codein(STOP); codein(STOP);
		}
#line 3149 "parse.c" /* yacc.c:1646  */
    break;

  case 125:
#line 524 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 3155 "parse.c" /* yacc.c:1646  */
    break;

  case 126:
#line 525 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(sec_access_push); codesym(spop()); (yyval.inst) = (yyvsp[0].inst);}
#line 3161 "parse.c" /* yacc.c:1646  */
    break;

  case 127:
#line 527 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		  (yyval.inst) = code(hoc_sec_internal_push);
		  hoc_codeptr((yyvsp[0].ptr));
		}
#line 3170 "parse.c" /* yacc.c:1646  */
    break;

  case 128:
#line 532 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		  nrn_parsing_pysec_ = NULL;
		  (yyval.inst) = code(hoc_sec_internal_push);
		  hoc_codeptr((yyvsp[0].ptr));
		}
#line 3180 "parse.c" /* yacc.c:1646  */
    break;

  case 129:
#line 540 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.ptr) = (yyvsp[0].ptr); }
#line 3186 "parse.c" /* yacc.c:1646  */
    break;

  case 131:
#line 545 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.ptr) = (yyvsp[0].ptr); }
#line 3192 "parse.c" /* yacc.c:1646  */
    break;

  case 132:
#line 548 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {TPD;}
#line 3198 "parse.c" /* yacc.c:1646  */
    break;

  case 133:
#line 549 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = progp; code(connect_obsec_syntax);}
#line 3204 "parse.c" /* yacc.c:1646  */
    break;

  case 134:
#line 550 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
#if 0
		 acterror("Sorry. The \"connect ob.sec...\" syntax ",
			"is not implemented");
#endif
		 hoc_ob_check(SECTION); code(ob_sec_access);
		}
#line 3216 "parse.c" /* yacc.c:1646  */
    break;

  case 135:
#line 560 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[0].sym)); codei(0);}
#line 3222 "parse.c" /* yacc.c:1646  */
    break;

  case 136:
#line 562 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 3228 "parse.c" /* yacc.c:1646  */
    break;

  case 137:
#line 564 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(add_section); codesym((yyvsp[0].sym)); codei(0);}
#line 3234 "parse.c" /* yacc.c:1646  */
    break;

  case 138:
#line 566 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(add_section); codesym((yyvsp[-1].sym)); codei((yyvsp[0].narg));}
#line 3240 "parse.c" /* yacc.c:1646  */
    break;

  case 139:
#line 569 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
			Symbol* s;
			s = hoc_decl((yyvsp[0].sym));
			if (s->type != UNDEF && s->type != SECTION)
				acterror(s->name, " already declared");
		}
#line 3251 "parse.c" /* yacc.c:1646  */
    break;

  case 140:
#line 577 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(sec_access_push); codesym((Symbol *)0);}
#line 3257 "parse.c" /* yacc.c:1646  */
    break;

  case 142:
#line 580 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[0].sym)); pushi(CHECK);}
#line 3263 "parse.c" /* yacc.c:1646  */
    break;

  case 143:
#line 581 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[0].inst);}
#line 3269 "parse.c" /* yacc.c:1646  */
    break;

  case 144:
#line 584 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code3(varpush, spop(), hoc_evalpointer);}
#line 3275 "parse.c" /* yacc.c:1646  */
    break;

  case 145:
#line 586 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; code(rangevarevalpointer); codesym(spop());}
#line 3281 "parse.c" /* yacc.c:1646  */
    break;

  case 146:
#line 588 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {hoc_ipop(); code(hoc_ob_pointer);}
#line 3287 "parse.c" /* yacc.c:1646  */
    break;

  case 147:
#line 589 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("rangevariable needs explicit arc position,eg. v(.5)");}
#line 3293 "parse.c" /* yacc.c:1646  */
    break;

  case 148:
#line 591 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = argcode(hoc_argrefarg, (yyvsp[0].narg));}
#line 3299 "parse.c" /* yacc.c:1646  */
    break;

  case 149:
#line 597 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst);}
#line 3305 "parse.c" /* yacc.c:1646  */
    break;

  case 150:
#line 599 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; }
#line 3311 "parse.c" /* yacc.c:1646  */
    break;

  case 151:
#line 602 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(forcode); codei(0); codei(0); codei(0); }
#line 3317 "parse.c" /* yacc.c:1646  */
    break;

  case 152:
#line 605 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); codein(STOP);}
#line 3323 "parse.c" /* yacc.c:1646  */
    break;

  case 153:
#line 608 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); codein(STOP);}
#line 3329 "parse.c" /* yacc.c:1646  */
    break;

  case 154:
#line 610 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; codein(STOP);}
#line 3335 "parse.c" /* yacc.c:1646  */
    break;

  case 155:
#line 613 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; codein(STOP); (yyval.inst) = (yyvsp[-1].inst);}
#line 3341 "parse.c" /* yacc.c:1646  */
    break;

  case 156:
#line 616 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); }
#line 3347 "parse.c" /* yacc.c:1646  */
    break;

  case 157:
#line 619 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst)=code(ifcode); codei(0); codei(0); codei(0); }
#line 3353 "parse.c" /* yacc.c:1646  */
    break;

  case 158:
#line 622 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; }
#line 3359 "parse.c" /* yacc.c:1646  */
    break;

  case 159:
#line 625 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { codein(STOP); (yyval.inst) = progp; }
#line 3365 "parse.c" /* yacc.c:1646  */
    break;

  case 160:
#line 628 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = progp; prog_error = (yyval.inst); }
#line 3371 "parse.c" /* yacc.c:1646  */
    break;

  case 161:
#line 630 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
			prog_parse_recover = progp;
			prog_error = (yyval.inst);
			if (fin && nrn_fw_eq(fin, stdin) && !pipeflag)
			{	int i;
				Printf(">");
				for (i = 0; i < ntab; i++)
					Printf("	");
			}
		}
#line 3386 "parse.c" /* yacc.c:1646  */
    break;

  case 163:
#line 642 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("syntax error in compound statement");}
#line 3392 "parse.c" /* yacc.c:1646  */
    break;

  case 164:
#line 647 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(constpush); codesym((yyvsp[0].sym)); PN;}
#line 3398 "parse.c" /* yacc.c:1646  */
    break;

  case 165:
#line 649 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(pushzero); PN;}
#line 3404 "parse.c" /* yacc.c:1646  */
    break;

  case 166:
#line 651 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code3(varpush, spop(), eval); PN;}
#line 3410 "parse.c" /* yacc.c:1646  */
    break;

  case 167:
#line 653 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { defnonly("$"); (yyval.inst) = argcode(arg, (yyvsp[0].narg)); PN;}
#line 3416 "parse.c" /* yacc.c:1646  */
    break;

  case 168:
#line 655 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { defnonly("$&"); (yyval.inst) = argrefcode(hoc_argref, (yyvsp[-1].narg), (yyvsp[0].narg)); PN;}
#line 3422 "parse.c" /* yacc.c:1646  */
    break;

  case 169:
#line 658 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(rangepoint); codesym(spop()); PN;}
#line 3428 "parse.c" /* yacc.c:1646  */
    break;

  case 170:
#line 660 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; code(rangevareval); codesym(spop()); PN;}
#line 3434 "parse.c" /* yacc.c:1646  */
    break;

  case 171:
#line 664 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(hoc_object_eval);}
#line 3440 "parse.c" /* yacc.c:1646  */
    break;

  case 173:
#line 668 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); code(call); codesym((yyvsp[-4].sym)); codei((yyvsp[-1].narg)); PN;}
#line 3446 "parse.c" /* yacc.c:1646  */
    break;

  case 174:
#line 670 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(call); codesym(spop()); codei((yyvsp[-1].narg)); PN;}
#line 3452 "parse.c" /* yacc.c:1646  */
    break;

  case 175:
#line 672 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst)=(yyvsp[-1].inst); code(varread); codesym(spop()); PN;}
#line 3458 "parse.c" /* yacc.c:1646  */
    break;

  case 176:
#line 674 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[-1].inst); code(bltin); codesym((yyvsp[-3].sym)); PN;}
#line 3464 "parse.c" /* yacc.c:1646  */
    break;

  case 177:
#line 676 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-1].inst); }
#line 3470 "parse.c" /* yacc.c:1646  */
    break;

  case 178:
#line 678 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {myerr("syntax error in expression");}
#line 3476 "parse.c" /* yacc.c:1646  */
    break;

  case 179:
#line 680 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(add); PN; }
#line 3482 "parse.c" /* yacc.c:1646  */
    break;

  case 180:
#line 682 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD;code(hoc_sub); PN;}
#line 3488 "parse.c" /* yacc.c:1646  */
    break;

  case 181:
#line 684 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(mul); PN;}
#line 3494 "parse.c" /* yacc.c:1646  */
    break;

  case 182:
#line 686 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_div); PN;}
#line 3500 "parse.c" /* yacc.c:1646  */
    break;

  case 183:
#line 688 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_cyclic); PN;}
#line 3506 "parse.c" /* yacc.c:1646  */
    break;

  case 184:
#line 690 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(power); PN;}
#line 3512 "parse.c" /* yacc.c:1646  */
    break;

  case 185:
#line 692 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); code(negate); PN;}
#line 3518 "parse.c" /* yacc.c:1646  */
    break;

  case 186:
#line 694 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(gt); PN;}
#line 3524 "parse.c" /* yacc.c:1646  */
    break;

  case 187:
#line 696 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(ge); PN;}
#line 3530 "parse.c" /* yacc.c:1646  */
    break;

  case 188:
#line 698 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(lt); PN;}
#line 3536 "parse.c" /* yacc.c:1646  */
    break;

  case 189:
#line 700 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(le); PN;}
#line 3542 "parse.c" /* yacc.c:1646  */
    break;

  case 190:
#line 702 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); hoc_ob_check(-1); code(eq); PN;}
#line 3548 "parse.c" /* yacc.c:1646  */
    break;

  case 191:
#line 704 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1); hoc_ob_check(-1); code(ne); PN;}
#line 3554 "parse.c" /* yacc.c:1646  */
    break;

  case 192:
#line 706 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_and); PN;}
#line 3560 "parse.c" /* yacc.c:1646  */
    break;

  case 193:
#line 708 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; TPD; code(hoc_or); PN;}
#line 3566 "parse.c" /* yacc.c:1646  */
    break;

  case 194:
#line 710 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPD; (yyval.inst) = (yyvsp[0].inst); code(hoc_not); PN;}
#line 3572 "parse.c" /* yacc.c:1646  */
    break;

  case 199:
#line 718 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s=spop()); (yyval.inst) = (yyvsp[-1].inst);
		code(arayinstal); codei((yyvsp[0].narg)); hoc_obvar_declare(s, VAR, 0);}
#line 3579 "parse.c" /* yacc.c:1646  */
    break;

  case 200:
#line 721 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code(varpush); codesym(s = spop());
		code(arayinstal); codei((yyvsp[0].narg)); hoc_obvar_declare(s, VAR, 0);}
#line 3586 "parse.c" /* yacc.c:1646  */
    break;

  case 201:
#line 726 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {pushs((yyvsp[-1].sym)); (yyval.narg) = (yyvsp[0].narg);}
#line 3592 "parse.c" /* yacc.c:1646  */
    break;

  case 202:
#line 729 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  TPD; (yyval.narg) = 1; }
#line 3598 "parse.c" /* yacc.c:1646  */
    break;

  case 203:
#line 731 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  TPD;(yyval.narg) = (yyval.narg) + 1; }
#line 3604 "parse.c" /* yacc.c:1646  */
    break;

  case 205:
#line 737 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { pushs((yyvsp[-1].sym)); (yyval.inst) = (yyvsp[0].inst); }
#line 3610 "parse.c" /* yacc.c:1646  */
    break;

  case 206:
#line 739 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { if ((yyvsp[-1].sym)->subtype == USERPROPERTY) {
			code(sec_access_push); codesym((Symbol *)0);
		  }
		pushs((yyvsp[-1].sym)); pushi(CHECK);
		}
#line 3620 "parse.c" /* yacc.c:1646  */
    break;

  case 207:
#line 744 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.inst) = (yyvsp[-2].inst);}
#line 3626 "parse.c" /* yacc.c:1646  */
    break;

  case 208:
#line 746 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { if ((yyvsp[0].sym)->subtype != USERPROPERTY) {
			acterror((yyvsp[0].sym)->name, "not a section variable");
		  }
		(yyval.inst) = (yyvsp[-2].inst); pushs((yyvsp[0].sym));
		}
#line 3636 "parse.c" /* yacc.c:1646  */
    break;

  case 209:
#line 760 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		int d1, chk;
		Symbol *sym;
		d1 = ipop();
		chk = ipop();
		sym = spop();
   if (chk) {
	if (!ISARRAY(sym)) {
		if (d1)
			acterror(sym->name, "not an array variable");
	}else{
		if ( d1 == 0 ) { /*fake index list with all 0's*/
			int i;
			for (i=0; i<sym->arayinfo->nsub; i++) {
				code(pushzero);
			}
		}			
		else if ( d1 != sym->arayinfo->nsub) {
			acterror("wrong # of subscripts",sym->name);
		}
	}
   }else {
	pushi(d1); /* must check dynamically */
   }
		pushs(sym);
		}
#line 3667 "parse.c" /* yacc.c:1646  */
    break;

  case 210:
#line 789 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
			(yyval.narg) = ipop();
		}
#line 3675 "parse.c" /* yacc.c:1646  */
    break;

  case 211:
#line 795 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { pushi(0); }
#line 3681 "parse.c" /* yacc.c:1646  */
    break;

  case 212:
#line 797 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  TPD;pushi(ipop() + 1); }
#line 3687 "parse.c" /* yacc.c:1646  */
    break;

  case 213:
#line 801 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPDYNAM; code(prexpr);}
#line 3693 "parse.c" /* yacc.c:1646  */
    break;

  case 214:
#line 803 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(prstr); }
#line 3699 "parse.c" /* yacc.c:1646  */
    break;

  case 215:
#line 805 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { TPDYNAM; code(prexpr);}
#line 3705 "parse.c" /* yacc.c:1646  */
    break;

  case 216:
#line 807 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(prstr); }
#line 3711 "parse.c" /* yacc.c:1646  */
    break;

  case 217:
#line 810 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = code(hoc_delete_symbol); codesym((yyvsp[0].sym)); }
#line 3717 "parse.c" /* yacc.c:1646  */
    break;

  case 218:
#line 814 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyvsp[0].sym)->type=FUNCTION; indef=1; }
#line 3723 "parse.c" /* yacc.c:1646  */
    break;

  case 219:
#line 816 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3731 "parse.c" /* yacc.c:1646  */
    break;

  case 220:
#line 820 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type=PROCEDURE; indef=1; }
#line 3737 "parse.c" /* yacc.c:1646  */
    break;

  case 221:
#line 822 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3745 "parse.c" /* yacc.c:1646  */
    break;

  case 222:
#line 826 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type = ITERATOR; indef=2; }
#line 3751 "parse.c" /* yacc.c:1646  */
    break;

  case 223:
#line 828 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto = (yyvsp[0].narg); indef = 0; }
#line 3759 "parse.c" /* yacc.c:1646  */
    break;

  case 224:
#line 832 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyvsp[0].sym)->type=HOCOBJFUNCTION; indef=3; }
#line 3765 "parse.c" /* yacc.c:1646  */
    break;

  case 225:
#line 834 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(procret); hoc_define((yyvsp[-4].sym));
		 (yyvsp[-4].sym)->u.u_proc->nobjauto = (yyvsp[0].narg) - localcnt;
		 (yyvsp[-4].sym)->u.u_proc->nauto=(yyvsp[0].narg); indef=0; }
#line 3773 "parse.c" /* yacc.c:1646  */
    break;

  case 226:
#line 839 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { Symbol *s; s=yylval.sym;
		if(s->type != UNDEF) acterror(s->name, "already defined");
		s->u.u_proc = (Proc *)emalloc(sizeof(Proc));
		s->u.u_proc->defn.in = STOP;
		s->u.u_proc->list = (Symlist *)0; }
#line 3783 "parse.c" /* yacc.c:1646  */
    break;

  case 231:
#line 849 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {ntab++;}
#line 3789 "parse.c" /* yacc.c:1646  */
    break;

  case 232:
#line 850 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		ntab--;
		(yyval.narg) = (yyvsp[-4].narg) + (yyvsp[-3].narg);
		}
#line 3798 "parse.c" /* yacc.c:1646  */
    break;

  case 233:
#line 856 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0; }
#line 3804 "parse.c" /* yacc.c:1646  */
    break;

  case 235:
#line 860 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.narg) = 1;}
#line 3810 "parse.c" /* yacc.c:1646  */
    break;

  case 236:
#line 862 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {(yyval.narg) = (yyvsp[-2].narg) + 1;}
#line 3816 "parse.c" /* yacc.c:1646  */
    break;

  case 237:
#line 865 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {}
#line 3822 "parse.c" /* yacc.c:1646  */
    break;

  case 238:
#line 867 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { hoc_ob_check(-1);}
#line 3828 "parse.c" /* yacc.c:1646  */
    break;

  case 240:
#line 870 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		 code(hoc_newobj_arg); codesym(hoc_which_template((yyvsp[-3].sym))); codei((yyvsp[-1].narg));
		}
#line 3836 "parse.c" /* yacc.c:1646  */
    break;

  case 241:
#line 875 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); }
#line 3842 "parse.c" /* yacc.c:1646  */
    break;

  case 242:
#line 877 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {code3(varpush, spop(), eqn_name);
		do_equation = 1; }
#line 3849 "parse.c" /* yacc.c:1646  */
    break;

  case 243:
#line 880 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[-3].inst); do_equation = 0; }
#line 3855 "parse.c" /* yacc.c:1646  */
    break;

  case 244:
#line 883 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code3(varpush,s= spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
#line 3861 "parse.c" /* yacc.c:1646  */
    break;

  case 245:
#line 885 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {Symbol *s; code3(varpush, s=spop(), dep_make); hoc_obvar_declare(s, VAR, 0);}
#line 3867 "parse.c" /* yacc.c:1646  */
    break;

  case 248:
#line 890 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(eqn_init); }
#line 3873 "parse.c" /* yacc.c:1646  */
    break;

  case 250:
#line 894 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(eqn_lhs); }
#line 3879 "parse.c" /* yacc.c:1646  */
    break;

  case 251:
#line 896 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { codein(STOP); TPD; }
#line 3885 "parse.c" /* yacc.c:1646  */
    break;

  case 252:
#line 899 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { code(eqn_rhs); }
#line 3891 "parse.c" /* yacc.c:1646  */
    break;

  case 253:
#line 901 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { codein(STOP); TPD; }
#line 3897 "parse.c" /* yacc.c:1646  */
    break;

  case 254:
#line 904 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0; localcnt = (yyval.narg);}
#line 3903 "parse.c" /* yacc.c:1646  */
    break;

  case 256:
#line 908 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = 1; localcnt = (yyval.narg);
		sp = install((yyvsp[0].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
#line 3914 "parse.c" /* yacc.c:1646  */
    break;

  case 257:
#line 915 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[-2].narg) + 1; localcnt = (yyval.narg);
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTO, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg);
		}
#line 3928 "parse.c" /* yacc.c:1646  */
    break;

  case 258:
#line 926 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    { (yyval.narg) = 0;}
#line 3934 "parse.c" /* yacc.c:1646  */
    break;

  case 260:
#line 930 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = 1;
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
#line 3948 "parse.c" /* yacc.c:1646  */
    break;

  case 261:
#line 940 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {
		Symbol *sp;
		(yyval.narg) = (yyvsp[-2].narg) + 1;
		if (hoc_table_lookup((yyvsp[0].sym)->name, p_symlist)) {
			acterror((yyvsp[0].sym)->name, "already declared local");
		}
		sp = install((yyvsp[0].sym)->name, AUTOOBJ, 0.0, &p_symlist);
		sp->u.u_auto = (yyval.narg) + localcnt;
		}
#line 3962 "parse.c" /* yacc.c:1646  */
    break;

  case 262:
#line 951 "../../../nrn/src/oc/parse.y" /* yacc.c:1646  */
    {  Symbol* s;
	   s = hoc_decl((yyvsp[0].sym));
	   if (s->subtype != NOTUSER)
		acterror("can't redeclare user variable", s->name);
	   (yyval.sym) = s;
	}
#line 3973 "parse.c" /* yacc.c:1646  */
    break;


#line 3977 "parse.c" /* yacc.c:1646  */
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
#line 963 "../../../nrn/src/oc/parse.y" /* yacc.c:1906  */

	/* end of grammar */

static void yyerror(const char* s)	/* called for yacc syntax error */
{
	execerror(s, (char *)0);
}

void acterror(const char* s, const char*t)	/* recover from action error while parsing */
{
	execerror(s,t);
}

static Inst* argrefcode(Pfrv pfrv, int i, int j){
	Inst* in;
	in = argcode(pfrv, i);
	codei(j);
	return in;
}

static Inst* argcode(Pfrv pfrv, int i) {
	Inst* in;
	if (i == 0) {
		Symbol* si = hoc_lookup("i");
		if (si->type != AUTO) {
			acterror("arg index used and i is not a LOCAL variable", 0);
		}
		in = code3(varpush, si, eval);		
		Code(pfrv);
		codei(0);
	}else{
		in = Code(pfrv);
		codei(i);
	}
	return in;
}

static void hoc_opasgn_invalid(int op) {
        if (op) {
                acterror("Invalid assignment operator.", "Only '=' allowed. ");
        }
} 

