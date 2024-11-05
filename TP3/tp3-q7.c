#include <stdio.h>

int main(){
  int c = 0;
  char list[100];

  printf("Digite a string:\n");
  scanf("%s", list);

  for(int i = 0; list[i] != '\0'; i++){
    c += 1;
  }
  printf("O comprimento da lista e: ");
  printf("%d\n", c);

  return 0;
}