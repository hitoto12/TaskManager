// Cesar Wellington Dos Santos Nunes - Ra 024058

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_MAX_DESCRICAO 100

typedef struct Tarefa {
  int id;
  char descricao[TAMANHO_MAX_DESCRICAO];
  struct Tarefa *prox;
} TAREFA;

// CONSTRUTOR
TAREFA *criarTarefa(int id, char *descricao);
TAREFA *criarTarefaPorScanf();

// LISTA
void adicionarNaListaConcluida(TAREFA *novaTarefa);
TAREFA *removerDaListaConcluidaPeloId(int id);
void verTodasAsTarefasConcluidas();

// FILA
void colocarNaFilaPendente(TAREFA *novaTarefa);
TAREFA *obterDaFilaPendente();
void verTodasAsTarefasPendentes();

// PILHA
void empurrarParaPilhaRascunho(TAREFA *novaTarefa);
TAREFA *retirarDaPilhaRascunho();
void verTodasAsTarefasRascunho();

// MENU
void exibirMenu();

// Ponteiro global
TAREFA *fila_topo = NULL, *fila_baixo = NULL;
TAREFA *concluido_topo = NULL;
TAREFA *rascunho = NULL;

int main() {
  int escolha;
  printf("################# SISTEMA DE GERENCIAMENTO DE TAREFAS #################");

  do {
    exibirMenu();
    printf("Escolha uma opção: ");
    scanf("%d", &escolha);

    TAREFA *tarefa;
    int id;

    switch (escolha) {
    case 1:
      // CRIAR UMA TAREFA, DEPOIS ADICIONAR NA FILA PENDENTE
      tarefa = criarTarefaPorScanf();
      colocarNaFilaPendente(tarefa);
      break;

    case 2:
      // VER TODAS AS TAREFAS DA FILA PENDENTE
      verTodasAsTarefasPendentes();
      break;

    case 3:
      // CONCLUIR A PRIMEIRA TAREFA PENDENTE
      tarefa = obterDaFilaPendente();
      if (tarefa != NULL) {
        adicionarNaListaConcluida(tarefa);
      }
      break;

    case 4:
      // VER TODAS AS TAREFAS DA LISTA CONCLUÍDA
      verTodasAsTarefasConcluidas();
      break;

    case 5:
      // MOVER TAREFA CONCLUÍDA PARA RASCUNHO
      printf("Insira o ID da Tarefa (número): ");
      scanf("%d", &id);

      tarefa = removerDaListaConcluidaPeloId(id);
      if (tarefa != NULL) {
        empurrarParaPilhaRascunho(tarefa);
      }
      break;

    case 6:
      // VER TODAS AS TAREFAS DO RASCUNHO
      verTodasAsTarefasRascunho();
      break;

    case 7:
      // MOVER ÚLTIMO RASCUNHO PARA TAREFA PENDENTE
      tarefa = retirarDaPilhaRascunho();
      if (tarefa != NULL) {
        colocarNaFilaPendente(tarefa);
      }
      break;

    case 0:
      printf("Saindo do programa\n");
      break;
    default:
      printf("Escolha inválida\n");
      break;
    }
  } while (escolha != 0);

  printf("################# SISTEMA DESLIGADO #################");
}

// CONSTRUTOR
TAREFA *criarTarefa(int id, char *descricao) {
  TAREFA *novaTarefa = (TAREFA *)malloc(sizeof(TAREFA));

  novaTarefa->id = id;
  strcpy(novaTarefa->descricao, descricao);
  novaTarefa->prox = NULL;

  return novaTarefa;
}

TAREFA *criarTarefaPorScanf() {
  int id;
  char descricao[TAMANHO_MAX_DESCRICAO];

  printf("Insira o ID da Tarefa (número): ");
  scanf("%d", &id);

  getchar();
  printf("Insira a Descrição da Tarefa (texto): ");

  fgets(descricao, TAMANHO_MAX_DESCRICAO, stdin);
  descricao[strcspn(descricao, "\n")] = '\0';

  return criarTarefa(id, descricao);
}

