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


/* Substitute the variable and function names.  */
#define yyparse         semanage_parse
#define yylex           semanage_lex
#define yyerror         semanage_error
#define yydebug         semanage_debug
#define yynerrs         semanage_nerrs

#define yylval          semanage_lval
#define yychar          semanage_char

/* Copy the first part of user declarations.  */
#line 21 "conf-parse.y" /* yacc.c:339  */


#include "semanage_conf.h"

#include <sepol/policydb.h>
#include <selinux/selinux.h>
#include <semanage/handle.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int semanage_lex(void);                /* defined in conf-scan.c */
extern int semanage_lex_destroy(void);        /* defined in conf-scan.c */
int semanage_error(const char *msg);

extern FILE *semanage_in;
extern char *semanage_text;

static int parse_module_store(char *arg);
static int parse_store_root_path(char *arg);
static int parse_compiler_path(char *arg);
static void semanage_conf_external_prog_destroy(external_prog_t *ep);
static int new_external_prog(external_prog_t **chain);

static semanage_conf_t *current_conf;
static external_prog_t *new_external;
static int parse_errors;

#define PASSIGN(p1,p2) { free(p1); p1 = p2; }


#line 108 "conf-parse.c" /* yacc.c:339  */

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
   by #include "conf-parse.h".  */
#ifndef YY_SEMANAGE_CONF_PARSE_H_INCLUDED
# define YY_SEMANAGE_CONF_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int semanage_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MODULE_STORE = 258,
    VERSION = 259,
    EXPAND_CHECK = 260,
    FILE_MODE = 261,
    SAVE_PREVIOUS = 262,
    SAVE_LINKED = 263,
    TARGET_PLATFORM = 264,
    COMPILER_DIR = 265,
    IGNORE_MODULE_CACHE = 266,
    STORE_ROOT = 267,
    LOAD_POLICY_START = 268,
    SETFILES_START = 269,
    SEFCONTEXT_COMPILE_START = 270,
    DISABLE_GENHOMEDIRCON = 271,
    HANDLE_UNKNOWN = 272,
    USEPASSWD = 273,
    IGNOREDIRS = 274,
    BZIP_BLOCKSIZE = 275,
    BZIP_SMALL = 276,
    REMOVE_HLL = 277,
    VERIFY_MOD_START = 278,
    VERIFY_LINKED_START = 279,
    VERIFY_KERNEL_START = 280,
    BLOCK_END = 281,
    PROG_PATH = 282,
    PROG_ARGS = 283,
    ARG = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 57 "conf-parse.y" /* yacc.c:355  */

        int d;
        char *s;

#line 183 "conf-parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE semanage_lval;

int semanage_parse (void);

#endif /* !YY_SEMANAGE_CONF_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "conf-parse.c" /* yacc.c:358  */

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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   70

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  97

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    72,    72,    73,    76,    77,    78,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,   100,   110,   119,   128,   140,   151,
     163,   169,   175,   188,   200,   211,   222,   227,   240,   249,
     260,   272,   281,   289,   297,   307,   315,   323,   324,   325,
     328,   329,   332,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MODULE_STORE", "VERSION",
  "EXPAND_CHECK", "FILE_MODE", "SAVE_PREVIOUS", "SAVE_LINKED",
  "TARGET_PLATFORM", "COMPILER_DIR", "IGNORE_MODULE_CACHE", "STORE_ROOT",
  "LOAD_POLICY_START", "SETFILES_START", "SEFCONTEXT_COMPILE_START",
  "DISABLE_GENHOMEDIRCON", "HANDLE_UNKNOWN", "USEPASSWD", "IGNOREDIRS",
  "BZIP_BLOCKSIZE", "BZIP_SMALL", "REMOVE_HLL", "VERIFY_MOD_START",
  "VERIFY_LINKED_START", "VERIFY_KERNEL_START", "BLOCK_END", "PROG_PATH",
  "PROG_ARGS", "ARG", "'='", "$accept", "config_file", "config_line",
  "single_opt", "module_store", "store_root", "compiler_dir",
  "ignore_module_cache", "version", "target_platform", "expand_check",
  "file_mode", "save_previous", "save_linked", "disable_genhomedircon",
  "usepasswd", "ignoredirs", "handle_unknown", "bzip_blocksize",
  "bzip_small", "remove_hll", "command_block", "command_start",
  "verify_block", "verify_start", "verify_start_tok", "external_opts",
  "external_opt", YY_NULLPTR
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
      61
};
# endif

