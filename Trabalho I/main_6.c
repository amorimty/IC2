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

    //{7, 11, 18, 42, 43, 52, 69, 94}
    //{94, 69, 52, 43, 42, 18, 11, 7}
    //{11, 52, 43, 42, 94, 18, 7, 69}
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
    int comparacao = 0, movimento = 0;

    n1 = q - p + 1;
    n2 = r - q;

    // arrays temporários
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
    {
        movimento++;
        L[i] = array[p + i];
    }
    for (j = 0; j < n2; j++)
    {
        movimento++;
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
        comparacao++;
        if (L[i] <= R[j])
        {
            movimento++;
            array[k] = L[i];
            i++;
        }
        else
        {
            movimento++;
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        movimento++;
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        movimento++;
        array[k] = R[j];
        j++;
        k++;
    }
    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);

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