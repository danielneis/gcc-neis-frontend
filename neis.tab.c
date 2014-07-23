/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "neis.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>

#include "neis.tab.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "debug.h"
#include "neis-tree.h"
#include "function.h"
#include "expr.h"
#include "passes.h"

int yylex(void);

tree fndecl; // Consider it as a global value.
void build_function_decl (char *name)
{
    tree param_list;  //param_list is of type tree. Similarly others.
    tree param_type_list;
    tree fntype;
    tree fndecl; // Consider it as a global value.
    // It will be required quite often.

    /*First of all we have to arrange the parameters that are involved in the function. Suppose, we have "hello(int a, int b)" then a and b form the parameters. a and b have to be made available to the function. But since this is our first attempt, we are assuming that the function doesn't involve any parameters. So param_list is made to be a NULL_TREE (which is a NULL of type tree). */
    param_list = NULL_TREE;

    /*Next is the type of the parameters. The function always take a fixed number of parameters. Since we don't have any parameters in the current example, we are invoking the function, tree_cons as shown. The first field is a purpose field and the last one is a chain field (for linking together different types like integers). We will be explaining more about this when we pass some parameters. */
    param_type_list = tree_cons(NULL_TREE, void_type_node, NULL_TREE);

    /*Alright, we are done with the parameters. ie. the parameters and the type. We needn't bother about them. Now let's look at the function. The first thing is the type of the function. It depends on the return type and the parameter type. We consider our function as one returning an integer value. So the first argument of build_function is integer. The second one deals with parameters. The type of the parameters is given in the param_type_list. */
    fntype = build_function_type(integer_type_node, param_type_list);

    /*Next is the function declaration. It is possible with the function build_decl. The first argument says that it is a function declaration. The second one involves a function, get_identifier. It returns a tree whose name is "name". If an identifier with that name has been previously referred to, then the same tree node is returned. Since this is the first time we are using this, a new tree node is returned. The last argument deals with the type of the function. */
    fndecl = build_decl(FUNCTION_DECL, get_identifier(name), fntype);

    /*Here comes the flags. They are invoked through special macros given below*/

    /*If nonzero, it means external reference. Needn't allocate storage. There is a definition elsewhere. But we need to make a definition here itself and hence zero. */
    DECL_EXTERNAL(fndecl) = 0;

    /* non zero means function can be accessed from outside the module.*/
    TREE_PUBLIC(fndecl) = 1;

    /* non zero means function has been defined and not declared. */
    TREE_STATIC(fndecl) = 1;

    /* It declares the argument of the function (which is stored in param_list)*/
    DECL_ARGUMENTS(fndecl) = param_list;

    /* It makes the declaration for the return value.*/
    DECL_RESULT(fndecl) =
        build_decl(RESULT_DECL, NULL_TREE, integer_type_node);

    /*It declares the context of the result. ie. We inform the result, that its scope is fndecl.*/
    DECL_CONTEXT( DECL_RESULT( fndecl)) = fndecl;

    /*Creates the rtl for the function declaration. The first argument gives the tree for the function declaration The second parameter deals with assembler symbol name. We don't want it here. We make it NULL. Let's look at third and fourth parameters later. Interested readers can refer toplev.c */
    rest_of_decl_compilation (fndecl, NULL_PTR, 1, 0);

    /*This gives idea regarding where the declaration is in the source code */
    DECL_SOURCE_FILE( fndecl) = input_filename;
    DECL_SOURCE_LINE( fndecl) = 1;

    /* This function is just used to print the name of the function "name", on stderr if required */
    announce_function( fndecl);

    /* Let the GCC know the name of the function being compiled.*/
    current_function_decl = fndecl;

    /* It holds the tree of bindings. Just a method used here to make a partial tree. Don't bother about that. */
    DECL_INITIAL( fndecl) = error_mark_node;

    /* All tree and rtl are allocated in temporary memory. Used per function. */
    temporary_allocation();

    /*pushlevel is explained in call back. Here, it requires a push at the start of any function. */
    pushlevel(0);

    /*create function rtl for function definition. */
    make_function_rtl( fndecl);

    /*Generate rtl for the start of a function, fndecl. The second and third parameters denote the file and the line */
    init_function_start(fndecl, input_filename, 1);

    /*Let's start the rtl for a new function. It also sets the variables used for emitting rtl. The second parameter shows that there is no cleanup associated with. If it is made nonzero, cleanup will be run when a return statement is met. */
    expand_function_start(fndecl, 0);

    /*It generates the rtl code for entering a new binding level.*/
    expand_start_bindings(0);

} //end of build_function_decl


