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
    EQ = 282,
    NE = 283,
    LE = 284,
    GE = 285,
    OR = 286,
    AND = 287,
    NOT = 288,
    L = 289,
    G = 290,
    ASSIGN = 291,
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
#line 95 "parser.y" /* yacc.c:355  */

    char* token;
    struct node* node;

#line 244 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   4473

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  366

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
       0,   114,   114,   118,   122,   125,   128,   131,   134,   140,
     147,   147,   158,   161,   167,   171,   177,   180,   186,   192,
     195,   201,   204,   207,   210,   213,   216,   219,   222,   225,
     228,   235,   239,   245,   248,   251,   254,   260,   263,   266,
     269,   275,   281,   284,   287,   293,   296,   299,   305,   311,
     314,   321,   327,   332,   339,   350,   354,   358,   362,   367,
     369,   371,   373,   378,   380,   382,   384,   386,   388,   393,
     395,   397,   405,   408,   411,   414,   417,   420,   423,   426,
     432,   444,   447,   453,   456
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
  "CHAR", "THEN", "EQ", "NE", "LE", "GE", "OR", "AND", "NOT", "L", "G",
  "ASSIGN", "ADD_OP", "SUB", "MULT", "DIV", "';'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "program", "declaration-list",
  "variable-declaration", "function", "$@1", "params-list", "params",
  "compound-inline", "compound-stmt", "stmt-list", "stmt", "expr",
  "set-func", "simple-expr", "in-stmt", "write-stmt", "writeln-stmt",
  "read-stmt", "conditional-stmt", "iteration-stmt", "return-stmt", "var",
  "op-expr", "OP", "RELOP", "LOG", "term", "call", "args", "arg-list", YY_NULLPTR
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

