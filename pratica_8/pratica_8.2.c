#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 200

typedef struct
{
    char nome[MAXCHAR];
    int n_insc;
} registro;

void ordenacao_bolha(registro a[], int n);

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

    ordenacao_bolha(vet, 8);

    /* imprime o vetor ordenado */
    for (i = 0; i < 8; i++)
    {
        printf("%d ", vet[i].n_insc);
    }
    printf("\n");

    return 0;
}

void ordenacao_bolha(registro a[], int n)
{
    int i, j, contador_comp = 0, contador_mov = 0;
    registro temp;

    for (i = 1; i < n; i++)
    {
        for (j = n; j >= i; j--)
        {
            if (a[j - 1].n_insc > a[j].n_insc)
            {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                contador_mov++;
            }
            contador_comp++;
        }
    }

    printf("\nocorreram %d comparacoes entre chaves e %d movimentacoes de registros\n", contador_comp, contador_mov);
}
