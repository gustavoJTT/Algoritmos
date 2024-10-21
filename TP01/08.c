#include <stdio.h>

float porcentagem(int a, int b){
  float r;

  r = (b/100.0)*a;

  return r;
}

int main(){
  int a, b;
  float r;

  printf("Digite o valor de seu salario: ");
  scanf("%d", &a);
  printf("Digite a porcentagem do aumento: ");
  scanf("%d", &b);

  r = a+porcentagem(a, b);

  printf("Seu salario com o aumento fica por: R$%.2f\n", r);

  return 0;
}