#define YYPACT_NINF -235

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-235)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,     7,    26,    21,    11,   136,   341,   115,  -235,   351,
     412,   423,    19,     4,    61,    20,   178,   236,    41,    92,
    1903,   492,    93,  1943,   238,  1983,  3974,  3991,  4008,  4025,
    4042,    99,  3870,    75,    77,   109,   161,   174,   191,   193,
     222,   228,   266,   132,   171,   493,  2023,  2063,  2103,    48,
      51,    87,  2143,  2183,  2223,  2263,  2303,  2343,  3928,  4059,
    4076,  4093,    70,    22,   171,  2383,   145,   164,  4110,   392,
     177,   392,   392,   117,   327,   392,   177,   349,    40,  2423,
     433,  2463,   577,   207,   630,   752,   767,   809,   851,   887,
     927,   967,  1007,  1047,  1087,  1127,  1167,  1167,  1167,    47,
     147,   264,    50,  2503,   291,    53,   272,   277,   127,   148,
     280,   282,   297,   303,   343,   363,   163,   376,  4127,   394,
    2543,  4144,  4161,  4178,   679,  4195,  3223,  3266,   346,   450,
     457,   390,   398,   405,   411,   432,   453,   462,   465,   384,
     719,   863,   903,  2583,  2623,  2663,  2703,  2743,  2783,  2823,
    2863,  3266,  2903,  3894,  3632,  3649,  3666,  3683,  3700,  3615,
     458,   466,   468,   478,   336,   171,   200,   204,  3717,  3734,
    3751,  3768,  2943,  3307,  3329,  3351,  3373,  3395,  3285,   479,
     487,   489,   490,   533,   171,    69,   122,  3417,  3439,  3461,
    3483,  4212,  4229,  4246,  4263,  4280,  3911,   491,   494,   499,
     502,   547,   171,   480,  4297,  4314,  4331,  4348,   431,   511,
     514,   524,   525,   328,   171,   528,   529,   171,   679,   943,
     503,   532,   130,   535,   537,   546,   548,  1903,   983,  1023,
     470,   471,  1063,  1103,  1143,  1183,  1223,  1263,  3951,  1903,
    2983,  3023,    22,   392,   392,   392,   177,   244,   258,  1207,
    1207,  1207,    22,   392,   392,   392,   177,   125,   259,  1247,
    1247,  1247,    22,   392,   392,   392,   177,   515,   270,  1287,
    1287,  1287,    22,   271,   281,   154,   504,   171,  1303,   477,
     392,   177,   369,   455,  3063,  1343,  1383,   577,  3103,   549,
     293,   300,   323,   554,  3785,  3802,  3819,  3836,   558,   337,
     338,   374,   559,  3505,  3527,  3549,  3571,   560,   379,   385,
     386,   561,  4365,  4382,  4399,  4416,   564,   568,  1423,   399,
    1463,   401,   569,   572,   574,   575,   581,   582,   583,  1503,
    1543,  3143,  3853,   414,   434,   435,   445,  3593,   158,   165,
     248,   254,  4433,   556,   570,   608,   611,   593,  3223,  3223,
     550,   598,   600,   601,   602,   603,   604,  3183,  1583,  1623,
    1663,  1703,  1743,  1783,  1823,  1863
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
       0,     0,     0,     0,     0,     0
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -235,  -235,  -235,     0,   642,  -235,  -235,  -235,   -74,   -12,
    -222,  -117,   -80,   321,   344,   585,  -123,  -107,  -103,   -95,
     -91,   -77,   -22,   496,  -155,  -132,  -126,    34,   265,  -234,
     526
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    46,     6,    12,    15,    16,   140,   141,
      23,    47,    48,   203,   104,    51,    52,    53,    54,    55,
      56,    57,   204,   205,    96,    97,    98,   206,   207,   100,
     101
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,    58,   120,   232,     9,   284,    21,    -3,   289,   142,
     241,    -2,    68,    14,   249,    -8,     1,   288,   298,   233,
       2,     8,   168,   234,     2,   173,   174,   175,   307,   176,
     177,   235,   178,   259,   241,   236,     7,   250,   316,   179,
     180,   187,   168,   251,   181,   182,   229,   -13,   107,   237,
     269,   215,   215,   143,   117,   183,   260,    60,    68,   217,
      58,    13,   261,    18,   184,   -82,   218,   -39,    60,   217,
      80,    17,   -40,   270,    68,    68,    68,   152,   170,   271,
      26,    27,    28,   118,    29,    30,    20,   153,   -39,    79,
     -84,   124,    81,   126,    37,    38,   127,   189,   170,    41,
      42,    22,   187,    24,   238,    58,   -40,   112,   115,    62,
      43,   172,   -39,   -39,    60,   240,    60,    64,    65,    44,
     208,   209,   210,   110,   211,   212,   228,   213,   -40,    58,
     121,   122,   123,    26,    27,    28,    -5,    29,    30,   240,
     153,   -40,   111,   168,   -38,    -5,   -40,    37,    38,    37,
      38,    69,    41,    42,    41,    42,    11,   -10,   189,   214,
      60,    60,   168,    43,   -39,   -40,   -40,   -40,   -38,   -38,
     129,   278,    44,   218,   154,   155,   156,   -33,   157,   158,
     168,   159,   -40,    80,   -34,    60,   -39,   106,   160,   161,
     125,   130,   168,   162,   163,   168,   187,   -41,   -41,   170,
      68,   -33,   -33,    70,   164,   103,   137,   330,   -34,   -34,
     -68,   -68,   -68,   165,   -68,   -68,    71,   -68,   170,   -39,
     187,   -12,    19,   -40,   293,   232,   232,   168,   168,   168,
     187,   142,   142,    72,   302,    73,   170,   187,   187,   187,
     187,   233,   233,   -39,   311,   234,   234,   -40,   170,   -68,
     187,   170,   189,   235,   235,   168,    60,   236,   236,   322,
     215,   215,    58,   -38,    74,   238,    58,   -35,   229,   229,
      75,   237,   237,   -36,   357,   358,   189,   217,   217,   -15,
     -15,   -14,   -14,   295,   296,   297,   189,   -38,    61,   217,
     217,   -35,   -35,   304,   305,   306,   189,   -36,   -36,    61,
     217,   294,   303,   313,   314,   315,   189,   -81,    76,   171,
     217,   170,   -40,   312,   317,   -54,   325,   328,    60,   -40,
     128,    60,    60,   131,   -41,   132,   238,   238,   190,   171,
     208,   209,   210,   113,   211,   212,   333,   213,   216,   216,
     133,    -7,   -40,   334,    49,    61,   134,    61,   228,   228,
      -7,    -4,   114,   160,   161,    66,   -40,   -40,   162,   163,
      -4,    61,    61,    61,    77,   166,   335,    50,   -38,   214,
     272,   -54,   208,   209,   210,   323,   211,   212,    67,   213,
     338,   339,    60,    60,   185,   166,   135,   144,    78,   190,
     -38,    61,    61,   -40,   324,   191,   192,   193,   -40,   194,
     195,    66,   196,    66,   -40,   -40,   136,    99,   102,   197,
     198,   214,    -6,    80,   199,   200,    61,   340,   217,   138,
     -40,    -6,   343,    -9,   119,   201,    50,   -83,   344,   345,
     171,   145,    -9,   -33,   202,   -41,    26,    27,    28,   146,
      29,    30,   348,   153,   349,   185,   147,   230,    49,   171,
      37,    38,   148,   -34,   -35,    41,    42,   -33,   208,   209,
     210,   326,   211,   212,   -36,   213,    43,   171,    99,   -33,
     231,    50,    49,   149,   -75,    44,   -34,   -34,   -35,   171,
     327,   -35,   171,   190,   -36,   247,   166,    61,   -36,   -39,
      80,   -33,   -11,   -18,   150,    50,    80,   214,   -34,   -39,
     243,   -11,   -18,   -35,   257,   166,   -36,   190,   244,   248,
     245,   285,   286,   276,   171,   171,   171,   190,   320,    59,
     246,   253,   267,   166,   190,   190,   190,   190,   258,   254,
      59,   255,   256,   263,   -38,   166,   264,   190,   166,   185,
     169,   265,   171,    66,   266,   318,   268,   216,   216,    61,
     179,   180,    61,    61,   -76,   181,   182,   -78,   273,   188,
     169,   274,   275,   185,   197,   198,   279,   -77,   -79,   199,
     200,   -73,   -74,   185,   277,   -33,    59,   280,    59,   281,
      26,    27,    28,   185,    29,    30,    99,    32,   282,   -34,
     283,   359,   332,   185,    37,    38,    99,   336,   166,    41,
      42,   337,   341,   342,   346,    49,    99,   347,    66,    49,
      43,   -72,   350,    61,    61,   351,    99,   352,   353,    44,
     188,   319,    59,    59,   354,   355,   356,   -35,    50,   167,
     -36,   231,    50,   -67,   -67,   -67,   -80,   -67,   -67,   360,
     -67,   361,   362,   363,   364,   365,    10,    59,   186,   167,
     139,     0,     0,     0,   105,     0,   108,   109,     0,     0,
     116,   169,     0,     0,     0,     0,     0,     0,     0,   230,
     230,     0,   -67,     0,     0,     0,     0,     0,     0,     0,
     169,     0,   173,   174,   175,     0,   176,   177,     0,   178,
       0,     0,   231,   231,     0,     0,   179,   180,   169,     0,
       0,   181,   182,     0,     0,     0,     0,     0,     0,   186,
     169,     0,   183,   169,   188,     0,     0,     0,    59,     0,
     -49,   184,   -49,   -49,   -49,     0,   -49,   -49,   -49,   -49,
     -49,   151,   -49,     0,   -49,   -49,   -49,   -49,   188,   -49,
     -49,   -49,   -49,     0,     0,     0,     0,     0,   188,     0,
     167,     0,   -49,     0,     0,   -64,   -64,   -64,   188,   -64,
     -64,   -49,   -64,     0,     0,   -49,     0,     0,   188,   167,
     -63,   -63,   -63,   169,   -63,   -63,     0,   -63,     0,     0,
      59,     0,     0,    59,    59,     0,     0,   167,     0,     0,
       0,     0,     0,     0,   -64,     0,     0,     0,     0,   167,
       0,     0,   167,   186,     0,     0,     0,     0,     0,   -63,
       0,     0,   -69,   -69,   -69,     0,   -69,   -69,     0,   -69,
       0,     0,     0,     0,     0,     0,     0,   186,   290,   291,
     292,     0,     0,     0,     0,     0,     0,   186,   299,   300,
     301,     0,     0,     0,    59,    59,     0,   186,   308,   309,
     310,   -69,     0,     0,   -70,   -70,   -70,   186,   -70,   -70,
       0,   -70,   167,     0,   -16,   321,   -16,   -16,   -16,     0,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,     0,   -16,   -16,
     -16,   -16,     0,   -16,   -16,   -16,   -16,     0,     0,     0,
     -71,   -71,   -71,   -70,   -71,   -71,   -16,   -71,     0,     0,
       0,     0,     0,     0,   -17,   -16,   -17,   -17,   -17,   -16,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,   -17,   -17,
     -17,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,   -71,
     -66,   -66,   -66,     0,   -66,   -66,   -17,   -66,     0,     0,
       0,     0,     0,     0,   -30,   -17,   -30,   -30,   -30,   -17,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,
     -30,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,   -66,
     -65,   -65,   -65,     0,   -65,   -65,   -30,   -65,     0,     0,
       0,     0,     0,     0,   -21,   -30,   -21,   -21,   -21,   -30,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,   -65,
     -59,   -59,   -59,     0,   -59,   -59,   -21,   -59,     0,     0,
       0,     0,     0,     0,   -22,   -21,   -22,   -22,   -22,   -21,
     -22,   -22,   -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,
     -22,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,   -59,
     -60,   -60,   -60,     0,   -60,   -60,   -22,   -60,     0,     0,
       0,     0,     0,     0,   -27,   -22,   -27,   -27,   -27,   -22,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,
     -27,   -27,     0,   -27,   -27,   -27,   -27,     0,     0,   -60,
     -61,   -61,   -61,     0,   -61,   -61,   -27,   -61,     0,     0,
       0,     0,     0,     0,   -28,   -27,   -28,   -28,   -28,   -27,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,   -61,
     -62,   -62,   -62,     0,   -62,   -62,   -28,   -62,     0,     0,
       0,     0,     0,     0,   -29,   -28,   -29,   -29,   -29,   -28,
     -29,   -29,   -29,   -29,   -29,   -29,   -29,     0,   -29,   -29,
     -29,   -29,     0,   -29,   -29,   -29,   -29,     0,     0,   -62,
      26,    27,    28,     0,    29,    30,   -29,   153,     0,     0,
       0,     0,     0,     0,   -23,   -29,   -23,   -23,   -23,   -29,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,    44,
     154,   155,   156,     0,   157,   158,   -23,   159,     0,     0,
       0,     0,     0,     0,   -24,   -23,   -24,   -24,   -24,   -23,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,     0,   -24,   -24,
     -24,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,   165,
     173,   174,   175,     0,   176,   177,   -24,   178,     0,     0,
       0,     0,     0,     0,   -25,   -24,   -25,   -25,   -25,   -24,
     -25,   -25,   -25,   -25,   -25,   -25,   -25,     0,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,   184,
     191,   192,   193,     0,   194,   195,   -25,   196,     0,     0,
       0,     0,     0,     0,   -53,   -25,   -53,   -53,   -53,   -25,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,     0,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -53,   -53,     0,     0,   202,
       0,     0,     0,     0,     0,     0,   -53,     0,     0,     0,
       0,     0,     0,     0,   -26,   -53,   -26,   -26,   -26,   -53,
     -26,   -26,   -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,   -26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -26,     0,     0,     0,
       0,     0,     0,     0,   -32,   -26,   -32,   -32,   -32,   -26,
     -32,   -32,   -32,   -32,   -32,   -32,   -32,     0,   -32,   -32,
     -32,   -32,     0,   -32,   -32,   -32,   -32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -32,     0,     0,     0,
       0,     0,     0,     0,    -9,   -32,    -9,    -9,    -9,   -32,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,     0,    -9,    -9,
      -9,    -9,     0,    -9,    -9,    -9,    -9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -9,     0,     0,     0,
       0,     0,     0,     0,   -52,    -9,   -52,   -52,   -52,    -9,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,     0,   -52,   -52,
     -52,   -52,     0,   -52,   -52,   -52,   -52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -52,     0,     0,     0,
       0,     0,     0,     0,   -18,   -52,   -18,   -18,   -18,   -52,
     -18,   -18,   -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,
     -18,   -18,     0,   -18,   -18,   -18,   -18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -18,     0,     0,     0,
       0,     0,     0,     0,   -31,   -18,   -31,   -31,   -31,   -18,
     -31,   -31,   -31,   -31,   -31,   -31,   -31,     0,   -31,   -31,
     -31,   -31,     0,   -31,   -31,   -31,   -31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -31,     0,     0,     0,
       0,     0,     0,     0,   -51,   -31,   -51,   -51,   -51,   -31,
     -51,   -51,   -51,   -51,   -51,   -51,   -51,     0,   -51,   -51,
     -51,   -51,     0,   -51,   -51,   -51,   -51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -51,     0,     0,     0,
       0,     0,     0,     0,   -48,   -51,   -48,   -48,   -48,   -51,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0,   -48,   -48,
     -48,   -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -48,     0,     0,     0,
       0,     0,     0,     0,   -42,   -48,   -42,   -42,   -42,   -48,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,     0,   -42,   -42,
     -42,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -42,     0,     0,     0,
       0,     0,     0,     0,   -43,   -42,   -43,   -43,   -43,   -42,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,     0,   -43,   -43,
     -43,   -43,     0,   -43,   -43,   -43,   -43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -43,     0,     0,     0,
       0,     0,     0,     0,   -44,   -43,   -44,   -44,   -44,   -43,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -44,     0,     0,     0,
       0,     0,     0,     0,   -45,   -44,   -45,   -45,   -45,   -44,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,     0,   -45,   -45,
     -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -45,     0,     0,     0,
       0,     0,     0,     0,   -46,   -45,   -46,   -46,   -46,   -45,
     -46,   -46,   -46,   -46,   -46,   -46,   -46,     0,   -46,   -46,
     -46,   -46,     0,   -46,   -46,   -46,   -46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -46,     0,     0,     0,
       0,     0,     0,     0,   -47,   -46,   -47,   -47,   -47,   -46,
     -47,   -47,   -47,   -47,   -47,   -47,   -47,     0,   -47,   -47,
     -47,   -47,     0,   -47,   -47,   -47,   -47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -47,     0,     0,     0,
       0,     0,     0,     0,   -20,   -47,   -20,   -20,   -20,   -47,
     -20,   -20,   -20,   -20,   -20,     0,   -20,     0,   -20,   -20,
     -20,   -20,     0,   -20,   -20,   -20,   -20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -20,     0,     0,     0,
       0,     0,     0,     0,    25,   -20,    26,    27,    28,   -20,
      29,    30,    31,    32,    33,     0,    34,     0,    35,    36,
      37,    38,     0,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,   -30,    44,   -30,   -30,   -30,    45,
     -30,   -30,   -30,   -30,   -30,     0,   -30,     0,   -30,   -30,
     -30,   -30,     0,   -30,   -30,   -30,   -30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -30,     0,     0,     0,
       0,     0,     0,     0,   -21,   -30,   -21,   -21,   -21,   -30,
     -21,   -21,   -21,   -21,   -21,     0,   -21,     0,   -21,   -21,
     -21,   -21,     0,   -21,   -21,   -21,   -21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -21,     0,     0,     0,
       0,     0,     0,     0,   -19,   -21,   -19,   -19,   -19,   -21,
     -19,   -19,   -19,   -19,   -19,     0,   -19,     0,   -19,   -19,
     -19,   -19,     0,   -19,   -19,   -19,   -19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -19,     0,     0,     0,
       0,     0,     0,     0,   -22,   -19,   -22,   -22,   -22,   -19,
     -22,   -22,   -22,   -22,   -22,     0,   -22,     0,   -22,   -22,
     -22,   -22,     0,   -22,   -22,   -22,   -22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -22,     0,     0,     0,
       0,     0,     0,     0,   -27,   -22,   -27,   -27,   -27,   -22,
     -27,   -27,   -27,   -27,   -27,     0,   -27,     0,   -27,   -27,
     -27,   -27,     0,   -27,   -27,   -27,   -27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -27,     0,     0,     0,
       0,     0,     0,     0,   -28,   -27,   -28,   -28,   -28,   -27,
     -28,   -28,   -28,   -28,   -28,     0,   -28,     0,   -28,   -28,
     -28,   -28,     0,   -28,   -28,   -28,   -28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -28,     0,     0,     0,
       0,     0,     0,     0,   -29,   -28,   -29,   -29,   -29,   -28,
     -29,   -29,   -29,   -29,   -29,     0,   -29,     0,   -29,   -29,
     -29,   -29,     0,   -29,   -29,   -29,   -29,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -29,     0,     0,     0,
       0,     0,     0,     0,   -23,   -29,   -23,   -23,   -23,   -29,
     -23,   -23,   -23,   -23,   -23,     0,   -23,     0,   -23,   -23,
     -23,   -23,     0,   -23,   -23,   -23,   -23,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -23,     0,     0,     0,
       0,     0,     0,     0,   -24,   -23,   -24,   -24,   -24,   -23,
     -24,   -24,   -24,   -24,   -24,     0,   -24,     0,   -24,   -24,
     -24,   -24,     0,   -24,   -24,   -24,   -24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -24,     0,     0,     0,
       0,     0,     0,     0,   -25,   -24,   -25,   -25,   -25,   -24,
     -25,   -25,   -25,   -25,   -25,     0,   -25,     0,   -25,   -25,
     -25,   -25,     0,   -25,   -25,   -25,   -25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -25,     0,     0,     0,
       0,     0,     0,     0,   -53,   -25,   -53,   -53,   -53,   -25,
     -53,   -53,   -53,   -53,   -53,     0,   -53,     0,   -53,   -53,
     -53,   -53,     0,   -53,   -53,   -53,   -53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -53,     0,     0,     0,
       0,     0,     0,     0,   -26,   -53,   -26,   -26,   -26,   -53,
     -26,   -26,   -26,   -26,   -26,     0,   -26,     0,   -26,   -26,
     -26,   -26,     0,   -26,   -26,   -26,   -26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -26,     0,     0,     0,
       0,     0,     0,     0,   -32,   -26,   -32,   -32,   -32,   -26,
     -32,   -32,   -32,   -32,   -32,     0,   -32,     0,   -32,   -32,
     -32,   -32,     0,   -32,   -32,   -32,   -32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -32,     0,     0,     0,
       0,     0,     0,     0,   -52,   -32,   -52,   -52,   -52,   -32,
     -52,   -52,   -52,   -52,   -52,     0,   -52,     0,   -52,   -52,
     -52,   -52,     0,   -52,   -52,   -52,   -52,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -52,     0,     0,     0,
       0,     0,     0,     0,   -31,   -52,   -31,   -31,   -31,   -52,
     -31,   -31,   -31,   -31,   -31,     0,   -31,     0,   -31,   -31,
     -31,   -31,     0,   -31,   -31,   -31,   -31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -31,     0,     0,     0,
       0,     0,     0,     0,   -51,   -31,   -51,   -51,   -51,   -31,
     -51,   -51,   -51,   -51,   -51,     0,   -51,     0,   -51,   -51,
     -51,   -51,     0,   -51,   -51,   -51,   -51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -51,     0,     0,     0,
       0,     0,     0,     0,   -48,   -51,   -48,   -48,   -48,   -51,
     -48,   -48,   -48,   -48,   -48,     0,   -48,     0,   -48,   -48,
     -48,   -48,     0,   -48,   -48,   -48,   -48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -48,     0,     0,     0,
       0,     0,     0,     0,   -42,   -48,   -42,   -42,   -42,   -48,
     -42,   -42,   -42,   -42,   -42,     0,   -42,     0,   -42,   -42,
     -42,   -42,     0,   -42,   -42,   -42,   -42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -42,     0,     0,     0,
       0,     0,     0,     0,   -43,   -42,   -43,   -43,   -43,   -42,
     -43,   -43,   -43,   -43,   -43,     0,   -43,     0,   -43,   -43,
     -43,   -43,     0,   -43,   -43,   -43,   -43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -43,     0,     0,     0,
       0,     0,     0,     0,   -44,   -43,   -44,   -44,   -44,   -43,
     -44,   -44,   -44,   -44,   -44,     0,   -44,     0,   -44,   -44,
     -44,   -44,     0,   -44,   -44,   -44,   -44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -44,     0,     0,     0,
       0,     0,     0,     0,   -45,   -44,   -45,   -45,   -45,   -44,
     -45,   -45,   -45,   -45,   -45,     0,   -45,     0,   -45,   -45,
     -45,   -45,     0,   -45,   -45,   -45,   -45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -45,     0,     0,     0,
       0,     0,     0,     0,   -46,   -45,   -46,   -46,   -46,   -45,
     -46,   -46,   -46,   -46,   -46,     0,   -46,     0,   -46,   -46,
     -46,   -46,     0,   -46,   -46,   -46,   -46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -46,     0,     0,     0,
       0,     0,     0,     0,   -47,   -46,   -47,   -47,   -47,   -46,
     -47,   -47,   -47,   -47,   -47,     0,   -47,     0,   -47,   -47,
     -47,   -47,     0,   -47,   -47,   -47,   -47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -47,     0,     0,     0,
       0,     0,     0,     0,   -50,   -47,   -50,   -50,   -50,   -47,
     -50,   -50,   -50,   -50,   -50,     0,   -50,     0,   -50,   -50,
     -50,   -50,     0,   -50,   -50,   -50,   -50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -50,     0,     0,     0,
       0,     0,     0,     0,    -9,   -50,    -9,    -9,    -9,   -50,
      -9,    -9,    -9,    -9,    -9,     0,    -9,     0,    -9,    -9,
      -9,    -9,     0,    -9,    -9,    -9,    -9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    -9,     0,     0,     0,
       0,     0,     0,     0,   -16,    -9,   -16,   -16,   -16,    -9,
     -16,   -16,   -16,   -16,   -16,     0,   -16,     0,   -16,   -16,
     -16,   -16,     0,   -16,   -16,   -16,   -16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -16,     0,     0,     0,
       0,     0,     0,     0,   -17,   -16,   -17,   -17,   -17,   -16,
     -17,   -17,   -17,   -17,   -17,     0,   -17,     0,   -17,   -17,
     -17,   -17,     0,   -17,   -17,   -17,   -17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -17,     0,     0,     0,
       0,     0,     0,     0,    25,   -17,    26,    27,    28,   -17,
      29,    30,    31,    32,    33,     0,    34,     0,    35,    36,
      37,    38,     0,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    25,    44,    26,    27,    28,   329,
      29,    30,    31,    32,    33,     0,    34,     0,    35,    36,
      37,    38,     0,    39,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,   -18,    44,   -18,   -18,   -18,   331,
     -18,   -18,   -18,   -18,   -18,     0,   -18,     0,   -18,   -18,
     -18,   -18,     0,   -18,   -18,   -18,   -18,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -18,     0,     0,     0,
       0,     0,     0,     0,   -49,   -18,   -49,   -49,   -49,   -18,
     -49,   -49,   -49,   -49,   -49,     0,   -49,     0,   -49,   -49,
     -49,   -49,     0,   -49,   -49,   -49,   -49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -49,     0,     0,     0,
       0,     0,     0,     0,   219,   -49,    26,    27,    28,   -49,
      29,    30,   220,    32,   221,     0,   222,     0,   223,   224,
      37,    38,     0,   225,   226,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    25,   227,    26,
      27,    28,     0,    29,    30,    31,    32,    33,     0,    34,
       0,    35,    36,    37,    38,     0,    39,    40,    41,    42,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,   -54,     0,     0,     0,    44,     0,
       0,   239,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,     0,   -54,   -54,   -54,   -54,   -75,   252,   -54,   -54,
       0,     0,     0,     0,   -75,   -75,   -75,   -75,   -75,   -75,
     -75,   -75,   -75,     0,   -75,   -75,   -75,   -75,   -76,     0,
     -75,   -75,     0,     0,     0,     0,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,     0,   -76,   -76,   -76,   -76,
     -78,     0,   -76,   -76,     0,     0,     0,     0,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -78,     0,   -78,   -78,
     -78,   -78,   -77,     0,   -78,   -78,     0,     0,     0,     0,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,     0,
     -77,   -77,   -77,   -77,   -79,     0,   -77,   -77,     0,     0,
       0,     0,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,     0,   -79,   -79,   -79,   -79,   -73,     0,   -79,   -79,
       0,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,     0,   -73,   -73,   -73,   -73,   -37,     0,
     -73,   -73,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     0,    92,    93,    94,    95,
     -58,     0,   -37,   -37,     0,     0,     0,     0,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -58,   -58,   -74,     0,   -58,   -58,     0,     0,     0,     0,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     0,
     -74,   -74,   -74,   -74,   -72,     0,   -74,   -74,     0,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,     0,   -72,   -72,   -72,   -72,   -55,     0,   -72,   -72,
       0,     0,     0,     0,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,     0,   -55,   -55,   -55,   -55,   -57,     0,
     -55,   -55,     0,     0,     0,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,     0,   -57,   -57,   -57,   -57,
     -56,     0,   -57,   -57,     0,     0,     0,     0,   -56,   -56,
     -56,   -56,   -56,   -56,   -56,   -56,   -56,     0,   -56,   -56,
     -56,   -56,   -80,     0,   -56,   -56,     0,     0,     0,     0,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,
     -80,   -80,   -80,   -80,   -54,     0,   -80,   -80,     0,     0,
       0,     0,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -75,   -54,   -54,   -54,   -54,     0,   242,   -54,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -76,   -75,
     -75,   -75,   -75,     0,     0,   -75,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -78,   -76,   -76,   -76,   -76,
       0,     0,   -76,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -77,   -78,   -78,   -78,   -78,     0,     0,   -78,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -79,
     -77,   -77,   -77,   -77,     0,     0,   -77,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -73,   -79,   -79,   -79,
     -79,     0,     0,   -79,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -37,   -73,   -73,   -73,   -73,     0,     0,
     -73,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     -58,    92,    93,    94,    95,     0,     0,   -37,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -74,   -58,   -58,
     -58,   -58,     0,     0,   -58,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -72,   -74,   -74,   -74,   -74,     0,
       0,   -74,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -55,   -72,   -72,   -72,   -72,     0,     0,   -72,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -57,   -55,
     -55,   -55,   -55,     0,     0,   -55,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -56,   -57,   -57,   -57,   -57,
       0,     0,   -57,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -80,   -56,   -56,   -56,   -56,     0,     0,   -56,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -54,
     -80,   -80,   -80,   -80,     0,     0,   -80,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,    63,   -54,     0,     0,     0,     0,     0,     0,
       0,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,    63,     0,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -73,   -54,   -54,
     -54,   -54,     0,   262,     0,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    82,   -73,   -73,   -73,   -73,   -73,
     -73,     0,     0,     0,     0,     0,     0,     0,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   287,   -73,   -73,
     -73,   -73,   -73,   -75,     0,     0,     0,     0,     0,     0,
       0,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,
     -76,   -75,   -75,   -75,   -75,   -75,     0,     0,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -78,   -76,   -76,
     -76,   -76,   -76,     0,     0,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   -78,   -77,   -78,   -78,   -78,   -78,   -78,
       0,     0,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -79,   -77,   -77,   -77,   -77,   -77,     0,     0,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -37,   -79,
     -79,   -79,   -79,   -79,     0,     0,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   -58,    92,    93,    94,    95,
     -37,     0,     0,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -74,   -58,   -58,   -58,   -58,   -58,     0,     0,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -73,
     -74,   -74,   -74,   -74,   -74,     0,     0,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -72,   -73,   -73,   -73,
     -73,   -73,     0,     0,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -55,   -72,   -72,   -72,   -72,   -72,     0,
       0,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -57,   -55,   -55,   -55,   -55,   -55,     0,     0,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   -56,   -57,   -57,
     -57,   -57,   -57,     0,     0,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -56,   -56,   -80,   -56,   -56,   -56,   -56,   -56,
       0,     0,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   -75,   -80,   -80,   -80,   -80,   -80,     0,     0,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -76,   -75,
     -75,   -75,   -75,     0,     0,     0,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -78,   -76,   -76,   -76,   -76,
       0,     0,     0,   -78,   -78,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -77,   -78,   -78,   -78,   -78,     0,     0,     0,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -79,
     -77,   -77,   -77,   -77,     0,     0,     0,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -73,   -79,   -79,   -79,
     -79,     0,     0,     0,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   -73,   -73,   -37,   -73,   -73,   -73,   -73,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     -58,    92,    93,    94,    95,     0,     0,     0,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -74,   -58,   -58,
     -58,   -58,     0,     0,     0,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -72,   -74,   -74,   -74,   -74,     0,
       0,     0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -55,   -72,   -72,   -72,   -72,     0,     0,     0,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -57,   -55,
     -55,   -55,   -55,     0,     0,     0,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   -56,   -57,   -57,   -57,   -57,
       0,     0,     0,   -56,   -56,   -56,   -56,   -56,   -56,   -56,
     -56,   -56,   -80,   -56,   -56,   -56,   -56,     0,     0,     0,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,
     -80,   -80,   -80,   -80
};

