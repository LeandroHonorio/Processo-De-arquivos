#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista_arquivos.h"

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
