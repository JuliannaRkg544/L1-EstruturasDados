#include "agenda-protot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef DOS
#include <conio.h>
#else
#include <curses.h>
#endif

int main(void) {
  Agenda *agenda = criarAgenda(10);
  int op;

  do {
    printf("\n1 - Inclusao");
    printf("\n2 - Alteracao");
    printf("\n3 - Consulta");
    printf("\n4 - Excluir");
    printf("\n5 - Pesquisar");
    printf("\n9 - Sair");
    printf("\nEntre com uma opcao -> ");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("*** Inclusao ***\n");
      char nome[40], email[40];
      int telefone;
      printf("Entre com o Nome: ");
      scanf("%s", nome);
      printf("Entre com o Email: ");
      scanf("%s", email);
      printf("Entre com o Telefone: ");
      scanf("%d", &telefone);
      inserirContato(agenda, nome, email, telefone);
      break;
    case 2:
      printf("Digite o Nome: ");
      scanf("%s", nome);
      alterarContato(agenda, nome);
      break;
    case 3:
      ordenarAgenda(agenda);
      consultarAgenda(agenda);
      break;
    case 4:
      printf("Digite o Nome: ");
      scanf("%s", nome);
      excluirContato(agenda, nome);
      break;
    case 5:
      printf("Digite o Nome: ");
      scanf("%s", nome);
      pesquisarContato(agenda, nome);
      break;
    case 9:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (op != 9);

  liberarAgenda(agenda);
  return 0;
}

// Função para criar uma nova agenda
Agenda *criarAgenda(int capacidade) {
  Agenda *agenda = (Agenda *)malloc(sizeof(Agenda));
  if (agenda == NULL) {
    printf("Erro de alocacao de memoria.");
    exit(1);
  }
  agenda->contatos = (Contato *)malloc(capacidade * sizeof(Contato));
  if (agenda->contatos == NULL) {
    printf("Erro de alocacao de memoria.");
    exit(1);
  }
  agenda->capacidade = capacidade;
  agenda->tamanho = 0;
  return agenda;
}

// Função para liberar a memória alocada para a agenda
void liberarAgenda(Agenda *agenda) {
  free(agenda->contatos);
  free(agenda);
}

// Função para inserir um novo contato na agenda
void inserirContato(Agenda *agenda, const char *nome, const char *email,
                    int telefone) {
  if (agenda->tamanho >= agenda->capacidade) {
    printf("Agenda cheia!\n");
    return;
  }

  Contato *contato = &(agenda->contatos[agenda->tamanho]);
  strcpy(contato->nome, nome);
  strcpy(contato->email, email);
  contato->telefone = telefone;
  agenda->tamanho++;
}

// Função para excluir um contato da agenda
void excluirContato(Agenda *agenda, const char *nome) {
  int i, j;
  for (i = 0; i < agenda->tamanho; i++) {
    if (strcmp(agenda->contatos[i].nome, nome) == 0) {
      for (j = i; j < agenda->tamanho - 1; j++) {
        agenda->contatos[j] = agenda->contatos[j + 1];
      }
      agenda->tamanho--;
      printf("Contato excluido com sucesso!\n");
      return;
    }
  }
  printf("Contato nao encontrado!\n");
}

// Função para alterar um contato na agenda
void alterarContato(Agenda *agenda, const char *nome) {
  int i;
  for (i = 0; i < agenda->tamanho; i++) {
    if (strcmp(agenda->contatos[i].nome, nome) == 0) {
      printf("Novo nome: ");
      scanf("%s", agenda->contatos[i].nome);
      printf("Novo email: ");
      scanf("%s", agenda->contatos[i].email);
      printf("Novo telefone: ");
      scanf("%d", &agenda->contatos[i].telefone);
      return;
    }
  }
  printf("Contato nao encontrado!\n");
}

// Função para consultar a agenda
void consultarAgenda(const Agenda *agenda) {
  int i;
  for (i = 0; i < agenda->tamanho; i++) {
    printf("\nRegistro %d", i);
    printf("\n\tNome: %s", agenda->contatos[i].nome);
    printf("\n\tEmail: %s", agenda->contatos[i].email);
    printf("\n\tTelefone: %d\n", agenda->contatos[i].telefone);
  }
}

// Função para pesquisar um contato na agenda
void pesquisarContato(const Agenda *agenda, const char *nome) {
  int i;
  for (i = 0; i < agenda->tamanho; i++) {
    if (strcmp(agenda->contatos[i].nome, nome) == 0) {
      printf("\nRegistro %d", i);
      printf("\n\tNome: %s", agenda->contatos[i].nome);
      printf("\n\tEmail: %s", agenda->contatos[i].email);
      printf("\n\tTelefone: %d\n", agenda->contatos[i].telefone);
      return;
    }
  }
  printf("Contato nao encontrado!\n");
}

// Função para ordenar a agenda
void ordenarAgenda(Agenda *agenda) {
  quicksort(agenda->contatos, 0, agenda->tamanho - 1);
}

// Função quicksort para ordenação
void quicksort(Contato *contatos, int esq, int dir) {
  int i = esq, j = dir;
  Contato pivo, temp;
  strcpy(pivo.nome, contatos[(esq + dir) / 2].nome);

  do {
    while (strcmp(contatos[i].nome, pivo.nome) < 0 && i < dir)
      i++;
    while (strcmp(contatos[j].nome, pivo.nome) > 0 && j > esq)
      j--;
    if (i <= j) {
      temp = contatos[i];
      contatos[i] = contatos[j];
      contatos[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);

  if (esq < j)
    quicksort(contatos, esq, j);
  if (i < dir)
    quicksort(contatos, i, dir);
}
