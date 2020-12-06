#include <stdio.h>

void qsort(int a[], int L, int R);

int main()
{
    int n, i;

	/*
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int array[n];

    for (i = 0; i < n; i++)
    {
        printf("\nDigite um número para o índice %d: ", i);
        scanf("%d", &array[i]);
    }
	*/

	// {7, 11, 18, 42, 43, 52, 69, 94}
	// {94, 69, 52, 43, 42, 18, 11, 7}
	// {11, 52, 43, 42, 94, 18, 7, 69}

	int array[] = {7, 11, 18, 42, 43, 52, 69, 94};
	n = 8;
	

    qsort(array, 0, n-1);

    printf("\n");

    /* imprime o vetor ordenado */
    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}


void qsort(int a[], int L, int R)
{
	int i, j, x, w, comparacao = 0, movimento = 0;
	j = R;
	i = L;
	x = a[(L + R)/2];
	movimento++;

	do
	{
		comparacao++;
		while (a[i] < x)
		{
			comparacao++;
			i++;
		}
		comparacao++;
		while (x < a[j])
		{
			comparacao++;
			j--;
		}
		if (i <= j)
		{
			movimento += 3;
			w = a[i];
			a[i] = a[j];
			a[j] = w;
			i++;
			j--;
		}

	} while (i <= j);

	if (L < j)
	{
		qsort(a, L, j);
	}
	if (i < R)
	{
		qsort(a, i, R);
	}
	printf("\nmovimentacoes = %d e comparacoes = %d", movimento, comparacao);
}