void build_function()
{

    tree fndecl; // Consider it as a global value.

    /*Let's build the tree and emit the rtl for the return statement. In order to avoid an extra tree variable, I have included the tree creation and rtl conversion in a single statement. First build a tree of type result for 'fndecl'. I am always returning zero from our simple function. If you intend to return any other value, replace integer_zero_node with the other corresponding tree structure. expand_return creates the rtl for the tree. */
    expand_return (build (MODIFY_EXPR, void_type_node, DECL_RESULT(fndecl), integer_zero_node));

    /*Emit rtl for the end of bindings. Just like start bindings */
    expand_end_bindings (NULL_TREE, 1, 0);

    /* We have pushed. So don't forget to pop */
    poplevel (1, 0, 1);

    /*Emit rtl for the end of function. Just like starting */
    expand_function_end (input_file_name, 1, 0);

    /*Compile the function, output the assembler code, Free the tree storage. */
    rest_of_compilation (fndecl);

    /*We are free now */
    current_function_decl=0;

    /* Free everything in temporary store. Argument 1 shows that, we have just finished compiling a function */
    permanent_allocation (1);
}


char *var_name[100];    //global array ie. initialized to zero.
tree var_decls[100];    //global array

void add_var(char *name)
{
    tree fndecl; // Consider it as a global value.
    int i;
    /*Add the name given, as the last name in the array */
    for(i=0;var_name[i];i++);

    /* Store the name */
    var_name[i] = name;

    /*Build the tree structure for the variable declared
      All the parameters are explained before.
      Thus we have name of the variable stored in var_name[] and
      tree stored in var_decls[ ]*/
    var_decls[i] =
        build_decl (VAR_DECL, get_identifier(name), integer_type_node);

    /* Explained before*/
    DECL_CONTEXT (var_decls[i]) = fndecl;

    /*We are just making the initial value of the variable declared
      as zero. This is a matter of taste. */
    DECL_INITIAL (var_decls[i]) = integer_zero_node;

    /*push to the current scope. Explained before*/
    pushdecl (var_decls[i]);

    /* Emit the rtl for the variable declaration*/
    expand_decl (var_decls[i]);

    /* Emit the rtl for the initialization. ie. Initialized to zero*/
    expand_decl_init (var_decls[i]);
}

tree get_var(char *name)
{
    int i;
    //Search for the name "name" in the variable name table, var_name[]
    for(i=0;var_name[i];i++)
        //If found, return the corresponding tree structure of "name"
        if( !strcmp (var_name[i], name))
            return var_decls[i];
}

void make_assign (tree vartree, tree valtree)
{
    tree assign;

    // Create the tree. Explained before.
    assign = build (MODIFY_EXPR, integer_type_node, vartree, valtree);

    /*Non zero values means that there is a side effect and re evaluation
    of the whole expression could produce a different value. The
    optimization phase takes this into consideration.
     */
    TREE_SIDE_EFFECTS (assign) = 1;

    /* Indicates that the tree node is used */
    TREE_USED (assign) = 1;

    /* Emit the rtl for the assign tree */
    expand_expr_stmt (assign);
}

tree ret_stmt (tree expr)
{
    tree fndecl; // Consider it as a global value.
    tree ret;
    /* build the tree node for return. The arguments are explained
       before. 'fndecl' is the global variable that we have defined
       before, for our function.  */
    ret = build (MODIFY_EXPR, integer_type_node, DECL_RESULT(fndecl), expr);

    /*emits the rtl */
    expand_return (ret);

    return ret;
}


#line 277 "neis.tab.c" /* yacc.c:339  */

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
   by #include "neis.tab.h".  */
#ifndef YY_YY_NEIS_TAB_H_INCLUDED
# define YY_YY_NEIS_TAB_H_INCLUDED
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
    TINT = 258,
    TFLOAT = 259,
    TCHAR = 260,
    TDOUBLE = 261,
    TVOID = 262,
    FOR = 263,
    WHILE = 264,
    IF = 265,
    ELSE = 266,
    NUM = 267,
    ID = 268,
    TRETURN = 269,
    TAND = 270,
    TOR = 271,
    TLE = 272,
    TGE = 273,
    TEQ = 274,
    TNE = 275,
    TLT = 276,
    TGT = 277
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 212 "neis.y" /* yacc.c:355  */

        tree tree;       //Tree tree developed by us.
        int ival;       //Integer value for constants.
        char *name;     //Name of function or variables.

