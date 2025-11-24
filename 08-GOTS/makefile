LEX = flex
YACC = bison
CC = gcc
CFLAGS = -w -g

all: parser

parser: parser.tab.o lex.yy.o tabla_simbolos.o
	$(CC) $(CFLAGS) parser.tab.o lex.yy.o tabla_simbolos.o -o parser

parser.tab.o: parser.tab.c parser.tab.h tabla_simbolos.h
	$(CC) $(CFLAGS) -c parser.tab.c -o parser.tab.o

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c -o lex.yy.o

tabla_simbolos.o: tabla_simbolos.c tabla_simbolos.h
	$(CC) $(CFLAGS) -c tabla_simbolos.c -o tabla_simbolos.o

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y 2>/dev/null

lex.yy.c: lexer.l
	$(LEX) lexer.l

test-valid: parser
	@echo "\n=== Probando archivos válidos ===\n"
	@./parser archivoValido.go
	@echo "\n"
	@./parser archivoValido2.go

test-invalid: parser
	@echo "\n=== Probando archivos inválidos ===\n"
	@./parser archivoInvalido.go
	@echo "\n"
	@./parser archivoInvalido2.go

test-semantic: parser
	@echo "\n=== Probando archivos con errores semánticos ===\n"
	@./parser testSemantico1.go


test-all: test-valid test-invalid test-semantic

clean:
	rm -f parser.tab.c parser.tab.h parser.tab.o lex.yy.c lex.yy.o tabla_simbolos.o parser parser.exe

.PHONY: all clean test-valid test-invalid test-semantic test-all