// LISTA
void adicionarNaListaConcluida(TAREFA *novaTarefa) {
  printf("Adicionando Tarefa à Lista Concluída\n");

  // SEU CÓDIGO AQUI
  if (fila_topo == NULL) {
    concluido_topo = novaTarefa;
  } else {
    TAREFA *temp = fila_topo;
    while (temp->prox != NULL) {
      temp = temp->prox;
    }
    temp->prox = novaTarefa;
  }
}

TAREFA *removerDaListaConcluidaPeloId(int id) {
  printf("Removendo Tarefa da Lista Concluída\n");

  // SEU CÓDIGO AQUI
  TAREFA *temp = concluido_topo, *prev = NULL;

  if (temp != NULL && temp->id == id) {
    concluido_topo = temp->prox;
    return temp;
  }

  while (temp != NULL && temp->id != id) {
    prev = temp;
    temp = temp->prox;
  }

  if (temp == NULL)
    return NULL;

  prev->prox = temp->prox;
  return temp;
}

void verTodasAsTarefasConcluidas() {
  printf("Imprimindo Todas as Tarefas Concluídas\n");

  // SEU CÓDIGO AQUI
  TAREFA *temp = concluido_topo;
  while (temp != NULL) {
    printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao);
    temp = temp->prox;
  }
}

// FILA
void colocarNaFilaPendente(TAREFA *novaTarefa) {

  // SEU CÓDIGO AQUI
  printf("Colocando Tarefa na Fila Pendente\n");

  if (fila_baixo == NULL) {
    fila_topo = fila_baixo = novaTarefa;
  } else {
    fila_baixo->prox = novaTarefa;
    fila_baixo = novaTarefa;
  }
}

TAREFA *obterDaFilaPendente() {
  printf("Obtendo Tarefa da Fila Pendente\n");

  // SEU CÓDIGO AQUI
  if (fila_topo == NULL)
    return NULL;

  TAREFA *temp = fila_topo;
  fila_topo = fila_topo->prox;

  if (fila_topo == NULL) {
    fila_baixo = NULL;
  }

  return temp;
}

void verTodasAsTarefasPendentes() {
  printf("Imprimindo Todas as Tarefas Pendentes\n");

  // SEU CÓDIGO AQUI
  TAREFA *temp = fila_topo;
  while (temp != NULL) {
    printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao);
    temp = temp->prox;
  }
}

// PILHA
void empurrarParaPilhaRascunho(TAREFA *novaTarefa) {
  printf("Empurrando Tarefa para a Pilha de Rascunho\n");

  // SEU CÓDIGO AQUI
  novaTarefa->prox = rascunho;
  rascunho = novaTarefa;
}

TAREFA *retirarDaPilhaRascunho() {
  printf("Retirando Tarefa da Pilha de Rascunho\n");

  // SEU CÓDIGO AQUI
  if (rascunho == NULL)
    return NULL;

  TAREFA *temp = rascunho;
  rascunho = rascunho->prox;

  return temp;
}

void verTodasAsTarefasRascunho() {
  printf("Imprimindo Todas as Tarefas de Rascunho\n");

  // SEU CÓDIGO AQUI
  TAREFA *temp = rascunho;
  while (temp != NULL) {
    printf("ID: %d, Descrição: %s\n", temp->id, temp->descricao);
    temp = temp->prox;
  }
}

// MENU
void exibirMenu() {
  printf("\nMenu:\n");
  printf("1 - Criar Nova Tarefa Pendente\n");
  printf("2 - Ver Todas as Tarefas Pendentes\n");
  printf("3 - Concluir Primeira Tarefa Pendente\n");
  printf("4 - Ver Todas as Tarefas Concluídas\n");
  printf("5 - Mover Tarefa Concluída para Rascunho pelo ID\n");
  printf("6 - Ver Todas as Tarefas de Rascunho\n");
  printf("7 - Mover Última Tarefa de Rascunho para Pendente\n");
  printf("0 - Sair\n");
}
