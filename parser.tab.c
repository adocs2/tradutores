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
#line 3 "parser.y" /* yacc.c:339  */

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

typedef struct args_node {
    char* name;
    char* type;
    struct args_node *next;
} args_node;

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
void semantic_error_redeclared_variable(char* name, char* scope);
void semantic_error_not_declared_variable(char* name);
symbol_node* search_for_symbol(char* name);
void semantic_error_no_main();
void check_semantic_error_no_main();
void implicit_conversion(node *no, char* func_type);
void define_type(node* no);
void semantic_error_return_type(char* return_type, char* type);
void check_semantic_error_return_type(char* return_type, node* no);
void semantic_error_wrong_number_arguments(char* value, int number_args, int number_param);
void semantic_error_type_mismatch(char* value_left, char* value_right, char* type_left, char* type_right);
void semantic_error_type_mismatch_args(char* function_name, char* arg_name, char* type_arg, char* param_name, char* type_param);
void check_semantic_error_type_mismatch_args(node* no, char* function_name);
void implicit_args_conversion(node *no, char* expected_type, int direction);
node* find_arg(node* no, int i, int number_args, int* direction);
args_node* create_args_list(node* no);
void semantic_error_set_arith_op();


#line 158 "parser.tab.c" /* yacc.c:339  */

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
#line 95 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 234 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   3007

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

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
       0,   113,   113,   117,   121,   124,   127,   130,   133,   139,
     146,   146,   157,   160,   166,   170,   176,   179,   185,   191,
     194,   200,   203,   206,   209,   212,   215,   218,   221,   224,
     227,   234,   238,   244,   247,   250,   253,   259,   262,   265,
     268,   274,   280,   283,   286,   292,   295,   298,   304,   310,
     313,   320,   326,   331,   338,   349,   353,   357,   361,   367,
     370,   373,   376,   379,   382,   385,   388,   394,   406,   409,
     415,   418
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

