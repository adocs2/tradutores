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
    ASSIGN = 280,
    OP = 281,
    RELOP = 282,
    LOG = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 78 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 216 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   2056

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  339

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      30,    31,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    94,    94,    97,   101,   104,   107,   110,   116,   123,
     123,   134,   137,   143,   147,   154,   160,   163,   169,   172,
     179,   182,   185,   188,   191,   194,   197,   200,   203,   206,
     212,   215,   221,   224,   227,   230,   236,   238,   243,   249,
     252,   255,   261,   267,   270,   276,   279,   285,   288,   294,
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
  "EMPTY", "TYPE", "ID", "IF", "ELSE", "RETURN", "FOR", "FORALL", "READ",
  "ADD", "REMOVE", "IN", "WRITE", "WRITELN", "EXISTS", "IS_SET", "QUOTES",
  "ASSIGN", "OP", "RELOP", "LOG", "';'", "'('", "')'", "','", "'{'", "'}'",
  "$accept", "program", "declaration-list", "variable-declaration",
  "function", "$@1", "params-list", "params", "compound-stmt",
  "local_declaration", "stmt-list", "stmt", "expr", "simple-expr",
  "add-stmt", "remove-stmt", "exists-stmt", "in-stmt", "write-stmt",
  "writeln-stmt", "is-set-stmt", "read-stmt", "conditional-stmt",
  "iteration-stmt", "return-stmt", "var", "op-expr", "term", "call",
  "args", "arg-list", "string", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -218

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-218)))