#define YYPACT_NINF -48

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-48)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,    -5,     0,     1,     2,     3,     4,     5,     6,     7,
       8,   -48,   -48,   -48,     9,    10,    11,    12,    13,    14,
      15,   -48,   -48,   -48,    28,    -2,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,    -1,   -48,    -1,   -48,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      29,    30,    31,    32,    33,    34,   -48,   -48,    35,    36,
      38,    -1,    41,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
      39,    40,   -48,   -48,   -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,    47,    48,    49,     0,     3,     4,     7,    10,    11,
      12,     8,     9,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,     5,    51,     6,    51,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,    51,     0,    24,    28,    30,    31,    32,    33,    29,
      26,    27,    25,    34,    37,    35,    36,    38,    39,    40,
       0,     0,    41,    50,    45,    52,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,    45,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   -48,   -48,   -48,   -48,   -47,   -48
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    70,    71
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      72,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    93,    49,    68,    69,    66,     0,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    84,    85,
      86,    87,    88,    89,    92,    90,    91,    94,    95,    96,
      67
};

static const yytype_int8 yycheck[] =
{
      47,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    71,    30,    27,    28,     0,    -1,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    -1,    29,    29,
      29,    29,    29,    29,    26,    30,    30,    26,    29,    29,
      25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,    30,    30,    30,     0,    32,    27,    28,
      57,    58,    57,    29,    29,    29,    29,    29,    29,    29,
      29,    29,    29,    29,    29,    29,    29,    29,    29,    29,
      30,    30,    26,    57,    26,    29,    29
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    53,    53,    54,    55,    56,    56,    56,
      57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     0,     3,     3
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
        case 24:
#line 100 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (parse_module_store((yyvsp[0].s)) != 0) {
                                parse_errors++;
                                YYABORT;
                        }
                        free((yyvsp[0].s));
                }
#line 1350 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 110 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (parse_store_root_path((yyvsp[0].s)) != 0) {
                                parse_errors++;
                                YYABORT;
                        }
                        free((yyvsp[0].s));
                }
#line 1362 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 119 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (parse_compiler_path((yyvsp[0].s)) != 0) {
                                parse_errors++;
                                YYABORT;
                        }
                        free((yyvsp[0].s));
                }
#line 1374 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "conf-parse.y" /* yacc.c:1646  */
    {
							if (strcasecmp((yyvsp[0].s), "true") == 0)
								current_conf->ignore_module_cache = 1;
							else if (strcasecmp((yyvsp[0].s), "false") == 0)
								current_conf->ignore_module_cache = 0;
							else {
								yyerror("disable-caching can only be 'true' or 'false'");
							}
							free((yyvsp[0].s));
						}
#line 1389 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 140 "conf-parse.y" /* yacc.c:1646  */
    {
                        current_conf->policyvers = atoi((yyvsp[0].s));
                        free((yyvsp[0].s));
                        if (current_conf->policyvers < sepol_policy_kern_vers_min() ||
                            current_conf->policyvers > sepol_policy_kern_vers_max()) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1403 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 151 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (strcasecmp((yyvsp[0].s), "selinux") == 0)
                                current_conf->target_platform = SEPOL_TARGET_SELINUX;
                        else if (strcasecmp((yyvsp[0].s), "xen") == 0)
                                current_conf->target_platform = SEPOL_TARGET_XEN;
                        else {
                                yyerror("target_platform can only be 'selinux' or 'xen'");
                        }
                        free((yyvsp[0].s));
                }
#line 1418 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 163 "conf-parse.y" /* yacc.c:1646  */
    {
                        current_conf->expand_check = atoi((yyvsp[0].s));
                        free((yyvsp[0].s));
                }
#line 1427 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 169 "conf-parse.y" /* yacc.c:1646  */
    {
                        current_conf->file_mode = strtoul((yyvsp[0].s), NULL, 8);
                        free((yyvsp[0].s));
                }
#line 1436 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 175 "conf-parse.y" /* yacc.c:1646  */
    {
	                if (strcasecmp((yyvsp[0].s), "true") == 0)
		                current_conf->save_previous = 1;
			else if (strcasecmp((yyvsp[0].s), "false") == 0)
				current_conf->save_previous = 0;		
			else {
				yyerror("save-previous can only be 'true' or 'false'");
			}
			free((yyvsp[0].s));
                }
