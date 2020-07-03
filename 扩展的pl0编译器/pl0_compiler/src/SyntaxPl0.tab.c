/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_VAL = 258,
     FLOAT_VAL = 259,
     CHAR_VAL = 260,
     STRING_VAL = 261,
     CMP = 262,
     IDENTIFIER = 263,
     PROCEDURE = 264,
     IF = 265,
     THEN = 266,
     WHILE = 267,
     DO = 268,
     READ = 269,
     WRITE = 270,
     CALL = 271,
     _BEGIN_ = 272,
     END = 273,
     CONST = 274,
     VAR = 275,
     ODD = 276,
     FOR = 277,
     TO = 278,
     REPEAT = 279,
     UNTIL = 280,
     ARRAY = 281,
     OF = 282,
     INT_ = 283,
     FLOAT = 284,
     CHAR = 285,
     STRING = 286,
     SL_PAREN = 287,
     SR_PAREN = 288,
     ML_PAREN = 289,
     MR_PAREN = 290,
     LL_PAREN = 291,
     LR_PAREN = 292,
     COMMA = 293,
     COLON = 294,
     SEMI = 295,
     DOTDOT = 296,
     DOT = 297,
     MINUS = 298,
     PLUS = 299,
     DIVIDE = 300,
     TIMES = 301,
     ASSIGN = 302,
     LOWERELSE = 303,
     ELSE = 304
   };
#endif
/* Tokens.  */
#define INTEGER_VAL 258
#define FLOAT_VAL 259
#define CHAR_VAL 260
#define STRING_VAL 261
#define CMP 262
#define IDENTIFIER 263
#define PROCEDURE 264
#define IF 265
#define THEN 266
#define WHILE 267
#define DO 268
#define READ 269
#define WRITE 270
#define CALL 271
#define _BEGIN_ 272
#define END 273
#define CONST 274
#define VAR 275
#define ODD 276
#define FOR 277
#define TO 278
#define REPEAT 279
#define UNTIL 280
#define ARRAY 281
#define OF 282
#define INT_ 283
#define FLOAT 284
#define CHAR 285
#define STRING 286
#define SL_PAREN 287
#define SR_PAREN 288
#define ML_PAREN 289
#define MR_PAREN 290
#define LL_PAREN 291
#define LR_PAREN 292
#define COMMA 293
#define COLON 294
#define SEMI 295
#define DOTDOT 296
#define DOT 297
#define MINUS 298
#define PLUS 299
#define DIVIDE 300
#define TIMES 301
#define ASSIGN 302
#define LOWERELSE 303
#define ELSE 304




/* Copy the first part of user declarations.  */
#line 1 "SyntaxPl0.y"

