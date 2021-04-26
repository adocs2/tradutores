/* Afonso Dias de Oliveira Conceição Silva - 140055771 */
%define lr.type canonical-lr
%{
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

%}

%union {
    char* token;
    struct node* node;
}

%token <token> INT FLOAT SET STR ELEM EMPTY TYPE ID IF ELSE RETURN FOR FORALL READ ADD REMOVE IN WRITE WRITELN EXISTS IS_SET QUOTES CHAR THEN

%right <token> ASSIGN

%left <token> OP RELOP LOG

%nonassoc THEN ELSE

%type <node> program declaration-list variable-declaration function params-list compound-stmt params stmt-list stmt set-func expr simple-expr conditional-stmt
             iteration-stmt return-stmt write-stmt writeln-stmt read-stmt var op-expr in-stmt term call args arg-list  error compound-inline

%%
program:
    declaration-list { 
        parser_tree = $1;
        check_semantic_error_no_main();
    }
    | error{yyerrok;}
;

declaration-list:
    declaration-list variable-declaration { 
        $$ = create_tree_node("DECLARATION_LIST", $1, $2, NULL, NULL);
    }
    | variable-declaration { 
        $$ = $1;
    }
     | declaration-list function { 
        $$ = create_tree_node("DECLARATION_LIST", $1, $2, NULL, NULL);
    }
    | function { 
        $$ = $1;
    }
    | {
        $$ = NULL;
    }
;

variable-declaration:
    TYPE ID ';' { 
        $$ = create_tree_node("VARIABLE_DECLARATION", NULL, NULL, $1, $2);
        add_symbol($2, $1, "variable");
    }
;

function:
    TYPE ID { 
        add_symbol($2, $1, "function");
        push_stack($2, $1);
    }
    '(' params-list ')' compound-stmt { 
        $$ = create_tree_node("FUNCTION", $5, $7, $1, $2);
        pop_stack();
    }
;

params-list: 
    params {
        $$ = $1;
    }
    | { 
        $$ = NULL; 
    }
;

params:
    params ',' TYPE ID { 
        $$ = create_tree_node("PARAMETER", $1, NULL, $3, $4);
        add_symbol($4, $3, "parameter");
    }
    | TYPE ID { 
        $$ = create_tree_node("PARAMETER", NULL, NULL, $1, $2);
        add_symbol($2, $1, "parameter");
    }
;

compound-inline: compound-stmt {
                    $$ = $1;
                }
                | stmt {
                    $$ = $1;
                }
;

compound-stmt:
    '{' stmt-list '}' { 
        $$ = create_tree_node("COMPOUND_STATEMENT", $2, NULL , NULL, NULL);
    }
;

stmt-list:
    stmt-list stmt { 
        $$ = create_tree_node("STATEMENT_LIST", $1, $2, NULL, NULL);
    }
    | { 
        $$ = NULL; 
    }
;

stmt: 
    variable-declaration {
        $$ = $1;
    }
    | expr { 
        $$ = $1; 
    }
    | conditional-stmt { 
        $$ = $1; 
    }
    | iteration-stmt { 
        $$ = $1; 
    }
    | return-stmt {
        $$ = $1; 
    }
    | set-func ';' {
        $$ = $1; 
    }
    | write-stmt {
        $$ = $1;
    }
    | writeln-stmt {
        $$ = $1;
    }
    | read-stmt {
        $$ = $1;
    }
    | error { 
        $$ = $1;
        yyerrok;
    }
;

expr:
    var ASSIGN expr { 
        $$ = create_tree_node("ASSIGN_EXPRESSION", $1, $3, NULL, $2);
         define_type($$);
    }
    | simple-expr ';' { 
        $$ = $1; 
    }
;

set-func:
    ADD '(' in-stmt ')' {
        $$ = create_tree_node("ADD_STATEMENT", $3, NULL, "set", $1);
    }
    | REMOVE '(' in-stmt ')' {
        $$ = create_tree_node("REMOVE_STATEMENT", $3, NULL, "set", $1);
    }
    | EXISTS '(' in-stmt')' {
        $$ = create_tree_node("EXISTS_STATEMENT", $3, NULL, "set", $1);
    }
    | IS_SET '(' var ')' {
        $$ = create_tree_node("IS_SET_STATEMENT", $3, NULL, "set", $1);
    }
;

simple-expr:
    op-expr { 
        $$ = $1; 
    }
    | LOG set-func {
        $$ = create_tree_node("LOGICAL_EXPRESSION", $2, NULL, NULL, $1);
    }
    | set-func {
        $$ = $1; 
    }
    | in-stmt {
        $$ = $1;
    }
