#include <stdio.h>

int main(){
    int c = 1, op, vta = 0, vtb = 0, vtc = 0;

    printf("Selecione qual candidato votar;\n");
    printf("1. Candidato A\n");
    printf("2. Candidato B\n");
    printf("3. Candidato C\n");
    printf("0. Encerrar votacao\n");
    scanf("%d", &op);

    while(c==1){
        if(op==1){
            vta += 1;
            printf("\n");
            printf("Voto computado com sucesso\n");
            printf("\n");

        }else if(op==2){
            vtb += 1;
            printf("\n");
            printf("Voto computado com sucesso\n");
            printf("\n");

        }else if(op==3){
            vtc += 1;
            printf("\n");
            printf("Voto computado com sucesso\n");
            printf("\n");

        }else if(op < 0 || op > 3){
            printf("\n");
            printf("Candidato desconhecido\n");
            printf("\n");

        }else if(op==0){
            printf("\n");
            printf("Votacao encerrada, quantidade de votos; \n");
            printf("Candidato A: %d votos", vta);
            printf("Candidato B: %d votos", vtb);
            printf("Candidato C: %d votos", vtc);
            printf("\n");

            if(vta == vtb && vta == vtc && vtb == vtc){
                printf("Houve um impate na quantidade de votos de todos os candidatos\n");
                break;
            }else if(vta > vtb && vta > vtc){
                printf("O candiadato mais votado e o candidato A!!!\n");
                break;

            }else if(vta > vtb && vta == vtc){
                printf("Os candiadatos A e C foram os mais votados!!!\n");
                break;

            }else if(vta == vtb && vta > vtc){
                printf("Os candiadatos A e B foram os mais votados!!!\n");
                break;
            }
            else if(vta < vtb && vtb > vtc){
                printf("O candiadato mais votado e o candidato B!!!\n");
                break;

            }else if(vta < vtb && vtb == vtc){
                printf("Os candiadatos B e C foram os mais votados!!!\n");
                break;

            }else if(vta == vtb && vtb < vtc){
                printf("Os candiadatos A e B foram os mais votados!!!\n");
                break;
            }
            else if(vta < vtc && vtb < vtc){
                printf("O candiadato mais votado e o candidato C!!!\n");
                break;

            }else if(vta == vtc && vtb < vtc){
                printf("Os candiadatos A e C foram os mais votados!!!\n");
                break;

            }else if(vta < vtc && vtb == vtc){
                printf("Os candiadatos B e C foram os mais votados!!!\n");
                break;
            }
        }

        printf("Selecione qual candidato votar;\n");
        printf("1. Candidato A\n");
        printf("2. Candidato B\n");
        printf("3. Candidato C\n");
        printf("0. Encerrar votacao\n");
        scanf("%d", &op);

    }
    return 0;
}
