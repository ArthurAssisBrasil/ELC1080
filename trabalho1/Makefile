###############################################################################
# Makefile para compilacao
###############################################################################
# define o compilador C
CC = gcc
# define flags do compilador
CFLAGS = -Wall -g
# define flags do ligador
LDFLAGS = -lm -lpthread

# define uma variavel com o nome do programa
PROG = principal

###############################################################################
# comeca aqui os alvos de compilacao
# cada alvo e formado de:
# alvo: dep1 dep2
#
# onde alvo e o arquivo gerado, e dep1 e dep2 sao dependencias para gerar o alvo.

# o primeiro alvo e o padrao.
all: principal

# descreve o objeto principal.o, compilado de forma implicita
principal.o: principal.c

# descreve o objeto pessoas.o, compilado de forma implicita
pessoas.o: pessoas.c pessoas.h

# descreve o objeto elevador.o, compilado de forma implicita
carta.o: elevador.c elevador.h


# programa principal, compilado de forma implicita
principal: principal.o pessoas.o elevador.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


# comando para limpar arquivos, digite
# $ make clean
clean:
	rm -f *.o $(PROG)
