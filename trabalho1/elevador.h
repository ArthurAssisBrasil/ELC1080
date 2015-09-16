#ifndef _ELEVADOR_H_
#define _ELEVADOR_H_

/*
* elevador.h
* TAD que implementa fun��es das threads de Elevador.
*/

typedef struct elevador{
  int* andar;
  int* botoes;
  int sentido;
  int capacidade;
}Elevador;

void *elevador();
/* funcoes */

#endif