#define YYPACT_NINF -223

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-223)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     168,    34,    39,    53,    15,   210,   370,   -23,  -223,   441,
     461,   584,    23,    -4,    49,    50,   292,   549,    55,    84,
    1652,   588,    85,  1682,   595,  1712,   854,  2805,  2818,  2822,
    2826,    87,  2782,    78,   267,    88,   113,   140,   156,   158,
     196,   198,   202,   632,   470,   617,  1742,  1772,  1802,    -5,
      47,   109,  1832,  1862,  1892,  1922,  1952,  1982,  2788,  2839,
    2843,  2847,   181,   114,   470,  2012,   120,   131,  2860,   748,
     271,   748,   748,   101,   153,   748,   271,   178,    13,  2042,
     840,  2072,  2663,   188,   188,   188,   -13,   224,   250,    24,
    2102,   272,    31,   253,   318,    37,    79,   338,   343,   345,
     366,   371,   379,    82,   383,  2864,   187,  2132,  2868,  2881,
    2885,  2684,  2889,   710,  2642,   400,   247,   257,   403,   413,
     437,   459,   467,   479,   263,   314,   481,    64,   385,   902,
    2162,  2192,  2222,  2252,  2282,  2312,  2342,  2372,  2642,  2402,
    2681,   313,   339,   466,   674,   782,   289,   503,   510,   520,
     523,   837,   470,   110,   115,  2727,  2733,  2739,  2745,  2432,
     282,   390,   430,   478,   585,   235,   530,   534,   568,   573,
    2661,   470,     6,    11,   614,   634,   656,   762,  2902,  2905,
    2908,  2920,  2923,   548,   578,   580,   592,   598,  2804,   470,
     597,  2926,  2938,  2941,  2944,   587,   599,   601,   604,   606,
     554,   470,   612,   613,   470,  2684,   932,   642,   625,   425,
     628,   633,   638,   646,  1652,   962,   992,   356,   391,  1022,
    1052,  1082,  1112,  1142,  1172,  2801,  1652,  2462,  2492,   114,
     748,   748,   748,   271,   151,   170,   349,   349,   349,   114,
     748,   748,   748,   271,    69,   180,   553,   553,   553,   114,
     748,   748,   748,   271,   655,   254,   591,   591,   591,   114,
     260,   358,   108,   648,   470,  1202,   460,   748,   271,   299,
     518,  2522,  1232,  1262,  2663,  2552,   647,   418,   420,   421,
     649,  2751,  2757,  2763,  2769,   654,   443,   448,   450,   658,
     806,  2689,  2696,  2708,   659,   453,   484,   499,   661,  2956,
    2959,  2962,  2974,   662,   665,  1292,   500,  1322,   501,   666,
     672,   689,   691,   702,   703,   706,  1352,  1382,  2582,  2775,
     508,   511,   512,   532,  2715,   119,   147,   167,   189,  2977,
     669,   722,   724,   725,   727,   710,   710,   726,   730,   733,
     737,   738,   741,   742,  2612,  1412,  1442,  1472,  1502,  1532,
    1562,  1592,  1622
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
       0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -223,  -223,  -223,     0,   771,  -223,  -223,  -223,   -91,   -15,
    -195,  -103,   -80,   402,   545,   637,  -100,   -97,   -95,   -85,
     -77,   -75,   -22,   558,    91,   300,  -222,   668
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
       5,    58,   107,    21,     9,    14,   205,   276,    11,   -10,
     129,   228,    68,   219,   -39,    -2,   220,   285,   221,   271,
     -71,   111,   155,   130,     2,   -39,    79,   294,   222,   -13,
     -40,   275,   204,   216,    -3,   228,   223,   303,   224,   -39,
     -39,   174,   155,   204,   -40,   -40,   105,   139,    94,     7,
     -40,   202,   202,     8,   104,    13,   -40,   113,    68,    17,
      58,    68,    68,    68,   114,   -49,    80,   -49,   -49,   -49,
     116,   -49,   -49,   -49,   -49,   -49,   138,   -49,    81,   -49,
     -49,   -49,   -49,    18,   -49,   -49,   -49,   -49,   -38,   174,
      20,   225,    58,    22,   -49,    24,   -49,    62,   -40,   227,
     -49,   -40,   -38,   -38,   195,   196,   197,    97,   198,   199,
      64,   200,   117,   215,    60,   124,    58,   160,   161,   162,
      69,   163,   164,   227,   165,    60,    98,   205,   -40,   -39,
     155,   166,   167,   201,   -40,   157,   168,   169,   -33,   -39,
     -40,   -41,   -41,   -39,   170,    70,   171,   -69,   -40,   155,
      80,   -39,   -33,   -33,   176,   157,   195,   196,   197,   100,
     198,   199,    90,   200,    99,   102,   -34,   155,    -8,     1,
     -38,    60,    71,    60,   108,   109,   110,     2,   101,   155,
     -34,   -34,   155,   174,   -38,   201,   -35,    68,    72,   204,
      73,    26,    27,    28,   317,    29,    30,   -38,   140,   204,
     -35,   -35,   176,   281,    60,    60,    80,   174,   -36,   -38,
      -5,   280,   159,   290,   155,   155,   155,   174,   -41,    -5,
      44,   289,   -36,   -36,   174,   174,   174,   174,    74,    60,
      75,   298,   129,   129,    76,   219,   219,   174,   220,   220,
     221,   221,   155,   157,   344,   345,   309,   202,   202,    58,
     222,   222,   225,    58,   -54,   216,   216,   112,   223,   223,
     224,   224,   157,   -54,   -54,   -54,   -33,   239,   -54,   -54,
      26,    27,    28,   204,    29,    30,   -34,   140,   -33,   204,
     157,    93,   -35,   -68,    37,    38,   -54,   299,   -34,    41,
      42,   204,   157,   304,   -35,   157,   176,    43,    65,    44,
      60,   -62,   195,   196,   197,   310,   198,   199,   -54,   200,
     -62,   -62,   -62,   225,   225,   -62,   -62,   -54,   -54,   -54,
     176,   229,   -54,    61,   311,   -12,    19,   282,   283,   284,
     176,   201,   -62,   -36,    61,   215,   215,   291,   292,   293,
     176,   -62,   -62,   -62,   158,   -36,   -62,   300,   301,   302,
     176,   115,   141,   142,   143,   157,   144,   145,   -63,   146,
     312,   315,    60,   177,   158,    60,    60,   -63,   -63,   -63,
      -7,   118,   -63,   203,   203,   -39,   119,   204,   120,    -7,
      61,   152,    61,    61,    61,    61,   -16,   272,   -16,   -16,
     -16,   -41,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   121,
     -16,   -16,   -16,   -16,   122,   -16,   -16,   -16,   -16,   -63,
      80,   177,   123,    61,    61,   -16,   125,   -16,   -63,   -63,
     -63,   -16,   273,   -63,   -63,    49,    60,    60,    26,    27,
      28,   131,    29,    30,   132,   140,    66,   -40,    61,   -40,
     -40,    -4,    37,    38,   133,    77,   153,    41,    42,   -65,
      -4,   320,   158,   321,   322,    43,   265,    44,   -65,   -65,
     -65,    -6,   -40,   -65,   -65,   172,   153,   -40,   134,   -40,
      -6,   158,   -40,   141,   142,   143,   325,   144,   145,    80,
     146,   326,    66,   327,    66,   -65,   330,   147,   148,   158,
     135,   307,   149,   150,   -65,   -65,   -65,   -64,   136,   -65,
     151,   158,   152,   -40,   158,   177,   -64,   -64,   -64,    61,
     137,   -64,   -64,   172,   -70,   217,    49,   331,   -40,   204,
     -40,   195,   196,   197,   313,   198,   199,   -33,   200,   177,
     -34,   -35,   332,   335,   336,   230,   158,   158,   158,   177,
      49,   -33,   231,   314,   -34,   -35,   177,   177,   177,   177,
     201,   -36,   232,   234,   153,   233,   160,   161,   162,   177,
     163,   164,   240,   165,   158,   -36,   241,   -54,    50,   203,
     203,    61,   244,   153,    61,    61,   -54,   -54,   -54,    67,
     249,    59,   -15,   -15,    -9,   171,   259,   -54,   -11,    78,
     254,   153,    59,    -9,   178,   179,   180,   -11,   181,   182,
     242,   183,   156,   153,   -66,   243,   153,   172,    86,    89,
     250,    66,   251,   -66,   -66,   -66,   -39,   -18,   -66,   -66,
     -62,   175,   156,   189,   252,   106,   -18,    50,   -14,   -14,
     253,   172,   -63,   -60,   -65,    61,    61,   -64,    59,   -66,
      59,   172,   -60,   -60,   -60,   -60,   -61,   -60,   -60,    37,
      38,   172,   263,   -37,    41,    42,    86,   264,   218,    50,
     267,   172,   246,   247,   248,   268,   153,   -37,   -37,   175,
     269,    59,    59,    49,   -38,   -58,    66,    49,   270,   305,
     319,   154,   323,    50,   -58,   -58,   -58,   324,   -33,   -58,
     -58,   328,   329,   -64,   333,   334,    59,   235,   -59,   337,
     173,   154,   -64,   -64,   -64,   338,    92,   -64,    95,    96,
     156,   206,   103,    26,    27,    28,   245,    29,    30,   207,
      32,   208,   339,   209,   340,   210,   211,    37,    38,   156,
     212,   213,    41,    42,   255,   341,   342,   217,   217,   343,
      43,   -34,    44,   -35,   -36,   214,   260,   156,   173,   261,
     262,   178,   179,   180,   266,   181,   182,   346,   183,   156,
     -67,   347,   156,   175,   348,   184,   185,    59,   349,   350,
     186,   187,   351,   352,    86,    10,     0,     0,   188,   126,
     189,   -61,     0,     0,    86,     0,     0,   175,     0,   154,
     -61,   -61,   -61,     0,    86,   -61,   -61,   175,     0,     0,
       0,   -66,     0,     0,    86,     0,     0,   175,   154,   306,
     -66,   -66,   -66,     0,     0,   -66,    50,   175,     0,   218,
      50,     0,   156,     0,     0,   -59,   154,     0,     0,    59,
       0,     0,    59,    59,   -59,   -59,   -59,     0,   154,   -59,
     -59,   154,   173,    26,    27,    28,     0,    29,    30,     0,
     140,     0,     0,     0,   147,   148,     0,    37,    38,   149,
     150,     0,    41,    42,     0,     0,   173,   277,   278,   279,
      43,     0,    44,   -62,     0,     0,   173,   286,   287,   288,
     218,   218,   -62,   -62,   -62,   -62,   173,   295,   296,   297,
       0,     0,     0,    59,    59,     0,   173,     0,     0,     0,
       0,   154,     0,   -17,   308,   -17,   -17,   -17,     0,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,     0,   -17,   -17,   -17,
     -17,     0,   -17,   -17,   -17,   -17,     0,     0,     0,     0,
       0,     0,   -17,   -30,   -17,   -30,   -30,   -30,   -17,   -30,
     -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   -30,   -30,     0,     0,     0,     0,
       0,     0,   -30,   -21,   -30,   -21,   -21,   -21,   -30,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,     0,     0,     0,     0,
       0,     0,   -21,   -22,   -21,   -22,   -22,   -22,   -21,   -22,
     -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,
     -22,     0,   -22,   -22,   -22,   -22,     0,     0,     0,     0,
       0,     0,   -22,   -27,   -22,   -27,   -27,   -27,   -22,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,
     -27,     0,   -27,   -27,   -27,   -27,     0,     0,     0,     0,
       0,     0,   -27,   -28,   -27,   -28,   -28,   -28,   -27,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   -28,   -28,     0,     0,     0,     0,
       0,     0,   -28,   -29,   -28,   -29,   -29,   -29,   -28,   -29,
     -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,     0,     0,     0,     0,
       0,     0,   -29,   -23,   -29,   -23,   -23,   -23,   -29,   -23,
     -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,   -23,
     -23,     0,   -23,   -23,   -23,   -23,     0,     0,     0,     0,
       0,     0,   -23,   -24,   -23,   -24,   -24,   -24,   -23,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,     0,     0,     0,     0,
       0,     0,   -24,   -25,   -24,   -25,   -25,   -25,   -24,   -25,
     -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,   -25,
     -25,     0,   -25,   -25,   -25,   -25,     0,     0,     0,     0,
       0,     0,   -25,   -53,   -25,   -53,   -53,   -53,   -25,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,   -53,
     -53,     0,   -53,   -53,   -53,   -53,     0,     0,     0,     0,
       0,     0,   -53,   -26,   -53,   -26,   -26,   -26,   -53,   -26,
     -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,   -26,   -32,   -26,   -32,   -32,   -32,   -26,   -32,
     -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,   -32,
     -32,     0,   -32,   -32,   -32,   -32,     0,     0,     0,     0,
       0,     0,   -32,    -9,   -32,    -9,    -9,    -9,   -32,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,     0,    -9,    -9,    -9,
      -9,     0,    -9,    -9,    -9,    -9,     0,     0,     0,     0,
       0,     0,    -9,   -52,    -9,   -52,   -52,   -52,    -9,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,   -52,
     -52,     0,   -52,   -52,   -52,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -18,   -52,   -18,   -18,   -18,   -52,   -18,
     -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,
     -18,     0,   -18,   -18,   -18,   -18,     0,     0,     0,     0,
       0,     0,   -18,   -31,   -18,   -31,   -31,   -31,   -18,   -31,
     -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,   -31,
     -31,     0,   -31,   -31,   -31,   -31,     0,     0,     0,     0,
       0,     0,   -31,   -51,   -31,   -51,   -51,   -51,   -31,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -51,     0,     0,     0,     0,
       0,     0,   -51,   -48,   -51,   -48,   -48,   -48,   -51,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,   -48,
     -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -42,   -48,   -42,   -42,   -42,   -48,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -42,     0,     0,     0,     0,
       0,     0,   -42,   -43,   -42,   -43,   -43,   -43,   -42,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,   -43,
     -43,     0,   -43,   -43,   -43,   -43,     0,     0,     0,     0,
       0,     0,   -43,   -44,   -43,   -44,   -44,   -44,   -43,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,     0,
       0,     0,   -44,   -45,   -44,   -45,   -45,   -45,   -44,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -46,   -45,   -46,   -46,   -46,   -45,   -46,
     -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,   -46,
     -46,     0,   -46,   -46,   -46,   -46,     0,     0,     0,     0,
       0,     0,   -46,   -47,   -46,   -47,   -47,   -47,   -46,   -47,
     -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,
       0,     0,   -47,   -20,   -47,   -20,   -20,   -20,   -47,   -20,
     -20,   -20,   -20,   -20,     0,   -20,     0,   -20,   -20,   -20,
     -20,     0,   -20,   -20,   -20,   -20,     0,     0,     0,     0,
       0,     0,   -20,    25,   -20,    26,    27,    28,   -20,    29,
      30,    31,    32,    33,     0,    34,     0,    35,    36,    37,
      38,     0,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,    43,   -30,    44,   -30,   -30,   -30,    45,   -30,
     -30,   -30,   -30,   -30,     0,   -30,     0,   -30,   -30,   -30,
     -30,     0,   -30,   -30,   -30,   -30,     0,     0,     0,     0,
       0,     0,   -30,   -21,   -30,   -21,   -21,   -21,   -30,   -21,
     -21,   -21,   -21,   -21,     0,   -21,     0,   -21,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,     0,     0,     0,     0,
       0,     0,   -21,   -19,   -21,   -19,   -19,   -19,   -21,   -19,
     -19,   -19,   -19,   -19,     0,   -19,     0,   -19,   -19,   -19,
     -19,     0,   -19,   -19,   -19,   -19,     0,     0,     0,     0,
       0,     0,   -19,   -22,   -19,   -22,   -22,   -22,   -19,   -22,
     -22,   -22,   -22,   -22,     0,   -22,     0,   -22,   -22,   -22,
     -22,     0,   -22,   -22,   -22,   -22,     0,     0,     0,     0,
       0,     0,   -22,   -27,   -22,   -27,   -27,   -27,   -22,   -27,
     -27,   -27,   -27,   -27,     0,   -27,     0,   -27,   -27,   -27,
     -27,     0,   -27,   -27,   -27,   -27,     0,     0,     0,     0,
       0,     0,   -27,   -28,   -27,   -28,   -28,   -28,   -27,   -28,
     -28,   -28,   -28,   -28,     0,   -28,     0,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   -28,   -28,     0,     0,     0,     0,
       0,     0,   -28,   -29,   -28,   -29,   -29,   -29,   -28,   -29,
     -29,   -29,   -29,   -29,     0,   -29,     0,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,     0,     0,     0,     0,
       0,     0,   -29,   -23,   -29,   -23,   -23,   -23,   -29,   -23,
     -23,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,   -23,
     -23,     0,   -23,   -23,   -23,   -23,     0,     0,     0,     0,
       0,     0,   -23,   -24,   -23,   -24,   -24,   -24,   -23,   -24,
     -24,   -24,   -24,   -24,     0,   -24,     0,   -24,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,     0,     0,     0,     0,
       0,     0,   -24,   -25,   -24,   -25,   -25,   -25,   -24,   -25,
     -25,   -25,   -25,   -25,     0,   -25,     0,   -25,   -25,   -25,
     -25,     0,   -25,   -25,   -25,   -25,     0,     0,     0,     0,
       0,     0,   -25,   -53,   -25,   -53,   -53,   -53,   -25,   -53,
     -53,   -53,   -53,   -53,     0,   -53,     0,   -53,   -53,   -53,
     -53,     0,   -53,   -53,   -53,   -53,     0,     0,     0,     0,
       0,     0,   -53,   -26,   -53,   -26,   -26,   -26,   -53,   -26,
     -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,   -26,
     -26,     0,   -26,   -26,   -26,   -26,     0,     0,     0,     0,
       0,     0,   -26,   -32,   -26,   -32,   -32,   -32,   -26,   -32,
     -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,   -32,
     -32,     0,   -32,   -32,   -32,   -32,     0,     0,     0,     0,
       0,     0,   -32,   -52,   -32,   -52,   -52,   -52,   -32,   -52,
     -52,   -52,   -52,   -52,     0,   -52,     0,   -52,   -52,   -52,
     -52,     0,   -52,   -52,   -52,   -52,     0,     0,     0,     0,
       0,     0,   -52,   -31,   -52,   -31,   -31,   -31,   -52,   -31,
     -31,   -31,   -31,   -31,     0,   -31,     0,   -31,   -31,   -31,
     -31,     0,   -31,   -31,   -31,   -31,     0,     0,     0,     0,
       0,     0,   -31,   -51,   -31,   -51,   -51,   -51,   -31,   -51,
     -51,   -51,   -51,   -51,     0,   -51,     0,   -51,   -51,   -51,
     -51,     0,   -51,   -51,   -51,   -51,     0,     0,     0,     0,
       0,     0,   -51,   -48,   -51,   -48,   -48,   -48,   -51,   -48,
     -48,   -48,   -48,   -48,     0,   -48,     0,   -48,   -48,   -48,
     -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,     0,
       0,     0,   -48,   -42,   -48,   -42,   -42,   -42,   -48,   -42,
     -42,   -42,   -42,   -42,     0,   -42,     0,   -42,   -42,   -42,
     -42,     0,   -42,   -42,   -42,   -42,     0,     0,     0,     0,
       0,     0,   -42,   -43,   -42,   -43,   -43,   -43,   -42,   -43,
     -43,   -43,   -43,   -43,     0,   -43,     0,   -43,   -43,   -43,
     -43,     0,   -43,   -43,   -43,   -43,     0,     0,     0,     0,
       0,     0,   -43,   -44,   -43,   -44,   -44,   -44,   -43,   -44,
     -44,   -44,   -44,   -44,     0,   -44,     0,   -44,   -44,   -44,
     -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,     0,
       0,     0,   -44,   -45,   -44,   -45,   -45,   -45,   -44,   -45,
     -45,   -45,   -45,   -45,     0,   -45,     0,   -45,   -45,   -45,
     -45,     0,   -45,   -45,   -45,   -45,     0,     0,     0,     0,
       0,     0,   -45,   -46,   -45,   -46,   -46,   -46,   -45,   -46,
     -46,   -46,   -46,   -46,     0,   -46,     0,   -46,   -46,   -46,
     -46,     0,   -46,   -46,   -46,   -46,     0,     0,     0,     0,
       0,     0,   -46,   -47,   -46,   -47,   -47,   -47,   -46,   -47,
     -47,   -47,   -47,   -47,     0,   -47,     0,   -47,   -47,   -47,
     -47,     0,   -47,   -47,   -47,   -47,     0,     0,     0,     0,
       0,     0,   -47,   -50,   -47,   -50,   -50,   -50,   -47,   -50,
     -50,   -50,   -50,   -50,     0,   -50,     0,   -50,   -50,   -50,
     -50,     0,   -50,   -50,   -50,   -50,     0,     0,     0,     0,
       0,     0,   -50,    -9,   -50,    -9,    -9,    -9,   -50,    -9,
      -9,    -9,    -9,    -9,     0,    -9,     0,    -9,    -9,    -9,
      -9,     0,    -9,    -9,    -9,    -9,     0,     0,     0,     0,
       0,     0,    -9,   -16,    -9,   -16,   -16,   -16,    -9,   -16,
     -16,   -16,   -16,   -16,     0,   -16,     0,   -16,   -16,   -16,
     -16,     0,   -16,   -16,   -16,   -16,     0,     0,     0,     0,
       0,     0,   -16,   -17,   -16,   -17,   -17,   -17,   -16,   -17,
     -17,   -17,   -17,   -17,     0,   -17,     0,   -17,   -17,   -17,
     -17,     0,   -17,   -17,   -17,   -17,     0,     0,     0,     0,
       0,     0,   -17,    25,   -17,    26,    27,    28,   -17,    29,
      30,    31,    32,    33,     0,    34,     0,    35,    36,    37,
      38,     0,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,    43,    25,    44,    26,    27,    28,   316,    29,
      30,    31,    32,    33,     0,    34,     0,    35,    36,    37,
      38,     0,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,    43,   -18,    44,   -18,   -18,   -18,   318,   -18,
     -18,   -18,   -18,   -18,     0,   -18,     0,   -18,   -18,   -18,
     -18,     0,   -18,   -18,   -18,   -18,     0,     0,     0,     0,
       0,     0,   -18,   -49,   -18,   -49,   -49,   -49,   -18,   -49,
     -49,   -49,   -49,   -49,     0,   -49,     0,   -49,   -49,   -49,
     -49,     0,   -49,   -49,   -49,   -49,     0,     0,     0,     0,
       0,     0,   -49,    25,   -49,    26,    27,    28,   -49,    29,
      30,    31,    32,    33,     0,    34,     0,    35,    36,    37,
      38,     0,    39,    40,    41,    42,    26,    27,    28,     0,
      29,    30,    43,    32,    44,     0,     0,   226,   166,   167,
      37,    38,     0,   168,   169,    41,    42,   160,   161,   162,
       0,   163,   164,    43,   165,    44,     0,     0,     0,     0,
     -54,   166,   167,     0,     0,     0,   168,   169,   -55,   -54,
     -54,   -54,   -54,    63,   170,   -57,   171,   -55,   -55,   -55,
       0,     0,   -55,   -55,   -57,   -57,   -57,   -56,     0,   -57,
     -57,     0,     0,     0,   -67,     0,   -56,   -56,   -56,     0,
       0,   -56,   -56,   -67,   -67,   -67,   -60,     0,   -67,   -67,
       0,     0,   -37,     0,     0,   -60,   -60,   -60,   -58,     0,
     -60,   236,   237,   238,   -61,     0,   -37,   -58,   -58,   -58,
     -59,     0,   -58,   -61,   -61,   -61,   -55,     0,   -61,   -59,
     -59,   -59,   -57,     0,   -59,   -55,   -55,   -55,   -56,     0,
     -55,   -57,   -57,   -57,   -67,     0,   -57,   -56,   -56,   -56,
       0,   -54,   -56,   -67,   -67,   -67,     0,   -60,   -67,   -54,
     -54,   -54,   -54,   -54,    63,    82,   -60,   -60,   -60,   -60,
     -60,   184,   185,     0,   -63,     0,   186,   187,   274,   -60,
     -60,   -60,   -60,   -63,   -63,   -63,   -63,   -65,     0,     0,
       0,   -64,     0,     0,     0,   -66,   -65,   -65,   -65,   -65,
     -64,   -64,   -64,   -64,   -66,   -66,   -66,   -66,   -37,     0,
       0,     0,   -58,     0,     0,     0,   -61,    83,    84,    85,
     -37,   -58,   -58,   -58,   -58,   -61,   -61,   -61,   -61,   -60,
       0,     0,     0,   -59,     0,     0,     0,   -55,   -60,   -60,
     -60,   -60,   -59,   -59,   -59,   -59,   -55,   -55,   -55,   -55,
     -57,     0,     0,     0,   -56,     0,     0,     0,   -67,   -57,
     -57,   -57,   -57,   -56,   -56,   -56,   -56,   -67,   -67,   -67,
     -67,   -62,     0,     0,   -63,     0,     0,   -65,     0,     0,
     -62,   -62,   -62,   -63,   -63,   -63,   -65,   -65,   -65,   -64,
       0,     0,   -66,     0,     0,   -60,     0,     0,   -64,   -64,
     -64,   -66,   -66,   -66,   -60,   -60,   -60,   -37,     0,     0,
     -58,     0,     0,   -61,     0,     0,   256,   257,   258,   -58,
     -58,   -58,   -61,   -61,   -61,   -59,     0,     0,   -55,     0,
       0,   -57,     0,     0,   -59,   -59,   -59,   -55,   -55,   -55,
     -57,   -57,   -57,   -56,     0,     0,   -67,     0,     0,     0,
       0,     0,   -56,   -56,   -56,   -67,   -67,   -67
};

