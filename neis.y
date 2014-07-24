%{

#include "neis.tab.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "stor-layout.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "debug.h"
#include "neis-tree.h"
#include "function.h"
#include "toplev.h"
#include "expr.h"
#include "stmt.h"
#include "name-lookup.h"
#include "stringpool.h"

int yylex(void);
void yyerror(const char *s);

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
    fndecl = build_decl(UNKNOWN_LOCATION, FUNCTION_DECL, get_identifier(name), fntype);

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
        build_decl(UNKNOWN_LOCATION, RESULT_DECL, NULL, integer_type_node);

    /*It declares the context of the result. ie. We inform the result, that its scope is fndecl.*/
    DECL_CONTEXT( DECL_RESULT( fndecl)) = fndecl;

    /*Creates the rtl for the function declaration. The first argument gives the tree for the function declaration The second parameter deals with assembler symbol name. We don't want it here. We make it NULL. Let's look at third and fourth parameters later. Interested readers can refer toplev.c */
    rest_of_decl_compilation (fndecl, 1, 0);

    /*This gives idea regarding where the declaration is in the source code */
    //DECL_SOURCE_FILE( fndecl) = input_filename;
    //DECL_SOURCE_LINE( fndecl) = 1;

    /* This function is just used to print the name of the function "name", on stderr if required */
    announce_function( fndecl);

    /* Let the GCC know the name of the function being compiled.*/
    current_function_decl = fndecl;

    /* It holds the tree of bindings. Just a method used here to make a partial tree. Don't bother about that. */
    DECL_INITIAL( fndecl) = error_mark_node;

    /* All tree and rtl are allocated in temporary memory. Used per function. */
    //temporary_allocation();

    /*pushlevel is explained in call back. Here, it requires a push at the start of any function. */
    //pushlevel(0);

    /*create function rtl for function definition. */
   // make_function_rtl( fndecl);

    /*Generate rtl for the start of a function, fndecl. The second and third parameters denote the file and the line */
   // init_function_start(fndecl, input_filename, 1);

    /*Let's start the rtl for a new function. It also sets the variables used for emitting rtl. The second parameter shows that there is no cleanup associated with. If it is made nonzero, cleanup will be run when a return statement is met. */
    //expand_function_start(fndecl, 0);

    /*It generates the rtl code for entering a new binding level.*/
    //expand_start_bindings(0);

} //end of build_function_decl


void build_function()
{

    //tree fndecl; // Consider it as a global value.

    /*Let's build the tree and emit the rtl for the return statement. In order to avoid an extra tree variable, I have included the tree creation and rtl conversion in a single statement. First build a tree of type result for 'fndecl'. I am always returning zero from our simple function. If you intend to return any other value, replace integer_zero_node with the other corresponding tree structure. expand_return creates the rtl for the tree. */
    //expand_return (build (MODIFY_EXPR, void_type_node, DECL_RESULT(fndecl), integer_zero_node));

    /*Emit rtl for the end of bindings. Just like start bindings */
    //expand_end_bindings (NULL_TREE, 1, 0);

    /* We have pushed. So don't forget to pop */
    //poplevel (1, 0, 1);

    /*Emit rtl for the end of function. Just like starting */
    //expand_function_end (input_file_name, 1, 0);

    /*Compile the function, output the assembler code, Free the tree storage. */
    rest_of_decl_compilation (fndecl, 1, 0);

    /*We are free now */
    current_function_decl=0;

    /* Free everything in temporary store. Argument 1 shows that, we have just finished compiling a function */
    //permanent_allocation (1);
}


char *var_name[100];    //global array ie. initialized to zero.
tree var_decls[100];    //global array

void add_var(char *name)
{
    //tree fndecl; // Consider it as a global value.
    int i;

    /*Add the name given, as the first empty item in the array */
    for(i=0;var_name[i];i++)
        if (!var_name[i])
            var_name[i] = name;

    /*Build the tree structure for the variable declared
      All the parameters are explained before.
      Thus we have name of the variable stored in var_name[] and
      tree stored in var_decls[ ]*/
    var_decls[i] =
        build_decl (UNKNOWN_LOCATION, VAR_DECL, get_identifier(name), integer_type_node);

    /* Explained before*/
    DECL_CONTEXT (var_decls[i]) = fndecl;

    /*We are just making the initial value of the variable declared
      as zero. This is a matter of taste. */
    DECL_INITIAL (var_decls[i]) = integer_zero_node;

    /*push to the current scope. Explained before*/
    //pushdecl (var_decls[i]);

    /* Emit the rtl for the variable declaration*/
    rest_of_compilation (var_decls[i]);

    /* Emit the rtl for the initialization. ie. Initialized to zero*/
    //expand_decl_init (var_decls[i]);
}

