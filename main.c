#include <stdio.h>
#include "functions.h"
#include <string.h>
#include <math.h>

int main() {
    char opcao;

while (opcao != '0'){
    AbrirMenu();
    scanf(" %c", &opcao);

    switch (opcao)
        {
        case '1':
            AdicionarUsuario();
            break;
        case '2':
            EditarUsuario();
            break;
        default:
            break;
        }
    }
}