static const yytype_int16 yycheck[] =
{
       0,    23,    82,    18,     4,     9,    19,   229,    31,    32,
     113,   114,    34,   113,    19,     0,   113,   239,   113,   214,
      33,    34,    44,   114,     9,    19,    31,   249,   113,    33,
      19,   226,    19,   113,     0,   138,   113,   259,   113,    33,
      34,    63,    64,    19,    33,    34,    33,   138,    70,    10,
      19,    73,    74,     0,    76,    32,    19,    33,    80,    10,
      82,    83,    84,    85,    33,     1,    19,     3,     4,     5,
      33,     7,     8,     9,    10,    11,    12,    13,    31,    15,
      16,    17,    18,    33,    20,    21,    22,    23,    19,   111,
      35,   113,   114,     9,    30,    10,    32,    10,    19,   114,
      36,    19,    33,    34,     3,     4,     5,     6,     7,     8,
      32,    10,    33,   113,    23,    33,   138,     3,     4,     5,
      32,     7,     8,   138,    10,    34,    25,    19,    19,    19,
     152,    17,    18,    32,    19,    44,    22,    23,    19,    19,
      31,    33,    34,    33,    30,    32,    32,    33,    33,   171,
      19,    31,    33,    34,    63,    64,     3,     4,     5,     6,
       7,     8,    31,    10,    73,    74,    19,   189,     0,     1,
      19,    80,    32,    82,    83,    84,    85,     9,    25,   201,
      33,    34,   204,   205,    33,    32,    19,   209,    32,    19,
      32,     3,     4,     5,   274,     7,     8,    19,    10,    19,
      33,    34,   111,    33,   113,   114,    19,   229,    19,    31,
       0,   233,    31,    33,   236,   237,   238,   239,    31,     9,
      32,   243,    33,    34,   246,   247,   248,   249,    32,   138,
      32,   253,   335,   336,    32,   335,   336,   259,   335,   336,
     335,   336,   264,   152,   335,   336,   268,   269,   270,   271,
     335,   336,   274,   275,    19,   335,   336,    33,   335,   336,
     335,   336,   171,    28,    29,    30,    19,    32,    33,    34,
       3,     4,     5,    19,     7,     8,    19,    10,    31,    19,
     189,    10,    19,    33,    17,    18,    33,    33,    31,    22,
      23,    19,   201,    33,    31,   204,   205,    30,    31,    32,
     209,    19,     3,     4,     5,     6,     7,     8,    19,    10,
      28,    29,    30,   335,   336,    33,    34,    28,    29,    30,
     229,    32,    33,    23,    25,    33,    34,   236,   237,   238,
     239,    32,    19,    19,    34,   335,   336,   246,   247,   248,
     249,    28,    29,    30,    44,    31,    33,   256,   257,   258,
     259,    33,     3,     4,     5,   264,     7,     8,    19,    10,
     269,   270,   271,    63,    64,   274,   275,    28,    29,    30,
       0,    33,    33,    73,    74,    19,    33,    19,    33,     9,
      80,    32,    82,    83,    84,    85,     1,    31,     3,     4,
       5,    33,     7,     8,     9,    10,    11,    12,    13,    33,
      15,    16,    17,    18,    33,    20,    21,    22,    23,    19,
      19,   111,    33,   113,   114,    30,    33,    32,    28,    29,
      30,    36,    31,    33,    34,    23,   335,   336,     3,     4,
       5,    31,     7,     8,    31,    10,    34,    19,   138,    19,
      19,     0,    17,    18,    31,    43,    44,    22,    23,    19,
       9,    33,   152,    33,    33,    30,    31,    32,    28,    29,
      30,     0,    19,    33,    34,    63,    64,    19,    31,    19,
       9,   171,    19,     3,     4,     5,    33,     7,     8,    19,
      10,    33,    80,    33,    82,    19,    33,    17,    18,   189,
      31,    31,    22,    23,    28,    29,    30,    19,    31,    33,
      30,   201,    32,    19,   204,   205,    28,    29,    30,   209,
      31,    33,    34,   111,    33,   113,   114,    33,    19,    19,
      19,     3,     4,     5,     6,     7,     8,    19,    10,   229,
      19,    19,    33,    33,    33,    32,   236,   237,   238,   239,
     138,    33,    32,    25,    33,    33,   246,   247,   248,   249,
      32,    19,    32,   151,   152,    32,     3,     4,     5,   259,
       7,     8,    32,    10,   264,    33,    32,    19,    23,   269,
     270,   271,   170,   171,   274,   275,    28,    29,    30,    34,
      32,    23,    33,    34,     0,    32,    32,    33,     0,    44,
     188,   189,    34,     9,     3,     4,     5,     9,     7,     8,
      32,    10,    44,   201,    19,    32,   204,   205,    63,    64,
      32,   209,    32,    28,    29,    30,    19,     0,    33,    34,
      33,    63,    64,    32,    32,    80,     9,    82,    33,    34,
      32,   229,    33,    19,    33,   335,   336,    33,    80,    33,
      82,   239,    28,    29,    30,    33,    33,    33,    34,    17,
      18,   249,    10,    19,    22,    23,   111,    32,   113,   114,
      32,   259,    28,    29,    30,    32,   264,    33,    34,   111,
      32,   113,   114,   271,    19,    19,   274,   275,    32,    31,
      33,    44,    33,   138,    28,    29,    30,    33,    19,    33,
      34,    33,    33,    19,    33,    33,   138,   152,    33,    33,
      63,    64,    28,    29,    30,    33,    69,    33,    71,    72,
     152,     1,    75,     3,     4,     5,   171,     7,     8,     9,
      10,    11,    33,    13,    33,    15,    16,    17,    18,   171,
      20,    21,    22,    23,   189,    33,    33,   335,   336,    33,
      30,    19,    32,    19,    19,    35,   201,   189,   111,   204,
     205,     3,     4,     5,   209,     7,     8,    31,    10,   201,
      33,    31,   204,   205,    31,    17,    18,   209,    31,    31,
      22,    23,    31,    31,   229,     4,    -1,    -1,    30,   111,
      32,    19,    -1,    -1,   239,    -1,    -1,   229,    -1,   152,
      28,    29,    30,    -1,   249,    33,    34,   239,    -1,    -1,
      -1,    19,    -1,    -1,   259,    -1,    -1,   249,   171,   264,
      28,    29,    30,    -1,    -1,    33,   271,   259,    -1,   274,
     275,    -1,   264,    -1,    -1,    19,   189,    -1,    -1,   271,
      -1,    -1,   274,   275,    28,    29,    30,    -1,   201,    33,
      34,   204,   205,     3,     4,     5,    -1,     7,     8,    -1,
      10,    -1,    -1,    -1,    17,    18,    -1,    17,    18,    22,
      23,    -1,    22,    23,    -1,    -1,   229,   230,   231,   232,
      30,    -1,    32,    19,    -1,    -1,   239,   240,   241,   242,
     335,   336,    28,    29,    30,    31,   249,   250,   251,   252,
      -1,    -1,    -1,   335,   336,    -1,   259,    -1,    -1,    -1,
      -1,   264,    -1,     1,   267,     3,     4,     5,    -1,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    12,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     1,    32,     3,     4,     5,    36,     7,
       8,     9,    10,    11,    -1,    13,    -1,    15,    16,    17,
      18,    -1,    20,    21,    22,    23,     3,     4,     5,    -1,
       7,     8,    30,    10,    32,    -1,    -1,    35,    17,    18,
      17,    18,    -1,    22,    23,    22,    23,     3,     4,     5,
      -1,     7,     8,    30,    10,    32,    -1,    -1,    -1,    -1,
      19,    17,    18,    -1,    -1,    -1,    22,    23,    19,    28,
      29,    30,    31,    32,    30,    19,    32,    28,    29,    30,
      -1,    -1,    33,    34,    28,    29,    30,    19,    -1,    33,
      34,    -1,    -1,    -1,    19,    -1,    28,    29,    30,    -1,
      -1,    33,    34,    28,    29,    30,    19,    -1,    33,    34,
      -1,    -1,    19,    -1,    -1,    28,    29,    30,    19,    -1,
      33,    28,    29,    30,    19,    -1,    33,    28,    29,    30,
      19,    -1,    33,    28,    29,    30,    19,    -1,    33,    28,
      29,    30,    19,    -1,    33,    28,    29,    30,    19,    -1,
      33,    28,    29,    30,    19,    -1,    33,    28,    29,    30,
      -1,    19,    33,    28,    29,    30,    -1,    19,    33,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      19,    17,    18,    -1,    19,    -1,    22,    23,    27,    28,
      29,    30,    31,    28,    29,    30,    31,    19,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    19,    28,    29,    30,    31,
      28,    29,    30,    31,    28,    29,    30,    31,    19,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    19,    28,    29,    30,
      31,    28,    29,    30,    31,    28,    29,    30,    31,    19,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    19,    28,    29,
      30,    31,    28,    29,    30,    31,    28,    29,    30,    31,
      19,    -1,    -1,    -1,    19,    -1,    -1,    -1,    19,    28,
      29,    30,    31,    28,    29,    30,    31,    28,    29,    30,
      31,    19,    -1,    -1,    19,    -1,    -1,    19,    -1,    -1,
      28,    29,    30,    28,    29,    30,    28,    29,    30,    19,
      -1,    -1,    19,    -1,    -1,    19,    -1,    -1,    28,    29,
      30,    28,    29,    30,    28,    29,    30,    19,    -1,    -1,
      19,    -1,    -1,    19,    -1,    -1,    28,    29,    30,    28,
      29,    30,    28,    29,    30,    19,    -1,    -1,    19,    -1,
      -1,    19,    -1,    -1,    28,    29,    30,    28,    29,    30,
      28,    29,    30,    19,    -1,    -1,    19,    -1,    -1,    -1,
      -1,    -1,    28,    29,    30,    28,    29,    30
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
      31,    51,    52,    10,    59,    52,    52,     6,    25,    61,
       6,    25,    61,    52,    59,    33,    51,    49,    61,    61,
      61,    34,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    64,    45,    46,    48,
      45,    31,    31,    31,    31,    31,    31,    31,    12,    45,
      10,     3,     4,     5,     7,     8,    10,    17,    18,    22,
      23,    30,    32,    50,    52,    59,    60,    61,    62,    31,
       3,     4,     5,     7,     8,    10,    17,    18,    22,    23,
      30,    32,    50,    52,    59,    60,    61,    62,     3,     4,
       5,     7,     8,    10,    17,    18,    22,    23,    30,    32,
      50,    59,    60,    61,    62,     3,     4,     5,     7,     8,
      10,    32,    59,    62,    19,    19,     1,     9,    11,    13,
      15,    16,    20,    21,    35,    40,    49,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    35,    46,    48,    32,
      32,    32,    32,    32,    50,    51,    28,    29,    30,    32,
      32,    32,    32,    32,    50,    51,    28,    29,    30,    32,
      32,    32,    32,    32,    50,    51,    28,    29,    30,    32,
      51,    51,    51,    10,    32,    31,    51,    32,    32,    32,
      32,    47,    31,    31,    27,    47,    63,    52,    52,    52,
      59,    33,    61,    61,    61,    63,    52,    52,    52,    59,
      33,    61,    61,    61,    63,    52,    52,    52,    59,    33,
      61,    61,    61,    63,    33,    31,    51,    31,    52,    59,
       6,    25,    61,     6,    25,    61,    36,    49,    36,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    45,    45,    31,    31,    31,    31,
      31,    31,    31
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    39,    39,    39,    40,
      42,    41,    43,    43,    44,    44,    45,    45,    46,    47,
      47,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    51,    51,
      51,    52,    53,    53,    53,    54,    54,    54,    55,    56,
      56,    57,    58,    58,    59,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    61,    61,    61,    62,    63,    63,
      64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     0,     3,
       0,     7,     1,     0,     4,     2,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     2,     4,     4,     4,     4,     1,     2,     1,
       1,     3,     5,     5,     5,     5,     5,     5,     5,     5,
       7,     5,     3,     2,     1,     3,     3,     3,     1,     3,
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
#line 113 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
        check_semantic_error_no_main();
    }
