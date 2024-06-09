
#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>

#define MAX_PALAVRAS 1000
#define MAX_TAMANHO_PALAVRA 50

void abrir_arquivo();
void carregar_arquivo();
void ler_sem_arquivo();
void lista_arquivos();
void minuscula(char *str);
void processa_palavras(char *linha, char palavras[][MAX_TAMANHO_PALAVRA], int conta[], int *n_palavras);

#endif // FUNCOES_H
