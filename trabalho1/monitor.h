#ifndef _MONITOR_H_
#define _MONITOR_H_

/*
* monitor.h
* TAD que implementa monitor compartilhado entre threads
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    pthread_mutex_t exclusao_mutua;
    pthread_cond_t tem_vaga;
    pthread_cond_t tem_gente;
}Monitor;

//void inicializa_monitor();
void inicializa_varcond(pthread_cond_t cond);
void destroi_varacond(pthread_cond_t cond);
void inicializa_mutex(pthread_mutex_t mutex);
void destroi_mutex(pthread_mutex_t mutex);
void espera_sinalizacao(pthread_cond_t cond,pthread_mutex_t mutex);
void sinaliza_thread(pthread_cond_t cond);
void tranca_mutex(pthread_mutex_t mutex);
void libera_mutex(pthread_mutex_t mutex);



#endif
