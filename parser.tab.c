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
#line 2 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include "utarray.h"
#include "uthash.h"
#include "utlist.h"
#include "utringbuffer.h"
#include "utstack.h"
#include "utstring.h"

int yylex();
extern int yylex_destroy(void);
extern int total_errors;
extern int line;
extern int lex_error;
extern void yyerror(const char* msg);
extern FILE *yyin;



typedef struct node {
    char* node_class;  
    struct node* left;
    struct node* right;
    char* type;
    char* value;
} node;

node* parser_tree = NULL;

typedef struct scope {
    char* scope_name;   
    char* type;          
    struct scope *next;
} scope;

scope* stack = NULL;

typedef struct args_node {
    char* name;
    char* type;
    struct args_node *next;
} args_node;

typedef struct param_node {
    char* key;
    struct param_node *next;
} param_node;

typedef struct symbol_node {
    char* key;
    char* name;
    char* type;
    char symbol_type;
    param_node* param_list;
    char* scope_name;
    UT_hash_handle hh;
} symbol_node;

symbol_node *symbol_table = NULL;

void init_scope_global();
node* insert_node(char* node_class, node* left, node* right, char* type, char* value);
symbol_node* create_symbol(char* key, char *name, char* type, char symbol_type, char* scope_name);
void add_symbol(char *name, char* type, char symbol_type);
void push_stack(char* scope_name, char* type);
void pop_stack();
char* concat_string(const char *s1, const char *s2);
void print_parser_tree(node * tree, int depth);
void print_depth(int depth);
void free_parser_tree(struct node* no);
void print_symbol_table();
void free_symbol_table();


#line 142 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    SET = 260,
    STR = 261,
    ELEM = 262,
    EMPTY = 263,
    TYPE = 264,
    ID = 265,
    IF = 266,
    ELSE = 267,
    RETURN = 268,
    FOR = 269,
    FORALL = 270,
    READ = 271,
    ADD = 272,
    REMOVE = 273,
    IN = 274,
    WRITE = 275,
    WRITELN = 276,
    EXISTS = 277,
    IS_SET = 278,
    QUOTES = 279,
    CHAR = 280,
    ASSIGN = 281,
    OP = 282,
    RELOP = 283,
    LOG = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 78 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 217 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 234 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  406

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    32,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    97,   101,   104,   107,   110,   116,   123,
     123,   134,   137,   143,   147,   154,   160,   163,   169,   172,
     179,   182,   185,   188,   191,   194,   197,   200,   203,   206,
     212,   215,   221,   224,   227,   230,   233,   236,   239,   245,
     251,   257,   263,   269,   272,   275,   281,   284,   287,   293,
     299,   305,   308,   315,   319,   325,   328,   334,   340,   343,
     346,   352,   355,   358,   361,   364,   367,   370,   373,   376,
     379,   385,   391,   394,   400,   403,   409,   412,   418,   421
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "SET", "STR", "ELEM",
  "EMPTY", "TYPE", "ID", "IF", "ELSE", "RETURN", "FOR", "FORALL", "READ",
  "ADD", "REMOVE", "IN", "WRITE", "WRITELN", "EXISTS", "IS_SET", "QUOTES",
  "CHAR", "ASSIGN", "OP", "RELOP", "LOG", "';'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "program", "declaration-list",
  "variable-declaration", "function", "$@1", "params-list", "params",
  "compound-stmt", "local_declaration", "stmt-list", "stmt", "expr",
  "simple-expr", "add-stmt", "remove-stmt", "exists-stmt", "in-stmt",
  "write-stmt", "writeln-stmt", "is-set-stmt", "read-stmt",
  "conditional-stmt", "iteration-stmt", "return-stmt", "var", "op-expr",
  "term", "call", "args", "arg-list", "char", "string", YY_NULLPTR
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
      59,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -236

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-236)))

