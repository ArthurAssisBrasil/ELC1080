#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "memo.h"
#include "pessoas.h"
#include "elevador.h"


int main(int argc, char const *argv[]) {
    FILE *f;

    /*arrumar nome do arquivo */
    f = fopen(argv[1],"r");

    if(f == NULL){
        printf("Nao foi possivel abrir arquivo! \n");
        exit(1);

    }else{
        while(!feof(f)){
            int n_pessoas, n_visitas;
            int i = 0;
            int k = 0;
            char c;

            if(fscanf(f,"%d",&n_pessoas) < 0)
                break;

            printf("numero de pessoas: %d\n\n", n_pessoas);

            pthread_t elevador_t;
            pthread_t pessoa_t[n_pessoas];
            Pessoa p[n_pessoas];

            while(c != '\n')  //avanca ate nova linha
                c = fgetc(f);

            for(i=0; i<n_pessoas; i++){
                p[i].id = i+1;  //identificação de pessoa
                p[i].andar_atual = 0; //inicializa todas as pessoas no terreo

                fscanf(f,"%d", &n_visitas);
                p[i].andares = (int*)memo_aloca(n_visitas * sizeof(int));
                p[i].tempo_visita = (unsigned long int*)memo_aloca(n_visitas * sizeof(unsigned long int));

                /* para cada pessoa preenche os vetores 'andares' e 'tempo_visita'
                   de acordo com o numero de visitas que cada um realiza */
                for(k=0; k<n_visitas; k++){
                  while(c != ' ')  //avanca ate proxima informacao
                      c = fgetc(f);

                  fscanf(f,"%d", &p[i].andares[k]);
                  while(c != ' ')  ///avanca ate proxima informacao
                      c = fgetc(f);

                  fscanf(f,"%lu", &p[i].tempo_visita[k]);
                }

                /*teste para verificar leitura do arquivo

                  printf("\npessoa %d realiza %d visitas -", i+1, n_visitas);
                  for(k=0; k<n_visitas; k++){
                    printf("%d %lu ",p[i].andares[k], p[i].tempo_visita[k]);
                  }
                  printf("\n");
                */
            }



            //Cria threads para n pessoas
            for(i=0; i<n_pessoas; i++){
                pthread_create(&(pessoa_t[i]), NULL, pessoa, (void *)&(p[i]));
            }
            pthread_create(&elevador_t,NULL,elevador,NULL);

            // Espera que as threads terminem
            for(i=0; i<n_pessoas; i++){
                pthread_join(pessoa_t[i], NULL);
            }
            pthread_join(elevador_t,NULL);
        }

    }

    pthread_exit((void *)NULL);
    fclose(f);
    return 0;
}
