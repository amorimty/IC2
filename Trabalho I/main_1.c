#include <stdio.h>

void insert_sort(int array[], int n);

int main()
{
    int n, i;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int array[n + 1];

    for (i = 1; i <= n; i++)
    {
        printf("\nDigite um número para o índice %d: ", i);
        scanf("%d", &array[i]);
    }

    insert_sort(array, (n + 1));

    /* imprime o vetor ordenado */
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void insert_sort(int array[], int n) //o vetor a tem que ter tamanho N + 1
{
    int i, j, x;

    for (i = 2; i < n; i++)
    {
        x = array[i];
        array[0] = x;
        j = i;

        while (x < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = x;
    }
}