tree get_var(char *name)
{
    int i;
    //Search for the name "name" in the variable name table, var_name[]
    for(i=0;var_name[i];i++)
        //If found, return the corresponding tree structure of "name"
        if( !strcmp (var_name[i], name))
            return var_decls[i];

    return NULL_TREE;
}

tree make_assign (tree vartree, tree valtree)
{
    tree assign;

    // Create the tree. Explained before.
    assign = build2 (MODIFY_EXPR, integer_type_node, vartree, valtree);

    /*Non zero values means that there is a side effect and re evaluation
    of the whole expression could produce a different value. The
    optimization phase takes this into consideration.
     */
    TREE_SIDE_EFFECTS (assign) = 1;

    /* Indicates that the tree node is used */
    TREE_USED (assign) = 1;

    return assign;
}

tree ret_stmt (tree expr)
{
    tree fndecl; // Consider it as a global value.
    tree ret;
    /* build the tree node for return. The arguments are explained
       before. 'fndecl' is the global variable that we have defined
       before, for our function.  */
    ret = build2 (MODIFY_EXPR, integer_type_node, DECL_RESULT(fndecl), expr);

    return ret;
}

%}

%code requires {
#include "neis.tab.h"
#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "stor-layout.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "debug.h"
#include "neis-tree.h"
#include "function.h"
#include "toplev.h"
#include "expr.h"
#include "stmt.h"
#include "name-lookup.h"
#include "stringpool.h"
}

%union{
    tree treenode;       //Tree
    int ival;       //Integer value for constants.
    char *name;     //Name of function or variables.
}

%token TINT TFLOAT TCHAR TDOUBLE TVOID
%token FOR WHILE 
%token IF ELSE
%token NUM ID
%token TRETURN

%type <treenode> CompoundStmt
%type <treenode> WhileStmt
%type <treenode> ForStmt
%type <treenode> IfStmt
%type <treenode> IfElseStmt
%type <treenode> ReturnStmt
%type <treenode> Stmt
%type <treenode> StmtList
%type <treenode> TINT TFLOAT TCHAR TDOUBLE TVOID
%type <ival> NUM
%type <name> ID
%type <treenode> TRETURN
%type <treenode> Arg
%type <treenode> Assignment
%type <treenode> Type
%type <treenode> Function
%type <treenode> FunctionCall
%type <treenode> Declaration
%type <treenode> Expr
%type <treenode> error
%type <treenode> ';'

%right '='
%left '/' '*'
%left TAND TOR
%left TLE TGE TEQ TNE TLT TGT

%%

start:   Function { build_function(); }
       | Declaration { build_function(); }
     ;

Declaration:  Type ID ';' { add_var($2); }
            | Assignment ';'    
            | FunctionCall ';'   
            | error 
           ;

/* Assignment block */
Assignment:   ID '=' Assignment { $$ = make_assign(get_var($1), $3); }
            | ID '=' FunctionCall  { $$ =  make_assign(get_var($1), $3); }
            | ID '+' Assignment { $$ = build2 (PLUS_EXPR, integer_type_node, get_var($1), $3); }
            | ID '-' Assignment { $$ = build2 (MINUS_EXPR, integer_type_node, get_var($1), $3); }
            | ID '*' Assignment { $$ = build2 (MULT_EXPR, integer_type_node, get_var($1), $3); }
            | ID '/' Assignment { $$ = build2 (TRUNC_DIV_EXPR, integer_type_node, get_var($1), $3); }
            | ID '%' Assignment { $$ = build2 (TRUNC_DIV_EXPR, integer_type_node, get_var($1), $3); }
            | NUM '+' Assignment { tree num = build_int_cst (integer_type_node, $1);
                                   $$ = build2 (PLUS_EXPR, integer_type_node,  num, $3); }
            | NUM '-' Assignment { tree num = build_int_cst (integer_type_node, $1);
                                   $$ = build2 (MINUS_EXPR, integer_type_node, num, $3); }
            | NUM '*' Assignment { tree num = build_int_cst (integer_type_node, $1);
                                   $$ = build2 (MULT_EXPR, integer_type_node, num, $3); }
            | NUM '/' Assignment { tree num = build_int_cst (integer_type_node, $1);
                                   $$ = build2 (TRUNC_DIV_EXPR, integer_type_node, num, $3); }
            | NUM '%' Assignment { tree num = build_int_cst (integer_type_node, $1);
                                   $$ = build2 (TRUNC_MOD_EXPR, integer_type_node, num, $3); }
            | ID TOR ID    {$$ = build2 (TRUTH_ORIF_EXPR, integer_type_node, get_var($1), get_var($3)); }
            | ID TAND ID  {$$ = build2 (TRUTH_ANDIF_EXPR, integer_type_node, get_var($1), get_var($3)); }
            | '\'' Assignment '\'' { $$ = $2; }
            | '(' Assignment ')' { $$ = $2; }
            | '-' '(' Assignment ')' { $$ = build1 (NEGATE_EXPR, integer_type_node, $3); }
            | '-' NUM { tree num = build_int_cst (integer_type_node, $2);
                        $$ = build2 (MINUS_EXPR, integer_type_node, integer_zero_node, num); }
            | '-' ID { $$ = build1 (NEGATE_EXPR, integer_type_node, get_var($2)); }
            |   NUM { $$ = build_int_cst (integer_type_node, $1); }
            |   ID  { $$ = get_var ($1); }
	;

