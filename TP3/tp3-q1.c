#include <stdio.h>

int main(){
  int n;
  printf("Digite quantos numeros vao ter a sequencia: ");
  scanf("%d", &n);

  int list[n];
  printf("\n");

  printf("Digite a sequencia:\n");

  for(int i = 0; i < n; i++){
    scanf("%d", &list[i]);
  }

  printf("\n");
  printf("Sequencia inversa:\n");

  for(int i = n - 1; i >= 0; i--){
    printf("%d ", list[i]);
  }
  printf("\n");
  
  return 0;
}