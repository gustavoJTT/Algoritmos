#include <stdio.h>

int main() {
    int n, k;
    
    printf("Digite o número de alunos: ");
    scanf("%d", &n);
    
    printf("Digite o número de provas: ");
    scanf("%d", &k);

    float pesos[k];
    float notas[n][k];
    float media_ponderada_aluno[n];
    float media_aritmetica_provas[k];

    for (int i = 0; i < k; i++) 
    {
        media_aritmetica_provas[i] = 0.0;
    }

    printf("Digite os pesos das %d provas:\n", k);
    for (int i = 0; i < k; i++)
    {
        printf("Peso da prova %d: ", i + 1);
        scanf("%f", &pesos[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Digite as notas do aluno %d:\n", i + 1);
        for (int j = 0; j < k; j++)
        {
            printf("Nota da prova %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            media_aritmetica_provas[j] += notas[i][j];
        }
    }


    for (int i = 0; i < n; i++) 
    {
        float soma_ponderada = 0.0;
        float soma_pesos = 0.0;
        for (int j = 0; j < k; j++) {
            soma_ponderada += notas[i][j] * pesos[j];
            soma_pesos += pesos[j];
        }
        media_ponderada_aluno[i] = soma_ponderada / soma_pesos;
    }


    for (int j = 0; j < k; j++)
    {
        media_aritmetica_provas[j] /= n;
    }

    printf("Média ponderada de cada aluno:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Aluno %d: %.2f\n", i + 1, media_ponderada_aluno[i]);
    }

    printf("Média aritmética da classe em cada prova:\n");
    for (int j = 0; j < k; j++) 
    {
        printf("Prova %d: %.2f\n", j + 1, media_aritmetica_provas[j]);
    }

    return 0;
}
