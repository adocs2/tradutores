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
    PRINTF = 269,
    FOR = 270,
    FORALL = 271,
    READ = 272,
    ADD = 273,
    REMOVE = 274,
    IN = 275,
    WRITE = 276,
    WRITELN = 277,
    EXISTS = 278,
    IS_SET = 279,
    QUOTES = 280,
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
#define YYLAST   2115

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  343

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
     209,   212,   218,   221,   227,   230,   233,   236,   242,   244,
     249,   255,   258,   261,   267,   273,   279,   285,   288,   294,
     300,   303,   310,   314,   320,   323,   329,   335,   338,   341,
     347,   350,   353,   356,   359,   362,   365,   368,   371,   377,
     383,   386,   392,   395,   401,   404
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "SET", "STR", "ELEM",
  "EMPTY", "TYPE", "ID", "IF", "ELSE", "RETURN", "PRINTF", "FOR", "FORALL",
  "READ", "ADD", "REMOVE", "IN", "WRITE", "WRITELN", "EXISTS", "IS_SET",
  "QUOTES", "ASSIGN", "OP", "RELOP", "LOG", "';'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "program", "declaration-list",
  "variable-declaration", "function", "$@1", "params-list", "params",
  "compound-stmt", "local_declaration", "stmt-list", "stmt", "expr",
  "simple-expr", "add-stmt", "remove-stmt", "exists-stmt", "in-stmt",
  "write-stmt", "writeln-stmt", "is-set-stmt", "read-stmt",
  "conditional-stmt", "iteration-stmt", "return-stmt", "var", "op-expr",
  "term", "call", "args", "arg-list", "string", YY_NULLPTR
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

#define YYPACT_NINF -204

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-204)))

