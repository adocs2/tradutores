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
extern int column;
extern int lex_error;
extern void yyerror(const char* msg);
extern FILE *yyin;

typedef struct node {
    char* class;  
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

typedef struct param_node {
    char* key;
    struct param_node *next;
} param_node;

typedef struct symbol_node {
    char* key;
    char* name;
    char* type;
    char* symbol_type;
    param_node* param_list;
    char* scope_name;
    UT_hash_handle hh;
} symbol_node;

symbol_node *symbol_table = NULL;

void init_scope_global();
node* create_tree_node(char* class, node* left, node* right, char* type, char* value);
symbol_node* create_symbol(char* key, char *name, char* type, char* symbol_type, char* scope_name);
void add_symbol(char* name, char* type, char* symbol_type);
void push_stack(char* scope_name, char* type);
void pop_stack();
char* concat_string(const char *s1, const char *s2);
void print_parser_tree(node * tree, int depth);
void print_depth(int depth);
void free_parser_tree(struct node* no);
void print_symbol_table();
void free_symbol_table();


#line 135 "parser.tab.c" /* yacc.c:339  */

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
    THEN = 281,
    ASSIGN = 282,
    OP = 283,
    RELOP = 284,
    LOG = 285
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 71 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 211 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   3307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  415

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

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
      32,    33,     2,     2,    34,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    92,    96,    99,   102,   105,   108,   114,
     121,   121,   132,   135,   141,   145,   151,   154,   160,   166,
     169,   175,   178,   181,   184,   187,   190,   193,   196,   199,
     202,   209,   212,   218,   221,   224,   227,   233,   236,   239,
     242,   245,   251,   257,   260,   263,   269,   272,   275,   281,
     287,   290,   297,   303,   306,   312,   318,   321,   324,   330,
     333,   336,   339,   342,   345,   348,   351,   357,   363,   366,
     372,   375
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
  "CHAR", "THEN", "ASSIGN", "OP", "RELOP", "LOG", "';'", "'('", "')'",
  "','", "'{'", "'}'", "$accept", "program", "declaration-list",
  "variable-declaration", "function", "$@1", "params-list", "params",
  "compound-inline", "compound-stmt", "stmt-list", "stmt", "expr",
  "set-func", "simple-expr", "in-stmt", "write-stmt", "writeln-stmt",
  "read-stmt", "conditional-stmt", "iteration-stmt", "return-stmt", "var",
  "op-expr", "term", "call", "args", "arg-list", YY_NULLPTR
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
     285,    59,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -225

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-225)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     508,    24,     6,    32,   157,   617,   652,    66,  -225,   701,
     709,   747,     5,     1,    43,    22,    95,   129,    58,    48,
    1911,   765,    49,  1941,   182,  1971,  3037,  3041,  3045,  3058,
    3062,   108,   638,   155,   138,   166,   168,   228,   241,   275,
     283,   304,   309,   214,   171,   825,  2001,  2031,  2061,    -5,
      16,    47,  2091,  2121,  2151,  2181,  2211,  2241,   973,  3066,
    3079,  3083,   164,   104,   171,  2271,   120,   128,  3087,   497,
     258,   497,   497,    13,    15,   497,   258,   152,    10,  2301,
     813,  2331,   919,   201,   322,   201,    69,   310,   311,    17,
    2361,   328,    37,   330,   346,    82,    87,   347,   367,   382,
     383,   392,   399,   100,   400,  3100,   281,  2391,  3104,  3125,
    3108,   957,  3121,  1026,  2901,   423,   297,   365,   425,   430,
     455,   475,   482,   485,   438,   552,   465,    64,   467,  1127,
    2421,  2451,  2481,  2511,  2541,  2571,  2601,  2631,  2901,  2661,
    3018,   305,   323,   515,   725,   763,  2915,   381,   492,   498,
     523,  3040,   171,   119,   121,   879,  2923,  2930,  2936,  2691,
     237,   417,   551,   608,   662,   216,   540,   541,   542,   544,
    3061,   171,    71,    91,   669,   687,   751,   771,   858,   891,
    1058,  3185,  3191,   535,   570,   573,   575,   581,  3082,   171,
     516,  3197,  3203,  3209,  3215,   171,  3129,  3135,  3139,  3143,
    3149,  1159,   171,  3153,  3157,  3163,   957,   322,   322,  1191,
     598,   583,   291,   601,   603,   618,   621,  1911,  1221,  1251,
     620,   627,  1281,  1311,  1341,  1371,  1401,  1431,  3024,  1911,
    2721,  2751,   104,   497,   497,   497,   258,   139,   193,   362,
     385,   362,   104,   497,   497,   497,   258,    98,   236,   394,
     402,   394,   104,   497,   497,   497,   258,   635,   278,   586,
     596,   586,   285,   104,   286,   131,  3167,  3171,   624,   171,
    1461,   656,   497,   258,    21,    39,  2781,  1491,  1521,   919,
    2811,   645,   287,   326,   345,   646,  2942,  2948,   818,   986,
    2966,  2967,  2973,   493,   171,  2979,  2983,  2989,  2995,  2954,
     650,   389,   404,   408,   661,   871,   924,   503,   643,   700,
     837,   978,   343,   171,  1063,  1071,  1083,  1090,   965,   667,
     416,   433,   434,   674,  3221,  3227,   707,  1041,  3245,  3246,
    3251,   745,   171,  3252,  3258,  3259,  3264,  3233,   675,  3177,
    1551,   462,  1581,   477,   691,   692,   694,   698,   699,   710,
     712,  1611,  1641,  2841,  2960,   509,   520,   527,   533,   104,
     576,   385,   385,  1051,   158,   163,   188,   206,   104,   591,
     402,   402,  3239,   670,   730,   742,   749,   104,   592,   596,
     596,  3181,  1026,  1026,   738,   741,   752,   756,   767,   778,
     780,   761,  2996,  3002,  3008,   782,  1132,  1139,  1152,   786,
    3265,  3271,  3272,  2871,  1671,  1701,  1731,  1761,  1791,  1821,
    1851,  1881,  3012,  2907,  3277
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,  -225,     0,   823,  -225,  -225,  -225,   -94,   -15,
    -134,  -108,   -80,   534,   744,   820,  -106,  -104,  -102,  -100,
     -98,   -96,   -22,   600,   179,   380,  -224,   711
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    46,     6,    12,    15,    16,   127,   128,
      23,    47,    48,   190,    91,    51,    52,    53,    54,    55,
      56,    57,   191,   192,   193,   194,    87,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    58,   107,    21,     9,   129,   231,   222,   281,   223,
      14,   224,    68,   225,   -40,   226,     7,   227,   300,    97,
     130,   100,   155,    93,    -3,    93,    79,   345,   319,   195,
     231,    93,     8,   219,   -13,    80,   195,    13,    98,   338,
     101,   174,   155,   105,   139,   348,   346,    81,    94,    93,
     113,    99,   102,    17,   104,    18,   -41,    22,    68,    24,
      58,    68,   203,    68,   349,   -50,   -41,   -50,   -50,   -50,
     114,   -50,   -50,   -50,   -50,   -50,   138,   -50,   -41,   -50,
     -50,   -50,   -50,   276,   -50,   -50,   -50,   -50,   206,   174,
     -40,   228,    58,    20,   -50,   280,   -50,    11,   -10,   230,
     -50,   -41,   -71,   111,   -40,   -40,   -41,   160,   161,   162,
     -41,   163,   164,   218,   165,   116,    58,   -39,    62,   -41,
     117,   166,   167,   230,   -41,   -41,   168,   169,   -12,    19,
     155,   -39,   -39,   124,   170,   391,   171,   -69,   -40,   -40,
     -41,    26,    27,    28,   395,    29,    30,    80,   140,   155,
     206,   -40,   -40,   399,   -41,    37,    38,    -2,   -39,    90,
      41,    42,   -15,   -15,   -42,   -42,     2,   155,    43,    65,
      44,   -39,   -39,   155,   141,   142,   143,   -33,   144,   145,
     155,   146,   -34,   -39,   174,   203,   203,    64,   147,   148,
      68,   -33,   -33,   149,   150,   159,   -34,   -34,    69,   352,
      70,   151,    60,   152,    26,    27,    28,   -35,    29,    30,
     174,   140,   195,    60,   285,   -14,   -14,   155,   295,   155,
     174,   -35,   -35,   157,   304,   -36,   286,   174,   314,   174,
     174,    37,    38,    44,   323,   -55,    41,    42,   333,   -36,
     -36,   174,   176,   157,   -55,   -55,   -55,   155,   242,   -55,
     -55,   344,   347,   350,    58,   195,   -62,   228,    58,    60,
      71,    60,   108,   204,   110,   -62,   -62,   -62,    93,   305,
     -62,   -62,   155,    72,   129,   129,   222,   222,   223,   223,
     224,   224,   225,   225,   226,   226,   227,   227,   403,   404,
     176,   155,    60,    60,    26,    27,    28,   195,    29,    30,
      80,   140,   219,   219,   195,   195,   -41,    73,    37,    38,
     155,   324,   -42,    41,    42,    74,   -33,    60,   -42,   339,
     355,    43,   270,    44,   -62,   196,   197,   198,   -33,   199,
     200,   157,   201,   -62,   -62,   -62,    75,   174,   -62,   295,
     295,    76,   -63,   112,   -68,   -41,   174,   195,   314,   314,
     157,   -63,   -63,   -63,   202,   174,   -63,   333,   333,   356,
     228,   228,   -55,   -55,   -41,   141,   142,   143,   157,   144,
     145,   -55,   146,   -55,   157,   368,   -55,   -55,   357,   115,
     118,   157,   218,   218,   -34,   176,   266,   267,   288,   289,
     290,    60,   291,   292,   152,   293,   -34,   160,   161,   162,
     119,   163,   164,    61,   165,   307,   308,   309,   -41,   310,
     311,   176,   312,   233,    61,   120,   121,   294,   287,   297,
     299,   176,   364,   -41,   158,   122,   171,   -41,   306,   316,
     318,   176,   123,   125,   313,   -41,   -63,   365,   325,   335,
     337,   366,   176,   177,   158,   -63,   -63,   -63,   157,   373,
     -63,   -63,   -41,   -41,   131,    60,   132,   -35,    60,    60,
      61,   133,    61,    61,   205,    61,   374,   375,   -16,   -35,
     -16,   -16,   -16,   157,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   195,   -16,   -16,   -16,   -16,   134,   -16,   -16,   -16,
     -16,   177,   157,    61,    61,   382,   -41,   -16,   -70,   -16,
     178,   179,   180,   -16,   181,   182,   135,   183,    -8,     1,
     383,   157,   -55,   136,   184,   185,   137,     2,    61,   186,
     187,   -55,   -62,   -55,   234,   359,   -55,   188,   -33,   189,
     235,   -62,   158,   -62,   -65,   -40,   -62,   -62,   176,   -34,
     393,   394,   -33,   -65,   -65,   -65,   -35,   176,   -65,   397,
     398,   158,   -36,   -34,   -55,   236,   176,    49,   401,   402,
     -35,    60,    60,   -55,   -55,   -55,   -36,   252,    66,   158,
     -65,   -36,   243,   244,   245,   158,   246,    77,   153,   -65,
     -65,   -65,   158,   -36,   -65,   -65,   177,   205,   205,   178,
     179,   180,    61,   181,   182,   195,   183,   172,   153,   326,
     327,   328,   253,   329,   330,   254,   331,   255,   268,   392,
     195,   195,   177,   256,    66,   269,    66,    -5,   189,   158,
     298,   158,   177,    59,   396,   400,    -5,   -64,   332,   177,
     317,   177,   177,   272,    59,   273,   -64,   -64,   -64,   -40,
     336,   -64,   -64,   177,   156,   172,    80,   220,    49,   158,
     274,   277,    -7,   275,   -39,   340,    61,   -55,   278,    61,
      61,    -7,   -63,   175,   156,   -55,   -55,   -55,   -55,   -55,
      63,   -63,    49,   -63,   158,    80,   -63,   -63,   354,   358,
      59,   -66,    59,   363,   109,   237,   153,   342,   -60,   -33,
     -66,   -66,   -66,   158,   367,   -66,   -66,   -60,   -60,   -60,
     372,    -4,   -60,   -60,   247,   153,   -38,   376,   381,    -6,
      -4,   175,   158,    59,    59,   249,   250,   251,    -6,   -65,
     -38,   -38,   257,   153,   384,   385,   -62,   386,   -65,   153,
     -65,   387,   388,   -65,   -65,   -62,   153,   -62,    59,   177,
     172,   298,   298,   389,   -64,   390,    66,    -9,   177,   -34,
     317,   317,   156,   -64,   -64,   -64,    -9,   177,   -64,   336,
     336,   -35,    61,    61,   -55,   -11,   172,    50,   -36,   405,
     -58,   156,   406,   -55,   -11,   -55,   172,   377,    67,   -58,
     -58,   -58,   -66,   407,   -58,   -58,   172,   408,    78,   156,
     -61,   -66,   -66,   -66,   412,   156,   -66,   172,   409,   -61,
     -61,   -61,   156,   153,   -61,   -61,   175,    86,    89,   410,
      49,   411,    59,    66,    49,   413,    26,    27,    28,   414,
      29,    30,   126,   140,   106,   -18,    50,    10,   153,     0,
      37,    38,   175,     0,   -18,    41,    42,   -62,     0,     0,
     296,     0,   175,    43,     0,    44,   -62,   153,   -62,     0,
     315,   -62,   175,     0,     0,    86,   -64,   221,    50,     0,
     334,     0,     0,   175,   154,   -64,   153,   -64,     0,   156,
     -64,   -64,     0,     0,     0,     0,    59,   -62,     0,    59,
      59,     0,    50,   173,   154,     0,   -62,   -62,   -62,    92,
     -59,    95,    96,   172,   156,   103,   238,     0,   -60,   -59,
     -59,   -59,   172,     0,   -59,   -59,     0,   -60,   -60,   -60,
     -63,   172,   -60,   156,     0,   248,   220,   220,     0,   -63,
     -63,   -63,    26,    27,    28,     0,    29,    30,     0,    32,
       0,   173,   156,   258,     0,     0,    37,    38,     0,   262,
       0,    41,    42,   -56,     0,     0,   264,     0,     0,    43,
     265,    44,   -56,   -56,   -56,     0,   271,   -56,   -56,   175,
     160,   161,   162,     0,   163,   164,     0,   165,   175,     0,
       0,     0,   154,     0,   166,   167,    86,   175,     0,   168,
     169,     0,    59,    59,   -57,     0,    86,   170,     0,   171,
       0,   154,   -60,   -57,   -57,   -57,    86,   -66,   -57,   -57,
      82,   -60,   -60,   -60,   -60,   -63,   -66,    86,   -66,   154,
       0,   -66,   -66,   341,   -63,   154,   -63,     0,     0,   -63,
      50,     0,   154,   221,    50,     0,   173,   209,     0,    26,
      27,    28,     0,    29,    30,   210,    32,   211,   360,   212,
       0,   213,   214,    37,    38,     0,   215,   216,    41,    42,
       0,     0,   173,   282,   283,   284,    43,   369,    44,     0,
     -63,   217,   173,   301,   302,   303,     0,     0,     0,   -63,
     -67,   -63,   173,   320,   321,   322,   378,   -65,     0,   -67,
     -67,   -67,   -60,   173,   -67,   -67,   -65,   -65,   -65,   154,
     -37,   -60,   343,   -60,     0,     0,   -60,   -60,     0,   370,
       0,   371,   -58,    86,   -37,   -37,     0,     0,     0,   -61,
       0,   -58,    86,   -58,   154,     0,   -58,   -58,   -61,     0,
     -61,    86,     0,   -61,   -61,     0,   221,   221,   -17,     0,
     -17,   -17,   -17,   154,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,     0,   -17,   -17,   -17,   -17,     0,   -17,   -17,   -17,
     -17,   -59,   154,     0,     0,     0,     0,   -17,   -56,   -17,
     -59,     0,   -59,   -17,     0,   -59,   -59,   -56,     0,   -56,
       0,   -57,   -56,   -56,     0,     0,     0,     0,   -55,   173,
     -57,     0,   -57,     0,     0,   -57,   -57,   -55,   173,   -55,
     -55,   263,   -30,     0,   -30,   -30,   -30,   173,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -30,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -21,   -30,   -21,   -21,   -21,   -30,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,
       0,   -21,   -21,   -21,   -21,     0,     0,     0,     0,     0,
       0,   -21,   -22,   -21,   -22,   -22,   -22,   -21,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,   -22,     0,     0,     0,     0,     0,
       0,   -22,   -27,   -22,   -27,   -27,   -27,   -22,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
       0,   -27,   -27,   -27,   -27,     0,     0,     0,     0,     0,
       0,   -27,   -28,   -27,   -28,   -28,   -28,   -27,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   -28,     0,     0,     0,     0,     0,
       0,   -28,   -29,   -28,   -29,   -29,   -29,   -28,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,
       0,   -29,   -29,   -29,   -29,     0,     0,     0,     0,     0,
       0,   -29,   -23,   -29,   -23,   -23,   -23,   -29,   -23,   -23,
     -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,     0,     0,     0,     0,     0,
       0,   -23,   -24,   -23,   -24,   -24,   -24,   -23,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,   -24,     0,     0,     0,     0,     0,
       0,   -24,   -25,   -24,   -25,   -25,   -25,   -24,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,
       0,   -25,   -25,   -25,   -25,     0,     0,     0,     0,     0,
       0,   -25,   -54,   -25,   -54,   -54,   -54,   -25,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -26,   -54,   -26,   -26,   -26,   -54,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -26,   -26,     0,     0,     0,     0,     0,
       0,   -26,   -32,   -26,   -32,   -32,   -32,   -26,   -32,   -32,
     -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,
       0,   -32,   -32,   -32,   -32,     0,     0,     0,     0,     0,
       0,   -32,    -9,   -32,    -9,    -9,    -9,   -32,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,     0,    -9,    -9,    -9,    -9,
       0,    -9,    -9,    -9,    -9,     0,     0,     0,     0,     0,
       0,    -9,   -53,    -9,   -53,   -53,   -53,    -9,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,
       0,   -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,
       0,   -53,   -18,   -53,   -18,   -18,   -18,   -53,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,
       0,   -18,   -18,   -18,   -18,     0,     0,     0,     0,     0,
       0,   -18,   -31,   -18,   -31,   -31,   -31,   -18,   -31,   -31,
     -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
       0,   -31,   -31,   -31,   -31,     0,     0,     0,     0,     0,
       0,   -31,   -52,   -31,   -52,   -52,   -52,   -31,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -49,   -52,   -49,   -49,   -49,   -52,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -43,   -49,   -43,   -43,   -43,   -49,   -43,   -43,
     -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,
       0,   -43,   -43,   -43,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -44,   -43,   -44,   -44,   -44,   -43,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,   -44,     0,     0,     0,     0,     0,
       0,   -44,   -45,   -44,   -45,   -45,   -45,   -44,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
       0,   -45,   -45,   -45,   -45,     0,     0,     0,     0,     0,
       0,   -45,   -46,   -45,   -46,   -46,   -46,   -45,   -46,   -46,
     -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -47,   -46,   -47,   -47,   -47,   -46,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,     0,
       0,   -47,   -48,   -47,   -48,   -48,   -48,   -47,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,   -48,     0,     0,     0,     0,     0,
       0,   -48,   -20,   -48,   -20,   -20,   -20,   -48,   -20,   -20,
     -20,   -20,   -20,     0,   -20,     0,   -20,   -20,   -20,   -20,
       0,   -20,   -20,   -20,   -20,     0,     0,     0,     0,     0,
       0,   -20,    25,   -20,    26,    27,    28,   -20,    29,    30,
      31,    32,    33,     0,    34,     0,    35,    36,    37,    38,
       0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,    43,   -30,    44,   -30,   -30,   -30,    45,   -30,   -30,
     -30,   -30,   -30,     0,   -30,     0,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -30,   -30,     0,     0,     0,     0,     0,
       0,   -30,   -21,   -30,   -21,   -21,   -21,   -30,   -21,   -21,
     -21,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,   -21,
       0,   -21,   -21,   -21,   -21,     0,     0,     0,     0,     0,
       0,   -21,   -19,   -21,   -19,   -19,   -19,   -21,   -19,   -19,
     -19,   -19,   -19,     0,   -19,     0,   -19,   -19,   -19,   -19,
       0,   -19,   -19,   -19,   -19,     0,     0,     0,     0,     0,
       0,   -19,   -22,   -19,   -22,   -22,   -22,   -19,   -22,   -22,
     -22,   -22,   -22,     0,   -22,     0,   -22,   -22,   -22,   -22,
       0,   -22,   -22,   -22,   -22,     0,     0,     0,     0,     0,
       0,   -22,   -27,   -22,   -27,   -27,   -27,   -22,   -27,   -27,
     -27,   -27,   -27,     0,   -27,     0,   -27,   -27,   -27,   -27,
       0,   -27,   -27,   -27,   -27,     0,     0,     0,     0,     0,
       0,   -27,   -28,   -27,   -28,   -28,   -28,   -27,   -28,   -28,
     -28,   -28,   -28,     0,   -28,     0,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   -28,     0,     0,     0,     0,     0,
       0,   -28,   -29,   -28,   -29,   -29,   -29,   -28,   -29,   -29,
     -29,   -29,   -29,     0,   -29,     0,   -29,   -29,   -29,   -29,
       0,   -29,   -29,   -29,   -29,     0,     0,     0,     0,     0,
       0,   -29,   -23,   -29,   -23,   -23,   -23,   -29,   -23,   -23,
     -23,   -23,   -23,     0,   -23,     0,   -23,   -23,   -23,   -23,
       0,   -23,   -23,   -23,   -23,     0,     0,     0,     0,     0,
       0,   -23,   -24,   -23,   -24,   -24,   -24,   -23,   -24,   -24,
     -24,   -24,   -24,     0,   -24,     0,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,   -24,     0,     0,     0,     0,     0,
       0,   -24,   -25,   -24,   -25,   -25,   -25,   -24,   -25,   -25,
     -25,   -25,   -25,     0,   -25,     0,   -25,   -25,   -25,   -25,
       0,   -25,   -25,   -25,   -25,     0,     0,     0,     0,     0,
       0,   -25,   -54,   -25,   -54,   -54,   -54,   -25,   -54,   -54,
     -54,   -54,   -54,     0,   -54,     0,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,
       0,   -54,   -26,   -54,   -26,   -26,   -26,   -54,   -26,   -26,
     -26,   -26,   -26,     0,   -26,     0,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -26,   -26,     0,     0,     0,     0,     0,
       0,   -26,   -32,   -26,   -32,   -32,   -32,   -26,   -32,   -32,
     -32,   -32,   -32,     0,   -32,     0,   -32,   -32,   -32,   -32,
       0,   -32,   -32,   -32,   -32,     0,     0,     0,     0,     0,
       0,   -32,   -53,   -32,   -53,   -53,   -53,   -32,   -53,   -53,
     -53,   -53,   -53,     0,   -53,     0,   -53,   -53,   -53,   -53,
       0,   -53,   -53,   -53,   -53,     0,     0,     0,     0,     0,
       0,   -53,   -31,   -53,   -31,   -31,   -31,   -53,   -31,   -31,
     -31,   -31,   -31,     0,   -31,     0,   -31,   -31,   -31,   -31,
       0,   -31,   -31,   -31,   -31,     0,     0,     0,     0,     0,
       0,   -31,   -52,   -31,   -52,   -52,   -52,   -31,   -52,   -52,
     -52,   -52,   -52,     0,   -52,     0,   -52,   -52,   -52,   -52,
       0,   -52,   -52,   -52,   -52,     0,     0,     0,     0,     0,
       0,   -52,   -49,   -52,   -49,   -49,   -49,   -52,   -49,   -49,
     -49,   -49,   -49,     0,   -49,     0,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,     0,     0,     0,     0,     0,
       0,   -49,   -43,   -49,   -43,   -43,   -43,   -49,   -43,   -43,
     -43,   -43,   -43,     0,   -43,     0,   -43,   -43,   -43,   -43,
       0,   -43,   -43,   -43,   -43,     0,     0,     0,     0,     0,
       0,   -43,   -44,   -43,   -44,   -44,   -44,   -43,   -44,   -44,
     -44,   -44,   -44,     0,   -44,     0,   -44,   -44,   -44,   -44,
       0,   -44,   -44,   -44,   -44,     0,     0,     0,     0,     0,
       0,   -44,   -45,   -44,   -45,   -45,   -45,   -44,   -45,   -45,
     -45,   -45,   -45,     0,   -45,     0,   -45,   -45,   -45,   -45,
       0,   -45,   -45,   -45,   -45,     0,     0,     0,     0,     0,
       0,   -45,   -46,   -45,   -46,   -46,   -46,   -45,   -46,   -46,
     -46,   -46,   -46,     0,   -46,     0,   -46,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -46,     0,     0,     0,     0,     0,
       0,   -46,   -47,   -46,   -47,   -47,   -47,   -46,   -47,   -47,
     -47,   -47,   -47,     0,   -47,     0,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,     0,
       0,   -47,   -48,   -47,   -48,   -48,   -48,   -47,   -48,   -48,
     -48,   -48,   -48,     0,   -48,     0,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,   -48,     0,     0,     0,     0,     0,
       0,   -48,   -51,   -48,   -51,   -51,   -51,   -48,   -51,   -51,
     -51,   -51,   -51,     0,   -51,     0,   -51,   -51,   -51,   -51,
       0,   -51,   -51,   -51,   -51,     0,     0,     0,     0,     0,
       0,   -51,    -9,   -51,    -9,    -9,    -9,   -51,    -9,    -9,
      -9,    -9,    -9,     0,    -9,     0,    -9,    -9,    -9,    -9,
       0,    -9,    -9,    -9,    -9,     0,     0,     0,     0,     0,
       0,    -9,   -16,    -9,   -16,   -16,   -16,    -9,   -16,   -16,
     -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,   -16,
       0,   -16,   -16,   -16,   -16,     0,     0,     0,     0,     0,
       0,   -16,   -17,   -16,   -17,   -17,   -17,   -16,   -17,   -17,
     -17,   -17,   -17,     0,   -17,     0,   -17,   -17,   -17,   -17,
       0,   -17,   -17,   -17,   -17,     0,     0,     0,     0,     0,
       0,   -17,    25,   -17,    26,    27,    28,   -17,    29,    30,
      31,    32,    33,     0,    34,     0,    35,    36,    37,    38,
       0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,    43,    25,    44,    26,    27,    28,   351,    29,    30,
      31,    32,    33,     0,    34,     0,    35,    36,    37,    38,
       0,    39,    40,    41,    42,     0,     0,     0,     0,     0,
       0,    43,   -18,    44,   -18,   -18,   -18,   353,   -18,   -18,
     -18,   -18,   -18,     0,   -18,     0,   -18,   -18,   -18,   -18,
       0,   -18,   -18,   -18,   -18,     0,     0,     0,     0,     0,
       0,   -18,   -50,   -18,   -50,   -50,   -50,   -18,   -50,   -50,
     -50,   -50,   -50,     0,   -50,     0,   -50,   -50,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,     0,     0,     0,     0,
       0,   -50,    25,   -50,    26,    27,    28,   -50,    29,    30,
      31,    32,    33,     0,    34,     0,    35,    36,    37,    38,
       0,    39,    40,    41,    42,     0,   -67,     0,     0,     0,
       0,    43,     0,    44,   -55,   -67,   229,   -67,     0,     0,
     -67,   -67,   -38,   -55,   -55,   -55,     0,   232,   -55,   -58,
       0,   239,   240,   241,     0,   -61,   -38,     0,   -58,   -58,
     -58,   -59,     0,   -58,   -61,   -61,   -61,   -56,     0,   -61,
     -59,   -59,   -59,   -57,     0,   -59,   -56,   -56,   -56,   -67,
       0,   -56,   -57,   -57,   -57,   -65,   -64,   -57,   -67,   -67,
     -67,     0,   -66,   -67,   -65,   -64,   -65,   -64,   -60,   -65,
     -64,   -66,   -37,   -66,     0,     0,   -66,   -60,   -58,   -60,
       0,   361,   -60,   362,   -61,   -59,   -37,   -58,     0,   -58,
       0,   -56,   -58,   -61,   -59,   -61,   -59,   -57,   -61,   -59,
     -56,   -67,   -56,     0,     0,   -56,   -57,   -55,   -57,     0,
     -67,   -57,   -67,   -60,     0,   -67,   -55,   -55,   -55,   -55,
      63,   279,   -60,   -60,   -60,   -60,   -62,   147,   148,     0,
     -63,     0,   149,   150,   -65,   -62,   -62,   -62,   -62,   -63,
     -63,   -63,   -63,   -65,   -65,   -65,   -65,   -64,   166,   167,
       0,   -66,     0,   168,   169,   -38,   -64,   -64,   -64,   -64,
     -66,   -66,   -66,   -66,    83,    84,    85,   -38,   -58,   184,
     185,     0,   -61,     0,   186,   187,   -60,   -58,   -58,   -58,
     -58,   -61,   -61,   -61,   -61,   -60,   -60,   -60,   -60,   -59,
       0,     0,     0,   -56,     0,     0,     0,   -57,   -59,   -59,
     -59,   -59,   -56,   -56,   -56,   -56,   -57,   -57,   -57,   -57,
     -67,     0,     0,     0,   -37,     0,     0,     0,   -62,   -67,
     -67,   -67,   -67,   207,   -63,   208,   -37,   -62,   -65,   -62,
     -62,     0,   -64,   -63,     0,   -63,   -63,   -65,   -66,   -65,
     -65,   -64,   -60,   -64,   -64,     0,   -58,   -66,     0,   -66,
     -66,   -60,   -61,   -60,   -60,   -58,   -56,   -58,   -58,     0,
     -57,   -61,     0,   -61,   -61,   -56,   -59,   -56,   -56,   -57,
     -67,   -57,   -57,     0,   -64,   -59,     0,   -59,   -59,   -67,
     -66,   -67,   -67,   -64,   -64,   -64,   -60,     0,     0,   -66,
     -66,   -66,   -38,     0,     0,   -60,   -60,   -60,   -58,     0,
       0,   259,   260,   261,   -61,     0,     0,   -58,   -58,   -58,
     -59,     0,     0,   -61,   -61,   -61,   -56,     0,     0,   -59,
     -59,   -59,   -57,     0,     0,   -56,   -56,   -56,   -67,     0,
       0,   -57,   -57,   -57,   -65,   -64,     0,   -67,   -67,   -67,
     -66,   -60,     0,   -65,   -64,   -65,   -64,   -37,   -58,   -66,
     -60,   -66,   -60,   -61,   -59,     0,   379,   -58,   380,   -58,
     -56,   -57,   -61,   -59,   -61,   -59,   -67,     0,     0,   -56,
     -57,   -56,   -57,     0,     0,   -67,     0,   -67
};

