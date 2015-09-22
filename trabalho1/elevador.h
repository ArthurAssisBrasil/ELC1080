#ifndef _ELEVADOR_H_
#define _ELEVADOR_H_

/*
* elevador.h
* TAD que implementa funcoes das threads de Elevador.
*/

//#define CAPACIDADE 3

typedef struct elevador{
  int* andar;
  int* botoes;
  int estado; /* estado pode ser: parado, descendo ou subindo */
  int lotacao;
}Elevador;

/* funcoes */
void *elevador(void *var);

#endif
