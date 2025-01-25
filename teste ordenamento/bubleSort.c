#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int quantidade, vezes = 4;
  clock_t inicio, fim;

  printf("Quantidade de numeros a serem ordenados: ");
  scanf("%d", &quantidade);

  int *lista = (int *)malloc(quantidade * sizeof(int));

  // Inicializa o gerador de números aleatórios
  srand(time(NULL));

  while (vezes > 0)
  {
    // Gera números aleatórios
    for (int i = 0; i < quantidade; i++)
    {
      int numero_aleatorio = rand() % (2 * quantidade + 1) - quantidade;
      lista[i] = numero_aleatorio;
    }

    // Começa a medir o tempo de execução
    inicio = clock();

    // Buble sort
    for (int i = 0; i < quantidade - 1; i++)
    {
      for (int j = 0; j < quantidade - i - 1; j++)
      {
        if (lista[j] > lista[j + 1])
        {
          int temp = lista[j];
          lista[j] = lista[j + 1]; // troca
          lista[j + 1] = temp; // coloca o maior na frente
        }
      }
    }
    
    // Para de medir o tempo de execução
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