#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 200

typedef struct
{
    char nome[MAXCHAR];
    int n_insc;
} registro;

void ordenacao_selec(registro a[], int n);

int main()
{
    int i;
    registro vet[8];

    printf("digite os numeros do vetor\n");

    /* recebe os elemntos do vetor */
    for (i = 0; i < 8; i++)
    {
        printf("\n%d = ", i);
        scanf("%d%*c", &vet[i].n_insc);
    }

    ordenacao_selec(vet, 8);

    /* imprime o vetor ordenado */
    for (i = 0; i < 8; i++)
    {
        printf("%d ", vet[i].n_insc);
    }
    printf("\n");

    return 0;
}

void ordenacao_selec(registro a[], int n)
{
    int min, i, j, contador_comp = 0, contador_mov = 0;
    registro temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            contador_comp++;
            if (a[j].n_insc < a[min].n_insc)
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        contador_mov++;
    }

    printf("\nocorreram %d comparacoes entre chaves e %d movimentacoes de registros\n", contador_comp, contador_mov);
}
