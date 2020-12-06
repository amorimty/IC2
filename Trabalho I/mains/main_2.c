#include <stdio.h>

void insert_binsort(int array[], int n);

int main()
{
    int n, i;

    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int array[n + 1];

    for (i = 1; i <= n; i++)
    {
        printf("\nDigite um número para o índice %d: ", i);
        scanf("%d", &array[i]);
    }
    
    

    insert_binsort(array, (n + 1));

    /* imprime o vetor ordenado */
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void insert_binsort(int array[], int n) //o vetor a tem que ter tamanho N + 1
{
    int i, j, x, L, R, m, movimento = 0, comparacao = 0;

    for (i = 2; i < n; i++)
    {
        x = array[i];
        movimento++;
        L = 1;
        R = i;

        while (L < R)
        {
            m = (L + R) / 2;
            comparacao++;
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
            movimento++;
            j--;
        }
        array[R] = x;
        movimento++;
    }
    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);
}