#include <stdio.h>
#include <stdlib.h>
#include "abrir_arquivo.h"

void abrir_arquivo() {
    FILE *arquivo;
    char ch, nome_arquivo[100];

    printf("Digite o Nome do Arquivo (ex: ocorrencia.txt) ");
    scanf("%s", nome_arquivo);

    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Error ao abrir o arquivo\n");
        exit(6);
    }

    while ((ch = fgetc(arquivo)) != EOF) {
        printf("%c", ch);
    }
    printf("_______________________________\n");
    fclose(arquivo);

}