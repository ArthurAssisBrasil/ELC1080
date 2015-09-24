/*
* elevador.c
* TAD que implementa fun��es das threads de Elevador.
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
  e->botoes = (int*)memo_aloca(13*sizeof(int)); /* aloca botoes: 5 internos e 8 externos */
  printf("Comecou a thread Elevador!\n");
  for(i = 0; i < 100000000; i++);

  printf("Terminou a thread Elevador\n");
  pthread_exit((void *)NULL);
}
