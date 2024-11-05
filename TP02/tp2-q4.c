#include <stdio.h>

int main()
{
    int option, convert;
    double entrada, saida;
    const double brl_from_eur = 0.1624, brl_from_usd = 0.1755, eur_from_usd = 1.081;

    printf("Ola, bem vindo ao conversor de moedas\n");
    do
    {
        printf("Moeda de entrada: \n");
        printf("[1] EUR \n");
        printf("[2] USD \n");
        printf("[3] BRL \n");
        printf("[0] SAIR\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Para que moeda quer converter?\n");
            printf("[1] USD \n");
            printf("[2] BRL \n");
            scanf("%d", &convert);
            if (convert == 1)
            {
                printf("EUR: ");
                scanf("%lf", &entrada);
                saida = entrada * eur_from_usd;
                printf("USD: %.2lf\n", saida); 
            }
            else if (convert == 2)
            {
                printf("EUR: ");
                scanf("%lf", &entrada);
                saida = entrada / brl_from_eur; 
                printf("BRL: %.2lf\n", saida);
            }
            break;

        case 2:
            printf("Para que moeda quer converter?\n");
            printf("[1] EUR \n");
            printf("[2] BRL \n");
            scanf("%d", &convert);
            if (convert == 1)
            {
                printf("USD: ");
                scanf("%lf", &entrada);
                saida = entrada / eur_from_usd;
                printf("EUR: %.2lf\n", saida);
            }
            else if (convert == 2)
            {
                printf("USD: ");
                scanf("%lf", &entrada);
                saida = entrada * (1 / brl_from_usd);
                printf("BRL: %.2lf\n", saida);
            }
            break;

        case 3:
            printf("Para que moeda quer converter?\n");
            printf("[1] EUR \n");
            printf("[2] USD \n");
            scanf("%d", &convert);
            if (convert == 1)
            {
                printf("BRL: ");
                scanf("%lf", &entrada);
                saida = entrada * brl_from_eur;
                printf("EUR: %.2lf\n", saida);
            }
            else if (convert == 2)
            {
                printf("BRL: ");
                scanf("%lf", &entrada);
                saida = entrada * (1 / brl_from_usd);
                printf("USD: %.2lf\n", saida);
            }
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    while (option != 0);

    return 0;
}
