#include <stdio.h>

int main(){
  char a[3];

  printf("Digite um numero de 3 digitos para ser invertido: ");
  scanf("%s", a);

  printf("O numero invertido e: %c%c%c", a[2], a[1], a[0]);

  return 0;
}