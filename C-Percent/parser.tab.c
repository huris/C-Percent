
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 3 "parser.y"

#include "stdio.h"
#include "math.h"
#include "string.h"
#include "def.h"

extern int yylineno;
extern char *yytext;
extern FILE *yyin;
void yyerror(const char* fmt, ...);
void display(struct node *, int);


/* Line 189 of yacc.c  */
#line 87 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     TYPE = 259,
     POINTER = 260,
     MyNULL = 261,
     ID = 262,
     RELOP = 263,
     LIBRARY = 264,
     CHAR = 265,
     PLUSPLUS = 266,
     PLUSPLUS2 = 267,
     FUHE = 268,
     STRING = 269,
     FLOAT = 270,
     LP = 271,
     RP = 272,
     LB = 273,
     RB = 274,
     LC = 275,
     RC = 276,
     SEMI = 277,
     COMMA = 278,
     DOT = 279,
     PLUS = 280,
     MINUS = 281,
     STAR = 282,
     DIV = 283,
     ASSIGNOP = 284,
     AND = 285,
     OR = 286,
     NOT = 287,
     IF = 288,
     ELSE = 289,
     WHILE = 290,
     RETURN = 291,
     FOR = 292,
     STRUCT = 293,
     BREAK = 294,
     DF = 295,
     DQ = 296,
     SQ = 297,
     ADDRESS = 298,
     UMINUS = 299,
     LOWER_THEN_ELSE = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "parser.y"

	int    type_int;
	float  type_float;
	char   type_id[32];
	struct node *ptr;



