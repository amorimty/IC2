#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void heapsort(int a[], int L, int R)
{

	int i, j, x;

	i = L;
	j = 2 * L;
	x = a[L];

	if ((j < R) && (a[j] < a[j + 1]))
	{
		j++;
	}

	while ((j <= R) && (x < a[j]))
	{

		a[i] = a[j];
		i = j;
		j = 2 * j;

		if ((j < R) && (a[j] < a[j + 1]))
		{
			j++;
		}
	}

	a[i] = x;
}

heapfy(int a[], int N)
{

	int L, R, m;

	for (L = N / 2; L >= 1; L--)
	{
		heapsort(a, L, N);
	}

	for (R = N; R >= 2; R--)
	{

		m = a[1];
		a[1] = a[R];
		a[R] = m;

		heapsort(a, 1, R - 1);
	}
}

int main()
{

	int v[5], size = 4;
	int i;

	srand(time(NULL));

	for (i = 1; i <= size; i++)
	{

		v[i] = rand();
		printf("vetor[%i] == %d   ", i, v[i]);
	}

	printf("\n");

	heapfy(v, size);

	for (i = 1; i <= size; i++)
	{

		printf("vetor[%i] == %d   ", i, v[i]);
	}

	return 0;
}