#define YYTABLE_NINF -76

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,    11,    56,    16,     8,    55,    68,   247,  -204,    71,
     110,   143,   -26,    -5,    78,    -2,    70,   241,   103,    81,
     513,   151,   122,   576,   264,   139,   605,   754,    90,  2033,
    2037,  2041,  2045,  2049,   335,   133,  1691,   135,   176,   179,
     783,   181,   187,   190,   207,   212,     0,   221,  1720,   154,
     812,   841,   220,   870,   899,   928,   957,   986,   231,  1015,
    1044,  1073,  1102,   439,  2053,  2057,  2061,  1682,   173,  1131,
     173,   249,  2065,     4,   271,   275,     5,   297,   301,   271,
     275,     6,   259,   310,   296,  1160,   137,  1728,   261,   420,
     261,   279,   302,   312,   315,  1189,   337,     0,   376,   380,
     347,   382,   395,   402,   406,     0,     0,   397,   416,    12,
    2069,   271,  2073,    38,  1218,  2024,  2077,   160,  2081,  1757,
    2085,   400,    13,   429,   634,   275,   447,   275,    14,    17,
     451,   466,   468,   510,   501,   667,   509,  1247,  1276,  1305,
     511,  1334,   519,   536,   537,  1363,   546,   556,   353,   557,
     566,   572,   573,   574,  1392,  1421,  1450,  1479,  1508,  1537,
    1566,   696,  2028,   142,   203,  1915,  1921,  1927,  1909,   575,
       0,   593,   173,   588,  1933,  1939,  1945,  1951,   344,   365,
     461,   478,   526,   404,   594,     0,   607,   173,   367,   533,
    1676,  1751,  1774,   612,   602,    58,    62,    86,    94,    98,
      52,     0,   173,   104,   155,   159,  1904,   195,   351,   411,
     455,  1747,   126,     0,   173,  1820,  1827,  1834,   604,   137,
     137,   420,   420,   513,   513,   460,   137,  1682,   275,    20,
     611,   614,   494,   542,   494,  1682,   275,    44,   476,   617,
    1765,  1790,  1765,   271,  1682,    45,   622,  1682,    48,   628,
     271,   217,   233,  1841,  1848,   576,   576,   243,   629,   641,
    1957,  1963,  1969,   274,   446,   635,  1710,  1760,   374,     0,
     173,  1985,  1989,  1993,  1997,  1975,   644,   650,  1781,  1791,
    1798,   304,   545,  1819,  1826,  1833,   388,     0,   173,  1840,
    1847,  1854,  1861,  1805,   655,   661,   273,   300,   662,  1855,
    1862,   663,  1595,  1624,   510,  1981,   106,  1682,    50,   665,
     542,   542,  1812,  1866,  1682,    51,   676,  1790,  1790,   636,
     303,  1876,   679,   725,  1653,   482,   684,   690,  2001,  2005,
    2009,  2013,   507,   691,  1868,  1875,  1882,  1889,   704,   706,
     525,  2017,  1896
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,  -204,   105,   730,  -204,  -204,  -204,  -114,   340,
    -121,  -204,   653,    80,  -131,  -204,   669,   -78,  -204,  -204,
     268,  -204,  -204,  -204,  -204,   -27,    72,     7,   169,  -203,
     632,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    26,     6,    12,    15,    16,    21,    23,
      27,    50,    51,    91,    53,    54,    55,    99,    56,    57,
     173,    59,    60,    61,    62,   174,   175,   176,   177,    92,
      93,    81
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   107,   148,   139,    14,    13,   -75,   135,    -2,    72,
     138,    -3,   109,   122,    96,   193,     8,     2,   -74,   109,
     109,   128,   129,   109,   258,   -75,   109,   -12,   194,    97,
      18,   110,   276,   132,    65,   156,   102,   -74,   136,   143,
     189,   295,   144,    65,   298,   260,    98,   100,   101,   104,
     109,   109,   100,   108,   109,    -5,   109,   109,   133,   203,
     115,    72,   215,    72,    -5,   219,     7,   220,    -7,   278,
     296,    -4,   -56,   299,   191,   328,   334,    -7,   -64,   -56,
      -4,   -56,   -65,   244,   100,   -64,   229,   -64,    17,   -65,
      22,   -65,   189,   204,    65,   116,   216,   118,   140,    64,
     142,   237,   -11,    19,   327,     5,   -67,    52,    64,     9,
      -6,   333,    63,   -67,   -66,   -67,    71,   245,   -68,    -6,
     161,   -66,     1,   -66,   -61,   -68,   191,   -68,    84,   248,
       2,   -61,    24,   -61,   302,   303,   326,    20,   -48,   190,
     195,   196,   197,    -8,   198,   199,    65,   200,    94,    28,
      84,   -10,    -8,   -56,   -15,   -56,   -56,   247,   113,    64,
     -10,   117,   201,   -15,    68,   294,    73,    52,   202,   -64,
     -64,   -64,   301,   325,   -64,   -59,   163,   164,   165,   -62,
     166,   167,   -59,   168,   -59,   308,   -62,   221,   -62,   222,
     -34,   190,   203,   203,   215,   215,    66,   169,   170,   203,
     189,   259,   171,   315,   172,    66,   271,    74,   189,   277,
      75,    64,    76,   189,   289,   189,   100,   189,    77,    52,
     189,    78,   -64,   100,   -64,   -64,   251,   252,   253,   254,
     -65,   -65,   -65,   204,   191,   -65,   192,   -57,    79,   262,
     273,   275,   191,    80,   -57,    45,   -57,   280,   291,   293,
      85,   191,   231,   -58,   191,   205,    66,    66,   217,    66,
     -58,   -36,   -58,   304,    29,    30,    31,   239,    32,    33,
     219,   162,   220,   -14,   -14,    63,    63,    11,    -9,    95,
     189,   193,   246,   271,   271,    96,    46,   189,   192,   -37,
     289,   289,    70,   -63,   249,    58,   -13,   -13,   257,   190,
     -63,   -64,   -63,   -64,    58,   272,   -64,   190,    66,    65,
      65,   -73,   119,   290,   191,    82,   190,   330,   331,   190,
     -60,   191,   105,   -69,   336,   337,   106,   -60,   112,   -60,
     -69,   -64,   -69,   -64,   120,   188,   -64,   -64,   -56,   -56,
     -56,   111,   -56,   -56,   -70,   -56,   -56,   121,   -56,   -56,
     309,   -56,   -56,   -56,   -56,    58,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,    67,   125,   316,   -56,
     -56,   -64,   -64,   -64,    64,    64,   -64,   -64,   -65,   190,
     -65,   -65,    52,    52,   226,   155,   190,   188,   205,   205,
     217,   217,   -65,   -65,   -65,   205,   192,   -65,   -65,   -36,
     -36,   -56,   274,   -56,   192,   307,   -56,    58,   123,   192,
     292,   192,   124,   192,   126,   -56,   192,   -56,   218,   314,
     -56,   -56,   127,   207,   208,   209,   -43,   210,   211,   130,
     212,   -56,   -56,   -56,   223,   235,   -56,   -56,   -67,   230,
     -67,   -67,   -43,   -43,   -43,   213,   -43,   -43,   131,   -43,
     -43,   214,   -43,   -43,   238,   -43,   -43,   -43,   -43,   137,
     -43,   -43,   -43,   -43,   -43,    87,   -61,   -61,   -43,   -61,
     -43,    66,    66,   -65,   -43,   -65,   192,   141,   -65,   274,
     274,   145,   -66,   192,   -66,   -66,   292,   292,   -67,   -67,
     -67,   -39,   -39,   -67,   -67,   188,   146,   163,   164,   165,
     147,   166,   167,   188,   168,   -66,   -66,   -66,   -37,   -37,
     -66,   -66,   188,   226,   340,   188,   -17,   -17,   -17,   170,
     -17,   -17,   -17,   -17,   -17,   172,   -17,   -17,   225,   -17,
     -17,   -17,   -17,   -72,   -17,   -17,   -17,   -17,   -17,   -47,
     -47,   150,   -17,   -44,   -17,   263,   264,   265,   -17,   266,
     267,   151,   268,   -68,   -68,   -68,   -38,   -38,   -68,   -68,
     -61,   -61,   -61,   255,   256,   -61,   -61,   269,   152,   153,
      58,    58,   -65,   270,   -65,   188,   -47,   -65,   -65,   -19,
     -19,   -19,   188,   -19,   -19,    25,   -19,   -19,   154,   -19,
     -19,   224,   -19,   -19,   -19,   -19,   157,   -19,   -19,   -19,
     -19,   -19,   158,   159,   160,   -19,   228,   -19,   -16,   -16,
     -16,   -19,   -16,   -16,   -16,   -16,   -16,   169,   -16,   -16,
     -36,   -16,   -16,   -16,   -16,   236,   -16,   -16,   -16,   -16,
     -16,   184,   -56,   243,   -16,   250,   -16,   -19,   -19,   -19,
     -16,   -19,   -19,   -37,   -19,   -19,   261,   -19,   -19,   279,
     -19,   -19,   -19,   -19,   297,   -19,   -19,   -19,   -19,   -19,
     300,   305,   -67,   -19,   -67,   -19,   338,   -67,   224,   -19,
     -50,   -50,   -50,   306,   -50,   -50,   312,   -50,   -50,   149,
     -50,   -50,   313,   -50,   -50,   -50,   -50,   319,   -50,   -50,
     -50,   -50,   -50,   320,   321,   322,   -50,   329,   -50,    -8,
      -8,    -8,   -50,    -8,    -8,    -8,    -8,    -8,   335,    -8,
      -8,   339,    -8,    -8,    -8,    -8,   -47,    -8,    -8,    -8,
      -8,    -8,   341,   342,   -42,    -8,   -41,    -8,   -15,   -15,
     -15,    -8,   -15,   -15,    10,   -15,   -15,   -15,   -15,   -15,
     114,   -15,   -15,   -15,   -15,   103,   -15,   -15,   -15,   -15,
     -15,   134,     0,     0,   -15,     0,   -15,    29,    30,    31,
     -15,    32,    33,     0,    34,    35,     0,    36,    37,     0,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
       0,     0,     0,    47,     0,    48,   -39,   -39,   -39,    49,
     -39,   -39,     0,   -39,   -39,     0,   -39,   -39,     0,   -39,
     -39,   -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,     0,
       0,     0,   -39,     0,   -39,   -18,   -18,   -18,   -39,   -18,
     -18,     0,   -18,   -18,     0,   -18,   -18,     0,   -18,   -18,
     -18,   -18,     0,   -18,   -18,   -18,   -18,   -18,     0,     0,
       0,   -18,     0,   -18,   -20,   -20,   -20,   -18,   -20,   -20,
       0,   -20,   -20,     0,   -20,   -20,     0,   -20,   -20,   -20,
     -20,     0,   -20,   -20,   -20,   -20,   -20,     0,     0,     0,
     -20,     0,   -20,   -24,   -24,   -24,   -20,   -24,   -24,     0,
     -24,   -24,     0,   -24,   -24,     0,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,
       0,    86,   -25,   -25,   -25,   -24,   -25,   -25,     0,   -25,
     -25,     0,   -25,   -25,     0,   -25,   -25,   -25,   -25,     0,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,     0,
     -25,   -26,   -26,   -26,   -25,   -26,   -26,     0,   -26,   -26,
       0,   -26,   -26,     0,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   -26,   -26,     0,     0,     0,   -26,     0,   -26,
     -27,   -27,   -27,   -26,   -27,   -27,     0,   -27,   -27,     0,
     -27,   -27,     0,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,   -27,   -27,     0,     0,     0,   -27,     0,   -27,   -28,
     -28,   -28,   -27,   -28,   -28,     0,   -28,   -28,     0,   -28,
     -28,     0,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,
     -28,   -28,     0,     0,     0,   -28,     0,   -28,   -29,   -29,
     -29,   -28,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,
       0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,
     -29,     0,     0,     0,   -29,     0,   -29,   -21,   -21,   -21,
     -29,   -21,   -21,     0,   -21,   -21,     0,   -21,   -21,     0,
     -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,   -21,
       0,     0,     0,   -21,     0,   -21,   -22,   -22,   -22,   -21,
     -22,   -22,     0,   -22,   -22,     0,   -22,   -22,     0,   -22,
     -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,   -22,     0,
       0,     0,   -22,     0,   -22,   -23,   -23,   -23,   -22,   -23,
     -23,     0,   -23,   -23,     0,   -23,   -23,     0,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,     0,     0,
       0,   -23,     0,   -23,   -55,   -55,   -55,   -23,   -55,   -55,
       0,   -55,   -55,     0,   -55,   -55,     0,   -55,   -55,   -55,
     -55,     0,   -55,   -55,   -55,   -55,   -55,     0,     0,     0,
     -55,     0,   -55,   -33,   -33,   -33,   -55,   -33,   -33,     0,
     -33,   -33,     0,   -33,   -33,     0,   -33,   -33,   -33,   -33,
       0,   -33,   -33,   -33,   -33,   -33,     0,     0,     0,   -33,
       0,   -33,   -54,   -54,   -54,   -33,   -54,   -54,     0,   -54,
     -54,     0,   -54,   -54,     0,   -54,   -54,   -54,   -54,     0,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,   -54,     0,
     -54,   -32,   -32,   -32,   -54,   -32,   -32,     0,   -32,   -32,
       0,   -32,   -32,     0,   -32,   -32,   -32,   -32,     0,   -32,
     -32,   -32,   -32,   -32,     0,     0,     0,   -32,     0,   -32,
     -31,   -31,   -31,   -32,   -31,   -31,     0,   -31,   -31,     0,
     -31,   -31,     0,   -31,   -31,   -31,   -31,     0,   -31,   -31,
     -31,   -31,   -31,     0,     0,     0,   -31,     0,   -31,   -53,
     -53,   -53,   -31,   -53,   -53,     0,   -53,   -53,     0,   -53,
     -53,     0,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,
     -53,   -53,     0,     0,     0,   -53,     0,   -53,    29,    30,
      31,   -53,    32,    33,     0,    34,    35,     0,    36,    37,
       0,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,     0,     0,     0,    47,     0,    48,   -49,   -49,   -49,
     -52,   -49,   -49,     0,   -49,   -49,     0,   -49,   -49,     0,
     -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,   -49,
       0,     0,     0,   -49,     0,   -49,   -42,   -42,   -42,   -49,
     -42,   -42,     0,   -42,   -42,     0,   -42,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,   -42,     0,
       0,     0,   -42,     0,   -42,   -41,   -41,   -41,   -42,   -41,
     -41,     0,   -41,   -41,     0,   -41,   -41,     0,   -41,   -41,
     -41,   -41,     0,   -41,   -41,   -41,   -41,   -41,     0,     0,
       0,   -41,     0,   -41,   -38,   -38,   -38,   -41,   -38,   -38,
       0,   -38,   -38,     0,   -38,   -38,     0,   -38,   -38,   -38,
     -38,     0,   -38,   -38,   -38,   -38,   -38,     0,     0,     0,
     -38,     0,   -38,   -51,   -51,   -51,   -38,   -51,   -51,     0,
     -51,   -51,     0,   -51,   -51,     0,   -51,   -51,   -51,   -51,
       0,   -51,   -51,   -51,   -51,   -51,     0,     0,     0,   -51,
       0,   -51,   -30,   -30,   -30,   -51,   -30,   -30,     0,   -30,
     -30,     0,   -30,   -30,     0,   -30,   -30,   -30,   -30,     0,
     -30,   -30,   -30,   -30,   -30,     0,     0,     0,   -30,     0,
     -30,   -40,   -40,   -40,   -30,   -40,   -40,     0,   -40,   -40,
       0,   -40,   -40,     0,   -40,   -40,   -40,   -40,     0,   -40,
     -40,   -40,   -40,   -40,     0,     0,     0,   -40,     0,   -40,
     -45,   -45,   -45,   -40,   -45,   -45,     0,   -45,   -45,     0,
     -45,   -45,     0,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,   -45,   -45,     0,     0,     0,   -45,     0,   -45,   -46,
     -46,   -46,   -45,   -46,   -46,     0,   -46,   -46,     0,   -46,
     -46,     0,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,     0,   -46,    29,    30,
      31,   -46,    32,    33,     0,    34,    35,     0,    36,    37,
       0,    38,    39,    40,    41,     0,    42,    43,    44,    45,
      46,     0,     0,     0,    47,     0,    48,    29,    30,    31,
     323,    32,    33,     0,    34,    35,     0,    36,    37,     0,
      38,    39,    40,    41,     0,    42,    43,    44,    45,    46,
       0,     0,     0,    47,     0,    48,   -15,   -15,   -15,   324,
     -15,   -15,     0,   -15,   -15,     0,   -15,   -15,     0,   -15,
     -15,   -15,   -15,     0,   -15,   -15,   -15,   -15,   -15,     0,
       0,     0,   -15,     0,   -15,   178,   179,   180,   -15,   181,
     182,     0,   183,     0,    29,    30,    31,     0,    32,    33,
       0,   162,     0,   240,   241,   242,   184,   185,   -35,   -35,
       0,   186,     0,   187,   -71,    45,    46,     0,     0,     0,
      47,    69,    70,   163,   164,   165,     0,   166,   167,     0,
     168,    29,    30,    31,     0,    32,    33,   -66,   206,   -66,
       0,     0,   -66,    83,   169,   170,     0,     0,     0,   171,
       0,   172,    45,    46,     0,     0,     0,    47,     0,    70,
     178,   179,   180,     0,   181,   182,     0,   183,   178,   179,
     180,     0,   181,   182,   -68,   183,   -68,   -68,   -59,   -59,
     -59,   184,   185,   -59,   -59,     0,   186,   -68,   187,   -68,
     185,     0,   -68,   281,   282,   283,   187,   284,   285,     0,
     286,   -62,   -62,   -62,     0,     0,   -62,   -62,   -63,   -63,
     -63,     0,     0,   -63,   -63,   287,     0,     0,   -60,   -60,
     -60,   288,     0,   -60,   -60,   -57,   -57,   -57,     0,     0,
     -57,   -57,   -58,   -58,   -58,     0,     0,   -58,   -58,   -69,
     -69,   -69,     0,     0,   -69,   -69,   -67,   -61,   -67,   -61,
     -61,   -67,   -67,   -66,   -59,   -66,   -59,   -59,   -66,   -66,
     -68,   -62,   -68,   -62,   -62,   -68,   -68,   -61,   -57,   -61,
     -57,   -57,   -61,   -61,   317,   -58,   318,   -58,   -58,   -34,
     -34,   -59,   -63,   -59,   -63,   -63,   -59,   -59,   -62,   -60,
     -62,   -60,   -60,   -62,   -62,   -63,   332,   -63,   -48,   -48,
     -63,   -63,   -60,   -69,   -60,   -69,   -69,   -60,   -60,   -57,
       0,   -57,     0,     0,   -57,   -57,   -58,     0,   -58,     0,
       0,   -58,   -58,   -69,     0,   -69,     0,     0,   -69,   -69,
     -56,   -56,   -56,   -56,   -56,    67,   -56,   -56,   -56,     0,
     227,   -56,   -67,   -67,   -67,     0,     0,   -67,   -66,   -66,
     -66,     0,     0,   -66,   -68,   -68,   -68,     0,     0,   -68,
     -61,   -61,   -61,     0,     0,   -61,   232,   233,   234,     0,
       0,   -35,   -59,   -59,   -59,     0,     0,   -59,   -62,   -62,
     -62,     0,     0,   -62,   -63,   -63,   -63,     0,     0,   -63,
     -60,   -60,   -60,     0,     0,   -60,   -57,   -57,   -57,     0,
       0,   -57,   -58,   -58,   -58,     0,     0,   -58,   -69,   -69,
     -69,     0,   -61,   -69,   -61,     0,   310,   -61,   311,     0,
     -59,   -34,   -59,     0,   -62,   -59,   -62,     0,   -63,   -62,
     -63,     0,   -60,   -63,   -60,     0,   -57,   -60,   -57,     0,
     -58,   -57,   -58,     0,   -69,   -58,   -69,     0,     0,   -69,
      87,   -61,   -61,   -61,   -61,   -56,   -56,   -56,   -56,    67,
     -64,   -64,   -64,   -64,   -65,   -65,   -65,   -65,   -67,   -67,
     -67,   -67,   -66,   -66,   -66,   -66,   -68,   -68,   -68,   -68,
      88,    89,    90,   -35,   -59,   -59,   -59,   -59,   -62,   -62,
     -62,   -62,   -61,   -61,   -61,   -61,   -63,   -63,   -63,   -63,
     -60,   -60,   -60,   -60,   -57,   -57,   -57,   -57,   -58,   -58,
     -58,   -58,   -69,   -69,   -69,   -69
};

