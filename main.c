#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>




#define USERS_MAXIMO 1000 // Limites das constantes
#define NOME_MAXIMO 100
#define SEXO_MAXIMO 100
#define EMAIL_MAXIMO 100
#define ENDERCO_MAXIMO 100

int validarEmail(const char *email){
    if (strchr(email, '@') == NULL)  
    {
        return 0; // invalido
    }
    return 1; // valido
}


// Dados
int numeroUsuarios = 0; // quantos cadastros
int quantidadeBackup = 0; // quantos cadastros dentro do backup
int totalID[USERS_MAXIMO];
char totalNomeCompleto[USERS_MAXIMO][50];
char totalEmail[USERS_MAXIMO][50];
char totalSexo[USERS_MAXIMO][10];
char totalEndereco[USERS_MAXIMO][50];
double totalAltura[USERS_MAXIMO];
int totalVacina[USERS_MAXIMO];


// Fazer backup de dados
int backupID[USERS_MAXIMO];
char backupNomeCompleto[USERS_MAXIMO][100];
char backupEmail[USERS_MAXIMO][100];
char backupSexo[USERS_MAXIMO][10];
char backupEndereco[USERS_MAXIMO][100];
double backupAltura[USERS_MAXIMO];
int backupVacina[USERS_MAXIMO];


