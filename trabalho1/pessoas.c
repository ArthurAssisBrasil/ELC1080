/*
* pessoas.c
* TAD que implementa funções das threads de Pessoa.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "pessoas.h"

void *pessoa(void *vargp){
    int i = 0;
    Pessoa *a = (Pessoa*) vargp;

    printf("Comecou a thread pessoa %d\n", a->id);
    // Faz um trabalho qualquer
    for(i = 0; i < 1000000; i++);
    printf("Terminou a thread pessoa %d\n", a->id);

    pthread_exit((void *)NULL);
}