#line 2063 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 117 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2069 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 121 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2085 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 127 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2093 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 130 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 133 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
    }
#line 2109 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 139 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), "variable");
    }
#line 2118 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 146 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "function");
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2136 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2144 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2152 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 166 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 170 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2170 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 176 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2186 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 185 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("COMPOUND_STATEMENT", (yyvsp[-1].node), NULL , NULL, NULL);
    }
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 191 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2202 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 194 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2210 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2218 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 203 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2226 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 206 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2234 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 209 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2242 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 212 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 215 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2258 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 218 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2266 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 221 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2274 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 224 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2282 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 227 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
        yyerrok;
    }
#line 2291 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 234 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
         define_type((yyval.node));
    }
#line 2300 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 238 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2308 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2316 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 247 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2324 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 250 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 253 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2340 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 259 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 262 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 265 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 268 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 274 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 280 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2388 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 283 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 286 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2404 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 292 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 295 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 298 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2428 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 304 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 310 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 313 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT_ELSE", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2453 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 320 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 326 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
        define_type((yyval.node));
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2471 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 331 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 338 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[0].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("VARIABLE", NULL, NULL, type, (yyvsp[0].token));
    }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 349 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        define_type((yyval.node));
    }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 353 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        define_type((yyval.node));
    }
#line 2511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 357 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
        define_type((yyval.node));
    }
