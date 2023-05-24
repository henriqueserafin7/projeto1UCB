#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 1000
int quantidadeUsuarios = 0;

typedef struct tUsuario {
    int identificador;
    char nomeCompleto[100];
    char email[100];
    char genero[10];
    char endereco[100];
    double altura;
    int statusVacinacao;
} Usuario;

Usuario usuarios[MAX_USUARIOS];
Usuario usuariosbackup[MAX_USUARIOS];

void AbrirMenu(){
    printf("1 - Adicionar Usuario\n");
    printf("2 - Editar Usuario\n");
    printf("3 - Excluir Usuario\n");
    printf("4 - Buscar por Email\n");
    printf("5 - Imprimir todos os Usuarios\n");
    printf("6 - Fazer Backup dos Usuarios\n");
    printf("7 - Restaurar os dados\n");
    printf("0 - Fechar programa\n");
    printf("Digite a opcao escolhida: ");
}

int AdicionarUsuario(){
    int identificador, statusVacinacao, validacao, encontrado = 0;;
    char nome[100], email[100], genero[100], endereco[100];
    double altura;

    if (quantidadeUsuarios >= MAX_USUARIOS){
        printf("Numero de usuarios alcançou o limite!\n");
        return -1;
    }
    
    srand(time(NULL));

    do{
        identificador = rand() % 100000;

        for(int i = 0; i < quantidadeUsuarios; i++){
            if(usuarios[i].identificador == identificador){
                printf("Usuario ja existe\n");
                identificador = 00000;
                validacao = 1;
                break;
            }
            else{
                validacao = 0;
            }
        }
    } while (validacao == 1);

    validacao = 1;
    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);
    printf("Digite seu email: ");
    scanf(" %[^\n]", email);

    while(validacao == 1){
        for (int i = 0; i < strlen(email); i++){
            if (email[i] == '@'){
                encontrado = 1;
                validacao = 0;
                break;
            }
        }

        if (encontrado == 1){
            validacao = 0;
        }
        else{
            printf("Email invalido tente novamente: ");
            scanf(" %[^\n]", email);
        }
    }

    validacao = 1;
    printf("Digite seu genero (Masculino ou Feminino): ");
    scanf("%s", genero);
    genero[0] = toupper(genero[0]);

    while(validacao == 1){
        if(strcmp(genero, "Masculino") == 0 || strcmp(genero, "Feminino") == 0 || strcmp(genero, "Indefinido") == 0)
            break;
        else{
            printf("e invalido, tente novamente: ");
            scanf("%s", genero);
            genero[0] = toupper(genero[0]);
        }
    }

    printf("Digite seu endereco: ");
    scanf(" %[^\n]", endereco);
    printf("Digite sua altura: ");
    scanf("%lf", &altura);

    while(validacao == 1){
        if(altura > 2 || altura < 1){
            printf("Altura invalida, lembre-se que a medida esta em metros.\n");
            printf("Tente novamente: ");
            scanf("%lf", &altura);
        }
        else{
            break;
        }
    }

    printf("Digite o estado de sua vacinacao (1 = Vacinado / 0 = nao vacinado): ");
    scanf("%d", &statusVacinacao);

    while(validacao == 1){
        if(statusVacinacao == 1 || statusVacinacao == 0)
            break;
        else{
            printf("So sao aceitos 1 e 0 como valor.\n");
            printf("Tente novamente: ");
            scanf("%d", &statusVacinacao);
        }
    }

    Usuario tempUsuario;
    tempUsuario.identificador = identificador;
    strcpy(tempUsuario.nomeCompleto, nome);
    strcpy(tempUsuario.email, email);
    strcpy(tempUsuario.genero, genero);
    strcpy(tempUsuario.endereco, endereco);
    tempUsuario.altura = altura;
    tempUsuario.statusVacinacao = statusVacinacao;
    usuarios[quantidadeUsuarios] = tempUsuario;
    quantidadeUsuarios++;
    return 0;
}

