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

//pthread_mutex_t p->monitor->exclusao_mutua;
//pthread_cond_t p->monitor->tem_vaga;
//pthread_cond_t p->monitor->tem_gente;


void *pessoa(void *vargp){
    int i = 0;
    Pessoa *p = (Pessoa*) vargp;

    // Cria o mutex
    p->monitor = (Monitor*)memo_aloca(sizeof(Monitor));
    inicializa_mutex(p->monitor->exclusao_mutua);

    // Cria variaveis de condicao
    inicializa_varcond(p->monitor->tem_vaga);
    inicializa_varcond(p->monitor->tem_gente);


    printf("Comecou a thread pessoa %d\n", p->id);
    // Faz um trabalho qualquer
    for(i = 0; i < 1000000; i++);

    acessa_elevador(p);
    sai_elevador(p);

    //quando a thread retorna ao térro encerra a thread
    if(p->andar_atual == 0)
      pthread_exit((void *)NULL);

    printf("Terminou a thread pessoa %d\n", p->id);
    destroi_varacond(p->monitor->tem_vaga);
    destroi_varacond(p->monitor->tem_gente);
    destroi_mutex(p->monitor->exclusao_mutua);

    pthread_exit((void *)NULL);
}

void acessa_elevador(Pessoa *p){
  //Pessoa *p = (Pessoa*) vargp;
  tranca_mutex(p->monitor->exclusao_mutua);

  while (lotacao_elevador == CAPACIDADE) //aguarda liberação de vaga no elevador
    espera_sinalizacao(p->monitor->tem_vaga, p->monitor->exclusao_mutua);

  if(lotacao_elevador <= CAPACIDADE) {
        printf("Thread %d: Entrou no elevador\n", p->id);
        ++(lotacao_elevador);
        printf("Lotacao atual: %d\n", lotacao_elevador);

        sinaliza_thread(p->monitor->tem_gente);

  }else{
    printf("Sinaliza outras threads\n");
    sinaliza_thread(p->monitor->tem_gente);
  }
  libera_mutex(p->monitor->exclusao_mutua);
}


void sai_elevador(Pessoa *p){
  //Pessoa *p = (Pessoa*) vargp;
  tranca_mutex(p->monitor->exclusao_mutua);
  while (lotacao_elevador == 0)
    espera_sinalizacao(p->monitor->tem_gente, p->monitor->exclusao_mutua);

  --(lotacao_elevador);
  printf("Thread %d saiu do Elevador\n", p->id);
  sinaliza_thread(p->monitor->tem_vaga);
  libera_mutex(p->monitor->exclusao_mutua);
}

void solicita_elevador(Pessoa *p){
  printf("%d ", p->id);


}

void solicita_andar(Pessoa *p){
  printf("%d ", p->id);

}
