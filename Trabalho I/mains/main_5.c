#include <stdio.h>


void heapify(int array[], int L, int R);
void heapsort(int array[], int N);

int main()
{
    // nesse daqui o vetor comeca no 1, entao declarar vetor como n+1
    int n, i;

	/*
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int array[n + 1];

    for (i = 1; i <= n; i++)
    {
        printf("\nDigite um número para o índice %d: ", i + 1);
        scanf("%d", &array[i]);
    }
	*/

	// {0, 7, 11, 18, 42, 43, 52, 69, 94}
	// {0, 94, 69, 52, 43, 42, 18, 11, 7}
	// {0, 11, 52, 43, 42, 94, 18, 7, 69}

	int array[] = {0, 11, 52, 43, 42, 94, 18, 7, 69};
	n = 8;

    for (i = 1; i <= n; i++)
    {
        printf("vetor[%i] == %d   ", i, array[i]);
    }
    printf("\n");

    heapsort(array, n);

	printf("\n");

    /* imprime o vetor ordenado */
    for (i = 1; i <= n; i++)
    {
        printf("vetor[%i] == %d   ", i, array[i]);
    }
    printf("\n");

    return 0;
}

void heapify(int array[], int L, int R)
{
   
	int i, j, x, comparacao = 0, movimento = 0;

	i = L;
	j = 2 * L;
	movimento++;
	x = array[L];

	comparacao++;
	if ((j < R) && (array[j] < array[j + 1]))
	{
		j++;
	}

	while ((j <= R) && (x < array[j]))
	{
		comparacao++;
		movimento++;
		array[i] = array[j];
		i = j;
		j = 2 * j;

		comparacao++;
		if ((j < R) && (array[j] < array[j + 1]))
		{
			j++;
		}
	}
	movimento++;
	array[i] = x;
	printf("\nmovimentacoes = %d e comparacoes = %d", movimento, comparacao);
}

void heapsort(int array[], int N)
{

	int L, R, m, movimento =0;

	for (L = N / 2; L >= 1; L--)
	{
		heapify(array, L, N);
	}

	for (R = N; R >= 2; R--)
	{
		movimento += 3;
		m = array[1];
		array[1] = array[R];
		array[R] = m;

		heapify(array, 1, R - 1);
	}
	printf("\nmovimentacoes = %d", movimento);
}