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
int aux_register = 0;

typedef struct node {
    char* class;  
    struct node* left;
    struct node* right;
    char* type;
    char* value;
    char* instruction;
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


#line 160 "parser.tab.c" /* yacc.c:339  */

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
    OR = 282,
    AND = 283,
    NOT = 284,
    ASSIGN = 285,
    L = 286,
    G = 287,
    EQ = 288,
    NE = 289,
    LE = 290,
    GE = 291,
    ADD_OP = 292,
    SUB = 293,
    MULT = 294,
    DIV = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 97 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 246 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   4939

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  370

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      42,    43,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   121,   125,   128,   131,   134,   137,   143,
     150,   150,   161,   164,   170,   174,   180,   183,   189,   195,
     198,   204,   207,   210,   213,   216,   219,   222,   225,   228,
     231,   238,   242,   248,   251,   254,   257,   263,   266,   269,
     272,   278,   284,   287,   290,   296,   299,   302,   308,   314,
     317,   324,   330,   335,   342,   353,   357,   361,   365,   368,
     373,   375,   377,   379,   384,   386,   388,   390,   392,   394,
     399,   401,   403,   411,   414,   417,   420,   423,   426,   429,
     432,   438,   450,   453,   459,   462
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
  "CHAR", "THEN", "OR", "AND", "NOT", "ASSIGN", "L", "G", "EQ", "NE", "LE",
  "GE", "ADD_OP", "SUB", "MULT", "DIV", "';'", "'('", "')'", "','", "'{'",
  "'}'", "$accept", "program", "declaration-list", "variable-declaration",
  "function", "$@1", "params-list", "params", "compound-inline",
  "compound-stmt", "stmt-list", "stmt", "expr", "set-func", "simple-expr",
  "in-stmt", "write-stmt", "writeln-stmt", "read-stmt", "conditional-stmt",
  "iteration-stmt", "return-stmt", "var", "op-expr", "OP", "RELOP", "LOG",
  "term", "call", "args", "arg-list", YY_NULLPTR
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
     295,    59,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF -197

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-197)))

