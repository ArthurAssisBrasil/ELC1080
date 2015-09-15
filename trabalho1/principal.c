#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "pessoas.h"


int main(int argc, char const *argv[]) {
    FILE *f;

    f = fopen("teste.txt","r");

    if(f == NULL){
        printf("Nao foi possivel abrir arquivo! \n");
        exit(1);

    }else{
        while(!feof(f)){
            int n_pessoas;
            int i = 0;
            char c;

            if(fscanf(f,"%d",&n_pessoas) < 0)
                break;

            printf("numero de pessoas: %d\n\n", n_pessoas);

            pthread_t pessoa_t[n_pessoas];
            Pessoa p[n_pessoas];

            while(c != '\n'){  //avança até nova linha
                c = fgetc(f);
            }

            //Cria threads para n pessoas
            for(i=0; i<n_pessoas; i++){
                p[i].id = i;
                pthread_create(&(pessoa_t[i]), NULL, pessoa, (void *)&(p[i]));
            }

            // Espera que as threads terminem
            for(i=0; i<n_pessoas; i++){
                pthread_join(pessoa_t[i], NULL);
            }
        }

    }

    pthread_exit((void *)NULL);
    fclose(f);
    return 0;
}
