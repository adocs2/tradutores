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


#line 136 "parser.tab.c" /* yacc.c:339  */

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
#line 72 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 212 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 229 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   3363

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  419

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
       0,    92,    92,    95,    99,   102,   105,   108,   111,   117,
     124,   124,   135,   138,   144,   148,   154,   157,   163,   170,
     173,   179,   182,   188,   191,   194,   197,   200,   203,   206,
     209,   212,   215,   222,   225,   231,   234,   237,   240,   246,
     249,   252,   255,   258,   264,   270,   273,   276,   282,   285,
     288,   294,   300,   303,   310,   316,   319,   325,   331,   334,
     337,   343,   346,   349,   352,   355,   358,   361,   364,   370,
     376,   379,   385,   388
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
  "compound-inline", "compound-stmt", "local_declaration", "stmt-list",
  "stmt", "expr", "set-func", "simple-expr", "in-stmt", "write-stmt",
  "writeln-stmt", "read-stmt", "conditional-stmt", "iteration-stmt",
  "return-stmt", "var", "op-expr", "term", "call", "args", "arg-list", YY_NULLPTR
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

#define YYPACT_NINF -230

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-230)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     457,    22,    17,    42,   527,   660,   677,    16,  -230,   682,
     685,   742,    49,    -1,    76,    55,   360,   426,    58,   110,
     530,   743,    91,  2006,   496,   117,  2036,  2066,   118,  2096,
     619,  3097,  3110,  3114,  3118,  1184,   102,   405,   122,   134,
     142,   171,   181,   198,   203,   209,   844,   597,   767,  2126,
    2156,  2186,    -7,    45,   145,  2216,  2246,  2276,  2306,  2336,
    2366,   594,  3131,  3135,  3139,   103,   597,  2396,   179,   212,
    3152,   658,   201,   658,   658,     3,    20,   658,   201,   290,
      18,  2426,   908,  2456,  1065,    92,   135,    92,     1,   213,
     215,    24,  2486,   245,    35,   244,   260,    72,    84,   280,
     283,   291,   315,   318,   345,    90,   363,  3156,   301,  2516,
    3160,  1314,  3173,  1150,  3177,  3026,  3059,   390,   330,   419,
     452,   454,   472,   478,   488,   501,   492,   567,   400,    62,
     359,   692,  2546,  2576,  2606,  2636,  2666,  2696,  2726,  2756,
    3059,  2786,  2816,  1205,   312,   539,  1004,  1061,  1073,   795,
     445,   494,   517,   522,   905,   597,   111,   127,  1080,  1093,
    1146,  1159,   369,   697,   704,   720,   760,   413,   524,   529,
     555,   556,   927,   597,   160,   162,   787,   803,   823,   835,
     975,  3241,  3247,  3253,  3259,   815,   571,   585,   596,   601,
    3113,   597,   558,  3265,  3271,  3277,  3283,   597,  3181,  3191,
    3195,  3199,  3205,  1131,   597,  3209,  3213,  3219,  1150,   135,
     135,  1255,   621,   602,   490,   625,   626,   627,   640,   530,
    1293,  1346,   577,   578,  1376,  1406,  1436,  1466,  1496,  1526,
    3093,   530,  2846,  2876,   103,   658,   658,   658,   201,   158,
     221,   148,   165,   148,   103,   658,   658,   658,   201,   187,
     223,   182,   197,   182,   103,   658,   658,   658,   201,   620,
     248,   258,   307,   258,   272,   103,   285,   190,  3223,  3227,
     643,   597,  1556,   599,   658,   201,   106,   112,  2006,  1586,
    1616,  1065,  2006,   645,   303,   354,   367,   646,  1165,  1172,
     241,   324,   752,  1114,  1220,  1099,   597,  1262,  1302,  3065,
    3069,  1213,   651,   373,   392,   397,   659,   854,   862,   300,
     446,   471,   551,   607,   129,   597,   728,   875,   929,   937,
     913,   673,   398,   407,   415,   678,  3289,  3295,    25,   716,
    1077,  1318,  3089,   780,   597,  3313,  3314,  3319,  3320,  3301,
     686,  3233,  1646,   436,  1676,   437,   696,   707,   708,   731,
     735,   736,   737,  2906,  1706,  2936,  1298,   459,   463,   483,
     491,   103,   495,   165,   165,   963,   200,   219,   225,   371,
     103,   545,   197,   197,  3307,   754,   773,   778,   779,   103,
     557,   307,   307,  3237,  3026,  3026,   769,   772,   774,   776,
     804,   807,   809,  1736,  2966,   771,  3073,  3077,  3081,   785,
     981,   994,  1021,   793,  3326,  3327,  3332,  2996,  1766,  1796,
    1826,  1856,  1886,  1916,  1946,  1976,  3085,  1029,  3333
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
       0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -230,  -230,  -230,     0,   837,  -230,  -230,  -230,   -78,   -12,
    -212,   277,   -99,   -82,   605,   870,   973,  -112,  -105,  -101,
     -97,   -86,   -84,   -26,   764,   210,   402,  -229,   745
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    49,     6,    12,    15,    16,   129,   130,
      23,    27,    50,    51,   192,    93,    54,    55,    56,    57,
      58,    59,    60,   193,   194,   195,   196,    89,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    61,   109,   224,     9,   283,    21,   278,    14,    99,
     225,    70,   -42,    95,   226,   302,   131,   233,   227,   282,
     208,   158,    -3,    26,    81,   321,   102,     7,   100,   228,
      95,   229,   -13,   221,   -73,   113,   340,   197,   132,   176,
     158,   233,     8,   197,   -64,   103,    96,    11,   -10,   101,
     104,   107,   106,   -64,   -43,   -64,    70,   115,    61,    70,
     205,    70,   141,   -52,    82,   -52,   -52,   -52,   116,   -52,
     -52,   -52,   -52,   -52,   140,   -52,    83,   -52,   -52,   -52,
     -52,    13,   -52,   -52,   -52,   -52,    17,   176,    18,   230,
      61,   -43,   -52,    20,   -52,    30,    31,    32,   -52,    33,
      34,    24,   143,   -43,   232,   118,   162,   163,   164,   -43,
     165,   166,   347,   167,    61,   220,    95,   119,   350,    22,
     168,   169,    95,   126,    47,   170,   171,    28,   232,   158,
     -42,   348,   395,   172,    66,   173,   -71,   351,   198,   199,
     200,   399,   201,   202,   -42,   203,   -43,   158,   -57,   142,
     403,   144,   145,   146,    71,   147,   148,   -57,   149,   -57,
     -43,   370,   -57,   -57,   -43,   158,    72,   204,   290,   291,
     292,   158,   293,   294,    73,   295,   -43,   -41,   158,   -42,
     155,   -43,   176,   205,   205,   162,   163,   164,    70,   165,
     166,   -41,   167,   -42,   -42,   -43,   -43,   296,   -42,   354,
     309,   310,   311,    74,   312,   313,   -41,   314,   176,   208,
     -42,    95,   287,    75,   173,   158,   297,   158,   176,   -35,
     -41,   -41,   306,   -44,   -44,   176,   316,   176,   176,   315,
      76,    82,   325,   -35,   -35,    77,   335,    63,   -36,   176,
     197,    78,   197,    92,   -37,   158,   114,    63,   -70,   346,
     349,   352,   -36,   -36,   288,   230,   307,   160,   -37,   -37,
     -64,   180,   181,   182,   197,   183,   184,   197,   185,   -64,
     158,   -64,   224,   224,   -64,   178,   160,   -57,    26,   225,
     225,   326,    26,   226,   226,   131,   131,   227,   227,   158,
     191,   197,    63,   117,    63,   110,   206,   112,   228,   228,
     229,   229,   221,   221,   197,   -44,   407,   408,   158,   -41,
     328,   329,   330,   120,   331,   332,   121,   333,   341,   -64,
      82,   -41,   -43,   178,   122,    63,    63,    61,   -64,    61,
     -64,   -64,   -44,   -64,   -64,   176,   357,   297,   297,   334,
     -64,   -64,   -64,   -65,   176,   -64,   316,   316,   123,   -35,
      63,   124,   -65,   176,   -65,   335,   335,   -65,   230,   230,
     -16,   -35,   -16,   -16,   -16,   160,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,   -43,   -16,   -16,   -16,   -16,   125,   -16,
     -16,   -16,   -16,   160,   220,   220,   -43,   358,   -64,   -16,
     -38,   -16,   -43,   -12,    19,   -16,   127,   -64,   -64,   -64,
     359,   160,   -64,   -64,   -38,   -38,   366,   160,    30,    31,
      32,   -43,    33,    34,   160,   143,   -43,   -43,   178,   268,
     269,   133,    40,    41,    63,   367,   -43,    44,    45,    64,
     368,   375,   -57,   -72,   -43,    46,    67,    47,   -36,    64,
     376,   -57,   -57,   -57,   178,   244,   -57,   -57,   377,   161,
     -36,   289,   299,   301,   178,   197,   -43,    -8,     1,   -15,
     -15,   308,   318,   320,   178,   -65,     2,   179,   161,   384,
     385,   327,   337,   339,   -65,   178,   -65,   235,   -35,   -65,
     -65,   160,   -36,   134,    64,   135,    64,    64,   207,    64,
     -67,    63,   -35,    30,    31,    32,   -36,    33,    34,   -67,
     143,   -67,   -37,   136,   -67,   -67,   160,    40,    41,   137,
     -38,   -37,    44,    45,   197,   179,   -37,    64,    64,   138,
      46,   272,    47,   -37,   -38,   160,   236,    -2,   396,   -14,
     -14,   -20,   139,   -20,   -20,   -20,     2,   -20,   -20,   -20,
     -20,   -20,    64,   -20,   160,   -20,   -20,   -20,   -20,   237,
     -20,   -20,   -20,   -20,   238,   353,   245,   161,   -65,   355,
     -20,   246,   -20,    63,   197,    63,   -20,   -65,   -65,   -65,
     -66,   178,   -65,   397,   398,   161,   197,   -42,   400,   -66,
     178,   -66,   401,   402,   -66,   -66,   -38,   247,   248,   178,
     404,   405,   406,   161,    63,    63,   -42,    82,   -38,   161,
     144,   145,   146,   255,   147,   148,   161,   149,   279,   280,
     179,   207,   207,   -62,   150,   151,    64,   256,    82,   152,
     153,    84,   -62,   -62,   -62,   -62,   -68,   154,   257,   155,
     344,   270,    52,   258,   271,   -68,   179,   -68,   -64,   -41,
     -68,   -68,    68,   161,   300,   161,   179,   -64,   -64,   -64,
     -64,    79,   156,   179,   319,   179,   179,   274,   275,   276,
      -5,   180,   181,   182,   338,   183,   184,   179,   185,    -5,
     174,   156,   277,   161,   342,   186,   187,    -7,   356,   360,
     188,   189,    -4,    64,   365,    -6,    -7,    68,   190,    68,
     191,    -4,   369,   -17,    -6,   -17,   -17,   -17,   161,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   374,   -17,   -17,   -17,
     -17,   378,   -17,   -17,   -17,   -17,   -65,   161,   174,   383,
     222,    52,   -17,   -67,   -17,   -65,   -65,   -65,   -17,   386,
     -65,   -65,   -67,   -67,   -67,   -65,   161,   -67,   -67,   -66,
     387,   388,    -9,   -11,   -65,    52,   -65,   -62,   -66,   -66,
     -66,    -9,   -11,   -66,   -66,    64,   -62,    64,   -62,   239,
     156,   -62,   -62,   179,   389,   300,   300,   -18,   390,   391,
     392,   -67,   179,   -35,   319,   319,   -18,   249,   156,   -68,
     -67,   179,   -67,   338,   338,   -67,    64,    64,   -68,   -68,
     -68,    62,   -36,   -68,   -68,   259,   156,   -37,   -38,   -57,
     409,    62,   156,   410,   416,   411,   -62,   412,   -57,   156,
     -57,   159,   379,   174,   -57,   -62,   -62,   -62,   417,    68,
     -62,   -62,   -40,   -57,   -57,   -57,   418,   234,   -57,   177,
     159,   251,   252,   253,   -57,   413,   -40,   -40,   414,   174,
     415,    10,   -60,   -57,   -57,   -57,    62,   254,    62,   174,
     111,   -60,   -60,   -60,   -63,     0,   -60,   -60,   128,   174,
       0,    40,    41,   -63,   -63,   -63,    44,    45,   -63,   -63,
     174,     0,     0,   -61,     0,     0,   156,   177,     0,    62,
      62,   -58,   -61,   -61,   -61,     0,    68,   -61,   -61,     0,
     -58,   -58,   -58,     0,   -39,   -58,   -58,    53,     0,     0,
       0,   156,     0,   372,    62,   373,     0,    69,   -39,   -39,
       0,    30,    31,    32,     0,    33,    34,    80,   143,   159,
     156,     0,   150,   151,     0,    40,    41,   152,   153,     0,
      44,    45,   -59,     0,     0,    88,    91,   159,    46,   156,
      47,   -59,   -59,   -59,   168,   169,   -59,   -59,   -60,   170,
     171,     0,   108,     0,    53,   159,   -63,   -60,    52,   -60,
      52,   159,   -60,   -60,     0,   -63,   174,   -63,   159,     0,
     -63,   -63,   177,     0,     0,   174,     0,     0,    62,     0,
       0,     0,   -69,    88,   174,   223,    53,     0,     0,   222,
     222,   -69,   -69,   -69,   -64,     0,   -69,   -69,   177,     0,
     -61,     0,     0,   -64,   -64,   -64,   298,     0,   177,   -61,
      53,   -61,     0,   -58,   -61,   -61,   317,     0,   177,     0,
     157,     0,   -58,   -67,   -58,   240,   336,   -58,   -58,   177,
       0,     0,   -67,   -67,   -67,   159,     0,   -67,   175,   157,
     -59,     0,     0,   250,    94,    62,    97,    98,   -69,   -59,
     105,   -59,     0,     0,   -59,   -59,     0,   -69,     0,   -69,
     159,   260,   -69,   -69,     0,     0,     0,   264,    30,    31,
      32,     0,    33,    34,   266,    35,     0,     0,   267,   159,
     -66,     0,    40,    41,   273,     0,   175,    44,    45,   -66,
     -66,   -66,   -68,     0,   -66,    46,   -67,    47,   159,   -62,
       0,   -68,   -68,   -68,    88,   -67,   -68,   -67,   -62,   -62,
     -62,     0,   -40,   -62,    88,     0,     0,    62,   -57,    62,
       0,   241,   242,   243,    88,   177,   -40,   -57,   157,   -57,
       0,   361,   -57,   -66,   177,    88,     0,     0,     0,     0,
       0,   343,   -66,   177,   -66,     0,   157,   -66,    62,    62,
     -57,   223,     0,   162,   163,   164,     0,   165,   166,   -57,
     167,   -57,   -57,   265,   157,   -60,   362,   168,   169,     0,
     157,     0,   170,   171,   -60,   -60,   -60,   157,   -63,   -60,
     172,   175,   173,     0,   -61,   371,     0,   -63,   -63,   -63,
       0,   -58,   -63,   -61,   -61,   -61,     0,     0,   -61,     0,
     -58,   -58,   -58,   -57,   380,   -58,     0,   175,   284,   285,
     286,   -57,   -57,   -57,   -57,   -57,    65,   175,   303,   304,
     305,     0,     0,    53,   -57,    53,     0,   175,   322,   323,
     324,    88,   -59,   -57,   -57,   -57,   -57,    65,   175,   -68,
      88,   -59,   -59,   -59,   157,     0,   -59,   345,   -68,    88,
     -68,     0,     0,   -68,   223,   223,   -32,     0,   -32,   -32,
     -32,     0,   -32,   -32,   -32,   -32,   -32,   -32,   -32,   157,
     -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,     0,
       0,   -62,     0,     0,     0,   -32,     0,   -32,   157,     0,
     -62,   -32,   -62,     0,   -23,   -62,   -23,   -23,   -23,     0,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,   157,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,   -69,     0,     0,
       0,   -39,     0,   -23,     0,   -23,   -69,   -69,   -69,   -23,
     363,   -69,   364,   -39,   175,   -39,     0,   -66,     0,     0,
       0,     0,   209,   175,   210,   -39,   -66,   -24,   -66,   -24,
     -24,   -24,   175,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
       0,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,
       0,     0,     0,     0,     0,     0,   -24,   -29,   -24,   -29,
     -29,   -29,   -24,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
       0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,
       0,     0,     0,     0,     0,     0,   -29,   -30,   -29,   -30,
     -30,   -30,   -29,   -30,   -30,   -30,   -30,   -30,   -30,   -30,
       0,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,
       0,     0,     0,     0,     0,     0,   -30,   -31,   -30,   -31,
     -31,   -31,   -30,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
       0,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
       0,     0,     0,     0,     0,     0,   -31,   -25,   -31,   -25,
     -25,   -25,   -31,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
       0,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,
       0,     0,     0,     0,     0,     0,   -25,   -26,   -25,   -26,
     -26,   -26,   -25,   -26,   -26,   -26,   -26,   -26,   -26,   -26,
       0,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
       0,     0,     0,     0,     0,     0,   -26,   -27,   -26,   -27,
     -27,   -27,   -26,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
       0,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
       0,     0,     0,     0,     0,     0,   -27,   -56,   -27,   -56,
     -56,   -56,   -27,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
       0,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
       0,     0,     0,     0,     0,     0,   -56,   -28,   -56,   -28,
     -28,   -28,   -56,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
       0,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,
       0,     0,     0,     0,     0,     0,   -28,   -34,   -28,   -34,
     -34,   -34,   -28,   -34,   -34,   -34,   -34,   -34,   -34,   -34,
       0,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,
       0,     0,     0,     0,     0,     0,   -34,    -9,   -34,    -9,
      -9,    -9,   -34,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
       0,    -9,    -9,    -9,    -9,     0,    -9,    -9,    -9,    -9,
       0,     0,     0,     0,     0,     0,    -9,   -55,    -9,   -55,
     -55,   -55,    -9,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,   -55,   -33,   -55,   -33,
     -33,   -33,   -55,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
       0,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,
       0,     0,     0,     0,     0,     0,   -33,   -18,   -33,   -18,
     -18,   -18,   -33,   -18,   -18,   -18,   -18,   -18,   -18,   -18,
       0,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,
       0,     0,     0,     0,     0,     0,   -18,   -54,   -18,   -54,
     -54,   -54,   -18,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
       0,   -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -51,   -54,   -51,
     -51,   -51,   -54,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
       0,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,
       0,     0,     0,     0,     0,     0,   -51,   -45,   -51,   -45,
     -45,   -45,   -51,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
       0,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -46,   -45,   -46,
     -46,   -46,   -45,   -46,   -46,   -46,   -46,   -46,   -46,   -46,
       0,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,
       0,     0,     0,     0,     0,     0,   -46,   -47,   -46,   -47,
     -47,   -47,   -46,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
       0,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -48,   -47,   -48,
     -48,   -48,   -47,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
       0,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,
       0,     0,     0,     0,     0,     0,   -48,   -49,   -48,   -49,
     -49,   -49,   -48,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
       0,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -50,   -49,   -50,
     -50,   -50,   -49,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
       0,   -50,   -50,   -50,   -50,     0,   -50,   -50,   -50,   -50,
       0,     0,     0,     0,     0,     0,   -50,   -22,   -50,   -22,
     -22,   -22,   -50,   -22,   -22,    25,   -22,   -22,     0,   -22,
       0,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
       0,     0,     0,     0,     0,     0,   -22,   -19,   -22,   -19,
     -19,   -19,   -22,   -19,   -19,   -19,   -19,   -19,     0,   -19,
       0,   -19,   -19,   -19,   -19,     0,   -19,   -19,   -19,   -19,
       0,     0,     0,     0,     0,     0,   -19,    29,   -19,    30,
      31,    32,   -19,    33,    34,    25,    35,    36,     0,    37,
       0,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,     0,     0,     0,     0,     0,    46,   -32,    47,   -32,
     -32,   -32,    48,   -32,   -32,   -32,   -32,   -32,     0,   -32,
       0,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,
       0,     0,     0,     0,     0,     0,   -32,   -23,   -32,   -23,
     -23,   -23,   -32,   -23,   -23,   -23,   -23,   -23,     0,   -23,
       0,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,
       0,     0,     0,     0,     0,     0,   -23,   -21,   -23,   -21,
     -21,   -21,   -23,   -21,   -21,   -21,   -21,   -21,     0,   -21,
       0,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,
       0,     0,     0,     0,     0,     0,   -21,   -24,   -21,   -24,
     -24,   -24,   -21,   -24,   -24,   -24,   -24,   -24,     0,   -24,
       0,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,
       0,     0,     0,     0,     0,     0,   -24,   -29,   -24,   -29,
     -29,   -29,   -24,   -29,   -29,   -29,   -29,   -29,     0,   -29,
       0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,
       0,     0,     0,     0,     0,     0,   -29,   -30,   -29,   -30,
     -30,   -30,   -29,   -30,   -30,   -30,   -30,   -30,     0,   -30,
       0,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,
       0,     0,     0,     0,     0,     0,   -30,   -31,   -30,   -31,
     -31,   -31,   -30,   -31,   -31,   -31,   -31,   -31,     0,   -31,
       0,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,
       0,     0,     0,     0,     0,     0,   -31,   -25,   -31,   -25,
     -25,   -25,   -31,   -25,   -25,   -25,   -25,   -25,     0,   -25,
       0,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,
       0,     0,     0,     0,     0,     0,   -25,   -26,   -25,   -26,
     -26,   -26,   -25,   -26,   -26,   -26,   -26,   -26,     0,   -26,
       0,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
       0,     0,     0,     0,     0,     0,   -26,   -27,   -26,   -27,
     -27,   -27,   -26,   -27,   -27,   -27,   -27,   -27,     0,   -27,
       0,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
       0,     0,     0,     0,     0,     0,   -27,   -56,   -27,   -56,
     -56,   -56,   -27,   -56,   -56,   -56,   -56,   -56,     0,   -56,
       0,   -56,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
       0,     0,     0,     0,     0,     0,   -56,   -28,   -56,   -28,
     -28,   -28,   -56,   -28,   -28,   -28,   -28,   -28,     0,   -28,
       0,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,
       0,     0,     0,     0,     0,     0,   -28,   -34,   -28,   -34,
     -34,   -34,   -28,   -34,   -34,   -34,   -34,   -34,     0,   -34,
       0,   -34,   -34,   -34,   -34,     0,   -34,   -34,   -34,   -34,
       0,     0,     0,     0,     0,     0,   -34,   -55,   -34,   -55,
     -55,   -55,   -34,   -55,   -55,   -55,   -55,   -55,     0,   -55,
       0,   -55,   -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,
       0,     0,     0,     0,     0,     0,   -55,   -33,   -55,   -33,
     -33,   -33,   -55,   -33,   -33,   -33,   -33,   -33,     0,   -33,
       0,   -33,   -33,   -33,   -33,     0,   -33,   -33,   -33,   -33,
       0,     0,     0,     0,     0,     0,   -33,   -54,   -33,   -54,
     -54,   -54,   -33,   -54,   -54,   -54,   -54,   -54,     0,   -54,
       0,   -54,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,
       0,     0,     0,     0,     0,     0,   -54,   -51,   -54,   -51,
     -51,   -51,   -54,   -51,   -51,   -51,   -51,   -51,     0,   -51,
       0,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,
       0,     0,     0,     0,     0,     0,   -51,   -45,   -51,   -45,
     -45,   -45,   -51,   -45,   -45,   -45,   -45,   -45,     0,   -45,
       0,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,
       0,     0,     0,     0,     0,     0,   -45,   -46,   -45,   -46,
     -46,   -46,   -45,   -46,   -46,   -46,   -46,   -46,     0,   -46,
       0,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,
       0,     0,     0,     0,     0,     0,   -46,   -47,   -46,   -47,
     -47,   -47,   -46,   -47,   -47,   -47,   -47,   -47,     0,   -47,
       0,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,
       0,     0,     0,     0,     0,     0,   -47,   -48,   -47,   -48,
     -48,   -48,   -47,   -48,   -48,   -48,   -48,   -48,     0,   -48,
       0,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,
       0,     0,     0,     0,     0,     0,   -48,   -49,   -48,   -49,
     -49,   -49,   -48,   -49,   -49,   -49,   -49,   -49,     0,   -49,
       0,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
       0,     0,     0,     0,     0,     0,   -49,   -50,   -49,   -50,
     -50,   -50,   -49,   -50,   -50,   -50,   -50,   -50,     0,   -50,
       0,   -50,   -50,   -50,   -50,     0,   -50,   -50,   -50,   -50,
       0,     0,     0,     0,     0,     0,   -50,   -53,   -50,   -53,
     -53,   -53,   -50,   -53,   -53,   -53,   -53,   -53,     0,   -53,
       0,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,
       0,     0,     0,     0,     0,     0,   -53,    -9,   -53,    -9,
      -9,    -9,   -53,    -9,    -9,    -9,    -9,    -9,     0,    -9,
       0,    -9,    -9,    -9,    -9,     0,    -9,    -9,    -9,    -9,
       0,     0,     0,     0,     0,     0,    -9,   -16,    -9,   -16,
     -16,   -16,    -9,   -16,   -16,   -16,   -16,   -16,     0,   -16,
       0,   -16,   -16,   -16,   -16,     0,   -16,   -16,   -16,   -16,
       0,     0,     0,     0,     0,     0,   -16,   -17,   -16,   -17,
     -17,   -17,   -16,   -17,   -17,   -17,   -17,   -17,     0,   -17,
       0,   -17,   -17,   -17,   -17,     0,   -17,   -17,   -17,   -17,
       0,     0,     0,     0,     0,     0,   -17,    29,   -17,    30,
      31,    32,   -17,    33,    34,    25,    35,    36,     0,    37,
       0,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,     0,     0,     0,     0,     0,    46,    29,    47,    30,
      31,    32,   393,    33,    34,    25,    35,    36,     0,    37,
       0,    38,    39,    40,    41,     0,    42,    43,    44,    45,
       0,     0,     0,     0,     0,     0,    46,   -18,    47,   -18,
     -18,   -18,   394,   -18,   -18,   -18,   -18,   -18,     0,   -18,
       0,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,
       0,     0,     0,     0,     0,     0,   -18,   -52,   -18,   -52,
     -52,   -52,   -18,   -52,   -52,   -52,   -52,   -52,     0,   -52,
       0,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,
       0,     0,     0,     0,     0,     0,   -52,   211,   -52,    30,
      31,    32,   -52,    33,    34,   212,    35,   213,     0,   214,
       0,   215,   216,    40,    41,     0,   217,   218,    44,    45,
       0,     0,     0,     0,     0,     0,    46,     0,    47,     0,
      29,   219,    30,    31,    32,     0,    33,    34,    25,    35,
      36,     0,    37,     0,    38,    39,    40,    41,     0,    42,
      43,    44,    45,     0,   -60,     0,     0,     0,   -63,    46,
       0,    47,   -61,   -60,   231,   -60,   -58,   -63,   -60,   -63,
     -59,   -61,   -63,   -61,   -69,   -58,   -61,   -58,   -68,   -59,
     -58,   -59,   -62,   -69,   -59,   -69,   -65,   -68,   -69,   -68,
     281,   -62,   -62,   -62,   -62,   -65,   -65,   -65,   -65,   -67,
     186,   187,     0,   -66,     0,   188,   189,   -68,   -67,   -67,
     -67,   -67,   -66,   -66,   -66,   -66,   -68,   -68,   -68,   -68,
     -40,     0,     0,     0,   -60,     0,     0,     0,   -63,    85,
      86,    87,   -40,   -60,   -60,   -60,   -60,   -63,   -63,   -63,
     -63,   -62,     0,     0,     0,   -61,     0,     0,     0,   -58,
     -62,   -62,   -62,   -62,   -61,   -61,   -61,   -61,   -58,   -58,
     -58,   -58,   -59,     0,     0,     0,   -69,     0,     0,     0,
     -64,   -59,   -59,   -59,   -59,   -69,   -69,   -69,   -69,   -64,
     -65,   -64,   -64,     0,   -67,     0,     0,     0,   -66,   -65,
       0,   -65,   -65,   -67,   -68,   -67,   -67,   -66,   -62,   -66,
     -66,     0,   -60,   -68,     0,   -68,   -68,   -62,   -63,   -62,
     -62,   -60,   -58,   -60,   -60,     0,   -59,   -63,     0,   -63,
     -63,   -58,   -61,   -58,   -58,   -59,   -69,   -59,   -59,     0,
     -65,   -61,     0,   -61,   -61,   -69,   -67,   -69,   -69,   -65,
     -65,   -65,   -66,     0,     0,   -67,   -67,   -67,   -68,     0,
       0,   -66,   -66,   -66,   -62,     0,     0,   -68,   -68,   -68,
     -40,     0,     0,   -62,   -62,   -62,   -60,     0,     0,   261,
     262,   263,   -63,     0,     0,   -60,   -60,   -60,   -61,     0,
       0,   -63,   -63,   -63,   -58,     0,     0,   -61,   -61,   -61,
     -59,     0,     0,   -58,   -58,   -58,   -69,     0,     0,   -59,
     -59,   -59,   -62,   -39,     0,   -69,   -69,   -69,   -60,   -63,
       0,   -62,   381,   -62,   382,   -61,   -58,   -60,   -63,   -60,
     -63,   -59,   -69,     0,   -61,   -58,   -61,   -58,     0,     0,
     -59,   -69,   -59,   -69
};

