#include <stdio.h>

#define quest 10

int main() {
    char gabarito[quest];
    int num_alunos;
    char respostas[100][quest]; 
    int acertos[100]; 

    printf("Digite o gabarito (10 letras A, B, C, D ou E): ");
    for (int i = 0; i < quest; i++) 
    {
        scanf(" %c", &gabarito[i]);
    }

    printf("Digite o numero de alunos: ");
    scanf("%d", &num_alunos);

    for (int i = 0; i < num_alunos; i++)
    {
        printf("Digite as respostas do aluno %d (10 letras A, B, C, D ou E): ", i + 1);
        for (int j = 0; j < quest; j++)
        {
            scanf(" %c", &respostas[i][j]);
        }
    }

    for (int i = 0; i < num_alunos; i++)
    {
        acertos[i] = 0; 
        for (int j = 0; j < quest; j++)
        {
            if (respostas[i][j] == gabarito[j])
            {
                acertos[i]++; 
            }
        }
    }


    printf("\nResultado:\n");
    for (int i = 0; i < num_alunos; i++)
    {
        printf("Aluno %d: %d acertos\n", i + 1, acertos[i]);
    }

    return 0;
}
