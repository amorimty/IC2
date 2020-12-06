#include <stdio.h>

void merge(int a[], int l, int h, int r, int c[]);
void mpas(int a[], int n, int p, int c[]);
void mergesort(int a[], int n);

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
	// {45, 56, 12, 43, 95, 19, 8, 67}
	// {8, 12, 19, 43, 45, 56, 67, 95}
	// {95, 67, 56, 45, 43, 19, 12, 8}
	// {19, 12, 8, 45, 43, 56, 67, 95}

	// {7, 11, 18, 42, 43, 52, 69, 94}
	// {94, 69, 52, 43, 42, 18, 11, 7}
	// {11, 52, 43, 42, 94, 18, 7, 69}

	int array[] = {0, 8, 12, 19, 43, 45, 56, 67, 95};
	n = 9;

	for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    mergesort(array, n);

    /* imprime o vetor ordenado */
    for (i = 1; i <= n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void merge(int a[], int l, int h, int r, int c[])
{
	int i, j, k, compar = 0, mov = 0;

	i = l;
	j = h + 1;
	k = l - 1;

	while (i <= h && j <= r)
	{
		k++;
		compar++;
		if (a[i] < a[j])
		{
			mov++;
			c[k] = a[i];
			i++;
		}
		else
		{
			mov++;
			c[k] = a[j];
			j++;
		}
	}

	while (i <= h)
	{
		mov++;
		k++;
		c[k] = a[i];
		i++;
	}
	while (j <= r)
	{
		mov++;
		k++;
		c[k] = a[j];
		j++;
	}
	printf("\ncomparacoes = %d\nmovimentacoes = %d\n", compar, mov);
}

void mpas(int a[], int n, int p, int c[])
{
	int i, j, mov = 0;
	i = 1;

	while (i <= (n - 2*p + 1))
	{
		merge(a, i, (i + p - 1), (i + 2*p - 1), c);
		i += 2*p;
	}

	if ((i + p - 1) < n)
	{
		merge(a, i, (i + p - 1), n, c);
	}

	else
	{
		for (j = i; j < n; j++)
		{
			mov++;
			c[j] = a[j];
		}
	}
	printf("\nmovimentacoes = %d\n", mov);
}

void mergesort(int a[], int n)
{
	int p, c[n];
	p = 1;
	while(p < n)
	{
		mpas(a, n, p, c);

		p = 2 * p;

		mpas(c, n, p, a);

		p = 2 * p;
	}
}