/* Line 214 of yacc.c  */
#line 177 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    13,    16,    20,    25,
      27,    30,    33,    35,    39,    41,    44,    50,    52,    57,
      59,    64,    66,    71,    75,    79,    81,    84,    89,    90,
      93,    96,    98,   102,   106,   112,   116,   120,   123,   126,
     132,   137,   138,   140,   141,   144,   148,   150,   154,   156,
     160,   164,   168,   172,   176,   180,   184,   188,   192,   196,
     200,   204,   207,   210,   213,   216,   221,   224,   229,   233,
     237,   239,   241,   243,   245,   247,   251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    -1,    -1,    49,    48,    -1,    53,
      52,    22,    -1,    54,    22,    -1,    53,    58,    61,    -1,
      53,    58,    29,    50,    -1,    51,    -1,    70,    22,    -1,
      40,     9,    -1,    55,    -1,    55,    23,    52,    -1,     4,
      -1,    38,     7,    -1,    38,     7,    20,    66,    21,    -1,
       7,    -1,    55,    18,    57,    19,    -1,     7,    -1,    56,
      18,    70,    19,    -1,     3,    -1,     7,    16,    59,    17,
      -1,     7,    16,    17,    -1,    60,    23,    59,    -1,    60,
      -1,    53,    55,    -1,    20,    66,    62,    21,    -1,    -1,
      63,    62,    -1,    70,    22,    -1,    61,    -1,    36,    70,
      22,    -1,    33,    70,    63,    -1,    33,    70,    63,    34,
      63,    -1,    35,    70,    63,    -1,    37,    64,    63,    -1,
      39,    22,    -1,     1,    22,    -1,    65,    22,    65,    22,
      65,    -1,    67,    65,    22,    65,    -1,    -1,    70,    -1,
      -1,    67,    66,    -1,    53,    68,    22,    -1,    69,    -1,
      69,    23,    68,    -1,    55,    -1,    55,    29,    70,    -1,
      55,    13,    70,    -1,    70,    29,    70,    -1,    70,    30,
      70,    -1,    70,    31,    70,    -1,    70,     8,    70,    -1,
      70,    25,    70,    -1,    70,    26,    70,    -1,    70,    27,
      70,    -1,    70,    28,    70,    -1,    70,    13,    70,    -1,
      16,    70,    17,    -1,    26,    70,    -1,    32,    70,    -1,
      11,    70,    -1,    70,    11,    -1,    56,    18,    70,    19,
      -1,    43,     7,    -1,     7,    16,    71,    17,    -1,     7,
      16,    17,    -1,     7,    24,    56,    -1,     7,    -1,     3,
      -1,    15,    -1,    10,    -1,    14,    -1,    70,    23,    71,
      -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    66,    67,    70,    71,    72,    73,    74,
      76,    79,    81,    82,    85,    91,    94,    97,    98,   100,
     101,   103,   106,   107,   110,   111,   113,   116,   118,   119,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   131,
     132,   133,   134,   135,   136,   138,   140,   141,   143,   144,
     145,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "TYPE", "POINTER", "MyNULL",
  "ID", "RELOP", "LIBRARY", "CHAR", "PLUSPLUS", "PLUSPLUS2", "FUHE",
  "STRING", "FLOAT", "LP", "RP", "LB", "RB", "LC", "RC", "SEMI", "COMMA",
  "DOT", "PLUS", "MINUS", "STAR", "DIV", "ASSIGNOP", "AND", "OR", "NOT",
  "IF", "ELSE", "WHILE", "RETURN", "FOR", "STRUCT", "BREAK", "DF", "DQ",
  "SQ", "ADDRESS", "UMINUS", "LOWER_THEN_ELSE", "$accept", "Program",
  "ExtDefList", "ExtDef", "AssReturn", "Includes", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "ListDec", "ListNum",
  "FuncDec", "VarList", "ParamDec", "CompSt", "StmList", "Stmt", "ForExp",
  "ForNull", "DefList", "Def", "DecList", "Dec", "Exp", "Args", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
      50,    51,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     3,     2,     3,     4,     1,
       2,     2,     1,     3,     1,     2,     5,     1,     4,     1,
       4,     1,     4,     3,     3,     1,     2,     4,     0,     2,
       2,     1,     3,     3,     5,     3,     3,     2,     2,     5,
       4,     0,     1,     0,     2,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     4,     2,     4,     3,     3,
       1,     1,     1,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    14,     0,     0,     0,     2,     3,     9,     0,     0,
      15,    11,     1,     4,    17,     0,    12,     0,     6,    43,
       0,     5,     0,     0,    43,     0,     7,     0,     0,     0,
      43,    23,     0,     0,    25,    21,     0,    17,    13,     0,
      71,    70,    73,     0,    74,    72,     0,     0,     0,     0,
       8,     0,     0,    15,    48,     0,    46,    16,    44,    26,
      22,     0,    18,     0,     0,     0,     0,    41,     0,    31,
       0,     0,     0,     0,     0,    63,     0,    61,    62,    66,
       0,     0,    64,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,    24,    38,     0,     0,
       0,     0,     0,    41,    42,    37,    27,    29,    30,    68,
      76,     0,    19,    69,    60,     0,    54,    59,    55,    56,
      57,    58,    51,    52,    53,    50,    49,    47,    64,     0,
      33,    35,    32,    36,    41,     0,     0,    67,     0,    65,
      56,     0,     0,    41,    75,     0,    34,    41,    40,    20,
      39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    50,     7,    15,    28,     9,    16,
      51,    36,    17,    33,    34,    69,    70,    71,   101,   102,
      29,    30,    55,    56,    72,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int16 yypact[] =
{
      -3,  -101,    -2,     3,    13,  -101,    -3,  -101,    19,    22,
      26,  -101,  -101,  -101,    59,    55,    36,    -4,  -101,     7,
       0,  -101,    78,    79,     7,   225,  -101,    80,    79,    85,
       7,  -101,    79,    75,    82,  -101,    91,  -101,  -101,   150,
    -101,    84,  -101,   225,  -101,  -101,   225,   225,   225,   110,
    -101,    97,   234,  -101,     1,   103,   109,  -101,  -101,   116,
    -101,     7,  -101,   115,   225,   225,   225,    69,   125,  -101,
     133,   150,   258,   201,   124,   148,   265,   148,   148,  -101,
     225,   225,  -101,   225,  -101,   225,   225,   225,   225,   225,
     225,   225,   225,   225,  -101,    79,  -101,  -101,   113,   113,
     289,   187,   140,   225,   354,  -101,  -101,  -101,  -101,  -101,
     299,   146,  -101,   149,  -101,   323,    71,    63,    25,    25,
     148,   148,   378,   385,   147,   354,   354,  -101,    17,   225,
     134,  -101,  -101,  -101,   225,   156,   225,  -101,   225,   151,
     108,   187,   157,   225,  -101,   347,  -101,   225,  -101,  -101,
    -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -101,  -101,   174,  -101,  -101,  -101,   158,     9,  -101,   -26,
     117,  -101,  -101,   123,  -101,   175,   128,   -91,  -101,  -100,
      27,   129,   100,  -101,   -25,    64
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -62
static const yytype_int16 yytable[] =
{
      52,     1,    54,   135,     1,    10,    59,   130,   131,     8,
     133,     1,    11,    12,    92,     8,    24,    31,    75,    22,
      40,    76,    77,    78,    41,    25,    14,    42,    43,    32,
      93,    44,    45,    46,   142,     2,    82,     3,    27,    98,
      99,   100,   104,   148,    18,    27,    19,   150,   110,    48,
     146,    39,    87,    88,    22,   115,   116,    58,   117,    23,
     118,   119,   120,   121,   122,   123,   124,   125,   126,    54,
      32,    81,    40,     1,    82,    20,    41,    21,   104,    42,
      43,    35,    82,    44,    45,    46,    37,    53,    85,    86,
      87,    88,    60,    90,    91,    47,    85,    86,    87,    88,
      73,    48,   -19,    75,   140,    61,    57,    27,    74,   104,
      62,   110,    49,   145,    63,    80,    40,    79,   104,    82,
      41,    81,   104,    42,   128,    94,    83,    44,    45,    46,
     -61,   112,    95,    24,    22,   -61,   -61,    97,    85,   129,
      87,    88,    89,    90,    91,    48,    64,   105,    65,    66,
      67,    63,    68,    40,   106,    81,    49,    41,    82,    82,
      42,    43,   134,   137,    44,    45,    46,   138,   141,   -20,
      24,   -28,    85,    86,    87,    88,    47,    90,   143,   147,
      13,    38,    48,    64,    96,    65,    66,    67,    63,    68,
      40,   113,    26,    49,    41,   127,   103,    42,    43,   107,
     144,    44,    45,    46,    40,     0,     0,    24,    41,     0,
       0,    42,    43,    47,     0,    44,    45,    46,   109,    48,
      64,     0,    65,    66,    67,     0,    68,    47,    40,     0,
      49,     0,    41,    48,     0,    42,    43,     0,     0,    44,
      45,    46,    81,     0,    49,    82,     0,    83,     0,     0,
       0,    47,     0,     0,     0,     0,    84,    48,     0,    85,
      86,    87,    88,    89,    90,    91,    81,     0,    49,    82,
       0,    83,     0,    81,     0,     0,    82,     0,    83,     0,
     108,     0,   114,    85,    86,    87,    88,    89,    90,    91,
      85,    86,    87,    88,    89,    90,    91,    81,     0,     0,
      82,     0,    83,     0,     0,     0,     0,    81,     0,     0,
      82,   132,    83,     0,    85,    86,    87,    88,    89,    90,
      91,     0,   136,     0,    85,    86,    87,    88,    89,    90,
      91,    81,     0,     0,    82,     0,    83,     0,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    81,     0,     0,    82,     0,
      83,     0,    81,     0,     0,    82,   149,    83,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    85,
      86,    87,    88,    89,    90,    91,    81,     0,     0,    82,
       0,    83,     0,    81,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,     0,    90,    91,
      85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      25,     4,    28,   103,     4,     7,    32,    98,    99,     0,
     101,     4,     9,     0,    13,     6,    20,    17,    43,    18,
       3,    46,    47,    48,     7,    29,     7,    10,    11,    20,
      29,    14,    15,    16,   134,    38,    11,    40,    38,    64,
      65,    66,    67,   143,    22,    38,    20,   147,    73,    32,
     141,    24,    27,    28,    18,    80,    81,    30,    83,    23,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    95,
      61,     8,     3,     4,    11,    16,     7,    22,   103,    10,
      11,     3,    11,    14,    15,    16,     7,     7,    25,    26,
      27,    28,    17,    30,    31,    26,    25,    26,    27,    28,
      16,    32,    18,   128,   129,    23,    21,    38,    24,   134,
      19,   136,    43,   138,     1,    18,     3,     7,   143,    11,
       7,     8,   147,    10,    11,    22,    13,    14,    15,    16,
      22,     7,    23,    20,    18,    27,    28,    22,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    22,    35,    36,
      37,     1,    39,     3,    21,     8,    43,     7,    11,    11,
      10,    11,    22,    17,    14,    15,    16,    18,    34,    18,
      20,    21,    25,    26,    27,    28,    26,    30,    22,    22,
       6,    23,    32,    33,    61,    35,    36,    37,     1,    39,
       3,    74,    17,    43,     7,    95,    67,    10,    11,    71,
     136,    14,    15,    16,     3,    -1,    -1,    20,     7,    -1,
      -1,    10,    11,    26,    -1,    14,    15,    16,    17,    32,
      33,    -1,    35,    36,    37,    -1,    39,    26,     3,    -1,
      43,    -1,     7,    32,    -1,    10,    11,    -1,    -1,    14,
      15,    16,     8,    -1,    43,    11,    -1,    13,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    22,    32,    -1,    25,
      26,    27,    28,    29,    30,    31,     8,    -1,    43,    11,
      -1,    13,    -1,     8,    -1,    -1,    11,    -1,    13,    -1,
      22,    -1,    17,    25,    26,    27,    28,    29,    30,    31,
      25,    26,    27,    28,    29,    30,    31,     8,    -1,    -1,
      11,    -1,    13,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      11,    22,    13,    -1,    25,    26,    27,    28,    29,    30,
      31,    -1,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,     8,    -1,    -1,    11,    -1,    13,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    28,    29,    30,    31,     8,    -1,    -1,    11,    -1,
      13,    -1,     8,    -1,    -1,    11,    19,    13,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    25,
      26,    27,    28,    29,    30,    31,     8,    -1,    -1,    11,
      -1,    13,    -1,     8,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    25,    26,    27,    28,    -1,    30,    31,
      25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    38,    40,    47,    48,    49,    51,    53,    54,
       7,     9,     0,    48,     7,    52,    55,    58,    22,    20,
      16,    22,    18,    23,    20,    29,    61,    38,    53,    66,
      67,    17,    53,    59,    60,     3,    57,     7,    52,    66,
       3,     7,    10,    11,    14,    15,    16,    26,    32,    43,
      50,    56,    70,     7,    55,    68,    69,    21,    66,    55,
      17,    23,    19,     1,    33,    35,    36,    37,    39,    61,
      62,    63,    70,    16,    24,    70,    70,    70,    70,     7,
      18,     8,    11,    13,    22,    25,    26,    27,    28,    29,
      30,    31,    13,    29,    22,    23,    59,    22,    70,    70,
      70,    64,    65,    67,    70,    22,    21,    62,    22,    17,
      70,    71,     7,    56,    17,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    68,    11,    26,
      63,    63,    22,    63,    22,    65,    23,    17,    18,    19,
      70,    34,    65,    22,    71,    70,    63,    22,    65,    19,
      65
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 63 "parser.y"
    {display((yyvsp[(1) - (1)].ptr), 0); semantic_Analysis0((yyvsp[(1) - (1)].ptr));;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 66 "parser.y"
    {(yyval.ptr) = NULL;;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 67 "parser.y"
    {(yyval.ptr) = mknode(EXT_DEF_LIST, (yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr), NULL, yylineno);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    {(yyval.ptr) = mknode(EXT_VAR_DEF, (yyvsp[(1) - (3)].ptr), (yyvsp[(2) - (3)].ptr), NULL, yylineno);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (2)].ptr);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    {(yyval.ptr) = mknode(FUNC_DEF, (yyvsp[(1) - (3)].ptr), (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr), yylineno);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    {(yyval.ptr) = mknode(FUNC_DEF, (yyvsp[(1) - (4)].ptr), (yyvsp[(2) - (4)].ptr), (yyvsp[(4) - (4)].ptr), yylineno);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    {(yyval.ptr) = mknode(RETURN, (yyvsp[(1) - (2)].ptr), NULL, NULL, yylineno);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {(yyval.ptr) = mknode(Includes, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr)->type_id, (yyvsp[(2) - (2)].type_id));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {(yyval.ptr) = mknode(EXT_DEC_LIST, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    {(yyval.ptr) = mknode(TYPE, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id)); 
            if(strcmp((yyval.ptr) -> type_id, "int") == 0) (yyval.ptr) -> type = INTEGER;
			else if(strcmp((yyval.ptr) -> type_id, "float") == 0)(yyval.ptr) -> type = FLOAT;
			else if(strcmp((yyval.ptr) -> type_id, "char") == 0)(yyval.ptr) -> type = CHAR;
            else if(strcmp((yyval.ptr) -> type_id, "string") == 0) (yyval.ptr) -> type = STRING;
			else (yyval.ptr) -> type = POINTER;;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {(yyval.ptr) = mknode(StructSpecifier, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (2)].type_id));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {(yyval.ptr) = mknode(StructSpecifier, (yyvsp[(4) - (5)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (5)].type_id)); (yyval.ptr) -> isSTRUCT = 1;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval.ptr) = mknode(ID, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {(yyval.ptr) = mknode(Static_List, (yyvsp[(1) - (4)].ptr), (yyvsp[(3) - (4)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].ptr) -> type_id); (yyval.ptr) -> isShuzu = 1;;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {(yyval.ptr) = mknode(ID, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {(yyval.ptr) = mknode(Static_List, (yyvsp[(1) - (4)].ptr), (yyvsp[(3) - (4)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].ptr) -> type_id); (yyval.ptr) -> isShuzu = 1;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {(yyval.ptr) = mknode(INTEGER, NULL, NULL, NULL, yylineno); (yyval.ptr) -> type_int = (yyvsp[(1) - (1)].type_int); (yyval.ptr) -> type = INTEGER;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {(yyval.ptr) = mknode(FUNC_DEC, (yyvsp[(3) - (4)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].type_id));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {(yyval.ptr) = mknode(FUNC_DEC, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (3)].type_id));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 110 "parser.y"
    {(yyval.ptr) = mknode(PARAM_LIST, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 111 "parser.y"
    {(yyval.ptr) = mknode(PARAM_LIST, (yyvsp[(1) - (1)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].ptr));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval.ptr) = mknode(PARAM_DEC, (yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr), NULL, yylineno);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {(yyval.ptr) = mknode(COMP_STM, (yyvsp[(2) - (4)].ptr), (yyvsp[(3) - (4)].ptr), NULL, yylineno);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 118 "parser.y"
    {(yyval.ptr) = NULL;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    {(yyval.ptr) = mknode(STM_LIST, (yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr), NULL, yylineno);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    {(yyval.ptr) = mknode(EXP_STMT, (yyvsp[(1) - (2)].ptr), NULL, NULL, yylineno);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {(yyval.ptr) = mknode(RETURN, (yyvsp[(2) - (3)].ptr), NULL, NULL, yylineno);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    {(yyval.ptr) = mknode(IF_THEN, (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {(yyval.ptr) = mknode(IF_THEN_ELSE, (yyvsp[(2) - (5)].ptr), (yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr), yylineno);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {(yyval.ptr) = mknode(WHILE, (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    {(yyval.ptr) = mknode(FOR, (yyvsp[(2) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 128 "parser.y"
    {(yyval.ptr) = mknode(BREAK, NULL, NULL, NULL, yylineno);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {(yyval.ptr) = NULL;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {(yyval.ptr) = mknode(ForExp, (yyvsp[(1) - (5)].ptr), (yyvsp[(3) - (5)].ptr), (yyvsp[(5) - (5)].ptr), yylineno);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {(yyval.ptr) = mknode(ForExp, (yyvsp[(1) - (4)].ptr), (yyvsp[(2) - (4)].ptr), (yyvsp[(4) - (4)].ptr), yylineno);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {(yyval.ptr) = NULL;;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {(yyval.ptr) = NULL;;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {(yyval.ptr) = mknode(DEF_LIST, (yyvsp[(1) - (2)].ptr), (yyvsp[(2) - (2)].ptr), NULL, yylineno);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {(yyval.ptr) = mknode(VAR_DEF, (yyvsp[(1) - (3)].ptr), (yyvsp[(2) - (3)].ptr), NULL, yylineno);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {(yyval.ptr) = mknode(DEC_LIST, (yyvsp[(1) - (1)].ptr), NULL, NULL, yylineno);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {(yyval.ptr) = mknode(DEC_LIST, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {(yyval.ptr) = mknode(ASSIGNOP, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "ASSIGNOP");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {(yyval.ptr) = mknode(FUHE, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (3)].type_id));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {(yyval.ptr) = mknode(ASSIGNOP, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "ASSIGNOP");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {(yyval.ptr) = mknode(AND, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "AND");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {(yyval.ptr) = mknode(OR, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "OR");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.ptr) = mknode(RELOP, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (3)].type_id));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {(yyval.ptr) = mknode(PLUS, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "PLUS");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    {(yyval.ptr) = mknode(MINUS, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "MINUS");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {(yyval.ptr) = mknode(STAR, (yyvsp[(1) - (3)].ptr),(yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "STAR");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.ptr) = mknode(DIV, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, "DIV");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval.ptr) = mknode(FUHE ,(yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (3)].type_id));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.ptr) = mknode(UMINUS, (yyvsp[(2) - (2)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, "UMINUS");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyval.ptr) = mknode(NOT, (yyvsp[(2) - (2)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, "NOT");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {(yyval.ptr) = mknode(PLUSPLUS, (yyvsp[(2) - (2)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (2)].type_id));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 160 "parser.y"
    {(yyval.ptr) = mknode(PLUSPLUS2, (yyvsp[(1) - (2)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (2)].type_id));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {(yyval.ptr) = mknode(LIST_CALL, (yyvsp[(1) - (4)].ptr), (yyvsp[(3) - (4)].ptr), NULL, yylineno); if((yyvsp[(1) - (4)].ptr) -> kind == ID) strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].ptr)); else strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].ptr) -> type_id); (yyval.ptr) -> isShuzu = 1;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyval.ptr) = mknode(POINTER, (yyvsp[(2) - (2)].type_id), NULL, NULL, yylineno);strcpy((yyval.ptr) -> type_id, (yyvsp[(2) - (2)].type_id));;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyval.ptr) = mknode(FUNC_CALL, (yyvsp[(3) - (4)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (4)].type_id));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.ptr) = mknode(FUNC_CALL, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (3)].type_id));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyval.ptr) = mknode(STRUCT_CALL, (yyvsp[(3) - (3)].ptr), NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (3)].type_id));;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    {(yyval.ptr) = mknode(ID, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id));;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {(yyval.ptr) = mknode(INTEGER, NULL, NULL, NULL, yylineno); (yyval.ptr) -> type_int = (yyvsp[(1) - (1)].type_int); (yyval.ptr) -> type = INTEGER;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    {(yyval.ptr) = mknode(FLOAT, NULL, NULL, NULL, yylineno); (yyval.ptr) -> type_float = (yyvsp[(1) - (1)].type_float); (yyval.ptr) -> type = FLOAT;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {(yyval.ptr) = mknode(CHAR, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id)); (yyval.ptr) -> type = CHAR;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyval.ptr) = mknode(STRING, NULL, NULL, NULL, yylineno); strcpy((yyval.ptr) -> type_id, (yyvsp[(1) - (1)].type_id)); (yyval.ptr) -> type = STRING; (yyval.ptr) -> num = strlen((yyvsp[(1) - (1)].type_id));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyval.ptr) = mknode(ARGS, (yyvsp[(1) - (3)].ptr), (yyvsp[(3) - (3)].ptr), NULL, yylineno);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {(yyval.ptr) = mknode(ARGS, (yyvsp[(1) - (1)].ptr), NULL, NULL, yylineno);;}
    break;



/* Line 1455 of yacc.c  */
#line 2147 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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
		      yytoken, &yylval, &yylloc);
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

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 174 "parser.y"



#include<stdarg.h>

void yyerror(const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    fprintf(stderr, "Grammar Error at Line %d Column %d: ", yylloc.first_line, yylloc.first_column);
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, ".\n");
}

int main(int argc, char *argv[]) {
	if (!(yyin = fopen(argv[1], "r"))) return 1;
	
    yylineno = 1;
	yyparse();

	return 0;
}