#include "define.h"
#define MAGENTA "\033[35m"      /* Magenta */
extern int row,column;
extern void yyerror(char const* s);
extern int yylex(void);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 10 "SyntaxPl0.y"
{
      struct {
        int i_val;
        float f_val;
        int type_; //int:0 float:1
      }count;

      struct {
        char* id;
        int offset;
        int type_;//int:0 float:1 char:2 string:3 aryint:4 aryfloat:5
      }Identi;
      
      struct {
	      int dimension;
	      int low[10];
	      int high[10];
        int search[10];
      }array__;

     
      int i_val;
      float f_val;
      char* str; 
}
/* Line 193 of yacc.c.  */
#line 229 "SyntaxPl0.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 242 "SyntaxPl0.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,    11,    15,    16,    17,    19,    22,
      25,    29,    32,    34,    36,    41,    45,    49,    51,    55,
      59,    64,    68,    72,    74,    78,    86,    92,    96,    98,
     100,   102,   104,   106,   108,   113,   117,   121,   123,   124,
     128,   130,   133,   136,   138,   141,   144,   147,   150,   153,
     155,   160,   162,   166,   168,   172,   176,   180,   184,   187,
     194,   205,   206,   207,   211,   215,   218,   221,   223,   227,
     231,   233,   235,   237,   239,   243,   250,   259,   266,   267,
     268,   269,   274,   279,   284,   289
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    52,    42,    -1,    53,    55,    54,    67,
      -1,    53,    54,    67,    -1,    -1,    -1,    56,    -1,    56,
      59,    -1,    56,    65,    -1,    56,    59,    65,    -1,    59,
      65,    -1,    59,    -1,    65,    -1,    56,    19,    57,    40,
      -1,    19,    57,    40,    -1,    57,    38,    58,    -1,    58,
      -1,     8,    47,     3,    -1,     8,    47,     4,    -1,    59,
      20,    60,    40,    -1,    20,    60,    40,    -1,    60,    38,
      61,    -1,    61,    -1,     8,    27,    64,    -1,     8,    26,
      34,    62,    35,    27,    63,    -1,    62,    38,     3,    41,
       3,    -1,     3,    41,     3,    -1,    28,    -1,    29,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    65,    66,
      52,    40,    -1,    66,    52,    40,    -1,     9,     8,    40,
      -1,    68,    -1,    -1,    17,    69,    18,    -1,    70,    -1,
      69,    70,    -1,    73,    40,    -1,    75,    -1,    87,    40,
      -1,    88,    40,    -1,    89,    40,    -1,    81,    40,    -1,
      82,    40,    -1,    83,    -1,     8,    34,    72,    35,    -1,
       8,    -1,    72,    38,    78,    -1,    78,    -1,    71,    47,
      78,    -1,    71,    47,     5,    -1,    71,    47,     6,    -1,
      78,     7,    78,    -1,    21,    78,    -1,    10,    74,    76,
      11,    68,    40,    -1,    10,    74,    76,    11,    68,    40,
      49,    77,    68,    40,    -1,    -1,    -1,    78,    44,    79,
      -1,    78,    43,    79,    -1,    44,    79,    -1,    43,    79,
      -1,    79,    -1,    79,    46,    80,    -1,    79,    45,    80,
      -1,    80,    -1,    71,    -1,     3,    -1,     4,    -1,    32,
      78,    33,    -1,    12,    84,    74,    13,    85,    67,    -1,
      22,    73,    23,    84,    74,    13,    85,    67,    -1,    24,
      86,    67,    40,    25,    74,    -1,    -1,    -1,    -1,    16,
      32,     8,    33,    -1,    14,    32,    71,    33,    -1,    15,
      32,    71,    33,    -1,    15,    32,     5,    33,    -1,    15,
      32,     6,    33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    61,    63,    66,    78,    93,    95,    97,
      99,   101,   103,   105,   109,   111,   114,   116,   119,   129,
     141,   143,   146,   149,   153,   162,   189,   194,   200,   203,
     207,   210,   213,   216,   221,   229,   238,   251,   253,   256,
     259,   261,   263,   265,   267,   269,   271,   273,   275,   277,
     282,   317,   334,   344,   355,   379,   397,   416,   443,   457,
     460,   464,   471,   479,   509,   539,   557,   578,   597,   628,
     671,   690,   718,   728,   738,   757,   764,   771,   777,   781,
     789,   794,   807,   839,   878,   890
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_VAL", "FLOAT_VAL", "CHAR_VAL",
  "STRING_VAL", "CMP", "IDENTIFIER", "PROCEDURE", "IF", "THEN", "WHILE",
  "DO", "READ", "WRITE", "CALL", "_BEGIN_", "END", "CONST", "VAR", "ODD",
  "FOR", "TO", "REPEAT", "UNTIL", "ARRAY", "OF", "INT_", "FLOAT", "CHAR",
  "STRING", "SL_PAREN", "SR_PAREN", "ML_PAREN", "MR_PAREN", "LL_PAREN",
  "LR_PAREN", "COMMA", "COLON", "SEMI", "DOTDOT", "DOT", "MINUS", "PLUS",
  "DIVIDE", "TIMES", "ASSIGN", "LOWERELSE", "ELSE", "$accept", "Program",
  "SubPro", "BeforeDec", "BeforeSta", "DeclarePart", "ConstDec",
  "ConstDef", "CDefine", "VarDec", "IdentiDef", "IDefine", "Dimension",
  "ArrayType", "VarType", "ProDec", "ProceHead", "Statement", "ComplexS",
  "States", "Statements", "Identifier", "GetDi", "AssignS", "Condition",
  "CondiS", "BeforeThen", "BeforeElseDo", "Expr", "Term", "Factor",
  "While_Loop", "For_Loop", "Repeat_Loop", "BeforeCond", "BeforeCondDo",
  "BeforeRepeat", "Call_Func", "Read_Func", "Write_Func", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    65,    65,    66,    67,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    77,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    80,    80,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    89,    89
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     3,     0,     0,     1,     2,     2,
       3,     2,     1,     1,     4,     3,     3,     1,     3,     3,
       4,     3,     3,     1,     3,     7,     5,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     1,     0,     3,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       4,     1,     3,     1,     3,     3,     3,     3,     2,     6,
      10,     0,     0,     3,     3,     2,     2,     1,     3,     3,
       1,     1,     1,     1,     3,     6,     8,     6,     0,     0,
       0,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     6,     1,     2,     0,     0,     0,    38,
       6,     7,    12,    13,     5,     0,     0,     0,    17,     0,
       0,    23,     0,     4,    37,    38,     0,     8,     9,     0,
      11,     5,     0,    36,     0,     0,    15,     0,     0,     0,
      21,    51,     0,    78,     0,     0,     0,     0,    80,     0,
      40,     0,     0,    43,     0,     0,    49,     0,     0,     0,
       3,     0,    10,     0,     0,    35,    18,    19,    16,     0,
      30,    31,    32,    33,    24,    22,     0,    72,    73,     0,
       0,     0,     0,    71,    61,     0,    67,    70,     0,     0,
       0,     0,     0,    38,    39,    41,     0,    42,    47,    48,
      44,    45,    46,    14,    20,    34,     0,     0,     0,    53,
      58,     0,    66,    65,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,    55,    56,
      54,     0,     0,     0,    50,     0,    74,     0,    57,    64,
      63,    69,    68,    79,    82,    84,    85,    83,    81,     0,
       0,    27,     0,     0,    52,     0,    38,     0,     0,    28,
      29,    25,     0,    59,    75,    79,    77,    26,    62,    38,
       0,    76,     0,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,     9,    10,    11,    17,    18,    12,
      20,    21,   107,   161,    74,    13,    14,    23,    24,    49,
      50,    83,   108,    52,    84,    53,   114,   170,    85,    86,
      87,    54,    55,    56,    88,   156,    93,    57,    58,    59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -125