;

in-stmt: 
    simple-expr IN simple-expr {
        $$ = create_tree_node("IN_STATEMENT", $1, $3, NULL, $2);
    }
;

write-stmt: 
    WRITE '(' STR  ')' ';' {
        $$ = create_tree_node("WRITE_STATEMENT", NULL, NULL, "string", $3);
    }
    | WRITE '(' CHAR  ')' ';' {
        $$ = create_tree_node("WRITE_STATEMENT", NULL, NULL, "char", $3);
    }
    | WRITE '(' term ')' ';' { 
        $$ = create_tree_node("WRITE_STATEMENT", $3, NULL, $3->type, $1); 
    }
;

writeln-stmt: 
    WRITELN '('  STR  ')' ';' {
        $$ = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "string", $3);
    }
    | WRITELN '('  CHAR  ')' ';' {
        $$ = create_tree_node("WRITELN_STATEMENT", NULL, NULL, "char", $3);
    }
    | WRITELN '(' term ')' ';' { 
        $$ = create_tree_node("WRITELN_STATEMENT", $3, NULL, $3->type, $1); 
    }
;

read-stmt: 
    READ '(' var ')' ';' {
        $$ = create_tree_node("READ_STATEMENT", $3, NULL, NULL, $1);
    }
;

conditional-stmt:
    IF '(' simple-expr ')' compound-inline %prec THEN { 
        $$ = create_tree_node("CONDITIONAL_STATEMENT_IF", $3, $5, NULL, $1);
    }
    | IF '(' simple-expr ')' compound-inline ELSE compound-inline {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT_ELSE", $7, NULL, NULL, $6);
        $$ = create_tree_node("CONDITIONAL_STATEMENT_IF", $5, aux_node, NULL, $1);
    }
;

iteration-stmt:
    FORALL '(' in-stmt ')' compound-inline { 
        $$ = create_tree_node("ITERATION_STATEMENT", $3, $5, NULL, $1);
    }
;

return-stmt:
    RETURN simple-expr ';' { 
        $$ = create_tree_node("RETURN_STATEMENT", $2, NULL, NULL, $1); 
        define_type($$);
        check_semantic_error_return_type($$->type, $$);
    }
    | RETURN ';' { 
        $$ = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", $1); 
        check_semantic_error_return_type($$->type, $$);
    }
;

var:
    ID {
        symbol_node* s = search_for_symbol($1);
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        $$ = create_tree_node("VARIABLE", NULL, NULL, type, $1);
    }
;

op-expr:
    op-expr OP term {
        $$ = create_tree_node("ARITHIMETIC_EXPRESSION", $1, $3, NULL, $2);
        define_type($$);
    }
    | op-expr LOG term { 
        $$ = create_tree_node("LOGICAL_EXPRESSION", $1, $3, NULL, $2);
        define_type($$);
    }
    | op-expr RELOP term { 
        $$ = create_tree_node("RELATIONAL_EXPRESSION", $1, $3, NULL, $2);
        define_type($$);
    }
    | term { 
        $$ = $1; 
    }
;

term:
    '(' simple-expr ')' { 
        $$ = $2; 
    }
    | var { 
        $$ = $1; 
    }
    | call { 
        $$ = $1; 
    }
    | INT { 
        $$ = create_tree_node("INTEGER", NULL, NULL, "int", $1); 
    }
    | FLOAT { 
        $$ = create_tree_node("FLOATNUMBER", NULL, NULL, "float", $1); 
    }
    | ELEM { 
        $$ = create_tree_node("ELEM", NULL, NULL, "elem", $1); 
    }
    | SET { 
        $$ = create_tree_node("SET", NULL, NULL, "set", $1); 
    }
    | EMPTY { 
        $$ = create_tree_node("EMPTY_VALUE", NULL, NULL, "set", $1); 
    }
;

call:
    ID '(' args ')' {
        symbol_node* s = search_for_symbol($1);
        char* type = NULL;
        if(s != NULL){
            type = s->type;
        }
        $$ = create_tree_node("FUNCTION_CALL", $3, NULL, type, $1);
        check_semantic_error_type_mismatch_args($3, $1);
    }
;

args:
    arg-list { 
        $$ = $1;
    }
    | { 
        $$ = NULL;
    }
;

arg-list:
    simple-expr ',' arg-list { 
        $$ = create_tree_node("ARGS_LIST", $1, $3, NULL, NULL); 
    }
    | simple-expr { 
        $$ = $1; 
    }
;

%%

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