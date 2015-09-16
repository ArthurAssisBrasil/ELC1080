/*
* elevador.c
* TAD que implementa fun��es das threads de Elevador.
*/
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "elevador.h"

void *elevador(){
  int i;
  printf("Comecou a thread Elevador!\n");
  for(i = 0; i < 1000000; i++);

  //if(p->andar_atual == 0)
  printf("Terminou a thread Elevador\n");
  pthread_exit((void *)NULL);

}
