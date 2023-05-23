#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <math.h>

int main() {
    char opcao;

    AbrirMenu();
    scanf(" %c", &opcao);

    printf("%c", opcao);
}