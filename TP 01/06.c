#include <stdio.h>

float media(float a, float b){
  float r;

  r = ((a*6)+(b*4))/10;

  return r;
}

int main(){
  float a, b, r;

  printf("Didite as notas para calcular a media:\n");
  printf("Primeira: ");
  scanf("%f", &a);
  printf("Segunda: ");
  scanf("%f", &b);

  r = media(a, b);
  
  printf("Media final: %.1f", r);

  return 0;
}