/* Function Call Block */
FunctionCall :   ID'('')'  { $$ = build1 (CALL_EXPR, integer_type_node, get_var($1)); }
               | ID'('Assignment')'  { $$ = build0 (CALL_EXPR, get_var($1)); }
            ;

/* Function block */
Function: Type ID '(' ArgListOpt ')' CompoundStmt  { build_function_decl($2); }
	;

ArgListOpt: ArgList
            |
	;

ArgList:  ArgList ',' Arg
        | Arg
       ;

Arg:  Type ID 
    ;

CompoundStmt: '{' StmtList '}' {$$ = $2;}
	;

StmtList: StmtList Stmt
          | {}
	;

Stmt:  WhileStmt
      | Declaration
      | ForStmt
      | IfStmt
      | IfElseStmt
      | ReturnStmt
      | ';' {}
    ;

/* Type Identifier block */
Type:   TINT      
      | TFLOAT  
      | TCHAR   
      | TDOUBLE 
      | TVOID   
    ;

/* Loop Blocks */ 
WhileStmt:   WHILE '(' Expr ')' Stmt { $$ = build2 (WHILE_STMT, integer_type_node, $3, $5); }
	   | WHILE '(' Expr ')' CompoundStmt  { $$ = build2 (WHILE_STMT, integer_type_node, $3, $5); }
        ;

/* For Block */
ForStmt: FOR '(' Expr ';' Expr ';' Expr ')' Stmt { $$ = build4 (FOR_STMT, integer_type_ndoe, $3, $5, $7, $9); }
       | FOR '(' Expr ';' Expr ';' Expr ')' CompoundStmt { $$ = build4 (FOR_STMT, integer_type_ndoe, $3, $5, $7, $9); }
    ;

/* IfStmt Block */
IfStmt : IF '(' Expr ')' '{'
		Stmt
        '}' { $$ = build3 (COND_EXPR, integer_type_node, $3, $6, NULL_TREE); }
       ;

IfElseStmt : IF '(' Expr ')' '{'
		Stmt 
             '}' ELSE '{'
               Stmt
             '}' { $$ = build3 (COND_EXPR, integer_type_node, $3, $6, $10); }
	;

ReturnStmt: TRETURN Stmt ';' { $$ = ret_stmt ($2);}
        ;

/*Expression Block*/
Expr:   Expr TLE Expr {$$ = build2 (LE_EXPR, integer_type_node, $1, $3); } 
      | Expr TGE Expr {$$ = build2 (GE_EXPR, integer_type_node, $1, $3); } 
      | Expr TNE Expr {$$ = build2 (NE_EXPR, integer_type_node, $1, $3); } 
      | Expr TEQ Expr {$$ = build2 (EQ_EXPR, integer_type_node, $1, $3); } 
      | Expr TGT Expr {$$ = build2 (GT_EXPR, integer_type_node, $1, $3); } 
      | Expr TLT Expr {$$ = build2 (LT_EXPR, integer_type_node, $1, $3); } 
      | Assignment
    ;

%%

#include "lex.yy.c"

int yylex(void);
int yyparse(void);

void yyerror(const char *s) {
    printf("Linha %d : %s (%s) \n", yylineno, s, yytext );
}
