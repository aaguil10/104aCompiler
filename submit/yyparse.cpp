
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

// $Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYPRINT yyprint
#define YYMALLOC yycalloc

static void* yycalloc (size_t size);

astree* structdef1(astree* one, astree* two, astree* three,
		   astree* four, astree* five){
   free_ast2 (three, five);
   adoptsym (two, TOK_TYPEID);
   return adopt2 (one, two, four);
}

astree* call1(astree* one, astree* two, astree* three, astree* four){
   free_ast(four); 
   adoptsym (two, TOK_CALL);
   return adopt2 (two, one, three);  
}

astree* function1(astree* one, astree* two, astree* three){
   char* tname = (char*)get_yytname (three->symbol);
   astree* func = NULL;
   if(strcmp(tname, (char*)"';'") == 0 ){
      func = new_parseroot("TOK_PROTOTYPE");
   }else{
      func = new_parseroot("TOK_FUNCTION");
   }
   return adopt3 (func, one, two, three);
}



/* Line 189 of yacc.c  */
#line 117 "yyparse.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_ROOT = 258,
     TOK_KW_IDENT = 259,
     NOTIDENT = 260,
     NOTCHAR = 261,
     TOK_KW_VOID = 262,
     TOK_KW_BOOL = 263,
     TOK_KW_CHAR = 264,
     TOK_KW_INT = 265,
     TOK_KW_STRING = 266,
     TOK_KW_WHILE = 267,
     TOK_KW_RETURN = 268,
     TOK_KW_FALSE = 269,
     TOK_KW_TRUE = 270,
     TOK_KW_NEW = 271,
     TOK_KW_STRUCT = 272,
     TOK_NEWSTRING = 273,
     TOK_KW_NULL = 274,
     TOK_LIT_INT = 275,
     TOK_LIT_CHAR = 276,
     TOK_LIT_STRING = 277,
     TOK_FIELD = 278,
     TOK_DECLID = 279,
     TOK_TYPEID = 280,
     TOK_CALL = 281,
     TOK_STRINGCON = 282,
     TOK_CHARCON = 283,
     TOK_INTCON = 284,
     TOK_NEWARRAY = 285,
     TOK_sNEWARRAY = 286,
     TOK_KW_ELSE = 287,
     TOK_KW_IF = 288,
     TOK_PARAMLIST = 289,
     TOK_BLOCK = 290,
     TOK_VARDECL = 291,
     TOK_IFELSE = 292,
     TOK_LESSEQU = 293,
     TOK_GREAEQU = 294,
     TOK_NEQUAL = 295,
     TOK_EQUALS = 296,
     TOK_KW_CHR = 297,
     TOK_KW_ORD = 298,
     TOK_NEG = 299,
     TOK_POS = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 204 "yyparse.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   525

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    57,     2,     2,     2,    56,     2,     2,
      37,    35,    54,    52,    32,    53,    63,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      46,    41,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    33,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    38,    39,    40,    42,
      43,    44,    45,    48,    49,    50,    51,    58,    59,    60,
      61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    15,    21,    25,
      26,    29,    33,    35,    37,    39,    41,    43,    45,    49,
      51,    52,    56,    60,    63,    67,    70,    71,    75,    77,
      79,    81,    83,    85,    87,    90,    95,   101,   107,   115,
     118,   122,   126,   130,   134,   138,   142,   146,   150,   154,
     158,   162,   166,   170,   173,   176,   179,   182,   185,   187,
     189,   193,   195,   197,   202,   208,   214,   218,   220,   221,
     226,   228,   233,   237,   239,   241,   243,   245,   247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    66,    67,    -1,    66,    73,
      -1,    66,    77,    -1,    -1,    17,     4,    36,    68,    33,
      -1,    68,    69,    31,    -1,    -1,    70,     4,    -1,    70,
      30,    23,    -1,     7,    -1,     8,    -1,    10,    -1,     9,
      -1,    11,    -1,    25,    -1,    71,    32,    74,    -1,    74,
      -1,    -1,    37,    71,    35,    -1,    74,    72,    76,    -1,
      70,     4,    -1,    70,    38,     4,    -1,    75,    77,    -1,
      -1,    36,    75,    33,    -1,    31,    -1,    76,    -1,    78,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    31,    -1,
      74,    41,    82,    31,    -1,    12,    37,    82,    35,    77,
      -1,    40,    37,    82,    35,    77,    -1,    40,    37,    82,
      35,    77,    39,    77,    -1,    13,    31,    -1,    13,    82,
      31,    -1,    82,    52,    82,    -1,    82,    53,    82,    -1,
      82,    54,    82,    -1,    82,    55,    82,    -1,    82,    56,
      82,    -1,    82,    41,    82,    -1,    82,    51,    82,    -1,
      82,    50,    82,    -1,    82,    46,    82,    -1,    82,    49,
      82,    -1,    82,    47,    82,    -1,    82,    48,    82,    -1,
      52,    82,    -1,    53,    82,    -1,    57,    82,    -1,    59,
      82,    -1,    58,    82,    -1,    83,    -1,    85,    -1,    37,
      82,    35,    -1,    86,    -1,    87,    -1,    16,     4,    37,
      35,    -1,    16,    11,    37,    82,    35,    -1,    16,    70,
      62,    82,    34,    -1,    84,    32,    82,    -1,    82,    -1,
      -1,     4,    37,    84,    35,    -1,     4,    -1,    82,    62,
      82,    34,    -1,    82,    63,     4,    -1,    20,    -1,    21,
      -1,    22,    -1,    14,    -1,    15,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    79,    80,    81,    82,    85,    89,    90,
      93,    95,    98,    98,    98,    99,    99,    99,   102,   103,
     104,   107,   114,   117,   119,   123,   124,   127,   131,   134,
     135,   136,   137,   138,   139,   142,   147,   150,   152,   158,
     159,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   176,   178,   179,   180,   181,   182,
     183,   184,   185,   188,   191,   195,   201,   202,   203,   206,
     209,   210,   211,   215,   216,   217,   218,   219,   220
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_ROOT", "TOK_KW_IDENT", "NOTIDENT",
  "NOTCHAR", "TOK_KW_VOID", "TOK_KW_BOOL", "TOK_KW_CHAR", "TOK_KW_INT",
  "TOK_KW_STRING", "TOK_KW_WHILE", "TOK_KW_RETURN", "TOK_KW_FALSE",
  "TOK_KW_TRUE", "TOK_KW_NEW", "TOK_KW_STRUCT", "TOK_NEWSTRING",
  "TOK_KW_NULL", "TOK_LIT_INT", "TOK_LIT_CHAR", "TOK_LIT_STRING",
  "TOK_FIELD", "TOK_DECLID", "TOK_TYPEID", "TOK_CALL", "TOK_STRINGCON",
  "TOK_CHARCON", "TOK_INTCON", "TOK_NEWARRAY", "';'", "','", "'}'", "']'",
  "')'", "'{'", "'('", "TOK_sNEWARRAY", "TOK_KW_ELSE", "TOK_KW_IF", "'='",
  "TOK_PARAMLIST", "TOK_BLOCK", "TOK_VARDECL", "TOK_IFELSE", "'<'", "'>'",
  "TOK_LESSEQU", "TOK_GREAEQU", "TOK_NEQUAL", "TOK_EQUALS", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "TOK_KW_CHR", "TOK_KW_ORD", "TOK_NEG",
  "TOK_POS", "'['", "'.'", "$accept", "start", "program", "structdef",
  "mfielddecl", "fielddecl", "basetype", "funcargs", "param", "function",
  "identdecl", "blokargs", "block", "statement", "vardecl", "while",
  "ifelse", "return", "expr", "allocator", "args", "call", "variable",
  "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    59,    44,   125,    93,    41,   123,    40,   286,   287,
     288,    61,   289,   290,   291,   292,    60,    62,   293,   294,
     295,   296,    43,    45,    42,    47,    37,    33,   297,   298,
     299,   300,    91,    46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    67,    68,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    71,    71,
      71,    72,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    78,    79,    80,    80,    81,
      81,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    84,    84,    84,    85,
      86,    86,    86,    87,    87,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     5,     3,     0,
       2,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     3,     2,     3,     2,     0,     3,     1,     1,
       1,     1,     1,     1,     2,     4,     5,     5,     7,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     1,     1,
       3,     1,     1,     4,     5,     5,     3,     1,     0,     4,
       1,     4,     3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,    70,    12,    13,    15,    14,    16,
       0,     0,    76,    77,     0,     0,    78,    73,    74,    75,
      17,    28,    26,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     4,     0,    29,     5,    30,    31,    32,    33,
       0,    58,    59,    61,    62,    68,     0,    39,     0,     0,
      16,     0,     0,     0,     0,     0,    53,    54,    55,    57,
      56,    23,     0,    20,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    40,     0,     0,     0,     9,    27,
       0,    25,    60,     0,    24,     0,    19,     0,    22,    46,
      49,    51,    52,    50,    48,    47,    41,    42,    43,    44,
      45,     0,    72,     0,    69,     0,    63,     0,     0,     0,
       0,     0,    21,    35,    71,    66,    36,    64,    65,     7,
       0,     0,    37,    18,     8,    10,     0,     0,    11,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    30,   119,   130,    31,    95,    65,    32,
      90,    53,    34,    35,    36,    37,    38,    39,    40,    41,
      82,    42,    43,    44
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -41
static const yytype_int16 yypact[] =
{
     -41,     2,   113,   -41,   -33,   -41,   -41,   -41,   -41,   -41,
     -23,   238,   -41,   -41,    35,    12,   -41,   -41,   -41,   -41,
     -41,   -41,   -41,   284,    -7,   284,   284,   284,   284,   284,
     -41,    -1,   -41,   -22,   -41,   -41,   -41,   -41,   -41,   -41,
     261,   -41,   -41,   -41,   -41,   284,   284,   -41,   298,    10,
      17,   -26,    13,   169,   393,   284,   -28,   -28,   -10,   -10,
     -10,   -41,    34,   132,   284,   -19,   -41,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
      51,    37,    -3,   416,   -41,    21,   284,   284,   -41,   -41,
      36,   -41,   -41,   439,   -41,    16,   -41,   324,   -41,    37,
      49,    49,    49,    49,    49,    49,   -28,   -28,   -10,   -10,
     -10,   347,   -41,   284,   -41,   225,   -41,   462,   370,     0,
     225,   132,   -41,   -41,   -41,    37,   -41,   -41,   -41,   -41,
      26,     1,    19,   -41,   -41,   -41,    53,   225,   -41,   -41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -41,   -41,   -41,   -41,   -13,   -41,   -41,   -41,
      -2,   -41,    14,   -40,   -41,   -41,   -41,   -41,    -5,   -41,
     -41,   -41,   -41,   -41
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    51,     3,    61,    45,   135,    48,     5,     6,     7,
       8,     9,    21,    91,    46,    63,    52,    22,    54,    64,
      56,    57,    58,    59,    60,    20,    76,    77,    78,   113,
      55,   136,   114,   129,    79,    80,    87,    62,    94,    49,
      81,    83,     5,     6,     7,     8,    50,    85,   121,    88,
      93,   122,    79,    80,    86,   112,   116,   134,   137,    97,
      20,    96,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   126,   138,    64,    67,    98,
     132,   117,   118,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,     0,     0,     0,   139,     0,    79,
      80,    74,    75,    76,    77,    78,   131,     0,   125,     0,
       0,    79,    80,     0,     0,     0,     0,     4,     0,   133,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     0,    16,    17,    18,    19,     0,     0,    20,     5,
       6,     7,     8,     9,    21,     0,     0,     0,     0,    22,
      23,     0,     0,    24,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
      27,    28,    29,     4,     0,     0,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    16,    17,
      18,    19,     0,     0,    20,     0,     0,     0,     0,     0,
      21,     0,    89,     0,     0,    22,    23,     0,     0,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    27,    28,    29,     4,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     4,     0,    16,    17,    18,    19,     0,     0,
      20,     0,    12,    13,    14,     0,    21,    16,    17,    18,
      19,    22,    23,     0,     0,    24,     0,     0,     0,    47,
       0,     0,     0,     0,     0,    23,     0,    25,    26,     0,
       0,     0,    27,    28,    29,     0,     0,     0,     4,     0,
      25,    26,    66,     0,     0,    27,    28,    29,    12,    13,
      14,     0,    67,    16,    17,    18,    19,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,     0,     0,
       0,    23,     0,    79,    80,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,    25,    26,     0,    67,
       0,    27,    28,    29,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,   123,     0,     0,     0,     0,
      79,    80,     0,     0,     0,    67,     0,     0,     0,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   124,     0,     0,     0,     0,    79,    80,    67,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   128,     0,     0,     0,     0,    79,
      80,    67,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,     0,    92,     0,
       0,     0,    79,    80,    67,     0,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,   115,     0,     0,     0,    79,    80,    67,     0,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,     0,   120,     0,     0,     0,    79,    80,
      67,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,   127,     0,     0,
       0,    79,    80,    67,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,     0,
       0,     0,     0,     0,    79,    80
};

