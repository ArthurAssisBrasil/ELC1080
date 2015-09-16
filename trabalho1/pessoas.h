#ifndef _PESSOAS_H_
#define _PESSOAS_H_

/*
* pessoas.c
* TAD que implementa fun��es das threads de Pessoa.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int nVisitas;
    int* andares;
    int andar_atual;
    int id;
}Pessoa;

void *pessoa(void *vargp);

#endif
