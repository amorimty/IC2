#include <stdio.h>

int partition(int a[], int p, int r);
void quicksort(int a[], int p, int r);

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

    quicksort(array, 0, n-1);

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


int partition(int a[], int p, int r)
{
    int x, i, j, temp;
    x = a[r];
    i = p - 1;

    for (j = p; j < r; j++)
    {
        if (a[j] <= x)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return (i + 1);
}
void quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}