#line 2520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 361 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2528 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 367 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 370 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 373 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2552 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 376 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 379 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 382 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ELEM", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2576 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 385 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("SET", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 388 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("EMPTY_VALUE", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 2592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 394 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[-3].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, type, (yyvsp[-3].token));
        check_semantic_error_type_mismatch_args((yyvsp[-1].node), (yyvsp[-3].token));
    }
#line 2606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 406 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 409 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 2622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 415 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 2630 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 418 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2638 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2642 "parser.tab.c" /* yacc.c:1646  */
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
#line 423 "parser.y" /* yacc.c:1906  */


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
    HASH_FIND_STR(symbol_table, key, s);
    if(s == NULL){
        s = create_symbol(key, name, type, symbol_type, scope->scope_name);
        HASH_ADD_STR(symbol_table, key, s);
    }
    else{
        semantic_error_redeclared_variable(name, scope->scope_name);
    }
}

// Procura símbolo na tabela de símbolos
symbol_node* search_for_symbol(char* name) {
    symbol_node *s;
    scope* scope = get_stack_head();
    char *key = concat_string(name, scope->scope_name);
    HASH_FIND_STR(symbol_table, key, s);
    if(
        s == NULL && 
        (strcmp(scope->scope_name, "global") != 0)
    ){
        scope = stack;
        key = concat_string(name, scope->scope_name);
        HASH_FIND_STR(symbol_table, key, s);
    }
    if(s == NULL){
        semantic_error_not_declared_variable(name);
    }
    return s;
}


