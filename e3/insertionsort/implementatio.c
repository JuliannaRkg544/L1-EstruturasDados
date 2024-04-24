#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

void aloca_vetor(int **v, int n)
{
    *v = (int *)malloc(n * sizeof(int));
}

void preenche_vetor(int *v, int n)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        v[i] = rand() % 5000;
    }
}

void insertionSort(int *v, int n, int *comparacoes, int *atribuicoes)
{
    int i, j, atual;
    for (i = 1; i < n; i++)
    {
        atual = v[i];
        (*atribuicoes)++;
        for (j = i; (j > 0) && (atual < v[j - 1]); j--)
            v[j] = v[j - 1];
        (*atribuicoes)++;
        (*comparacoes)++;
        v[j] = atual;
        (*atribuicoes)++;
    }
}

void imprime_vetor(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int *v, n, comparacoes = 0, atribuicoes = 0;

    n = 50000;

    aloca_vetor(&v, n);
    preenche_vetor(v, n);

    clock_t antes = clock();
    insertionSort(v, n, &comparacoes, &atribuicoes);
    clock_t depois = clock();

    printf("Vetor ordenado:\n");
    imprime_vetor(v, n);
    printf("\nNumero de comparacoes: %d\n", comparacoes);
    printf("\nNumero de atribuicoes: %d\n", atribuicoes);
    free(v);

    double tempo = (double)(depois - antes) / CLOCKS_PER_SEC;
    printf("Tempo de ordenação: %f", tempo);
}