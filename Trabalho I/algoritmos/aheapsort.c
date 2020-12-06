#include <stdio.h>

// ESSE DAQUI TA DANDO TRETA
void heapify(int arr[], int n, int i);
void heapsort(int a[], int n);

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

void heapify(int arr[], int n, int i)
{
    int largest, l, r;

    largest = i;   // Initialize largest as root
    l = 2 * i + 1; // left = 2*i + 1
    r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l <= n && arr[l] > arr[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    // If right child is larger than largest so far
    if (r <= n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = arr[i];

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapsort(int a[], int n)
{
    int i;
    // Build heap (rearrange array)
    for (i = (n / 2) - 1; i > 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (i = n - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        n--;

        // call max heapify on the reduced heap
        heapify(a, n, 0);
    }
}