static const yytype_int16 yycheck[] =
{
       0,    23,    82,   126,     4,   227,    18,     0,   242,   126,
     127,     0,    34,     9,   169,     0,     1,   239,   252,   126,
       9,     0,    44,   126,     9,     3,     4,     5,   262,     7,
       8,   126,    10,   188,   151,   126,    10,   169,   272,    17,
      18,    63,    64,   169,    22,    23,   126,    43,    70,   126,
     205,    73,    74,   127,    76,    33,   188,    23,    80,    19,
      82,    42,   188,    43,    42,    43,    19,    19,    34,    19,
      19,    10,    19,   205,    96,    97,    98,   151,    44,   205,
       3,     4,     5,    43,     7,     8,    45,    10,    19,    41,
      43,    44,    41,    43,    17,    18,    43,    63,    64,    22,
      23,     9,   124,    10,   126,   127,    19,    73,    74,    10,
      33,    41,    43,    44,    80,   127,    82,    42,    41,    42,
       3,     4,     5,     6,     7,     8,   126,    10,    41,   151,
      96,    97,    98,     3,     4,     5,     0,     7,     8,   151,
      10,    19,    25,   165,    19,     9,    19,    17,    18,    17,
      18,    42,    22,    23,    22,    23,    41,    42,   124,    42,
     126,   127,   184,    33,    19,    43,    44,    19,    43,    44,
      43,    41,    42,    19,     3,     4,     5,    19,     7,     8,
     202,    10,    19,    19,    19,   151,    41,    10,    17,    18,
      43,    43,   214,    22,    23,   217,   218,    43,    44,   165,
     222,    43,    44,    42,    33,    41,    43,   287,    43,    44,
       3,     4,     5,    42,     7,     8,    42,    10,   184,    19,
     242,    43,    44,    19,   246,   348,   349,   249,   250,   251,
     252,   348,   349,    42,   256,    42,   202,   259,   260,   261,
     262,   348,   349,    43,   266,   348,   349,    43,   214,    42,
     272,   217,   218,   348,   349,   277,   222,   348,   349,   281,
     282,   283,   284,    19,    42,   287,   288,    19,   348,   349,
      42,   348,   349,    19,   348,   349,   242,    19,    19,    43,
      44,    43,    44,   249,   250,   251,   252,    43,    23,    19,
      19,    43,    44,   259,   260,   261,   262,    43,    44,    34,
      19,    43,    43,   269,   270,   271,   272,    43,    42,    44,
      19,   277,    19,    43,    43,    43,   282,   283,   284,    19,
      43,   287,   288,    43,    43,    43,   348,   349,    63,    64,
       3,     4,     5,     6,     7,     8,    43,    10,    73,    74,
      43,     0,    19,    43,    23,    80,    43,    82,   348,   349,
       9,     0,    25,    17,    18,    34,    19,    19,    22,    23,
       9,    96,    97,    98,    43,    44,    43,    23,    19,    42,
      42,    43,     3,     4,     5,     6,     7,     8,    34,    10,
      43,    43,   348,   349,    63,    64,    43,    41,    44,   124,
      41,   126,   127,    19,    25,     3,     4,     5,    19,     7,
       8,    80,    10,    82,    19,    19,    43,    63,    64,    17,
      18,    42,     0,    19,    22,    23,   151,    43,    19,    43,
      19,     9,    43,     0,    80,    33,    82,    43,    43,    43,
     165,    41,     9,    19,    42,    41,     3,     4,     5,    41,
       7,     8,    43,    10,    43,   124,    41,   126,   127,   184,
      17,    18,    41,    19,    19,    22,    23,    43,     3,     4,
       5,     6,     7,     8,    19,    10,    33,   202,   124,    19,
     126,   127,   151,    41,    43,    42,    19,    43,    43,   214,
      25,    19,   217,   218,    19,   164,   165,   222,    43,    19,
      19,    41,     0,     0,    41,   151,    19,    42,    41,    19,
      42,     9,     9,    41,   183,   184,    41,   242,    42,   165,
      42,    41,    41,    10,   249,   250,   251,   252,    41,    23,
      42,    42,   201,   202,   259,   260,   261,   262,   184,    42,
      34,    42,    42,    42,    19,   214,    42,   272,   217,   218,
      44,    42,   277,   222,    42,    41,   202,   282,   283,   284,
      17,    18,   287,   288,    43,    22,    23,    43,   214,    63,
      64,   217,   218,   242,    17,    18,   222,    43,    43,    22,
      23,    43,    43,   252,    42,    19,    80,    42,    82,    42,
       3,     4,     5,   262,     7,     8,   242,    10,    42,    19,
      42,    41,    43,   272,    17,    18,   252,    43,   277,    22,
      23,    43,    43,    43,    43,   284,   262,    43,   287,   288,
      33,    43,    43,   348,   349,    43,   272,    43,    43,    42,
     124,   277,   126,   127,    43,    43,    43,    19,   284,    44,
      19,   287,   288,     3,     4,     5,    43,     7,     8,    41,
      10,    41,    41,    41,    41,    41,     4,   151,    63,    64,
     124,    -1,    -1,    -1,    69,    -1,    71,    72,    -1,    -1,
      75,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   348,
     349,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,    -1,     3,     4,     5,    -1,     7,     8,    -1,    10,
      -1,    -1,   348,   349,    -1,    -1,    17,    18,   202,    -1,
      -1,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,   124,
     214,    -1,    33,   217,   218,    -1,    -1,    -1,   222,    -1,
       1,    42,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,   242,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,   252,    -1,
     165,    -1,    33,    -1,    -1,     3,     4,     5,   262,     7,
       8,    42,    10,    -1,    -1,    46,    -1,    -1,   272,   184,
       3,     4,     5,   277,     7,     8,    -1,    10,    -1,    -1,
     284,    -1,    -1,   287,   288,    -1,    -1,   202,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,   214,
      -1,    -1,   217,   218,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,     3,     4,     5,    -1,     7,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,   254,
     255,    -1,    -1,    -1,   348,   349,    -1,   262,   263,   264,
     265,    42,    -1,    -1,     3,     4,     5,   272,     7,     8,
      -1,    10,   277,    -1,     1,   280,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
       3,     4,     5,    42,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
       3,     4,     5,    -1,     7,     8,    33,    10,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    12,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    42,     3,     4,     5,    46,
       7,     8,     9,    10,    11,    -1,    13,    -1,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,     1,    45,     3,
       4,     5,    -1,     7,     8,     9,    10,    11,    -1,    13,
      -1,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    42,    -1,
      -1,    45,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    19,    42,    43,    44,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    19,    -1,
      43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    19,    -1,    43,    44,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    19,    -1,    43,    44,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    19,    -1,
      43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    19,    -1,    43,    44,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    19,    -1,    43,    44,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    19,    -1,
      43,    44,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      19,    -1,    43,    44,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    19,    -1,    43,    44,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    19,    -1,    43,    44,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    37,    38,    39,    40,    -1,    42,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    37,
      38,    39,    40,    -1,    -1,    43,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    19,    37,    38,    39,    40,
      -1,    -1,    43,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    19,    37,    38,    39,    40,    -1,    -1,    43,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    19,
      37,    38,    39,    40,    -1,    -1,    43,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    19,    37,    38,    39,
      40,    -1,    -1,    43,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    19,    37,    38,    39,    40,    -1,    -1,
      43,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      19,    37,    38,    39,    40,    -1,    -1,    43,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    19,    37,    38,
      39,    40,    -1,    -1,    43,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    19,    37,    38,    39,    40,    -1,
      -1,    43,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    37,    38,    39,    40,    -1,    -1,    43,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    37,
      38,    39,    40,    -1,    -1,    43,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    19,    37,    38,    39,    40,
      -1,    -1,    43,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    19,    37,    38,    39,    40,    -1,    -1,    43,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    19,
      37,    38,    39,    40,    -1,    -1,    43,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      19,    37,    38,    39,    40,    41,    42,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    19,    37,    38,
      39,    40,    -1,    42,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      19,    37,    38,    39,    40,    41,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    19,    37,    38,
      39,    40,    41,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    19,    37,    38,    39,    40,    41,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    37,    38,    39,    40,    41,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    37,
      38,    39,    40,    41,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    19,    37,    38,    39,    40,
      41,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    19,    37,    38,    39,    40,    41,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    19,
      37,    38,    39,    40,    41,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    19,    37,    38,    39,
      40,    41,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    19,    37,    38,    39,    40,    41,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      19,    37,    38,    39,    40,    41,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    19,    37,    38,
      39,    40,    41,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    19,    37,    38,    39,    40,    41,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    37,    38,    39,    40,    41,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    37,
      38,    39,    40,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    19,    37,    38,    39,    40,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    19,    37,    38,    39,    40,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    19,
      37,    38,    39,    40,    -1,    -1,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    19,    37,    38,    39,
      40,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    19,    37,    38,    39,    40,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      19,    37,    38,    39,    40,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    19,    37,    38,
      39,    40,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    19,    37,    38,    39,    40,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    19,    37,    38,    39,    40,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    19,    37,
      38,    39,    40,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    19,    37,    38,    39,    40,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    19,    37,    38,    39,    40,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     9,    48,    49,    50,    51,    10,     0,    50,
      51,    41,    52,    42,     9,    53,    54,    10,    43,    44,
      45,    56,     9,    57,    10,     1,     3,     4,     5,     7,
       8,     9,    10,    11,    13,    15,    16,    17,    18,    20,
      21,    22,    23,    33,    42,    46,    50,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      74,    75,    10,    42,    42,    41,    60,    61,    69,    42,
      42,    42,    42,    42,    42,    42,    42,    60,    61,    41,
      19,    41,    36,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    37,    38,    39,    40,    71,    72,    73,    61,
      76,    77,    61,    41,    61,    62,    10,    69,    62,    62,
       6,    25,    74,     6,    25,    74,    62,    69,    43,    61,
      59,    74,    74,    74,    44,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    77,
      55,    56,    58,    55,    41,    41,    41,    41,    41,    41,
      41,    12,    55,    10,     3,     4,     5,     7,     8,    10,
      17,    18,    22,    23,    33,    42,    60,    62,    69,    70,
      74,    75,    41,     3,     4,     5,     7,     8,    10,    17,
      18,    22,    23,    33,    42,    60,    62,    69,    70,    74,
      75,     3,     4,     5,     7,     8,    10,    17,    18,    22,
      23,    33,    42,    60,    69,    70,    74,    75,     3,     4,
       5,     7,     8,    10,    42,    69,    75,    19,    19,     1,
       9,    11,    13,    15,    16,    20,    21,    45,    50,    59,
      60,    61,    63,    64,    65,    66,    67,    68,    69,    45,
      56,    58,    42,    42,    42,    42,    42,    60,    61,    71,
      72,    73,    42,    42,    42,    42,    42,    60,    61,    71,
      72,    73,    42,    42,    42,    42,    42,    60,    61,    71,
      72,    73,    42,    61,    61,    61,    10,    42,    41,    61,
      42,    42,    42,    42,    57,    41,    41,    36,    57,    76,
      62,    62,    62,    69,    43,    74,    74,    74,    76,    62,
      62,    62,    69,    43,    74,    74,    74,    76,    62,    62,
      62,    69,    43,    74,    74,    74,    76,    43,    41,    61,
      41,    62,    69,     6,    25,    74,     6,    25,    74,    46,
      59,    46,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    55,    55,    41,
      41,    41,    41,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    49,    49,    50,
      52,    51,    53,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    63,    63,    63,    64,    64,    64,    65,    66,
      66,    67,    68,    68,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      75,    76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     0,     3,
       0,     7,     1,     0,     4,     2,     1,     1,     3,     2,
       0,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     3,     2,     4,     4,     4,     4,     1,     2,     1,
       1,     3,     5,     5,     5,     5,     5,     5,     5,     5,
       7,     5,     3,     2,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     0,     3,     1
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
#line 114 "parser.y" /* yacc.c:1646  */
    { 
        parser_tree = (yyvsp[0].node);
        check_semantic_error_no_main();
    }
#line 2378 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 118 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 2384 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2392 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 125 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 128 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("DECLARATION_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 131 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 2416 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = NULL;
    }
