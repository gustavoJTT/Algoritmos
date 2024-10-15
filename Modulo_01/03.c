#include <stdio.h>

int main(int argc, char *argv[]) { //"int argc" representa o número de argumentos q o programa tem, incluindo o nome do próprio programa
    printf("Numero de argumentos: %d\n", argc);
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    return 0;
}
