#include <stdio.h>

float porcentagem(int a){
  float r;

  r = 0.04*a;

  return r;
}

int main(){
  float a, b, comissao, r;

  printf("Digite seu salario: R$");
  scanf("%f", &a);
  printf("Digite o valor das vendas: R$");
  scanf("%f", &b);

  comissao = porcentagem(b);
  r = a+comissao;

  printf("Valor da comissao: R$%.2f\n", comissao);
  printf("Valor o salario final: R$%.2f", r);

  return 0;
}