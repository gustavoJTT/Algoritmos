#include <stdio.h>
#include <stdlib.h>

// Estrutura que representa um paciente
struct Paciente {
    char nome[100]; // Nome do paciente
    int tipo; // Tipo do paciente: 0 para normal, 1 para preferencial
};

// Estrutura que representa um nó na fila de pacientes
struct Node {
    struct Paciente paciente; // Dados do paciente
    struct Node *proximo; // Ponteiro para o próximo nó na fila
};

// Estrutura que representa um médico
struct Medico {
    char nome[100]; // Nome do médico
    int total_pacientes_atendidos; // Total de pacientes atendidos pelo médico
    struct Node *inicio_da_fila; // Ponteiro para o início da fila de pacientes
};

// Função para inicializar a fila de pacientes de um médico
void inicializarFila(struct Medico *medico) {
    medico->inicio_da_fila = NULL; // Define o início da fila como NULL (vazia)
    medico->total_pacientes_atendidos = 0; // Define o total de pacientes atendidos como 0
}

// Função para adicionar um paciente à fila de um médico
void adicionarPaciente(struct Medico *medico, char *nome, int tipo) {
    // Verifica se o médico já atendeu o número máximo de pacientes
    if (medico->total_pacientes_atendidos >= 15) {
        printf("O médico já atendeu o número máximo de pacientes hoje.\n");
        return;
    }

    // Cria um novo nó para o paciente
    struct Node *novo_node = (struct Node *)malloc(sizeof(struct Node));
    // Copia o nome do paciente para a estrutura
    for (int i = 0; nome[i] != '\0'; i++) {
        novo_node->paciente.nome[i] = nome[i];
    }
    novo_node->paciente.tipo = tipo; // Define o tipo do paciente
    novo_node->proximo = NULL; // Define o próximo nó como NULL

    // Adiciona o novo nó ao final da fila
    if (medico->inicio_da_fila == NULL) {
        medico->inicio_da_fila = novo_node; // Se a fila estiver vazia, o novo nó é o primeiro
    } else {
        struct Node *atual = medico->inicio_da_fila;
        // Percorre a fila até encontrar o último nó
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo_node; // Adiciona o novo nó ao final da fila
    }
}

// Função para remover um paciente da fila de um médico
void removerPaciente(struct Medico *medico) {
    // Verifica se a fila está vazia
    if (medico->inicio_da_fila == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    // Remove o primeiro nó da fila
    struct Node *temp = medico->inicio_da_fila;
    medico->inicio_da_fila = medico->inicio_da_fila->proximo;
    free(temp); // Libera a memória do nó removido
    medico->total_pacientes_atendidos++; // Incrementa o total de pacientes atendidos
}

// Função para imprimir a fila de pacientes de um médico
void imprimirFila(struct Medico *medico) {
    struct Node *atual = medico->inicio_da_fila;
    printf("Fila de pacientes do Dr. %s:\n", medico->nome);
    // Percorre a fila e imprime os dados de cada paciente
    while (atual != NULL) {
        printf("Nome: %s, Tipo: %s\n", atual->paciente.nome, atual->paciente.tipo == 0 ? "Normal" : "Preferencial");
        atual = atual->proximo;
    }
}

// Função para atender pacientes seguindo a regra de 2 preferenciais para 1 normal
void atenderPacientes(struct Medico *medico) {
    int atendidosNormais = 0; // Contador de pacientes normais atendidos
    int atendidosPreferenciais = 0; // Contador de pacientes preferenciais atendidos

    // Atende pacientes enquanto houver na fila e o limite diário não for atingido
    while (medico->inicio_da_fila != NULL && medico->total_pacientes_atendidos < 15) {
        // Atende pacientes preferenciais se a contagem for menor que 2
        if (atendidosPreferenciais < 2 && medico->inicio_da_fila->paciente.tipo == 1) {
            removerPaciente(medico);
            atendidosPreferenciais++;
        } else if (medico->inicio_da_fila->paciente.tipo == 0) {
            removerPaciente(medico);
            atendidosNormais++;
            atendidosPreferenciais = 0; // Reseta a contagem de preferenciais
        } else {
            removerPaciente(medico);
        }
    }
}

// Função para imprimir o menu de opções
void imprimir_menu() {
    printf("1. Adicionar paciente\n");
    printf("2. Remover paciente\n");
    printf("3. Imprimir fila\n");
    printf("4. Atender pacientes\n");
    printf("5. Sair\n");
}

// Função principal
int main() {
    struct Medico medico;
    char nome_medico[] = "Dr. Silva";
    // Copia o nome do médico para a estrutura
    for (int i = 0; nome_medico[i] != '\0'; i++) {
        medico.nome[i] = nome_medico[i];
    }
    inicializarFila(&medico); // Inicializa a fila de pacientes do médico

    int opcao;
    char nome[100];
    int tipo;

    // Loop principal do programa
    while (1) {
        imprimir_menu(); // Imprime o menu de opções
        printf("Digite a opcao: ");
        scanf("%d", &opcao); // Lê a opção escolhida pelo usuário
        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                scanf("%s", nome); // Lê o nome do paciente
                printf("Tipo do paciente (0 para normal, 1 para preferencial): ");
                scanf("%d", &tipo); // Lê o tipo do paciente
                adicionarPaciente(&medico, nome, tipo); // Adiciona o paciente à fila
                break;
            case 2:
                removerPaciente(&medico); // Remove um paciente da fila
                break;
            case 3:
                imprimirFila(&medico); // Imprime a fila de pacientes
                break;
            case 4:
                atenderPacientes(&medico); // Atende os pacientes na fila
                break;
            case 5:
                return 0; // Encerra o programa
            default:
                printf("Opcao invalida\n"); // Mensagem de erro para opção inválida
        }
    }
    return 0;
}