// Adiciona nó de conversão implícita na árvore.
void implicit_conversion(node *no, char* func_type){
    node* conversion_node;
    if(strcmp(no->class, "RETURN_STATEMENT") == 0){
        if(strcmp(no->left->type, "int") == 0 && strcmp(func_type, "float") == 0){
            conversion_node = create_tree_node("INT_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }
        else if(strcmp(no->left->type, "float") == 0 && strcmp(func_type, "int") == 0){
            conversion_node = create_tree_node("FLOAT_TO_INT", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        }
        else if(strcmp(no->left->type, "elem") == 0 && strcmp(func_type, "int") == 0){
            conversion_node = create_tree_node("INTEGER", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        }
        else if(strcmp(no->left->type, "elem") == 0 && strcmp(func_type, "float") == 0){
            conversion_node = create_tree_node("FLOATNUMBER", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        }
        else if(strcmp(no->left->type, "int") == 0 && strcmp(func_type, "elem") == 0){
            conversion_node = create_tree_node("INTEGER", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        }
        else if(strcmp(no->left->type, "float") == 0 && strcmp(func_type, "elem") == 0){
            conversion_node = create_tree_node("FLOATNUMBER", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        } 
    }
    else{
        if(strcmp(no->class, "ASSIGN_EXPRESSION") == 0){
            if(strcmp(no->left->type, "int") == 0 && strcmp(no->right->type, "float") == 0){
                conversion_node = create_tree_node("FLOAT_TO_INT", no->right, NULL, "int", NULL); 
                no->right = conversion_node;
            }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "int") == 0){
                conversion_node = create_tree_node("INT_TO_FLOAT", no->left, NULL, "float", NULL);
                no->left = conversion_node;
            }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "elem") == 0){
                conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
                no->left = conversion_node;
            }else if (strcmp(no->left->type, "int") == 0 && strcmp(no->right->type, "elem") == 0){
                conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
                no->left = conversion_node;
            }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "int") == 0){
                conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
                no->left = conversion_node;
            }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "float") == 0){
                conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
                no->left = conversion_node;
            }
        }
        else {
            conversion_node = create_tree_node("INT_TO_FLOAT", no->right, NULL, "float", NULL);
            no->right = conversion_node;
        }
    }
}

