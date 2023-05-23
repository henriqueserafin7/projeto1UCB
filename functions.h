#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#define MAX_USUARIOS 1000
int numUsuarios = 0;
typedef struct tUsuario {
    int id;
    char nomeCompleto[100];
    char email[100];
    char sexo[10];
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
    int id, vacina, validacao, encontrado = 0;;
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
                validacao = 1;
                break;
            }
            else{
                validacao = 0;
            }
        }
    }while (validacao == 1);
    validacao = 1;
    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);
    printf("Digite seu email: ");
    scanf(" %[^\n]", email);
    while(validacao == 1){
        
        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@'){
                encontrado = 1;
                break;
            }
        }
        if (encontrado == 1){
            validacao = 0;
        }
        else{
            printf("Email invalido tente novamente.\n");
        }
    }
    validacao = 1;
    printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
    scanf("%s", sexo);
    sexo[0] = toupper(sexo[0]);
    while(validacao == 1){
        if(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)
            break;
        else{
            printf("Sexo invalido tente novamente: ");
            scanf("%s", sexo);
            sexo[0] = toupper(sexo[0]);
        }
    }
    printf("Digite seu endereco: ");
    scanf(" %[^\n]", endereco);
    printf("Digite sua altura: ");
    scanf("%lf", &altura);
    while(validacao == 1){
        if(altura > 2 || altura < 1){
            printf("Altura invalida, lembre-se a medida esta em metros\n");
            printf("Tente novamente: ");
            scanf("%lf", &altura);
        }
        else{
            break;
        }
    }
    printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
    scanf("%d", &vacina);
    
    while(validacao == 1){
        if(vacina == 1 || vacina == 0)
            break;
        else{
            printf("So sao aceitos 1 e 0 como valor\n");
            printf("Tente novamente: ");
            scanf("%d", &vacina);
        }
    }
    Usuario tempUser;
    tempUser.id = id;
    strcpy(tempUser.nomeCompleto, nome);
    strcpy(tempUser.email, email);
    strcpy(tempUser.sexo, sexo);
    strcpy(tempUser.endereco, endereco);
    tempUser.altura = altura;
    tempUser.vacina = vacina;
    users[numUsuarios] = tempUser;
    numUsuarios++;
    return 0;
}
int EditarUsuario(){
    char email[100];
    int validacao = 1;
    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);