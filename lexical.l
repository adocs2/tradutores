/* Afonso Dias de Oliveira Conceição Silva - 140055771 */
 
%{
 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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
%s STRING
STR [^\"]*
TYPE "int"|"float"|"set"|"elem"
EMPTY EMPTY

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

<INITIAL,STRING>{QUOTES} {
    if(inside_string) { 
        BEGIN(0);
        inside_string--;
        printf("%s%s\n", yytext, closeParenthesis);
    }
    else { 
        BEGIN(STRING);
        inside_string++;
        printf("STRING\t\t%s%s", openParenthesis, yytext);
    }
}


<STRING>{STR} { 
    if(strcmp(yytext, "\n") == 0){line++;} 
    printf("%s", yytext);

}
{INT} {
    printf("INT\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{FLOAT} {
    printf("FLOAT\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{TYPE} {
    printf("TYPE\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

"if" {
    printf("IF\n");
}
"else" {
    printf("ELSE\n");
}
"return" {
    printf("RETURN\n");
}
"printf" {
    printf("PRINT\n");
}

"read" {
    printf("READ\n");
}

"writeln" {
    printf("WRITELN\n");
}

"write" {
    printf("WRITE\n");
}

"in" {
    printf("IN\n");
}

"is_set" {
    printf("IS_SET\n");
}

"add" {
    printf("ADD\n");
}
"remove" {
    printf("REMOVE\n");
}
"exists" {
    printf("EXISTS\n");
}

"forall" {
    printf("FORALL\n");
}
"for" {
    printf("FOR\n");
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
}

{OP} {
    printf("OP\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{ASSIGN} {
    printf("ASSIGN\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{LOG} {
    printf("LOG\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{RELOP} {
    printf("RELOP\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

{ID} {
    printf("ID\t\t(%s) LENGTH %d\n", yytext, yyleng);
}

"," {
   printf(",\n");
}

";" {
    printf(";\n");
}

"(" {
    printf("(\n");
}

")" {
    printf(")\n");
}

"{" {
    printf("{\n");
}

"}" {
    printf("}\n");
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
    char *error = (char *)malloc((strlen(symbol) + 1 + 35) * sizeof(char)); // +1 for the null-terminator and 35 for lex error message
    sprintf(error, "lexical error, unrecognizable symbol %s", symbol);
    yyerror(error);
    free(error);
}
 
int main(int argc, char **argv) {
    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        yyin = stdin;
    }
    
    yylex();
    fclose(yyin);
    yylex_destroy();
}