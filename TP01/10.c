#include <stdio.h>

int gramas(int a){
  return a*1000;
}

int main(){
  int a, b, c, quant, r;

  printf("Digite quantos quilos de racao foram comprados: ");
  scanf("%d", &a);
  printf("Digite quantos gramas come o primeiro gato: ");
  scanf("%d", &b);
  printf("Digite quantos gramas come o segundo gato: ");
  scanf("%d", &c);

  quant = (5*b)+(5*c);
  if (gramas(a) > quant){
   r = gramas(a) - quant;
   printf("Resto da racao apos cinco dias: %d gramas\n", r);
  } 
  else{
    r = quant - gramas(a);
    printf("Faltaram %d gramas para completar os 5 dias\n", r);
  }

  return 0;
}