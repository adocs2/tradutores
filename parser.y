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
    }
    | simple-expr ';' { 
        $$ = $1; 
    }
;

set-func:
    ADD '(' in-stmt ')' {
        $$ = create_tree_node("ADD_STATEMENT", $3, NULL, NULL, $1);
    }
    | REMOVE '(' in-stmt ')' {
        $$ = create_tree_node("REMOVE_STATEMENT", $3, NULL, NULL, $1);
    }
    | EXISTS '(' in-stmt')' {
        $$ = create_tree_node("EXISTS_STATEMENT", $3, NULL, NULL, $1);
    }
    | IS_SET '(' var ')' {
        $$ = create_tree_node("IS_SET_STATEMENT", $3, NULL, NULL, $1);
    }
;

simple-expr:
    op-expr RELOP op-expr { 
        $$ = create_tree_node("RELATIONAL_EXPRESSION", $1, $3, NULL, $2);
    }
    | op-expr { 
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
    | WRITE '(' var ')' ';' { 
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
    | WRITELN '(' var ')' ';' { 
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
        $$ = create_tree_node("CONDITIONAL_STATEMENT", $3, $5, NULL, $1);
    }
    | IF '(' simple-expr ')' compound-inline ELSE compound-inline {
        node* aux_node = create_tree_node("CONDITIONAL_STATEMENT", $5, $7, NULL, $6);
        $$ = create_tree_node("CONDITIONAL_STATEMENT", $3, aux_node, NULL, $1);
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
    }
    | RETURN ';' { 
        $$ = create_tree_node("RETURN_STATEMENT", NULL, NULL, "void", $1); 
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
    }
    | op-expr LOG term { 
        $$ = create_tree_node("LOGICAL_EXPRESSION", $1, $3, NULL, $2); 
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
        $$ = create_tree_node("FLOATNUMBER", NULL, NULL, "elem", $1); 
    }
    | SET { 
        $$ = create_tree_node("FLOATNUMBER", NULL, NULL, "set", $1); 
    }
    | EMPTY { 
        $$ = create_tree_node("EMPTY_VALUE", NULL, NULL, "empty", $1); 
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
    if(s == NULL){ // variável não declarada, adicionar na tabela
        s = create_symbol(key, name, type, symbol_type, scope->scope_name);
        HASH_ADD_STR(symbol_table, key, s);
    }
    else{ // erro de variável redeclarada
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