#line 2424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, (yyvsp[-2].token), (yyvsp[-1].token));
        add_symbol((yyvsp[-1].token), (yyvsp[-2].token), "variable");
    }
#line 2433 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "parser.y" /* yacc.c:1646  */
    { 
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "function");
        push_stack((yyvsp[0].token), (yyvsp[-1].token));
    }
#line 2442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 151 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FUNCTION", (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-6].token), (yyvsp[-5].token));
        pop_stack();
    }
#line 2451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 158 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2459 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 161 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 167 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", (yyvsp[-3].node), NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2476 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 171 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("PARAMETER", NULL, NULL, (yyvsp[-1].token), (yyvsp[0].token));
        add_symbol((yyvsp[0].token), (yyvsp[-1].token), "parameter");
    }
#line 2485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 177 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 180 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("COMPOUND_STATEMENT", (yyvsp[-1].node), NULL , NULL, NULL);
    }
#line 2509 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 192 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("STATEMENT_LIST", (yyvsp[-1].node), (yyvsp[0].node), NULL, NULL);
    }
#line 2517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 195 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL; 
    }
#line 2525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 204 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 207 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 210 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2557 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 213 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 216 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 219 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 222 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 225 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
        yyerrok;
    }
#line 2606 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 235 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ASSIGN_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
         define_type((yyval.node));
    }
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 239 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2623 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 245 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 248 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("REMOVE_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 251 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EXISTS_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 254 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IS_SET_STATEMENT", (yyvsp[-1].node), NULL, "set", (yyvsp[-3].token));
    }
