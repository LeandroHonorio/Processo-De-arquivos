#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ler_sem_arquivo.h"
#include "carregar_arquivo.h"
#include "minuscula.h"
#include "lista_arquivos.h"
#include "abrir_arquivo.h"

int main() {
    int opcao = 0; 

    while (opcao != 5) {
        printf("[ 1. ] Ler um Arquivo\n");
        printf("[ 2. ] Ler sem Arquivo\n");
        printf("[ 3. ] Lista de Arquivos\n");
        printf("[ 4. ] Abrir um Arquivo\n");
        printf("[ 5. ] Sair\n");
        scanf("%d", &opcao);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (opcao) {
            case 1:
                carregar_arquivo();
                break;

            case 2:
                ler_sem_arquivo();
                break;

            case 3:
                lista_arquivos();
                break;

            case 4:
                abrir_arquivo();
                break;

            case 5:
                printf("Programa sendo Fechado...\n");
                sleep(3);
                exit(0);

            default:
                printf("Opcao invalida. \n");
                break;
        }
    }
    return 0;
}