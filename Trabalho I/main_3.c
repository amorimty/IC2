#include <stdio.h>

void ordenacao_selec(int a[], int n);

int main()
{
    int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("\nDigite um número para o índice %d: ", i);
        scanf("%d", &array[i]);
    }

    ordenacao_selec(array, n);

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void ordenacao_selec(int a[], int n)
{
    int indice_menor, i, j, x, contador_comp = 0, contador_mov = 0;

    for (i = 0; i < n - 1; i++)
    {
        indice_menor = i;

        for (j = i + 1; j < n; j++)
        {
            contador_comp++;
            if (a[j] < a[indice_menor])
            {
                indice_menor = j;
            }
        }
        x = a[i];
        a[i] = a[indice_menor];
        a[indice_menor] = x;        
        contador_mov++;
    }

    printf("\nocorreram %d comparacoes entre chaves e %d movimentacoes de registros\n", contador_comp, contador_mov);
}
