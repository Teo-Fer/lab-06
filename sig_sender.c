#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
     if (argc < 3){
        fprintf(stderr,"No hay suficientes argumentos!\n");
        exit(EXIT_FAILURE);
    }

    int pid = atoi(argv[1]);
    int senal = atoi(argv[2]);

    if (pid<=0){
        fprintf(stderr,"El pid no es valido \n");
        exit(EXIT_FAILURE);
    }

    if (senal<=0){
        fprintf(stderr,"Señal no valida \n");
        exit(EXIT_FAILURE);
    }
    kill(pid, senal);
    exit(EXIT_SUCCESS);

}
