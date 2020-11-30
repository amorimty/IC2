#include <stdio.h>

void Merge(int array[], int p, int q, int r);
void MergeSort(int array[], int p, int r);

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

    MergeSort(array, 0, n - 1);

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void Merge(int array[], int p, int q, int r)
{
    int n1, n2, i, j, k;
    int contador_comp = 0, contador_mov = 0;

    n1 = q - p + 1;
    n2 = r - q;

    // arrays temporários
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        contador_mov++;
        L[i] = array[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        contador_mov++;
        R[j] = array[q + j + 1];
    }
    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    i = 0;
    // Initial index of second subarray
    j = 0;
    // Initial index of merged subarray
    k = p;

    while (i < n1 && j < n2)
    {
        contador_comp++;
        if (L[i] <= R[j])
        {
            contador_mov++;
            array[k] = L[i];
            i++;
        }
        else
        {
            contador_mov++;
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        contador_mov++;
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        contador_mov++;
        array[k] = R[j];
        j++;
        k++;
    }
    printf("\nocorreram %d comparacoes entre chaves e %d movimentacoes de registros\n", contador_comp, contador_mov);

}

void MergeSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);
        Merge(array, p, q, r);
    }
}