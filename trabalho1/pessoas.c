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
#include "memo.h"

int lotacao_elevador;

pthread_mutex_t exclusao_mutua;
pthread_cond_t tem_vaga;
pthread_cond_t tem_gente;


void *pessoa(void *vargp){
    int i = 0;
    Pessoa *p = (Pessoa*) vargp;

    // Cria o mutex
    pthread_mutex_init(&exclusao_mutua, NULL);

    // Cria variaveis de condicao
    pthread_cond_init(&tem_vaga, NULL);
    pthread_cond_init(&tem_gente, NULL);


    printf("Comecou a thread pessoa %d\n", p->id);
    // Faz um trabalho qualquer
    for(i = 0; i < 1000000; i++);
    acessa_elevador(vargp);
    sai_elevador(vargp);

    //quando a thread retorna ao terro encerra a thread
    if(p->andar_atual == 0)
      pthread_exit((void *)NULL);

    printf("Terminou a thread pessoa %d\n", p->id);
    pthread_cond_destroy(&tem_vaga);
    pthread_cond_destroy(&tem_gente);
    pthread_exit((void *)NULL);
}
//32237370
void acessa_elevador(void* vargp){
  Pessoa *p = (Pessoa*) vargp;
  pthread_mutex_lock(&exclusao_mutua);

  while (lotacao_elevador == CAPACIDADE)
    pthread_cond_wait(&tem_vaga, &exclusao_mutua);

  if(lotacao_elevador <= CAPACIDADE) {
        printf("\nThread %d: Entrou no elevador\n", p->id);
        ++(lotacao_elevador);
        printf("\nLotacao atual: %d\n", lotacao_elevador);

        pthread_cond_signal(&tem_gente);

  }else{
    printf("Sinaliza outras threads\n");
    pthread_cond_signal(&tem_gente);
  }
  pthread_mutex_unlock(&exclusao_mutua);
}


void sai_elevador(void *vargp){
  Pessoa *p = (Pessoa*) vargp;
  pthread_mutex_lock(&exclusao_mutua);
  while (lotacao_elevador == 0)
    pthread_cond_wait(&tem_gente, &exclusao_mutua);

  --(lotacao_elevador);
  printf("Thread %d saiu do Elevador\n", p->id);
  pthread_cond_signal(&tem_vaga);
  pthread_mutex_unlock(&exclusao_mutua);
}
