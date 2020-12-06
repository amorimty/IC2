// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return; //returns recursively
    }
    int m = (l + r - 1) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

//algoritmo LIVRO AULA IC2
void Merge(int array[], int p, int q, int r)
{
    int n1, n2, i, j, k;

    n1 = q - p + 1;
    n2 = r - q;

    // arrays temporários
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[p + i];
    for (j = 0; j < n2; j++)
        R[j] = array[q + j + 1];

    // Merge the temp arrays back into arr[l..r]

    // Initial index of first subarray
    i = 0;
    // Initial index of second subarray
    j = 0;
    // Initial index of merged subarray
    k = p;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int array[], int p, int r)
{
    if (p >= r)
    {
        return; //returns recursively
    }
    int q = (p + r - 1) / 2;
    mergeSort(array, p, q);
    mergeSort(array, q + 1, r);
    merge(array, p, q, r);
}

//---------------------------------------------------------------------------------------------
//FUNCOES AULAS DO TINOS
void Merge(int a[], int L, int h, int R, int c[])
{
    int i, j, k;

    i = L;
    j = h + 1;
    k = L - 1;

    while ((i <= h) && (j <= R))
    {
        k++;
        if (a[i] < a[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = a[j];
            j++;
        }
    }

    while (i <= h)
    {
        k++;
        c[k] = a[i];
        i++;
    }

    while (j <= R)
    {
        k++;
        c[k] = a[j];
        j++;
    }
}

void Mpass(int a[], int N, int p, int c[])
{
    int i;

    i = 1;

    while (i <= N - 2 * p + 1)
    {
        Merge(a, i, (i + p - 1), (i + 2 * p - 1), c);
        i = i + 2 * p;
    }

    if ((i + p - 1) < N)
    {
        Merge(a, i, (i + p - 1), N, c);
    }

    else
    {
        for (int j = i; j <= N; j++)
        {
            c[j] = a[j];
        }
    }
}

void Mergesort(int a[], int N)
{
    int p, c[];
    p = 1;

    while (p < N)
    {
        Mpass(a, N, p, c);
        p = 2 * p;
        Mpass(c, N, p, a);
        p = 2 * p;
    }
}