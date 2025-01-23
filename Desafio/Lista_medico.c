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
  struct Node *inicio_da_fila;
};

void inicializarFila(struct Medico *medico)
{
  medico->inicio_da_fila = NULL;
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

void removerPaciente(struct Medico *medico)
{
  if (medico->inicio_da_fila == NULL)
  {
    printf("A fila esta vazia.\n");
    return;
  }

  struct Node *temp = medico->inicio_da_fila;
  printf("Paciente %s removido da fila.\n", temp->paciente.nome);
  medico->inicio_da_fila = medico->inicio_da_fila->proximo;
  free(temp);
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

void quantidadePacientes(struct Medico *medico)
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

  printf("Numero de pacientes na fila: %d\n", normais + preferenciais);
  printf("Numero de pacientes normais: %d\n", normais);
  printf("Numero de pacientes preferenciais: %d\n", preferenciais);
}

void atenderPacientePref(struct Medico *medico)
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
      printf("Paciente preferencial %s atendido.\n", atual->paciente.nome);
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  printf("Nenhum paciente preferencial na fila.\n"); // ajeitar quando não tiver preferencial pra ir direto pro normal seguinte da fila
}

void atenderPacienteNorm(struct Medico *medico)
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
      printf("Paciente normal %s atendido.\n", atual->paciente.nome);
      free(atual);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }

  printf("Nenhum paciente na fila.\n");
}

void atenderPaciente(struct Medico *medico)
{
  static int atendidosPreferenciais = 0;

  if (atendidosPreferenciais < 2)
  {
    atenderPacientePref(medico);
    atendidosPreferenciais++;
  }
  else
  {
    atenderPacienteNorm(medico);
    atendidosPreferenciais = 0;
  }
}

int main()
{
  struct Medico medico;
  strcpy(medico.nome, "Dr. Joao");
  inicializarFila(&medico);

  int op = -1, tipo;
  char nome[100];

  while (op != 0)
  {
    printf("\n");
    printf("1. Adicionar paciente\n");
    printf("2. Remover ultimo paciente\n");
    printf("3. Fila de pacientes\n");
    printf("4. Quantidade de pacientes\n");
    printf("5. Atender paciente\n");
    printf("0. Sair\n");
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
      removerPaciente(&medico);
      break;
    case 3:
      imprimirFila(&medico);
      break;
    case 4:
      quantidadePacientes(&medico);
      break;
    case 5:
      atenderPaciente(&medico);
      break;
    case 0:
      printf("Agenda fechada\n");
      break;
    default:
      printf("Opcao invalida. Tente novamente.\n");
    }
  }

  return 0;
}