#define YYTABLE_NINF -80

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     105,    18,    -6,    35,     8,    11,    13,    44,  -236,    14,
      54,    67,    82,    56,    47,    38,    62,    79,    96,   119,
     400,    93,   128,  1274,   226,   144,  1312,  1514,   122,   667,
     699,  2615,  2644,  2682,   829,   125,  1351,   127,   137,   139,
     143,   153,   162,   186,   190,   202,  2601,   142,  1547,  1580,
     208,  1613,  1646,  1679,  1712,  1745,   214,  1778,  1811,  1844,
    1877,   749,  2703,  2707,  2711,  1109,   104,  1154,  2601,  1910,
     216,   236,   257,   265,  2715,  2631,   219,  2631,  2631,     6,
       6,  2631,   219,   273,   244,  1943,  2660,  1056,  2689,  1056,
    1122,   222,   250,   279,   288,   295,  1976,   296,   307,   316,
     339,   350,   361,   380,   130,     4,   382,   146,    19,   387,
     394,  2719,  2009,  2723,   410,  2727,  2570,  2731,   402,  2601,
    1382,   416,  2042,  2075,   418,   422,   428,   439,   451,   466,
    2108,   475,   477,  1415,   487,  2141,  2174,  2207,  2240,  2273,
    2306,  2339,  2372,  2405,   497,  2438,  1448,  2585,   490,   501,
     512,   170,   859,   924,  1087,  1098,   347,   514,   525,   528,
     532,   543,  2601,   539,   558,   561,   581,  1114,  1138,  1166,
    1187,   313,   121,   717,   731,   786,   796,   852,   706,   585,
     614,   622,   628,   616,  2601,   293,   330,   357,   434,   867,
     899,   914,   941,   619,     1,   246,   337,   340,   358,   369,
     154,   647,   648,   658,   680,   663,  2601,   613,   696,   722,
     723,   372,   415,   426,   432,   303,   234,   838,   952,  1170,
    2556,  2735,   874,  2601,  2739,  2743,  2747,   676,    94,   245,
      26,  2689,  2689,   400,   400,  2631,  2631,  2631,  1154,  2631,
    2631,  2631,   219,   704,   715,    76,   545,    76,   635,   163,
    1154,  2631,  2631,  2631,   219,   441,   716,   112,   479,   112,
     655,    15,  1154,  2631,  2631,  2631,   219,   733,   724,  1198,
    2698,  1198,   324,   272,  1154,   725,   979,   207,  2751,  2755,
    1274,  1274,   736,   737,   738,   758,   768,   772,   776,   777,
    1209,  1219,   572,   609,  1091,  1146,  1180,  1070,  2601,  1201,
    1232,  1243,  1279,   289,   174,  1228,   779,   784,   785,   794,
     798,   965,   989,   261,   555,   692,   754,   765,   879,  2601,
     774,   805,   844,   887,   675,    39,  1042,   799,   808,   813,
     814,   815,   443,   474,   181,   499,   535,   538,   556,   195,
    2601,   567,   578,   579,   591,   488,   283,   495,   820,  2759,
    2471,  2504,   735,   853,   860,  1239,   850,   861,   865,   881,
    1154,   886,   545,   545,   601,   180,  1063,   462,   508,   633,
     642,  1154,   890,   479,   479,   685,    58,   506,   906,   910,
     915,   916,  1154,   901,  2698,  2698,   517,   290,  2763,  1481,
    2537,   913,  1317,  1321,  1338,   917,  1002,  1011,  1020,   918,
     592,   595,   596,  2552,  1078,   608
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -236,  -236,  -236,    69,   954,  -236,  -236,  -236,   -94,   199,
    -114,  -236,   877,   686,   871,   894,  1012,   -76,  -236,  -236,
     493,  -236,  -236,  -236,  -236,   -27,   753,    10,   604,  -235,
     849,   218,   411
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    26,     6,    12,    15,    16,    21,    23,
      27,    48,    49,    97,   207,   208,   209,    98,    54,    55,
     210,    57,    58,    59,    60,   211,   212,   213,   214,    93,
      94,   215,   216
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   101,   102,   285,     7,   109,   136,   261,    -2,    74,
     230,    -5,   -79,    -7,    -4,   306,    99,     2,    -3,   167,
      -5,   -78,    -7,    -4,   133,   230,   135,   327,   -64,   -64,
     -64,   -77,   -78,   -64,   -64,     8,   126,    63,   -77,   348,
     189,   167,   -78,   -78,   -78,   376,    63,   -78,   -78,   100,
     145,   129,   103,   106,    -6,   110,   169,    17,   -78,    61,
      74,   224,    74,    -6,   -78,    14,   -64,    -8,   -64,     5,
      18,   -64,   -64,     9,    11,    -9,    -8,   191,   169,   151,
     152,   153,   -79,   154,   155,   -78,   156,   -78,   -12,   189,
     -78,   -78,   167,   -10,   -11,    19,    63,   113,   225,   115,
     277,   -77,   -10,   -77,   -77,   -77,     1,   162,   -77,    61,
      91,   -14,   -14,    13,     2,   173,   174,   175,   -79,   176,
     177,   -64,   178,   -64,   -64,   391,   191,   249,    22,   169,
      20,   -64,   -64,   -64,   -64,   167,   395,   -77,    24,   -77,
     -77,   -77,   -15,   184,   -77,   -77,    63,   399,   -64,   -64,
     -64,   -15,   146,   -64,    28,   229,    68,   167,    75,   282,
     283,   284,   125,   286,   287,   288,   350,   351,    76,   -78,
      77,   229,   169,   -57,    78,   307,   308,   309,   128,   167,
     365,   -57,   -57,   -57,    79,   262,   -78,   328,   329,   330,
     -78,   -78,   -78,    80,   169,   -78,   167,   -66,   -66,   -66,
     -66,   -64,   -66,   -64,   224,   224,   -64,   -78,   -66,   -78,
     -66,   189,   -78,   -78,   -57,   289,   169,    81,   167,   299,
     167,    82,   -57,   189,   -57,    44,   382,   310,   -78,    99,
     189,   320,   189,   169,   -78,   189,   -78,   -78,    85,   331,
     273,   278,   279,   341,   -34,    65,    96,   189,   191,   -78,
     -78,   -78,   -78,   -64,    65,   291,   301,   305,   -13,   -13,
     191,   -64,   -64,   -64,   171,   -66,   -36,   312,   322,   326,
     -76,   167,   191,   -66,   -66,   -66,   111,   -76,   -78,   333,
     343,   347,   -75,   116,   191,   193,   171,   -37,   -66,   387,
     -66,   -78,   167,   -66,   -66,   -38,   -78,   104,   107,   -78,
     -78,   -78,   -64,   -35,    65,    65,   227,    65,   169,   -78,
     -64,   117,   -64,   167,   364,   119,   -65,   -78,   -65,   -78,
     -72,   -65,   -65,    61,    61,   -36,   -36,   118,   272,   169,
     -65,   -65,   -65,   189,   193,   299,   299,   171,   248,   120,
     -65,   -65,   -65,   -76,   189,   -65,   320,   320,   -57,   -76,
     169,   -76,   -76,   -76,    65,   189,   -67,   341,   341,   -69,
      63,    63,   -37,   -37,   -67,   -67,   -67,   -69,   -69,   -69,
     191,   121,   393,   394,   -57,   -57,   -57,   -68,   238,   -57,
     171,   191,   122,   397,   398,   -68,   -68,   -68,   -70,   -38,
     -38,   -62,   191,   123,   401,   402,   -70,   -70,   -70,   -62,
     -62,   -62,   171,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   124,   -17,   127,   -17,   -17,   -17,   -17,   130,
     -17,   -17,   -17,   -17,   171,   -17,   131,   -17,   -17,   -17,
     -17,   -17,   280,   281,   -33,   -17,   233,   231,    66,   232,
     -32,   171,   269,   270,   271,   -60,   137,    66,   138,   227,
     227,   -63,   139,   -60,   -60,   -60,   193,   172,   140,   -63,
     -63,   -63,   -61,   171,   303,   171,   -34,   -34,   193,   141,
     -61,   -61,   -61,   -35,   -35,   193,   324,   193,   194,   172,
     193,   142,   313,   314,   315,   -79,   316,   317,   345,   318,
     105,   108,   193,   -58,   -39,   -39,   143,    66,    66,   228,
      66,   -58,   -58,   -58,   -77,   -49,   -77,   -65,   -77,   -74,
     319,   -77,   -77,   386,   -59,   -65,   171,   -65,   -67,   -42,
      56,   235,   -59,   -59,   -59,   -71,   -67,   194,   -67,    56,
     172,   234,   236,   -71,   -71,   -71,   -76,   171,    83,   166,
     -40,   -40,   -76,   237,   -76,   239,   -76,    66,   292,   293,
     294,   -79,   295,   296,   -69,   297,   240,   -68,   171,   241,
     188,   166,   -69,   242,   -69,   -68,   160,   -68,    65,    65,
     -77,   -36,   -77,   172,   -77,   -70,   298,   -77,   193,    56,
     303,   303,   -67,   -70,   -67,   -70,   -62,   -67,   -67,   193,
     -37,   324,   324,   -38,   -62,   172,   -62,   -32,   -60,   -66,
     193,   -66,   345,   345,   -66,   384,   -60,   385,   -60,   188,
     -63,   -61,   166,   -34,   -58,   -59,   251,   172,   -63,   -61,
     -63,   -61,   -58,   -59,   -58,   -59,   -76,   -71,   -76,    56,
     -76,    64,   -36,   -76,   172,   -71,   -67,   -71,   -67,   182,
      64,   -67,   228,   228,   260,   252,   -65,   -65,   -65,   194,
     170,   -65,   -65,   253,   243,   166,   172,   304,   172,   254,
     -76,   194,   -76,   -76,   -76,   -41,   -41,   -76,   194,   325,
     194,   192,   170,   194,   -49,   -49,   255,   166,   263,   264,
     -76,   346,   -76,   -76,   -76,   194,   204,   -76,   -76,   265,
      64,    64,   226,    64,   -66,   -66,   -66,   -66,   267,   166,
     375,   276,   -65,   -65,   -65,   -65,   -65,   -65,   -65,   172,
     -76,   266,   -76,    50,   -76,   -37,   166,   -76,   -76,   -69,
     192,   -69,    70,   170,   -69,   -69,   -67,   -67,   -67,   -67,
     172,   188,    84,   -57,   -57,   -57,   -35,   250,   -57,   -57,
      64,   -38,   -34,   188,   -66,   -66,   -66,   290,   311,   -66,
     -66,   172,   -35,    92,    95,   188,   332,   349,   -67,   -67,
     -67,    66,    66,   -67,   -67,   -39,   170,   188,   352,   353,
     354,   194,    50,   304,   304,    86,   -62,   -62,   -62,   -62,
      62,   -68,   194,   -68,   325,   325,   -68,   -68,   170,    62,
     355,   166,   -70,   194,   -70,   346,   346,   -70,   -70,   168,
     356,   -62,    92,   -62,   357,   134,   -62,   -62,   358,   359,
     170,   366,   166,   -69,   -69,   -69,   367,   368,   -69,   -69,
     190,   168,    50,   -68,   -68,   -68,   369,   170,   -68,   -68,
     370,   377,   373,   166,   374,   226,   226,   -32,   -32,    62,
     378,   114,   192,    56,    56,   379,   380,   381,   244,   170,
     302,   170,   388,   188,   192,   -57,   -57,   -57,   -57,   -57,
      67,   192,   323,   192,   188,   -66,   192,   -66,   -66,   190,
     256,   -60,   168,   -60,   344,   188,   -60,   -60,   192,   -70,
     -70,   -70,   -39,   -40,   -70,   -70,   -67,   -67,   -67,    62,
     -41,   -67,   268,   -40,   -62,   -62,   -62,   -41,    51,   -62,
     -62,   -57,   170,   -57,   -57,   274,   -57,    71,   -57,   275,
     371,   -57,   -57,   -49,   -63,   168,   -63,   163,   392,   -63,
     -63,    52,   396,   170,    92,   -39,   257,   258,   259,   -40,
      72,   -33,   -33,   400,   -41,   -49,    92,   168,   185,   163,
     164,   -60,   -60,   -60,   170,   403,   -60,   -60,    92,   404,
     405,   -69,   -69,   -69,    64,    64,   -69,    71,    10,   168,
      92,   186,   164,   112,   192,   132,   302,   302,   -63,   -63,
     -63,     0,     0,   -63,   -63,   192,   168,   323,   323,   -67,
      72,   -67,   -67,     0,   361,     0,   192,   185,   344,   344,
     163,   190,   -61,   -61,   -61,     0,     0,   -61,   -61,   300,
       0,     0,     0,   190,   -76,   372,   -76,    51,   -76,   -76,
     186,   321,     0,   164,     0,   190,   -58,   -58,   -58,     0,
       0,   -58,   -58,   342,     0,     0,   383,   190,     0,   -61,
      52,   -61,     0,   163,   -61,   -61,    50,    50,   -58,    53,
     -58,     0,     0,   -58,   -58,     0,    92,   -59,    73,   -59,
       0,   168,   -59,   -59,     0,   163,   164,    92,   165,    29,
      30,    31,   -79,    32,    33,     0,   147,     0,    92,   -59,
     -59,   -59,   168,     0,   -59,   -59,     0,   163,   164,   187,
     165,   -77,     0,   -77,   -77,   -77,   -77,    46,     0,     0,
     -71,   -71,   -71,   168,   163,   -71,   -71,   -57,    73,   -57,
     164,   360,   -57,    62,    62,   -71,     0,   -71,     0,   185,
     -71,   -71,     0,   190,   -68,   -68,   -68,   164,   -69,   -68,
     -69,   185,     0,   -69,   190,   -70,   -70,   -70,   187,     0,
     -70,   165,   186,   185,    90,   190,   -65,   -65,   -65,   -65,
       0,   -62,   -62,   -62,   186,   185,   -62,   -76,    53,   -76,
     -76,   -76,   -76,     0,     0,     0,   186,   173,   174,   175,
     -79,   176,   177,     0,   178,   245,   246,   247,   186,   163,
     -33,   179,   180,   -68,   165,   -68,   181,   182,   -68,   -77,
       0,   -77,   -77,   183,     0,   184,   -73,   -77,     0,     0,
     163,     0,   164,   -60,   -60,   -60,   165,   -69,   -60,   -69,
     -69,   195,   196,   197,   -79,   198,   199,   -70,   200,   -70,
       0,   163,   -70,   164,   -63,   -63,   -63,   -77,   165,   -63,
       0,    51,    51,   -77,     0,   -77,   -77,   -77,   -62,   206,
     -62,   185,     0,   -62,   164,   165,   -61,   -61,   -61,     0,
       0,   -61,   185,     0,    52,    52,   -58,   -58,   -58,     0,
     187,   -58,     0,   185,   186,   -59,   -59,   -59,     0,   362,
     -59,   363,   187,     0,   -32,   186,   -71,   -71,   -71,     0,
     -60,   -71,   -60,     0,   187,   -60,   186,   -19,   -19,   -19,
     -19,   -19,   -19,    25,   -19,   -19,   187,   -19,     0,   -19,
     -19,   -19,   -19,     0,   -19,   -19,   -19,   -19,     0,   -19,
       0,   -19,   -19,   -19,   -19,   -19,   -63,     0,   -63,   -19,
     165,   -63,     0,     0,     0,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,
     -16,   165,   -16,   -16,   -16,   -16,     0,   -16,     0,   -16,
     -16,   -16,   -16,   -16,   -61,     0,   -61,   -16,   -58,   -61,
     -58,     0,   165,   -58,    29,    30,    31,   -79,    32,    33,
       0,   147,    53,    53,     0,   -59,     0,   -59,   148,   149,
     -59,     0,   187,   150,    44,     0,   -77,     0,   -77,   -77,
      45,    69,    46,   187,     0,   -19,   -19,   -19,   -19,   -19,
     -19,     0,   -19,   -19,   187,   -19,     0,   -19,   -19,   -19,
     -19,     0,   -19,   -19,   -19,   -19,     0,   -19,     0,   -19,
     -19,   -19,   -19,   -19,     0,     0,   234,   -19,   -51,   -51,
     -51,   -51,   -51,   -51,     0,   -51,   -51,   144,   -51,     0,
     -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,     0,
     -51,     0,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,
     -51,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,    -8,     0,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,     0,    -8,     0,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,    -8,   -15,   -15,   -15,   -15,   -15,   -15,
       0,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,   -15,
       0,   -15,   -15,   -15,   -15,     0,   -15,     0,   -15,   -15,
     -15,   -15,   -15,     0,     0,     0,   -15,    29,    30,    31,
     -79,    32,    33,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,   -77,
       0,   -77,   -77,    45,   -77,    46,     0,     0,     0,    47,
     -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,     0,
     -18,     0,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,
     -18,     0,   -18,     0,   -18,   -18,   -18,   -18,   -18,     0,
       0,     0,   -18,   -20,   -20,   -20,   -20,   -20,   -20,     0,
     -20,   -20,     0,   -20,     0,   -20,   -20,   -20,   -20,     0,
     -20,   -20,   -20,   -20,     0,   -20,     0,   -20,   -20,   -20,
     -20,   -20,     0,     0,     0,   -20,   -24,   -24,   -24,   -24,
     -24,   -24,     0,   -24,   -24,     0,   -24,     0,   -24,   -24,
     -24,   -24,     0,   -24,   -24,   -24,   -24,     0,   -24,     0,
     -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,   -25,
     -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,     0,   -25,
       0,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,
       0,   -25,     0,   -25,   -25,   -25,   -25,   -25,     0,     0,
       0,   -25,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,
     -26,     0,   -26,     0,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   -26,     0,   -26,     0,   -26,   -26,   -26,   -26,
     -26,     0,     0,     0,   -26,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,   -27,     0,   -27,     0,   -27,   -27,   -27,
     -27,     0,   -27,   -27,   -27,   -27,     0,   -27,     0,   -27,
     -27,   -27,   -27,   -27,     0,     0,     0,   -27,   -28,   -28,
     -28,   -28,   -28,   -28,     0,   -28,   -28,     0,   -28,     0,
     -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,     0,
     -28,     0,   -28,   -28,   -28,   -28,   -28,     0,     0,     0,
     -28,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,
       0,   -29,     0,   -29,   -29,   -29,   -29,     0,   -29,   -29,
     -29,   -29,     0,   -29,     0,   -29,   -29,   -29,   -29,   -29,
       0,     0,     0,   -29,   -21,   -21,   -21,   -21,   -21,   -21,
       0,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,   -21,
       0,   -21,   -21,   -21,   -21,     0,   -21,     0,   -21,   -21,
     -21,   -21,   -21,     0,     0,     0,   -21,   -22,   -22,   -22,
     -22,   -22,   -22,     0,   -22,   -22,     0,   -22,     0,   -22,
     -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,     0,   -22,
       0,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,   -22,
     -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,     0,
     -23,     0,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,
     -23,     0,   -23,     0,   -23,   -23,   -23,   -23,   -23,     0,
       0,     0,   -23,   -56,   -56,   -56,   -56,   -56,   -56,     0,
     -56,   -56,     0,   -56,     0,   -56,   -56,   -56,   -56,     0,
     -56,   -56,   -56,   -56,     0,   -56,     0,   -56,   -56,   -56,
     -56,   -56,     0,     0,     0,   -56,   -31,   -31,   -31,   -31,
     -31,   -31,     0,   -31,   -31,     0,   -31,     0,   -31,   -31,
     -31,   -31,     0,   -31,   -31,   -31,   -31,     0,   -31,     0,
     -31,   -31,   -31,   -31,   -31,     0,     0,     0,   -31,   -55,
     -55,   -55,   -55,   -55,   -55,     0,   -55,   -55,     0,   -55,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,
       0,   -55,     0,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
     -30,     0,   -30,     0,   -30,   -30,   -30,   -30,     0,   -30,
     -30,   -30,   -30,     0,   -30,     0,   -30,   -30,   -30,   -30,
     -30,     0,     0,     0,   -30,   -39,   -39,   -39,   -39,   -39,
     -39,     0,   -39,   -39,     0,   -39,     0,   -39,   -39,   -39,
     -39,     0,   -39,   -39,   -39,   -39,     0,   -39,     0,   -39,
     -39,   -39,   -39,   -39,     0,     0,     0,   -39,   -40,   -40,
     -40,   -40,   -40,   -40,     0,   -40,   -40,     0,   -40,     0,
     -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,     0,
     -40,     0,   -40,   -40,   -40,   -40,   -40,     0,     0,     0,
     -40,   -41,   -41,   -41,   -41,   -41,   -41,     0,   -41,   -41,
       0,   -41,     0,   -41,   -41,   -41,   -41,     0,   -41,   -41,
     -41,   -41,     0,   -41,     0,   -41,   -41,   -41,   -41,   -41,
       0,     0,     0,   -41,   -54,   -54,   -54,   -54,   -54,   -54,
       0,   -54,   -54,     0,   -54,     0,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,   -54,     0,   -54,   -54,
     -54,   -54,   -54,     0,     0,     0,   -54,    29,    30,    31,
     -53,    32,    33,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,   -53,
       0,   -53,   -53,    45,   -53,    46,     0,     0,     0,   -53,
     -50,   -50,   -50,   -50,   -50,   -50,     0,   -50,   -50,     0,
     -50,     0,   -50,   -50,   -50,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,     0,   -50,   -50,   -50,   -50,   -50,     0,
       0,     0,   -50,   -45,   -45,   -45,   -45,   -45,   -45,     0,
     -45,   -45,     0,   -45,     0,   -45,   -45,   -45,   -45,     0,
     -45,   -45,   -45,   -45,     0,   -45,     0,   -45,   -45,   -45,
     -45,   -45,     0,     0,     0,   -45,   -44,   -44,   -44,   -44,
     -44,   -44,     0,   -44,   -44,     0,   -44,     0,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,     0,
     -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,     0,   -43,
       0,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,
       0,   -43,     0,   -43,   -43,   -43,   -43,   -43,     0,     0,
       0,   -43,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,
     -48,     0,   -48,     0,   -48,   -48,   -48,   -48,     0,   -48,
     -48,   -48,   -48,     0,   -48,     0,   -48,   -48,   -48,   -48,
     -48,     0,     0,     0,   -48,   -47,   -47,   -47,   -47,   -47,
     -47,     0,   -47,   -47,     0,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,   -47,   -47,   -47,     0,   -47,     0,   -47,
     -47,   -47,   -47,   -47,     0,     0,     0,   -47,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,     0,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,     0,
     -46,     0,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,
     -46,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,
       0,   -52,     0,   -52,   -52,   -52,   -52,     0,   -52,   -52,
     -52,   -52,     0,   -52,     0,   -52,   -52,   -52,   -52,   -52,
       0,     0,     0,   -52,    29,    30,    31,   -79,    32,    33,
       0,    34,    35,     0,    36,     0,    37,    38,    39,    40,
       0,    41,    42,    43,    44,     0,   -77,     0,   -77,   -77,
      45,   -77,    46,     0,     0,     0,   389,    29,    30,    31,
     -79,    32,    33,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,   -77,
       0,   -77,   -77,    45,   -77,    46,     0,     0,     0,   390,
     -15,   -15,   -15,   -15,   -15,   -15,     0,   -15,   -15,     0,
     -15,     0,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,
     -15,     0,   -15,     0,   -15,   -15,   -15,   -15,   -15,     0,
       0,     0,   -15,   173,   174,   175,   -79,   176,   177,   -71,
     178,   -71,     0,   -68,   -71,   -68,   -68,   179,   180,     0,
       0,     0,   181,   182,     0,   -77,     0,   -77,   -77,   183,
       0,   184,   -77,   -77,   151,   152,   153,   -79,   154,   155,
       0,   156,   -57,   -57,   -57,   -57,    67,     0,   157,   158,
       0,     0,     0,   159,   160,     0,   -77,     0,   -77,   -77,
     161,     0,   162,   -77,   195,   196,   197,   -79,   198,   199,
       0,   200,   -69,   -69,   -69,   -69,     0,     0,   201,   202,
     -77,     0,     0,   203,   204,     0,   -77,     0,   -77,   -77,
     205,     0,   206,    29,    30,    31,   -79,    32,    33,     0,
      34,   -68,   -68,   -68,   -68,     0,     0,   148,   149,     0,
       0,     0,   150,    44,     0,   -77,     0,   -77,   -77,    45,
     -77,    46,   217,   218,   219,   -79,   220,   221,     0,   222,
       0,   334,   335,   336,   -79,   337,   338,     0,   339,   -70,
     -70,   -70,   -70,     0,   -77,     0,   -77,   -77,   -77,   -77,
     223,     0,     0,   -77,     0,   -77,     0,   -77,     0,   340,
      87,    88,    89,   -33,   -60,   -60,   -60,   -60,   -63,   -63,
     -63,   -63,   -62,   -62,   -62,   -62,   -61,   -61,   -61,   -61,
     -58,   -58,   -58,   -58,   -59,   -59,   -59,   -59,   -71,   -71,
     -71,   -71,   -70,     0,   -70,   -70,   -62,     0,   -62,   -62,
     -60,     0,   -60,   -60,   -63,     0,   -63,   -63,   -58,     0,
     -58,   -58,   -59,     0,   -59,   -59,   -61,     0,   -61,   -61,
     -71,     0,   -71,   -71
};