#define YYTABLE_NINF -76

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      32,     8,    18,    71,    21,   170,   185,    90,  -218,   198,
     242,   269,    35,    -2,    66,    48,   149,   186,    51,    78,
     138,   295,    97,   480,   212,   104,   605,   749,   100,  1975,
    1979,  1983,  1987,  1991,   518,   101,  1645,   133,   152,   777,
     157,   163,   176,   190,   244,     7,   177,   344,   305,   805,
     833,   252,   861,   889,   917,   945,   973,   256,  1001,  1029,
    1057,  1085,   577,  1995,  1999,  2003,    12,   414,  1113,   414,
     262,  2007,   296,   311,     2,    53,    54,   296,   311,    31,
     288,   309,   310,  1141,    65,   423,   108,   120,   108,   257,
     319,   322,   324,  1169,   362,   360,   370,   366,   373,   382,
     388,     7,   378,     7,   389,   392,   394,    50,  2011,   296,
    2015,    -1,  1197,  1966,  2019,   483,  2023,  1653,  2027,   380,
     633,   311,   400,   311,    56,   421,    61,   428,   430,   438,
     451,   469,   461,   665,  1225,  1253,   463,  1281,   489,   493,
    1309,   496,  1337,  1365,   501,   528,   298,   499,   544,   547,
     549,  1393,  1421,  1449,  1477,  1505,  1533,   693,  1970,   210,
    1835,  1841,  1847,  1853,   523,   559,     7,   568,   414,   565,
    1859,  1865,  1871,  1877,   372,   434,   540,  1639,  1666,   446,
     587,     7,   596,   414,   331,  1675,  1682,  1689,  1696,   593,
     602,    72,   107,   148,   158,   196,   195,     7,   414,   247,
     282,   283,  1830,   536,  1739,  1746,  1753,  1760,   406,     7,
     414,  1767,  1774,  1781,   604,    65,    65,   120,   120,   138,
     138,   339,    65,    12,   311,    82,   611,   614,   260,   289,
     260,    12,   311,    86,   439,   616,   553,  1681,   553,   296,
      12,    93,   621,    12,   115,   627,   296,   306,   307,  1788,
    1795,   480,   480,   317,   628,   640,  1883,  1889,  1895,   634,
    1911,  1915,  1919,  1923,   487,     7,   414,  1927,  1931,  1935,
    1939,  1901,   643,   648,  1703,  1710,  1717,   230,  1738,  1745,
    1752,  1759,   384,     7,   414,  1766,  1773,  1780,  1787,  1724,
     653,   659,   318,   358,   660,  1802,  1809,   661,  1561,  1589,
     469,  1907,    23,    12,   116,   663,   289,   289,  1731,  1813,
      12,   151,   674,  1681,  1681,   635,   364,  1823,   676,   721,
    1617,   345,   681,   687,  1943,  1947,  1951,  1955,   448,   688,
    1794,  1801,  1808,  1815,   701,   703,   475,  1959,  1822
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,   199,   726,  -218,  -218,  -218,  -109,   411,
    -115,  -218,   650,   271,  -127,  -218,   666,   -75,  -218,  -218,
     276,  -218,  -218,  -218,  -218,   -27,   165,    17,   142,  -217,
     629,  -100
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    26,     6,    12,    15,    16,    21,    23,
      27,    49,    50,    89,    52,    53,    54,    95,    55,    56,
     169,    58,    59,    60,    61,   170,   171,   172,   173,    90,
      91,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      62,   124,   105,   126,   146,   135,   254,    14,    -3,    71,
     133,   134,    94,   -75,   272,   174,   175,   176,   131,   177,
     178,    -2,   179,   291,   190,   215,   294,   216,     7,   -12,
       2,   -75,    98,     1,   130,   180,   181,   107,   153,   185,
     182,     2,   183,   -71,    64,    96,    97,   100,   102,   104,
      96,   106,   322,    64,   -48,   108,   -74,   199,   113,    71,
     211,    71,   107,   189,   189,    13,   225,   107,   191,   192,
     193,     8,   194,   195,   -74,   196,    17,   101,   103,    18,
     139,   233,    96,   187,    20,   141,   323,    22,   107,   197,
     185,   -64,   107,   329,   136,   198,   138,   241,   -64,   107,
     -64,   200,    64,   114,   212,   116,   256,    24,    62,   244,
     274,    29,    30,    31,    28,    32,    33,   292,   158,    11,
      -9,   107,   107,   203,   204,   205,   -65,   206,   207,   157,
     208,    67,    45,   -65,   187,   -65,   298,   299,    69,   295,
     324,   -17,   -17,   -17,   209,   -17,   -17,   -17,   -17,   -17,
     210,   -17,    64,   -17,   -17,   -17,   -17,   107,   -17,   -17,
     -17,   -17,   -17,    72,   290,   304,   -17,   -67,   -17,    65,
      -5,   297,   -17,   321,   -67,   330,   -67,   -66,    65,    -5,
     -11,    19,    73,   311,   -66,    -7,   -66,    74,   199,   199,
     211,   211,    63,    75,    -7,   199,   185,   255,    -4,     5,
      44,    63,   267,     9,   185,   273,    76,    -4,   188,   185,
     285,   185,    96,   185,   -56,   -68,   185,   -14,   -14,    96,
      77,   -56,   -68,   -56,   -68,   240,   201,    65,    65,   213,
      65,   186,   247,   248,   249,   250,   -64,   -64,   -64,   200,
     187,   -64,    -6,   -13,   -13,   258,   269,   271,   187,   111,
      63,    -6,   115,   276,   287,   289,   -64,   187,   -64,   188,
     187,   -64,   -64,   159,   160,   161,   -61,   162,   163,    -8,
     164,    62,    62,   -61,    78,   -61,   185,    65,    -8,   267,
     267,    83,   186,   185,   166,   -34,   285,   285,   -73,   117,
     168,    93,   259,   260,   261,   -10,   262,   263,    51,   264,
      63,   -59,   -62,    57,   -10,   -15,    94,    70,   -59,   -62,
     -59,   -62,    57,   265,   -15,    64,    64,   -35,    82,   266,
     187,   189,    80,   326,   327,   -57,   -58,   187,   222,   152,
     332,   333,   -57,   -58,   -57,   -58,   300,   -63,    92,   109,
      82,   110,   184,   215,   -63,   216,   -63,   159,   160,   161,
     118,   162,   163,   -70,   164,   119,    51,   201,   201,   213,
     213,    57,   -34,   -34,   201,   188,    81,   165,   166,   -37,
     -37,   270,   167,   188,   168,   222,   336,   -60,   188,   288,
     188,   -56,   188,   -69,   -60,   188,   -60,   253,   186,   121,
     -69,   120,   -69,   184,   268,   214,   186,   122,   -64,   -64,
     -64,   123,   286,   -64,   -64,   186,    51,   -41,   186,   125,
     -56,    57,   -56,   219,   310,   -56,   -56,   159,   160,   161,
     127,   162,   163,   128,   164,   129,    29,    30,    31,   137,
      32,    33,   -56,   202,   -56,   -56,   243,   165,   166,   227,
      65,    65,   167,   226,   168,   188,    44,    45,   270,   270,
     140,    46,   188,    69,   235,   288,   288,   142,   234,   143,
     -65,   -65,   -65,    63,    63,   -65,   -65,   144,   186,   242,
     -35,   -35,   -56,   -56,   -56,   186,   231,   -56,   -56,   -47,
     -47,   245,   145,   -19,   -19,   -19,   221,   -19,   -19,    25,
     -19,   -19,   -72,   -19,   -42,   -19,   -19,   -19,   -19,   184,
     -19,   -19,   -19,   -19,   -19,   -36,   -36,   184,   -19,   217,
     -19,   218,   -32,   -56,   -19,   -56,   184,   303,   -56,   184,
     148,   -56,   -56,   -56,   149,   -56,   -56,   150,   -56,   -56,
     -47,   -56,   220,   -56,   -56,   -56,   -56,   305,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,    66,   -56,
     -56,   -56,   -56,   223,   -56,   312,   174,   175,   176,   151,
     177,   178,   -64,   179,   -64,   -64,   -67,   -67,   -67,    51,
      51,   -67,   -67,   154,    57,    57,   155,   181,   156,   184,
     -41,   -41,   -41,   183,   -41,   -41,   184,   -41,   -41,   224,
     -41,   165,   -41,   -41,   -41,   -41,   -34,   -41,   -41,   -41,
     -41,   -41,    85,   -61,   -61,   -41,   -61,   -41,   -16,   -16,
     -16,   -41,   -16,   -16,   -16,   -16,   -16,   232,   -16,   180,
     -16,   -16,   -16,   -16,   -56,   -16,   -16,   -16,   -16,   -16,
     251,   252,   239,   -16,   246,   -16,   -19,   -19,   -19,   -16,
     -19,   -19,   -35,   -19,   -19,   257,   -19,   275,   -19,   -19,
     -19,   -19,   293,   -19,   -19,   -19,   -19,   -19,   296,   301,
     -64,   -19,   -64,   -19,   334,   -64,   220,   -19,   -50,   -50,
     -50,   302,   -50,   -50,   308,   -50,   -50,   147,   -50,   309,
     -50,   -50,   -50,   -50,   315,   -50,   -50,   -50,   -50,   -50,
     316,   317,   318,   -50,   325,   -50,    -8,    -8,    -8,   -50,
      -8,    -8,    -8,    -8,    -8,   331,    -8,   335,    -8,    -8,
      -8,    -8,   -47,    -8,    -8,    -8,    -8,    -8,   337,   338,
     -40,    -8,   -39,    -8,   -15,   -15,   -15,    -8,   -15,   -15,
      10,   -15,   -15,   -15,   -15,   112,   -15,   -15,   -15,   -15,
      99,   -15,   -15,   -15,   -15,   -15,   132,     0,     0,   -15,
       0,   -15,    29,    30,    31,   -15,    32,    33,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,     0,     0,     0,    46,     0,    47,
     -37,   -37,   -37,    48,   -37,   -37,     0,   -37,   -37,     0,
     -37,     0,   -37,   -37,   -37,   -37,     0,   -37,   -37,   -37,
     -37,   -37,     0,     0,     0,   -37,     0,   -37,   -18,   -18,
     -18,   -37,   -18,   -18,     0,   -18,   -18,     0,   -18,     0,
     -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,   -18,
       0,     0,     0,   -18,     0,   -18,   -20,   -20,   -20,   -18,
     -20,   -20,     0,   -20,   -20,     0,   -20,     0,   -20,   -20,
     -20,   -20,     0,   -20,   -20,   -20,   -20,   -20,     0,     0,
       0,   -20,     0,   -20,   -24,   -24,   -24,   -20,   -24,   -24,
       0,   -24,   -24,     0,   -24,     0,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,
       0,    84,   -25,   -25,   -25,   -24,   -25,   -25,     0,   -25,
     -25,     0,   -25,     0,   -25,   -25,   -25,   -25,     0,   -25,
     -25,   -25,   -25,   -25,     0,     0,     0,   -25,     0,   -25,
     -26,   -26,   -26,   -25,   -26,   -26,     0,   -26,   -26,     0,
     -26,     0,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,
     -26,   -26,     0,     0,     0,   -26,     0,   -26,   -27,   -27,
     -27,   -26,   -27,   -27,     0,   -27,   -27,     0,   -27,     0,
     -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,   -27,
       0,     0,     0,   -27,     0,   -27,   -28,   -28,   -28,   -27,
     -28,   -28,     0,   -28,   -28,     0,   -28,     0,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,   -28,   -28,     0,     0,
       0,   -28,     0,   -28,   -29,   -29,   -29,   -28,   -29,   -29,
       0,   -29,   -29,     0,   -29,     0,   -29,   -29,   -29,   -29,
       0,   -29,   -29,   -29,   -29,   -29,     0,     0,     0,   -29,
       0,   -29,   -21,   -21,   -21,   -29,   -21,   -21,     0,   -21,
     -21,     0,   -21,     0,   -21,   -21,   -21,   -21,     0,   -21,
     -21,   -21,   -21,   -21,     0,     0,     0,   -21,     0,   -21,
     -22,   -22,   -22,   -21,   -22,   -22,     0,   -22,   -22,     0,
     -22,     0,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,
     -22,   -22,     0,     0,     0,   -22,     0,   -22,   -23,   -23,
     -23,   -22,   -23,   -23,     0,   -23,   -23,     0,   -23,     0,
     -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,     0,   -23,   -55,   -55,   -55,   -23,
     -55,   -55,     0,   -55,   -55,     0,   -55,     0,   -55,   -55,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,     0,     0,
       0,   -55,     0,   -55,   -31,   -31,   -31,   -55,   -31,   -31,
       0,   -31,   -31,     0,   -31,     0,   -31,   -31,   -31,   -31,
       0,   -31,   -31,   -31,   -31,   -31,     0,     0,     0,   -31,
       0,   -31,   -54,   -54,   -54,   -31,   -54,   -54,     0,   -54,
     -54,     0,   -54,     0,   -54,   -54,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,     0,     0,     0,   -54,     0,   -54,
     -30,   -30,   -30,   -54,   -30,   -30,     0,   -30,   -30,     0,
     -30,     0,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,
     -30,   -30,     0,     0,     0,   -30,     0,   -30,   -53,   -53,
     -53,   -30,   -53,   -53,     0,   -53,   -53,     0,   -53,     0,
     -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,
       0,     0,     0,   -53,     0,   -53,    29,    30,    31,   -53,
      32,    33,     0,    34,    35,     0,    36,     0,    37,    38,
      39,    40,     0,    41,    42,    43,    44,    45,     0,     0,
       0,    46,     0,    47,   -49,   -49,   -49,   -52,   -49,   -49,
       0,   -49,   -49,     0,   -49,     0,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,   -49,     0,     0,     0,   -49,
       0,   -49,   -44,   -44,   -44,   -49,   -44,   -44,     0,   -44,
     -44,     0,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -44,   -44,     0,     0,     0,   -44,     0,   -44,
     -46,   -46,   -46,   -44,   -46,   -46,     0,   -46,   -46,     0,
     -46,     0,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,
     -46,   -46,     0,     0,     0,   -46,     0,   -46,   -40,   -40,
     -40,   -46,   -40,   -40,     0,   -40,   -40,     0,   -40,     0,
     -40,   -40,   -40,   -40,     0,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,   -40,     0,   -40,   -39,   -39,   -39,   -40,
     -39,   -39,     0,   -39,   -39,     0,   -39,     0,   -39,   -39,
     -39,   -39,     0,   -39,   -39,   -39,   -39,   -39,     0,     0,
       0,   -39,     0,   -39,   -36,   -36,   -36,   -39,   -36,   -36,
       0,   -36,   -36,     0,   -36,     0,   -36,   -36,   -36,   -36,
       0,   -36,   -36,   -36,   -36,   -36,     0,     0,     0,   -36,
       0,   -36,   -51,   -51,   -51,   -36,   -51,   -51,     0,   -51,
     -51,     0,   -51,     0,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -51,   -51,   -51,     0,     0,     0,   -51,     0,   -51,
     -38,   -38,   -38,   -51,   -38,   -38,     0,   -38,   -38,     0,
     -38,     0,   -38,   -38,   -38,   -38,     0,   -38,   -38,   -38,
     -38,   -38,     0,     0,     0,   -38,     0,   -38,   -43,   -43,
     -43,   -38,   -43,   -43,     0,   -43,   -43,     0,   -43,     0,
     -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,   -43,
       0,     0,     0,   -43,     0,   -43,   -45,   -45,   -45,   -43,
     -45,   -45,     0,   -45,   -45,     0,   -45,     0,   -45,   -45,
     -45,   -45,     0,   -45,   -45,   -45,   -45,   -45,     0,     0,
       0,   -45,     0,   -45,    29,    30,    31,   -45,    32,    33,
       0,    34,    35,     0,    36,     0,    37,    38,    39,    40,
       0,    41,    42,    43,    44,    45,     0,     0,     0,    46,
       0,    47,    29,    30,    31,   319,    32,    33,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,     0,    41,
      42,    43,    44,    45,     0,     0,     0,    46,     0,    47,
     -15,   -15,   -15,   320,   -15,   -15,     0,   -15,   -15,     0,
     -15,     0,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,
     -15,   -15,     0,     0,     0,   -15,     0,   -15,    29,    30,
      31,   -15,    32,    33,     0,   158,   174,   175,   176,     0,
     177,   178,     0,   179,     0,   -66,   -66,   -66,    44,    45,
     -66,   -66,     0,    46,    68,    69,   180,   181,     0,     0,
       0,   182,     0,   183,   277,   278,   279,     0,   280,   281,
       0,   282,   -68,   -68,   -68,     0,     0,   -68,   -68,     0,
       0,   -61,   -61,   -61,     0,   283,   -61,   -61,   236,   237,
     238,   284,     0,   -33,   -33,   -59,   -59,   -59,     0,     0,
     -59,   -59,   -62,   -62,   -62,     0,     0,   -62,   -62,   -63,
     -63,   -63,     0,     0,   -63,   -63,   -60,   -60,   -60,     0,
       0,   -60,   -60,   -57,   -57,   -57,     0,     0,   -57,   -57,
     -58,   -58,   -58,     0,     0,   -58,   -58,   -69,   -69,   -69,
       0,     0,   -69,   -69,   -65,   -65,   -65,   -65,   -65,   -65,
     -65,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   313,
     -59,   314,   -59,   -59,   -32,   -32,   -59,   -62,   -59,   -62,
     -62,   -59,   -59,   -62,   -57,   -62,   -57,   -57,   -62,   -62,
     -63,   -58,   -63,   -58,   -58,   -63,   -63,   -60,   -63,   -60,
     -63,   -63,   -60,   -60,   -57,   -60,   -57,   -60,   -60,   -57,
     -57,   -58,   328,   -58,   -48,   -48,   -58,   -58,   -69,   -69,
     -69,   -69,   -69,   -69,   -69,   -56,   -56,   -56,   -56,   -56,
      66,   -65,   -65,   -65,     0,     0,   -65,   -67,   -67,   -67,
       0,     0,   -67,   -66,   -66,   -66,     0,     0,   -66,   -68,
     -68,   -68,     0,     0,   -68,   -61,   -61,   -61,     0,     0,
     -61,   228,   229,   230,     0,     0,   -33,   -59,   -59,   -59,
       0,     0,   -59,   -62,   -62,   -62,     0,     0,   -62,   -63,
     -63,   -63,     0,     0,   -63,   -60,   -60,   -60,     0,     0,
     -60,   -57,   -57,   -57,     0,     0,   -57,   -58,   -58,   -58,
       0,     0,   -58,   -69,   -69,   -69,     0,   -65,   -69,   -65,
       0,   -67,   -65,   -67,     0,   -66,   -67,   -66,     0,   -68,
     -66,   -68,     0,   -61,   -68,   -61,     0,   306,   -61,   307,
       0,   -59,   -32,   -59,     0,   -62,   -59,   -62,     0,   -63,
     -62,   -63,     0,   -60,   -63,   -60,     0,   -57,   -60,   -57,
       0,   -58,   -57,   -58,     0,   -69,   -58,   -69,     0,     0,
     -69,    85,   -61,   -61,   -61,   -61,   -56,   -56,   -56,   -56,
      66,   -64,   -64,   -64,   -64,   -65,   -65,   -65,   -65,   -67,
     -67,   -67,   -67,   -66,   -66,   -66,   -66,   -68,   -68,   -68,
     -68,    86,    87,    88,   -33,   -59,   -59,   -59,   -59,   -62,
     -62,   -62,   -62,   -61,   -61,   -61,   -61,   -63,   -63,   -63,
     -63,   -60,   -60,   -60,   -60,   -57,   -57,   -57,   -57,   -58,
     -58,   -58,   -58,   -69,   -69,   -69,   -69
};

