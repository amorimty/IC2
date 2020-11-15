void insert_sort(int array[], int n) //o vetor a tem que ter tamanho N + 1
{
    int i, j, x;

    for (i = 2; i <= n; i++)
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


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are  
            greater than key, to one position ahead  
            of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int i, j, N, x;

    int a[N + 1];

    for (i = 2; i <= N; i++)
    {
        x = a[i];
        a[0] = x;
        j = i;

        while (x < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
    }
    
    return 0;
}