static const yytype_int16 yycheck[] =
{
      27,    77,    78,   238,    10,    81,   120,     6,     0,    36,
       6,     0,     6,     0,     0,   250,    10,     9,     0,    46,
       9,     6,     9,     9,   118,     6,   120,   262,    27,    28,
      29,    25,     6,    32,    33,     0,    32,    27,    32,   274,
      67,    68,    27,    28,    29,     6,    36,    32,    33,    76,
     144,    32,    79,    80,     0,    82,    46,    10,    32,    86,
      87,    88,    89,     9,     6,     9,    27,     0,    29,     0,
      32,    32,    33,     4,    30,    31,     9,    67,    68,     3,
       4,     5,     6,     7,     8,    27,    10,    29,    32,   116,
      32,    33,   119,     0,    32,    33,    86,    87,    88,    89,
       6,    25,     9,    27,    28,    29,     1,    31,    32,   136,
       6,    32,    33,    31,     9,     3,     4,     5,     6,     7,
       8,    27,    10,    29,    30,   360,   116,     6,     9,   119,
      34,    27,    28,    29,    30,   162,   371,    25,    10,    27,
      28,    29,     0,    31,    32,    33,   136,   382,    27,    28,
      29,     9,    30,    32,    10,    25,    31,   184,    31,   235,
     236,   237,    32,   239,   240,   241,   280,   281,    31,     6,
      31,    25,   162,    19,    31,   251,   252,   253,    32,   206,
       6,    27,    28,    29,    31,    31,     6,   263,   264,   265,
      27,    28,    29,    31,   184,    32,   223,    27,    28,    29,
      19,    27,    32,    29,   231,   232,    32,    27,    27,    29,
      29,   238,    32,     6,    19,   242,   206,    31,   245,   246,
     247,    31,    27,   250,    29,    23,    31,   254,     6,    10,
     257,   258,   259,   223,    27,   262,    29,    30,    30,   266,
       6,   231,   232,   270,    30,    27,    30,   274,   238,    27,
      28,    29,    30,    19,    36,   245,   246,   247,    32,    33,
     250,    27,    28,    29,    46,    19,    30,   257,   258,   259,
      25,   298,   262,    27,    28,    29,    32,    32,     6,   269,
     270,   271,    32,    33,   274,    67,    68,    30,    27,     6,
      29,    19,   319,    32,    33,    30,     6,    79,    80,    27,
      28,    29,    19,    30,    86,    87,    88,    89,   298,    19,
      27,    32,    29,   340,    25,    19,    27,    27,    29,    29,
      32,    32,    19,   350,   351,    32,    33,    32,    25,   319,
      27,    28,    29,   360,   116,   362,   363,   119,    25,    32,
      27,    28,    29,    19,   371,    32,   373,   374,    32,    25,
     340,    27,    28,    29,   136,   382,    19,   384,   385,    19,
     350,   351,    32,    33,    27,    28,    29,    27,    28,    29,
     360,    32,   362,   363,    27,    28,    29,    19,    31,    32,
     162,   371,    32,   373,   374,    27,    28,    29,    19,    32,
      33,    19,   382,    32,   384,   385,    27,    28,    29,    27,
      28,    29,   184,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    32,    13,    32,    15,    16,    17,    18,    32,
      20,    21,    22,    23,   206,    25,    32,    27,    28,    29,
      30,    31,   233,   234,    19,    35,    34,    27,    27,    29,
      30,   223,    27,    28,    29,    19,    30,    36,    30,   231,
     232,    19,    30,    27,    28,    29,   238,    46,    30,    27,
      28,    29,    19,   245,   246,   247,    32,    33,   250,    30,
      27,    28,    29,    32,    33,   257,   258,   259,    67,    68,
     262,    30,     3,     4,     5,     6,     7,     8,   270,    10,
      79,    80,   274,    19,    32,    33,    30,    86,    87,    88,
      89,    27,    28,    29,    25,    30,    27,    19,    29,    32,
      31,    32,    33,    25,    19,    27,   298,    29,    19,    32,
      27,    31,    27,    28,    29,    19,    27,   116,    29,    36,
     119,    34,    31,    27,    28,    29,    19,   319,    45,    46,
      32,    33,    25,    31,    27,    31,    29,   136,     3,     4,
       5,     6,     7,     8,    19,    10,    31,    19,   340,    31,
      67,    68,    27,    31,    29,    27,    23,    29,   350,   351,
      25,    32,    27,   162,    29,    19,    31,    32,   360,    86,
     362,   363,    27,    27,    29,    29,    19,    32,    33,   371,
      32,   373,   374,    32,    27,   184,    29,    19,    19,    27,
     382,    29,   384,   385,    32,    27,    27,    29,    29,   116,
      19,    19,   119,    32,    19,    19,    31,   206,    27,    27,
      29,    29,    27,    27,    29,    29,    25,    19,    27,   136,
      29,    27,    19,    32,   223,    27,    27,    29,    29,    23,
      36,    32,   231,   232,    25,    31,    27,    28,    29,   238,
      46,    32,    33,    31,   161,   162,   245,   246,   247,    31,
      25,   250,    27,    28,    29,    32,    33,    32,   257,   258,
     259,    67,    68,   262,    32,    33,   183,   184,    31,    31,
      25,   270,    27,    28,    29,   274,    23,    32,    33,    31,
      86,    87,    88,    89,    27,    28,    29,    30,   205,   206,
      25,    25,    27,    27,    29,    29,    30,    32,    33,   298,
      25,    31,    27,    27,    29,    19,   223,    32,    33,    27,
     116,    29,    36,   119,    32,    33,    27,    28,    29,    30,
     319,   238,    46,    27,    28,    29,    32,    31,    32,    33,
     136,    19,    19,   250,    27,    28,    29,    32,    32,    32,
      33,   340,    19,    67,    68,   262,    32,    32,    27,    28,
      29,   350,   351,    32,    33,    30,   162,   274,    32,    32,
      32,   360,    86,   362,   363,    26,    27,    28,    29,    30,
      27,    27,   371,    29,   373,   374,    32,    33,   184,    36,
      32,   298,    27,   382,    29,   384,   385,    32,    33,    46,
      32,    27,   116,    29,    32,   119,    32,    33,    32,    32,
     206,    32,   319,    27,    28,    29,    32,    32,    32,    33,
      67,    68,   136,    27,    28,    29,    32,   223,    32,    33,
      32,    32,    27,   340,    29,   231,   232,    32,    33,    86,
      32,    88,   238,   350,   351,    32,    32,    32,   162,   245,
     246,   247,    32,   360,   250,    26,    27,    28,    29,    30,
      31,   257,   258,   259,   371,    27,   262,    29,    30,   116,
     184,    27,   119,    29,   270,   382,    32,    33,   274,    27,
      28,    29,    32,    30,    32,    33,    27,    28,    29,   136,
      30,    32,   206,    32,    27,    28,    29,    32,    27,    32,
      33,    27,   298,    29,    30,    31,    27,    36,    29,   223,
      31,    32,    33,    32,    27,   162,    29,    46,    32,    32,
      33,    27,    32,   319,   238,    19,    27,    28,    29,    19,
      36,    32,    33,    32,    19,    19,   250,   184,    67,    68,
      46,    27,    28,    29,   340,    32,    32,    33,   262,    32,
      32,    27,    28,    29,   350,   351,    32,    86,     4,   206,
     274,    67,    68,    86,   360,   116,   362,   363,    27,    28,
      29,    -1,    -1,    32,    33,   371,   223,   373,   374,    27,
      86,    29,    30,    -1,   298,    -1,   382,   116,   384,   385,
     119,   238,    27,    28,    29,    -1,    -1,    32,    33,   246,
      -1,    -1,    -1,   250,    25,   319,    27,   136,    29,    30,
     116,   258,    -1,   119,    -1,   262,    27,    28,    29,    -1,
      -1,    32,    33,   270,    -1,    -1,   340,   274,    -1,    27,
     136,    29,    -1,   162,    32,    33,   350,   351,    27,    27,
      29,    -1,    -1,    32,    33,    -1,   360,    27,    36,    29,
      -1,   298,    32,    33,    -1,   184,   162,   371,    46,     3,
       4,     5,     6,     7,     8,    -1,    10,    -1,   382,    27,
      28,    29,   319,    -1,    32,    33,    -1,   206,   184,    67,
      68,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      27,    28,    29,   340,   223,    32,    33,    27,    86,    29,
     206,    31,    32,   350,   351,    27,    -1,    29,    -1,   238,
      32,    33,    -1,   360,    27,    28,    29,   223,    27,    32,
      29,   250,    -1,    32,   371,    27,    28,    29,   116,    -1,
      32,   119,   238,   262,    25,   382,    27,    28,    29,    30,
      -1,    27,    28,    29,   250,   274,    32,    25,   136,    27,
      28,    29,    30,    -1,    -1,    -1,   262,     3,     4,     5,
       6,     7,     8,    -1,    10,    27,    28,    29,   274,   298,
      32,    17,    18,    27,   162,    29,    22,    23,    32,    25,
      -1,    27,    28,    29,    -1,    31,    32,    33,    -1,    -1,
     319,    -1,   298,    27,    28,    29,   184,    27,    32,    29,
      30,     3,     4,     5,     6,     7,     8,    27,    10,    29,
      -1,   340,    32,   319,    27,    28,    29,    19,   206,    32,
      -1,   350,   351,    25,    -1,    27,    28,    29,    27,    31,
      29,   360,    -1,    32,   340,   223,    27,    28,    29,    -1,
      -1,    32,   371,    -1,   350,   351,    27,    28,    29,    -1,
     238,    32,    -1,   382,   360,    27,    28,    29,    -1,    27,
      32,    29,   250,    -1,    32,   371,    27,    28,    29,    -1,
      27,    32,    29,    -1,   262,    32,   382,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   274,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    27,    -1,    29,    35,
     298,    32,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,   319,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    27,    -1,    29,    35,    27,    32,
      29,    -1,   340,    32,     3,     4,     5,     6,     7,     8,
      -1,    10,   350,   351,    -1,    27,    -1,    29,    17,    18,
      32,    -1,   360,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,   371,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,   382,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    34,    35,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    12,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    35,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    35,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    35,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    35,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    35,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    -1,    15,    16,    17,    18,    -1,
      20,    21,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,    -1,    -1,    -1,    35,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    25,    -1,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    35,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    25,    -1,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    35,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    25,    -1,    27,
      28,    29,    30,    31,    -1,    -1,    -1,    35,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      25,    -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      35,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    -1,    15,    16,    17,    18,    -1,    20,    21,
      22,    23,    -1,    25,    -1,    27,    28,    29,    30,    31,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    35,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    25,
      -1,    27,    28,    29,    30,    31,    -1,    -1,    -1,    35,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    25,    -1,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    35,     3,     4,     5,     6,     7,     8,    27,
      10,    29,    -1,    27,    32,    29,    30,    17,    18,    -1,
      -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,    29,
      -1,    31,    32,    33,     3,     4,     5,     6,     7,     8,
      -1,    10,    27,    28,    29,    30,    31,    -1,    17,    18,
      -1,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      29,    -1,    31,    32,     3,     4,     5,     6,     7,     8,
      -1,    10,    27,    28,    29,    30,    -1,    -1,    17,    18,
      19,    -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,
      29,    -1,    31,     3,     4,     5,     6,     7,     8,    -1,
      10,    27,    28,    29,    30,    -1,    -1,    17,    18,    -1,
      -1,    -1,    22,    23,    -1,    25,    -1,    27,    28,    29,
      30,    31,     3,     4,     5,     6,     7,     8,    -1,    10,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    27,
      28,    29,    30,    -1,    25,    -1,    27,    19,    29,    30,
      31,    -1,    -1,    25,    -1,    27,    -1,    29,    -1,    31,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    27,    28,    29,    30,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    -1,    29,    30,    27,    -1,    29,    30,
      27,    -1,    29,    30,    27,    -1,    29,    30,    27,    -1,
      29,    30,    27,    -1,    29,    30,    27,    -1,    29,    30,
      27,    -1,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    37,    38,    39,    40,    10,     0,    39,
      40,    30,    41,    31,     9,    42,    43,    10,    32,    33,
      34,    44,     9,    45,    10,     9,    39,    46,    10,     3,
       4,     5,     7,     8,    10,    11,    13,    15,    16,    17,
      18,    20,    21,    22,    23,    29,    31,    35,    47,    48,
      49,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    67,    68,    31,    31,    30,
      49,    50,    51,    52,    61,    31,    31,    31,    31,    31,
      31,    31,    31,    56,    49,    30,    26,    27,    28,    29,
      25,     6,    49,    65,    66,    49,    30,    49,    53,    10,
      61,    53,    53,    61,    67,    68,    61,    67,    68,    53,
      61,    32,    48,    63,    62,    63,    33,    32,    32,    19,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    66,    44,    49,    44,    46,    30,    30,    30,
      30,    30,    30,    30,    12,    44,    30,    10,    17,    18,
      22,     3,     4,     5,     7,     8,    10,    17,    18,    22,
      23,    29,    31,    50,    51,    52,    56,    61,    62,    63,
      64,    67,    68,     3,     4,     5,     7,     8,    10,    17,
      18,    22,    23,    29,    31,    50,    51,    52,    56,    61,
      62,    63,    64,    67,    68,     3,     4,     5,     7,     8,
      10,    17,    18,    22,    23,    29,    31,    50,    51,    52,
      56,    61,    62,    63,    64,    67,    68,     3,     4,     5,
       7,     8,    10,    31,    61,    63,    64,    67,    68,    25,
       6,    27,    29,    34,    34,    31,    31,    31,    31,    31,
      31,    31,    31,    56,    49,    27,    28,    29,    25,     6,
      31,    31,    31,    31,    31,    56,    49,    27,    28,    29,
      25,     6,    31,    31,    31,    31,    31,    56,    49,    27,
      28,    29,    25,     6,    31,    49,    25,     6,    63,    63,
      45,    45,    53,    53,    53,    65,    53,    53,    53,    61,
      32,    63,     3,     4,     5,     7,     8,    10,    31,    61,
      62,    63,    64,    67,    68,    63,    65,    53,    53,    53,
      61,    32,    63,     3,     4,     5,     7,     8,    10,    31,
      61,    62,    63,    64,    67,    68,    63,    65,    53,    53,
      53,    61,    32,    63,     3,     4,     5,     7,     8,    10,
      31,    61,    62,    63,    64,    67,    68,    63,    65,    32,
      46,    46,    32,    32,    32,    32,    32,    32,    32,    32,
      31,    49,    27,    29,    25,     6,    32,    32,    32,    32,
      32,    31,    49,    27,    29,    25,     6,    32,    32,    32,
      32,    32,    31,    49,    27,    29,    25,     6,    32,    35,
      35,    65,    32,    63,    63,    65,    32,    63,    63,    65,
      32,    63,    63,    32,    32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    41,
      40,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    50,
      51,    52,    53,    54,    54,    54,    55,    55,    55,    56,
      57,    58,    58,    59,    59,    60,    60,    61,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     3,     0,
       7,     1,     0,     4,     2,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     1,     1,     2,     1,     1,     1,     4,
       4,     4,     3,     5,     5,     5,     5,     5,     5,     4,
       5,     5,     7,     5,     5,     3,     2,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     0,     3,     1,     2,     0,     2,     0
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
#line 94 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
    }
