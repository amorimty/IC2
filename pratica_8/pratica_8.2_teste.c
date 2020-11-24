#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 200

typedef struct
{
    char nome[MAXCHAR];
    int n_insc;
} registro;

void bubbleSort(registro arr[], int n);
void swap(int *a, int *b);

int main()
{
    int i;
    registro vet[8];

    printf("digite os numeros do vetor\n");

    /* recebe os elementos do vetor */
    for (i = 0; i < 8; i++)
    {
        printf("\n%d = ", i);
        scanf("%d", &vet[i].n_insc);
    }

    bubbleSort(vet, 8);

    /* imprime o vetor ordenado */
    for (i = 0; i < 8; i++)
    {
        printf("%d ", vet[i].n_insc);
    }
    printf("\n");

    return 0;
}


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(registro arr[], int n)
{
    int i, j, contador_comp = 0, contador_mov = 0;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].n_insc > arr[j + 1].n_insc)
            {
                swap(&arr[j], &arr[j + 1]);
                contador_mov++;
            }
            contador_comp++;
        }
    }
    printf("\nocorreram %d comparacoes entre chaves e %d movimentacoes de registros\n", contador_comp, contador_mov);
}