// Define tipo para nó da árvore checando os nós de cada lado
void define_type(node* node){
    char* type_left = NULL;
    char* type_right = NULL;
    if(node->left != NULL){
        type_left = node->left->type;
    }
    if(node->right != NULL){
        type_right = node->right->type;
    }
    if(type_left != NULL && type_right != NULL && strcmp(type_left, type_right) != 0){ 
        if(
            (strcmp(type_left, "int") == 0 && strcmp(type_right, "float") == 0) || 
            (strcmp(type_left, "float") == 0 && strcmp(type_right, "int") == 0) || 
            (strcmp(type_left, "elem") == 0 && strcmp(type_right, "int") == 0) ||
            (strcmp(type_left, "elem") == 0 && strcmp(type_right, "float") == 0) ||
            (strcmp(type_left, "float") == 0 && strcmp(type_right, "elem") == 0) ||
            (strcmp(type_left, "int") == 0 && strcmp(type_right, "elem") == 0)
        ){
            implicit_conversion(node, NULL);
            type_left = node->left->type;
        } else if (strcmp(node->class, "ARITHIMETIC_EXPRESSION") == 0 && (strcmp(type_left, "set") == 0 || strcmp(type_right, "set") == 0)){
            semantic_error_set_arith_op();
        }
        else{
            semantic_error_type_mismatch(node->left->value, node->right->value, type_left, type_right);
        }
    }
    node->type = type_left;
}


void check_semantic_error_return_type(char* return_type, node* no){
    symbol_node *s;
    scope* scope = get_stack_head();
    char* function_name = scope->scope_name;
    char* key = concat_string(function_name, stack->scope_name);
    HASH_FIND_STR(symbol_table, key, s);
    if(s != NULL){
        if(strcmp(return_type, s->type) != 0){
            if(
                (strcmp(return_type, "int") == 0 && strcmp(s->type, "float") == 0) || 
                (strcmp(return_type, "float") == 0 && strcmp(s->type, "int") == 0) || 
                (strcmp(return_type, "elem") == 0 && strcmp(s->type, "int") == 0) ||
                (strcmp(return_type, "elem") == 0 && strcmp(s->type, "float") == 0) ||
                (strcmp(return_type, "float") == 0 && strcmp(s->type, "elem") == 0) ||
                (strcmp(return_type, "int") == 0 && strcmp(s->type, "elem") == 0)
            ){
                implicit_conversion(no, s->type);
                no->type = no->left->type;
            }
            else{
                semantic_error_return_type(return_type, s->type);
            }
        }
    }
}

// Checa erro semântico de main não declarada
void check_semantic_error_no_main(){
    symbol_node* s;
    char* key = concat_string("main", stack->scope_name);
    HASH_FIND_STR(symbol_table, key, s);
    if(s == NULL){
        semantic_error_no_main();
    }
}

// Cria lista de argumentos a partir de um nó da árvore
args_node* create_args_list(node* no){
    args_node* args_list = NULL;
    args_node* arg_atual = NULL;
    node* no_atual = no;

    // Monta lista de argumentos
    if(no != NULL){
        if(strcmp(no_atual->class, "ARGS_LIST") == 0){
            while(strcmp(no_atual->class, "ARGS_LIST") == 0){
                args_node *a = (args_node *)malloc(sizeof *a);
                a->name = no_atual->left->value;
                a->type = no_atual->left->type;
                a->next = NULL;
                if(args_list == NULL){
                    args_list = a;
                    arg_atual = args_list;
                }
                else{
                    arg_atual->next = a;
                    arg_atual = arg_atual-> next;
                }
                if(strcmp(no_atual->right->class, "ARGS_LIST") != 0){
                    args_node *a = (args_node *)malloc(sizeof *a);
                    a->name = no_atual->right->value;
                    a->type = no_atual->right->type;
                    a->next = NULL;
                    arg_atual->next = a;
                    arg_atual = arg_atual-> next;
                }
                no_atual = no_atual->right;
            }
        }
        else{
            args_node *a = (args_node *)malloc(sizeof *a);
            a->name = no->value;
            a->type = no->type;
            a->next = NULL;
            args_list = a;
        }
    }
    return args_list;
}