#line 1451 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 188 "conf-parse.y" /* yacc.c:1646  */
    {
	                if (strcasecmp((yyvsp[0].s), "true") == 0)
		                current_conf->save_linked = 1;
			else if (strcasecmp((yyvsp[0].s), "false") == 0)
				current_conf->save_linked = 0;		
			else {
				yyerror("save-linked can only be 'true' or 'false'");
			}
			free((yyvsp[0].s));
                }
#line 1466 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 200 "conf-parse.y" /* yacc.c:1646  */
    {
	if (strcasecmp((yyvsp[0].s), "false") == 0) {
		current_conf->disable_genhomedircon = 0;
	} else if (strcasecmp((yyvsp[0].s), "true") == 0) {
		current_conf->disable_genhomedircon = 1;
	} else {
		yyerror("disable-genhomedircon can only be 'true' or 'false'");
	}
	free((yyvsp[0].s));
 }
#line 1481 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "conf-parse.y" /* yacc.c:1646  */
    {
	if (strcasecmp((yyvsp[0].s), "false") == 0) {
		current_conf->usepasswd = 0;
	} else if (strcasecmp((yyvsp[0].s), "true") == 0) {
		current_conf->usepasswd = 1;
	} else {
		yyerror("usepasswd can only be 'true' or 'false'");
	}
	free((yyvsp[0].s));
 }
#line 1496 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 222 "conf-parse.y" /* yacc.c:1646  */
    {
	current_conf->ignoredirs = strdup((yyvsp[0].s));
	free((yyvsp[0].s));
 }
#line 1505 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 227 "conf-parse.y" /* yacc.c:1646  */
    {
	if (strcasecmp((yyvsp[0].s), "deny") == 0) {
		current_conf->handle_unknown = SEPOL_DENY_UNKNOWN;
	} else if (strcasecmp((yyvsp[0].s), "reject") == 0) {
		current_conf->handle_unknown = SEPOL_REJECT_UNKNOWN;
	} else if (strcasecmp((yyvsp[0].s), "allow") == 0) {
		current_conf->handle_unknown = SEPOL_ALLOW_UNKNOWN;
	} else {
		yyerror("handle-unknown can only be 'deny', 'reject' or 'allow'");
	}
	free((yyvsp[0].s));
 }
