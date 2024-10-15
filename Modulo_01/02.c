#include <stdio.h>

int main() {
    int inteiro;
    float pontoFlutuante; //ocupa 4 bytes de memória, e de 6 a 7 dígitos decimais de precisão...MENOS PRECISO, MENOS MEMÓRIA
    double pontoFlutuanteDuplo; //ocupa 8 bytes de memória, e de 15 a 16 dígitos decimais de precisão...MAIS PECISO, MAIS MEMÓRIA
    char caractere; //uma única caractere 
    char string[100]; //uma string, array de caracteres("Lista de caracteres")

    // Leitura dos dados
    printf("Digite um número inteiro: ");
    scanf("%d", &inteiro); // & == "Operador de indereço", é usado para obter o endereço de memória da variável

    printf("Digite um número de ponto flutuante: ");
    scanf("%f", &pontoFlutuante);

    printf("Digite um número de ponto flutuante duplo: ");
    scanf("%lf", &pontoFlutuanteDuplo);

    printf("Digite um caractere: ");
    scanf(" %c", &caractere); // Note o espaço antes de %c para ignorar espaços em branco

    printf("Digite uma string: ");
    scanf("%s", string); //array não precisa de &
    //Quando você declara "char string[100];", string é um array de caracteres. Quando você passa o nome do array para uma função (como scanf), ele é automaticamente convertido para um ponteiro que aponta para o primeiro elemento do array. Portanto, string já se comporta como um ponteiro.
    //as demais funções q transformam array em ponteiro são: Entrada e Saída(scanf(), printf()); Manipulação de strings(strlen(), strcpy(), strcat(), strcmp()...); Manipulação de arrays; Funções matemáticas(qsort())

    // Saída dos dados
    printf("\nVocê digitou o número inteiro: %d\n", inteiro); //sempre q for printar algo, deve ser declarado qual o tipo de dado vai ser printado
    printf("Você digitou o número de ponto flutuante: %f\n", pontoFlutuante);
    printf("Você digitou o número de ponto flutuante duplo: %lf\n", pontoFlutuanteDuplo);
    printf("Você digitou o caractere: %c\n", caractere);
    printf("Você digitou a string: %s\n", string);

    return 0;
}