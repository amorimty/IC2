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
    int indice_menor, i, j, x, comparacao = 0, movimento = 0;

    for (i = 0; i < n - 1; i++)
    {
        indice_menor = i;

        for (j = i + 1; j < n; j++)
        {
            comparacao++;
            if (a[j] < a[indice_menor])
            {
                indice_menor = j;
            }
        }
        x = a[i];
        movimento++;
        a[i] = a[indice_menor];
        movimento++;
        a[indice_menor] = x;
        movimento++;
    }

    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);
}
