#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *encontrarSubstring(char *string, char *substring, int posicao,
                        int *ocorrencias, int *contagem)
{
    int tamString = strlen(string);
    int tamSub = strlen(substring);

    if (tamString < tamSub)
    {
        return ocorrencias;
    }

    if (strncmp(string, substring, tamSub) == 0)
    {
        (*contagem)++;
        ocorrencias = (int *)realloc(ocorrencias, (*contagem) * sizeof(int));
        ocorrencias[(*contagem) - 1] = posicao;
    }

    return encontrarSubstring(string + 1, substring, posicao + 1, ocorrencias,
                              contagem);
}

int main()
{
    char string[100], substring[100];

    printf("Digite a string: ");
    scanf("%[^\n]s", string);

    printf("Digite a substring: ");
    scanf(" %s", substring);

    int contagem = 0;
    int *ocorrencias = NULL;

    printf("Ocorrências da substring na string:\n");
    ocorrencias =
        encontrarSubstring(string, substring, 0, ocorrencias, &contagem);

    if (contagem == 0)
    {
        printf("Nenhuma ocorrência encontrada.\n");
    }
    else
    {
        printf("A substring foi encontrada nas seguintes posições:\n");
        for (int i = 0; i < contagem; ++i)
        {
            printf("%d ", ocorrencias[i]);
        }
        printf("\n");
    }

    free(ocorrencias);

    return 0;
}
