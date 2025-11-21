LEX = flex
YACC = bison
CC = gcc
CFLAGS = -Wall -Wextra

all: parser

parser: parser.tab.o lex.yy.o
	$(CC) $(CFLAGS) parser.tab.o lex.yy.o -o parser

parser.tab.o: parser.tab.c parser.tab.h
	$(CC) $(CFLAGS) -c parser.tab.c -o parser.tab.o

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

lex.yy.c: lexer.l
	$(LEX) lexer.l

clean:
	rm -f parser.tab.c parser.tab.h parser.tab.o lex.yy.c lex.yy.o parser parser.exe

.PHONY: all clean
