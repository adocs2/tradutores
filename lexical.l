/* Afonso Dias de Oliveira Conceição Silva - 140055771 */
 
%{
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"

char openParenthesis[] = "(";
char closeParenthesis[] = ")";
int line = 1;
int column = 1;
int inside_string = 0;
int total_errors = 0;

void lexical_error_unrecognizable_symbol(char* symbol);
void yyerror(const char* msg);
 
%}

%option noyywrap
%option noinput nounput

EOL \n
DELIM [ \t]
WHITESPACE {DELIM}+

LETTER [a-zA-Z]
UNDERSCORE "_"
DIGIT [0-9]

INT "-"?{DIGIT}+
FLOAT "-"?{DIGIT}+"."({DIGIT}*)?
TYPE "int"|"float"|"set"|"elem"
EMPTY EMPTY
STRING			\"[^"]*\"
CHAR			(\'(.|\\a|\\b|\\f|\\n|\\r|\\t|\\v|\\\\|\\\'|\\\"|\\\?)\')

ADD_OP				("+")
SUB				("-")
MULT			("*")
DIV				("/")
ASSIGN "="
OR			("||")
AND			("&&")
NOT			("!")
EQ			("==")
GE			(">=")
LE			("<=")
NE			("!=")
G			(">")
L			("<")

ID {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

QUOTES \"

%x COMMENT

 
%%
{EOL} {
    line++;
    column = 1;
}

{WHITESPACE} {
    column += strlen(yytext);
}


{STRING} { 
    if(strcmp(yytext, "\n") == 0){line++;} 
    //printf("%s", yytext);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return STR; 
}

{CHAR} { 
    if(strcmp(yytext, "\n") == 0){line++;} 
    //printf("%s", yytext);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return CHAR; 
}


{INT} {
    //printf("INT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return INT; 
}

{FLOAT} {
    //printf("FLOAT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return FLOAT; 
}

{TYPE} {
    //printf("TYPE\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return TYPE;
}

"if" {
    //printf("IF\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return IF;
}
"else" {
    //printf("ELSE\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return ELSE;
}
"return" {
    //printf("RETURN\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return RETURN;
}

"read" {
    //printf("READ\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return READ;
}

"writeln" {
    //printf("WRITELN\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return WRITELN;
}

"write" {
    //printf("WRITE\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return WRITE;
}

"in" {
    //printf("IN\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return IN;
}

"is_set" {
    // printf("IS_SET\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return IS_SET;
}

"add" {
    // printf("ADD\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return ADD;
}
"remove" {
    // printf("REMOVE\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return REMOVE;
}
"exists" {
    // printf("EXISTS\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return EXISTS;
}

"forall" {
    // printf("FORALL\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return FORALL;
}
"for" {
    // printf("FOR\n");
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return FOR;
}


"/*" {
    BEGIN(COMMENT);
    column += strlen(yytext);
}

"//".*  {
   
}

<COMMENT>"*/" {
    BEGIN(INITIAL);
    column += strlen(yytext);
}

<COMMENT>\n {line++;column += strlen(yytext);}

<COMMENT>. { }

{EMPTY} {
    // printf("EMPTY\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token= (char *) strdup(yytext);
    column += strlen(yytext);
    return EMPTY;
}

{ADD_OP} {
    // printf("ADD_OP\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return ADD_OP;
}

{SUB} {
    // printf("SUB\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return SUB;
}

{MULT} {
    // printf("MULT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return MULT;
}

{DIV} {
    // printf("DIV\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return DIV;
}

{OR} {
    // printf("OR\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return OR;
}

{AND} {
    // printf("AND\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return AND;
}

{NOT} {
    // printf("NOT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return NOT;
}

{EQ} {
    // printf("EQ\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return EQ;
}

{GE} {
    // printf("GE\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return GE;
}

{LE} {
    // printf("LE\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return LE;
}

{NE} {
    // printf("NE\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return NE;
}

{G} {
    // printf("G\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return G;
}

{L} {
    // printf("L\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return L;
}

{ASSIGN} {
    // printf("ASSIGN\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return ASSIGN;
}

{ID} {
    // printf("ID\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    column += strlen(yytext);
    return ID;
}

"," {
//    printf(",\n");
   column += strlen(yytext);
   return yytext[0];
}

";" {
    // printf(";\n");
    column += strlen(yytext);
    return yytext[0];
}

"(" {
    // printf("(\n");
    column += strlen(yytext);
    return yytext[0];
}

")" {
    // printf(")\n");
    column += strlen(yytext);
    return yytext[0];
}

"{" {
    // printf("{\n");
    column += strlen(yytext);
    return yytext[0];
}

"}" {
    // printf("}\n");
    column += strlen(yytext);
    return yytext[0];
}

"/r" {}

"\r" {}

. {
  lexical_error_unrecognizable_symbol(yytext);
}
  
%%
void yyerror(const char* msg) {
    fprintf(stderr, "\n%s -- linha: %d, coluna: %d\n", msg, line, column);
    total_errors++;
}

void lexical_error_unrecognizable_symbol(char* symbol){
    char *error = (char *)malloc((strlen(symbol) + 1 + 35) * sizeof(char));
    sprintf(error, "lexical error, unrecognizable symbol %s", symbol);
    yyerror(error);
    free(error);
}