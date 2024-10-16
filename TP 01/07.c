#include <stdio.h>

int main(){
  int r, a, unid, dez, cent;

  printf("Digite um numero de 3 digitos para ser invertido: ");
  scanf("%d", &a);

  unid = (a%10)*100;
  dez = ((a/10)%10)*10;
  cent = a/100;
  r = unid+dez+cent;

  printf("O numero invertido e: %d", r);

  return 0;
}