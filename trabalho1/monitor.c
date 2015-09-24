/*
* pessoas.c
* TAD que implementa funcoes das threads de Pessoa.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


void inicializa_varcond(pthread_cond_t cond){
  pthread_cond_init(&cond, NULL);
}

void destroi_varacond(pthread_cond_t cond){
  pthread_cond_destroy(&cond);
}

void inicializa_mutex(pthread_mutex_t mutex){
  pthread_mutex_init(&mutex, NULL);
}

void destroi_mutex(pthread_mutex_t mutex){
  pthread_mutex_destroy(&mutex);
}

void espera_sinalizacao(pthread_cond_t cond,pthread_mutex_t mutex){
  pthread_cond_wait(&cond, &mutex);
}

void sinaliza_thread(pthread_cond_t cond){
  pthread_cond_signal(&cond);
}

void tranca_mutex(pthread_mutex_t mutex){
  pthread_mutex_lock(&mutex);
}

void libera_mutex(pthread_mutex_t mutex){
  pthread_mutex_unlock(&mutex);
}
