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
  printf("Comecou a thread Elevador!\n");
  e->lotacao = 0;
  for(i = 0; i < 1000000; i++);

  //if(p->andar_atual == 0)
  printf("Terminou a thread Elevador\n");
  pthread_exit((void *)NULL);

}