static const yytype_int16 yycheck[] =
{
      27,    79,   133,   124,     9,    31,     6,   121,     0,    36,
     124,     0,     6,    97,    10,    10,     0,     9,     6,     6,
       6,   105,   106,     6,   227,    25,     6,    32,    23,    25,
      32,    25,   235,   111,    27,   149,    31,    25,    25,    25,
      67,   244,    25,    36,   247,    25,    73,    74,    75,    76,
       6,     6,    79,    80,     6,     0,     6,     6,    20,    86,
      87,    88,    89,    90,     9,    27,    10,    29,     0,    25,
      25,     0,    20,    25,    67,    25,    25,     9,    20,    27,
       9,    29,    20,    31,   111,    27,   170,    29,    10,    27,
       9,    29,   119,    86,    87,    88,    89,    90,   125,    27,
     127,   185,    32,    33,   307,     0,    20,    27,    36,     4,
       0,   314,   139,    27,    20,    29,    36,   201,    20,     9,
      30,    27,     1,    29,    20,    27,   119,    29,    48,   213,
       9,    27,    10,    29,   255,   256,    30,    34,    32,    67,
       3,     4,     5,     0,     7,     8,   139,    10,    68,    10,
      70,     0,     9,    27,     0,    29,    30,    31,    86,    87,
       9,    89,    25,     9,    31,   243,    31,    87,    31,    27,
      28,    29,   250,   304,    32,    20,     3,     4,     5,    20,
       7,     8,    27,    10,    29,   269,    27,    27,    29,    29,
      30,   119,   219,   220,   221,   222,    27,    24,    25,   226,
     227,   228,    29,   287,    31,    36,   233,    31,   235,   236,
      31,   139,    31,   240,   241,   242,   243,   244,    31,   139,
     247,    31,    27,   250,    29,    30,   219,   220,   221,   222,
      27,    28,    29,   226,   227,    32,    67,    20,    31,   232,
     233,   234,   235,    31,    27,    24,    29,   240,   241,   242,
      30,   244,   172,    20,   247,    86,    87,    88,    89,    90,
      27,    30,    29,    20,     3,     4,     5,   187,     7,     8,
      27,    10,    29,    32,    33,   302,   303,    30,    31,    30,
     307,    10,   202,   310,   311,    10,    25,   314,   119,    30,
     317,   318,    31,    20,   214,    27,    32,    33,   226,   227,
      27,    27,    29,    29,    36,   233,    32,   235,   139,   302,
     303,    32,    33,   241,   307,    47,   244,   310,   311,   247,
      20,   314,    25,    20,   317,   318,    25,    27,    32,    29,
      27,    27,    29,    29,    32,    67,    32,    33,     3,     4,
       5,    31,     7,     8,    32,    10,    11,    32,    13,    14,
     270,    16,    17,    18,    19,    87,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    20,   288,    32,
      35,    27,    28,    29,   302,   303,    32,    33,    27,   307,
      29,    30,   302,   303,    31,    32,   314,   119,   219,   220,
     221,   222,    27,    28,    29,   226,   227,    32,    33,    32,
      33,    27,   233,    29,   235,    31,    32,   139,    32,   240,
     241,   242,    32,   244,    32,    27,   247,    29,    23,    31,
      32,    33,    20,     3,     4,     5,    20,     7,     8,    32,
      10,    27,    28,    29,    34,    31,    32,    33,    27,   171,
      29,    30,     3,     4,     5,    25,     7,     8,    32,    10,
      11,    31,    13,    14,   186,    16,    17,    18,    19,    30,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,   302,   303,    27,    35,    29,   307,    30,    32,   310,
     311,    30,    27,   314,    29,    30,   317,   318,    27,    28,
      29,    31,    32,    32,    33,   227,    30,     3,     4,     5,
      32,     7,     8,   235,    10,    27,    28,    29,    32,    33,
      32,    33,   244,    31,    32,   247,     3,     4,     5,    25,
       7,     8,     9,    10,    11,    31,    13,    14,    18,    16,
      17,    18,    19,    32,    21,    22,    23,    24,    25,    32,
      33,    32,    29,    32,    31,     3,     4,     5,    35,     7,
       8,    32,    10,    27,    28,    29,    31,    32,    32,    33,
      27,    28,    29,   223,   224,    32,    33,    25,    32,    32,
     302,   303,    27,    31,    29,   307,    30,    32,    33,     3,
       4,     5,   314,     7,     8,     9,    10,    11,    32,    13,
      14,    34,    16,    17,    18,    19,    30,    21,    22,    23,
      24,    25,    30,    30,    30,    29,    31,    31,     3,     4,
       5,    35,     7,     8,     9,    10,    11,    24,    13,    14,
      32,    16,    17,    18,    19,    31,    21,    22,    23,    24,
      25,    24,    20,    31,    29,    31,    31,     3,     4,     5,
      35,     7,     8,    32,    10,    11,    32,    13,    14,    32,
      16,    17,    18,    19,    32,    21,    22,    23,    24,    25,
      32,    32,    27,    29,    29,    31,    30,    32,    34,    35,
       3,     4,     5,    32,     7,     8,    32,    10,    11,    12,
      13,    14,    32,    16,    17,    18,    19,    32,    21,    22,
      23,    24,    25,    32,    32,    32,    29,    32,    31,     3,
       4,     5,    35,     7,     8,     9,    10,    11,    32,    13,
      14,    32,    16,    17,    18,    19,    32,    21,    22,    23,
      24,    25,    32,    32,    20,    29,    20,    31,     3,     4,
       5,    35,     7,     8,     4,    10,    11,    12,    13,    14,
      87,    16,    17,    18,    19,    76,    21,    22,    23,    24,
      25,   119,    -1,    -1,    29,    -1,    31,     3,     4,     5,
      35,     7,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,    35,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    35,     7,
       8,    -1,    10,    11,    -1,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    31,     3,     4,     5,    35,     7,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    31,     3,     4,     5,    35,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    31,     3,     4,     5,    35,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      31,     3,     4,     5,    35,     7,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,
       3,     4,     5,    35,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,
       4,     5,    35,     7,     8,    -1,    10,    11,    -1,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,
       5,    35,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,
      35,     7,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,    35,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    35,     7,
       8,    -1,    10,    11,    -1,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    31,     3,     4,     5,    35,     7,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    31,     3,     4,     5,    35,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    31,     3,     4,     5,    35,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      31,     3,     4,     5,    35,     7,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,
       3,     4,     5,    35,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,
       4,     5,    35,     7,     8,    -1,    10,    11,    -1,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,
       5,    35,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,
      35,     7,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,    35,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    35,     7,
       8,    -1,    10,    11,    -1,    13,    14,    -1,    16,    17,
      18,    19,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    31,     3,     4,     5,    35,     7,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    16,    17,    18,
      19,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    31,     3,     4,     5,    35,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    31,     3,     4,     5,    35,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,    16,    17,    18,    19,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      31,     3,     4,     5,    35,     7,     8,    -1,    10,    11,
      -1,    13,    14,    -1,    16,    17,    18,    19,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,
       3,     4,     5,    35,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,
       4,     5,    35,     7,     8,    -1,    10,    11,    -1,    13,
      14,    -1,    16,    17,    18,    19,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,
       5,    35,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,
      35,     7,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    31,     3,     4,     5,    35,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    16,
      17,    18,    19,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    31,     3,     4,     5,    35,     7,
       8,    -1,    10,    -1,     3,     4,     5,    -1,     7,     8,
      -1,    10,    -1,    27,    28,    29,    24,    25,    32,    33,
      -1,    29,    -1,    31,    32,    24,    25,    -1,    -1,    -1,
      29,    30,    31,     3,     4,     5,    -1,     7,     8,    -1,
      10,     3,     4,     5,    -1,     7,     8,    27,    10,    29,
      -1,    -1,    32,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    31,    24,    25,    -1,    -1,    -1,    29,    -1,    31,
       3,     4,     5,    -1,     7,     8,    -1,    10,     3,     4,
       5,    -1,     7,     8,    27,    10,    29,    30,    27,    28,
      29,    24,    25,    32,    33,    -1,    29,    27,    31,    29,
      25,    -1,    32,     3,     4,     5,    31,     7,     8,    -1,
      10,    27,    28,    29,    -1,    -1,    32,    33,    27,    28,
      29,    -1,    -1,    32,    33,    25,    -1,    -1,    27,    28,
      29,    31,    -1,    32,    33,    27,    28,    29,    -1,    -1,
      32,    33,    27,    28,    29,    -1,    -1,    32,    33,    27,
      28,    29,    -1,    -1,    32,    33,    27,    27,    29,    29,
      30,    32,    33,    27,    27,    29,    29,    30,    32,    33,
      27,    27,    29,    29,    30,    32,    33,    27,    27,    29,
      29,    30,    32,    33,    27,    27,    29,    29,    30,    32,
      33,    27,    27,    29,    29,    30,    32,    33,    27,    27,
      29,    29,    30,    32,    33,    27,    30,    29,    32,    33,
      32,    33,    27,    27,    29,    29,    30,    32,    33,    27,
      -1,    29,    -1,    -1,    32,    33,    27,    -1,    29,    -1,
      -1,    32,    33,    27,    -1,    29,    -1,    -1,    32,    33,
      26,    27,    28,    29,    30,    31,    27,    28,    29,    -1,
      31,    32,    27,    28,    29,    -1,    -1,    32,    27,    28,
      29,    -1,    -1,    32,    27,    28,    29,    -1,    -1,    32,
      27,    28,    29,    -1,    -1,    32,    27,    28,    29,    -1,
      -1,    32,    27,    28,    29,    -1,    -1,    32,    27,    28,
      29,    -1,    -1,    32,    27,    28,    29,    -1,    -1,    32,
      27,    28,    29,    -1,    -1,    32,    27,    28,    29,    -1,
      -1,    32,    27,    28,    29,    -1,    -1,    32,    27,    28,
      29,    -1,    27,    32,    29,    -1,    27,    32,    29,    -1,
      27,    32,    29,    -1,    27,    32,    29,    -1,    27,    32,
      29,    -1,    27,    32,    29,    -1,    27,    32,    29,    -1,
      27,    32,    29,    -1,    27,    32,    29,    -1,    -1,    32,
      26,    27,    28,    29,    30,    27,    28,    29,    30,    31,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    27,    28,    29,    30,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    27,    28,    29,    30,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    37,    38,    39,    40,    10,     0,    39,
      40,    30,    41,    31,     9,    42,    43,    10,    32,    33,
      34,    44,     9,    45,    10,     9,    39,    46,    10,     3,
       4,     5,     7,     8,    10,    11,    13,    14,    16,    17,
      18,    19,    21,    22,    23,    24,    25,    29,    31,    35,
      47,    48,    49,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    31,    31,    30,
      31,    49,    61,    31,    31,    31,    31,    31,    31,    31,
      31,    67,    56,    23,    49,    30,    31,    26,    27,    28,
      29,    49,    65,    66,    49,    30,    10,    25,    61,    53,
      61,    61,    31,    52,    61,    25,    25,    53,    61,     6,
      25,    31,    32,    62,    48,    61,    63,    62,    63,    33,
      32,    32,    67,    32,    32,    20,    32,    20,    67,    67,
      32,    32,    53,    20,    66,    44,    25,    30,    44,    46,
      61,    30,    61,    25,    25,    30,    30,    32,    50,    12,
      32,    32,    32,    32,    32,    32,    44,    30,    30,    30,
      30,    30,    10,     3,     4,     5,     7,     8,    10,    24,
      25,    29,    31,    56,    61,    62,    63,    64,     3,     4,
       5,     7,     8,    10,    24,    25,    29,    31,    56,    61,
      62,    63,    64,    10,    23,     3,     4,     5,     7,     8,
      10,    25,    31,    61,    63,    64,    10,     3,     4,     5,
       7,     8,    10,    25,    31,    61,    63,    64,    23,    27,
      29,    27,    29,    34,    34,    18,    31,    31,    31,    67,
      56,    49,    27,    28,    29,    31,    31,    67,    56,    49,
      27,    28,    29,    31,    31,    67,    49,    31,    67,    49,
      31,    63,    63,    63,    63,    45,    45,    62,    65,    61,
      25,    32,    63,     3,     4,     5,     7,     8,    10,    25,
      31,    61,    62,    63,    64,    63,    65,    61,    25,    32,
      63,     3,     4,     5,     7,     8,    10,    25,    31,    61,
      62,    63,    64,    63,    53,    65,    25,    32,    65,    25,
      32,    53,    46,    46,    20,    32,    32,    31,    67,    49,
      27,    29,    32,    32,    31,    67,    49,    27,    29,    32,
      32,    32,    32,    35,    35,    50,    30,    65,    25,    32,
      63,    63,    30,    65,    25,    32,    63,    63,    30,    32,
      32,    32,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    41,
      40,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    52,    52,    52,    53,    54,    55,    56,    56,    57,
      58,    58,    59,    59,    60,    60,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      65,    65,    66,    66,    67,    67
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     3,     0,
       7,     1,     0,     4,     2,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       7,     5,     3,     2,     3,     1,     1,     2,     6,     1,
       7,     6,     5,     1,     3,     7,     7,     5,     4,     5,
       5,     7,     5,     5,     3,     2,     1,     3,     3,     1,
       3,     1,     1,     3,     1,     1,     1,     1,     1,     4,
       1,     0,     3,     1,     2,     0
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
#line 1867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.y" /* yacc.c:1646  */
    {}
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), 'V');
    }
#line 1914 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'F');
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 1923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1940 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 1957 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("COMPOUND_STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOCAL_DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2086 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PRINTF_STATEMENT", (yyvsp[-3].node), NULL, "void", (yyvsp[-6].token));
    }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PRINTF_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 218 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 221 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2126 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2134 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 233 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2142 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 236 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2150 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 242 "parser.y" /* yacc.c:1646  */
    {
    }
#line 2157 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "parser.y" /* yacc.c:1646  */
    {
    }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("REMOVE_STATEMENT", (yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[-6].token));
    }
#line 2172 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 258 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 261 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 267 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 273 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-3].node), NULL, NULL, (yyvsp[-6].token));
    }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-3].node), NULL, NULL, (yyvsp[-6].token));
    }
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 285 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2244 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2252 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 310 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 314 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 323 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 329 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 338 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2317 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 341 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 347 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 350 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 353 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 356 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2357 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 359 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2365 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 362 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2373 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 365 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 368 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 371 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 377 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2405 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 383 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 386 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 392 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 395 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 401 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "string", (yyvsp[0].token)); 
    }
#line 2445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2453 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2457 "parser.tab.c" /* yacc.c:1646  */
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
#line 408 "parser.y" /* yacc.c:1906  */


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
