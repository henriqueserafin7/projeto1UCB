#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 1000

int numUsuarios = 0;
//dados do usuario
int universalID[MAX_USUARIOS];
char universalNome[MAX_USUARIOS][100];
char universalEmail[MAX_USUARIOS][100];
char universalSexo[MAX_USUARIOS][10];
char universalEndereco[MAX_USUARIOS][100];
double universalAltura[MAX_USUARIOS];
int universalVacina[MAX_USUARIOS];
//backup
int backupID[MAX_USUARIOS];
char backupNome[MAX_USUARIOS][100];
char backupEmail[MAX_USUARIOS][100];
char backupSexo[MAX_USUARIOS][10];
char backupEndereco[MAX_USUARIOS][100];
double backupAltura[MAX_USUARIOS];
int backupVacina[MAX_USUARIOS];
//funcoes
void AbrirMenu();
int AdicionarUsuario();
int EditarUsuario();
int ExcluirUsuario();
int BuscarPorEmail();
int ImprimirUsuarios();
int BackUp();
int RestaurarDados();
int gerarID();


int main() {
    char opcao = ' ';

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
        case '3':
            ExcluirUsuario();
        case '4':
            BuscarPorEmail();
        case '5':
            ImprimirUsuarios();
        case '6':
            BackUp();
        case '7':
            RestaurarDados();
        case '0':
            printf("--------Fechando programa--------\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
}


void AbrirMenu(){

    printf("1 - Adicionar um novo usuario\n");
    printf("2 - Editar um Usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar por usuario por Email\n");
    printf("5 - Imprimir todos os usuarios cadastrados\n");
    printf("6 - Fazer Backup dos usuarios\n");
    printf("7 - Restaurar os dados\n");
    printf("0 - Fechar programa\n");
    printf("Digite a opcao escolhida: ");
}
int gerarID(){ 
    int id;
    int validacao;
    srand(time(NULL));
    do{
        id = rand() % 100000;

        for(int i = 0; i < numUsuarios; i++)
        {
            if(universalID[i] == id){
                printf("Usuario cadastrado ja existe\n");
                id = 00000;
                validacao = 1;
                break;
            }
            else{
                validacao = 0;
            }
        }
    }while (validacao == 1);
    return id;
}
int AdicionarUsuario(){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], email[100], sexo[10], endereco[100];
    double altura;

    if (numUsuarios >= MAX_USUARIOS){
        printf("Numero de usuarios alcançou o limite D:\n");
        return -1;
    }
    

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);

    printf("Digite seu email: ");
    scanf(" %[^\n]", email);

    do{
        validacao = 1;
        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@'){
                validacao = 0;
                break;
            }
        }

        if(validacao == 1){
            printf("Email invalido, tente novamente: ");
            scanf(" %[^\n]", email);
        }
    }
    while(validacao == 1);

    printf("Digite seu sexo (Masculino/Feminino/Indefinido): ");
    scanf(" %[^\n]", sexo);
    sexo[0] = toupper(sexo[0]);

    while(!(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)){
            printf("Sexo invalido, tente novamente: ");
            scanf(" %[^\n]", sexo);
            sexo[0] = toupper(sexo[0]);
    }

    printf("Digite seu endereco atual: ");
    scanf(" %[^\n]", endereco);

    printf("Digite sua altura: ");
    scanf("%lf", &altura);
    while(altura > 2 || altura < 1){
            printf("Altura invalida, lembre-se a unica mediada suportada e em metros\n");
            printf("Tente novamente: ");
            scanf("%lf", &altura);
    }

    printf("Digite o seu estado atual de vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
    scanf("%d", &vacina);
    
    while(!(vacina == 1 || vacina == 0)){
            printf("So sao aceitos 1 e 0 como valor de resposta\n");
            printf("Tente novamente: ");
            scanf("%d", &vacina);
    }

    universalID[numUsuarios] = gerarID;
    strcpy(universalNome[numUsuarios], nome);
    strcpy(universalEmail[numUsuarios], email);
    strcpy(universalSexo[numUsuarios], sexo);
    strcpy(universalEndereco[numUsuarios], endereco);
    universalAltura[numUsuarios] = altura;
    universalVacina[numUsuarios] = vacina;
    numUsuarios++;

    return 0;
}


int EditarUsuario(){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], email[100], sexo[10], endereco[100];
    double altura;

    printf("Digite o email do usuario cadastrado: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(universalEmail[i], email) == 0){

            printf("id: %d\n", universalID[i]);
            printf("nome: %s\n", universalNome[i]);
            printf("sexo: %s\n", universalSexo[i]);
            printf("endereco: %s\n", universalEndereco[i]);
            printf("altura: %.2lf\n", universalAltura[i]);
            printf("status de vacinacao: %d\n", universalVacina[i]);

            printf("Digite seu nome completo: ");
            scanf(" %[^\n]", nome);

            printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
            scanf(" %[^\n]", sexo);
            sexo[0] = toupper(sexo[0]);

            while(!(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)){
                printf("Sexo invalido tente novamente: ");
                scanf(" %[^\n]", sexo);
                sexo[0] = toupper(sexo[0]);
            }

            printf("Digite seu endereco: ");
            scanf(" %[^\n]", endereco);

            printf("Digite sua altura: ");
            scanf("%lf", &altura);

            while(altura > 2 || altura < 1){
                printf("Altura invalida, lembre-se a medida esta em metros\n");
                printf("Tente novamente: ");
                scanf("%lf", &altura);
            }

            printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
            scanf("%d", &vacina);
    
            while(!(vacina == 1 || vacina == 0)){
                printf("So sao aceitos 1 e 0 como valor\n");
                printf("Tente novamente: ");
                scanf("%d", &vacina);
            }

            strcpy(universalNome[i], nome);
            strcpy(universalEmail[i], email);
            strcpy(universalSexo[i], sexo);
            strcpy(universalEndereco[i], endereco);
            universalAltura[i] = altura;
            universalVacina[i] = vacina;

            printf("novo nome: %s\n", universalNome[i]);
            printf("novo sexo: %s\n", universalSexo[i]);
            printf("novo endereco: %s\n", universalEndereco[i]);
            printf("nova altura: %.2lf\n", universalAltura[i]);
            printf("novo status de vacinacao: %d\n", universalVacina[i]);

            return 0;
        }
    }
    printf("Usuario nao encontrado.\n");
    return -1;
}


