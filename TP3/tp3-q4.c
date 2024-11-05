#include <stdio.h>
#include <string.h>

int contar_ocorrencias(const char frase[], const char palavra[]) {
    int contador = 0;
    int tamanho_palavra = strlen(palavra);
    int i = 0;

    while (frase[i] != '\0')
    {
        if (strncmp(&frase[i], palavra, tamanho_palavra) == 0)
        {
            contador++;
            i += tamanho_palavra;
        }
        else {i++;}
    }

    return contador;
}

int main()
{
    char frase[250];
    char palavra[50];

    printf("Digite a frase: ");
    scanf("%[^\n]", frase);

    printf("Digite a palavra: ");
    scanf("%s", palavra);

    int contador = contar_ocorrencias(frase, palavra);

    printf("Na frase: '%s'\nA palavra: '%s' ocorre %d vezes.\n", frase, palavra, contador); 

    return 0;
}
