#include <stdio.h>

int main() {
    int n, i, j;

    printf("Digite o numero de elementos da sequencia: ");
    scanf("%d", &n);
    getchar();

    double sequencia[n];
    int contagens[n];

    printf("Digite os elementos da sequencia (separados por virgula):\n");


    for (i = 0; i < n; i++)
    {
        contagens[i] = -1;
    }

    for (i = 0; i < n; i++) 
    {
 
        double num;
        if (i > 0) {

            while (1) 
            {
                char c = getchar();
                if (c == ',' || c == '\n') 
                {
                    break;
                }
            }
        }
        scanf("%lf", &num);
        sequencia[i] = num;
    }

    for (i = 0; i < n; i++) 
    {
        if (contagens[i] == -1) 
        {
            contagens[i] = 1;
            for (j = i + 1; j < n; j++) 
            {
                if (sequencia[i] == sequencia[j]) 
                {
                    contagens[i]++;
                    contagens[j] = 0; 
                }
            }
        }
    }

    printf("\nResultados:\n");
    for (i = 0; i < n; i++) 
    {
        if (contagens[i] > 0) 
        {
            printf("%.1lf ocorre %d vez(es)\n", sequencia[i], contagens[i]);
        }
    }

    return 0;
}