#line 346 "neis.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_NEIS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 361 "neis.tab.c" /* yacc.c:358  */

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,    31,
      32,    33,    18,    28,    27,    29,     2,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    15,
       2,    16,     2,     2,     2,     2,     2,     2,     2,     2,
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
      19,    20,    21,    22,    23,    24,    25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   253,   253,   254,   257,   258,   259,   260,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     289,   290,   294,   297,   298,   301,   302,   305,   308,   311,
     312,   315,   316,   317,   318,   319,   320,   321,   325,   326,
     327,   328,   329,   333,   333,   337,   337,   344,   344,   348,
     348,   356,   355,   360,   362,   360,   367,   371,   372,   373,
     374,   375,   376,   377,   378
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TINT", "TFLOAT", "TCHAR", "TDOUBLE",
  "TVOID", "FOR", "WHILE", "IF", "ELSE", "NUM", "ID", "TRETURN", "';'",
  "'='", "'/'", "'*'", "TAND", "TOR", "TLE", "TGE", "TEQ", "TNE", "TLT",
  "TGT", "','", "'+'", "'-'", "'%'", "'\\''", "'('", "')'", "'{'", "'}'",
  "$accept", "start", "Declaration", "Assignment", "FunctionCall",
  "Function", "ArgListOpt", "ArgList", "Arg", "CompoundStmt", "StmtList",
  "Stmt", "Type", "WhileStmt", "$@1", "$@2", "ForStmt", "$@3", "$@4",
  "IfStmt", "$@5", "IfElseStmt", "$@6", "$@7", "ReturnStmt", "Expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,    59,    61,    47,    42,   270,
     271,   272,   273,   274,   275,   276,   277,    44,    43,    45,
      37,    39,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -60

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,  -107,  -107,  -107,  -107,  -107,  -107,   107,   164,    -5,
      66,    66,     3,  -107,   -11,   -10,  -107,    -7,    66,    66,
      66,    66,    66,    66,    90,    66,    66,    -4,    -1,    66,
      66,    66,    24,  -107,  -107,    66,   181,   -17,   -18,  -107,
    -107,  -107,     2,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,     5,
      15,  -107,  -107,  -107,   124,  -107,  -107,    16,     6,  -107,
      37,    25,   124,  -107,  -107,  -107,  -107,    79,   -16,    26,
      29,   137,  -107,  -107,  -107,  -107,    49,  -107,  -107,  -107,
    -107,  -107,    66,    66,    66,    48,    51,  -107,   209,   132,
     190,  -107,    66,    66,    66,    66,    66,    66,    66,    30,
      33,   221,  -107,  -107,  -107,  -107,  -107,  -107,   137,    25,
     137,    35,    66,  -107,  -107,  -107,   137,   196,    40,    41,
      38,  -107,  -107,   137,    25,    63,  -107,  -107,    56,   137,
      61,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     7,    48,    49,    50,    51,    52,    28,    29,     0,
       0,     0,     0,     3,     0,     0,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,     0,    29,     0,     0,     1,
       5,     6,     0,    19,    18,    11,    16,    17,    20,     8,
       9,    15,    14,    22,    21,    10,    12,    13,    30,     0,
       0,    23,    24,     4,    34,    31,    25,     0,    33,    36,
       0,     0,     0,    37,    40,    32,    35,     0,     0,     0,
       0,     0,    47,    38,    42,    39,     0,    41,    43,    44,
      45,    46,    67,    67,    67,     0,     0,    74,     0,     0,
       0,    66,    67,    67,    67,    67,    67,    67,    67,    53,
       0,     0,    68,    69,    71,    70,    73,    72,     0,     0,
       0,     0,    67,    54,    56,    61,     0,     0,     0,     0,
      57,    62,    64,     0,     0,     0,    58,    60,     0,     0,
       0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,    99,     0,    76,  -107,  -107,  -107,    32,  -106,
    -107,   -79,     1,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,    68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    84,    97,    15,    16,    67,    68,    69,    75,
      77,    85,    86,    87,   118,   119,    88,   133,   134,    89,
     128,    90,   121,   135,    91,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    17,    95,    39,    40,    41,    42,    33,    34,    53,
      37,    38,    54,   124,    61,    62,    92,    63,    43,    44,
      45,    46,    47,    48,    49,    51,    52,    35,   137,    55,
      56,    57,    59,    72,    64,    60,     7,    36,    65,   123,
       1,   125,     2,     3,     4,     5,     6,   129,    66,    71,
      73,     7,     8,     9,   136,    10,    11,    58,    93,    74,
     140,    94,    96,   101,   -55,    70,    63,   120,     9,   126,
      10,    11,   -59,    70,   138,   131,   132,    14,     7,    36,
       1,    14,     2,     3,     4,     5,     6,    78,    79,    80,
     139,     7,     8,    81,    82,     9,   141,    10,    11,    13,
      50,     0,     7,     8,    76,     0,     0,     0,     9,     0,
      10,    11,     0,     0,    83,     0,     0,     0,    14,     9,
      14,    10,    11,     0,    18,    19,    14,     2,     3,     4,
       5,     6,     0,    14,    20,    21,    22,    23,     1,    14,
       2,     3,     4,     5,     6,    78,    79,    80,     0,     7,
       8,    81,    82,   103,   104,   105,   106,   107,   108,     0,
       0,    99,   100,     0,     0,   109,     9,     0,    10,    11,
     111,   112,   113,   114,   115,   116,   117,     0,     0,     0,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
     127,    29,    30,    31,     0,     0,    32,    24,    25,    26,
      27,    28,     0,     0,     0,     0,     0,     0,    29,    30,
      31,   103,   104,   105,   106,   107,   108,   103,   104,   105,
     106,   107,   108,   110,   102,     0,     0,     0,     0,   130,
     103,   104,   105,   106,   107,   108,   122,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108
};

