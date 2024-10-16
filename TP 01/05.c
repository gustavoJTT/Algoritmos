#include <stdio.h>
#include <math.h> //na hora de compilar precisa por -lm(para dizer q usou a biblioteca de matemática) dps do nome dop executável //Em casa n precisei do -lm

float diferenca(float a, float b){
  return pow((a - b), 2);
}

int main(){
  float r, a, b, c, d;

  printf("Digite as coordenadas para o calculo da distancia entre elas:\n");
  printf("Primeira: ");
  scanf("%f %f", &a, &b);
  printf("Segunda: ");
  scanf("%f %f", &c, &d);

  r = sqrt(diferenca(c, a) + diferenca(d, b));

  printf("A distancioa entre os dois pontos e: %.2f", r);

  return 0;
}