/* Afonso Dias de Oliveira Conceição Silva - 140055771 */
 
%{
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "parser.tab.h"

char openParenthesis[] = "(";
char closeParenthesis[] = ")";
int line = 1;
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
STRING			(\"([^(\"\')])*\")
CHAR			(\'([^(\"\')])+\')

OP "+"|"-"|"*"|"/"
ASSIGN "="
RELOP "<="|"=="|">="|">"|"<"|"!="
LOG "&&"|"||"|"!"

ID {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

QUOTES \"

%x COMMENT

 
%%
{EOL} {
    line++;
}

{WHITESPACE} { }


{STRING} { 
    if(strcmp(yytext, "\n") == 0){line++;} 
    printf("%s", yytext);
    yylval.token = (char *) strdup(yytext);
    return STR; 
}

{CHAR} { 
    if(strcmp(yytext, "\n") == 0){line++;} 
    printf("%s", yytext);
    yylval.token = (char *) strdup(yytext);
    return CHAR; 

}


{INT} {
    printf("INT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return INT; 
}

{FLOAT} {
    printf("FLOAT\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return FLOAT; 
}

{TYPE} {
    printf("TYPE\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return TYPE;
}

"if" {
    printf("IF\n");
    yylval.token = (char *) strdup(yytext);
    return IF;
}
"else" {
    printf("ELSE\n");
    yylval.token = (char *) strdup(yytext);
    return ELSE;
}
"return" {
    printf("RETURN\n");
    yylval.token = (char *) strdup(yytext);
    return RETURN;
}

"read" {
    printf("READ\n");
    yylval.token = (char *) strdup(yytext);
    return READ;
}

"writeln" {
    printf("WRITELN\n");
    yylval.token = (char *) strdup(yytext);
    return WRITELN;
}

"write" {
    printf("WRITE\n");
    yylval.token = (char *) strdup(yytext);
    return WRITE;
}

"in" {
    printf("IN\n");
    yylval.token = (char *) strdup(yytext);
    return IN;
}

"is_set" {
    printf("IS_SET\n");
    yylval.token = (char *) strdup(yytext);
    return IS_SET;
}

"add" {
    printf("ADD\n");
    yylval.token = (char *) strdup(yytext);
    return ADD;
}
"remove" {
    printf("REMOVE\n");
    yylval.token = (char *) strdup(yytext);
    return REMOVE;
}
"exists" {
    printf("EXISTS\n");
    yylval.token = (char *) strdup(yytext);
    return EXISTS;
}

"forall" {
    printf("FORALL\n");
    yylval.token = (char *) strdup(yytext);
    return FORALL;
}
"for" {
    printf("FOR\n");
    yylval.token = (char *) strdup(yytext);
    return FOR;
}


"/*" {
    BEGIN(COMMENT);
}

"//".*  {
   
}

<COMMENT>"*/" {
    BEGIN(INITIAL);
}

<COMMENT>\n {line++;}

<COMMENT>. { }

{EMPTY} {
    printf("EMPTY\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token= (char *) strdup(yytext);
    return EMPTY;
}

{OP} {
    printf("OP\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return OP;
}

{ASSIGN} {
    printf("ASSIGN\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return ASSIGN;
}

{LOG} {
    printf("LOG\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return LOG;
}

{RELOP} {
    printf("RELOP\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return RELOP;
}

{ID} {
    printf("ID\t\t(%s) LENGTH %d\n", yytext, yyleng);
    yylval.token = (char *) strdup(yytext);
    return ID;
}

"," {
   printf(",\n");
   return yytext[0];
}

";" {
    printf(";\n");
    return yytext[0];
}

"(" {
    printf("(\n");
    return yytext[0];
}

")" {
    printf(")\n");
    return yytext[0];
}

"{" {
    printf("{\n");
    return yytext[0];
}

"}" {
    printf("}\n");
    return yytext[0];
}

"/r" {}

"\r" {}

. {
  lexical_error_unrecognizable_symbol(yytext);
}
  
%%
void yyerror(const char* msg) {
    fprintf(stderr, "\n%s -- linha: %d\n", msg, line);
    total_errors++;
}

void lexical_error_unrecognizable_symbol(char* symbol){
    char *error = (char *)malloc((strlen(symbol) + 1 + 35) * sizeof(char));
    sprintf(error, "lexical error, unrecognizable symbol %s", symbol);
    yyerror(error);
    free(error);
}