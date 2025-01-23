#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente
{
  char nome[100];
  int tipo; // 0 para normal, 1 para preferencial
};

struct Node
{
  struct Paciente paciente;
  struct Node *proximo;
};

struct Medico
{
  char nome[100];
  int total_pacientes_atendidos;
  struct Node *inicio_da_fila;
};

void inicializarFila(struct Medico *medico)
{
  medico->inicio_da_fila = NULL;
  medico->total_pacientes_atendidos = 0;
}

void adicionarPaciente(struct Medico *medico, char nome[], int tipo)
{
  struct Node *novoNode = (struct Node *)malloc(sizeof(struct Node));
  strcpy(novoNode->paciente.nome, nome);
  novoNode->paciente.tipo = tipo;
  novoNode->proximo = NULL;

  if (medico->inicio_da_fila == NULL)
  {
    medico->inicio_da_fila = novoNode;
  }
  else
  {
    struct Node *atual = medico->inicio_da_fila;
    while (atual->proximo != NULL)
    {
      atual = atual->proximo;
    }
    atual->proximo = novoNode;
  }
}

struct Paciente removerPaciente(struct Medico *medico)
{
  if (medico->inicio_da_fila == NULL)
  {
    printf("A fila esta vazia.\n");
    struct Paciente pacienteVazio = {"", -1};
    return pacienteVazio;
  }

  struct Node *temp = medico->inicio_da_fila;
  struct Paciente pacienteRemovido = temp->paciente;
  medico->inicio_da_fila = medico->inicio_da_fila->proximo;
  free(temp);

  return pacienteRemovido;
}

void imprimirFila(struct Medico *medico)
{
  struct Node *atual = medico->inicio_da_fila;

  if (atual == NULL)
  {
    printf("A fila esta vazia.\n");
    return;
  }

  printf("Fila de pacientes de %s:\n", medico->nome);
  while (atual != NULL)
  {
    printf("%s - %s\n", atual->paciente.nome, atual->paciente.tipo == 1 ? "Preferencial" : "Normal");
    atual = atual->proximo;
  }
}

void calcularTamanhoFila(struct Medico *medico)
{
  int normais = 0, preferenciais = 0;
  struct Node *atual = medico->inicio_da_fila;

  while (atual != NULL)
  {
    if (atual->paciente.tipo == 0)
      normais++;
    else
      preferenciais++;
    atual = atual->proximo;
  }

  printf("Numero de pacientes normais: %d\n", normais);
  printf("Numero de pacientes preferenciais: %d\n", preferenciais);
}

int filaVazia(struct Medico *medico)
{
  return medico->inicio_da_fila == NULL;
}

struct Paciente removerPacientePreferencial(struct Medico *medico)
{
  struct Node *atual = medico->inicio_da_fila;
  struct Node *anterior = NULL;

  while (atual != NULL)
  {
    if (atual->paciente.tipo == 1)
    {
      if (anterior == NULL)
      {
        medico->inicio_da_fila = atual->proximo;
      }
      else
      {
        anterior->proximo = atual->proximo;
      }
      struct Paciente pacienteRemovido = atual->paciente;
      free(atual);
      return pacienteRemovido;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  struct Paciente pacienteVazio = {"", -1};
  return pacienteVazio;
}

struct Paciente removerPacienteNormal(struct Medico *medico)
{
  struct Node *atual = medico->inicio_da_fila;
  struct Node *anterior = NULL;

  while (atual != NULL)
  {
    if (atual->paciente.tipo == 0)
    {
      if (anterior == NULL)
      {
        medico->inicio_da_fila = atual->proximo;
      }
      else
      {
        anterior->proximo = atual->proximo;
      }
      struct Paciente pacienteRemovido = atual->paciente;
      free(atual);
      return pacienteRemovido;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  struct Paciente pacienteVazio = {"", -1};
  return pacienteVazio;
}

void atenderPaciente(struct Medico *medico)
{
  struct Paciente pacienteAtendido;

  // Atender um paciente preferencial se houver
  pacienteAtendido = removerPacientePreferencial(medico);
  if (pacienteAtendido.tipo != -1)
  {
    printf("Atendendo paciente preferencial %s\n", pacienteAtendido.nome);
  }
  else
  {
    // Se nao houver preferenciais, atender um normal
    pacienteAtendido = removerPacienteNormal(medico);
    if (pacienteAtendido.tipo != -1)
    {
      printf("Atendendo paciente normal %s\n", pacienteAtendido.nome);
    }
    else
    {
      printf("A fila esta vazia.\n");
    }
  }
}

int main()
{
  struct Medico medico;
  strcpy(medico.nome, "Dr. Joao");
  inicializarFila(&medico);

  int op, tipo;
  char nome[100];

  while (op != 6)
  {
    printf("\n");
    printf("1. Adicionar paciente\n");
    printf("2. Remover paciente\n");
    printf("3. Imprimir fila de pacientes\n");
    printf("4. Calcular tamanho da fila\n");
    printf("5. Atender paciente\n");
    printf("6. Sair\n");
    printf("Digite a opcao: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
      printf("Nome do paciente: ");
      scanf("%s", nome);
      printf("Tipo (0-Normal, 1-Preferencial): ");
      scanf("%d", &tipo);
      adicionarPaciente(&medico, nome, tipo);
      break;
    case 2:
    {
      struct Paciente pacienteRemovido = removerPaciente(&medico);
      if (pacienteRemovido.tipo != -1)
      {
        printf("Paciente %s removido da fila.\n", pacienteRemovido.nome);
      }
    }
    break;
    case 3:
      imprimirFila(&medico);
      break;
    case 4:
      calcularTamanhoFila(&medico);
      break;
    case 5:
      atenderPaciente(&medico);
      break;
    case 6:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  }

  return 0;
}