int ExcluirUsuario() {
    char email[100];
    int certeza;

    printf("Digite o email do usuario cadastrado: ");
    scanf("%99[^\n]", email); 

    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(universalEmail[i], email) == 0) {
            printf("id: %d\n", universalID[i]);
            printf("nome: %s\n", universalNome[i]);
            printf("sexo: %s\n", universalSexo[i]);
            printf("endereco: %s\n", universalEndereco[i]);
            printf("altura: %.2lf\n", universalAltura[i]);
            printf("status de vacinacao: %d\n", universalVacina[i]);

            printf("Tem certeza que deseja excluir esse usuario?\n1 - sim 0 - nao\n");
            scanf("%d", &certeza);

            if (certeza == 1) {
                for (int j = i + 1; j < numUsuarios; j++) {
                    universalID[j - 1] = universalID[j];
                    strcpy(universalEmail[j - 1], universalEmail[j]);
                    strcpy(universalNome[j - 1], universalNome[j]);
                    strcpy(universalSexo[j - 1], universalSexo[j]);
                    strcpy(universalEndereco[j - 1], universalEndereco[j]);
                    universalAltura[j - 1] = universalAltura[j];
                    universalVacina[j - 1] = universalVacina[j];
                }

                universalID[numUsuarios - 1] = 0;
                memset(universalEmail[numUsuarios - 1], 0, sizeof(universalEmail[numUsuarios - 1]));
                memset(universalNome[numUsuarios - 1], 0, sizeof(universalNome[numUsuarios - 1]));
                memset(universalSexo[numUsuarios - 1], 0, sizeof(universalSexo[numUsuarios - 1]));
                memset(universalEndereco[numUsuarios - 1], 0, sizeof(universalEndereco[numUsuarios - 1]));
                universalAltura[numUsuarios - 1] = 0;
                universalVacina[numUsuarios - 1] = 0;
                numUsuarios--;

                printf("Usuario excluido com sucesso!\n");
                return 0;
            }
            else if (certeza == 0) {
                printf("Finalizando funcao ExcluirUsuario!\n");
                return 0;
            }
        }
    }
    printf("Usuario nao encontrado ou nao cadastrado\n");
    return -2; 
}


int BuscarPorEmail(){
    char email[100];

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]", email);

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(universalEmail[i], email) == 0){

            printf("id: %d\n", universalID[i]);
            printf("nome: %s\n", universalNome[i]);
            printf("sexo: %s\n", universalSexo[i]);
            printf("endereco: %s\n", universalEndereco[i]);
            printf("altura: %.2lf\n", universalAltura[i]);
            printf("status de vacinacao: %d\n", universalVacina[i]);

            return 0;
        }
        else{
            printf("Usuario nao encontrado\n");
            return -1;
        }
    }
}


int ImprimirUsuarios(){
    for(int i = 0; i < numUsuarios; i++){
        printf("\n----------USUARIO %d----------\n", i+1);
        printf("id: %d\n", universalID[i]);
        printf("email: %s\n", universalEmail[i]);
        printf("nome: %s\n", universalNome[i]);
        printf("sexo: %s\n", universalSexo[i]);
        printf("endereco: %s\n", universalEndereco[i]);
        printf("altura: %.2lf\n", universalAltura[i]);
        printf("status de vacinacao: %d\n\n", universalVacina[i]);
    }
}

int BackUp(){
    int certeza;

    printf("tem certeza que deseja fazer backup?\n1 - sim 0 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            backupID[i] = universalID[i];
            strcpy(backupNome[i], universalNome[i]);
            strcpy(backupEmail[i], universalEmail[i]);
            strcpy(backupSexo[i], universalSexo[i]);
            strcpy(backupEndereco[i], universalEndereco[i]);
            backupAltura[i] = universalAltura[i];
            backupVacina[i] = universalVacina[i];
        }
        
        printf("BackUp concluido com sucesso!\n\n");
       
        return 0;
    }
    else if(certeza == 0){
        printf("Backup cancelado!\n\n");
        return 0;
    }
    else {
        printf("Opcao invalida!\n\n");
        return -1;
    }
}

int RestaurarDados(){
    int certeza;

    printf("tem certeza que deseja restaurar dados?\n1 - sim 0 - nao\n");
    scanf("%d", &certeza);

    if(certeza == 1){
        for(int i = 0; i < numUsuarios; i++){
            universalID[i] = backupID[i];
            strcpy(universalNome[i], backupNome[i]);
            strcpy(universalEmail[i], backupEmail[i]);
            strcpy(universalSexo[i], backupSexo[i]);
            strcpy(universalEndereco[i], backupEndereco[i]);
            universalAltura[i] = backupAltura[i];
            universalVacina[i] = backupVacina[i];
        }
        
        printf("Restauracao concluida com sucesso!\n\n");
       
        return 0;
    }
    else if(certeza == 0){
        printf("Saindo da funcao de restaurar dados!\n\n");
        return 0;
    }
    else {
        printf("Opcao invalida\n");
        return -1;
    }
}