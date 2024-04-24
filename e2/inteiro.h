#include <stdio.h>

typedef struct
{
    int elementos[10];
    int tamanho;
} conjuntoDeInt;
void imprimir(conjuntoDeInt *conjunto)
{
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        printf("%d", conjunto->elementos[i]);
        if (i < conjunto->tamanho - 1)
        {
            printf(", ");
        }
    }
    printf(" }\n");
}
void criaConjunto(conjuntoDeInt *conjunto) { conjunto->tamanho = 0; }
void insereElemento(int num, conjuntoDeInt *conjunto)
{
    if (conjunto->tamanho >= 10)
    {
        return;
    }
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] == num)
        {
            return;
        }
    }
    conjunto->elementos[conjunto->tamanho++] = num;
    return;
}
void removeElemento(int num, conjuntoDeInt *conjunto)
{
    int i, j;
    for (i = 0; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] == num)
        {
            for (j = i; j < conjunto->tamanho - 1; j++)
            {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            return;
        }
    }
    return;
}

int verificaElemento(int num, conjuntoDeInt *conjunto)
{
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] == num)
        {
            return 1;
        }
    }
    return 0;
}
void destruir(conjuntoDeInt *conjunto) { conjunto->tamanho = 0; }

void uneConjuntos(conjuntoDeInt *conjuntoA, conjuntoDeInt *conjuntoB,
                  conjuntoDeInt *resultado)
{
    criaConjunto(resultado);

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        insereElemento(conjuntoA->elementos[i], resultado);
    }

    for (int i = 0; i < conjuntoB->tamanho; i++)
    {
        int aux = verificaElemento(conjuntoB->elementos[i], resultado);
        if (aux == 0)
        {
            insereElemento(conjuntoB->elementos[i], resultado);
        }
    }
}

void diferenca(conjuntoDeInt *conjuntoA, conjuntoDeInt *conjuntoB,
               conjuntoDeInt *resultado)
{

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        int aux = verificaElemento(conjuntoA->elementos[i], conjuntoB);
        if (aux == 0)
        {
            insereElemento(conjuntoA->elementos[i], resultado);
        }
    }
}

void interseccao(conjuntoDeInt *conjuntoA, conjuntoDeInt *conjuntoB,
                 conjuntoDeInt *resultado)
{

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        int aux = verificaElemento(conjuntoA->elementos[i], conjuntoB);
        if (aux == 1)
        {
            insereElemento(conjuntoA->elementos[i], resultado);
        }
    }
}

int saoIguais(conjuntoDeInt *conjuntoA, conjuntoDeInt *conjuntoB)
{
    if (conjuntoA->tamanho != conjuntoB->tamanho)
    {
        return 0;
    }

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        int aux = verificaElemento(conjuntoA->elementos[i], conjuntoB);
        if (aux == 0)
        {
            return 0; // Elemento de A não encontrado em B
        }
    }

    return 1; // Os conjuntos são iguais
}

int maiorValor(conjuntoDeInt *conjunto)
{
    int maior = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] > maior)
        {
            maior = conjunto->elementos[i];
        }
    }

    return maior;
}

int menorValor(conjuntoDeInt *conjunto)
{
    int menor = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] < menor)
        {
            menor = conjunto->elementos[i];
        }
    }

    return menor;
}