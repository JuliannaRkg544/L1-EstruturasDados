#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
		v[i] = rand() % 100;
	}
}

void insertionSort(int *v, int n)
{
	int i, j, atual;
	for (i = 1; i < n; i++)
	{
		atual = v[i];
		for (j = i; (j > 0) && (atual < v[j - 1]); j--)
		{
			v[j] = v[j - 1];
		}
		v[j] = atual;
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
	int *v, n;

	n = 10;

	aloca_vetor(&v, n);
	preenche_vetor(v, n);
	insertionSort(v, n);
	imprime_vetor(v, n);
	free(v);
}