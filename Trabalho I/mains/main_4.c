#include <stdio.h>

void ordenacao_bolha(int a[], int n);

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

    ordenacao_bolha(array, n);

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void ordenacao_bolha(int a[], int n)
{
    int i, j, temp, comparacao = 0, movimento = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            comparacao++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                movimento += 3;
            }
        }
    }
    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);
}