static const yytype_int16 yycheck[] =
{
       0,    23,    82,    18,     4,   113,   114,   113,   232,   113,
       9,   113,    34,   113,    19,   113,    10,   113,   242,     6,
     114,     6,    44,    10,     0,    10,    31,     6,   252,    19,
     138,    10,     0,   113,    33,    19,    19,    32,    25,   263,
      25,    63,    64,    33,   138,     6,    25,    31,    70,    10,
      33,    73,    74,    10,    76,    33,    19,     9,    80,    10,
      82,    83,    84,    85,    25,     1,    19,     3,     4,     5,
      33,     7,     8,     9,    10,    11,    12,    13,    31,    15,
      16,    17,    18,   217,    20,    21,    22,    23,    19,   111,
      19,   113,   114,    35,    30,   229,    32,    31,    32,   114,
      36,    19,    33,    34,    33,    34,    19,     3,     4,     5,
      19,     7,     8,   113,    10,    33,   138,    19,    10,    19,
      33,    17,    18,   138,    33,    34,    22,    23,    33,    34,
     152,    33,    34,    33,    30,   359,    32,    33,    19,    19,
      19,     3,     4,     5,   368,     7,     8,    19,    10,   171,
      19,    31,    33,   377,    33,    17,    18,     0,    19,    31,
      22,    23,    33,    34,    33,    34,     9,   189,    30,    31,
      32,    19,    33,   195,     3,     4,     5,    19,     7,     8,
     202,    10,    19,    31,   206,   207,   208,    32,    17,    18,
     212,    33,    34,    22,    23,    31,    33,    34,    32,   279,
      32,    30,    23,    32,     3,     4,     5,    19,     7,     8,
     232,    10,    19,    34,   236,    33,    34,   239,   240,   241,
     242,    33,    34,    44,   246,    19,    33,   249,   250,   251,
     252,    17,    18,    32,   256,    19,    22,    23,   260,    33,
      34,   263,    63,    64,    28,    29,    30,   269,    32,    33,
      34,   273,   274,   275,   276,    19,    19,   279,   280,    80,
      32,    82,    83,    84,    85,    28,    29,    30,    10,    33,
      33,    34,   294,    32,   382,   383,   382,   383,   382,   383,
     382,   383,   382,   383,   382,   383,   382,   383,   382,   383,
     111,   313,   113,   114,     3,     4,     5,    19,     7,     8,
      19,    10,   382,   383,    19,    19,    19,    32,    17,    18,
     332,    33,    31,    22,    23,    32,    19,   138,    33,    33,
      33,    30,    31,    32,    19,     3,     4,     5,    31,     7,
       8,   152,    10,    28,    29,    30,    32,   359,    33,   361,
     362,    32,    19,    33,    33,    19,   368,    19,   370,   371,
     171,    28,    29,    30,    32,   377,    33,   379,   380,    33,
     382,   383,    19,    33,    19,     3,     4,     5,   189,     7,
       8,    28,    10,    30,   195,    32,    33,    34,    33,    33,
      33,   202,   382,   383,    19,   206,   207,   208,     3,     4,
       5,   212,     7,     8,    32,    10,    31,     3,     4,     5,
      33,     7,     8,    23,    10,     3,     4,     5,    19,     7,
       8,   232,    10,    32,    34,    33,    33,    32,   239,   240,
     241,   242,    33,    19,    44,    33,    32,    19,   249,   250,
     251,   252,    33,    33,    32,    19,    19,    33,   259,   260,
     261,    33,   263,    63,    64,    28,    29,    30,   269,    33,
      33,    34,    19,    19,    31,   276,    31,    19,   279,   280,
      80,    31,    82,    83,    84,    85,    33,    33,     1,    31,
       3,     4,     5,   294,     7,     8,     9,    10,    11,    12,
      13,    19,    15,    16,    17,    18,    31,    20,    21,    22,
      23,   111,   313,   113,   114,    33,    19,    30,    33,    32,
       3,     4,     5,    36,     7,     8,    31,    10,     0,     1,
      33,   332,    19,    31,    17,    18,    31,     9,   138,    22,
      23,    28,    19,    30,    32,    32,    33,    30,    19,    32,
      32,    28,   152,    30,    19,    19,    33,    34,   359,    19,
     361,   362,    33,    28,    29,    30,    19,   368,    33,   370,
     371,   171,    19,    33,    19,    32,   377,    23,   379,   380,
      33,   382,   383,    28,    29,    30,    33,    32,    34,   189,
      19,    19,    32,    32,    32,   195,    32,    43,    44,    28,
      29,    30,   202,    31,    33,    34,   206,   207,   208,     3,
       4,     5,   212,     7,     8,    19,    10,    63,    64,     3,
       4,     5,    32,     7,     8,    32,    10,    32,    10,    33,
      19,    19,   232,    32,    80,    32,    82,     0,    32,   239,
     240,   241,   242,    23,    33,    33,     9,    19,    32,   249,
     250,   251,   252,    32,    34,    32,    28,    29,    30,    19,
     260,    33,    34,   263,    44,   111,    19,   113,   114,   269,
      32,    31,     0,    32,    19,    31,   276,    19,    31,   279,
     280,     9,    19,    63,    64,    27,    28,    29,    30,    31,
      32,    28,   138,    30,   294,    19,    33,    34,    33,    33,
      80,    19,    82,    33,    84,   151,   152,    31,    19,    19,
      28,    29,    30,   313,    33,    33,    34,    28,    29,    30,
      33,     0,    33,    34,   170,   171,    19,    33,    33,     0,
       9,   111,   332,   113,   114,    28,    29,    30,     9,    19,
      33,    34,   188,   189,    33,    33,    19,    33,    28,   195,
      30,    33,    33,    33,    34,    28,   202,    30,   138,   359,
     206,   361,   362,    33,    19,    33,   212,     0,   368,    19,
     370,   371,   152,    28,    29,    30,     9,   377,    33,   379,
     380,    19,   382,   383,    19,     0,   232,    23,    19,    31,
      19,   171,    31,    28,     9,    30,   242,    32,    34,    28,
      29,    30,    19,    31,    33,    34,   252,    31,    44,   189,
      19,    28,    29,    30,    33,   195,    33,   263,    31,    28,
      29,    30,   202,   269,    33,    34,   206,    63,    64,    31,
     276,    31,   212,   279,   280,    33,     3,     4,     5,    33,
       7,     8,   111,    10,    80,     0,    82,     4,   294,    -1,
      17,    18,   232,    -1,     9,    22,    23,    19,    -1,    -1,
     240,    -1,   242,    30,    -1,    32,    28,   313,    30,    -1,
     250,    33,   252,    -1,    -1,   111,    19,   113,   114,    -1,
     260,    -1,    -1,   263,    44,    28,   332,    30,    -1,   269,
      33,    34,    -1,    -1,    -1,    -1,   276,    19,    -1,   279,
     280,    -1,   138,    63,    64,    -1,    28,    29,    30,    69,
      19,    71,    72,   359,   294,    75,   152,    -1,    19,    28,
      29,    30,   368,    -1,    33,    34,    -1,    28,    29,    30,
      19,   377,    33,   313,    -1,   171,   382,   383,    -1,    28,
      29,    30,     3,     4,     5,    -1,     7,     8,    -1,    10,
      -1,   111,   332,   189,    -1,    -1,    17,    18,    -1,   195,
      -1,    22,    23,    19,    -1,    -1,   202,    -1,    -1,    30,
     206,    32,    28,    29,    30,    -1,   212,    33,    34,   359,
       3,     4,     5,    -1,     7,     8,    -1,    10,   368,    -1,
      -1,    -1,   152,    -1,    17,    18,   232,   377,    -1,    22,
      23,    -1,   382,   383,    19,    -1,   242,    30,    -1,    32,
      -1,   171,    19,    28,    29,    30,   252,    19,    33,    34,
      27,    28,    29,    30,    31,    19,    28,   263,    30,   189,
      -1,    33,    34,   269,    28,   195,    30,    -1,    -1,    33,
     276,    -1,   202,   279,   280,    -1,   206,     1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,   294,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,   232,   233,   234,   235,    30,   313,    32,    -1,
      19,    35,   242,   243,   244,   245,    -1,    -1,    -1,    28,
      19,    30,   252,   253,   254,   255,   332,    19,    -1,    28,
      29,    30,    19,   263,    33,    34,    28,    29,    30,   269,
      19,    28,   272,    30,    -1,    -1,    33,    34,    -1,    28,
      -1,    30,    19,   359,    33,    34,    -1,    -1,    -1,    19,
      -1,    28,   368,    30,   294,    -1,    33,    34,    28,    -1,
      30,   377,    -1,    33,    34,    -1,   382,   383,     1,    -1,
       3,     4,     5,   313,     7,     8,     9,    10,    11,    12,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    19,   332,    -1,    -1,    -1,    -1,    30,    19,    32,
      28,    -1,    30,    36,    -1,    33,    34,    28,    -1,    30,
      -1,    19,    33,    34,    -1,    -1,    -1,    -1,    19,   359,
      28,    -1,    30,    -1,    -1,    33,    34,    28,   368,    30,
      31,    32,     1,    -1,     3,     4,     5,   377,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    30,     1,    32,     3,     4,     5,    36,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    -1,    19,    -1,    -1,    -1,
      -1,    30,    -1,    32,    19,    28,    35,    30,    -1,    -1,
      33,    34,    19,    28,    29,    30,    -1,    32,    33,    19,
      -1,    28,    29,    30,    -1,    19,    33,    -1,    28,    29,
      30,    19,    -1,    33,    28,    29,    30,    19,    -1,    33,
      28,    29,    30,    19,    -1,    33,    28,    29,    30,    19,
      -1,    33,    28,    29,    30,    19,    19,    33,    28,    29,
      30,    -1,    19,    33,    28,    28,    30,    30,    19,    33,
      33,    28,    19,    30,    -1,    -1,    33,    28,    19,    30,
      -1,    28,    33,    30,    19,    19,    33,    28,    -1,    30,
      -1,    19,    33,    28,    28,    30,    30,    19,    33,    33,
      28,    19,    30,    -1,    -1,    33,    28,    19,    30,    -1,
      28,    33,    30,    19,    -1,    33,    28,    29,    30,    31,
      32,    27,    28,    29,    30,    31,    19,    17,    18,    -1,
      19,    -1,    22,    23,    19,    28,    29,    30,    31,    28,
      29,    30,    31,    28,    29,    30,    31,    19,    17,    18,
      -1,    19,    -1,    22,    23,    19,    28,    29,    30,    31,
      28,    29,    30,    31,    28,    29,    30,    31,    19,    17,
      18,    -1,    19,    -1,    22,    23,    19,    28,    29,    30,
      31,    28,    29,    30,    31,    28,    29,    30,    31,    19,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    19,    28,    29,
      30,    31,    28,    29,    30,    31,    28,    29,    30,    31,
      19,    -1,    -1,    -1,    19,    -1,    -1,    -1,    19,    28,
      29,    30,    31,    28,    19,    30,    31,    28,    19,    30,
      31,    -1,    19,    28,    -1,    30,    31,    28,    19,    30,
      31,    28,    19,    30,    31,    -1,    19,    28,    -1,    30,
      31,    28,    19,    30,    31,    28,    19,    30,    31,    -1,
      19,    28,    -1,    30,    31,    28,    19,    30,    31,    28,
      19,    30,    31,    -1,    19,    28,    -1,    30,    31,    28,
      19,    30,    31,    28,    29,    30,    19,    -1,    -1,    28,
      29,    30,    19,    -1,    -1,    28,    29,    30,    19,    -1,
      -1,    28,    29,    30,    19,    -1,    -1,    28,    29,    30,
      19,    -1,    -1,    28,    29,    30,    19,    -1,    -1,    28,
      29,    30,    19,    -1,    -1,    28,    29,    30,    19,    -1,
      -1,    28,    29,    30,    19,    19,    -1,    28,    29,    30,
      19,    19,    -1,    28,    28,    30,    30,    19,    19,    28,
      28,    30,    30,    19,    19,    -1,    28,    28,    30,    30,
      19,    19,    28,    28,    30,    30,    19,    -1,    -1,    28,
      28,    30,    30,    -1,    -1,    28,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    38,    39,    40,    41,    10,     0,    40,
      41,    31,    42,    32,     9,    43,    44,    10,    33,    34,
      35,    46,     9,    47,    10,     1,     3,     4,     5,     7,
       8,     9,    10,    11,    13,    15,    16,    17,    18,    20,
      21,    22,    23,    30,    32,    36,    40,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    10,    32,    32,    31,    50,    51,    59,    32,
      32,    32,    32,    32,    32,    32,    32,    50,    51,    31,
      19,    31,    27,    28,    29,    30,    51,    63,    64,    51,
      31,    51,    52,    10,    59,    52,    52,     6,    25,    59,
       6,    25,    59,    52,    59,    33,    51,    49,    61,    60,
      61,    34,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    64,    45,    46,    48,
      45,    31,    31,    31,    31,    31,    31,    31,    12,    45,
      10,     3,     4,     5,     7,     8,    10,    17,    18,    22,
      23,    30,    32,    50,    52,    59,    60,    61,    62,    31,
       3,     4,     5,     7,     8,    10,    17,    18,    22,    23,
      30,    32,    50,    52,    59,    60,    61,    62,     3,     4,
       5,     7,     8,    10,    17,    18,    22,    23,    30,    32,
      50,    59,    60,    61,    62,    19,     3,     4,     5,     7,
       8,    10,    32,    59,    61,    62,    19,    28,    30,     1,
       9,    11,    13,    15,    16,    20,    21,    35,    40,    49,
      50,    51,    53,    54,    55,    56,    57,    58,    59,    35,
      46,    48,    32,    32,    32,    32,    32,    50,    51,    28,
      29,    30,    32,    32,    32,    32,    32,    50,    51,    28,
      29,    30,    32,    32,    32,    32,    32,    50,    51,    28,
      29,    30,    51,    32,    51,    51,    61,    61,    10,    32,
      31,    51,    32,    32,    32,    32,    47,    31,    31,    27,
      47,    63,    52,    52,    52,    59,    33,    61,     3,     4,
       5,     7,     8,    10,    32,    59,    60,    61,    62,    61,
      63,    52,    52,    52,    59,    33,    61,     3,     4,     5,
       7,     8,    10,    32,    59,    60,    61,    62,    61,    63,
      52,    52,    52,    59,    33,    61,     3,     4,     5,     7,
       8,    10,    32,    59,    60,    61,    62,    61,    63,    33,
      31,    51,    31,    52,    59,     6,    25,    59,     6,    25,
      59,    36,    49,    36,    33,    33,    33,    33,    33,    32,
      51,    28,    30,    33,    33,    33,    33,    33,    32,    51,
      28,    30,    33,    33,    33,    33,    33,    32,    51,    28,
      30,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    63,    33,    61,    61,    63,    33,    61,    61,    63,
      33,    61,    61,    45,    45,    31,    31,    31,    31,    31,
      31,    31,    33,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    39,    39,    40,
      42,    41,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    52,    53,    53,    53,    54,    54,    54,    55,
      56,    56,    57,    58,    58,    59,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    63,    63,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     0,     3,
       0,     7,     1,     0,     4,     2,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     2,     4,     4,     4,     4,     3,     1,     2,
       1,     1,     3,     5,     5,     5,     5,     5,     5,     5,
       5,     7,     5,     3,     2,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     0,
       3,     1
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
#line 89 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
    }
