#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

const int MAX_USUARIOS = 1000;
int numUsuarios = 0;

typedef struct tUsuario {
    int id;
    char nomeCompleto[100];
    char sexo[10];
    char email[100];
    char endereco[100];
    double altura;
    int vacina;
} Usuario;

Usuario users[MAX_USUARIOS];

void AbrirMenu(){

    printf("1 - Adicionar Usuario\n");
    printf("2 - Editar Usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar por Email\n");
    printf("5 - Imprimir todos os usuarios\n");
    printf("6 - Fazer Backup dos usuarios\n");
    printf("7 - Restaurar os dados\n");
    printf("0 - Fechar programa\n");
    printf("Digite a opcao escolhida: ");
}
int AdicionarUsuario(){
    int id, vacina, existe;
    char nome[100], email[100], sexo[100], endereco[100];
    double altura;

    if (numUsuarios >= MAX_USUARIOS){
        printf("Numero de usuarios alcançou o limite D:\n");
        return -1;
    }

    srand(time(NULL));
    do{
        id = rand() % 100000;

        for(int i = 0; i < numUsuarios; i++)
        {
            if(users[i].id == id){
                printf("Usuario ja existe\n");
                id = 00000;
                existe = 1;
                break;
            }
            else{
                existe = 0;
            }
        }
    }while (existe = 1);

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);

     printf("Digite seu email: ");
    scanf(" %[^\n]", email);

    printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
    scanf("%s", sexo);

    printf("Digite seu endereco: ");
    scanf(" %[^\n]", endereco);

    printf("Digite sua altura: ");
    scanf("%lf", &altura);

    printf("Digite o estado de sua vacinacao (1 = Vacinado/ 2 = Nao vacinado): ");
    scanf("%d", &vacina);
}