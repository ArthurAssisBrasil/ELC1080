/*
* pessoas.c
* TAD que implementa funcoes das threads de Pessoa.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "pessoas.h"
#include "elevador.h"

void *pessoa(void *vargp){
    int i = 0;
    Pessoa *p = (Pessoa*) vargp;

    printf("Comecou a thread pessoa %d\n", p->id);
    // Faz um trabalho qualquer
    for(i = 0; i < 1000000; i++);
    name();

    if(p->andar_atual == 0)
    printf("Terminou a thread pessoa %d\n", p->id);

    pthread_exit((void *)NULL);
}


void acessa_elevador(){
  printf("funcao muito louca \n");
  return;
}
