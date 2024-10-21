#include <stdio.h>

int main(){
  double a, b, r;

  printf("Digite dois numeros a seguir;\n");
  printf("Primeiro: ");
  scanf("%lf", &a);
  printf("Segundo: ");
  scanf("%lf", &b);

  r = a*b;
  
  printf("Multiplicacao: %.0lf\n", r);

  return 0;
}