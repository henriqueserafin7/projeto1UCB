#include <stdio.h>
#include "functions.h"
#include <string.h>

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
         case '3':
            ExcluirUsuario();
            break;
        case '4':
            BuscarPorEmail();
            break;
        case '5':
            ImprimirUsuarios();
            break;
        default:
            break;
        }
    }
}