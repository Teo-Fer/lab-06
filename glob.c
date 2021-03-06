//
// Ejercicio 1
//
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Variable global que incrementan los hilos.
static int glob = 0;

static void *hilo(void *arg)
{
    int loops = *((int *) arg);
    int loc, j;

    // incrementa glob
    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int loops, s;
 
    // Controla numero de argumentos.
    if (argc != 2) {
        fprintf(stderr, "Uso: %s ciclos\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    loops = atoi(argv[1]);

    // Verifica argumentos.
    if (loops < 1) {
        fprintf(stderr, "Error: ciclos debe ser mayor a cero.\n");
        exit(EXIT_FAILURE);
    }

    // Crea hilo t1.
    s = pthread_create(&t1, NULL, hilo, &loops);
    if (s != 0) {
        perror("pthread_create");
    }

    // Crea hilo t2.
    s = pthread_create(&t2, NULL, hilo, &loops);
    if (s != 0) {
        perror("pthread_create");
    }

    // Espera por el hilo t1.
    s = pthread_join(t1, NULL);
    if (s != 0) {
        perror("pthread_join");
    }

    // Espera por el hilo t2.
    s = pthread_join(t2, NULL);
    if (s != 0) {
        perror("pthread_join");
    }

    printf("glob = %d\n", glob);

    exit(EXIT_SUCCESS);
}
