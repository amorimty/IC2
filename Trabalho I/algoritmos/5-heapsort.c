// Heapsort da aula
// faz com que o elemento em a[L], do heap dado por a[1] até a[R],
// obedeca a propriedade do heap máximo
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

/*
void heapsort_1(int array[], int L, int N)
{
    for (L = N / 2; L == 1; L--)
    {
        heapify(array, L, N);
    }
}
*/

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

// HEAPSORT DO IME -----------------------------------------------------
void troca(int A, int B)
{
    int t = A;
    A = B;
    B = t;
}

// Rearranja um vetor v[1..m] de modo a
// transformá-lo em heap.

static void constroiHeap(int m, int v[]) // static significa que não pode ser invocada diretamente pelo usuário
{
    for (int k = 1; k < m; ++k)
    {
        // v[1..k] é um heap
        int f = k + 1;
        while (f > 1 && v[f / 2] < v[f])
        {                          // 5
            troca(v[f / 2], v[f]); // 6
            f /= 2;                // 7
        }
    }
}

// Recebe um vetor v[1..m] que é um heap
// exceto talvez pelos índices 2 e 3 e
// rearranja o vetor de modo a
// transformá-lo em heap.
static void peneira(int m, int v[])
{
    int f = 2;
    while (f <= m)
    {
        if (f < m && v[f] < v[f + 1])
            ++f;
        // f é o filho mais valioso de f/2
        if (v[f / 2] >= v[f])
            break;
        troca(v[f / 2], v[f]);
        f *= 2;
    }
}

//versao melhorada da peneira
/*
static void peneira(int m, int v[])
{
    int p = 1, f = 2, x = v[1];
    while (f <= m)
    {
        if (f < m && v[f] < v[f + 1])
            ++f;
        if (x >= v[f])
            break;
        v[p] = v[f];
        p = f, f = 2 * p;
    }
    v[p] = x;
}
*/

// Rearranja os elementos do vetor v[1..n]
// de modo que fiquem em ordem crescente.
void heapsort(int n, int v[])
{
    constroiHeap(n, v);
    for (int m = n; m >= 2; --m)
    {
        troca(v[1], v[m]);
        peneira(m - 1, v);
    }
}

// heapsort do livro -----------------------------------------------------------------

// MAXHEAPIFY - mantém a propriedade de heap de máximo,
//
// Heap de Máximo: O valor de um nó é, no máximo, o valor de seu pai. Assim, o maior
// elemento em um heap de máximo é armazenado na raiz, e a subárvore
// que tem raiz em um nó contém valores menores que o próprio nó.
//
// entradas:
//      A = arranjo qualquer
//      i = índice para o arranjo
// Left(i) = 2*i
// Right(i) = 2*i + 1
void maxHeapify(int A[], int i)
{
    int l, r;
    l = 2 * i;
    r = 2 * i + 1;
}


// ACHO QUE ESSE FUNCIONA (IMPLEMENTACAO DO LIVRO) -----------------------------------------------------
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest, l, r;

    largest = i;   // Initialize largest as root
    l = 2 * i + 1; // left = 2*i + 1
    r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
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
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}