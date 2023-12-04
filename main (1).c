#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura para os veículos
typedef enum { ALCOOL, DIESEL, GASOLINA } Combustivel;

typedef struct {
    char proprietario[50];
    Combustivel combustivel;
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[8];
} Veiculo;

// Nó para a lista encadeada
typedef struct Node {
    Veiculo veiculo;
    struct Node* next;
} Node;

// Função para listar proprietários de carros do ano de 2010 ou posterior movidos a diesel
void listarDiesel2010(Node* head) {
    Node* current = head;
    printf("Proprietários de carros do ano de 2010 ou posterior movidos a diesel:\n");
    while (current != NULL) {
        if (current->veiculo.ano >= 2010 && current->veiculo.combustivel == DIESEL) {
            printf("%s\n", current->veiculo.proprietario);
        }
        current = current->next;
    }
}

// Função para listar placas que atendem a certos critérios e seus respectivos proprietários
void listarPlacasJ(Node* head) {
    Node* current = head;
    printf("\nPlacas que começam com a letra J e terminam com 0, 2, 4 ou 7 e seus respectivos proprietários:\n");
    while (current != NULL) {
        char primeiraLetra = current->veiculo.placa[0];
        char ultimaLetra = current->veiculo.placa[6];
        if (primeiraLetra == 'J' && (ultimaLetra == '0' || ultimaLetra == '2' || ultimaLetra == '4' || ultimaLetra == '7')) {
            printf("Placa: %s - Proprietário: %s\n", current->veiculo.placa, current->veiculo.proprietario);
        }
        current = current->next;
    }
}

// Função para listar modelo e cor dos veículos que atendem a certos critérios
void listarModeloCor(Node* head) {
    Node* current = head;
    printf("\nModelo e cor dos veículos cujas placas têm como segunda letra uma vogal e a soma dos valores numéricos é par:\n");
    while (current != NULL) {
        char segundaLetra = current->veiculo.placa[1];
        int somaNumerosPlaca = 0;
        for (int i = 3; i < 7; ++i) {
            somaNumerosPlaca += current->veiculo.placa[i] - '0';
        }
        if ((segundaLetra == 'A' || segundaLetra == 'E' || segundaLetra == 'I' || segundaLetra == 'O' || segundaLetra == 'U') && (somaNumerosPlaca % 2 == 0)) {
            printf("Modelo: %s - Cor: %s\n", current->veiculo.modelo, current->veiculo.cor);
        }
        current = current->next;
    }
}

// Função para trocar o proprietário com base no número do chassi
void trocarProprietario(Node* head, char chassi[]) {
    Node* current = head;
    while (current != NULL) {
        int hasZero = 0;
        for (int i = 0; i < 7; ++i) {
            if (current->veiculo.placa[i] == '0') {
                hasZero = 1;
                break;
            }
        }
        if (hasZero == 0 && strcmp(current->veiculo.chassi, chassi) == 0) {
            printf("\nNovo proprietário para o veículo com chassi %s: ", chassi);
            scanf("%s", current->veiculo.proprietario);
            printf("Proprietário atualizado com sucesso!\n");
            return;
        }
        current = current->next;
    }
    printf("Nenhum veículo corresponde aos critérios fornecidos.\n");
}

// Função principal apenas para teste
int main() {
    // Aqui você irá inicializar a lista encadeada com os dados dos veículos

    // Exemplo de uso das funções (substitua com sua lógica de inicialização da lista)
    Node* head = NULL;

    // Chamada das funções
    listarDiesel2010(head);
    listarPlacasJ(head);
    listarModeloCor(head);

    char chassiTroca[20];
    printf("\nDigite o número do chassi para trocar o proprietário: ");
    scanf("%s", chassiTroca);
    trocarProprietario(head, chassiTroca);

    return 0;
}
