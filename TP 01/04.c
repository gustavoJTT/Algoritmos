#include <stdio.h>

float soma(float a, float b, float c, float d){
  float r;

  r = a+b+c+d;

  return r;
}
int main(){
  float r, a, b, c, d;
  
  printf("Digite as notas a seguir:\n");
  printf("Primeiro: ");
  scanf("%f", &a);
  printf("Segundo: ");
  scanf("%f", &b);
  printf("Terceiro: ");
  scanf("%f", &c);
  printf("Quarto: ");
  scanf("%f", &d);

  r = soma(a, b, c, d)/4;

  printf("Media final: %.2f", r);

  return 0;
}