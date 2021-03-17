flex:
	flex lexical.l
	gcc -g -Wall lex.yy.c -o lexical.out
clear:
	rm *.yy.c *.out