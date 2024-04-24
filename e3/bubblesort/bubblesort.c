
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
		v[i] = rand() % 100;
	}
}

void bubbleSort(int *v, int n)
{
	int i, continua, aux, fim = n;
	do
	{
		continua = 0;
		for (i = 0; i < fim - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				continua = i;
			}
		}
		fim--;
	} while (continua != 0);
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

	int *v, n;

	n = 10;

	aloca_vetor(&v, n);
	preenche_vetor(v, n);
	bubbleSort(v, n);
	imprime_vetor(v, n);
	free(v);
}
