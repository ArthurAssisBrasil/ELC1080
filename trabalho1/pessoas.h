#ifndef _PESSOAS_H_
#define _PESSOAS_H_

/*
* pessoas.c
* TAD que implementa funcoes das threads de Pessoa
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int nVisitas;
    int* andares;  //lista de andares a serem visitados
    unsigned long int* tempo_visita;
    int andar_atual;
    int id;
}Pessoa;

void *pessoa(void *vargp);
void name();

#endif
