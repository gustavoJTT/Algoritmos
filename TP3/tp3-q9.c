#include <stdio.h>

int main(){
  int c = 0;
  char list[100];

  printf("Digite a string:\n");
  scanf("%s", list);

  for(int i = 0; list[i] != '\0'; i++){
    switch(list[i]){
      case '1':
        c += 1;
        break;
    }
  }
  printf("A quantidade de 1 e de: ");
  printf("%d\n", c);

  return 0;
}