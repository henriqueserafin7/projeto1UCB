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

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(users[i].email, email) == 0){

            printf("nome: %s\n", users[i].nomeCompleto);
            printf("sexo: %s\n", users[i].sexo);
            printf("endereco: %s\n", users[i].endereco);
            printf("altura: %.2lf\n", users[i].altura);
            printf("status de vacinacao: %d\n", users[i].vacina);
            printf("Digite seu nome completo: ");
            scanf(" %[^\n]", users[i].nomeCompleto);
            printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
            scanf("%s", users[i].sexo);
            users[i].sexo[0] = toupper(users[i].sexo[0]);
            while(validacao == 1){
                if(strcmp(users[i].sexo, "Masculino") == 0 || strcmp(users[i].sexo, "Feminino") == 0 || strcmp(users[i].sexo, "Indefinido") == 0)
                    break;
                else{
                    printf("Sexo invalido tente novamente: ");
                    scanf("%s", users[i].sexo);
                    users[i].sexo[0] = toupper(users[i].sexo[0]);
                }
            }
            printf("Digite seu endereco: ");
            scanf(" %[^\n]", users[i].endereco);
            printf("Digite sua altura: ");
            scanf("%lf", &users[i].altura);
            while(validacao == 1){
                if(users[i].altura > 2 || users[i].altura < 1){
                    printf("Altura invalida, lembre-se a medida esta em metros\n");
                    printf("Tente novamente: ");
                    scanf("%lf", &users[i].altura);
                }
                else{
                    break;
                }
            }
            printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
            scanf("%d", &users[i].vacina);
    
            while(validacao == 1){
                if(users[i].vacina == 1 || users[i].vacina == 0)
                    break;
                else{
                    printf("So sao aceitos 1 e 0 como valor\n");
                    printf("Tente novamente: ");
                    scanf("%d", &users[i].vacina);
                }
            }
            printf("novo nome: %s\n", users[i].nomeCompleto);
            printf("novo sexo: %s\n", users[i].sexo);
            printf("novo endereco: %s\n", users[i].endereco);
            printf("nova altura: %.2lf\n", users[i].altura);
            printf("novo status de vacinacao: %d\n", users[i].vacina);
            return 0;
        }
    }
    printf("Usuario nao encontrado.\n");
    return 0;
}
int ExcluirUsuario(){
    char email[100];
    int validacao = 1, certeza = 0;

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios; i++){
        if(strcmp(users[i].email, email) == 0){

            printf("nome: %s\n", users[i].nomeCompleto);
            printf("sexo: %s\n", users[i].sexo);
            printf("endereco: %s\n", users[i].endereco);
            printf("altura: %.2lf\n", users[i].altura);
            printf("status de vacinacao: %d\n", users[i].vacina);

            printf("Tem certeza que deseja excluir esse usuario?\n1 - sim 2 - nao\n");
            scanf("%d", &certeza);

            if(certeza == 1){
                users[i].id = 0;
                memset(users[i].email, 0, sizeof(users[i].email));
                memset(users[i].nomeCompleto, 0, sizeof(users[i].nomeCompleto));
                memset(users[i].sexo, 0, sizeof(users[i].sexo));
                memset(users[i].endereco, 0, sizeof(users[i].endereco));
                users[i].altura = 0;
                users[i].vacina = 0;
                numUsuarios--;

                for (int j = i + 1; j < numUsuarios; j++){
                    users[j - 1] = users [j];
                }
                return 0;
            }
            else if(certeza == 2){
                return 0;
            }
        }
    }
    printf("Usuario nao encontrado\n");
    return -1;
}