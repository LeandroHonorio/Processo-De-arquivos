#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ler_sem_arquivo.h"
#include "minuscula.h"

#define MAX_PALAVRAS 100
#define MAX_TAMANHO_PALAVRA 50

void ler_sem_arquivo() {
    char frase[256];
    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    int conta[MAX_PALAVRAS] = {0};
    int n_palavras = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    minuscula(frase);

    char *delimitadores = " ,.!?;:\"'\n\t"; 
    char *token = strtok(frase, delimitadores);

    while (token != NULL) {
        int existe = 0;
        for (int i = 0; i < n_palavras; i++) {
            if (strcmp(token, palavras[i]) == 0) {
                existe = 1;
                conta[i]++;
                break;
            }
        }
        if (!existe) {
            strcpy(palavras[n_palavras], token);
            conta[n_palavras]++;
            n_palavras++;
        }
        token = strtok(NULL, delimitadores);
    }

    printf("Palavras e suas ocorrencias:\n");
    for (int i = 0; i < n_palavras; i++) {
        printf("%s: %d\n", palavras[i], conta[i]);
    }
    printf("_______________________________\n");
}
