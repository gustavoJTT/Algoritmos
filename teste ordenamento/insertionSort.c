#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int quantidade, vezes = 4, novo, ultimo;
  clock_t inicio, fim;

  printf("Quantidade de numeros a serem ordenados: ");
  scanf("%d", &quantidade);

  int *lista = (int *)malloc(quantidade * sizeof(int));

  srand(time(NULL));

  while (vezes > 0)
  {
    for (int i = 0; i < quantidade; i++)
    {
      int numero_aleatorio = rand() % (2 * quantidade + 1) - quantidade;
      lista[i] = numero_aleatorio;
    }

    inicio = clock();

    // Insertion sort
    for(int N_i = 1; N_i < quantidade; N_i++) // N_i = novo(número) indice
    {
      novo = lista[N_i];
      ultimo = N_i - 1; //indice do ultimo da lista ordenada

      while(ultimo >= 0 && lista[ultimo] > novo)
      {
        lista[ultimo + 1] = lista[ultimo];
        ultimo--;
      }

      lista[ultimo + 1] = novo;
    }

    fim = clock();
    double tempoFinal = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // printf("Lista ordenada:\n");
    // for (int i = 0; i < quantidade; i++)
    // {
    //   printf("%d ", lista[i]);
    // }
    // printf("\n");

    printf("Tempo de execucao: %lf segundos\n", tempoFinal);
    printf("\n");

    vezes--;
  }

  free(lista);
  return 0;
}