#line 2021 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.y" /* yacc.c:1646  */
    {}
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2051 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), 'V');
    }
#line 2068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'F');
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2086 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 2111 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("COMPOUND_STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOCAL_DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2160 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2184 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2192 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2200 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2208 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2216 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 212 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2272 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 233 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 236 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 239 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2312 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 245 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2320 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 251 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2328 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 257 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 263 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 269 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2352 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2360 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 275 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2368 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 281 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2376 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 284 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 287 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 299 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 305 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 308 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 315 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 319 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 325 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 328 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 334 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 340 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 343 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 346 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 352 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 355 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 358 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 361 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2521 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 367 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 370 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 373 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 376 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 379 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2569 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 385 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2577 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 391 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 394 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2593 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 400 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2601 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 403 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 409 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "char", (yyvsp[0].token)); 
    }
#line 2617 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 412 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 418 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "string", (yyvsp[0].token)); 
    }
#line 2633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 421 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2641 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2645 "parser.tab.c" /* yacc.c:1646  */
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
#line 425 "parser.y" /* yacc.c:1906  */


// Inicializa o escopo global
void init_scope_global(){
    scope* s = (scope *)malloc(sizeof *s);
    s->scope_name = "global";
    stack = s;
}

// Pegar cabeça scope stack
scope* get_stack_head() {
    scope* s = stack;
    while(s->next != NULL) {
        s = s->next;
    }
    return s;
}