int EditarUsuario(){
    char email[100];
    int validacao = 1;

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < quantidadeUsuarios + 1; i++){
        if(strcmp(usuarios[i].email, email) == 0){
            printf("Nome: %s\n", usuarios[i].nomeCompleto);
            printf("e: %s\n", usuarios[i].genero);
            printf("c: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Status deca: %d\n", usuarios[i].statusVacinacao);

            printf("Digite seu nome completo: ");
            scanf(" %[^\n]", usuarios[i].nomeCompleto);
            printf("Digite seu e (Masculino/Feminino/Indefinido): ");
            scanf("%s", usuarios[i].genero);
            usuarios[i].genero[0] = toupper(usuarios[i].genero[0]);

            while(validacao == 1){
                if(strcmp(usuarios[i].genero, "Masculino") == 0 || strcmp(usuarios[i].genero, "Feminino") == 0 || strcmp(usuarios[i].genero, "Indefinido") == 0)
                    break;
                else{
                    printf("e invalido, tente novamente: ");
                    scanf("%s", usuarios[i].genero);
                    usuarios[i].genero[0] = toupper(usuarios[i].genero[0]);
                }
            }

            printf("Digite seu c: ");
            scanf(" %[^\n]", usuarios[i].endereco);
            printf("Digite sua altura: ");
            scanf("%lf", &usuarios[i].altura);

            while(validacao == 1){
                if(usuarios[i].altura > 2 || usuarios[i].altura < 1){
                    printf("Altura invalida, lembre-se que a medida esta em metros.\n");
                    printf("Tente novamente: ");
                    scanf("%lf", &usuarios[i].altura);
                }
                else{
                    break;
                }
            }

            printf("Digite o estado de suaca (1 = Vacinado / 0 = nao vacinado): ");
            scanf("%d", &usuarios[i].statusVacinacao);

            while(validacao == 1){
                if(usuarios[i].statusVacinacao == 1 || usuarios[i].statusVacinacao == 0)
                    break;
                else{
                    printf("Só são aceitos 1 e 0 como valor.\n");
                    printf("Tente novamente: ");
                    scanf("%d", &usuarios[i].statusVacinacao);
                }
            }

            printf("Novo nome: %s\n", usuarios[i].nomeCompleto);
            printf("Novo e: %s\n", usuarios[i].genero);
            printf("Novo c: %s\n", usuarios[i].endereco);
            printf("Nova altura: %.2lf\n", usuarios[i].altura);
            printf("Novo status deca: %d\n", usuarios[i].statusVacinacao);
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

    for(int i = 0; i < quantidadeUsuarios; i++){
        if(strcmp(usuarios[i].email, email) == 0){
            printf("Nome: %s\n", usuarios[i].nomeCompleto);
            printf("e: %s\n", usuarios[i].genero);
            printf("c: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Status deca: %d\n", usuarios[i].statusVacinacao);
            
            printf("Tem certeza que deseja excluir esse usuario?\n1 - sim 2 - nao\n");
            scanf("%d", &certeza);

            if(certeza == 1){
                usuarios[i].identificador = 0;
                memset(usuarios[i].email, 0, sizeof(usuarios[i].email));
                memset(usuarios[i].nomeCompleto, 0, sizeof(usuarios[i].nomeCompleto));
                memset(usuarios[i].genero, 0, sizeof(usuarios[i].genero));
                memset(usuarios[i].endereco, 0, sizeof(usuarios[i].endereco));
                usuarios[i].altura = 0;
                usuarios[i].statusVacinacao = 0;
                quantidadeUsuarios--;

                for (int j = i + 1; j < quantidadeUsuarios; j++){
                    usuarios[j - 1] = usuarios[j];
                }
                return 0;
            }
            else if(certeza == 2){
                return 0;
            }
        }
    }

    printf("Usuario nao encontrado.\n");
    return -1;
}

int BuscarPorEmail(){
    char email[100];

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < quantidadeUsuarios; i++){
        if(strcmp(usuarios[i].email, email) == 0){
            printf("Nome: %s\n", usuarios[i].nomeCompleto);
            printf("Email: %s\n", usuarios[i].email);
            printf("e: %s\n", usuarios[i].genero);
            printf("c: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Status deca: %d\n", usuarios[i].statusVacinacao);
            return 0;
        }
    }

    printf("Usuario nao encontrado.\n");
    return -1;
}

int ImprimirUsuarios(){
    for(int i = 0; i < quantidadeUsuarios; i++){
        printf("\n\n----------USUARIO %d----------\n", i+1);
        printf("id:  %d\n", usuarios[i].identificador);
        printf("nome: %s\n", usuarios[i].nomeCompleto);
        printf("email: %s\n", usuarios[i].email);
        printf("genero: %s\n", usuarios[i].genero);
        printf("endereco: %s\n", usuarios[i].endereco);
        printf("altura: %.2lf\n", usuarios[i].altura);
        printf("status de vacinacao: %d\n", usuarios[i].statusVacinacao);
    }
}

int BackUp(){
    int certeza;

    printf("tem certeza que deseja fazer backup?\n1 - sim 2 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < quantidadeUsuarios; i++){
           usuariosbackup[i].identificador = usuarios[i].identificador;
            strcpy(usuariosbackup[i].nomeCompleto, usuarios[i].nomeCompleto);
            strcpy(usuariosbackup[i].email,usuarios[i].email);
            strcpy(usuariosbackup[i].genero,usuarios[i].genero);
            strcpy(usuariosbackup[i].endereco,usuarios[i].endereco);
           usuariosbackup[i].altura =usuarios[i].altura;
           usuariosbackup[i].statusVacinacao =usuarios[i].statusVacinacao;

            printf("BackUp concluido com sucesso\n");

            return 0;
        }
    }
    else if(certeza == 2){
        return 0;
    }
    else {
        printf("invalido\n");
        return -1;
    }
}

int Restauracao(){
    int certeza;

    printf("quer mesmo fazer um backup?\n1 - sim 2 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < usuarios; i++){
            usuarios[i].identificador = usuariosbackup[i].identificador;
            strcpy(usuarios[i].nomeCompleto, usuariosbackup[i].nomeCompleto);
            strcpy(usuarios[i].email, usuariosbackup[i].email);
            strcpy(usuarios[i].genero, usuariosbackup[i].genero);
            strcpy(usuarios[i].endereco, usuariosbackup[i].endereco);
            usuarios[i].altura = usuariosbackup[i].altura;
            usuarios[i].statusVacinacao = usuariosbackup[i].statusVacinacao;
        }

        printf("Backup realizado com sucesso\n");

        return 0;
    }
    else if (certeza == 2){
        return 0;
    }
    else {
        printf("Invalido\n");
        return -1;
    }
    }