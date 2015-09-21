/*
* pessoas.c
* TAD que implementa funcoes das threads de Pessoa.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "pessoas.h"
#include "elevador.h"

pthread_mutex_t mutex_pessoa;
pthread_cond_t cond_pessoa;

void *pessoa(void *vargp){
    int i = 0;
    Pessoa *p = (Pessoa*) vargp;

    // Cria o mutex
    pthread_mutex_init(&mutex_pessoa, NULL);

    // Cria a variavel de condicao
    pthread_cond_init(&cond_pessoa, NULL);

    printf("Comecou a thread pessoa %d\n", p->id);
    // Faz um trabalho qualquer
    for(i = 0; i < 1000000; i++);
    acessa_elevador(vargp);
    sai_elevador(vargp);

    if(p->andar_atual == 0)
    printf("Terminou a thread pessoa %d\n", p->id);
    pthread_cond_destroy(&cond_pessoa);
    pthread_exit((void *)NULL);
}


void acessa_elevador(void *vargp){
  Pessoa *p = (Pessoa*) vargp;

  if(p->e.lotacao <= CAPACIDADE) {
        printf("\nThread %d: Entrou no elevador\n", p->id);
        printf("\nLotacao atual: %d\n", p->e.lotacao);
        p->e.lotacao++; //altera lotação apenas localmente: CORRIGIR
        printf("\nLotacao atual: %d\n", p->e.lotacao);

        pthread_cond_wait(&cond_pessoa, &mutex_pessoa);
        printf("Thread %d: Acabou a espera\n", p->id);
    }
    else {
        sleep(5);
        printf("Sinaliza outras threads\n");
        pthread_cond_signal(&cond_pessoa);
    }
    //pthread_exit((void *)NULL);
}

void sai_elevador(void *vargp){
  Pessoa *p = (Pessoa*) vargp;
  printf("Saiu do Elevador\n");
  p->e.lotacao --;
  pthread_exit((void *)NULL);

}