// Push do scope stack
void push_stack(char* scope_name, char* type){
    scope* s = (scope *)malloc(sizeof *s);
    scope* stack_head;

    s->type = type;
    s->scope_name = scope_name;

    stack_head = get_stack_head();
    stack_head->next = s;
}

// Pop do scope stack
void pop_stack(){
    scope* s = stack;
    if(
        (strcmp(s->scope_name, "global") == 0) && 
        s->next == NULL
    ) {
        return;
    }
    while(s->next->next != NULL){
        s = s->next;
    }
    free(s->next);
    s->next = NULL;
}

// adiciona símbolo na table
void add_symbol(char* name, char* type, char symbol_type) {
    symbol_node *s;
    scope* scope = get_stack_head();
    char *key = concat_string(name, scope->scope_name);
    s = create_symbol(key, name, type, symbol_type, scope->scope_name);
    HASH_ADD_STR(symbol_table, key, s);
}

// cria símbolo para table
symbol_node* create_symbol(char* key, char *name, char* type, char symbol_type, char* scope_name){
    symbol_node *s = (symbol_node *)malloc(sizeof *s);
    s->key = key;
    s->name = name;
    s->type = type;
    s->symbol_type = symbol_type;
    s->scope_name = scope_name;
    s->param_list = NULL;

    if(symbol_type == 'P'){
        symbol_node *f;
        param_node *prev_p;
        scope* scope = get_stack_head();
        char* function_name = scope->scope_name;
        char* function_key = concat_string(function_name, stack->scope_name);
        HASH_FIND_STR(symbol_table, function_key, f);
        if(f != NULL){
            param_node *p = (param_node *)malloc(sizeof *p);
            p->key = key;
            p->next = NULL;
            if(f->param_list == NULL){
                f->param_list = p;
            }
            else{
                prev_p = f->param_list;
                while(prev_p->next != NULL){
                    prev_p = prev_p->next;
                }
                prev_p->next = p;
            }
        }
    }
    return s;
}

