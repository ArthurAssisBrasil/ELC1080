#ifndef _ELEVADOR_H_
#define _ELEVADOR_H_

/*
* elevador.h
* TAD que implementa funcoes das threads de Elevador.
*/

//#define CAPACIDADE 3
enum Estado {DESCENDO, PARADO, SUBINDO};

typedef struct elevador{
  int* andar;
  int* botoes;
  enum Estado estado;
}Elevador;

/* funcoes */
void *elevador(void *var);

#endif
