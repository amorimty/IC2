#include <stdio.h>

// ESSE DAQUI TA DANDO TRETA
void heapify(int array[], int L, int R);
void heapsort(int array[], int N);

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

    heapsort(array, n);

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void heapify(int array[], int L, int R)
{
    int i, j, x;

    i = L + 1;
    j = 2 * L + 1;
    x = array[L];

    if ((j < R) && (array[j] < array[j + 1]))
    {
        j++;
    }

    while ((j <= R) && (x < array[j]))
    {
        array[i] = array[j];
        i = j;
        j = j * 2;

        if ((j < R) && (array[j] < array[j + 1]))
        {
            j++;
        }
    }
    array[i] = x;
}

void heapsort(int array[], int N)
{
    int L, R, w;
    for (L = N / 2 - 1; L >= 0; L--)
    {
        heapify(array, L, N);
    }
    for (R = N - 1; R > 0; R--)
    {
        w = array[0];
        array[0] = array[R];
        array[R] = w;
        heapify(array, 1, R - 1);
    }
}