#line 2117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 96 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 99 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 102 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 108 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
    }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 114 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), "variable");
    }
#line 2172 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 121 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "function");
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2181 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 125 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2190 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 132 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2198 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 141 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2215 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 145 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 151 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2232 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 154 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("COMPOUND_STATEMENT", (yyvsp[-1].node), NULL , NULL, NULL);
    }
#line 2248 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 166 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2256 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2264 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 175 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2272 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 178 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2280 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 181 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2288 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 184 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2296 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 187 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 190 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2312 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 193 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2320 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 196 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2328 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 199 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2336 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 202 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
        yyerrok;
    }
#line 2345 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 209 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2353 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 212 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2361 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 218 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2369 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 221 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2377 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 224 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 227 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2393 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 233 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 236 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2409 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 239 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2417 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 242 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 245 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2441 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 260 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2457 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 263 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2465 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 269 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 275 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 281 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2497 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 287 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 290 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 297 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 303 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 306 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 312 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2546 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 318 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 321 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 324 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 330 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 333 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 336 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 339 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 342 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 345 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 348 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 351 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 357 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 363 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 366 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 372 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2666 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 375 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2674 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2678 "parser.tab.c" /* yacc.c:1646  */
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
#line 380 "parser.y" /* yacc.c:1906  */


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
void add_symbol(char* name, char* type, char* symbol_type) {
    symbol_node *s;
    scope* scope = get_stack_head();
    char *key = concat_string(name, scope->scope_name);
    s = create_symbol(key, name, type, symbol_type, scope->scope_name);
    HASH_ADD_STR(symbol_table, key, s);
}