// cria node auxiliar para adicionar na parser tree nas regras
node* insert_node(char* node_class, node* left, node* right, char* type, char* value){
    node* aux_node = (node*)calloc(1, sizeof(node));

    aux_node->node_class = node_class;
    aux_node->left = left;
    aux_node->right = right;
    aux_node->type = type;
    aux_node->value = value;

    return aux_node;
}

// printa table
void print_symbol_table() {
    symbol_node *s;
    symbol_node *ps;
    param_node *p;
    int number_of_space;
    printf("\n\n----------  TABELA DE SÍMBOLOS ----------\n\n");
    for(s=symbol_table; s != NULL; s=s->hh.next) {
        if(s->symbol_type != 'P'){
            printf("key: %s | name: %s | type: %s | symbol_type: %c | scope: %s |\n", s->key, s->name, s->type, s->symbol_type, s->scope_name);
            if(s->symbol_type == 'F'){
                for(p=s->param_list; p != NULL; p=p->next) {
                    HASH_FIND_STR(symbol_table, p->key, ps);
                    if(ps != NULL){
                        for(number_of_space = 36; number_of_space > 0; number_of_space--){
                            printf(" ");
                        }
                        printf("| param_name: %s | type: %s | symbol_type: %c | scope: %s |\n", ps->name, ps->type, ps->symbol_type, ps->scope_name);
                    }
                }
            }
        }
    }
}