#define YYTABLE_NINF -86

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     122,    11,     4,    62,    15,   112,   160,   -24,  -197,   214,
     215,   218,    36,    -4,    87,    29,   -12,   128,    66,   116,
     923,   376,   141,  2014,   230,  2054,  4246,  4269,  4292,  4315,
    4338,   164,  4130,   119,   388,   137,   174,   180,   184,   186,
     226,   239,   242,  3366,   319,   403,  2094,  2134,  2174,   -13,
      25,    30,  2214,  2254,  2294,  2334,  2374,  2414,  4200,  4361,
    4384,  4407,   135,   275,   319,  2454,   100,   113,  4430,   553,
     309,   553,   553,   142,   430,   553,   309,   167,  4453,    -3,
    2494,   623,  2534,   811,    60,   195,   298,   454,   666,   677,
     710,   731,   739,   758,   780,   834,   880,   999,   999,   999,
      -9,   244,   257,    10,  2574,   302,    31,   282,   285,    91,
      99,   289,   329,   344,   359,   365,   372,   121,   373,  4476,
     194,  2614,  4499,  4522,  4545,   950,  4568,  3294,  3337,   381,
     297,   340,   386,   387,   390,   391,   398,   400,   363,   378,
     404,    78,   857,  1014,  2654,  2694,  2734,  2774,  2814,  2854,
    2894,  2934,  3337,  2974,  4154,  3800,  3822,  3844,  3866,  3888,
    3778,   408,   410,   414,   418,  3387,   319,   140,   149,  3910,
    3932,  3954,  3976,  3014,  3448,  3470,  3492,  3514,  3536,  3426,
     423,   439,   443,   444,  3408,   319,    65,    73,  3558,  3580,
    3602,  3624,  4591,  4613,  4635,  4657,  4679,  4178,   445,   451,
     455,   456,  3429,   319,   427,  4701,  4723,  4745,  4767,   406,
     457,   459,   464,   465,   371,   319,   466,   469,   319,   950,
    1054,   489,   473,   472,   474,   476,   477,   478,   923,  1094,
    1134,   401,   402,  1174,  1214,  1254,  1294,  1334,  1374,  4223,
     923,  3054,  3094,   275,   553,   553,   553,   309,   161,  3998,
     166,  1042,  1042,  1042,   275,   553,   553,   553,   309,    85,
    3646,   168,  1082,  1082,  1082,   275,   553,   553,   553,   309,
     503,  4789,   169,  1122,  1122,  1122,   275,   243,   248,    95,
     484,   319,  1414,   407,   553,   309,   463,   530,  3134,  1454,
    1494,   811,  3174,   481,   256,   269,   270,   485,  4020,  4042,
    4064,  4086,   487,   271,   277,   290,   488,  3668,  3690,  3712,
    3734,   496,   315,   320,   328,   499,  4811,  4833,  4855,  4877,
     500,   505,  1534,   331,  1574,   332,   507,   508,   509,   510,
     511,   516,   519,  1614,  1654,  3214,  4108,   343,   345,   358,
     375,  3756,   114,   134,   151,   163,  4899,   513,   554,   555,
     562,   540,  3294,  3294,   543,   544,   545,   546,   552,   556,
     557,  3254,  1694,  1734,  1774,  1814,  1854,  1894,  1934,  1974
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,  -197,     0,   522,  -197,  -197,  -197,   -92,   -15,
    -183,  -119,   -81,   440,   483,   732,  -114,  -107,  -104,  -102,
    -100,   -97,   -22,   628,  -163,  -151,  -133,    92,   326,  -196,
     471
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    46,     6,    12,    15,    16,   141,   142,
      23,    47,    48,   204,   105,    51,    52,    53,    54,    55,
      56,    57,   205,   206,    97,    98,    99,   207,   208,   101,
     102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    58,   121,    21,     9,    14,   -39,   251,   143,   242,
     219,    -3,    68,   233,     7,    -2,   218,    11,   -10,   252,
     234,    68,   169,   235,     2,   236,   262,   237,    80,   218,
     238,   -12,    19,   242,   -85,   125,   144,   253,   263,   -13,
     119,   188,   169,   273,    81,   288,   230,   293,   108,   -40,
     -40,   216,   216,   127,   118,   274,   264,   292,   302,    68,
     153,    58,     8,   -70,   -70,   -70,    82,   -70,   -70,   311,
     -70,   -40,    18,   275,   128,    68,    68,    68,    13,   -49,
     320,   -49,   -49,   -49,   -39,   -49,   -49,   -49,   -49,   -49,
     152,   -49,   -40,   -49,   -49,   -49,   -49,    17,   -49,   -49,
     -49,   -49,   -70,   188,   -38,   239,    58,   -49,   -39,   -39,
     -40,    20,    -5,   241,   219,    60,   -40,   -40,   -40,   -39,
     -49,    -5,    -8,     1,   -49,    22,    60,   229,   -38,   -38,
      58,     2,    81,   -33,   130,    78,   171,   241,   -41,   -41,
     -40,   -39,   131,   169,   169,   209,   210,   211,   111,   212,
     213,    24,   214,   -34,   104,   190,   171,   -33,   -33,   -39,
      -7,    64,   188,   169,   138,   113,   116,   112,   -40,    -7,
     -35,   -15,   -15,    60,    62,    60,   173,   -34,   -34,    69,
     -38,   169,   -36,   -39,   215,   218,   -38,   218,   218,   122,
     123,   124,   -40,   169,   -35,   -35,   169,   188,   -71,   -71,
     -71,    68,   -71,   -71,   -38,   -71,   -36,   -36,   -38,   298,
     334,   307,   316,    81,    -4,    -6,    70,   190,    -9,    60,
      60,   188,    71,    -4,    -6,   297,    72,    -9,    73,   169,
     169,   169,   188,   143,   143,   -41,   306,   -71,   233,   233,
     188,   188,   188,   188,    60,   234,   234,   315,   235,   235,
     236,   236,   237,   237,   188,   238,   238,   249,   171,   169,
     361,   362,   218,   326,   216,   216,    58,   218,    74,   239,
      58,   230,   230,   -14,   -14,   -40,   260,   171,   174,   175,
     176,    75,   177,   178,    76,   179,   321,   126,   -40,   -40,
     -40,   -41,   180,   181,   271,   171,   -40,   182,   183,   337,
     -82,   -72,   -72,   -72,   184,   -72,   -72,   171,   -72,   -40,
     171,   190,   338,   339,   342,    60,   -33,   185,   -83,   107,
     343,   218,   155,   156,   157,   -54,   158,   159,   129,   160,
     239,   239,   132,   344,   -40,   190,   161,   162,   -33,   -40,
     -72,   163,   164,   299,   300,   301,   190,   -40,   165,    61,
     218,   -40,   229,   229,   308,   309,   310,   190,   347,   -34,
      61,   166,   -33,   348,   -34,   317,   318,   319,   190,    61,
     172,   349,   133,   171,   352,   353,   -11,   -35,   329,   332,
      60,   -34,   -35,    60,    60,   -11,   -33,   134,   -34,   191,
     172,    26,    27,    28,   -36,    29,    30,   -36,   154,   217,
     217,   -35,   135,   -18,   -35,    37,    38,    61,   136,    61,
      41,    42,   -18,   276,   -54,   137,   139,    43,   -36,   -36,
     -39,    81,   145,    61,    61,    61,    81,   146,   147,    65,
      44,   148,   149,   209,   210,   211,   114,   212,   213,   150,
     214,   151,   289,   290,    60,    60,   -39,   -84,   324,   -76,
     244,   191,   245,    61,    61,   115,   246,   -67,   -67,   -67,
     247,   -67,   -67,    49,   -67,   255,   209,   210,   211,   327,
     212,   213,   215,   214,    66,    26,    27,    28,    61,    29,
      30,   256,   154,    77,   167,   257,   258,   266,   328,    37,
      38,   172,   172,   267,    41,    42,   -67,   268,   269,   280,
     -77,    43,   -79,   186,   167,   215,    50,   -78,   -80,   -74,
     191,   172,   -75,   282,    44,   281,   284,    67,   285,   286,
     287,    66,   -38,    66,   336,   322,    10,    79,   340,   172,
     341,   345,   -33,   209,   210,   211,   330,   212,   213,   346,
     214,   172,   350,   351,   172,   191,   100,   103,   -73,    61,
     354,   355,   356,   357,   358,   331,   192,   193,   194,   359,
     195,   196,   360,   197,   120,   186,    50,   231,    49,   191,
     198,   199,   215,   -34,   -35,   200,   201,   172,   172,   172,
     191,   -36,   202,   -81,   363,   364,   365,   366,   191,   191,
     191,   191,    49,   367,     0,   203,   140,   368,   369,     0,
       0,     0,   191,     0,     0,   248,   167,   172,   100,     0,
     232,    50,   217,   217,    61,     0,     0,    61,    61,     0,
       0,     0,     0,     0,   259,   167,    26,    27,    28,     0,
      29,    30,     0,   154,     0,    50,     0,     0,     0,     0,
      37,    38,   270,   167,     0,    41,    42,     0,     0,   250,
       0,    59,    43,     0,     0,   167,     0,     0,   167,   186,
       0,     0,    59,    66,     0,    44,     0,     0,   261,   -66,
     -66,   -66,   170,   -66,   -66,     0,   -66,     0,    61,    61,
     -69,   -69,   -69,   186,   -69,   -69,   272,   -69,     0,     0,
       0,   189,   170,     0,   186,     0,     0,     0,   277,     0,
       0,   278,   279,     0,     0,   186,   283,     0,   -66,    59,
       0,    59,     0,   -68,   -68,   -68,   186,   -68,   -68,   -69,
     -68,   167,     0,     0,     0,     0,   100,     0,    49,     0,
       0,    66,    49,     0,   -65,   -65,   -65,   100,   -65,   -65,
       0,   -65,   -64,   -64,   -64,     0,   -64,   -64,   100,   -64,
       0,     0,   -68,   189,     0,    59,    59,     0,     0,   100,
       0,   -60,   -60,   -60,   323,   -60,   -60,     0,   -60,     0,
       0,    50,     0,   -65,   232,    50,   168,     0,     0,     0,
      59,   -64,     0,   -61,   -61,   -61,     0,   -61,   -61,     0,
     -61,     0,   231,   231,   170,   187,   168,     0,     0,     0,
     -60,   106,     0,   109,   110,     0,     0,   117,     0,     0,
       0,     0,     0,   170,    26,    27,    28,     0,    29,    30,
       0,    32,   -61,     0,     0,     0,     0,     0,    37,    38,
       0,   170,     0,    41,    42,   232,   232,   -62,   -62,   -62,
      43,   -62,   -62,   170,   -62,     0,   170,   189,     0,     0,
       0,    59,     0,    44,     0,     0,     0,   187,   -16,     0,
     -16,   -16,   -16,     0,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   189,   -16,   -16,   -16,   -16,   -62,   -16,   -16,   -16,
     -16,     0,   189,   -63,   -63,   -63,   -16,   -63,   -63,     0,
     -63,     0,     0,   189,     0,     0,     0,     0,   168,   -16,
       0,     0,     0,   -16,   189,     0,     0,     0,     0,   170,
       0,     0,     0,     0,     0,     0,    59,   168,     0,    59,
      59,     0,   -63,     0,   -20,     0,   -20,   -20,   -20,     0,
     -20,   -20,   -20,   -20,   -20,   168,   -20,     0,   -20,   -20,
     -20,   -20,     0,   -20,   -20,   -20,   -20,   168,     0,     0,
     168,   187,   -20,   174,   175,   176,     0,   177,   178,     0,
     179,     0,     0,     0,     0,   -20,     0,   180,   181,   -20,
       0,     0,   182,   183,     0,   187,   294,   295,   296,   184,
      59,    59,     0,     0,     0,     0,   187,   303,   304,   305,
       0,     0,   185,     0,     0,     0,     0,   187,   312,   313,
     314,     0,    26,    27,    28,     0,    29,    30,   187,   154,
       0,     0,     0,   168,     0,   -17,   325,   -17,   -17,   -17,
       0,   -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,   -17,
     -17,   -17,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,
       0,    44,     0,   -17,     0,   155,   156,   157,     0,   158,
     159,     0,   160,     0,     0,   -30,   -17,   -30,   -30,   -30,
     -17,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,
       0,     0,     0,   -30,   166,   174,   175,   176,     0,   177,
     178,     0,   179,     0,     0,   -21,   -30,   -21,   -21,   -21,
     -30,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,
     -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,
       0,     0,     0,   -21,   185,   192,   193,   194,     0,   195,
     196,     0,   197,     0,     0,   -22,   -21,   -22,   -22,   -22,
     -21,   -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,
     -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,
       0,     0,     0,   -22,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -27,   -22,   -27,   -27,   -27,
     -22,   -27,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,
     -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,     0,     0,
       0,     0,     0,   -27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -27,   -28,   -28,   -28,
     -27,   -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,
     -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,
       0,     0,     0,   -28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -29,   -28,   -29,   -29,   -29,
     -28,   -29,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,     0,     0,
       0,     0,     0,   -29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -23,   -29,   -23,   -23,   -23,
     -29,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,
     -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,
       0,     0,     0,   -23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -24,   -23,   -24,   -24,   -24,
     -23,   -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,
     -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,
       0,     0,     0,   -24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -25,   -24,   -25,   -25,   -25,
     -24,   -25,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,
       0,     0,     0,   -25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -53,   -25,   -53,   -53,   -53,
     -25,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,     0,     0,
       0,     0,     0,   -53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -26,   -53,   -26,   -26,   -26,
     -53,   -26,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,
     -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,     0,     0,
       0,     0,     0,   -26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -32,   -26,   -32,   -32,   -32,
     -26,   -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,
     -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,     0,     0,
       0,     0,     0,   -32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -9,   -32,    -9,    -9,    -9,
     -32,    -9,    -9,    -9,    -9,    -9,    -9,    -9,     0,    -9,
      -9,    -9,    -9,     0,    -9,    -9,    -9,    -9,     0,     0,
       0,     0,     0,    -9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -52,    -9,   -52,   -52,   -52,
      -9,   -52,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,
     -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,     0,   -52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -18,   -52,   -18,   -18,   -18,
     -52,   -18,   -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,
     -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,     0,     0,
       0,     0,     0,   -18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -31,   -18,   -31,   -31,   -31,
     -18,   -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,
     -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,     0,     0,
       0,     0,     0,   -31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -51,   -31,   -51,   -51,   -51,
     -31,   -51,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,
     -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,     0,     0,
       0,     0,     0,   -51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -48,   -51,   -48,   -48,   -48,
     -51,   -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,
     -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,     0,     0,
       0,     0,     0,   -48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -42,   -48,   -42,   -42,   -42,
     -48,   -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,
       0,     0,     0,   -42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -43,   -42,   -43,   -43,   -43,
     -42,   -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,     0,   -43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -44,   -43,   -44,   -44,   -44,
     -43,   -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,     0,     0,
       0,     0,     0,   -44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -45,   -44,   -45,   -45,   -45,
     -44,   -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,
     -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,
       0,     0,     0,   -45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -46,   -45,   -46,   -46,   -46,
     -45,   -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,     0,     0,
       0,     0,     0,   -46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -47,   -46,   -47,   -47,   -47,
     -46,   -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,
     -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,     0,     0,
       0,     0,     0,   -47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,   -47,    26,    27,    28,
     -47,    29,    30,    31,    32,    33,     0,    34,     0,    35,
      36,    37,    38,     0,    39,    40,    41,    42,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -30,    44,   -30,   -30,   -30,
      45,   -30,   -30,   -30,   -30,   -30,     0,   -30,     0,   -30,
     -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,
       0,     0,     0,   -30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -21,   -30,   -21,   -21,   -21,
     -30,   -21,   -21,   -21,   -21,   -21,     0,   -21,     0,   -21,
     -21,   -21,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,
       0,     0,     0,   -21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -19,   -21,   -19,   -19,   -19,
     -21,   -19,   -19,   -19,   -19,   -19,     0,   -19,     0,   -19,
     -19,   -19,   -19,     0,   -19,   -19,   -19,   -19,     0,     0,
       0,     0,     0,   -19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -22,   -19,   -22,   -22,   -22,
     -19,   -22,   -22,   -22,   -22,   -22,     0,   -22,     0,   -22,
     -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,
       0,     0,     0,   -22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -27,   -22,   -27,   -27,   -27,
     -22,   -27,   -27,   -27,   -27,   -27,     0,   -27,     0,   -27,
     -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,     0,     0,
       0,     0,     0,   -27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -28,   -27,   -28,   -28,   -28,
     -27,   -28,   -28,   -28,   -28,   -28,     0,   -28,     0,   -28,
     -28,   -28,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,
       0,     0,     0,   -28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -29,   -28,   -29,   -29,   -29,
     -28,   -29,   -29,   -29,   -29,   -29,     0,   -29,     0,   -29,
     -29,   -29,   -29,     0,   -29,   -29,   -29,   -29,     0,     0,
       0,     0,     0,   -29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -23,   -29,   -23,   -23,   -23,
     -29,   -23,   -23,   -23,   -23,   -23,     0,   -23,     0,   -23,
     -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,
       0,     0,     0,   -23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -24,   -23,   -24,   -24,   -24,
     -23,   -24,   -24,   -24,   -24,   -24,     0,   -24,     0,   -24,
     -24,   -24,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,
       0,     0,     0,   -24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -25,   -24,   -25,   -25,   -25,
     -24,   -25,   -25,   -25,   -25,   -25,     0,   -25,     0,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,
       0,     0,     0,   -25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -53,   -25,   -53,   -53,   -53,
     -25,   -53,   -53,   -53,   -53,   -53,     0,   -53,     0,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,     0,     0,
       0,     0,     0,   -53,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -26,   -53,   -26,   -26,   -26,
     -53,   -26,   -26,   -26,   -26,   -26,     0,   -26,     0,   -26,
     -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,     0,     0,
       0,     0,     0,   -26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -32,   -26,   -32,   -32,   -32,
     -26,   -32,   -32,   -32,   -32,   -32,     0,   -32,     0,   -32,
     -32,   -32,   -32,     0,   -32,   -32,   -32,   -32,     0,     0,
       0,     0,     0,   -32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -52,   -32,   -52,   -52,   -52,
     -32,   -52,   -52,   -52,   -52,   -52,     0,   -52,     0,   -52,
     -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,     0,     0,
       0,     0,     0,   -52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -31,   -52,   -31,   -31,   -31,
     -52,   -31,   -31,   -31,   -31,   -31,     0,   -31,     0,   -31,
     -31,   -31,   -31,     0,   -31,   -31,   -31,   -31,     0,     0,
       0,     0,     0,   -31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -51,   -31,   -51,   -51,   -51,
     -31,   -51,   -51,   -51,   -51,   -51,     0,   -51,     0,   -51,
     -51,   -51,   -51,     0,   -51,   -51,   -51,   -51,     0,     0,
       0,     0,     0,   -51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -48,   -51,   -48,   -48,   -48,
     -51,   -48,   -48,   -48,   -48,   -48,     0,   -48,     0,   -48,
     -48,   -48,   -48,     0,   -48,   -48,   -48,   -48,     0,     0,
       0,     0,     0,   -48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -42,   -48,   -42,   -42,   -42,
     -48,   -42,   -42,   -42,   -42,   -42,     0,   -42,     0,   -42,
     -42,   -42,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,
       0,     0,     0,   -42,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -43,   -42,   -43,   -43,   -43,
     -42,   -43,   -43,   -43,   -43,   -43,     0,   -43,     0,   -43,
     -43,   -43,   -43,     0,   -43,   -43,   -43,   -43,     0,     0,
       0,     0,     0,   -43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -44,   -43,   -44,   -44,   -44,
     -43,   -44,   -44,   -44,   -44,   -44,     0,   -44,     0,   -44,
     -44,   -44,   -44,     0,   -44,   -44,   -44,   -44,     0,     0,
       0,     0,     0,   -44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -45,   -44,   -45,   -45,   -45,
     -44,   -45,   -45,   -45,   -45,   -45,     0,   -45,     0,   -45,
     -45,   -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,
       0,     0,     0,   -45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -46,   -45,   -46,   -46,   -46,
     -45,   -46,   -46,   -46,   -46,   -46,     0,   -46,     0,   -46,
     -46,   -46,   -46,     0,   -46,   -46,   -46,   -46,     0,     0,
       0,     0,     0,   -46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -47,   -46,   -47,   -47,   -47,
     -46,   -47,   -47,   -47,   -47,   -47,     0,   -47,     0,   -47,
     -47,   -47,   -47,     0,   -47,   -47,   -47,   -47,     0,     0,
       0,     0,     0,   -47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -50,   -47,   -50,   -50,   -50,
     -47,   -50,   -50,   -50,   -50,   -50,     0,   -50,     0,   -50,
     -50,   -50,   -50,     0,   -50,   -50,   -50,   -50,     0,     0,
       0,     0,     0,   -50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    -9,   -50,    -9,    -9,    -9,
     -50,    -9,    -9,    -9,    -9,    -9,     0,    -9,     0,    -9,
      -9,    -9,    -9,     0,    -9,    -9,    -9,    -9,     0,     0,
       0,     0,     0,    -9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -16,    -9,   -16,   -16,   -16,
      -9,   -16,   -16,   -16,   -16,   -16,     0,   -16,     0,   -16,
     -16,   -16,   -16,     0,   -16,   -16,   -16,   -16,     0,     0,
       0,     0,     0,   -16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -17,   -16,   -17,   -17,   -17,
     -16,   -17,   -17,   -17,   -17,   -17,     0,   -17,     0,   -17,
     -17,   -17,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,
       0,     0,     0,   -17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,   -17,    26,    27,    28,
     -17,    29,    30,    31,    32,    33,     0,    34,     0,    35,
      36,    37,    38,     0,    39,    40,    41,    42,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    44,    26,    27,    28,
     333,    29,    30,    31,    32,    33,     0,    34,     0,    35,
      36,    37,    38,     0,    39,    40,    41,    42,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -18,    44,   -18,   -18,   -18,
     335,   -18,   -18,   -18,   -18,   -18,     0,   -18,     0,   -18,
     -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,     0,     0,
       0,     0,     0,   -18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -49,   -18,   -49,   -49,   -49,
     -18,   -49,   -49,   -49,   -49,   -49,     0,   -49,     0,   -49,
     -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,     0,     0,
       0,     0,     0,   -49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   -49,    26,    27,    28,
     -49,    29,    30,   221,    32,   222,     0,   223,     0,   224,
     225,    37,    38,     0,   226,   227,    41,    42,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,     0,    25,   228,
      26,    27,    28,     0,    29,    30,    31,    32,    33,     0,
      34,     0,    35,    36,    37,    38,     0,    39,    40,    41,
      42,     0,     0,     0,     0,     0,    43,     0,     0,    26,
      27,    28,     0,    29,    30,     0,   154,     0,     0,    44,
       0,     0,   240,    37,    38,     0,     0,     0,    41,    42,
     155,   156,   157,     0,   158,   159,     0,   160,     0,     0,
       0,     0,     0,     0,   161,   162,     0,     0,    44,   163,
     164,   174,   175,   176,     0,   177,   178,     0,   179,     0,
       0,     0,     0,     0,     0,   180,   181,     0,     0,   166,
     182,   183,   192,   193,   194,     0,   195,   196,     0,   197,
       0,     0,     0,     0,     0,   -54,   198,   199,     0,     0,
     185,   200,   201,   -54,   -54,   -54,     0,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -76,   254,   -54,
     -54,   203,     0,     0,     0,   -76,   -76,   -76,     0,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -77,
       0,   -76,   -76,     0,     0,     0,     0,   -77,   -77,   -77,
       0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -79,     0,   -77,   -77,     0,     0,     0,     0,   -79,
     -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -78,     0,   -79,   -79,     0,     0,     0,
       0,   -78,   -78,   -78,     0,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -80,     0,   -78,   -78,     0,
       0,     0,     0,   -80,   -80,   -80,     0,   -80,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -74,     0,   -80,
     -80,     0,     0,     0,     0,   -74,   -74,   -74,     0,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -37,
       0,   -74,   -74,     0,     0,     0,     0,    84,    85,    86,
       0,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,   -59,     0,   -37,   -37,     0,     0,     0,     0,   -59,
     -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -75,     0,   -59,   -59,     0,     0,     0,
       0,   -75,   -75,   -75,     0,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -58,     0,   -75,   -75,     0,
       0,     0,     0,   -58,   -58,   -58,     0,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -73,     0,   -58,
     -58,     0,     0,     0,     0,   -73,   -73,   -73,     0,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -55,
       0,   -73,   -73,     0,     0,     0,     0,   -55,   -55,   -55,
       0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -57,     0,   -55,   -55,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -56,     0,   -57,   -57,     0,     0,     0,
       0,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -81,     0,   -56,   -56,     0,
       0,     0,     0,   -81,   -81,   -81,     0,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -54,     0,   -81,
     -81,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -76,
     243,   -54,     0,     0,     0,     0,     0,   -76,   -76,   -76,
       0,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -77,     0,   -76,     0,     0,     0,     0,     0,   -77,
     -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -79,     0,   -77,     0,     0,     0,     0,
       0,   -79,   -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -78,     0,   -79,     0,     0,
       0,     0,     0,   -78,   -78,   -78,     0,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -80,     0,   -78,
       0,     0,     0,     0,     0,   -80,   -80,   -80,     0,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -74,
       0,   -80,     0,     0,     0,     0,     0,   -74,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -37,     0,   -74,     0,     0,     0,     0,     0,    84,
      85,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   -59,     0,   -37,     0,     0,     0,     0,
       0,   -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -75,     0,   -59,     0,     0,
       0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -58,     0,   -75,
       0,     0,     0,     0,     0,   -58,   -58,   -58,     0,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -73,
       0,   -58,     0,     0,     0,     0,     0,   -73,   -73,   -73,
       0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -55,     0,   -73,     0,     0,     0,     0,     0,   -55,
     -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -57,     0,   -55,     0,     0,     0,     0,
       0,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -56,     0,   -57,     0,     0,
       0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -81,     0,   -56,
       0,     0,     0,     0,     0,   -81,   -81,   -81,     0,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -54,
       0,   -81,     0,     0,     0,     0,     0,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,    63,   -54,     0,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,     0,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,    63,   -54,     0,     0,
       0,     0,     0,     0,     0,   -54,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -74,
     265,     0,     0,     0,     0,     0,     0,   -74,   -74,   -74,
      83,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,     0,     0,     0,     0,     0,     0,     0,
     -74,   -74,   -74,   291,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -76,     0,     0,     0,     0,
       0,     0,     0,   -76,   -76,   -76,     0,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -77,     0,
       0,     0,     0,     0,     0,     0,   -77,   -77,   -77,     0,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -79,     0,     0,     0,     0,     0,     0,     0,   -79,
     -79,   -79,     0,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -78,     0,     0,     0,     0,     0,
       0,     0,   -78,   -78,   -78,     0,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -80,     0,     0,
       0,     0,     0,     0,     0,   -80,   -80,   -80,     0,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -37,     0,     0,     0,     0,     0,     0,     0,    84,    85,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   -37,   -59,     0,     0,     0,     0,     0,     0,
       0,   -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -75,     0,     0,     0,
       0,     0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -74,
       0,     0,     0,     0,     0,     0,     0,   -74,   -74,   -74,
       0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -58,     0,     0,     0,     0,     0,     0,     0,
     -58,   -58,   -58,     0,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -73,     0,     0,     0,     0,
       0,     0,     0,   -73,   -73,   -73,     0,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -55,     0,
       0,     0,     0,     0,     0,     0,   -55,   -55,   -55,     0,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -57,     0,     0,     0,     0,     0,     0,     0,   -57,
     -57,   -57,     0,   -57,   -57,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -56,     0,     0,     0,     0,     0,
       0,     0,   -56,   -56,   -56,     0,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -81,     0,     0,
       0,     0,     0,     0,     0,   -81,   -81,   -81,     0,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -76,     0,     0,     0,     0,     0,     0,     0,   -76,   -76,
     -76,     0,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -77,     0,     0,     0,     0,     0,     0,     0,
     -77,   -77,   -77,     0,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -79,     0,     0,     0,     0,     0,
       0,     0,   -79,   -79,   -79,     0,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -78,     0,     0,     0,
       0,     0,     0,     0,   -78,   -78,   -78,     0,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,   -78,   -80,     0,
       0,     0,     0,     0,     0,     0,   -80,   -80,   -80,     0,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -74,     0,     0,     0,     0,     0,     0,     0,   -74,   -74,
     -74,     0,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -37,     0,     0,     0,     0,     0,     0,     0,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   -59,     0,     0,     0,     0,     0,
       0,     0,   -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -75,     0,     0,     0,
       0,     0,     0,     0,   -75,   -75,   -75,     0,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -58,     0,
       0,     0,     0,     0,     0,     0,   -58,   -58,   -58,     0,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -73,     0,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -73,     0,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -55,     0,     0,     0,     0,     0,     0,     0,
     -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -57,     0,     0,     0,     0,     0,
       0,     0,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -56,     0,     0,     0,
       0,     0,     0,     0,   -56,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,   -56,   -81,     0,
       0,     0,     0,     0,     0,     0,   -81,   -81,   -81,     0,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81
};

