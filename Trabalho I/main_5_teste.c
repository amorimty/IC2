#include <stdio.h>

// ESSE DAQUI TA DANDO TRETA
void heapify(int array[], int L, int R);
void heapsort(int array[], int N);

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

    heapsort(array, n);

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
   
	int i, j, x;

	i = L;
	j = 2 * L;
	x = array[L];

	if ((j < R) && (array[j] < array[j + 1]))
	{
		j++;
	}

	while ((j <= R) && (x < array[j]))
	{

		array[i] = array[j];
		i = j;
		j = 2 * j;

		if ((j < R) && (array[j] < array[j + 1]))
		{
			j++;
		}
	}

	array[i] = x;
}

void heapsort(int array[], int N)
{

	int L, R, m;

	for (L = N / 2; L >= 1; L--)
	{
		heapify(array, L, N);
	}

	for (R = N; R >= 2; R--)
	{

		m = array[1];
		array[1] = array[R];
		array[R] = m;

		heapify(array, 1, R - 1);
	}
}