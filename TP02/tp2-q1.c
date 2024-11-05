#include <stdio.h>

int main(){
    int op, c=1;
    double saldo = 100.00, saque, deposito;

    printf("Selecione qual operaçao deseja realizar;\n");
    printf("1. Saque\n");
    printf("2. Deposito\n");
    printf("3. Verificar saldo\n");
    printf("0. Para sair\n");
    scanf("%d", &op);

    while(c==1){
        if(op==1){
            printf("\n");
            printf("Saque selecionado\n");
            printf("Seu saldo e: R$%.2lf\n", saldo);
            printf("Digite quanto deseja sacar: R$");
            scanf("%lf", &saque);
            printf("\n");

            if(saldo > saque && saque > 0){
                saldo -= saque;
                printf("\n");
                printf("Saque realizado com sucesso!!!\n");
                printf("Deseja realizar outra operacao\n");
                printf("\n");
            }else if(saque > saldo){
                printf("\n");
                printf("Saldo insuficiente\n");
                printf("Deseja realizar outra operacao\n");
                printf("\n");
            }else if(saque < 0){
                printf("\n");
                printf("valor invalido");
                printf("Deseja realizar outra operacao\n");
                printf("\n");
            }

        }else if(op==2){
            printf("Deposito selecionado\n");
            printf("Seu saldo e de: R$%.2lf\n", saldo);
            printf("Digite quanto deseja depositar: R$");
            scanf("%lf", &deposito);

            if(deposito > 0){
                saldo += deposito;
                printf("\n");
                printf("Deposito realizado com sucesso!!!\n");
                printf("Deseja realizar outra operacao\n");
                printf("\n");

            }else{
                printf("\n");
                printf("valor invalido\n");
                printf("Deseja realizar outra operacao\n");
                printf("\n");
            }

        }else if(op==3){
            printf("\n");
            printf("Seu saldo atual e de: R$%.2lf\n", saldo);
            printf("Deseja realizar outra operacao\n");
            printf("\n");

        }else if(op==0){
            printf("\n");
            printf("Saindo do sistema\n");
            break;

        }else if(op != 1 || op != 2 ||op != 3){
            printf("\n");
            printf("Operacao invalida\n");
            printf("Deseja realizar outra operacao\n");
            printf("\n");
        }

        printf("Selecione qual operaçao deseja realizar;\n");
        printf("1. Saque\n");
        printf("2. Deposito\n");
        printf("3. Verificar saldo\n");
        printf("0. Para sair\n");
        scanf("%d", &op);
    }
    return 0;
}