static const yytype_int16 yycheck[] =
{
       0,     0,    81,     0,    15,    15,    13,    12,    13,    13,
      10,    11,    13,   119,    31,    33,    32,    15,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    32,   134,    29,
      30,    31,    32,    27,    32,    35,    12,    13,    33,   118,
       1,   120,     3,     4,     5,     6,     7,   126,    33,    33,
      13,    12,    13,    29,   133,    31,    32,    33,    32,    34,
     139,    32,    13,    15,    34,    64,    15,    34,    29,    34,
      31,    32,    34,    72,    11,    35,    35,    77,    12,    13,
       1,    81,     3,     4,     5,     6,     7,     8,     9,    10,
      34,    12,    13,    14,    15,    29,    35,    31,    32,     0,
      24,    -1,    12,    13,    72,    -1,    -1,    -1,    29,    -1,
      31,    32,    -1,    -1,    35,    -1,    -1,    -1,   118,    29,
     120,    31,    32,    -1,    17,    18,   126,     3,     4,     5,
       6,     7,    -1,   133,    27,    28,    29,    30,     1,   139,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    21,    22,    23,    24,    25,    26,    -1,
      -1,    93,    94,    -1,    -1,    33,    29,    -1,    31,    32,
     102,   103,   104,   105,   106,   107,   108,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
     122,    27,    28,    29,    -1,    -1,    32,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    21,    22,    23,    24,    25,    26,    21,    22,    23,
      24,    25,    26,    33,    15,    -1,    -1,    -1,    -1,    33,
      21,    22,    23,    24,    25,    26,    15,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    12,    13,    29,
      31,    32,    37,    38,    39,    40,    41,    48,    17,    18,
      27,    28,    29,    30,    16,    17,    18,    19,    20,    27,
      28,    29,    32,    12,    13,    32,    13,    39,    39,     0,
      15,    15,    13,    39,    39,    39,    39,    39,    39,    39,
      40,    39,    39,    13,    13,    39,    39,    39,    33,    39,
      39,    31,    33,    15,    32,    33,    33,    42,    43,    44,
      48,    33,    27,    13,    34,    45,    44,    46,     8,     9,
      10,    14,    15,    35,    38,    47,    48,    49,    52,    55,
      57,    60,    32,    32,    32,    47,    13,    39,    61,    61,
      61,    15,    15,    21,    22,    23,    24,    25,    26,    33,
      33,    61,    61,    61,    61,    61,    61,    61,    50,    51,
      34,    58,    15,    47,    45,    47,    34,    61,    56,    47,
      33,    35,    35,    53,    54,    59,    47,    45,    11,    34,
      47,    35
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    38,    38,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      40,    40,    41,    42,    42,    43,    43,    44,    45,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    48,    48,
      48,    48,    48,    50,    49,    51,    49,    53,    52,    54,
      52,    56,    55,    58,    59,    57,    60,    61,    61,    61,
      61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     3,     2,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     2,     2,     1,     1,
       3,     4,     6,     1,     0,     3,     1,     2,     3,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     0,     6,     0,    10,     0,
      10,     0,     8,     0,     0,    13,     3,     0,     3,     3,
       3,     3,     3,     3,     1
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
#line 253 "neis.y" /* yacc.c:1646  */
    { build_function(); }
#line 1552 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 254 "neis.y" /* yacc.c:1646  */
    { build_function(); }
#line 1558 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 257 "neis.y" /* yacc.c:1646  */
    { add_var((yyvsp[-1].tree)); }
#line 1564 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 264 "neis.y" /* yacc.c:1646  */
    { make_assign(get_var((yyvsp[-2].tree)), (yyvsp[0].tree)); }
#line 1570 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 272 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build (PLUS_EXPR, integer_type_node, (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1576 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 273 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build (MINUS_EXPR, integer_type_node, (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1582 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 274 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build (MULT_EXPR, integer_type_node, (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1588 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 275 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build (TRUNC_DIV_EXPR, integer_type_node, (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1594 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 276 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build (TRUNC_MOD_EXPR, integer_type_node, (yyvsp[-2].tree), (yyvsp[0].tree)); }
#line 1600 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 279 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[-1].tree); }
#line 1606 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 280 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[-1].tree); }
#line 1612 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 281 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build1 (NEGATE_EXPR, integer_type_node, (yyvsp[-1].tree)); }
#line 1618 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 282 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build1 (NEGATE_EXPR, integer_type_node, (yyvsp[0].tree)); }
#line 1624 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 283 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = build1 (NEGATE_EXPR, integer_type_node, (yyvsp[0].tree)); }
#line 1630 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 284 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = get_var ((yyvsp[0].tree)); }
#line 1636 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 285 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = get_var ((yyvsp[0].tree)); }
#line 1642 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 294 "neis.y" /* yacc.c:1646  */
    { build_function_decl((yyvsp[-4].tree)); }
#line 1648 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 308 "neis.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1654 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 312 "neis.y" /* yacc.c:1646  */
    {}
#line 1660 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 321 "neis.y" /* yacc.c:1646  */
    {}
#line 1666 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 333 "neis.y" /* yacc.c:1646  */
    { struct nesting *loop;
                                  //loop = expand_start_loop (0);
                                  //expand_exit_loop_if_false (loop, $3);
                                }
#line 1675 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 336 "neis.y" /* yacc.c:1646  */
    {/* expand_end_loop();*/ }
#line 1681 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 337 "neis.y" /* yacc.c:1646  */
    { struct nesting *loop;
                                  //loop = expand_start_loop (0);
                                  //expand_exit_loop_if_false (loop, $3);
                                }
#line 1690 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 340 "neis.y" /* yacc.c:1646  */
    { /*expand_end_loop();*/ }
#line 1696 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 344 "neis.y" /* yacc.c:1646  */
    { struct nesting *loop;
                                             // loop = expand_start_loop (0);
                                             // expand_exit_loop_if_false (loop, $7);
                                            }
#line 1705 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 347 "neis.y" /* yacc.c:1646  */
    { /*expand_end_loop();*/ }
#line 1711 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 348 "neis.y" /* yacc.c:1646  */
    { struct nesting *loop;
                                             // loop = expand_start_loop (0);
                                            //  expand_exit_loop_if_false (loop, $7);
                                            }
#line 1720 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 351 "neis.y" /* yacc.c:1646  */
    { /*expand_end_loop();*/ }
#line 1726 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 356 "neis.y" /* yacc.c:1646  */
    {/* expand_start_cond ($3, 0); */}
#line 1732 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 357 "neis.y" /* yacc.c:1646  */
    {/* expand_end_cond ();*/ }
#line 1738 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 360 "neis.y" /* yacc.c:1646  */
    {/*  expand_start_cond ($3, 0); */}
#line 1744 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 362 "neis.y" /* yacc.c:1646  */
    {/*  expand_start_else ();*/ }
#line 1750 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 364 "neis.y" /* yacc.c:1646  */
    {/*  expand_end_cond (); */}
#line 1756 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 367 "neis.y" /* yacc.c:1646  */
    { (yyval.tree) = ret_stmt ((yyvsp[-1].tree));}
#line 1762 "neis.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 371 "neis.y" /* yacc.c:1646  */
    {}
#line 1768 "neis.tab.c" /* yacc.c:1646  */
    break;


#line 1772 "neis.tab.c" /* yacc.c:1646  */
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
#line 381 "neis.y" /* yacc.c:1906  */


#include "lex.yy.c"

int yylex(void);
int yyparse(void);

void yyerror(char *s) {
    printf("Linha %d : %s (%s) \n", yylineno, s, yytext );
}