static const yytype_int16 yycheck[] =
{
      27,   101,    77,   103,   131,   120,   223,     9,     0,    36,
     119,   120,    10,     6,   231,     3,     4,     5,    19,     7,
       8,     0,    10,   240,    22,    26,   243,    28,    10,    31,
       9,    24,    30,     1,   109,    23,    24,     6,   147,    66,
      28,     9,    30,    31,    27,    72,    73,    74,    75,    76,
      77,    78,    29,    36,    31,    24,     6,    84,    85,    86,
      87,    88,     6,    10,    10,    30,   166,     6,     3,     4,
       5,     0,     7,     8,    24,    10,    10,    24,    24,    31,
      24,   181,   109,    66,    33,    24,   303,     9,     6,    24,
     117,    19,     6,   310,   121,    30,   123,   197,    26,     6,
      28,    84,    85,    86,    87,    88,    24,    10,   135,   209,
      24,     3,     4,     5,    10,     7,     8,    24,    10,    29,
      30,     6,     6,     3,     4,     5,    19,     7,     8,    29,
      10,    30,    24,    26,   117,    28,   251,   252,    30,    24,
      24,     3,     4,     5,    24,     7,     8,     9,    10,    11,
      30,    13,   135,    15,    16,    17,    18,     6,    20,    21,
      22,    23,    24,    30,   239,   265,    28,    19,    30,    27,
       0,   246,    34,   300,    26,    24,    28,    19,    36,     9,
      31,    32,    30,   283,    26,     0,    28,    30,   215,   216,
     217,   218,    27,    30,     9,   222,   223,   224,     0,     0,
      23,    36,   229,     4,   231,   232,    30,     9,    66,   236,
     237,   238,   239,   240,    19,    19,   243,    31,    32,   246,
      30,    26,    26,    28,    28,    30,    84,    85,    86,    87,
      88,    66,   215,   216,   217,   218,    26,    27,    28,   222,
     223,    31,     0,    31,    32,   228,   229,   230,   231,    84,
      85,     9,    87,   236,   237,   238,    26,   240,    28,   117,
     243,    31,    32,     3,     4,     5,    19,     7,     8,     0,
      10,   298,   299,    26,    30,    28,   303,   135,     9,   306,
     307,    29,   117,   310,    24,    29,   313,   314,    31,    32,
      30,    29,     3,     4,     5,     0,     7,     8,    27,    10,
     135,    19,    19,    27,     9,     0,    10,    36,    26,    26,
      28,    28,    36,    24,     9,   298,   299,    29,    47,    30,
     303,    10,    46,   306,   307,    19,    19,   310,    30,    31,
     313,   314,    26,    26,    28,    28,    19,    19,    67,    30,
      69,    31,    66,    26,    26,    28,    28,     3,     4,     5,
      31,     7,     8,    31,    10,    31,    85,   215,   216,   217,
     218,    85,    31,    32,   222,   223,    22,    23,    24,    30,
      31,   229,    28,   231,    30,    30,    31,    19,   236,   237,
     238,    19,   240,    19,    26,   243,    28,   222,   223,    19,
      26,    31,    28,   117,   229,    22,   231,    31,    26,    27,
      28,    19,   237,    31,    32,   240,   135,    19,   243,    31,
      26,   135,    28,    33,    30,    31,    32,     3,     4,     5,
      31,     7,     8,    31,    10,    31,     3,     4,     5,    29,
       7,     8,    26,    10,    28,    29,    30,    23,    24,   168,
     298,   299,    28,   167,    30,   303,    23,    24,   306,   307,
      29,    28,   310,    30,   183,   313,   314,    29,   182,    29,
      26,    27,    28,   298,   299,    31,    32,    29,   303,   198,
      31,    32,    26,    27,    28,   310,    30,    31,    32,    31,
      32,   210,    31,     3,     4,     5,    17,     7,     8,     9,
      10,    11,    31,    13,    31,    15,    16,    17,    18,   223,
      20,    21,    22,    23,    24,    30,    31,   231,    28,    26,
      30,    28,    29,    26,    34,    28,   240,    30,    31,   243,
      31,     3,     4,     5,    31,     7,     8,    31,    10,    11,
      29,    13,    33,    15,    16,    17,    18,   266,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    26,
      27,    28,    34,    30,    31,   284,     3,     4,     5,    31,
       7,     8,    26,    10,    28,    29,    26,    27,    28,   298,
     299,    31,    32,    29,   298,   299,    29,    24,    29,   303,
       3,     4,     5,    30,     7,     8,   310,    10,    11,    30,
      13,    23,    15,    16,    17,    18,    31,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,     3,     4,
       5,    34,     7,     8,     9,    10,    11,    30,    13,    23,
      15,    16,    17,    18,    31,    20,    21,    22,    23,    24,
     219,   220,    30,    28,    30,    30,     3,     4,     5,    34,
       7,     8,    31,    10,    11,    31,    13,    31,    15,    16,
      17,    18,    31,    20,    21,    22,    23,    24,    31,    31,
      26,    28,    28,    30,    29,    31,    33,    34,     3,     4,
       5,    31,     7,     8,    31,    10,    11,    12,    13,    31,
      15,    16,    17,    18,    31,    20,    21,    22,    23,    24,
      31,    31,    31,    28,    31,    30,     3,     4,     5,    34,
       7,     8,     9,    10,    11,    31,    13,    31,    15,    16,
      17,    18,    31,    20,    21,    22,    23,    24,    31,    31,
      19,    28,    19,    30,     3,     4,     5,    34,     7,     8,
       4,    10,    11,    12,    13,    85,    15,    16,    17,    18,
      74,    20,    21,    22,    23,    24,   117,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,    11,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    28,    -1,    30,     3,     4,     5,    34,
       7,     8,    -1,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    34,     7,     8,
      -1,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    28,
      -1,    30,     3,     4,     5,    34,     7,     8,    -1,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    28,    -1,    30,
       3,     4,     5,    34,     7,     8,    -1,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    28,    -1,    30,     3,     4,
       5,    34,     7,     8,    -1,    10,     3,     4,     5,    -1,
       7,     8,    -1,    10,    -1,    26,    27,    28,    23,    24,
      31,    32,    -1,    28,    29,    30,    23,    24,    -1,    -1,
      -1,    28,    -1,    30,     3,     4,     5,    -1,     7,     8,
      -1,    10,    26,    27,    28,    -1,    -1,    31,    32,    -1,
      -1,    26,    27,    28,    -1,    24,    31,    32,    26,    27,
      28,    30,    -1,    31,    32,    26,    27,    28,    -1,    -1,
      31,    32,    26,    27,    28,    -1,    -1,    31,    32,    26,
      27,    28,    -1,    -1,    31,    32,    26,    27,    28,    -1,
      -1,    31,    32,    26,    27,    28,    -1,    -1,    31,    32,
      26,    27,    28,    -1,    -1,    31,    32,    26,    27,    28,
      -1,    -1,    31,    32,    26,    26,    28,    28,    29,    31,
      32,    26,    26,    28,    28,    29,    31,    32,    26,    26,
      28,    28,    29,    31,    32,    26,    26,    28,    28,    29,
      31,    32,    26,    26,    28,    28,    29,    31,    32,    26,
      26,    28,    28,    29,    31,    32,    26,    26,    28,    28,
      29,    31,    32,    26,    26,    28,    28,    29,    31,    32,
      26,    26,    28,    28,    29,    31,    32,    26,    26,    28,
      28,    29,    31,    32,    26,    26,    28,    28,    29,    31,
      32,    26,    29,    28,    31,    32,    31,    32,    26,    26,
      28,    28,    29,    31,    32,    25,    26,    27,    28,    29,
      30,    26,    27,    28,    -1,    -1,    31,    26,    27,    28,
      -1,    -1,    31,    26,    27,    28,    -1,    -1,    31,    26,
      27,    28,    -1,    -1,    31,    26,    27,    28,    -1,    -1,
      31,    26,    27,    28,    -1,    -1,    31,    26,    27,    28,
      -1,    -1,    31,    26,    27,    28,    -1,    -1,    31,    26,
      27,    28,    -1,    -1,    31,    26,    27,    28,    -1,    -1,
      31,    26,    27,    28,    -1,    -1,    31,    26,    27,    28,
      -1,    -1,    31,    26,    27,    28,    -1,    26,    31,    28,
      -1,    26,    31,    28,    -1,    26,    31,    28,    -1,    26,
      31,    28,    -1,    26,    31,    28,    -1,    26,    31,    28,
      -1,    26,    31,    28,    -1,    26,    31,    28,    -1,    26,
      31,    28,    -1,    26,    31,    28,    -1,    26,    31,    28,
      -1,    26,    31,    28,    -1,    26,    31,    28,    -1,    -1,
      31,    25,    26,    27,    28,    29,    26,    27,    28,    29,
      30,    26,    27,    28,    29,    26,    27,    28,    29,    26,
      27,    28,    29,    26,    27,    28,    29,    26,    27,    28,
      29,    26,    27,    28,    29,    26,    27,    28,    29,    26,
      27,    28,    29,    26,    27,    28,    29,    26,    27,    28,
      29,    26,    27,    28,    29,    26,    27,    28,    29,    26,
      27,    28,    29,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    36,    37,    38,    39,    10,     0,    38,
      39,    29,    40,    30,     9,    41,    42,    10,    31,    32,
      33,    43,     9,    44,    10,     9,    38,    45,    10,     3,
       4,     5,     7,     8,    10,    11,    13,    15,    16,    17,
      18,    20,    21,    22,    23,    24,    28,    30,    34,    46,
      47,    48,    49,    50,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    30,    30,    29,    30,
      48,    60,    30,    30,    30,    30,    30,    30,    30,    66,
      55,    22,    48,    29,    30,    25,    26,    27,    28,    48,
      64,    65,    48,    29,    10,    52,    60,    60,    30,    51,
      60,    24,    60,    24,    60,    52,    60,     6,    24,    30,
      31,    61,    47,    60,    62,    61,    62,    32,    31,    31,
      31,    19,    31,    19,    66,    31,    66,    31,    31,    31,
      52,    19,    65,    43,    43,    45,    60,    29,    60,    24,
      29,    24,    29,    29,    29,    31,    49,    12,    31,    31,
      31,    31,    31,    43,    29,    29,    29,    29,    10,     3,
       4,     5,     7,     8,    10,    23,    24,    28,    30,    55,
      60,    61,    62,    63,     3,     4,     5,     7,     8,    10,
      23,    24,    28,    30,    55,    60,    61,    62,    63,    10,
      22,     3,     4,     5,     7,     8,    10,    24,    30,    60,
      62,    63,    10,     3,     4,     5,     7,     8,    10,    24,
      30,    60,    62,    63,    22,    26,    28,    26,    28,    33,
      33,    17,    30,    30,    30,    66,    55,    48,    26,    27,
      28,    30,    30,    66,    55,    48,    26,    27,    28,    30,
      30,    66,    48,    30,    66,    48,    30,    62,    62,    62,
      62,    44,    44,    61,    64,    60,    24,    31,    62,     3,
       4,     5,     7,     8,    10,    24,    30,    60,    61,    62,
      63,    62,    64,    60,    24,    31,    62,     3,     4,     5,
       7,     8,    10,    24,    30,    60,    61,    62,    63,    62,
      52,    64,    24,    31,    64,    24,    31,    52,    45,    45,
      19,    31,    31,    30,    66,    48,    26,    28,    31,    31,
      30,    66,    48,    26,    28,    31,    31,    31,    31,    34,
      34,    49,    29,    64,    24,    31,    62,    62,    29,    64,
      24,    31,    62,    62,    29,    31,    31,    31,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    36,    37,    37,    37,    37,    38,    40,
      39,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    47,    48,    48,    48,    48,    49,    49,    50,    51,
      51,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      57,    57,    58,    58,    59,    59,    60,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      64,    64,    65,    65,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     3,     0,
       7,     1,     0,     4,     2,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     1,     1,     2,     6,     1,     7,     6,
       5,     1,     3,     7,     5,     7,     5,     5,     4,     5,
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
#line 1851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.y" /* yacc.c:1646  */
    {}
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1865 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1881 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), 'V');
    }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'F');
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 1907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1924 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 1932 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("COMPOUND_STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOCAL_DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 179 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 182 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 185 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2014 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2046 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2070 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 212 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2078 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 215 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2086 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 221 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 224 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2102 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 227 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2110 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 230 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 236 "parser.y" /* yacc.c:1646  */
    {
    }
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "parser.y" /* yacc.c:1646  */
    {
    }
#line 2132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 243 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("REMOVE_STATEMENT", (yyvsp[-4].node), (yyvsp[-2].node), NULL, (yyvsp[-6].token));
    }
#line 2140 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 249 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2148 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 252 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2172 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 267 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-3].node), NULL, NULL, (yyvsp[-6].token));
    }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 270 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 276 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-3].node), NULL, NULL, (yyvsp[-6].token));
    }
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 279 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2204 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 285 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 288 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2236 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 310 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 314 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 320 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 323 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 329 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 335 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 338 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 341 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 347 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2317 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 350 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 353 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 356 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 359 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 362 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2357 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 365 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2365 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 368 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2373 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 371 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 377 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 383 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2397 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 386 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2405 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 392 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 395 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2421 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 401 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "string", (yyvsp[0].token)); 
    }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2437 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2441 "parser.tab.c" /* yacc.c:1646  */
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