// print usu 
void listarUsuarios() {
	int i;
    // caso o valor seja 0 não a usuarios cadastrados
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        // Imprime todos os usuário
        for (i = 0; i < numeroUsuarios; i++) {
            printf("ID: %d\n", totalID[i]);
            printf("Nome: %s\n", totalNomeCompleto[i]);
            printf("Email: %s\n", totalEmail[i]);
            printf("Sexo: %s\n", totalSexo[i]);
            printf("Endereco: %s\n", totalEndereco[i]);
            printf("Altura: %.2lf\n", totalAltura[i]);
            printf("Vacina: %s\n", totalVacina[i] ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

// Função para listar todos os usuários cadastrados
void listarUsuariosBackup() {
	int i;
    if (quantidadeBackup == 0) {
        printf("Nenhum usuario cadastrado.\n");
    } else {
        for (i = 0; i < quantidadeBackup; i++) {
            printf("ID: %d\n", backupID[i]);
            printf("Nome: %s\n", backupNomeCompleto[i]);
            printf("Email: %s\n", backupEmail[i]);
            printf("Sexo: %s\n", backupSexo[i]);
            printf("Endereco: %s\n", backupEndereco[i]);
            printf("Altura: %.2lf\n", backupAltura[i]);
            printf("Vacina: %s\n", backupVacina[i] ? "Sim" : "Nao");
            printf("--------------------\n");
        }
    }
}

// Função para cadastrar um novo usuário
void cadastrarUsuario() {
    double altura;


    // limita quantidade de usuarios
    if (numeroUsuarios == USERS_MAXIMO) {
        printf("Numero maximo de usuarios atingido.\n");
        return;
    }
    printf("Digite seu nome: ");
    fgets(totalNomeCompleto[numeroUsuarios], 50, stdin);
    totalNomeCompleto[numeroUsuarios][strlen(totalNomeCompleto[numeroUsuarios]) - 1] = '\0'; // Remove caracteres novos

    do{
    printf("Digite seu email: ");
    fgets(totalEmail[numeroUsuarios], 50, stdin);
    totalEmail[numeroUsuarios][strlen(totalEmail[numeroUsuarios]) - 1] = '\0';
    if (!validarEmail(totalEmail[numeroUsuarios])){
        printf("Email invalido\n");
        //return;
    }
    }while(!validarEmail(totalEmail[numeroUsuarios]));

    printf("Qual seu sexo? Masculino ou Feminino? ");
fgets(totalSexo[numeroUsuarios], 10, stdin);
totalSexo[numeroUsuarios][strlen(totalSexo[numeroUsuarios]) - 1] = '\0';

getchar(); // Consumir o caractere de nova linha pendente

printf("Digite seu endereco: ");
fgets(totalEndereco[numeroUsuarios], 50, stdin);
totalEndereco[numeroUsuarios][strlen(totalEndereco[numeroUsuarios]) - 1] = '\0'; // Remove caracteres novos

   
    do {
    printf("Digite sua altura (exemplo: 1.75): ");
    scanf("%lf", &altura);
    if (altura > 2.0 || altura < 1.0)
        printf("Altura invalida\n");
    getchar(); // Consumir o caractere de nova linha pendente
} while (altura > 2.0 || altura < 1.0);



    do {
    printf("Vacina: 1 para sim || 2 para nao:");
    scanf("%d", &totalVacina[numeroUsuarios]);
    if (totalVacina[numeroUsuarios] < 1 || totalVacina[numeroUsuarios] > 2)
        printf("Vacina invalida!\n");
    } while (totalVacina[numeroUsuarios] < 1 || totalVacina[numeroUsuarios] > 2);
    

    totalID[numeroUsuarios] = numeroUsuarios + 1;
    totalAltura[numeroUsuarios] = altura;
    numeroUsuarios++;
    quantidadeBackup++;

    printf("Usuario cadastrado.\n");
}

// Função para remover um usuário
void RemoverUsuario() {
    int i;
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado para remover.\n");
        return;
    }

    int idUsuario;
    printf("Digite o ID do usuario que deseja Remover: ");
    scanf("%d", &idUsuario);

    int indiceUsuario = -1;
    for (i = 0; i < numeroUsuarios; i++) {
        if (totalID[i] == idUsuario) {
            indiceUsuario = i;
            break;
        }
    }
    
    if (indiceUsuario == -1) {
        printf("Usuario nao encontrado.\n", idUsuario);
    } else {
        // Realiza a exclusão do usuário
        for (i = indiceUsuario; i < numeroUsuarios - 1; i++) {
            totalID[i] = totalID[i + 1];
            strcpy(totalNomeCompleto[i], totalNomeCompleto[i + 1]);
            strcpy(totalEmail[i], totalEmail[i + 1]);
            strcpy(totalSexo[i], totalSexo[i + 1]);
            strcpy(totalEndereco[i], totalEndereco[i + 1]);
            totalAltura[i] = totalAltura[i + 1];
            totalVacina[i] = totalVacina[i + 1];
        }

        numeroUsuarios--;
        printf("Usuario com ID %d excluido com sucesso.\n", idUsuario);
    }
}


// procurar por email
void buscarUsuarioPorEmail() {
    int i;
    // se for 0 não tem usuarios
    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    char email[50];
    printf("Digite o email do usuario que deseja buscar: ");
    scanf("%s", email);

    int indiceUsuario = -1;
    for (i = 0; i < numeroUsuarios; i++) {
        if (strcmp(totalEmail[i], email) == 0) {
            indiceUsuario = i;
            break;
        }
    }
// o email não está cadastrado
    if (indiceUsuario == -1) {
        printf("Usuario com email %s nao encontrado.\n", email);
    } else {
        printf("Usuario encontrado:\n");
        printf("ID: %d\n", totalID[indiceUsuario]);
        printf("Nome: %s\n", totalNomeCompleto[indiceUsuario]);
        printf("Email: %s\n", totalEmail[indiceUsuario]);
        printf("Sexo: %s\n", totalSexo[indiceUsuario]);
        printf("Endereco: %s\n", totalEndereco[indiceUsuario]);
        printf("Altura: %.2lf\n", totalAltura[indiceUsuario]);
        printf("Vacina: %s\n", totalVacina[indiceUsuario] ? "Sim" : "Não");
    }
}

//fazer backup
void fazerBackup() {
    int i;
    //Copia os dados dos usuários para o backup
    for (i = 0; i < quantidadeBackup; i++) {
        backupID[i] = totalID[i];
        strcpy(backupNomeCompleto[i], totalNomeCompleto[i]);
        strcpy(backupEmail[i], totalEmail[i]);
        strcpy(backupSexo[i], totalSexo[i]);
        strcpy(backupEndereco[i], totalEndereco[i]);
        backupAltura[i] = totalAltura[i];
        backupVacina[i] = totalVacina[i];
    }

    printf("Backup realizado com sucesso.\n");
}

//fazer a restauração
void fazerRestauracao() {
    int i;
    //cadastra usuarios do backup de novo
    for (i = 0; i < quantidadeBackup; i++) {
        totalID[i] = backupID[i];
        strcpy(totalNomeCompleto[i], backupNomeCompleto[i]);
        strcpy(totalEmail[i], backupEmail[i]);
        strcpy(totalSexo[i], backupSexo[i]);
        strcpy(totalEndereco[i], backupEndereco[i]);
        totalAltura[i] = backupAltura[i];
        totalVacina[i] = backupVacina[i];
      //mantem apenas um registro de cada usuario, evita duplicações

    }

   numeroUsuarios = quantidadeBackup; //mantem a quantidade de usuarios igual as do backup

    printf("Restaurado com sucesso.\n");
}

//editar um usuário
void editarUsuario() {
    int i;

    if (numeroUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int idUsuario;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &idUsuario);

    int indiceUsuario = -1;
    for (i = 0; i < numeroUsuarios; i++) {
        if (totalID[i] == idUsuario) {
            indiceUsuario = i;
            break;
        }
    }

    if (indiceUsuario == -1) {
        printf("Usuario com ID %d nao encontrado.\n", idUsuario);
    } else {
        char nome[100], email[100], sexo[10], endereco[100];
        double altura;
        int vacina;

        printf("Digite o nome do usuario: ");
        scanf("%s", nome);
        strcpy(totalNomeCompleto[indiceUsuario], nome);

        printf("Digite o email do usuario: ");
        scanf("%s", email);
        strcpy(totalEmail[indiceUsuario], email);

        printf("Digite o sexo do usuario (Masculino ou Feminino): ");
        scanf("%s", sexo);
        strcpy(totalSexo[indiceUsuario], sexo);

        printf("Digite o endereco do usuario: ");
        scanf("%s", endereco);
        strcpy(totalEndereco[indiceUsuario], endereco);

        printf("Digite a altura do usuario: ");
        scanf("%lf", &altura);
        totalAltura[indiceUsuario] = altura;

        printf("Digite a opcao de vacina do usuario (1 para sim, 2 para nao): ");
        scanf("%d", &vacina);
        totalVacina[indiceUsuario] = vacina;

        printf("Usuario com ID %d editado com sucesso.\n", idUsuario);
    }
}

int main() {
    int opcao;

    do {
        // Exibe o menu de opções
        printf("-----------------MENU-------------------\n\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Listar usuarios\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Fazer backup dos usuarios cadastrados\n");
        printf("6. Restaurar dados do backup\n");
        printf("7. Editar Usuario\n");
        printf("8. Listar usuarios backup\n");
        printf("0. Sair\n");
        printf("----------------------------------------\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
                RemoverUsuario();
                break;
            case 4:
                buscarUsuarioPorEmail();
                break;
            case 5:
                fazerBackup();
                break;
            case 6:
                fazerRestauracao();
                break;
            case 7: 
                 editarUsuario();
                 break;
            case 8: 
                listarUsuariosBackup(); 
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("erro, selecione uma opção valida\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
