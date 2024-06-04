#include "minuscula.h"
#include <ctype.h>

void minuscula(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}