#line 2655 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 260 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 263 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
    }
#line 2671 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 266 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2679 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 269 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("IN_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].token));
    }
#line 2695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 281 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2703 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 284 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 287 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITE_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 293 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", (yyvsp[-2].token));
    }
#line 2727 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 296 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", (yyvsp[-2].token));
    }
#line 2735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 299 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("WRITELN_STATEMENT", (yyvsp[-2].node), NULL, (yyvsp[-2].node)->type, (yyvsp[-4].token)); 
    }
#line 2743 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 305 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("READ_STATEMENT", (yyvsp[-2].node), NULL, NULL, (yyvsp[-4].token));
    }
#line 2751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 311 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 314 "parser.y" /* yacc.c:1646  */
    {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT_ELSE", (yyvsp[0].node), NULL, NULL, (yyvsp[-1].token));
        (yyval.node) = create_tree_node("CONDITIONAL_STATEMENT_IF", (yyvsp[-2].node), aux_node, NULL, (yyvsp[-6].token));
    }
#line 2768 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 321 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ITERATION_STATEMENT", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-4].token));
    }
#line 2776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 327 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", (yyvsp[-1].node), NULL, NULL, (yyvsp[-2].token)); 
        define_type((yyval.node));
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2786 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 332 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", (yyvsp[-1].token)); 
        check_semantic_error_return_type((yyval.node)->type, (yyval.node));
    }
