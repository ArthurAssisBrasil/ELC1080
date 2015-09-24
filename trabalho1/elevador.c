/*
* elevador.c
* TAD que implementa funcoes das threads de Elevador.
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "elevador.h"
#include "memo.h"

#define TEMPO_MIN 2000000000 //2 segundos: tempo minimo de para deixar a porta aberta

void *elevador(void *var){
  int i;
  Elevador *e = (Elevador*) var;
  e->estado = PARADO; //elevador inicialmente parado
  e->botoes_ext = (int*)memo_aloca(8*sizeof(int)); /* aloca botoes externos: 2 por andar. Térreo e quarto andar: 1 botão */
  e->botoes_int = (int*)memo_aloca(5*sizeof(int)); /* aloca botoes internos: 1 por andar. */
  printf("Comecou a thread Elevador!\n");
  for(i = 0; i < 100000000; i++);

  printf("Terminou a thread Elevador\n");
  pthread_exit((void *)NULL);
}

void movimenta_elevador(){

}