#line 1522 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 240 "conf-parse.y" /* yacc.c:1646  */
    {
	int blocksize = atoi((yyvsp[0].s));
	free((yyvsp[0].s));
	if (blocksize > 9)
		yyerror("bzip-blocksize can only be in the range 0-9");
	else
		current_conf->bzip_blocksize = blocksize;
}
#line 1535 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 249 "conf-parse.y" /* yacc.c:1646  */
    {
	if (strcasecmp((yyvsp[0].s), "false") == 0) {
		current_conf->bzip_small = 0;
	} else if (strcasecmp((yyvsp[0].s), "true") == 0) {
		current_conf->bzip_small = 1;
	} else {
		yyerror("bzip-small can only be 'true' or 'false'");
	}
	free((yyvsp[0].s));
}
#line 1550 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "conf-parse.y" /* yacc.c:1646  */
    {
	if (strcasecmp((yyvsp[0].s), "false") == 0) {
		current_conf->remove_hll = 0;
	} else if (strcasecmp((yyvsp[0].s), "true") == 0) {
		current_conf->remove_hll = 1;
	} else {
		yyerror("remove-hll can only be 'true' or 'false'");
	}
	free((yyvsp[0].s));
}
#line 1565 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 272 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (new_external->path == NULL) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1576 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 281 "conf-parse.y" /* yacc.c:1646  */
    {
                        semanage_conf_external_prog_destroy(current_conf->load_policy);
                        current_conf->load_policy = NULL;
                        if (new_external_prog(&current_conf->load_policy) == -1) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1589 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 289 "conf-parse.y" /* yacc.c:1646  */
    {
                        semanage_conf_external_prog_destroy(current_conf->setfiles);
                        current_conf->setfiles = NULL;
                        if (new_external_prog(&current_conf->setfiles) == -1) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1602 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 297 "conf-parse.y" /* yacc.c:1646  */
    {
                        semanage_conf_external_prog_destroy(current_conf->sefcontext_compile);
                        current_conf->sefcontext_compile = NULL;
                        if (new_external_prog(&current_conf->sefcontext_compile) == -1) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1615 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 307 "conf-parse.y" /* yacc.c:1646  */
    {
                        if (new_external->path == NULL) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1626 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 315 "conf-parse.y" /* yacc.c:1646  */
    {
                        if ((yyvsp[0].d) == -1) {
                                parse_errors++;
                                YYABORT;
                        }
                }
#line 1637 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 323 "conf-parse.y" /* yacc.c:1646  */
    {(yyval.d) = new_external_prog(&current_conf->mod_prog);}
#line 1643 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 324 "conf-parse.y" /* yacc.c:1646  */
    {(yyval.d) = new_external_prog(&current_conf->linked_prog);}
#line 1649 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 325 "conf-parse.y" /* yacc.c:1646  */
    {(yyval.d) = new_external_prog(&current_conf->kernel_prog);}
#line 1655 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 332 "conf-parse.y" /* yacc.c:1646  */
    { PASSIGN(new_external->path, (yyvsp[0].s)); }
#line 1661 "conf-parse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 333 "conf-parse.y" /* yacc.c:1646  */
    { PASSIGN(new_external->args, (yyvsp[0].s)); }
#line 1667 "conf-parse.c" /* yacc.c:1646  */
    break;


#line 1671 "conf-parse.c" /* yacc.c:1646  */
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
#line 336 "conf-parse.y" /* yacc.c:1906  */


static int semanage_conf_init(semanage_conf_t * conf)
{
	conf->store_type = SEMANAGE_CON_DIRECT;
	conf->store_path = strdup(basename(selinux_policy_root()));
	conf->ignoredirs = NULL;
	conf->store_root_path = strdup("/var/lib/selinux");
	conf->compiler_directory_path = strdup("/usr/libexec/selinux/hll");
	conf->policyvers = sepol_policy_kern_vers_max();
	conf->target_platform = SEPOL_TARGET_SELINUX;
	conf->expand_check = 1;
	conf->handle_unknown = -1;
	conf->usepasswd = 1;
	conf->file_mode = 0644;
	conf->bzip_blocksize = 9;
	conf->bzip_small = 0;
	conf->ignore_module_cache = 0;
	conf->remove_hll = 0;

	conf->save_previous = 0;
	conf->save_linked = 0;

	if ((conf->load_policy =
	     calloc(1, sizeof(*(current_conf->load_policy)))) == NULL) {
		return -1;
	}

	if (access("/sbin/load_policy", X_OK) == 0) {
		conf->load_policy->path = strdup("/sbin/load_policy");
	} else {
		conf->load_policy->path = strdup("/usr/sbin/load_policy");
	}
	if (conf->load_policy->path == NULL) {
		return -1;
	}
	conf->load_policy->args = NULL;

	if ((conf->setfiles =
	     calloc(1, sizeof(*(current_conf->setfiles)))) == NULL) {
		return -1;
	}
	if (access("/sbin/setfiles", X_OK) == 0) {
		conf->setfiles->path = strdup("/sbin/setfiles");
	} else {
		conf->setfiles->path = strdup("/usr/sbin/setfiles");
	}
	if ((conf->setfiles->path == NULL) ||
	    (conf->setfiles->args = strdup("-q -c $@ $<")) == NULL) {
		return -1;
	}

	if ((conf->sefcontext_compile =
	     calloc(1, sizeof(*(current_conf->sefcontext_compile)))) == NULL) {
		return -1;
	}
	if (access("/sbin/sefcontext_compile", X_OK) == 0) {
		conf->sefcontext_compile->path = strdup("/sbin/sefcontext_compile");
	} else {
		conf->sefcontext_compile->path = strdup("/usr/sbin/sefcontext_compile");
	}
	if ((conf->sefcontext_compile->path == NULL) ||
	    (conf->sefcontext_compile->args = strdup("$@")) == NULL) {
		return -1;
	}

	return 0;
}

/* Parse a libsemanage configuration file.  THIS FUNCTION IS NOT
 * THREAD-SAFE!	 Return a newly allocated semanage_conf_t *.  If the
 * configuration file could be read, parse it; otherwise rely upon
 * default values.  If the file could not be parsed correctly or if
 * out of memory return NULL.
 */
semanage_conf_t *semanage_conf_parse(const char *config_filename)
{
	if ((current_conf = calloc(1, sizeof(*current_conf))) == NULL) {
		return NULL;
	}
	if (semanage_conf_init(current_conf) == -1) {
		goto cleanup;
	}
	if ((semanage_in = fopen(config_filename, "r")) == NULL) {
		/* configuration file does not exist or could not be
		 * read.  THIS IS NOT AN ERROR.  just rely on the
		 * defaults. */
		return current_conf;
	}
	parse_errors = 0;
	semanage_parse();
	fclose(semanage_in);
	semanage_lex_destroy();
	if (parse_errors != 0) {
		goto cleanup;
	}
	return current_conf;
      cleanup:
	semanage_conf_destroy(current_conf);
	return NULL;
}

static void semanage_conf_external_prog_destroy(external_prog_t * ep)
{
	while (ep != NULL) {
		external_prog_t *next = ep->next;
		free(ep->path);
		free(ep->args);
		free(ep);
		ep = next;
	}
}

/* Deallocates all space associated with a configuration struct,
 * including the pointer itself. */
void semanage_conf_destroy(semanage_conf_t * conf)
{
	if (conf != NULL) {
		free(conf->store_path);
		free(conf->ignoredirs);
		free(conf->store_root_path);
		free(conf->compiler_directory_path);
		semanage_conf_external_prog_destroy(conf->load_policy);
		semanage_conf_external_prog_destroy(conf->setfiles);
		semanage_conf_external_prog_destroy(conf->sefcontext_compile);
		semanage_conf_external_prog_destroy(conf->mod_prog);
		semanage_conf_external_prog_destroy(conf->linked_prog);
		semanage_conf_external_prog_destroy(conf->kernel_prog);
		free(conf);
	}
}

int semanage_error(const char *msg)
{
	fprintf(stderr, "error parsing semanage configuration file: %s\n", msg);
	parse_errors++;
	return 0;
}

/* Take the string argument for a module store.	 If it is exactly the
 * word "direct" then have libsemanage directly manipulate the module
 * store. The policy path will default to the active policy directory.
 * Otherwise if it begins with a forward slash interpret it as
 * an absolute path to a named socket, to which a policy server is
 * listening on the other end.	Otherwise treat it as the host name to
 * an external server; if there is a colon in the name then everything
 * after gives a port number.  The default port number is 4242.
 * Returns 0 on success, -1 if out of memory, -2 if a port number is
 * illegal.
 */
static int parse_module_store(char *arg)
{
	/* arg is already a strdup()ed copy of yytext */
	if (arg == NULL) {
		return -1;
	}
	free(current_conf->store_path);
	if (strcmp(arg, "direct") == 0) {
		current_conf->store_type = SEMANAGE_CON_DIRECT;
		current_conf->store_path =
		    strdup(basename(selinux_policy_root()));
		current_conf->server_port = -1;
	} else if (*arg == '/') {
		current_conf->store_type = SEMANAGE_CON_POLSERV_LOCAL;
		current_conf->store_path = strdup(arg);
		current_conf->server_port = -1;
	} else {
		char *s;
		current_conf->store_type = SEMANAGE_CON_POLSERV_REMOTE;
		if ((s = strchr(arg, ':')) == NULL) {
			current_conf->store_path = arg;
			current_conf->server_port = 4242;
		} else {
			char *endptr;
			*s = '\0';
			current_conf->store_path = arg;
			current_conf->server_port = strtol(s + 1, &endptr, 10);
			if (*(s + 1) == '\0' || *endptr != '\0') {
				return -2;
			}
		}
	}
	return 0;
}

static int parse_store_root_path(char *arg)
{
	if (arg == NULL) {
		return -1;
	}

	free(current_conf->store_root_path);
	current_conf->store_root_path = strdup(arg);
	return 0;
}

static int parse_compiler_path(char *arg)
{
	if (arg == NULL) {
		return -1;
	}
	free(current_conf->compiler_directory_path);
	current_conf->compiler_directory_path = strdup(arg);
	return 0;
}

/* Helper function; called whenever configuration file specifies
 * another external program.  Returns 0 on success, -1 if out of
 * memory.
 */
static int new_external_prog(external_prog_t ** chain)
{
	if ((new_external = calloc(1, sizeof(*new_external))) == NULL) {
		return -1;
	}
	/* hook this new external program to the end of the chain */
	if (*chain == NULL) {
		*chain = new_external;
	} else {
		external_prog_t *prog = *chain;
		while (prog->next != NULL) {
			prog = prog->next;
		}
		prog->next = new_external;
	}
	return 0;
}
