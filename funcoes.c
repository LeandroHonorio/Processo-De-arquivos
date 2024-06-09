#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_PALAVRAS 1000
#define MAX_TAMANHO_PALAVRA 50

void abrir_arquivo();
void carregar_arquivo();
void ler_sem_arquivo();
void lista_arquivos();
void minuscula(char *str);
void processa_palavras(char *linha, char palavras[][MAX_TAMANHO_PALAVRA], int conta[], int *n_palavras);

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

void carregar_arquivo() {
    char linha[256];
    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    int conta[MAX_PALAVRAS] = {0};
    int n_palavras = 0;
    FILE *input_file, *output_file;
    char nome_arquivo_entrada[256];
    char nome_arquivo_saida[256];

    printf("Digite o nome do arquivo de entrada (ex: frase.txt): ");
    fgets(nome_arquivo_entrada, sizeof(nome_arquivo_entrada), stdin);
    nome_arquivo_entrada[strcspn(nome_arquivo_entrada, "\n")] = '\0';

    input_file = fopen(nome_arquivo_entrada, "r");
    if (input_file == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return;
    }

    printf("Digite o nome do arquivo de saida (sem extensao): ");
    fgets(nome_arquivo_saida, sizeof(nome_arquivo_saida), stdin);
    nome_arquivo_saida[strcspn(nome_arquivo_saida, "\n")] = '\0';

    if (strlen(nome_arquivo_saida) > 4 && strcmp(nome_arquivo_saida + strlen(nome_arquivo_saida) - 4, ".txt") != 0) {
        strcat(nome_arquivo_saida, ".txt");
    } else if (strlen(nome_arquivo_saida) <= 4) {
        strcat(nome_arquivo_saida, ".txt");
    }

    while (fgets(linha, sizeof(linha), input_file) != NULL) {
        linha[strcspn(linha, "\n")] = '\0';
        minuscula(linha);
        processa_palavras(linha, palavras, conta, &n_palavras);
    }

    fclose(input_file);

    output_file = fopen(nome_arquivo_saida, "w");
    if (output_file == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return;
    }

    fprintf(output_file, "Palavras e suas ocorrencias:\n\n");
    for (int i = 0; i < n_palavras; i++) {
        fprintf(output_file, "%s: %d\n", palavras[i], conta[i]);
    }
    printf("_______________________________\n");
    fclose(output_file);

    printf("Dicionario gerado e salvo no arquivo '%s'.\n", nome_arquivo_saida);
}

void ler_sem_arquivo() {
    char frase[256];
    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRA];
    int conta[MAX_PALAVRAS] = {0};
    int n_palavras = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    minuscula(frase);

    processa_palavras(frase, palavras, conta, &n_palavras);

    printf("Palavras e suas ocorrencias:\n");
    for (int i = 0; i < n_palavras; i++) {
        printf("%s: %d\n", palavras[i], conta[i]);
    }
    printf("_______________________________\n");
}

void lista_arquivos() {
    DIR *dr;
    struct dirent *en;

    dr = opendir(".");
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            if (strstr(en->d_name, ".txt") != NULL) {
                printf("%s\n", en->d_name);
            }
        }
        closedir(dr);
    } else {
        printf("Nao foi possivel abrir o diretorio atual.\n");
        exit(EXIT_FAILURE);
    }
}

void minuscula(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

void processa_palavras(char *linha, char palavras[][MAX_TAMANHO_PALAVRA], int conta[], int *n_palavras) {
    // Substitui delimitadores por espaço
    for (int i = 0; linha[i]; i++) {
        if (strchr("-,.!?;:\"'\n\t", linha[i])) {
            linha[i] = ' ';
        }
    }

    char *token = strtok(linha, " ");
    while (token != NULL) {
        int existe = 0;
        for (int i = 0; i < *n_palavras; i++) {
            if (strcmp(token, palavras[i]) == 0) {
                existe = 1;
                conta[i]++;
                break;
            }
        }
        if (!existe) {
            strcpy(palavras[*n_palavras], token);
            conta[*n_palavras]++;
            (*n_palavras)++;
        }
        token = strtok(NULL, " ");
    }
}