// Checa erro semântico de tipo incompatível para argumentos
void check_semantic_error_type_mismatch_args(node* no, char* function_name){
    args_node* args_list = create_args_list(no);
    args_node* arg_atual = NULL;
    int number_args = 0;
    int number_param = 0;
    param_node* param_list = NULL;
    param_node* param_atual = NULL;

    symbol_node* f;
    char* key = concat_string(function_name, stack->scope_name);
    HASH_FIND_STR(symbol_table, key, f);
    if(f != NULL){
        param_list = f->param_list;
    }

    arg_atual = args_list;
    while(arg_atual != NULL){
        number_args++;
        arg_atual = arg_atual->next;
    }
    param_atual = param_list;
    while(param_atual != NULL){
        number_param++;
        param_atual = param_atual->next;
    }

    if(number_args != number_param){
        semantic_error_wrong_number_arguments(function_name, number_args, number_param);
    }
    else{
        symbol_node* s;
        arg_atual = args_list;
        param_atual = param_list;
        int direction;
        node* aux;
        int i = 0;
        while(arg_atual != NULL){
            HASH_FIND_STR(symbol_table, param_atual->key, s);
            if(s != NULL){
                if(
                    arg_atual->type != NULL &&
                    s->type != NULL &&
                    (strcmp(arg_atual->type, s->type) != 0)
                ){
                    if(
                        (strcmp(arg_atual->type, "int") == 0 && strcmp(s->type, "float") == 0) || 
                        (strcmp(arg_atual->type, "float") == 0 && strcmp(s->type, "int") == 0) ||
                        (strcmp(arg_atual->type, "elem") == 0 && strcmp(s->type, "int") == 0) ||
                        (strcmp(arg_atual->type, "elem") == 0 && strcmp(s->type, "float") == 0) ||
                        (strcmp(arg_atual->type, "float") == 0 && strcmp(s->type, "elem") == 0) ||
                        (strcmp(arg_atual->type, "int") == 0 && strcmp(s->type, "elem") == 0)
                    ){
                        aux = find_arg(no, i, number_args, &direction);
                        implicit_args_conversion(aux, s->type, direction);
                    }
                    else{
                        semantic_error_type_mismatch_args(function_name, arg_atual->name, arg_atual->type, s->name, s->type);
                    }
                }
            }
            arg_atual = arg_atual->next;
            param_atual = param_atual->next;
            i++;
        }
    }
}

// Adiciona nó de conversão implícita na árvore para argumentos.
void implicit_args_conversion(node *no, char* expected_type, int direction){
    node* conversion_node;
    if(direction == 0){
        if(strcmp(no->left->type, "int") == 0 && strcmp(expected_type, "float") == 0){
            conversion_node = create_tree_node("INT_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "int") == 0){
            conversion_node = create_tree_node("INT_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "elem") == 0){
            conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "int") == 0 && strcmp(no->right->type, "elem") == 0){
            conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "int") == 0){
            conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "float") == 0){
            conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }
        else{
            conversion_node = create_tree_node("FLOAT_TO_INT", no->left, NULL, "int", NULL); 
            no->left = conversion_node;
        }
    }
    else{
        if(strcmp(no->right->type, "int") == 0 && strcmp(expected_type, "float") == 0){
            conversion_node = create_tree_node("INT_TO_FLOAT", no->right, NULL, "float", NULL);
            no->right = conversion_node;
         }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "int") == 0){
            conversion_node = create_tree_node("INT_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "float") == 0 && strcmp(no->right->type, "elem") == 0){
            conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "int") == 0 && strcmp(no->right->type, "elem") == 0){
            conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "int") == 0){
            conversion_node = create_tree_node("ELEM_TO_INT", no->left, NULL, "int", NULL);
            no->left = conversion_node;
        }else if (strcmp(no->left->type, "elem") == 0 && strcmp(no->right->type, "float") == 0){
            conversion_node = create_tree_node("ELEM_TO_FLOAT", no->left, NULL, "float", NULL);
            no->left = conversion_node;
        }
        else{
            conversion_node = create_tree_node("FLOAT_TO_INT", no->right, NULL, "int", NULL); 
            no->right = conversion_node;
        }
    }
    
}

// Retorno o no da árvore do argumento da posição i
node* find_arg(node* no, int i, int number_args, int* direction){
    int j;
    node* aux = no;
    if((i == number_args - 1) && (i != 0)){

        j = i - 1;
    }
    else{
        j = i;
    }
    while(j > 0){
        aux = aux->right;
        j--;
    }
    if((i == number_args - 1) && (i != 0)){
        *direction = 1;
        return aux;
    }
    else{
        *direction = 0;
        return aux;
    }
}

// Erro semântico redeclaração de variável
void semantic_error_redeclared_variable(char* name, char* scope){
    char *error = (char *)malloc((strlen(name) + strlen(scope) + 46) * sizeof(char));
    sprintf(error, "semantic error, %s was already declared in %s", name, scope);
    yyerror(error);
    free(error);
}

// Erro semântico variável não declarada
void semantic_error_not_declared_variable(char* name){
    char *error = (char *)malloc((strlen(name) + 36) * sizeof(char));
    sprintf(error, "semantic error, %s was not declared", name);
    yyerror(error);
    free(error);
}

// Erro semântico de main não declarada
void semantic_error_no_main(){
    char *error = (char *)malloc(
        (1 + 47) * sizeof(char)
    );
    sprintf(error, "semantic error, no declaration of function main");
    yyerror(error);
    free(error);
}


// Erro semântico de tipo incompatível
void semantic_error_type_mismatch(char* value_left, char* value_right, char* type_left, char* type_right){
    char *error = (char *)malloc(
        (strlen(value_right) + strlen(value_left) + strlen(type_left) + strlen(type_right) + 56) * sizeof(char)
    );
    sprintf(error, "semantic error, type mismatch between %s of type %s and %s of type %s", value_left, type_left, value_right, type_right);
    yyerror(error);
    free(error);
}

// Erro semântico de aritmética do tipo SET
void semantic_error_set_arith_op() {
    char *error = (char *)malloc(60 * sizeof(char));
    sprintf(error, "semantic error, cannot do arithmetic operation with type set");
    yyerror(error);
    free(error);
}

// Erro semântico de tipo de retorno diferente de tipo da função
void semantic_error_return_type(char* return_type, char* type){
    char *error = (char *)malloc(
        (strlen(type) + strlen(return_type) + 52) * sizeof(char)
    );
    sprintf(error, "semantic error, return of type %s, expected type %s", return_type, type);
    yyerror(error);
    free(error);
}


// Erro semântico de numero de argumentos errado
void semantic_error_wrong_number_arguments(char* function_name, int number_args, int number_param){
    char *error = (char *)malloc(
        (strlen(function_name) + 71) * sizeof(char)
    );
    sprintf(error, "semantic error, call of function (%s) with %d arguments, expected %d", function_name, number_args, number_param);
    yyerror(error);
    free(error);
}

// Erro semântico de tipo incompatível entre arg e params
void semantic_error_type_mismatch_args(char* function_name, char* arg_name, char* type_arg, char* param_name, char* type_param){
    char *error = (char *)malloc(
        (strlen(function_name) + strlen(type_param) + strlen(type_arg) + strlen(arg_name) + strlen(param_name) + 118) * sizeof(char)
    );
    sprintf(error, "semantic error, type mismatch between argument (%s) of type %s and param (%s) of type %s during call of function (%s)", arg_name, type_arg, param_name, type_param, function_name);
    yyerror(error);
    free(error);
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