#line 2795 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 339 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[0].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("VARIABLE", NULL, NULL, type, (yyvsp[0].token));
    }
#line 2808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 350 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ARITHIMETIC_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 354 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("LOGICAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 358 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("RELATIONAL_EXPRESSION", (yyvsp[-2].node), (yyvsp[0].node), NULL, (yyvsp[-1].node)->value);
        define_type((yyval.node));
    }
#line 2835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 362 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2843 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 367 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("ADD_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2851 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 369 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("SUB_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 371 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("MULT_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 373 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("DIV_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 378 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("GE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2883 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 380 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("LE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 382 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("G_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2899 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 384 "parser.y" /* yacc.c:1646  */
    {
       (yyval.node) = create_tree_node("L_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2907 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 386 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("NE_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 388 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("EQ_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2923 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 393 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("OR_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2931 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 395 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("AND_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 397 "parser.y" /* yacc.c:1646  */
    {
        (yyval.node) = create_tree_node("NOT_OP", NULL, NULL, NULL, (yyvsp[0].token));
    }
#line 2947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 405 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[-1].node); 
    }
#line 2955 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 408 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2963 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 411 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 414 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("INTEGER", NULL, NULL, "int", (yyvsp[0].token)); 
    }
#line 2979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 417 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("FLOATNUMBER", NULL, NULL, "float", (yyvsp[0].token)); 
    }
#line 2987 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 420 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ELEM", NULL, NULL, "elem", (yyvsp[0].token)); 
    }
#line 2995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 423 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("SET", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 3003 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 426 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("EMPTY_VALUE", NULL, NULL, "set", (yyvsp[0].token)); 
    }
#line 3011 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 432 "parser.y" /* yacc.c:1646  */
    {
        symbol_node* s = search_for_symbol((yyvsp[-3].token));
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        (yyval.node) = create_tree_node("FUNCTION_CALL", (yyvsp[-1].node), NULL, type, (yyvsp[-3].token));
        check_semantic_error_type_mismatch_args((yyvsp[-1].node), (yyvsp[-3].token));
    }
#line 3025 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 444 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 3033 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 447 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = NULL;
    }
#line 3041 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 453 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = create_tree_node("ARGS_LIST", (yyvsp[-2].node), (yyvsp[0].node), NULL, NULL); 
    }
#line 3049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 456 "parser.y" /* yacc.c:1646  */
    { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 3057 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3061 "parser.tab.c" /* yacc.c:1646  */
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
#line 461 "parser.y" /* yacc.c:1906  */


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
