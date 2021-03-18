flex:
	bison -d --xml --graph parser.y
	flex lexical.l
	gcc -g -Wall parser.tab.c lex.yy.c -o program.out
clear:
	rm *.yy.c *.out *.dot *.tab.c *.tab.h *.png *.xml