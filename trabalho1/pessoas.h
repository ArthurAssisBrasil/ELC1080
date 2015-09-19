#ifndef _PESSOAS_H_
#define _PESSOAS_H_

/*
* pessoas.c
* TAD que implementa funcoes das threads de Pessoa
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "elevador.h"

typedef struct{
    int nVisitas;
    int* andares;  //lista de andares a serem visitados
    unsigned long int* tempo_visita;
    int andar_atual;
    int id;
    Elevador e;
}Pessoa;

void *pessoa(void *vargp);
void acessa_elevador(void *vargp);
void sai_elevador(void *vargp);

#endif
