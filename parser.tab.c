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
#define YYLAST   2537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  381

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
     178,   181,   184,   187,   190,   193,   196,   199,   205,   208,
     214,   217,   220,   223,   229,   232,   235,   238,   244,   250,
     253,   256,   262,   265,   268,   274,   280,   283,   290,   294,
     300,   303,   309,   315,   318,   321,   327,   330,   333,   336,
     339,   342,   345,   348,   351,   354,   360,   366,   369,   375,
     378,   384,   387,   393,   396
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
  "set-func", "simple-expr", "in-stmt", "write-stmt", "writeln-stmt",
  "read-stmt", "conditional-stmt", "iteration-stmt", "return-stmt", "var",
  "op-expr", "term", "call", "args", "arg-list", "char", "string", YY_NULLPTR
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

#define YYPACT_NINF -214

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-214)))

#define YYTABLE_NINF -75

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,    41,    54,   142,     2,    13,    20,    62,  -214,    45,
      82,    87,    63,     3,    97,    99,   177,   201,   114,   159,
     515,   141,   169,  1211,   261,   172,  1299,  1464,   167,  1005,
    2443,  2447,  2451,  2455,  1016,   199,   801,   219,   229,   264,
     266,   276,   278,   283,   289,   331,   624,   145,  1497,  1530,
     295,   313,  1563,  1596,  1629,  1662,  1695,  1728,  2434,  2459,
    2463,  2467,  1063,   131,   107,   624,  1761,   325,   330,  2471,
    1077,   319,  1077,  1077,    11,    11,  1077,   319,   339,   354,
    1794,  1827,   957,   441,   767,   441,  1183,   208,   303,   357,
     372,   385,  1860,   402,   409,   411,   418,   423,   435,   459,
     -24,    17,   461,   146,    19,   465,   470,  2475,  1893,  2479,
     384,  2483,   334,  2487,   493,   624,  1332,   404,   474,   499,
     509,   536,   540,   548,   561,   564,   586,   588,   544,  1365,
     556,  1926,  1959,  1992,  2025,  2058,  2091,  2124,  2157,  2190,
     599,  2223,  1398,  2438,  1237,  1246,  1252,  1258,  1264,   449,
     401,   591,   595,   605,   490,   624,   607,  2327,  2333,  2339,
    2345,   864,    40,   837,   919,   965,   974,   984,   664,   613,
     617,   630,   634,   713,   624,   314,   994,  1043,  1083,  1093,
     158,    -1,   374,   400,   455,   460,   471,   363,   637,   641,
     643,   677,   798,   624,   647,   482,   535,   546,   558,   271,
     255,   568,   909,   929,  1160,  1231,   217,   624,  1241,  1268,
    2491,  2351,   188,   173,    27,   767,   767,   515,   515,   107,
    1077,  1077,  1077,   319,   679,   680,    70,   678,    70,   883,
     239,   107,  1077,  1077,  1077,   319,   342,   695,   248,   432,
     248,   808,    33,   107,  1077,  1077,  1077,   319,   700,   701,
     718,   895,   718,   299,   259,   107,   707,  2357,   196,  2495,
    2499,  1211,  1211,   710,   722,   729,   737,   746,  2361,  2367,
     761,   818,  2387,  2391,  2395,  2371,   624,  2399,  2403,  2407,
    2411,   688,    77,  2377,   747,   750,   751,   763,   768,  1102,
    1109,   230,   526,   939,  1025,  1133,   848,   624,  1142,  1151,
    1159,  1167,    94,    57,  1116,   771,   781,   793,   795,   806,
     574,   585,    52,    89,   351,   616,   631,   391,   624,   635,
     644,   648,   675,   433,   286,   592,   807,  2503,  2256,  2289,
    2383,   810,   823,   824,   827,   107,   829,   678,   678,   730,
     200,  1126,   366,   398,   550,   573,   107,   840,   432,   432,
     819,   140,   596,   715,   780,   859,   869,   107,   851,   895,
     895,   522,   352,  2507,  1431,  2322,   858,  2415,  2419,  2423,
     862,  1174,  1216,  1223,   865,   687,   731,   762,  2427,  1230,
     783
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
       0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,   170,   902,  -214,  -214,  -214,  -100,    86,
    -106,  -214,   825,   822,   -12,   -69,  -214,  -214,  -214,  -214,
    -214,  -214,   -27,   954,   157,   702,  -213,   804,   341,   525
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    26,     6,    12,    15,    16,    21,    23,
      27,    48,    49,   194,    93,    94,    52,    53,    54,    55,
      56,    57,   195,   196,   197,   198,    89,    90,   199,   200
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,   213,    -2,    97,    98,   242,   263,   105,   121,    69,
     132,     2,    14,    -5,   129,    51,   131,   -74,   284,   157,
      -7,    95,    -5,   214,    68,   214,   -59,   -59,   -59,    -7,
     305,   -59,   -59,   -73,    79,   -12,   -72,   176,   157,   -73,
     141,    -3,   326,   -72,    96,    -4,   230,    99,   102,   122,
     106,   125,    88,    91,    -4,    58,    69,   208,    69,   -73,
     -73,   -73,   -73,   351,     7,   -73,   -73,   -59,   -59,   -59,
      51,   -61,   -59,   144,   145,   146,   -74,   147,   148,   -61,
     149,   -61,    -6,   340,   -59,   176,   -59,    -8,   157,   -59,
     -59,    -6,    11,    -9,    13,   -72,    -8,   -72,   -72,   -72,
      88,   155,   -72,   130,   -59,    58,   -59,    17,   -62,   -59,
     163,   164,   165,   -74,   166,   167,   -62,   168,   -62,   350,
      51,   -60,   366,   -60,   169,   170,   -60,   -60,   157,   171,
     172,    18,   -72,   370,   -72,   -72,   173,    87,   174,   -68,
     -72,   -10,     8,   225,   374,   -15,   -73,   157,    20,     1,
     -10,   264,   265,   266,   -15,   328,   329,     2,   -59,   -59,
     -59,   -59,   237,   285,   286,   287,   157,   -73,    22,   -73,
       5,   213,   -73,   -73,     9,   306,   307,   308,   124,    24,
     157,   249,    28,   241,    60,   -60,   -60,   -60,   208,   208,
     -60,   -60,   176,    60,   258,   256,   267,   142,   -71,   157,
     277,   157,   -73,   159,   176,   -71,   -73,    88,   288,   -11,
      19,   176,   298,   176,   -73,   -59,   176,   -59,   -59,    88,
     309,   178,   159,   -73,   319,   -73,   -73,   -73,   176,   -73,
      65,    88,   -73,   -14,   -14,   -73,   -73,   -73,   -73,    60,
     109,   209,   111,    88,   -52,   -73,   -52,   -52,   255,   157,
      70,   163,   164,   165,   -74,   166,   167,   -61,   168,   -61,
      71,   254,   -61,   -61,   336,   -73,   -73,   -73,   -73,   178,
     157,   -73,   159,   -72,   -59,   -72,   -72,   -72,   -73,   174,
     -72,   -72,   -59,   -59,   -59,   347,   -73,   -73,   -73,    60,
     -60,   157,   362,   -13,   -13,    72,   253,    73,   -60,   -60,
     -60,    58,    58,   261,   262,   -59,   358,    74,   176,    75,
     277,   277,   159,   -59,    76,   -59,    51,    51,   -71,   176,
      77,   298,   298,    88,   -71,    80,   -71,   -71,   -71,    95,
     176,   159,   319,   319,    88,   -70,   112,   163,   164,   165,
     -74,   166,   167,    81,   168,    88,   -37,   -37,    39,    40,
     159,   169,   170,    43,    44,   -37,   171,   172,   -73,   -72,
      92,   -72,   -72,   173,   159,   174,   -72,   -72,    62,   -36,
     -64,   -73,   259,   260,   -36,   -36,   178,    62,   -64,   -73,
     -64,   -73,   -52,   269,   279,   283,   107,   161,   178,   113,
     -52,   -52,   -52,   -61,   243,   290,   300,   304,   -30,   -30,
     178,   -61,   -61,   -61,   -67,   180,   161,   311,   321,   325,
     -52,   215,   178,   216,   -34,   100,   103,   114,   -52,   -62,
     -52,   115,   357,    62,    62,   211,    62,   -62,   -62,   -62,
     -31,   -31,   220,   159,   133,   291,   292,   293,   -74,   294,
     295,   116,   296,   -52,    29,    30,    31,   -74,    32,    33,
     117,   143,   -60,   180,   159,   118,   161,   -72,   361,   -72,
     -60,   -72,   -60,   297,   -72,   -72,   -72,   119,   -72,   -72,
     -72,   -72,    46,    62,   -64,   159,   -52,   -52,   -52,   -63,
     219,   -52,   -64,   -64,   -64,    60,    60,   -63,   -63,   -63,
     -65,   120,   178,   123,   368,   369,   161,   126,   -65,   -65,
     -65,   -57,   127,   178,   -30,   372,   373,   150,   151,   -57,
     -57,   -57,   152,   153,   178,   161,   376,   377,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   217,   -17,   -31,
     -17,   -17,   -17,   -17,   161,   -17,   -17,   -17,   -17,   134,
     -17,   -71,   -17,   -17,   -17,   -17,   -17,   -71,   161,   -71,
     -17,   -71,    63,   -62,   -35,   -62,   211,   211,   -62,   -62,
     180,    63,   250,   251,   252,   -55,   135,   161,   281,   161,
     136,   162,   180,   -55,   -55,   -55,   -69,   -58,   137,   180,
     302,   180,   -32,   -32,   180,   -58,   -58,   -58,   -38,   181,
     162,   138,   323,   -56,   139,   -61,   180,   -61,   -61,   101,
     104,   -56,   -56,   -56,   -53,   -33,   -33,    63,    63,   212,
      63,   -54,   -53,   -53,   -53,   -66,   -32,   161,   -33,   -54,
     -54,   -54,   221,   -66,   -66,   -66,   222,   144,   145,   146,
     -74,   147,   148,   218,   149,   -63,   223,   181,   161,   -37,
     162,   150,   151,   -63,   232,   -63,   152,   153,   233,   -72,
     -65,   -72,   -72,   154,   -57,   155,   -72,    63,   -65,   161,
     -65,   234,   -57,   -34,   -57,   235,   -37,   -55,   244,    62,
      62,   359,   245,   360,   246,   -55,   180,   -55,   281,   281,
     162,   270,   271,   272,   -74,   273,   274,   180,   275,   302,
     302,   -52,   -52,   -52,   -58,   231,   -52,   -52,   180,   162,
     323,   323,   -58,   -72,   -58,   -72,   -56,   -72,   247,   276,
     -72,   -36,   268,   339,   -56,   -60,   -56,   -60,   162,   -36,
     -60,   182,   183,   184,   -74,   185,   186,   289,   187,    61,
     169,   170,   162,   310,   -30,   171,   172,   -72,    61,   327,
     212,   212,   330,   -72,   181,   -72,   -72,   -72,   160,   193,
     -53,   162,   282,   162,   331,   -71,   181,   -71,   -53,   -71,
     -53,   332,   -71,   181,   303,   181,   179,   160,   181,   333,
     201,   202,   203,   -74,   204,   205,   324,   206,   334,   341,
     181,   -54,   342,   343,    61,    61,   210,    61,   -61,   -54,
     -61,   -54,   -72,   -61,   -72,   344,   -72,   -72,   207,   -31,
     345,   162,   -66,   352,    29,    30,    31,   -74,    32,    33,
     -66,   143,   -66,   353,   179,   188,   189,   160,    39,    40,
     190,   191,   162,    43,    44,   354,   -72,   355,   -72,   -72,
      45,    66,    46,   -71,    61,   -71,   -71,   -71,   356,   363,
     -71,   -71,   -30,   162,   -71,   -62,   -71,   -62,   -71,    50,
     -62,   -71,   -71,    63,    63,   -31,   -32,   160,    67,   -33,
     181,   367,   282,   282,   -61,   -61,   -61,    78,   156,   -61,
     -61,   181,   371,   303,   303,   -52,   160,   -52,   -32,   346,
     -52,   -52,   181,   375,   324,   324,   175,   156,   -33,   229,
     378,   -60,   -60,   -60,   379,   160,   -60,   380,   312,   313,
     314,   -74,   315,   316,    67,   317,    10,   108,   -71,   160,
     -71,   -71,   -71,     0,   -72,   -71,   128,   210,   210,     0,
     -72,   179,   -72,     0,   -72,     0,   318,     0,   160,   280,
     160,     0,     0,   179,   175,     0,   -62,   156,   -62,   -62,
     179,   301,   179,     0,     0,   179,   -62,   -62,   -62,     0,
       0,   -62,   -62,   322,    50,     0,   -64,   179,   -64,   -64,
      29,    30,    31,   -74,    32,    33,   -64,    34,   -64,     0,
       0,   -64,   -64,     0,    39,    40,   224,   156,   160,    43,
      44,    59,   -72,     0,   -72,   -72,    45,   -72,    46,     0,
      59,     0,   -64,   -64,   -64,   236,   156,   -64,   -64,   160,
     158,   -63,   -63,   -63,     0,     0,   -63,   -63,     0,     0,
       0,   -65,   -65,   -65,   248,   156,   -65,   -65,   177,   158,
     160,   -57,   -57,   -57,     0,     0,   -57,   -57,     0,   156,
      61,    61,   -61,   -61,   -61,   -61,    59,   179,   110,   280,
     280,   175,   -52,   -52,   -52,   -52,   -52,    64,   179,     0,
     301,   301,   -63,   175,   -63,     0,     0,   -63,   -63,   179,
       0,   322,   322,     0,     0,   175,   177,     0,     0,   158,
     238,   239,   240,     0,     0,   -35,   -35,   175,     0,     0,
     182,   183,   184,   -74,   185,   186,    59,   187,    86,     0,
     -60,   -60,   -60,   -60,   188,   189,   -72,     0,   156,   190,
     191,     0,   -72,     0,   -72,   -72,   192,     0,   193,   158,
     -55,   -55,   -55,     0,     0,   -55,   -55,     0,     0,   156,
     -58,   -58,   -58,     0,     0,   -58,   -58,     0,   158,   -56,
     -56,   -56,     0,     0,   -56,   -56,   -53,   -53,   -53,     0,
     156,   -53,   -53,   -54,   -54,   -54,     0,   158,   -54,   -54,
      50,    50,     0,   -66,   -66,   -66,     0,   175,   -66,   -66,
     -65,   158,   -65,     0,     0,   -65,   -65,     0,   175,   -57,
       0,   -57,     0,   177,   -57,   -57,     0,     0,   348,   175,
     349,   278,     0,   -34,   -34,   177,   -55,   -63,   -55,   -63,
     -63,   -55,   -55,   299,   -58,     0,   -58,   177,     0,   -58,
     -58,   -56,     0,   -56,     0,   320,   -56,   -56,   -71,   177,
     -71,   -71,   -71,   -71,   -19,   -19,   -19,   -19,   -19,   -19,
      25,   -19,   -19,     0,   -19,     0,   -19,   -19,   -19,   -19,
     158,   -19,   -19,   -19,   -19,     0,   -19,     0,   -19,   -19,
     -19,   -19,   -19,   -53,     0,   -53,   -19,     0,   -53,   -53,
     -54,   158,   -54,     0,     0,   -54,   -54,   -66,   -65,   -66,
     -65,   -65,   -66,   -66,   -61,   -61,   -61,     0,   -57,   -61,
     -57,   -57,   158,   -62,   -62,   -62,     0,     0,   -62,   -64,
     -64,   -64,    59,    59,   -64,   -63,   -63,   -63,     0,   177,
     -63,   -65,   -65,   -65,     0,   -55,   -65,   -55,   -55,     0,
     177,     0,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   177,   -16,     0,   -16,   -16,   -16,   -16,     0,   -16,
     -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,   -16,
     -16,     0,     0,     0,   -16,   -19,   -19,   -19,   -19,   -19,
     -19,     0,   -19,   -19,     0,   -19,     0,   -19,   -19,   -19,
     -19,     0,   -19,   -19,   -19,   -19,     0,   -19,     0,   -19,
     -19,   -19,   -19,   -19,     0,     0,   218,   -19,   -46,   -46,
     -46,   -46,   -46,   -46,     0,   -46,   -46,   140,   -46,     0,
     -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,     0,
     -46,     0,   -46,   -46,   -46,   -46,   -46,     0,     0,     0,
     -46,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
       0,    -8,     0,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,     0,    -8,     0,    -8,    -8,    -8,    -8,    -8,
       0,     0,     0,    -8,   -15,   -15,   -15,   -15,   -15,   -15,
       0,   -15,   -15,   -15,   -15,     0,   -15,   -15,   -15,   -15,
       0,   -15,   -15,   -15,   -15,     0,   -15,     0,   -15,   -15,
     -15,   -15,   -15,     0,     0,     0,   -15,    29,    30,    31,
     -74,    32,    33,     0,    34,    35,     0,    36,     0,    37,
      38,    39,    40,     0,    41,    42,    43,    44,     0,   -72,
       0,   -72,   -72,    45,   -72,    46,     0,     0,     0,    47,
     -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,     0,
     -18,     0,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,
     -18,     0,   -18,     0,   -18,   -18,   -18,   -18,   -18,     0,
       0,     0,   -18,   -20,   -20,   -20,   -20,   -20,   -20,     0,
     -20,   -20,     0,   -20,     0,   -20,   -20,   -20,   -20,     0,
     -20,   -20,   -20,   -20,     0,   -20,     0,   -20,   -20,   -20,
     -20,   -20,     0,     0,     0,   -20,   -25,   -25,   -25,   -25,
     -25,   -25,     0,   -25,   -25,     0,   -25,     0,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,   -25,     0,   -25,     0,
     -25,   -25,   -25,   -25,   -25,     0,     0,     0,   -25,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,     0,   -26,
       0,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
       0,   -26,     0,   -26,   -26,   -26,   -26,   -26,     0,     0,
       0,   -26,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
     -27,     0,   -27,     0,   -27,   -27,   -27,   -27,     0,   -27,
     -27,   -27,   -27,     0,   -27,     0,   -27,   -27,   -27,   -27,
     -27,     0,     0,     0,   -27,   -21,   -21,   -21,   -21,   -21,
     -21,     0,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,     0,   -21,     0,   -21,
     -21,   -21,   -21,   -21,     0,     0,     0,   -21,   -22,   -22,
     -22,   -22,   -22,   -22,     0,   -22,   -22,     0,   -22,     0,
     -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,     0,
     -22,     0,   -22,   -22,   -22,   -22,   -22,     0,     0,     0,
     -22,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
       0,   -23,     0,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,   -23,     0,   -23,     0,   -23,   -23,   -23,   -23,   -23,
       0,     0,     0,   -23,   -51,   -51,   -51,   -51,   -51,   -51,
       0,   -51,   -51,     0,   -51,     0,   -51,   -51,   -51,   -51,
       0,   -51,   -51,   -51,   -51,     0,   -51,     0,   -51,   -51,
     -51,   -51,   -51,     0,     0,     0,   -51,   -24,   -24,   -24,
     -24,   -24,   -24,     0,   -24,   -24,     0,   -24,     0,   -24,
     -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,     0,   -24,
       0,   -24,   -24,   -24,   -24,   -24,     0,     0,     0,   -24,
     -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,     0,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,
     -29,     0,   -29,     0,   -29,   -29,   -29,   -29,   -29,     0,
       0,     0,   -29,   -50,   -50,   -50,   -50,   -50,   -50,     0,
     -50,   -50,     0,   -50,     0,   -50,   -50,   -50,   -50,     0,
     -50,   -50,   -50,   -50,     0,   -50,     0,   -50,   -50,   -50,
     -50,   -50,     0,     0,     0,   -50,   -28,   -28,   -28,   -28,
     -28,   -28,     0,   -28,   -28,     0,   -28,     0,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,   -28,     0,   -28,     0,
     -28,   -28,   -28,   -28,   -28,     0,     0,     0,   -28,   -49,
     -49,   -49,   -49,   -49,   -49,     0,   -49,   -49,     0,   -49,
       0,   -49,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
       0,   -49,     0,   -49,   -49,   -49,   -49,   -49,     0,     0,
       0,   -49,    29,    30,    31,   -48,    32,    33,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,     0,    41,
      42,    43,    44,     0,   -48,     0,   -48,   -48,    45,   -48,
      46,     0,     0,     0,   -48,   -45,   -45,   -45,   -45,   -45,
     -45,     0,   -45,   -45,     0,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,   -45,     0,   -45,     0,   -45,
     -45,   -45,   -45,   -45,     0,     0,     0,   -45,   -41,   -41,
     -41,   -41,   -41,   -41,     0,   -41,   -41,     0,   -41,     0,
     -41,   -41,   -41,   -41,     0,   -41,   -41,   -41,   -41,     0,
     -41,     0,   -41,   -41,   -41,   -41,   -41,     0,     0,     0,
     -41,   -40,   -40,   -40,   -40,   -40,   -40,     0,   -40,   -40,
       0,   -40,     0,   -40,   -40,   -40,   -40,     0,   -40,   -40,
     -40,   -40,     0,   -40,     0,   -40,   -40,   -40,   -40,   -40,
       0,     0,     0,   -40,   -39,   -39,   -39,   -39,   -39,   -39,
       0,   -39,   -39,     0,   -39,     0,   -39,   -39,   -39,   -39,
       0,   -39,   -39,   -39,   -39,     0,   -39,     0,   -39,   -39,
     -39,   -39,   -39,     0,     0,     0,   -39,   -44,   -44,   -44,
     -44,   -44,   -44,     0,   -44,   -44,     0,   -44,     0,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,     0,   -44,
       0,   -44,   -44,   -44,   -44,   -44,     0,     0,     0,   -44,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,     0,
     -43,     0,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,
     -43,     0,   -43,     0,   -43,   -43,   -43,   -43,   -43,     0,
       0,     0,   -43,   -42,   -42,   -42,   -42,   -42,   -42,     0,
     -42,   -42,     0,   -42,     0,   -42,   -42,   -42,   -42,     0,
     -42,   -42,   -42,   -42,     0,   -42,     0,   -42,   -42,   -42,
     -42,   -42,     0,     0,     0,   -42,   -47,   -47,   -47,   -47,
     -47,   -47,     0,   -47,   -47,     0,   -47,     0,   -47,   -47,
     -47,   -47,     0,   -47,   -47,   -47,   -47,     0,   -47,     0,
     -47,   -47,   -47,   -47,   -47,     0,     0,     0,   -47,    29,
      30,    31,   -74,    32,    33,     0,    34,    35,     0,    36,
       0,    37,    38,    39,    40,     0,    41,    42,    43,    44,
       0,   -72,     0,   -72,   -72,    45,   -72,    46,     0,     0,
       0,   364,    29,    30,    31,   -74,    32,    33,     0,    34,
      35,     0,    36,     0,    37,    38,    39,    40,     0,    41,
      42,    43,    44,     0,   -72,     0,   -72,   -72,    45,   -72,
      46,     0,     0,     0,   365,   -15,   -15,   -15,   -15,   -15,
     -15,     0,   -15,   -15,     0,   -15,     0,   -15,   -15,   -15,
     -15,     0,   -15,   -15,   -15,   -15,     0,   -15,     0,   -15,
     -15,   -15,   -15,   -15,   -57,   -57,   -57,   -15,     0,   -57,
     226,   227,   228,     0,     0,   -35,   -55,   -55,   -55,     0,
       0,   -55,   -58,   -58,   -58,     0,   257,   -58,   -60,     0,
     -60,   -60,   -71,     0,   -71,     0,   -71,   -71,   -56,   -56,
     -56,     0,     0,   -56,   -53,   -53,   -53,     0,   -52,   -53,
     -52,     0,   335,   -52,   -54,   -54,   -54,     0,     0,   -54,
     -66,   -66,   -66,     0,   -64,   -66,   -64,     0,   -63,   -64,
     -63,     0,   -65,   -63,   -65,     0,   -57,   -65,   -57,     0,
     337,   -57,   338,     0,   -55,   -34,   -55,     0,   -58,   -55,
     -58,     0,   -56,   -58,   -56,     0,   -53,   -56,   -53,     0,
     -54,   -53,   -54,     0,   -66,   -54,   -66,     0,     0,   -66,
      82,   -57,   -57,   -57,   -57,   -52,   -52,   -52,   -52,    64,
     -62,   -62,   -62,   -62,   -64,   -64,   -64,   -64,   -63,   -63,
     -63,   -63,   -65,   -65,   -65,   -65,    83,    84,    85,   -35,
     -55,   -55,   -55,   -55,   -58,   -58,   -58,   -58,   -57,   -57,
     -57,   -57,   -56,   -56,   -56,   -56,   -53,   -53,   -53,   -53,
     -54,   -54,   -54,   -54,   -66,   -66,   -66,   -66,   -58,     0,
     -58,   -58,   -53,     0,   -53,   -53,   -54,     0,   -54,   -54,
     -56,     0,   -56,   -56,   -66,     0,   -66,   -66
};

