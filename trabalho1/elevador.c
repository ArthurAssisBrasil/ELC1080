/*
* elevador.c
* TAD que implementa fun��es das threads de Elevador.
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "elevador.h"

#define TEMPO_MIN 2000000000 //2 segundos: tempo minimo de para deixar a porta aberta

void *elevador(void *var){
  int i;
  Elevador *e = (Elevador*) var;
  e->estado = 0; //elevador inicialmente parado
  printf("Comecou a thread Elevador!\n");
  for(i = 0; i < 100000000; i++);

  printf("Terminou a thread Elevador\n");
  pthread_exit((void *)NULL);
}