static const yytype_int16 yycheck[] =
{
       0,    27,    84,   115,     4,   234,    18,   219,     9,     6,
     115,    37,    19,    10,   115,   244,   115,   116,   115,   231,
      19,    47,     0,    23,    31,   254,     6,    10,    25,   115,
      10,   115,    33,   115,    33,    34,   265,    19,   116,    65,
      66,   140,     0,    19,    19,    25,    72,    31,    32,    75,
      76,    33,    78,    28,    19,    30,    82,    33,    84,    85,
      86,    87,   140,     1,    19,     3,     4,     5,    33,     7,
       8,     9,    10,    11,    12,    13,    31,    15,    16,    17,
      18,    32,    20,    21,    22,    23,    10,   113,    33,   115,
     116,    19,    30,    35,    32,     3,     4,     5,    36,     7,
       8,    10,    10,    19,   116,    33,     3,     4,     5,    19,
       7,     8,     6,    10,   140,   115,    10,    33,     6,     9,
      17,    18,    10,    33,    32,    22,    23,    10,   140,   155,
      19,    25,   361,    30,    32,    32,    33,    25,     3,     4,
       5,   370,     7,     8,    33,    10,    19,   173,    19,    31,
     379,     3,     4,     5,    32,     7,     8,    28,    10,    30,
      33,    32,    33,    34,    19,   191,    32,    32,     3,     4,
       5,   197,     7,     8,    32,    10,    31,    19,   204,    19,
      32,    19,   208,   209,   210,     3,     4,     5,   214,     7,
       8,    33,    10,    33,    34,    33,    34,    32,    19,   281,
       3,     4,     5,    32,     7,     8,    19,    10,   234,    19,
      31,    10,   238,    32,    32,   241,   242,   243,   244,    19,
      33,    34,   248,    33,    34,   251,   252,   253,   254,    32,
      32,    19,   258,    33,    34,    32,   262,    27,    19,   265,
      19,    32,    19,    31,    19,   271,    33,    37,    33,   275,
     276,   277,    33,    34,    33,   281,    33,    47,    33,    34,
      19,     3,     4,     5,    19,     7,     8,    19,    10,    28,
     296,    30,   384,   385,    33,    65,    66,    33,   278,   384,
     385,    33,   282,   384,   385,   384,   385,   384,   385,   315,
      32,    19,    82,    33,    84,    85,    86,    87,   384,   385,
     384,   385,   384,   385,    19,    33,   384,   385,   334,    19,
       3,     4,     5,    33,     7,     8,    33,    10,    33,    19,
      19,    31,    19,   113,    33,   115,   116,   353,    28,   355,
      30,    19,    31,    33,    34,   361,    33,   363,   364,    32,
      28,    29,    30,    19,   370,    33,   372,   373,    33,    19,
     140,    33,    28,   379,    30,   381,   382,    33,   384,   385,
       1,    31,     3,     4,     5,   155,     7,     8,     9,    10,
      11,    12,    13,    19,    15,    16,    17,    18,    33,    20,
      21,    22,    23,   173,   384,   385,    19,    33,    19,    30,
      19,    32,    19,    33,    34,    36,    33,    28,    29,    30,
      33,   191,    33,    34,    33,    34,    33,   197,     3,     4,
       5,    19,     7,     8,   204,    10,    19,    19,   208,   209,
     210,    31,    17,    18,   214,    33,    19,    22,    23,    27,
      33,    33,    19,    33,    19,    30,    31,    32,    19,    37,
      33,    28,    29,    30,   234,    32,    33,    34,    33,    47,
      31,   241,   242,   243,   244,    19,    19,     0,     1,    33,
      34,   251,   252,   253,   254,    19,     9,    65,    66,    33,
      33,   261,   262,   263,    28,   265,    30,    32,    19,    33,
      34,   271,    19,    31,    82,    31,    84,    85,    86,    87,
      19,   281,    33,     3,     4,     5,    33,     7,     8,    28,
      10,    30,    19,    31,    33,    34,   296,    17,    18,    31,
      19,    19,    22,    23,    19,   113,    33,   115,   116,    31,
      30,    31,    32,    31,    33,   315,    32,     0,    33,    33,
      34,     1,    31,     3,     4,     5,     9,     7,     8,     9,
      10,    11,   140,    13,   334,    15,    16,    17,    18,    32,
      20,    21,    22,    23,    32,   278,    32,   155,    19,   282,
      30,    32,    32,   353,    19,   355,    36,    28,    29,    30,
      19,   361,    33,   363,   364,   173,    19,    19,    33,    28,
     370,    30,   372,   373,    33,    34,    19,    32,    32,   379,
      33,   381,   382,   191,   384,   385,    19,    19,    31,   197,
       3,     4,     5,    32,     7,     8,   204,    10,    31,    31,
     208,   209,   210,    19,    17,    18,   214,    32,    19,    22,
      23,    27,    28,    29,    30,    31,    19,    30,    32,    32,
      31,    10,    27,    32,    32,    28,   234,    30,    19,    19,
      33,    34,    37,   241,   242,   243,   244,    28,    29,    30,
      31,    46,    47,   251,   252,   253,   254,    32,    32,    32,
       0,     3,     4,     5,   262,     7,     8,   265,    10,     9,
      65,    66,    32,   271,    31,    17,    18,     0,    33,    33,
      22,    23,     0,   281,    33,     0,     9,    82,    30,    84,
      32,     9,    33,     1,     9,     3,     4,     5,   296,     7,
       8,     9,    10,    11,    12,    13,    33,    15,    16,    17,
      18,    33,    20,    21,    22,    23,    19,   315,   113,    33,
     115,   116,    30,    19,    32,    28,    29,    30,    36,    33,
      33,    34,    28,    29,    30,    19,   334,    33,    34,    19,
      33,    33,     0,     0,    28,   140,    30,    19,    28,    29,
      30,     9,     9,    33,    34,   353,    28,   355,    30,   154,
     155,    33,    34,   361,    33,   363,   364,     0,    33,    33,
      33,    19,   370,    19,   372,   373,     9,   172,   173,    19,
      28,   379,    30,   381,   382,    33,   384,   385,    28,    29,
      30,    27,    19,    33,    34,   190,   191,    19,    19,    19,
      31,    37,   197,    31,    33,    31,    19,    31,    28,   204,
      30,    47,    32,   208,    19,    28,    29,    30,    33,   214,
      33,    34,    19,    28,    29,    30,    33,    32,    33,    65,
      66,    28,    29,    30,    19,    31,    33,    34,    31,   234,
      31,     4,    19,    28,    29,    30,    82,    32,    84,   244,
      86,    28,    29,    30,    19,    -1,    33,    34,   113,   254,
      -1,    17,    18,    28,    29,    30,    22,    23,    33,    34,
     265,    -1,    -1,    19,    -1,    -1,   271,   113,    -1,   115,
     116,    19,    28,    29,    30,    -1,   281,    33,    34,    -1,
      28,    29,    30,    -1,    19,    33,    34,    27,    -1,    -1,
      -1,   296,    -1,    28,   140,    30,    -1,    37,    33,    34,
      -1,     3,     4,     5,    -1,     7,     8,    47,    10,   155,
     315,    -1,    17,    18,    -1,    17,    18,    22,    23,    -1,
      22,    23,    19,    -1,    -1,    65,    66,   173,    30,   334,
      32,    28,    29,    30,    17,    18,    33,    34,    19,    22,
      23,    -1,    82,    -1,    84,   191,    19,    28,   353,    30,
     355,   197,    33,    34,    -1,    28,   361,    30,   204,    -1,
      33,    34,   208,    -1,    -1,   370,    -1,    -1,   214,    -1,
      -1,    -1,    19,   113,   379,   115,   116,    -1,    -1,   384,
     385,    28,    29,    30,    19,    -1,    33,    34,   234,    -1,
      19,    -1,    -1,    28,    29,    30,   242,    -1,   244,    28,
     140,    30,    -1,    19,    33,    34,   252,    -1,   254,    -1,
      47,    -1,    28,    19,    30,   155,   262,    33,    34,   265,
      -1,    -1,    28,    29,    30,   271,    -1,    33,    65,    66,
      19,    -1,    -1,   173,    71,   281,    73,    74,    19,    28,
      77,    30,    -1,    -1,    33,    34,    -1,    28,    -1,    30,
     296,   191,    33,    34,    -1,    -1,    -1,   197,     3,     4,
       5,    -1,     7,     8,   204,    10,    -1,    -1,   208,   315,
      19,    -1,    17,    18,   214,    -1,   113,    22,    23,    28,
      29,    30,    19,    -1,    33,    30,    19,    32,   334,    19,
      -1,    28,    29,    30,   234,    28,    33,    30,    28,    29,
      30,    -1,    19,    33,   244,    -1,    -1,   353,    19,   355,
      -1,    28,    29,    30,   254,   361,    33,    28,   155,    30,
      -1,    32,    33,    19,   370,   265,    -1,    -1,    -1,    -1,
      -1,   271,    28,   379,    30,    -1,   173,    33,   384,   385,
      19,   281,    -1,     3,     4,     5,    -1,     7,     8,    28,
      10,    30,    31,    32,   191,    19,   296,    17,    18,    -1,
     197,    -1,    22,    23,    28,    29,    30,   204,    19,    33,
      30,   208,    32,    -1,    19,   315,    -1,    28,    29,    30,
      -1,    19,    33,    28,    29,    30,    -1,    -1,    33,    -1,
      28,    29,    30,    19,   334,    33,    -1,   234,   235,   236,
     237,    27,    28,    29,    30,    31,    32,   244,   245,   246,
     247,    -1,    -1,   353,    19,   355,    -1,   254,   255,   256,
     257,   361,    19,    28,    29,    30,    31,    32,   265,    19,
     370,    28,    29,    30,   271,    -1,    33,   274,    28,   379,
      30,    -1,    -1,    33,   384,   385,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,   296,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    -1,
      -1,    19,    -1,    -1,    -1,    30,    -1,    32,   315,    -1,
      28,    36,    30,    -1,     1,    33,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,   334,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    19,    -1,    -1,
      -1,    19,    -1,    30,    -1,    32,    28,    29,    30,    36,
      28,    33,    30,    19,   361,    33,    -1,    19,    -1,    -1,
      -1,    -1,    28,   370,    30,    31,    28,     1,    30,     3,
       4,     5,   379,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    12,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     1,    32,     3,
       4,     5,    36,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    32,    -1,
       1,    35,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    -1,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    19,    -1,    -1,    -1,    19,    30,
      -1,    32,    19,    28,    35,    30,    19,    28,    33,    30,
      19,    28,    33,    30,    19,    28,    33,    30,    19,    28,
      33,    30,    19,    28,    33,    30,    19,    28,    33,    30,
      27,    28,    29,    30,    31,    28,    29,    30,    31,    19,
      17,    18,    -1,    19,    -1,    22,    23,    19,    28,    29,
      30,    31,    28,    29,    30,    31,    28,    29,    30,    31,
      19,    -1,    -1,    -1,    19,    -1,    -1,    -1,    19,    28,
      29,    30,    31,    28,    29,    30,    31,    28,    29,    30,
      31,    19,    -1,    -1,    -1,    19,    -1,    -1,    -1,    19,
      28,    29,    30,    31,    28,    29,    30,    31,    28,    29,
      30,    31,    19,    -1,    -1,    -1,    19,    -1,    -1,    -1,
      19,    28,    29,    30,    31,    28,    29,    30,    31,    28,
      19,    30,    31,    -1,    19,    -1,    -1,    -1,    19,    28,
      -1,    30,    31,    28,    19,    30,    31,    28,    19,    30,
      31,    -1,    19,    28,    -1,    30,    31,    28,    19,    30,
      31,    28,    19,    30,    31,    -1,    19,    28,    -1,    30,
      31,    28,    19,    30,    31,    28,    19,    30,    31,    -1,
      19,    28,    -1,    30,    31,    28,    19,    30,    31,    28,
      29,    30,    19,    -1,    -1,    28,    29,    30,    19,    -1,
      -1,    28,    29,    30,    19,    -1,    -1,    28,    29,    30,
      19,    -1,    -1,    28,    29,    30,    19,    -1,    -1,    28,
      29,    30,    19,    -1,    -1,    28,    29,    30,    19,    -1,
      -1,    28,    29,    30,    19,    -1,    -1,    28,    29,    30,
      19,    -1,    -1,    28,    29,    30,    19,    -1,    -1,    28,
      29,    30,    19,    19,    -1,    28,    29,    30,    19,    19,
      -1,    28,    28,    30,    30,    19,    19,    28,    28,    30,
      30,    19,    19,    -1,    28,    28,    30,    30,    -1,    -1,
      28,    28,    30,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    38,    39,    40,    41,    10,     0,    40,
      41,    31,    42,    32,     9,    43,    44,    10,    33,    34,
      35,    46,     9,    47,    10,     9,    40,    48,    10,     1,
       3,     4,     5,     7,     8,    10,    11,    13,    15,    16,
      17,    18,    20,    21,    22,    23,    30,    32,    36,    40,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    32,    32,    31,    51,    52,
      60,    32,    32,    32,    32,    32,    32,    32,    32,    51,
      52,    31,    19,    31,    27,    28,    29,    30,    52,    64,
      65,    52,    31,    52,    53,    10,    60,    53,    53,     6,
      25,    60,     6,    25,    60,    53,    60,    33,    52,    50,
      62,    61,    62,    34,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    65,    45,
      46,    49,    45,    31,    31,    31,    31,    31,    31,    31,
      12,    45,    31,    10,     3,     4,     5,     7,     8,    10,
      17,    18,    22,    23,    30,    32,    51,    53,    60,    61,
      62,    63,     3,     4,     5,     7,     8,    10,    17,    18,
      22,    23,    30,    32,    51,    53,    60,    61,    62,    63,
       3,     4,     5,     7,     8,    10,    17,    18,    22,    23,
      30,    32,    51,    60,    61,    62,    63,    19,     3,     4,
       5,     7,     8,    10,    32,    60,    62,    63,    19,    28,
      30,     1,     9,    11,    13,    15,    16,    20,    21,    35,
      40,    50,    51,    52,    54,    55,    56,    57,    58,    59,
      60,    35,    46,    49,    32,    32,    32,    32,    32,    51,
      52,    28,    29,    30,    32,    32,    32,    32,    32,    51,
      52,    28,    29,    30,    32,    32,    32,    32,    32,    51,
      52,    28,    29,    30,    52,    32,    52,    52,    62,    62,
      10,    32,    31,    52,    32,    32,    32,    32,    47,    31,
      31,    27,    47,    64,    53,    53,    53,    60,    33,    62,
       3,     4,     5,     7,     8,    10,    32,    60,    61,    62,
      63,    62,    64,    53,    53,    53,    60,    33,    62,     3,
       4,     5,     7,     8,    10,    32,    60,    61,    62,    63,
      62,    64,    53,    53,    53,    60,    33,    62,     3,     4,
       5,     7,     8,    10,    32,    60,    61,    62,    63,    62,
      64,    33,    31,    52,    31,    53,    60,     6,    25,    60,
       6,    25,    60,    48,    50,    48,    33,    33,    33,    33,
      33,    32,    52,    28,    30,    33,    33,    33,    33,    33,
      32,    52,    28,    30,    33,    33,    33,    33,    33,    32,
      52,    28,    30,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    36,    36,    64,    33,    62,    62,    64,
      33,    62,    62,    64,    33,    62,    62,    45,    45,    31,
      31,    31,    31,    31,    31,    31,    33,    33,    33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    39,    39,    40,
      42,    41,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    58,    59,    59,    60,    61,    61,
      61,    62,    62,    62,    62,    62,    62,    62,    62,    63,
      64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     0,     3,
       0,     7,     1,     0,     4,     2,     1,     1,     4,     2,
       0,     2,     0,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     2,     4,     4,     4,     4,     3,
       1,     2,     1,     1,     3,     5,     5,     5,     5,     5,
       5,     5,     5,     7,     5,     3,     2,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     0,     3,     1
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
#line 92 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
    }
#line 2130 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 95 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 99 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 102 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 105 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2160 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2168 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 111 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
    }
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), "variable");
    }
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 124 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "function");
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 128 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 135 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 138 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2219 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 144 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 148 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2237 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 157 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2253 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("COMPOUND_STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 2261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 170 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOCAL_DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 173 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2277 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 179 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2285 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 188 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2301 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 191 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 194 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2317 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 197 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 203 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2349 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2357 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2365 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 215 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
        yyerrok;
    }
#line 2374 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 222 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2382 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2398 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2406 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 237 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 246 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 252 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2446 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 264 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 270 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 273 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 276 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 282 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 285 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 288 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 300 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 303 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 310 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2551 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 316 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2559 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 319 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 325 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2575 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 331 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 334 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 337 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 343 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2607 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 346 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 349 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 352 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 355 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 358 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 361 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 364 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 370 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 376 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 379 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 385 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 388 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2703 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2707 "parser.tab.c" /* yacc.c:1646  */
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
#line 393 "parser.y" /* yacc.c:1906  */


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
