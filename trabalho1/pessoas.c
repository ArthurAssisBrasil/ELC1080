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

    pthread_exit((void *)NULL);
}


void acessa_elevador(void *vargp){
  Pessoa *p = (Pessoa*) vargp;

  if(p->e.capacidade < 4) {
        printf("\nThread %d: Entrou no elevador\n", p->id);
        p->e.capacidade++;
        pthread_cond_wait(&cond_pessoa, &mutex_pessoa);
        printf("Thread %d: Acabou a espera\n", p->id);
    }
    else {
        sleep(1);
        printf("Thread %d: Sinalizando a outra thread\n", p->id);
        pthread_cond_signal(&cond_pessoa);
    }
    pthread_exit((void *)NULL);
}

void sai_elevador(void *vargp){
  Pessoa *p = (Pessoa*) vargp;
  p->e.capacidade --;
  printf("Chegou aqui\n");
  pthread_exit((void *)NULL);

}