static const yytype_int16 yycheck[] =
{
      27,    25,     0,    72,    73,     6,   219,    76,    32,    36,
     116,     9,     9,     0,   114,    27,   116,     6,   231,    46,
       0,    10,     9,     6,    36,     6,    27,    28,    29,     9,
     243,    32,    33,     6,    46,    32,    25,    64,    65,     6,
     140,     0,   255,    32,    71,     0,     6,    74,    75,    32,
      77,    32,    64,    65,     9,    82,    83,    84,    85,    32,
      27,    28,    29,     6,    10,    32,    33,    27,    28,    29,
      82,    19,    32,     3,     4,     5,     6,     7,     8,    27,
      10,    29,     0,     6,    27,   112,    29,     0,   115,    32,
      33,     9,    30,    31,    31,    25,     9,    27,    28,    29,
     112,    31,    32,   115,    27,   132,    29,    10,    19,    32,
       3,     4,     5,     6,     7,     8,    27,    10,    29,    25,
     132,    27,   335,    29,    17,    18,    32,    33,   155,    22,
      23,    32,    25,   346,    27,    28,    29,     6,    31,    32,
      33,     0,     0,   155,   357,     0,     6,   174,    34,     1,
       9,   220,   221,   222,     9,   261,   262,     9,    27,    28,
      29,    30,   174,   232,   233,   234,   193,    27,     9,    29,
       0,    25,    32,    33,     4,   244,   245,   246,    32,    10,
     207,   193,    10,    25,    27,    27,    28,    29,   215,   216,
      32,    33,   219,    36,     6,   207,   223,    30,    25,   226,
     227,   228,     6,    46,   231,    32,     6,   219,   235,    32,
      33,   238,   239,   240,     6,    27,   243,    29,    30,   231,
     247,    64,    65,    27,   251,    29,    30,    27,   255,    29,
      31,   243,    32,    32,    33,    27,    28,    29,    30,    82,
      83,    84,    85,   255,    27,     6,    29,    30,    31,   276,
      31,     3,     4,     5,     6,     7,     8,    27,    10,    29,
      31,     6,    32,    33,   276,     6,    27,    28,    29,   112,
     297,    32,   115,    25,    19,    27,    28,    29,    19,    31,
      32,    33,    27,    28,    29,   297,    27,    28,    29,   132,
      19,   318,     6,    32,    33,    31,    25,    31,    27,    28,
      29,   328,   329,   217,   218,    19,   318,    31,   335,    31,
     337,   338,   155,    27,    31,    29,   328,   329,    19,   346,
      31,   348,   349,   335,    25,    30,    27,    28,    29,    10,
     357,   174,   359,   360,   346,    32,    33,     3,     4,     5,
       6,     7,     8,    30,    10,   357,    32,    33,    17,    18,
     193,    17,    18,    22,    23,    30,    22,    23,     6,    25,
      30,    27,    28,    29,   207,    31,    32,    33,    27,    30,
      19,    19,   215,   216,    32,    33,   219,    36,    27,    27,
      29,    29,    19,   226,   227,   228,    32,    46,   231,    32,
      27,    28,    29,    19,    31,   238,   239,   240,    32,    33,
     243,    27,    28,    29,    32,    64,    65,   250,   251,   252,
      19,    27,   255,    29,    30,    74,    75,    32,    27,    19,
      29,    19,    31,    82,    83,    84,    85,    27,    28,    29,
      32,    33,    31,   276,    30,     3,     4,     5,     6,     7,
       8,    32,    10,    32,     3,     4,     5,     6,     7,     8,
      32,    10,    19,   112,   297,    32,   115,    25,    25,    27,
      27,    29,    29,    31,    32,    33,    25,    32,    27,    28,
      29,    30,    31,   132,    19,   318,    27,    28,    29,    19,
      31,    32,    27,    28,    29,   328,   329,    27,    28,    29,
      19,    32,   335,    32,   337,   338,   155,    32,    27,    28,
      29,    19,    32,   346,    30,   348,   349,    17,    18,    27,
      28,    29,    22,    23,   357,   174,   359,   360,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    34,    13,    30,
      15,    16,    17,    18,   193,    20,    21,    22,    23,    30,
      25,    19,    27,    28,    29,    30,    31,    25,   207,    27,
      35,    29,    27,    27,    19,    29,   215,   216,    32,    33,
     219,    36,    27,    28,    29,    19,    30,   226,   227,   228,
      30,    46,   231,    27,    28,    29,    32,    19,    30,   238,
     239,   240,    32,    33,   243,    27,    28,    29,    32,    64,
      65,    30,   251,    19,    30,    27,   255,    29,    30,    74,
      75,    27,    28,    29,    19,    32,    33,    82,    83,    84,
      85,    19,    27,    28,    29,    19,    30,   276,    30,    27,
      28,    29,    31,    27,    28,    29,    31,     3,     4,     5,
       6,     7,     8,    34,    10,    19,    31,   112,   297,    32,
     115,    17,    18,    27,    31,    29,    22,    23,    31,    25,
      19,    27,    28,    29,    19,    31,    32,   132,    27,   318,
      29,    31,    27,    19,    29,    31,    19,    19,    31,   328,
     329,    27,    31,    29,    31,    27,   335,    29,   337,   338,
     155,     3,     4,     5,     6,     7,     8,   346,    10,   348,
     349,    27,    28,    29,    19,    31,    32,    33,   357,   174,
     359,   360,    27,    25,    29,    27,    19,    29,    31,    31,
      32,    32,    32,    25,    27,    27,    29,    29,   193,    19,
      32,     3,     4,     5,     6,     7,     8,    32,    10,    27,
      17,    18,   207,    32,    19,    22,    23,    19,    36,    32,
     215,   216,    32,    25,   219,    27,    28,    29,    46,    31,
      19,   226,   227,   228,    32,    25,   231,    27,    27,    29,
      29,    32,    32,   238,   239,   240,    64,    65,   243,    32,
       3,     4,     5,     6,     7,     8,   251,    10,    32,    32,
     255,    19,    32,    32,    82,    83,    84,    85,    27,    27,
      29,    29,    25,    32,    27,    32,    29,    30,    31,    19,
      32,   276,    19,    32,     3,     4,     5,     6,     7,     8,
      27,    10,    29,    32,   112,    17,    18,   115,    17,    18,
      22,    23,   297,    22,    23,    32,    25,    32,    27,    28,
      29,    30,    31,    25,   132,    27,    28,    29,    32,    32,
      32,    33,    32,   318,    25,    27,    27,    29,    29,    27,
      32,    32,    33,   328,   329,    32,    32,   155,    36,    32,
     335,    32,   337,   338,    27,    28,    29,    45,    46,    32,
      33,   346,    32,   348,   349,    27,   174,    29,    19,    31,
      32,    33,   357,    32,   359,   360,    64,    65,    19,    25,
      32,    27,    28,    29,    32,   193,    32,    32,     3,     4,
       5,     6,     7,     8,    82,    10,     4,    82,    25,   207,
      27,    28,    29,    -1,    19,    32,   112,   215,   216,    -1,
      25,   219,    27,    -1,    29,    -1,    31,    -1,   226,   227,
     228,    -1,    -1,   231,   112,    -1,    27,   115,    29,    30,
     238,   239,   240,    -1,    -1,   243,    27,    28,    29,    -1,
      -1,    32,    33,   251,   132,    -1,    27,   255,    29,    30,
       3,     4,     5,     6,     7,     8,    27,    10,    29,    -1,
      -1,    32,    33,    -1,    17,    18,   154,   155,   276,    22,
      23,    27,    25,    -1,    27,    28,    29,    30,    31,    -1,
      36,    -1,    27,    28,    29,   173,   174,    32,    33,   297,
      46,    27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,
      -1,    27,    28,    29,   192,   193,    32,    33,    64,    65,
     318,    27,    28,    29,    -1,    -1,    32,    33,    -1,   207,
     328,   329,    27,    28,    29,    30,    82,   335,    84,   337,
     338,   219,    26,    27,    28,    29,    30,    31,   346,    -1,
     348,   349,    27,   231,    29,    -1,    -1,    32,    33,   357,
      -1,   359,   360,    -1,    -1,   243,   112,    -1,    -1,   115,
      27,    28,    29,    -1,    -1,    32,    33,   255,    -1,    -1,
       3,     4,     5,     6,     7,     8,   132,    10,    25,    -1,
      27,    28,    29,    30,    17,    18,    19,    -1,   276,    22,
      23,    -1,    25,    -1,    27,    28,    29,    -1,    31,   155,
      27,    28,    29,    -1,    -1,    32,    33,    -1,    -1,   297,
      27,    28,    29,    -1,    -1,    32,    33,    -1,   174,    27,
      28,    29,    -1,    -1,    32,    33,    27,    28,    29,    -1,
     318,    32,    33,    27,    28,    29,    -1,   193,    32,    33,
     328,   329,    -1,    27,    28,    29,    -1,   335,    32,    33,
      27,   207,    29,    -1,    -1,    32,    33,    -1,   346,    27,
      -1,    29,    -1,   219,    32,    33,    -1,    -1,    27,   357,
      29,   227,    -1,    32,    33,   231,    27,    27,    29,    29,
      30,    32,    33,   239,    27,    -1,    29,   243,    -1,    32,
      33,    27,    -1,    29,    -1,   251,    32,    33,    25,   255,
      27,    28,    29,    30,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    13,    -1,    15,    16,    17,    18,
     276,    20,    21,    22,    23,    -1,    25,    -1,    27,    28,
      29,    30,    31,    27,    -1,    29,    35,    -1,    32,    33,
      27,   297,    29,    -1,    -1,    32,    33,    27,    27,    29,
      29,    30,    32,    33,    27,    28,    29,    -1,    27,    32,
      29,    30,   318,    27,    28,    29,    -1,    -1,    32,    27,
      28,    29,   328,   329,    32,    27,    28,    29,    -1,   335,
      32,    27,    28,    29,    -1,    27,    32,    29,    30,    -1,
     346,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   357,    13,    -1,    15,    16,    17,    18,    -1,    20,
      21,    22,    23,    -1,    25,    -1,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    35,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    13,    -1,    15,    16,    17,
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
      28,    29,    30,    31,    27,    28,    29,    35,    -1,    32,
      27,    28,    29,    -1,    -1,    32,    27,    28,    29,    -1,
      -1,    32,    27,    28,    29,    -1,    25,    32,    27,    -1,
      29,    30,    25,    -1,    27,    -1,    29,    30,    27,    28,
      29,    -1,    -1,    32,    27,    28,    29,    -1,    27,    32,
      29,    -1,    31,    32,    27,    28,    29,    -1,    -1,    32,
      27,    28,    29,    -1,    27,    32,    29,    -1,    27,    32,
      29,    -1,    27,    32,    29,    -1,    27,    32,    29,    -1,
      27,    32,    29,    -1,    27,    32,    29,    -1,    27,    32,
      29,    -1,    27,    32,    29,    -1,    27,    32,    29,    -1,
      27,    32,    29,    -1,    27,    32,    29,    -1,    -1,    32,
      26,    27,    28,    29,    30,    27,    28,    29,    30,    31,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    27,    28,    29,    30,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    28,
      29,    30,    27,    28,    29,    30,    27,    28,    29,    30,
      27,    28,    29,    30,    27,    28,    29,    30,    27,    -1,
      29,    30,    27,    -1,    29,    30,    27,    -1,    29,    30,
      27,    -1,    29,    30,    27,    -1,    29,    30
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
      49,    50,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    64,    65,    31,    31,    30,    49,    50,    58,
      31,    31,    31,    31,    31,    31,    31,    31,    49,    50,
      30,    30,    26,    27,    28,    29,    25,     6,    50,    62,
      63,    50,    30,    50,    51,    10,    58,    51,    51,    58,
      64,    65,    58,    64,    65,    51,    58,    32,    48,    60,
      59,    60,    33,    32,    32,    19,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    63,    44,
      50,    44,    46,    30,    30,    30,    30,    30,    30,    30,
      12,    44,    30,    10,     3,     4,     5,     7,     8,    10,
      17,    18,    22,    23,    29,    31,    49,    58,    59,    60,
      61,    64,    65,     3,     4,     5,     7,     8,    10,    17,
      18,    22,    23,    29,    31,    49,    58,    59,    60,    61,
      64,    65,     3,     4,     5,     7,     8,    10,    17,    18,
      22,    23,    29,    31,    49,    58,    59,    60,    61,    64,
      65,     3,     4,     5,     7,     8,    10,    31,    58,    60,
      61,    64,    65,    25,     6,    27,    29,    34,    34,    31,
      31,    31,    31,    31,    49,    50,    27,    28,    29,    25,
       6,    31,    31,    31,    31,    31,    49,    50,    27,    28,
      29,    25,     6,    31,    31,    31,    31,    31,    49,    50,
      27,    28,    29,    25,     6,    31,    50,    25,     6,    60,
      60,    45,    45,    62,    51,    51,    51,    58,    32,    60,
       3,     4,     5,     7,     8,    10,    31,    58,    59,    60,
      61,    64,    65,    60,    62,    51,    51,    51,    58,    32,
      60,     3,     4,     5,     7,     8,    10,    31,    58,    59,
      60,    61,    64,    65,    60,    62,    51,    51,    51,    58,
      32,    60,     3,     4,     5,     7,     8,    10,    31,    58,
      59,    60,    61,    64,    65,    60,    62,    32,    46,    46,
      32,    32,    32,    32,    32,    31,    50,    27,    29,    25,
       6,    32,    32,    32,    32,    32,    31,    50,    27,    29,
      25,     6,    32,    32,    32,    32,    32,    31,    50,    27,
      29,    25,     6,    32,    35,    35,    62,    32,    60,    60,
      62,    32,    60,    60,    62,    32,    60,    60,    32,    32,
      32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    41,
      40,    42,    42,    43,    43,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      49,    49,    49,    49,    50,    50,    50,    50,    51,    52,
      52,    52,    53,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    65
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     3,     0,
       7,     1,     0,     4,     2,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     2,     1,     1,     1,     3,     2,
       4,     4,     4,     4,     3,     1,     2,     1,     3,     5,
       5,     5,     5,     5,     5,     5,     5,     7,     5,     5,
       3,     2,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     0,     3,
       1,     2,     0,     2,     0
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
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 97 "parser.y" /* yacc.c:1646  */
    {}
#line 1966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1974 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 104 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1982 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 107 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 116 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), 'V');
    }
