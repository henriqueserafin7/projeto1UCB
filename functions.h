#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct Node
{
    int ID;
    char nome[50];
    char email[50];
    char sexo[10];
    char endereco[50];
    double altura;
    int vacina;
    struct Node* next;
};

struct Node* startNode;
struct Node* nodeBuffer;

// Função para adicionar um novo node
void addNode();

// Função para editar os dados de um node adiconado
void editNode();

// Função para excluir um node da lista
void deleteNode();

// Função para exibir os dados da lista
void displayList();

// Função para gerar um ID único para cada node
int generateID();

// Funções para validar os campos de entrada do usuário
int validateEmail(const char email[]);
int validateSexo(const char sexo[]);
int validateAltura(double altura);
int validateVacina(int vacina);

int nodeCounter = 0;

int main()
{
    int option;

    do
    {
        printf("-----------------------------------------\n");
        printf("1 - Criar/Adicionar Nodes à lista\n");
        printf("2 - Editar dados do Node\n");
        printf("3 - Excluir Node\n");
        printf("4 - Listar dados da Lista\n");
        printf("0 - Sair do algoritmo\n");
        printf("Digite a opção: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            addNode();
            break;
        case 2:
            editNode();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            displayList();
            break;
        case 0:
            printf("------------Fechando programa------------\n");
            break;
        default:
            printf("Valor inválido\n");
            break;
        }
    } while (option != 0);

    return 0;
}

// Função para adicionar um novo node
void addNode()
{
    struct Node* newNode;
    int nodeID, nodeVacina;
    char nodeNome[100], nodeEmail[100], nodeSexo[20], nodeEndereco[100];
    double nodeAltura;

    printf("Digite os dados do Node abaixo:\n");
    printf("Digite o nome completo: ");
    scanf(" %[^\n]", nodeNome);
    printf("Digite o email: ");
    scanf(" %[^\n]", nodeEmail);

    while (validateEmail(nodeEmail) != 0)
    {
        printf("Tente novamente: ");
        scanf(" %[^\n]", nodeEmail);
    }

    printf("Digite o sexo (Masculino, Feminino ou Indiferente): ");
    scanf(" %[^\n]", nodeSexo);
    nodeSexo[0] = toupper(nodeSexo[0]);

    while (validateSexo(nodeSexo) != 0)
    {
        printf("Tente novamente: ");
        scanf(" %[^\n]", nodeSexo);
        nodeSexo[0] = toupper(nodeSexo[0]);
    }

    printf("Digite o endereço: ");
    scanf(" %[^\n]", nodeEndereco);
    printf("Digite a altura (Entre 1.0 e 2.0): ");
    scanf("%lf", &nodeAltura);

    while (validateAltura(nodeAltura) != 0)
    {
        printf("Tente novamente: ");
        scanf("%lf", &nodeAltura);
    }

    printf("Foi vacinado? Digite 1 para sim ou 0 para não: ");
    scanf("%d", &nodeVacina);

    while (validateVacina(nodeVacina) != 0)
    {
        printf("Tente novamente: ");
        scanf("%d", &nodeVacina);
    }

    // Gera um ID único e aleatorio para o node
    nodeID = generateID();

    // Aloca memória para o novo node
    newNode = (struct Node*)malloc(sizeof(struct Node));

    // Preenche os campos do node com os valores fornecidos pelo usuário
    newNode->ID = nodeID;
    strcpy(newNode->nome, nodeNome);
    strcpy(newNode->email, nodeEmail);
    strcpy(newNode->sexo, nodeSexo);
    strcpy(newNode->endereco, nodeEndereco);
    newNode->altura = nodeAltura;
    newNode->vacina = nodeVacina;
    newNode->next = NULL;

    // Verifica se a lista está vazia
    if (startNode == NULL)
    {
        // Se a lista estiver vazia, o novo node será o primeiro node da lista
        startNode = newNode;
    }
    else
    {
        // Se a lista não estiver vazia, percorre a lista até encontrar o último node
        struct Node* tempNode = startNode;
        while (tempNode->next != NULL)
        {
            tempNode = tempNode->next;
        }

        // Insere o novo node no final da lista
        tempNode->next = newNode;
    }

    // Incrementa o contador de nodes
    nodeCounter++;

    printf("Node adicionado com sucesso!\n");
}

