#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int L, int R)
{

	int i, j, x, comparacao = 0, movimento = 0;

	i = L;
	j = 2 * L;
	x = a[L];
    movimento++;

    comparacao++;
	if ((j < R) && (a[j] < a[j + 1]))
	{
		j++;
	}

	while ((j <= R) && (x < a[j]))
	{
        comparacao++;
        movimento++;
		a[i] = a[j];
		i = j;
		j = 2 * j;

        comparacao++;
		if ((j < R) && (a[j] < a[j + 1]))
		{
			j++;
		}
	}
    movimento++;
	a[i] = x;
    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);

}

void heapsort(int a[], int N)
{

	int L, R, m, comparacao = 0, movimento = 0;

	for (L = N / 2; L >= 1; L--)
	{
		heapify(a, L, N);
	}

	for (R = N; R >= 2; R--)
	{
        movimento += 3;
		m = a[1];
		a[1] = a[R];
		a[R] = m;

		heapify(a, 1, R - 1);
	}
    printf("\nforam %d comparacoes e %d movimentos\n", comparacao, movimento);
}

int main()
{

	// nesse daqui o vetor comeca no 1, entao declarar vetor como n+1
	int n, i;

	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);

	int array[n + 1];

	for (i = 1; i <= n; i++)
	{
		printf("\nDigite um número para o índice %d: ", i + 1);
		scanf("%d", &array[i]);
	}

	for (i = 1; i <= n; i++)
	{
		printf("vetor[%i] == %d   ", i, array[i]);
	}
	printf("\n");

    //{7, 11, 18, 42, 43, 52, 69, 94}
    //{94, 69, 52, 43, 42, 18, 11, 7}
    //{11, 52, 43, 42, 94, 18, 7, 69}
	heapsort(array, n);


	/* imprime o vetor ordenado */
	for (i = 1; i <= n; i++)
	{
		printf("vetor[%i] == %d   ", i, array[i]);
	}
	printf("\n");

	return 0;
}