// desaloca table
void free_symbol_table(){
    symbol_node *s, *tmp;
    HASH_ITER(hh, symbol_table, s, tmp) {
        HASH_DEL(symbol_table, s);
        free(s);
    }
}

// Printa níveis do escopo
void print_depth(int depth) {
    int i = depth;
    while(i != 0){
        printf(" ");
        i--;
    }
}

// Printa parser tree
void print_parser_tree(node * tree, int depth) {
    if (tree) {
        print_depth(depth);
        printf(" Class: %s, ", tree->node_class);
        if (tree->type != NULL){
            printf("type: %s && ", tree->type);
        }
        if (tree->value != NULL){
            printf("value: %s", tree->value);
        }
        printf("\n");
        print_parser_tree(tree->left, depth + 1);
        print_parser_tree(tree->right, depth + 1);
    }
}

// desaloca parser tree
void free_parser_tree(struct node* node){
    if(node == NULL) return;
    if(node->left) free_parser_tree(node->left);
    if(node->right) free_parser_tree(node->right);
    free(node);
}

char* concat_string(const char *s1, const char *s2){
    char *result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, "::");
    strcat(result, s2);
    return result;
}


int main(int argc, char **argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("\n\n----------  ANALISADOR LÉXICO ----------\n\n");
        printf("ADD não implementado e REMOVE, EXISTS E IN não finalizados\n");
    }
    else {
        yyin = stdin;
    }
    init_scope_global();
    yyparse();
    print_symbol_table();
    printf("\n\n----------  AST ----------\n\n");
    print_parser_tree(parser_tree, 0);
    free_parser_tree(parser_tree);
    free_symbol_table();
    fclose(yyin);
    yylex_destroy();
}