#line 2007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'F');
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 134 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 137 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 2050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), 'P');
    }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("COMPOUND_STATEMENT", (yyvsp[-2].node), (yyvsp[-1].node), NULL, NULL);
    }
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOCAL_DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2075 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 163 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 169 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2091 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 172 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2099 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 178 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 181 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2115 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 184 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2123 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 187 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 190 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2139 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 193 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2147 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 196 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 199 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2163 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2171 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 208 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 214 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2187 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 217 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2195 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 220 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 223 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2211 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 229 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2219 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 232 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2227 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 235 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2235 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2243 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 244 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2251 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 250 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 253 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2267 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 256 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 262 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 265 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2291 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 268 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, "void", (yyvsp[-4].token)); 
    }
#line 2299 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 274 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 280 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2315 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 283 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        (yyval.node) = insert_node("CONDITIONAL_STATEMENT", (yyvsp[-4].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 290 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 294 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2340 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 300 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
    }
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 303 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
    }
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 309 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("VARIABLE", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 315 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 318 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token)); 
    }
#line 2380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 321 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2388 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 327 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 330 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 333 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 336 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 339 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 342 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 345 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 348 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2452 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 351 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("FLOATNUMBER", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 354 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("EMPTY_VALUE", NULL, NULL, "empty", (yyvsp[0].token)); 
    }
#line 2468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 360 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = insert_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, NULL, (yyvsp[-3].token));
    }
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 366 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 369 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 375 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 378 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 384 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "char", (yyvsp[0].token)); 
    }
#line 2516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 387 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 393 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = insert_node("STRING", (yyvsp[-1].node), NULL, "string", (yyvsp[0].token)); 
    }
#line 2532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 396 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2540 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2544 "parser.tab.c" /* yacc.c:1646  */
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
#line 400 "parser.y" /* yacc.c:1906  */


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
