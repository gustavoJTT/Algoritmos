#include <stdio.h>

struct Node
{
  int valor;
  struct Node *proximo;
};

struct Node *inicio = NULL;

void insere(int valor)
{
  struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
  novo->valor = valor;
  novo->proximo = inicio;
  inicio = novo;
}

void remove()
{
  struct Node *temp = inicio;
  inicio = inicio->proximo;
  free(temp);
}

int busca(int valor)
{
  struct Node *temp = inicio;
  while (temp != NULL)
  {
    if (temp->valor == valor)
    {
      return 1;
    }
    temp = temp->proximo;
  }
  return 0;
}

void imprime()
{
  struct Node *temp = inicio;
  while (temp != NULL)
  {
    printf("%d ", temp->valor);
    temp = temp->proximo;
  }
  printf("\n");
}

int tamanho()
{
  int tam = 0;
  struct Node *temp = inicio;
  while (temp != NULL)
  {
    tam++;
    temp = temp->proximo;
  }
  return tam;
}

int vazia()
{
  return inicio == NULL;
}

int main()
{
  insere(10);
  insere(20);
  insere(30);
  insere(40);
  insere(50);

  imprime();
  printf("Tamanho: %d\n", tamanho());

  remove();
  remove();

  imprime();
  printf("Tamanho: %d\n", tamanho());

  printf("Busca: %d\n", busca(20));
  printf("Busca: %d\n", busca(30));

  return 0;
}