static const yytype_int16 yycheck[] =
{
       0,    23,    83,    18,     4,     9,    19,   170,   127,   128,
      19,     0,    34,   127,    10,     0,    19,    41,    42,   170,
     127,    43,    44,   127,     9,   127,   189,   127,    41,    19,
     127,    43,    44,   152,    43,    44,   128,   170,   189,    43,
      43,    63,    64,   206,    19,   228,   127,   243,    70,    19,
      19,    73,    74,    43,    76,   206,   189,   240,   254,    81,
     152,    83,     0,     3,     4,     5,    41,     7,     8,   265,
      10,    41,    43,   206,    43,    97,    98,    99,    42,     1,
     276,     3,     4,     5,    19,     7,     8,     9,    10,    11,
      12,    13,    19,    15,    16,    17,    18,    10,    20,    21,
      22,    23,    42,   125,    19,   127,   128,    29,    43,    44,
      19,    45,     0,   128,    19,    23,    43,    44,    19,    19,
      42,     9,     0,     1,    46,     9,    34,   127,    43,    44,
     152,     9,    19,    19,    43,    43,    44,   152,    43,    44,
      19,    41,    43,   165,   166,     3,     4,     5,     6,     7,
       8,    10,    10,    19,    41,    63,    64,    43,    44,    19,
       0,    42,   184,   185,    43,    73,    74,    25,    19,     9,
      19,    43,    44,    81,    10,    83,    41,    43,    44,    42,
      19,   203,    19,    43,    42,    19,    19,    19,    19,    97,
      98,    99,    43,   215,    43,    44,   218,   219,     3,     4,
       5,   223,     7,     8,    43,    10,    43,    44,    41,    43,
     291,    43,    43,    19,     0,     0,    42,   125,     0,   127,
     128,   243,    42,     9,     9,   247,    42,     9,    42,   251,
     252,   253,   254,   352,   353,    41,   258,    42,   352,   353,
     262,   263,   264,   265,   152,   352,   353,   269,   352,   353,
     352,   353,   352,   353,   276,   352,   353,   165,   166,   281,
     352,   353,    19,   285,   286,   287,   288,    19,    42,   291,
     292,   352,   353,    43,    44,    19,   184,   185,     3,     4,
       5,    42,     7,     8,    42,    10,    43,    43,    19,    19,
      19,    43,    17,    18,   202,   203,    19,    22,    23,    43,
      43,     3,     4,     5,    29,     7,     8,   215,    10,    19,
     218,   219,    43,    43,    43,   223,    19,    42,    43,    10,
      43,    19,     3,     4,     5,    43,     7,     8,    43,    10,
     352,   353,    43,    43,    19,   243,    17,    18,    41,    19,
      42,    22,    23,   251,   252,   253,   254,    19,    29,    23,
      19,    19,   352,   353,   262,   263,   264,   265,    43,    19,
      34,    42,    19,    43,    19,   273,   274,   275,   276,    43,
      44,    43,    43,   281,    43,    43,     0,    19,   286,   287,
     288,    41,    19,   291,   292,     9,    43,    43,    43,    63,
      64,     3,     4,     5,    19,     7,     8,    19,    10,    73,
      74,    43,    43,     0,    41,    17,    18,    81,    43,    83,
      22,    23,     9,    42,    43,    43,    43,    29,    43,    41,
      19,    19,    41,    97,    98,    99,    19,    41,    41,    41,
      42,    41,    41,     3,     4,     5,     6,     7,     8,    41,
      10,    41,    41,    41,   352,   353,    19,    43,    41,    43,
      42,   125,    42,   127,   128,    25,    42,     3,     4,     5,
      42,     7,     8,    23,    10,    42,     3,     4,     5,     6,
       7,     8,    42,    10,    34,     3,     4,     5,   152,     7,
       8,    42,    10,    43,    44,    42,    42,    42,    25,    17,
      18,   165,   166,    42,    22,    23,    42,    42,    42,    10,
      43,    29,    43,    63,    64,    42,    23,    43,    43,    43,
     184,   185,    43,    41,    42,    42,    42,    34,    42,    42,
      42,    81,    19,    83,    43,    41,     4,    44,    43,   203,
      43,    43,    19,     3,     4,     5,     6,     7,     8,    43,
      10,   215,    43,    43,   218,   219,    63,    64,    43,   223,
      43,    43,    43,    43,    43,    25,     3,     4,     5,    43,
       7,     8,    43,    10,    81,   125,    83,   127,   128,   243,
      17,    18,    42,    19,    19,    22,    23,   251,   252,   253,
     254,    19,    29,    43,    41,    41,    41,    41,   262,   263,
     264,   265,   152,    41,    -1,    42,   125,    41,    41,    -1,
      -1,    -1,   276,    -1,    -1,   165,   166,   281,   125,    -1,
     127,   128,   286,   287,   288,    -1,    -1,   291,   292,    -1,
      -1,    -1,    -1,    -1,   184,   185,     3,     4,     5,    -1,
       7,     8,    -1,    10,    -1,   152,    -1,    -1,    -1,    -1,
      17,    18,   202,   203,    -1,    22,    23,    -1,    -1,   166,
      -1,    23,    29,    -1,    -1,   215,    -1,    -1,   218,   219,
      -1,    -1,    34,   223,    -1,    42,    -1,    -1,   185,     3,
       4,     5,    44,     7,     8,    -1,    10,    -1,   352,   353,
       3,     4,     5,   243,     7,     8,   203,    10,    -1,    -1,
      -1,    63,    64,    -1,   254,    -1,    -1,    -1,   215,    -1,
      -1,   218,   219,    -1,    -1,   265,   223,    -1,    42,    81,
      -1,    83,    -1,     3,     4,     5,   276,     7,     8,    42,
      10,   281,    -1,    -1,    -1,    -1,   243,    -1,   288,    -1,
      -1,   291,   292,    -1,     3,     4,     5,   254,     7,     8,
      -1,    10,     3,     4,     5,    -1,     7,     8,   265,    10,
      -1,    -1,    42,   125,    -1,   127,   128,    -1,    -1,   276,
      -1,     3,     4,     5,   281,     7,     8,    -1,    10,    -1,
      -1,   288,    -1,    42,   291,   292,    44,    -1,    -1,    -1,
     152,    42,    -1,     3,     4,     5,    -1,     7,     8,    -1,
      10,    -1,   352,   353,   166,    63,    64,    -1,    -1,    -1,
      42,    69,    -1,    71,    72,    -1,    -1,    75,    -1,    -1,
      -1,    -1,    -1,   185,     3,     4,     5,    -1,     7,     8,
      -1,    10,    42,    -1,    -1,    -1,    -1,    -1,    17,    18,
      -1,   203,    -1,    22,    23,   352,   353,     3,     4,     5,
      29,     7,     8,   215,    10,    -1,   218,   219,    -1,    -1,
      -1,   223,    -1,    42,    -1,    -1,    -1,   125,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,   243,    15,    16,    17,    18,    42,    20,    21,    22,
      23,    -1,   254,     3,     4,     5,    29,     7,     8,    -1,
      10,    -1,    -1,   265,    -1,    -1,    -1,    -1,   166,    42,
      -1,    -1,    -1,    46,   276,    -1,    -1,    -1,    -1,   281,
      -1,    -1,    -1,    -1,    -1,    -1,   288,   185,    -1,   291,
     292,    -1,    42,    -1,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,   203,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,   215,    -1,    -1,
     218,   219,    29,     3,     4,     5,    -1,     7,     8,    -1,
      10,    -1,    -1,    -1,    -1,    42,    -1,    17,    18,    46,
      -1,    -1,    22,    23,    -1,   243,   244,   245,   246,    29,
     352,   353,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,    42,    -1,    -1,    -1,    -1,   265,   266,   267,
     268,    -1,     3,     4,     5,    -1,     7,     8,   276,    10,
      -1,    -1,    -1,   281,    -1,     1,   284,     3,     4,     5,
      -1,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    42,    -1,    29,    -1,     3,     4,     5,    -1,     7,
       8,    -1,    10,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    42,     3,     4,     5,    -1,     7,
       8,    -1,    10,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    42,     3,     4,     5,    -1,     7,
       8,    -1,    10,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    12,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,
      46,     7,     8,     9,    10,    11,    -1,    13,    -1,    15,
      16,    17,    18,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,     1,    45,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    -1,
      13,    -1,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,     3,
       4,     5,    -1,     7,     8,    -1,    10,    -1,    -1,    42,
      -1,    -1,    45,    17,    18,    -1,    -1,    -1,    22,    23,
       3,     4,     5,    -1,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    42,    22,
      23,     3,     4,     5,    -1,     7,     8,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    -1,    -1,    42,
      22,    23,     3,     4,     5,    -1,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    19,    17,    18,    -1,    -1,
      42,    22,    23,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    42,    43,
      44,    42,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    44,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      44,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    44,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      44,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    44,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      44,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      42,    43,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    19,    -1,    43,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    19,    -1,    43,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    19,    -1,    43,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    19,    -1,    43,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    19,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,
      -1,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    19,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    48,    49,    50,    51,    10,     0,    50,
      51,    41,    52,    42,     9,    53,    54,    10,    43,    44,
      45,    56,     9,    57,    10,     1,     3,     4,     5,     7,
       8,     9,    10,    11,    13,    15,    16,    17,    18,    20,
      21,    22,    23,    29,    42,    46,    50,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      74,    75,    10,    42,    42,    41,    60,    61,    69,    42,
      42,    42,    42,    42,    42,    42,    42,    60,    74,    61,
      41,    19,    41,    30,    27,    28,    29,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    71,    72,    73,
      61,    76,    77,    61,    41,    61,    62,    10,    69,    62,
      62,     6,    25,    74,     6,    25,    74,    62,    69,    43,
      61,    59,    74,    74,    74,    44,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      77,    55,    56,    58,    55,    41,    41,    41,    41,    41,
      41,    41,    12,    55,    10,     3,     4,     5,     7,     8,
      10,    17,    18,    22,    23,    29,    42,    60,    62,    69,
      70,    74,    75,    41,     3,     4,     5,     7,     8,    10,
      17,    18,    22,    23,    29,    42,    60,    62,    69,    70,
      74,    75,     3,     4,     5,     7,     8,    10,    17,    18,
      22,    23,    29,    42,    60,    69,    70,    74,    75,     3,
       4,     5,     7,     8,    10,    42,    69,    75,    19,    19,
       1,     9,    11,    13,    15,    16,    20,    21,    45,    50,
      59,    60,    61,    63,    64,    65,    66,    67,    68,    69,
      45,    56,    58,    42,    42,    42,    42,    42,    60,    74,
      61,    71,    72,    73,    42,    42,    42,    42,    42,    60,
      74,    61,    71,    72,    73,    42,    42,    42,    42,    42,
      60,    74,    61,    71,    72,    73,    42,    61,    61,    61,
      10,    42,    41,    61,    42,    42,    42,    42,    57,    41,
      41,    30,    57,    76,    62,    62,    62,    69,    43,    74,
      74,    74,    76,    62,    62,    62,    69,    43,    74,    74,
      74,    76,    62,    62,    62,    69,    43,    74,    74,    74,
      76,    43,    41,    61,    41,    62,    69,     6,    25,    74,
       6,    25,    74,    46,    59,    46,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    55,    55,    41,    41,    41,    41,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      52,    51,    53,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    63,    63,    63,    64,    64,    64,    65,    66,
      66,    67,    68,    68,    69,    70,    70,    70,    70,    70,
      71,    71,    71,    71,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     0,     3,
       0,     7,     1,     0,     4,     2,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     2,     4,     4,     4,     4,     1,     2,     1,
       1,     3,     5,     5,     5,     5,     5,     5,     5,     5,
       7,     5,     3,     2,     1,     3,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     0,     3,     1
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
#line 117 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
        check_semantic_error_no_main();
    }
