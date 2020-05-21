//
// Ejercicio 2 -- sem_open
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char* argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Uso: %s nombre valor\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int n = atoi(argv[2]);

    if (n<0){
        fprintf(stderr,"El valor del semaforo debe ser mayor o igual 0\n");
        exit(EXIT_FAILURE);
    }

    sem_t *sem = sem_open(argv[1],O_CREAT,0644 ,n);

    if (sem == SEM_FAILED) {
        perror("sem_open");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}

