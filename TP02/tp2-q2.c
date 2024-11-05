#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int numero, chute;

    numero = rand() % 101;
    printf("tente adivinhar o numero :)\n");

    do {
        printf("Eu acho que: ");
        scanf("%d", &chute);

        if (chute > numero) 
        {
            printf("Errou, muito alto!\n");
        }

        else if (chute < numero)
        {
            printf("Errou, muito baixo!\n");
        }
        else
        {
            printf("vc acertou, parabens!!!");
        }
    } while (chute != numero);
    return 0;
    
} 
