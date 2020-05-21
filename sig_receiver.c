#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

int i;

void imprimir();

int main(int argc, char *argv[])
{
        i = 0;
        for (i = 0; i < NSIG; i++) {
                signal(i, imprimir);
        }
        while (pause());

        exit(EXIT_SUCCESS);
}
void imprimir(int nsignal){
        printf ("Señal: %s,  identificador: %d\n", strsignal(nsignal), nsignal);
}

