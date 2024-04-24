#include "inteiro.h"
#include <stdio.h>

int main()
{
    conjuntoDeInt conjuntoA;
    conjuntoDeInt conjuntoB;
    criaConjunto(&conjuntoA);
    criaConjunto(&conjuntoB);
    conjuntoDeInt resultado;
    criaConjunto(&resultado);
    int numero;
    int escolha;
    insereElemento(1, &conjuntoA);
    insereElemento(4, &conjuntoA);
    insereElemento(5, &conjuntoA);
    insereElemento(6, &conjuntoA);

    insereElemento(1, &conjuntoB);
    insereElemento(4, &conjuntoB);
    insereElemento(2, &conjuntoB);
    insereElemento(8, &conjuntoB);

    printf("----------OPERAÇÕES COM CONJUNTOS DE INTEIROS------------\n");
    printf("Conjunto A:\n");
    imprimir(&conjuntoA);
    printf("Conjunto B:\n");
    imprimir(&conjuntoB);

    printf("Menu\n");
    printf("1 - inserir elemento no conjunto A\n");
    printf("2 - inserir elemento no conjunto B\n");
    printf("3 - remover elemento no conjunto A\n");
    printf("4 - remover elemento no conjunto B\n");
    printf("5 - unir conjuntos\n");
    printf("6 - diferença entre conjuntos (A-B)\n");
    printf("7 - interseccao entre conjuntos\n");
    printf("8 - Testar se um numero pertence ao conjunto A:\n");
    printf("9 - Testar se os dois conjuntos são iguais:\n");
    printf("10 - Maior valor do conjunto A:\n");
    printf("11 - Menor valor do conjunto A:\n");
    printf("12 - Destruir conjunto A:\n");

    printf("\nDigite sua opcao\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("Escolha o numero:  ");
        scanf("%d", &numero);
        insereElemento(numero, &conjuntoA);
        imprimir(&conjuntoA);
        break;
    case 2:
        printf("Escolha o numero:  ");
        scanf("%d", &numero);
        insereElemento(numero, &conjuntoB);
        imprimir(&conjuntoB);
        break;
    case 3:
        printf("Escolha o numero:  ");
        scanf("%d", &numero);
        removeElemento(numero, &conjuntoA);
        imprimir(&conjuntoA);
        break;
    case 4:
        printf("Escolha o numero:  ");
        scanf("%d", &numero);
        removeElemento(numero, &conjuntoB);
        imprimir(&conjuntoB);
        break;
    case 5:
        uneConjuntos(&conjuntoA, &conjuntoB, &resultado);
        imprimir(&resultado);
        break;
    case 6:
        diferenca(&conjuntoA, &conjuntoB, &resultado);
        imprimir(&resultado);
    case 7:
        interseccao(&conjuntoA, &conjuntoB, &resultado);
        imprimir(&resultado);
        break;
    case 8:
        printf("\n Informe um numero:  ");
        scanf("%d", &numero);
        int aux = verificaElemento(numero, &conjuntoA);
        if (aux == 0)
        {
            printf("Não pertence ao conjunto A");
        }
        else
            printf("Pertence ao conjunto A");
        break;
    case 9:
        aux = saoIguais(&conjuntoA, &conjuntoB);
        if (aux == 0)
        {
            printf("Os conjuntos são diferentes");
        }
        else
            printf("os conjuntos são iguais");
        break;
    case 10:
        aux = maiorValor(&conjuntoA);
        printf("O maior valor do conjunto A é: %d", aux);
        break;
    case 11:
        aux = menorValor(&conjuntoA);
        printf("O menor valor do conjunto A é: %d", aux);
        break;
    case 12:
        destruir(&conjuntoA);
        imprimir(&conjuntoA);
        break;
    }

    return 0;
}