static const yytype_int16 yypact[] =
{
    -125,    47,   -27,    39,  -125,  -125,    20,    43,    59,    60,
    -125,    87,    24,    88,  -125,    45,    81,    -3,  -125,    78,
      15,  -125,    79,  -125,  -125,    60,    43,    24,    88,    59,
      88,  -125,    75,  -125,   114,    43,  -125,    95,    82,    59,
    -125,    96,    13,  -125,   100,   101,   102,   119,  -125,    68,
    -125,    89,    97,  -125,    98,    99,  -125,   103,   105,   106,
    -125,    41,    88,    76,   107,  -125,  -125,  -125,  -125,   132,
    -125,  -125,  -125,  -125,  -125,  -125,    22,  -125,  -125,    22,
      22,    28,    28,  -125,  -125,    -2,    74,  -125,    13,   119,
      94,   133,   117,    60,  -125,  -125,     6,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,   108,   -16,    26,    80,
      80,    65,    74,    74,   131,    22,    28,    28,    28,    28,
     135,   118,   120,   121,   122,   123,  -125,   110,  -125,  -125,
      80,   149,   130,   155,  -125,    22,  -125,    60,    80,    74,
      74,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,    13,
     134,  -125,    93,   124,    80,   126,    60,   147,    13,  -125,
    -125,  -125,   158,   113,  -125,  -125,  -125,  -125,  -125,    60,
      60,  -125,   127,  -125
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,    -8,  -125,   153,  -125,  -125,   138,   136,   157,
     140,   137,  -125,  -125,  -125,    61,   -10,   -25,  -124,  -125,
     125,   -20,  -125,   128,   -87,  -125,  -125,  -125,   -72,   -42,
       7,  -125,  -125,  -125,    44,     8,  -125,  -125,  -125,  -125
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      60,   120,    51,    31,   109,   115,    32,   110,   111,    77,
      78,   128,   129,   155,    41,     5,    77,    78,    31,   132,
      31,    41,   133,    64,   130,    77,    78,    51,    15,    51,
      41,    77,    78,     6,    79,    35,    41,    36,    80,   112,
     113,   116,   117,   138,    29,    80,   172,     4,     6,    81,
      82,    16,    31,    39,    80,    40,    81,    82,     7,     8,
      80,   134,   157,   154,   135,    81,    82,    19,   127,   121,
     124,   166,    28,    30,   139,   140,    41,    22,    42,    35,
      43,   103,    44,    45,    46,    33,    94,    41,    62,    42,
      47,    43,    48,    44,    45,    46,     6,     6,   136,   122,
     123,    47,    41,    48,    37,    38,    26,     8,   116,   117,
      70,    71,    72,    73,    39,    65,   104,    66,    67,   118,
     119,   159,   160,   116,   117,   141,   142,    41,    34,    69,
      76,   164,    89,    90,    91,   106,    96,    97,    98,    99,
     126,   125,   137,   100,   171,   101,   102,   105,   143,   131,
     150,   144,   151,   145,   146,   147,   148,   152,   153,   158,
     165,   167,   168,    25,    61,   162,   163,   173,    27,    63,
     149,    68,     0,   169,    95,    92,    75
};

static const yytype_int16 yycheck[] =
{
      25,    88,    22,    13,    76,     7,    14,    79,    80,     3,
       4,     5,     6,   137,     8,    42,     3,     4,    28,    35,
      30,     8,    38,    31,    96,     3,     4,    47,     8,    49,
       8,     3,     4,     9,    21,    38,     8,    40,    32,    81,
      82,    43,    44,   115,    20,    32,   170,     0,     9,    43,
      44,     8,    62,    38,    32,    40,    43,    44,    19,    20,
      32,    35,   149,   135,    38,    43,    44,     8,    93,    89,
      90,   158,    11,    12,   116,   117,     8,    17,    10,    38,
      12,    40,    14,    15,    16,    40,    18,     8,    27,    10,
      22,    12,    24,    14,    15,    16,     9,     9,    33,     5,
       6,    22,     8,    24,    26,    27,    19,    20,    43,    44,
      28,    29,    30,    31,    38,    40,    40,     3,     4,    45,
      46,    28,    29,    43,    44,   118,   119,     8,    47,    34,
      34,   156,    32,    32,    32,     3,    47,    40,    40,    40,
      23,     8,    11,    40,   169,    40,    40,    40,    13,    41,
      40,    33,     3,    33,    33,    33,    33,    27,     3,    25,
      13,     3,    49,    10,    26,    41,    40,    40,    11,    29,
     126,    35,    -1,   165,    49,    47,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,    53,     0,    42,     9,    19,    20,    54,
      55,    56,    59,    65,    66,     8,     8,    57,    58,     8,
      60,    61,    17,    67,    68,    54,    19,    59,    65,    20,
      65,    66,    52,    40,    47,    38,    40,    26,    27,    38,
      40,     8,    10,    12,    14,    15,    16,    22,    24,    69,
      70,    71,    73,    75,    81,    82,    83,    87,    88,    89,
      67,    57,    65,    60,    52,    40,     3,     4,    58,    34,
      28,    29,    30,    31,    64,    61,    34,     3,     4,    21,
      32,    43,    44,    71,    74,    78,    79,    80,    84,    32,
      32,    32,    73,    86,    18,    70,    47,    40,    40,    40,
      40,    40,    40,    40,    40,    40,     3,    62,    72,    78,
      78,    78,    79,    79,    76,     7,    43,    44,    45,    46,
      74,    71,     5,     6,    71,     8,    23,    67,     5,     6,
      78,    41,    35,    38,    35,    38,    33,    11,    78,    79,
      79,    80,    80,    13,    33,    33,    33,    33,    33,    84,
      40,     3,    27,     3,    78,    68,    85,    74,    25,    28,
      29,    63,    41,    40,    67,    13,    74,     3,    49,    85,
      77,    67,    68,    40
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
              ;}
    break;

  case 3:
#line 61 "SyntaxPl0.y"
    {
              ;}
    break;

  case 4:
#line 63 "SyntaxPl0.y"
    {
              ;}
    break;

  case 5:
#line 66 "SyntaxPl0.y"
    {
                if(symtable_size()!=0){
                  display_top++;
                  display_stack[display_top]=symtable_size()+1;
                }
                backPatch_table[++backPatch_table_top]=code_line;
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              ;}
    break;

  case 6:
#line 78 "SyntaxPl0.y"
    {
                if(backPatch_table_top>-1){
                  backpatch(backPatch_table[backPatch_table_top--],code_line);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(display_stack[display_top]==1){
                  gen(instruction::INI,0,sym_top+3,p);
                }
                else
                {
                  gen(instruction::INI,0,sym_top-display_stack[display_top]+1+3,p);
                }
              ;}
    break;

  case 7:
#line 93 "SyntaxPl0.y"
    {
              ;}
    break;

  case 8:
#line 95 "SyntaxPl0.y"
    {
              ;}
    break;

  case 9:
#line 97 "SyntaxPl0.y"
    {
              ;}
    break;

  case 10:
#line 99 "SyntaxPl0.y"
    {
              ;}
    break;

  case 11:
#line 101 "SyntaxPl0.y"
    {
              ;}
    break;

  case 12:
#line 103 "SyntaxPl0.y"
    {
              ;}
    break;

  case 13:
#line 105 "SyntaxPl0.y"
    {
              ;}
    break;

  case 14:
#line 109 "SyntaxPl0.y"
    {
              ;}
    break;

  case 15:
#line 111 "SyntaxPl0.y"
    {
              ;}
    break;

  case 16:
#line 114 "SyntaxPl0.y"
    {
              ;}
    break;

  case 17:
#line 116 "SyntaxPl0.y"
    {
              ;}
    break;

  case 18:
#line 119 "SyntaxPl0.y"
    {                
                if(if_declared((yyvsp[(1) - (3)].str))==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.i_val=(yyvsp[(3) - (3)].i_val);
                    temp.type_=all_type_val_value::int_;
                    symtable_push((yyvsp[(1) - (3)].str),Symbol::const_,temp);
                }
              ;}
    break;

  case 19:
#line 129 "SyntaxPl0.y"
    {
                if(if_declared((yyvsp[(1) - (3)].str))==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.f_val=(yyvsp[(3) - (3)].f_val);
                    temp.type_=all_type_val_value::float_;
                    symtable_push((yyvsp[(1) - (3)].str),Symbol::const_,temp);
                }
             ;}
    break;

  case 20:
#line 141 "SyntaxPl0.y"
    {
              ;}
    break;

  case 21:
#line 143 "SyntaxPl0.y"
    {
              ;}
    break;

  case 22:
#line 146 "SyntaxPl0.y"
    {
              
              ;}
    break;

  case 23:
#line 149 "SyntaxPl0.y"
    {
              
              ;}
    break;

  case 24:
#line 153 "SyntaxPl0.y"
    {
                if(if_declared((yyvsp[(1) - (3)].str))==0)
                {
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define((yyvsp[(3) - (3)].i_val));
                    symtable_push((yyvsp[(1) - (3)].str),Symbol::var_,temp);
                }
              ;}
    break;

  case 25:
#line 162 "SyntaxPl0.y"
    {
                if(if_declared((yyvsp[(1) - (7)].str))==0)
                {
                    array_stack_top_index++;
                    ary_stack[array_stack_top_index].id=(yyvsp[(1) - (7)].str);
                    ary_stack[array_stack_top_index].dimension=(yyvsp[(4) - (7)].array__).dimension;
                    ary_stack[array_stack_top_index].type_=(yyvsp[(7) - (7)].i_val);
                    for(int index=0;index<(yyvsp[(4) - (7)].array__).dimension;index++)
                    {
                      ary_stack[array_stack_top_index].low[index]=(yyvsp[(4) - (7)].array__).low[index];
                      ary_stack[array_stack_top_index].high[index]=(yyvsp[(4) - (7)].array__).high[index];
                    }
                    int s=(yyvsp[(4) - (7)].array__).high[0]-(yyvsp[(4) - (7)].array__).low[0]+1;
	                  if((yyvsp[(4) - (7)].array__).dimension>1)
		                  for(int i=1;i<(yyvsp[(4) - (7)].array__).dimension;i++)
			                  s=s*((yyvsp[(4) - (7)].array__).high[i]-(yyvsp[(4) - (7)].array__).low[i]+1);
	                  ary_stack[array_stack_top_index].size=s;
                    
                    all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    temp.type_=all_type_val_value::define((yyvsp[(7) - (7)].i_val));                
                    for(int i=0;i<s;i++)
                      symtable_push((yyvsp[(1) - (7)].str),Symbol::var_,temp);
                }
              ;}
    break;

  case 26:
#line 189 "SyntaxPl0.y"
    {
                (yyval.array__).dimension=(yyvsp[(1) - (5)].array__).dimension+1;
                (yyval.array__).low[(yyvsp[(1) - (5)].array__).dimension]=(yyvsp[(3) - (5)].i_val);
                (yyval.array__).high[(yyvsp[(1) - (5)].array__).dimension]=(yyvsp[(5) - (5)].i_val);
              ;}
    break;

  case 27:
#line 194 "SyntaxPl0.y"
    {
                (yyval.array__).dimension=1;
                (yyval.array__).low[0]=(yyvsp[(1) - (3)].i_val);
                (yyval.array__).high[0]=(yyvsp[(3) - (3)].i_val);
              ;}
    break;

  case 28:
#line 200 "SyntaxPl0.y"
    {
                (yyval.i_val)=4;
              ;}
    break;

  case 29:
#line 203 "SyntaxPl0.y"
    {
                (yyval.i_val)=5;
              ;}
    break;

  case 30:
#line 207 "SyntaxPl0.y"
    {
                (yyval.i_val)=0;
              ;}
    break;

  case 31:
#line 210 "SyntaxPl0.y"
    {
                (yyval.i_val)=1;
              ;}
    break;

  case 32:
#line 213 "SyntaxPl0.y"
    {
                (yyval.i_val)=2;
              ;}
    break;

  case 33:
#line 216 "SyntaxPl0.y"
    {
                (yyval.i_val)=3;
              ;}
    break;

  case 34:
#line 221 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              ;}
    break;

  case 35:
#line 229 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,0,p);
                current_Level--;
                symtable_pop();
                addr=2+symtable_size();
              ;}
    break;

  case 36:
#line 238 "SyntaxPl0.y"
    {
                addr=3;
                if(if_declared((yyvsp[(2) - (3)].str))==0 && find_pro((yyvsp[(2) - (3)].str))==-1)
                {
                    
                    struct all_type_val_value temp;
                    init_for_gen_pcode(temp);
                    symtable_push((yyvsp[(2) - (3)].str),Symbol::proc,temp);
                    current_Level++;
                }    
              ;}
    break;

  case 37:
#line 251 "SyntaxPl0.y"
    {
              ;}
    break;

  case 38:
#line 253 "SyntaxPl0.y"
    { 
              ;}
    break;

  case 39:
#line 256 "SyntaxPl0.y"
    {
              ;}
    break;

  case 40:
#line 259 "SyntaxPl0.y"
    {
              ;}
    break;

  case 41:
#line 261 "SyntaxPl0.y"
    {
              ;}
    break;

  case 42:
#line 263 "SyntaxPl0.y"
    {
              ;}
    break;

  case 43:
#line 265 "SyntaxPl0.y"
    {
              ;}
    break;

  case 44:
#line 267 "SyntaxPl0.y"
    {
              ;}
    break;

  case 45:
#line 269 "SyntaxPl0.y"
    {
              ;}
    break;

  case 46:
#line 271 "SyntaxPl0.y"
    {
              ;}
    break;

  case 47:
#line 273 "SyntaxPl0.y"
    {
              ;}
    break;

  case 48:
#line 275 "SyntaxPl0.y"
    {
              ;}
    break;

  case 49:
#line 277 "SyntaxPl0.y"
    {
              ;}
    break;

  case 50:
#line 282 "SyntaxPl0.y"
    {                              
                int arypos=find_ary((yyvsp[(1) - (4)].str));
                if(arypos==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<(yyvsp[(1) - (4)].str)<<" isn't  array!"<<std::endl;
                  exit(1);
                }
                if(ary_stack[arypos].dimension != (yyvsp[(3) - (4)].array__).dimension)
                { // dimension error
                  std::cout<<MAGENTA<<"Semantic error! "<<(yyvsp[(1) - (4)].str)<<"\'s dimension is not right!"<<std::endl;
                  exit(1);
                }
                for(int i=0;i<(yyvsp[(3) - (4)].array__).dimension;i++)
                { // search error
                  if((yyvsp[(3) - (4)].array__).search[i]<ary_stack[arypos].low[i] || (yyvsp[(3) - (4)].array__).search[i]>ary_stack[arypos].high[i])
                  {
                    std::cout<<MAGENTA<<(yyvsp[(3) - (4)].array__).search[i]<<' '<<ary_stack[arypos].low[i]<<' '<<ary_stack[arypos].high[i]<<std::endl;
                    std::cout<<MAGENTA<<"Semantic Error! Array Dimension Over Bound!"<<std::endl;
                    exit(1);
                  }
                }
                
                int offset=(yyvsp[(3) - (4)].array__).search[0]-ary_stack[arypos].low[0];
                if((yyvsp[(3) - (4)].array__).dimension>1)
                {
                  for(int i=1;i<(yyvsp[(3) - (4)].array__).dimension;i++)
                  {
                    offset=offset*(ary_stack[arypos].high[i]-ary_stack[arypos].low[i]+1);
                    offset=offset+(yyvsp[(3) - (4)].array__).search[i]-ary_stack[arypos].low[i];
                  }
                }
                (yyval.Identi).offset=offset;
                (yyval.Identi).id=(yyvsp[(1) - (4)].str);
                (yyval.Identi).type_=ary_stack[arypos].type_;
              ;}
    break;

  case 51:
