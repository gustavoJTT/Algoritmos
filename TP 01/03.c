#include <stdio.h>

int soma(int a, int b){
  int r;

  r = a+b;

  return r;
}
int mult(int a, int b){
  int r;

  r = a*b;

  return r;
}

int main(){
  int a, b;

  printf("Digite dois numeros a seguir;\n");
  printf("Primeiro: ");
  scanf("%d", &a);
  printf("Segundo: ");
  scanf("%d", &b);
  
  printf("Soma: %d\n", soma(a, b));
  printf("Multiplicacao: %d", mult(a, b));

  return 0;
}