static const yytype_int16 yycheck[] =
{
       2,    14,     0,     4,    37,     4,    11,     7,     8,     9,
      10,    11,    31,    53,    37,    37,     4,    36,    23,    41,
      25,    26,    27,    28,    29,    25,    54,    55,    56,    32,
      37,    30,    35,    33,    62,    63,    62,    38,     4,     4,
      45,    46,     7,     8,     9,    10,    11,    37,    32,    36,
      55,    35,    62,    63,    37,     4,    35,    31,    39,    64,
      25,    63,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   115,    23,    41,    41,    65,
     120,    86,    87,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    -1,    -1,   137,    -1,    62,
      63,    52,    53,    54,    55,    56,   119,    -1,   113,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,     4,    -1,   121,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    19,    20,    21,    22,    -1,    -1,    25,     7,
       8,     9,    10,    11,    31,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    40,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    -1,
      57,    58,    59,     4,    -1,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    20,
      21,    22,    -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    -1,    -1,    36,    37,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    -1,    57,    58,    59,     4,
      -1,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     4,    -1,    19,    20,    21,    22,    -1,    -1,
      25,    -1,    14,    15,    16,    -1,    31,    19,    20,    21,
      22,    36,    37,    -1,    -1,    40,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    52,    53,    -1,
      -1,    -1,    57,    58,    59,    -1,    -1,    -1,     4,    -1,
      52,    53,    31,    -1,    -1,    57,    58,    59,    14,    15,
      16,    -1,    41,    19,    20,    21,    22,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    37,    -1,    62,    63,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,    41,
      -1,    57,    58,    59,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    31,    -1,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    34,    -1,    -1,    -1,    -1,    62,    63,    41,    -1,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    34,    -1,    -1,    -1,    -1,    62,
      63,    41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    35,    -1,
      -1,    -1,    62,    63,    41,    -1,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    35,    -1,    -1,    -1,    62,    63,    41,    -1,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    35,    -1,    -1,    -1,    62,    63,
      41,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    35,    -1,    -1,
      -1,    62,    63,    41,    -1,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    -1,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,     0,     4,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    19,    20,    21,    22,
      25,    31,    36,    37,    40,    52,    53,    57,    58,    59,
      67,    70,    73,    74,    76,    77,    78,    79,    80,    81,
      82,    83,    85,    86,    87,    37,    37,    31,    82,     4,
      11,    70,     4,    75,    82,    37,    82,    82,    82,    82,
      82,     4,    38,    37,    41,    72,    31,    41,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    62,
      63,    82,    84,    82,    31,    37,    37,    62,    36,    33,
      74,    77,    35,    82,     4,    71,    74,    82,    76,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,     4,    32,    35,    35,    35,    82,    82,    68,
      35,    32,    35,    31,    34,    82,    77,    35,    34,    33,
      69,    70,    77,    74,    31,     4,    30,    39,    23,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {
      case 3: /* "TOK_ROOT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1309 "yyparse.cpp"
	break;
      case 4: /* "TOK_KW_IDENT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1318 "yyparse.cpp"
	break;
      case 5: /* "NOTIDENT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1327 "yyparse.cpp"
	break;
      case 6: /* "NOTCHAR" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1336 "yyparse.cpp"
	break;
      case 7: /* "TOK_KW_VOID" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1345 "yyparse.cpp"
	break;
      case 8: /* "TOK_KW_BOOL" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1354 "yyparse.cpp"
	break;
      case 9: /* "TOK_KW_CHAR" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1363 "yyparse.cpp"
	break;
      case 10: /* "TOK_KW_INT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1372 "yyparse.cpp"
	break;
      case 11: /* "TOK_KW_STRING" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1381 "yyparse.cpp"
	break;
      case 12: /* "TOK_KW_WHILE" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1390 "yyparse.cpp"
	break;
      case 13: /* "TOK_KW_RETURN" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1399 "yyparse.cpp"
	break;
      case 14: /* "TOK_KW_FALSE" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1408 "yyparse.cpp"
	break;
      case 15: /* "TOK_KW_TRUE" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1417 "yyparse.cpp"
	break;
      case 16: /* "TOK_KW_NEW" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1426 "yyparse.cpp"
	break;
      case 17: /* "TOK_KW_STRUCT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1435 "yyparse.cpp"
	break;
      case 18: /* "TOK_NEWSTRING" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1444 "yyparse.cpp"
	break;
      case 19: /* "TOK_KW_NULL" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1453 "yyparse.cpp"
	break;
      case 20: /* "TOK_LIT_INT" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1462 "yyparse.cpp"
	break;
      case 21: /* "TOK_LIT_CHAR" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1471 "yyparse.cpp"
	break;
      case 22: /* "TOK_LIT_STRING" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1480 "yyparse.cpp"
	break;
      case 23: /* "TOK_FIELD" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1489 "yyparse.cpp"
	break;
      case 24: /* "TOK_DECLID" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1498 "yyparse.cpp"
	break;
      case 25: /* "TOK_TYPEID" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1507 "yyparse.cpp"
	break;
      case 26: /* "TOK_CALL" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1516 "yyparse.cpp"
	break;
      case 27: /* "TOK_STRINGCON" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1525 "yyparse.cpp"
	break;
      case 28: /* "TOK_CHARCON" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1534 "yyparse.cpp"
	break;
      case 29: /* "TOK_INTCON" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1543 "yyparse.cpp"
	break;
      case 30: /* "TOK_NEWARRAY" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1552 "yyparse.cpp"
	break;
      case 31: /* "';'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1561 "yyparse.cpp"
	break;
      case 32: /* "','" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1570 "yyparse.cpp"
	break;
      case 33: /* "'}'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1579 "yyparse.cpp"
	break;
      case 34: /* "']'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1588 "yyparse.cpp"
	break;
      case 35: /* "')'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1597 "yyparse.cpp"
	break;
      case 36: /* "'{'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1606 "yyparse.cpp"
	break;
      case 37: /* "'('" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1615 "yyparse.cpp"
	break;
      case 38: /* "TOK_sNEWARRAY" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1624 "yyparse.cpp"
	break;
      case 39: /* "TOK_KW_ELSE" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1633 "yyparse.cpp"
	break;
      case 40: /* "TOK_KW_IF" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1642 "yyparse.cpp"
	break;
      case 41: /* "'='" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1651 "yyparse.cpp"
	break;
      case 42: /* "TOK_PARAMLIST" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1660 "yyparse.cpp"
	break;
      case 43: /* "TOK_BLOCK" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1669 "yyparse.cpp"
	break;
      case 44: /* "TOK_VARDECL" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1678 "yyparse.cpp"
	break;
      case 45: /* "TOK_IFELSE" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1687 "yyparse.cpp"
	break;
      case 46: /* "'<'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1696 "yyparse.cpp"
	break;
      case 47: /* "'>'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1705 "yyparse.cpp"
	break;
      case 48: /* "TOK_LESSEQU" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1714 "yyparse.cpp"
	break;
      case 49: /* "TOK_GREAEQU" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1723 "yyparse.cpp"
	break;
      case 50: /* "TOK_NEQUAL" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1732 "yyparse.cpp"
	break;
      case 51: /* "TOK_EQUALS" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1741 "yyparse.cpp"
	break;
      case 52: /* "'+'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1750 "yyparse.cpp"
	break;
      case 53: /* "'-'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1759 "yyparse.cpp"
	break;
      case 54: /* "'*'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1768 "yyparse.cpp"
	break;
      case 55: /* "'/'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1777 "yyparse.cpp"
	break;
      case 56: /* "'%'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1786 "yyparse.cpp"
	break;
      case 57: /* "'!'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1795 "yyparse.cpp"
	break;
      case 58: /* "TOK_KW_CHR" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1804 "yyparse.cpp"
	break;
      case 59: /* "TOK_KW_ORD" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1813 "yyparse.cpp"
	break;
      case 60: /* "TOK_NEG" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1822 "yyparse.cpp"
	break;
      case 61: /* "TOK_POS" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1831 "yyparse.cpp"
	break;
      case 62: /* "'['" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1840 "yyparse.cpp"
	break;
      case 63: /* "'.'" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1849 "yyparse.cpp"
	break;
      case 65: /* "start" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1858 "yyparse.cpp"
	break;
      case 66: /* "program" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1867 "yyparse.cpp"
	break;
      case 67: /* "structdef" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1876 "yyparse.cpp"
	break;
      case 68: /* "mfielddecl" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1885 "yyparse.cpp"
	break;
      case 69: /* "fielddecl" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1894 "yyparse.cpp"
	break;
      case 70: /* "basetype" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1903 "yyparse.cpp"
	break;
      case 71: /* "funcargs" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1912 "yyparse.cpp"
	break;
      case 72: /* "param" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1921 "yyparse.cpp"
	break;
      case 73: /* "function" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1930 "yyparse.cpp"
	break;
      case 74: /* "identdecl" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1939 "yyparse.cpp"
	break;
      case 75: /* "blokargs" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1948 "yyparse.cpp"
	break;
      case 76: /* "block" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1957 "yyparse.cpp"
	break;
      case 77: /* "statement" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1966 "yyparse.cpp"
	break;
      case 78: /* "vardecl" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1975 "yyparse.cpp"
	break;
      case 79: /* "while" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1984 "yyparse.cpp"
	break;
      case 80: /* "ifelse" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 1993 "yyparse.cpp"
	break;
      case 81: /* "return" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2002 "yyparse.cpp"
	break;
      case 82: /* "expr" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2011 "yyparse.cpp"
	break;
      case 83: /* "allocator" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2020 "yyparse.cpp"
	break;
      case 84: /* "args" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2029 "yyparse.cpp"
	break;
      case 85: /* "call" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2038 "yyparse.cpp"
	break;
      case 86: /* "variable" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2047 "yyparse.cpp"
	break;
      case 87: /* "constant" */

/* Line 1000 of yacc.c  */
#line 50 "parser.y"
	{ error_destructor ((*yyvaluep)); };

/* Line 1000 of yacc.c  */
#line 2056 "yyparse.cpp"
	break;

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 76 "parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 80 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 81 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    { (yyval) = new_parseroot(""); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 85 "parser.y"
    { (yyval) = structdef1((yyvsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yyvsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yyvsp[(5) - (5)])); 
                                                            delRoots ((yyvsp[(1) - (5)])); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { free_ast((yyvsp[(3) - (3)])); (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    { (yyval) = new_parseroot(""); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { adoptsym ((yyvsp[(1) - (2)]), TOK_FIELD);
						 (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 102 "parser.y"
    { free_ast((yyvsp[(2) - (3)])); (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    { (yyval) = adopt1 (new_parseroot(""), (yyvsp[(1) - (1)]));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { (yyval) = new_parseroot(""); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 107 "parser.y"
    {free_ast((yyvsp[(3) - (3)]));
						adoptsym ((yyvsp[(1) - (3)]), TOK_PARAMLIST);
						(yyval) = adopt1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
						delmiddle((yyvsp[(1) - (3)]), 0);
;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    { (yyval) = function1((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { adoptsym ((yyvsp[(1) - (2)]), TOK_DECLID);
						  (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 119 "parser.y"
    { adoptsym ((yyvsp[(1) - (3)]), TOK_DECLID);
						  (yyval) = adopt2 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 124 "parser.y"
    { (yyval) = new_parseroot(""); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { free_ast((yyvsp[(3) - (3)]));
						adoptsym ((yyvsp[(1) - (3)]), TOK_BLOCK);
						(yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); 
						delmiddle((yyvsp[(1) - (3)]), 0);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    { free_ast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]) ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 142 "parser.y"
    {free_ast((yyvsp[(4) - (4)]));
						adoptsym ((yyvsp[(2) - (4)]), TOK_VARDECL);
						(yyval) = adopt2 ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    { free_ast2((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    { free_ast2((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); 
						(yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)])); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 152 "parser.y"
    { free_ast2((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
						 free_ast((yyvsp[(6) - (7)]));
						 adoptsym ((yyvsp[(1) - (7)]), TOK_IFELSE); 
						(yyval) = adopt3 ((yyvsp[(1) - (7)]), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)])); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    { free_ast((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]) ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    { free_ast((yyvsp[(3) - (3)])); (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 168 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    { adoptsym ((yyvsp[(1) - (2)]), TOK_POS); 
						(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 176 "parser.y"
    { adoptsym ((yyvsp[(1) - (2)]), TOK_NEG);
						(yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 181 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    { free_ast2((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]) ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    { free_ast2((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
						adoptsym ((yyvsp[(2) - (4)]), TOK_TYPEID); 
						(yyval) = adopt1 ((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    { free_ast2((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
						free_ast((yyvsp[(2) - (5)]));
						adoptsym ((yyvsp[(1) - (5)]), TOK_NEWSTRING);
						(yyval) = adopt1 ((yyvsp[(1) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    { free_ast2 ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
						adoptsym ((yyvsp[(1) - (5)]), TOK_NEWARRAY);
						adoptsym ((yyvsp[(2) - (5)]), TOK_TYPEID);
						(yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)])); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { free_ast((yyvsp[(2) - (3)])); (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { (yyval) = adopt1 (new_parseroot(""), (yyvsp[(1) - (1)]));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { (yyval) = new_parseroot(""); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    { (yyval) = call1((yyvsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yyvsp[(4) - (4)])); delRoots ((yyvsp[(2) - (4)])); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    { free_ast2((yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); (yyval) = adopt1 ((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)])); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    { adoptsym ((yyvsp[(3) - (3)]), TOK_FIELD);
						(yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)]), (yyvsp[(1) - (3)])); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    { adoptsym ((yyvsp[(1) - (1)]), TOK_INTCON); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    { adoptsym ((yyvsp[(1) - (1)]), TOK_CHARCON); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    { adoptsym ((yyvsp[(1) - (1)]), TOK_STRINGCON); (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2886 "yyparse.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 223 "parser.y"


const char* get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}

bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != NULL);
   return result;
}


RCSC("$Id: parser.y,v 1.5 2013-10-10 18:48:18-07 - - $")


