#ifndef _ELEVADOR_H_
#define _ELEVADOR_H_

/*
* elevador.h
* TAD que implementa fun��es das threads de Elevador.
*/

#define CAPACIDADE 3

typedef struct elevador{
  int* andar;
  int* botoes;
  int sentido;
  int lotacao;
}Elevador;

void *elevador(void *var);
/* funcoes */

#endif
