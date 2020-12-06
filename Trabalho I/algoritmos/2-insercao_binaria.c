void insert_binsort(int array[], int n) //o vetor a tem que ter tamanho N + 1
{
    int i, j, x, L, R, m;

    for (i = 2; i <= n; i++)
    {
        x = array[i];
        L = 1;
        R = i;

        while (L < R)
        {
            m = (L + R) / 2;
            if (array[m] <= x)
            {
                L = m + 1;
            }
            else
            {
                R = m;
            }
        }

        j = i;

        while (j > R)
        {
            array[j] = array[j - 1];
            j--;
        }
        array[R] = x;
    }
}