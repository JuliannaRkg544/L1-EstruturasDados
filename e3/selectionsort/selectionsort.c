
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

void selectionSort(int *v, int n)
{
	int i, j, menor, aux;
	for (i = 0; i < n; i++)
	{
		menor = i;
		for (j = i + 1; j < n; j++)
		{
			if (v[j] < v[menor])
			{
				menor = j;
			}
		}
		if (i != menor)
		{
			aux = v[i];
			v[i] = v[menor];
			v[menor] = aux;
		}
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
	selectionSort(v, n);
	imprime_vetor(v, n);
	free(v);
}
