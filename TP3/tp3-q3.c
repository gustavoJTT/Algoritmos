#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x, dado;
  int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;

  printf("Digite quantas vezes o dado foi lancado: ");
  scanf("%d", &x);

  srand(time(NULL));
  
  for(int i = 0; i < x; i++){
    dado = (rand() % 6) + 1;

    switch(dado){
      case 1:
        a += 1;
        break;

      case 2:
        b += 1;
        break;
      
      case 3:
        c += 1;
        break;

      case 4:
        d += 1;
        break;

      case 5:
        e += 1;
        break;
      
      case 6:
        f += 1;
        break;
    }
  }
  
  printf("O numero de ocorrencias de cada numero foi:\n");
  printf("Numero 1 --> %d vez(es)\n", a);
  printf("Numero 2 --> %d vez(es)\n", b);
  printf("Numero 3 --> %d vez(es)\n", c);
  printf("Numero 4 --> %d vez(es)\n", d);
  printf("Numero 5 --> %d vez(es)\n", e);
  printf("Numero 6 --> %d vez(es)\n", f);

  return 0;
}