#line 2472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 121 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 125 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2486 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 128 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 134 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 137 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
    }
#line 2518 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), "variable");
    }
#line 2527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 150 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "function");
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 154 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2545 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 161 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 164 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 170 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2570 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 174 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 180 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2587 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 183 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2595 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("COMPOUND_STATEMENT", (yyvsp[-1].node), NULL , NULL, NULL);
    }
#line 2603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 195 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2611 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 198 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2619 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 204 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 210 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 213 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 216 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 219 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2667 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 222 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 225 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 228 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 231 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
        yyerrok;
    }
#line 2700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 238 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
         define_type((yyval.node));
    }
#line 2709 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 242 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 248 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 251 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 254 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 263 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 266 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 269 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2781 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 278 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2789 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 284 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2797 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 287 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 290 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2813 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 296 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 299 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 302 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2837 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 308 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2845 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 314 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2853 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 317 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT_ELSE", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2862 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 324 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2870 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 330 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
        define_type((yyval.node));
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2880 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 335 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 342 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[0].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("VARIABLE", NULL, NULL, type, (yyvsp[0].token));
    }
#line 2902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 353 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 357 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 361 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2929 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 365 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("NOT_OP", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2937 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 368 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2945 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 373 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 375 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("SUB_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 377 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("MULT_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2969 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 379 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("DIV_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2977 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 384 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("GE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2985 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 386 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2993 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 388 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("G_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 390 "parser.y" /* yacc.c:1646  */
    {
       (yyval.node) = create_tree_node("L_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3009 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 392 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("NE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 394 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EQ_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 399 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("OR_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 401 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("AND_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 403 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("NOT_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 3049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 411 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 3057 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 414 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 3065 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 417 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 3073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 420 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 3081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 423 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 3089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 426 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ELEM", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 3097 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 429 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("SET", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 3105 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 432 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("EMPTY_VALUE", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 3113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 438 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[-3].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, type, (yyvsp[-3].token));
        check_semantic_error_type_mismatch_args((yyvsp[-1].node), (yyvsp[-3].token));
    }
#line 3127 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 450 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 3135 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 453 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 3143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 459 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 3151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 462 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 3159 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3163 "parser.tab.c" /* yacc.c:1646  */
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
#line 467 "parser.y" /* yacc.c:1906  */


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

// Checa se o tipo do retorno é o mesmo da função
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
    args_node* arguments = NULL;
    node* node = no;

    if(no != NULL){
        if(strcmp(node->class, "ARGS_LIST") == 0){
            while(strcmp(node->class, "ARGS_LIST") == 0){
                args_node *a = (args_node *)malloc(sizeof *a);
                a->name = node->left->value;
                a->type = node->left->type;
                a->next = NULL;
                if(args_list == NULL){
                    args_list = a;
                    arguments = args_list;
                }
                else{
                    arguments->next = a;
                    arguments = arguments-> next;
                }
                if(strcmp(node->right->class, "ARGS_LIST") != 0){
                    args_node *a = (args_node *)malloc(sizeof *a);
                    a->name = node->right->value;
                    a->type = node->right->type;
                    a->next = NULL;
                    arguments->next = a;
                    arguments = arguments-> next;
                }
                node = node->right;
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
    args_node* arguments = NULL;
    int number_args = 0;
    int number_param = 0;
    param_node* param_list = NULL;
    param_node* params = NULL;

    symbol_node* f;
    char* key = concat_string(function_name, stack->scope_name);
    HASH_FIND_STR(symbol_table, key, f);
    if(f != NULL){
        param_list = f->param_list;
    }

    arguments = args_list;
    while(arguments != NULL){
        number_args++;
        arguments = arguments->next;
    }
    params = param_list;
    while(params != NULL){
        number_param++;
        params = params->next;
    }

    if(number_args != number_param){
        semantic_error_wrong_number_arguments(function_name, number_args, number_param);
    }
    else{
        symbol_node* s;
        arguments = args_list;
        params = param_list;
        int direction;
        node* aux;
        int i = 0;
        while(arguments != NULL){
            HASH_FIND_STR(symbol_table, params->key, s);
            if(s != NULL){
                if(
                    arguments->type != NULL &&
                    s->type != NULL &&
                    (strcmp(arguments->type, s->type) != 0)
                ){
                    if(
                        (strcmp(arguments->type, "int") == 0 && strcmp(s->type, "float") == 0) || 
                        (strcmp(arguments->type, "float") == 0 && strcmp(s->type, "int") == 0) ||
                        (strcmp(arguments->type, "elem") == 0 && strcmp(s->type, "int") == 0) ||
                        (strcmp(arguments->type, "elem") == 0 && strcmp(s->type, "float") == 0) ||
                        (strcmp(arguments->type, "float") == 0 && strcmp(s->type, "elem") == 0) ||
                        (strcmp(arguments->type, "int") == 0 && strcmp(s->type, "elem") == 0)
                    ){
                        aux = find_arg(no, i, number_args, &direction);
                        implicit_args_conversion(aux, s->type, direction);
                    }
                    else{
                        semantic_error_type_mismatch_args(function_name, arguments->name, arguments->type, s->name, s->type);
                    }
                }
            }
            arguments = arguments->next;
            params = params->next;
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
        (strlen(function_name) + 80) * sizeof(char)
    );
    sprintf(error, "semantic error, call of function (%s) with %d arguments, expected %d", function_name, number_args, number_param);
    yyerror(error);
    free(error);
}

// Erro semântico de tipo incompatível entre arg e params
void semantic_error_type_mismatch_args(char* function_name, char* arg_name, char* type_arg, char* param_name, char* type_param){
    char *error = (char *)malloc(
        (strlen(function_name) + strlen(type_param) + strlen(type_arg) + strlen(arg_name) + strlen(param_name) + 130) * sizeof(char)
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

    if(strcmp(aux_node->class, "ARITHIMETIC_EXPRESSION") == 0){
        if(strcmp(aux_node->value, "+") == 0){
            aux_node->instruction = "add";
        }

        else if(strcmp(aux_node->value, "-") == 0){
            aux_node->instruction = "sub";;
        }

        else if(strcmp(aux_node->value, "*") == 0){
            aux_node->instruction = "mul";
        }

        else if(strcmp(aux_node->value, "/") == 0){
            aux_node->instruction = "div";
        }
    }

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

FILE *create_tac() {
    return fopen("code.tac", "w+");
}

void close_tac(FILE *fp_tac) {
    fclose(fp_tac);
}

void write_table(FILE *fp_tac) {
    fprintf(fp_tac, ".table\n");
    symbol_node *s;
    for(s=symbol_table; s != NULL; s=s->hh.next) {
        if(strcmp(s->symbol_type, "variable") == 0 ){
            fprintf(fp_tac, "\t%s %s \n", s->type, s->name);
        }
    }
}

void arith_assembly(FILE *fp_tac, node * tree) {
    if (strcmp(tree->left->class,"ARITHIMETIC_EXPRESSION") == 0){
        arith_assembly(fp_tac, tree->left);
        fprintf(fp_tac, "\t%s $%d, $%d, %s \n", tree->instruction , aux_register, aux_register, tree->right->value);
    } else {
        fprintf(fp_tac, "\t%s $%d, %s, %s \n", tree->instruction , aux_register, tree->left->value, tree->right->value);
    }
}

void write_assembly(FILE *fp_tac, node * tree) {
    if(tree) {
        if (strcmp(tree->class,"ASSIGN_EXPRESSION") == 0){
            if (strcmp(tree->right->class,"ARITHIMETIC_EXPRESSION") == 0){
                arith_assembly(fp_tac, tree->right);
                fprintf(fp_tac, "\tmov %s, $%d \n", tree->left->value, aux_register);
                aux_register++;
            } else {
                fprintf(fp_tac, "\tmov %s, %s \n", tree->left->value, tree->right->value);
            }
        }

        if (strcmp(tree->class,"WRITE_STATEMENT") == 0){
            if (tree->left != NULL && strcmp(tree->left->class,"VARIABLE") == 0) {
                fprintf(fp_tac, "\tprint %s\n", tree->left->value);
            } else {
                 if (strlen(tree->value) > 1) {
                    for(int i = 1; i < strlen(tree->value) - 1; ++i){
                        fprintf(fp_tac, "\tprint \'%c\'\n", tree->value[i]);
                    }
                } else {
                    fprintf(fp_tac, "\tprint %s\n", tree->value);
                }
            }
        }

        if (strcmp(tree->class,"WRITELN_STATEMENT") == 0){
              if (tree->left != NULL && strcmp(tree->left->class,"VARIABLE") == 0) {
                fprintf(fp_tac, "\tprintln %s\n", tree->left->value);
            } else {
                if (strlen(tree->value) > 1) {
                    for(int i = 1; i < strlen(tree->value) - 1; ++i){
                        fprintf(fp_tac, "\tprintln \'%c\'\n", tree->value[i]);
                    }
                } else {
                    fprintf(fp_tac, "\tprintln %s\n", tree->value);
                }
            }
        }
        write_assembly(fp_tac, tree->left);
        write_assembly(fp_tac, tree->right);
    }
}

void write_code(FILE *fp_tac, node * tree) {
    fprintf(fp_tac, "\n.code\nmain:\n");
    write_assembly(fp_tac, tree);
}

int main(int argc, char **argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        yyin = stdin;
    }
    // printf("----------  ANALISADOR LÉXICO ----------\n\n");
    init_scope_global();
    yyparse();
    print_symbol_table();
    if (total_errors == 0) {    
        printf("\n\n----------  AST ----------\n\n");
        print_parser_tree(parser_tree, 0);
        FILE *fp_tac = create_tac();
        write_table(fp_tac);
        write_code(fp_tac, parser_tree);
        close_tac(fp_tac);
        free_parser_tree(parser_tree);
    }
    printf("Total de Erros: %d\n", total_errors);
    free_symbol_table();
    fclose(yyin);
    yylex_destroy();
}