// cria símbolo para table
symbol_node* create_symbol(char* key, char *name, char* type, char* symbol_type, char* scope_name){
    symbol_node *s = (symbol_node *)malloc(sizeof *s);
    s->key = key;
    s->name = name;
    s->type = type;
    s->symbol_type = symbol_type;
    s->scope_name = scope_name;
    s->param_list = NULL;

    if(strcmp(symbol_type, "parameter") == 0){
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
node* create_tree_node(char* class, node* left, node* right, char* type, char* value){
    node* aux_node = (node*)calloc(1, sizeof(node));

    aux_node->class = class;
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
        if(strcmp(s->symbol_type, "parameter") !=0 ){
            printf("key: %s | name: %s | type: %s | symbol_type: %s | scope: %s |\n", s->key, s->name, s->type, s->symbol_type, s->scope_name);
            if(strcmp(s->symbol_type, "function") == 0){
                for(p=s->param_list; p != NULL; p=p->next) {
                    HASH_FIND_STR(symbol_table, p->key, ps);
                    if(ps != NULL){
                        for(number_of_space = 36; number_of_space > 0; number_of_space--){
                            printf(" ");
                        }
                        printf("| param_name: %s | type: %s | symbol_type: %s | scope: %s |\n", ps->name, ps->type, ps->symbol_type, ps->scope_name);
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
        printf(" Class: %s, ", tree->class);
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

// função de concatenar para criar chave da tabela
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
    }
    else {
        yyin = stdin;
    }
    printf("----------  ANALISADOR LÉXICO ----------\n\n");
    init_scope_global();
    yyparse();
    print_symbol_table();
    if (total_errors == 0) {    
    printf("\n\n----------  AST ----------\n\n");
        print_parser_tree(parser_tree, 0);
        free_parser_tree(parser_tree);
    }
    printf("Total de Erros: %d\n", total_errors);
    free_symbol_table();
    fclose(yyin);
    yylex_destroy();
}