// Função para editar os dados de um node existente
void editNode()
{
    int nodeID, nodeVacina;
    char nodeNome[100], nodeEmail[100], nodeSexo[20], nodeEndereco[100];
    double nodeAltura;

    if (startNode == NULL)
    {
        printf("A lista está vazia. Não há Nodes para editar.\n");
        return;
    }

    printf("Digite o ID do Node a ser editado: ");
    scanf("%d", &nodeID);

    struct Node* tempNode = startNode;
    while (tempNode != NULL)
    {
        if (tempNode->ID == nodeID)
        {
            printf("Digite os novos dados para o Node:\n");
            printf("Digite o nome completo: ");
            scanf(" %[^\n]", nodeNome);
            printf("Digite o email: ");
            scanf(" %[^\n]", nodeEmail);

            while (validateEmail(nodeEmail) != 0)
            {
                printf("Tente novamente: ");
                scanf(" %[^\n]", nodeEmail);
            }

            printf("Digite o sexo (Masculino, Feminino ou Indiferente): ");
            scanf(" %[^\n]", nodeSexo);
            nodeSexo[0] = toupper(nodeSexo[0]);

            while (validateSexo(nodeSexo) != 0)
            {
                printf("Tente novamente: ");
                scanf(" %[^\n]", nodeSexo);
                nodeSexo[0] = toupper(nodeSexo[0]);
            }

            printf("Digite o endereço: ");
            scanf(" %[^\n]", nodeEndereco);
            printf("Digite a altura (Entre 1.0 e 2.0): ");
            scanf("%lf", &nodeAltura);

            while (validateAltura(nodeAltura) != 0)
            {
                printf("Tente novamente: ");
                scanf("%lf", &nodeAltura);
            }

            printf("Foi vacinado? Digite 1 para sim ou 0 para não: ");
            scanf("%d", &nodeVacina);

            while (validateVacina(nodeVacina) != 0)
            {
                printf("Tente novamente: ");
                scanf("%d", &nodeVacina);
            }

            // Atualiza os dados do node com os novos valores fornecidos pelo usuário
            strcpy(tempNode->nome, nodeNome);
            strcpy(tempNode->email, nodeEmail);
            strcpy(tempNode->sexo, nodeSexo);
            strcpy(tempNode->endereco, nodeEndereco);
            tempNode->altura = nodeAltura;
            tempNode->vacina = nodeVacina;

            printf("Dados do Node atualizados com sucesso!\n");
            return;
        }

        tempNode = tempNode->next;
    }

    printf("Não foi encontrado um Node com o ID fornecido.\n");
}

// Função para excluir um node da lista
void deleteNode()
{
    int nodeID;

    if (startNode == NULL)
    {
        printf("A lista está vazia. Não há Nodes para excluir.\n");
        return;
    }

    printf("Digite o ID do Node a ser excluido: ");
    scanf("%d", &nodeID);

    if (startNode->ID == nodeID)
    {
        // Caso o node a ser excluido seja o primeiro node da lista
        struct Node* tempNode = startNode;
        startNode = startNode->next;
        free(tempNode);
        nodeCounter--;
        printf("Node excluido com sucesso!\n");
        return;
    }

    struct Node* prevNode = startNode;
    struct Node* currNode = startNode->next;

    while (currNode != NULL)
    {
        if (currNode->ID == nodeID)
        {
            prevNode->next = currNode->next;
            free(currNode);
            nodeCounter--;
            printf("Node excluido com sucesso!\n");
            return;
        }

        prevNode = currNode;
        currNode = currNode->next;
    }

    printf("Não foi encontrado um Node com o ID fornecido.\n");
}

// Função para exibir os dados da lista
void displayList()
{
    if (startNode == NULL)
    {
        printf("A lista está vazia. Não há Nodes para exibir.\n");
        return;
    }

    struct Node* tempNode = startNode;
    printf("Lista de Nodes:\n");
    while (tempNode != NULL)
    {
        printf("ID: %d\n", tempNode->ID);
        printf("Nome: %s\n", tempNode->nome);
        printf("Email: %s\n", tempNode->email);
        printf("sexo: %s\n", tempNode->sexo);
        printf("Endereço: %s\n", tempNode->endereco);
        printf("Altura: %.2lf\n", tempNode->altura);
        printf("Vacina: %d\n", tempNode->vacina);
        printf("--------------------\n");

        tempNode = tempNode->next;
    }
}

// Função para gerar um ID único para cada node
int generateID()
{
    srand(time(NULL));
    int id = rand() % 10000;

    // Verifica se o ID já está em uso na lista
    struct Node* tempNode = startNode;
    while (tempNode != NULL)
    {
        if (tempNode->ID == id)
        {
            id = rand() % 10000; // Gera um novo ID
            tempNode = startNode; // Reinicia a verificação
        }
        else
        {
            tempNode = tempNode->next;
        }
    }

    return id;
}

// Função para validar o email
int validateEmail(const char email[])
{
    // Se não tiver arroba retornar 1
    if (strstr(email, "@") != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Função para validar o sexo
int validateSexo(const char sexo[])
{
    // Se digitar um sexo que não esteja nas opccoes retorna 1  
    if (strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indiferente") == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Função para validar a altura
int validateAltura(double altura)
{
    // Se a altura inserida não estiver nos parametros retornar 1
    if (altura >= 1.0 && altura <= 2.0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Função para validar a vacinação
int validateVacina(int vacina)
{
    // Se a opccão nao estiver nos parametros retorna 1
    if (vacina == 0 || vacina == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
