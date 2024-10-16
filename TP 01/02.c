#include <stdio.h>

int main(){
  char nome[100];

  printf("Qual seu nome?\n");
  scanf("%s", nome);
  printf("Ola %s, bem-vindo(a) ao mundo da linguagem de programacao C!", nome);

  return 0;
}