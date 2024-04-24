#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <conio.h>

typedef struct agenda {
  char nome[40];
  char email[40];
  int telefone;
} AGENDA;

void aloca(AGENDA **pAgenda, int *piEntradas);
void consulta(AGENDA *pAgenda, int iEntradas);

void qs_ordena(AGENDA pAgenda[], int left, int right);
void ordena(AGENDA pAgenda[], int iEntradas);

void excluir(AGENDA **pAgenda, int *piEntradas);
void pesquisar(AGENDA *pAgenda, int iEntradas);
void alterar(AGENDA *pAgenda, int iEntradas);

int main(void) {
  AGENDA *pAgenda;
  int iEntradas, op;
  iEntradas = 0;
  pAgenda = NULL; // Inicialize como NULL
  do {
    printf("\n1 - Inclusao");
    printf("\n2 - Alteracao");
    printf("\n3 - Consulta");
    printf("\n4 - Excluir");
    printf("\n5 - Pesquisar");
    printf("\n9 - Sair");
    printf("\nEntre com uma opcao -> ");
    scanf("%d", &op);
    if (op == 1) {
      aloca(&pAgenda, &iEntradas);
      printf("*** Inclusao ***");
      printf("\nEntre com o Nome:");
      scanf("%s", pAgenda[iEntradas].nome);
      printf("Entre com o email:");
      scanf("%s", pAgenda[iEntradas].email);
      printf("Entre com o telefone:");
      scanf("%d", &pAgenda[iEntradas].telefone);
      iEntradas++;
    } else if (op == 2) {
      alterar(pAgenda, iEntradas);
    } else if (op == 3) {
      ordena(pAgenda, iEntradas);
      consulta(pAgenda, iEntradas);
    } else if (op == 4) {
      ordena(pAgenda, iEntradas);
      excluir(&pAgenda, &iEntradas);
    } else if (op == 5) {
      ordena(pAgenda, iEntradas);
      pesquisar(pAgenda, iEntradas);
    }
  } while (op != 9);

  free(pAgenda); // Libere a memÃ³ria alocada no final do programa
  return 0;
}

void consulta(AGENDA *pAgenda, int iEntradas) {
  int i;
  for (i = 0; i < iEntradas; i++) {
    printf("\n\nRegistro %d", i);
    printf("\n\tNome: %s", pAgenda[i].nome);
    printf("\n\tEmails: %s", pAgenda[i].email);
    printf("\n\tTelefone: %d", pAgenda[i].telefone);
    getchar();
  }
}

void alterar(AGENDA *pAgenda, int iEntradas) {
  char op;
  int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  scanf("%s", nome);
  for (i = 0;
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome)) != 0; i++)
    ;
  if (i >= iEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    printf("\n\tRegistro %d", i);
    printf("\n\tNome : %s", pAgenda[i].nome);
    printf("\n\tEmail : %s", pAgenda[i].email);
    printf("\n\tFone : %d", pAgenda[i].telefone);
    printf("\n\tConfirma a alteracao ?");
    op = getchar();
    if (op == 'S' || op == 's') {
      printf("\nEntre com o Nome:");
      scanf("%s", pAgenda[i].nome);
      printf("Entre com o email:");
      scanf("%s", pAgenda[i].email);
      printf("Entre com o telefone:");
      scanf("%d", &pAgenda[i].telefone);
    }
  }
}

void excluir(AGENDA **pAgenda, int *piEntradas) {
  char op;
  int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  scanf("%s", nome);
  for (i = 0;
       i < *piEntradas && strncmp((*pAgenda)[i].nome, nome, strlen(nome)) != 0;
       i++)
    ;
  if (i >= *piEntradas) {
    printf("\nRegistro nï¿½o encontrado");
  } else {
    printf("\n\tRegistro %d", i);
    printf("\n\tNome : %s", (*pAgenda)[i].nome);
    printf("\n\tEmail : %s", (*pAgenda)[i].email);
    printf("\n\tFone : %d", (*pAgenda)[i].telefone);
    printf("\n\tConfirma a exclusao ?");
    op = getchar();
    if (op == 'S' || op == 's') {
      (*pAgenda)[i] = (*pAgenda)[(*piEntradas) - 1];
      (*piEntradas)--;
      *pAgenda = realloc(*pAgenda, (*piEntradas) * sizeof(AGENDA));
      if (*pAgenda == NULL) {
        printf("\nErro de re-alocacao de memoria");
        exit(1);
      }
    }
  }
}

void aloca(AGENDA **pAgenda, int *piEntradas) {
  *pAgenda = (AGENDA *)(realloc(*pAgenda, (*piEntradas + 1) * sizeof(AGENDA)));
  if (*pAgenda == NULL) {
    printf("\nErro de re-alocacao de memoria");
    exit(1);
  }
}

void pesquisar(AGENDA *pAgenda, int iEntradas) {
  char op;
  int i = 0;
  char nome[40];
  printf("\n\tDigite o Nome:");
  scanf("%s", nome);
  for (i = 0;
       i < iEntradas && strncmp(pAgenda[i].nome, nome, strlen(nome)) != 0; i++)
    ;
  if (i >= iEntradas) {
    printf("\nRegistro nao encontrado");
  } else {
    do {
      printf("\n\n\tRegistro %d", i);
      printf("\n\tNome : %s", pAgenda[i].nome);
      printf("\n\tEmail : %s", pAgenda[i].email);
      printf("\n\tFone : %d", pAgenda[i].telefone);
      printf("\n\tProximo ? ");
      op = getchar();
      i++;
      if (i >= iEntradas) {
        i = 0;
      }
    } while (op == 'S' || op == 's');
  }
}

void ordena(AGENDA pAgenda[], int iEntradas) {
  qs_ordena(pAgenda, 0, iEntradas - 1);
}

void qs_ordena(AGENDA pAgenda[], int left, int right) {
  register int i, j;
  char *x;
  AGENDA t;
  i = left;
  j = right;
  x = pAgenda[(left + right) / 2].nome;
  do {
    while (strcmp(pAgenda[i].nome, x) < 0 && i < right)
      i++;
    while (strcmp(pAgenda[j].nome, x) > 0 && j > left)
      j--;
    if (i <= j) {
      t = pAgenda[i];
      pAgenda[i] = pAgenda[j];
      pAgenda[j] = t;
      i++;
      j--;
    }
  } while (i <= j);
  if (left < j)
    qs_ordena(pAgenda, left, i);
  if (i < right)
    qs_ordena(pAgenda, i, right);
}
