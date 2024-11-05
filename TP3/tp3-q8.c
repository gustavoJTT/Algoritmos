#include <stdio.h>

int main() {
    char str1[100], str2[100], StrOut[200];
    int i, j;

    printf("Digite a primeira string: \n");
    scanf("%s", str1);
    printf("\n");

    printf("Digite a segunda string: \n");
    scanf("%s", str2);
    printf("\n");

   
    for (i = 0; str1[i] != '\0'; i++) {
        StrOut[i] = str1[i];
    }


    for (j = 0; str2[j] != '\0'; j++) {
        StrOut[i + j] = str2[j];
    }

    printf("String concatenada: %s \n", StrOut);

    return 0;
}
