#include <stdio.h>

int main()
{
    int shift, i = 0;
    char texto[100];

    printf("Deslocamento: ");
    scanf("%d", &shift);
    printf("\n");

    printf("digite um texto para ser criptografado: \n");
    scanf(" %[^\n]", texto);

    for (i; texto[i] != '\0'; i++)
    {
        if (texto[i] >= 'a' && texto[i] <= 'z')
        { 
            texto[i] = (texto[i] - 'a' + shift) % 26 + 'a'; 
        }
        else if (texto[i] >= 'A' && texto[i] <= 'Z') 
        {  
            texto[i] = (texto[i] - 'A' + shift) % 26 + 'A';
        }
    }

    printf("\n");
    printf("texto criptografado padrao Cifra de César: \n%s \n", texto);

    return 0;
}