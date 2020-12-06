/*
void particao(int array[], int N)
{
    int i, j, x, w;

    x = elem aleatorio de array[]
    
    do
    {
        while (array[i] < x)
        {
            i++;
        }
        while (x < array[j])
        {
            j--;
        }
        if (i <= j)
        {
            w = array[i];
            array[i] = array[j];
            array[j] = w;
            i++;
            j--;
        }
    }while (i <= j);
}
*/

void qsort(int array[], int L, int R)
{
    int w;
    int i = L;
    int j = R;
    int x = (L + R) / 2;

    do
    {
        while (array[i] < x)
        {
            i++;
        }
        while (x < array[j])
        {
            j--;
        }
        if (i <= j)
        {
            w = array[i];
            array[i] = array[j];
            array[j] = w;
            i++;
            j--;
        }
    } while (i <= j);

    if (L < j)
    {
        qsort(array, L, j);
    }

    if (i < R)
    {
        qsort(array, i, R);
    }
}

void quicksort(int array[], int N)
{
    qsort(array, 1, N);
}

// QUICKSORT IME

// Recebe vetor v[p..r] com p <= r. Rearranja
// os elementos do vetor e devolve j em p..r
// tal que v[p..j-1] <= v[j] < v[j+1..r].

static int separa(int v[], int p, int r)
{
    int c, t, j;
    
    c = v[r]; // pivô
    j = p;
    for (int k = p; /*A*/ k < r; ++k)
        if (v[k] <= c)
        {
            t = v[j]; 
            v[j] = v[k]; 
            v[k] = t;
            ++j;
        }
    t = v[j];
    v[j] = v[r];
    v[r] = t;
    return j;
}

// Esta função rearranja qualquer vetor
// v[p..r] em ordem crescente.

void quicksort(int v[], int p, int r)
{
    if (p < r)
    {                            // 1
        int j = separa(v, p, r); // 2
        quicksort(v, p, j - 1);  // 3
        quicksort(v, j + 1, r);  // 4
    }
}

// ALGORITMO IMPLEMENTADO DO LIVRO

int Partition(int a[], int p, int r)
{
    int x, i, j, temp;
    x = a[r];
    i = p - 1;

    for (j = p; j < r - 1; j++)
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
void Quicksort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        Quicksort(a, p, q - 1);
        Quicksort(a, q + 1, r);
    }
}