#line 317 "SyntaxPl0.y"
    {                
                int pos=find_sign((yyvsp[(1) - (1)].str));
                if(symtable[pos].symtype_==Symbol::proc)
                {
                  exit(1);
                }
                if(symtable[pos].var.type_==all_type_val_value::aryint || symtable[pos].var.type_==all_type_val_value::aryfloat)
                {
                  
                  exit(1);
                }

                (yyval.Identi).offset=0;
                (yyval.Identi).id=(yyvsp[(1) - (1)].str);  
                (yyval.Identi).type_=symtable[pos].var.type_;                              
              ;}
    break;

  case 52:
#line 334 "SyntaxPl0.y"
    {
                (yyval.array__).dimension=(yyvsp[(1) - (3)].array__).dimension+1;
                if((yyvsp[(3) - (3)].count).type_==0)
                  (yyval.array__).search[(yyvsp[(1) - (3)].array__).dimension]=(yyvsp[(3) - (3)].count).i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 53:
#line 344 "SyntaxPl0.y"
    {
                (yyval.array__).dimension=1;
                if((yyvsp[(1) - (1)].count).type_==0)
                  (yyval.array__).search[0]=(yyvsp[(1) - (1)].count).i_val;
                else
                {
                  std::cout<<MAGENTA<<"Semantic Error! Array index must be int!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 54:
#line 355 "SyntaxPl0.y"
    {
                int pos=find_sign((yyvsp[(1) - (3)].Identi).id);
                pos+=(yyvsp[(1) - (3)].Identi).offset;
                if(symtable[pos].symtype_!=Symbol::var_)
                { // type error
                  std::cout<<MAGENTA<<"Semaantic Error! "<<(yyvsp[(1) - (3)].Identi).id<<" type error!"<<std::endl;
                  exit(1);
                }
                
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::define((yyvsp[(3) - (3)].count).type_);
                if((yyvsp[(3) - (3)].count).type_==0)
                {
                  p.i_val=(yyvsp[(3) - (3)].count).i_val;
                  symtable[pos].var.i_val=(yyvsp[(3) - (3)].count).i_val;
                }
                if((yyvsp[(3) - (3)].count).type_==1)
                {
                  p.f_val=(yyvsp[(3) - (3)].count).f_val;
                  symtable[pos].var.f_val=(yyvsp[(3) - (3)].count).f_val;
                } 
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;}
    break;

  case 55:
#line 379 "SyntaxPl0.y"
    {
                if((yyvsp[(1) - (3)].Identi).type_!=2)
                {
                  std::cout<<MAGENTA<<"Semantic Error! "<<(yyvsp[(1) - (3)].Identi).id<<" is not char type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign((yyvsp[(1) - (3)].Identi).id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::char_;
                char* temp=strdup((yyvsp[(3) - (3)].str));
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup((yyvsp[(3) - (3)].str));
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;}
    break;

  case 56:
#line 397 "SyntaxPl0.y"
    {
                if((yyvsp[(1) - (3)].Identi).type_!=3)
                {
                  std::cout<<MAGENTA<<"Setanmic Error! "<<(yyvsp[(1) - (3)].Identi).id<<" is not string type!"<<std::endl;
                  exit(1);
                }

                int pos=find_sign((yyvsp[(1) - (3)].Identi).id);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::string_;
                char* temp=strdup((yyvsp[(3) - (3)].str));
                temp[strlen(temp)-1]='\0';
                p.v_str=temp+1;
                symtable[pos].var.v_str=strdup((yyvsp[(3) - (3)].str));
                gen(instruction::LIT,0,0,p);
                gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
              ;}
    break;

  case 57:
#line 416 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==0)
                {
                  if(!strcmp((yyvsp[(2) - (3)].str),"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),">="))  gen(instruction::OPR,0,11,p);
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==1)
                {
                  if(!strcmp((yyvsp[(2) - (3)].str),"=="))  gen(instruction::OPR,0,8,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"!="))  gen(instruction::OPR,0,9,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"<"))   gen(instruction::OPR,0,10,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),"<="))  gen(instruction::OPR,0,13,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),">"))   gen(instruction::OPR,0,12,p);
                  if(!strcmp((yyvsp[(2) - (3)].str),">="))  gen(instruction::OPR,0,11,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int or float in condition!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 58:
#line 443 "SyntaxPl0.y"
    {
                if((yyvsp[(2) - (2)].count).type_==0)
                {
                  all_type_val_value p;
                  init_for_gen_pcode(p);
                  gen(instruction::OPR,0,6,p);
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error! Only int in odd condition!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 59:
#line 457 "SyntaxPl0.y"
    {
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;}
    break;

  case 60:
#line 460 "SyntaxPl0.y"
    {
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;}
    break;

  case 61:
#line 464 "SyntaxPl0.y"
    {
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              ;}
    break;

  case 62:
#line 471 "SyntaxPl0.y"
    {
                backpatch(backPatch_table[backPatch_table_top--],code_line+1);
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,0,p);
              ;}
    break;

  case 63:
#line 479 "SyntaxPl0.y"
    {
                if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=0;
                    (yyval.count).i_val=(yyvsp[(1) - (3)].count).i_val+(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val+(yyvsp[(3) - (3)].count).f_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val+(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).i_val+(yyvsp[(3) - (3)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,2,p);
              ;}
    break;

  case 64:
#line 509 "SyntaxPl0.y"
    {
                if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=0;
                    (yyval.count).i_val=(yyvsp[(1) - (3)].count).i_val-(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val-(yyvsp[(3) - (3)].count).f_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val-(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).i_val-(yyvsp[(3) - (3)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,3,p);
              ;}
    break;

  case 65:
#line 539 "SyntaxPl0.y"
    {
                //$$=$2;
                if((yyvsp[(2) - (2)].count).type_==0)
                {
                  (yyval.count).type_=0;
                  (yyval.count).i_val=(yyvsp[(2) - (2)].count).i_val;
                }
                else if((yyvsp[(2) - (2)].count).type_==1)
                {
                  (yyval.count).type_=1;
                  (yyval.count).f_val=(yyvsp[(2) - (2)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 66:
#line 557 "SyntaxPl0.y"
    {
                //$$=-$2;
                if((yyvsp[(2) - (2)].count).type_==0)
                {
                    (yyval.count).type_=0;
                    (yyval.count).i_val=-(yyvsp[(2) - (2)].count).i_val;
                }
                else if((yyvsp[(2) - (2)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=-(yyvsp[(2) - (2)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,1,p);
              ;}
    break;

  case 67:
#line 578 "SyntaxPl0.y"
    {
                //$$=$1;
                if((yyvsp[(1) - (1)].count).type_==0)
                {
                  (yyval.count).type_=0;
                  (yyval.count).i_val=(yyvsp[(1) - (1)].count).i_val;
                }
                else if((yyvsp[(1) - (1)].count).type_==1)
                {
                  (yyval.count).type_=1;
                  (yyval.count).f_val=(yyvsp[(1) - (1)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 68:
#line 597 "SyntaxPl0.y"
    {
                //$$=$1*$3;
                if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=0;
                    (yyval.count).i_val=(yyvsp[(1) - (3)].count).i_val*(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val*(yyvsp[(3) - (3)].count).f_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val*(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    (yyval.count).f_val=(yyvsp[(1) - (3)].count).i_val*(yyvsp[(3) - (3)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,4,p);
              ;}
    break;

  case 69:
#line 628 "SyntaxPl0.y"
    {
                //$$=$1/$3;
                if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=0;
                    if((yyvsp[(3) - (3)].count).i_val==0)
                      (yyval.count).i_val=0;
                    else
                      (yyval.count).i_val=(yyvsp[(1) - (3)].count).i_val/(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    if((yyvsp[(3) - (3)].count).f_val==0)
                      (yyval.count).f_val=0;
                    else
                      (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val/(yyvsp[(3) - (3)].count).f_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==1 && (yyvsp[(3) - (3)].count).type_==0)
                {
                    (yyval.count).type_=1;
                    if((yyvsp[(3) - (3)].count).i_val==0)
                      (yyval.count).f_val=0;
                    else
                      (yyval.count).f_val=(yyvsp[(1) - (3)].count).f_val/(yyvsp[(3) - (3)].count).i_val;
                }
                else if((yyvsp[(1) - (3)].count).type_==0 && (yyvsp[(3) - (3)].count).type_==1)
                {
                    (yyval.count).type_=1;
                    if((yyvsp[(3) - (3)].count).f_val==0)
                      (yyval.count).f_val=0;
                    else
                      (yyval.count).f_val=(yyvsp[(1) - (3)].count).i_val/(yyvsp[(3) - (3)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::OPR,0,5,p);
              ;}
    break;

  case 70:
#line 671 "SyntaxPl0.y"
    {
                //$$=$1;
                if((yyvsp[(1) - (1)].count).type_==0)
                {
                  (yyval.count).type_=0;
                  (yyval.count).i_val=(yyvsp[(1) - (1)].count).i_val;
                }
                else if((yyvsp[(1) - (1)].count).type_==1)
                {
                  (yyval.count).type_=1;
                  (yyval.count).f_val=(yyvsp[(1) - (1)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 71:
#line 690 "SyntaxPl0.y"
    {
                int pos=find_sign((yyvsp[(1) - (1)].Identi).id);
                pos+=(yyvsp[(1) - (1)].Identi).offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if((yyvsp[(1) - (1)].Identi).type_==0 ||(yyvsp[(1) - (1)].Identi).type_==4)
                {
                  (yyval.count).type_=0;
                  (yyval.count).i_val=symtable[pos].var.i_val;
                  p.type_=all_type_val_value::int_;
                  p.i_val=(yyval.count).i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if((yyvsp[(1) - (1)].Identi).type_==1||(yyvsp[(1) - (1)].Identi).type_==5)
                {
                  (yyval.count).type_=1;
                  (yyval.count).f_val=symtable[pos].var.f_val;
                  p.type_=all_type_val_value::float_;
                  p.f_val=(yyval.count).f_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }   
              ;}
    break;

  case 72:
#line 718 "SyntaxPl0.y"
    {
                //$$=$1;
                (yyval.count).type_=0;
                (yyval.count).i_val=(yyvsp[(1) - (1)].i_val);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::int_;
                p.i_val=(yyvsp[(1) - (1)].i_val);
                gen(instruction::LIT,0,(yyvsp[(1) - (1)].i_val),p);
              ;}
    break;

  case 73:
#line 728 "SyntaxPl0.y"
    {
                //$$=$1;
                (yyval.count).type_=1;
                (yyval.count).f_val=(yyvsp[(1) - (1)].f_val);
                all_type_val_value p;
                init_for_gen_pcode(p);
                p.type_=all_type_val_value::float_;
                p.f_val=(yyvsp[(1) - (1)].f_val);
                gen(instruction::LIT,0,(yyvsp[(1) - (1)].f_val),p);
              ;}
    break;

  case 74:
#line 738 "SyntaxPl0.y"
    {
                //$$=$2;
                if((yyvsp[(2) - (3)].count).type_==0)
                {
                  (yyval.count).type_=0;
                  (yyval.count).i_val=(yyvsp[(2) - (3)].count).i_val;
                }
                else if((yyvsp[(2) - (3)].count).type_==1)
                {
                  (yyval.count).type_=1;
                  (yyval.count).f_val=(yyvsp[(2) - (3)].count).f_val;
                }
                else
                {
                  std::cout<<MAGENTA<<"Type Error!"<<std::endl;
                  exit(1);
                }
              ;}
    break;

  case 75:
#line 757 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;}
    break;

  case 76:
#line 764 "SyntaxPl0.y"
    {
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JMP,0,whilepos[whiletop--],p);
                backpatch(backPatch_table[backPatch_table_top--],code_line);
              ;}
    break;

  case 77:
#line 771 "SyntaxPl0.y"
    { 
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,whilepos[whiletop--],p);
              ;}
    break;

  case 78:
#line 777 "SyntaxPl0.y"
    {
                whilepos[++whiletop]=code_line;
              ;}
    break;

  case 79:
#line 781 "SyntaxPl0.y"
    {
                backPatch_table[++backPatch_table_top]=code_line;
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::JPC,0,0,p);
              ;}
    break;

  case 80:
#line 789 "SyntaxPl0.y"
    {
                whilepos[++whiletop]=code_line;
              ;}
    break;

  case 81:
#line 794 "SyntaxPl0.y"
    {
                if(find_pro((yyvsp[(3) - (4)].str))==-1)
                {
                  std::cout<<MAGENTA<<"Semantic error! "<<(yyvsp[(3) - (4)].str)<<" not found!"<<std::endl;
                  exit(1);
                }

                int pos=find_pro((yyvsp[(3) - (4)].str));
                all_type_val_value p;
                init_for_gen_pcode(p);
                gen(instruction::CAL,current_Level-pro_stack[pos].level,pro_stack[pos].pos-1,p);
              ;}
    break;

  case 82:
#line 807 "SyntaxPl0.y"
    {
                int pos=find_sign((yyvsp[(3) - (4)].Identi).id);
                pos+=(yyvsp[(3) - (4)].Identi).offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if(symtable[pos].var.type_==0||symtable[pos].var.type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==1||symtable[pos].var.type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if(symtable[pos].var.type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  gen(instruction::OPR,0,16,p);
                  gen(instruction::STO,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                
              ;}
    break;

  case 83:
#line 839 "SyntaxPl0.y"
    {
                int pos=find_sign((yyvsp[(3) - (4)].Identi).id);
                pos+=(yyvsp[(3) - (4)].Identi).offset;
                all_type_val_value p;
                init_for_gen_pcode(p);
                if((yyvsp[(3) - (4)].Identi).type_==0 ||(yyvsp[(3) - (4)].Identi).type_==4)
                {
                  p.type_=all_type_val_value::int_;
                  p.i_val=symtable[pos].var.i_val;
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.i_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if((yyvsp[(3) - (4)].Identi).type_==1||(yyvsp[(3) - (4)].Identi).type_==5)
                {
                  p.type_=all_type_val_value::float_;
                  p.f_val=symtable[pos].var.f_val;
                  
                  if(symtable[pos].symtype_==Symbol::const_)
                    gen(instruction::LIT,0,symtable[pos].var.f_val,p);
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if((yyvsp[(3) - (4)].Identi).type_==2)
                {
                  p.type_=all_type_val_value::char_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                if((yyvsp[(3) - (4)].Identi).type_==3)
                {
                  p.type_=all_type_val_value::string_;
                  if(symtable[pos].symtype_==Symbol::var_)
                    gen(instruction::LOD,current_Level-symtable[pos].level,symtable[pos].addr,p);
                }
                gen(instruction::OPR,0,14,p);
                gen(instruction::OPR,0,15,p);
              ;}
    break;

  case 84:
#line 878 "SyntaxPl0.y"
    {
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::char_;
              char* temp=strdup((yyvsp[(3) - (4)].str));
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
            ;}
    break;

  case 85:
#line 890 "SyntaxPl0.y"
    {
              all_type_val_value p;
              init_for_gen_pcode(p);
              p.type_=all_type_val_value::string_;
              char* temp=strdup((yyvsp[(3) - (4)].str));
              temp[strlen(temp)-1]='\0';
              p.v_str=temp+1;
              gen(instruction::LIT,0,0,p);
              init_for_gen_pcode(p);
              gen(instruction::OPR,0,14,p);
              gen(instruction::OPR,0,15,p);
            ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2731 "SyntaxPl0.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 904 "SyntaxPl0.y"


void yyerror(char const* s)
{
    //printf("%s,(%d,%d)\n",s,row,column);
    std::cout<<MAGENTA<<s<<" ("<<row<<","<<column<<")"<<std::endl;
    return;
}
