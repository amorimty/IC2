#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int *prefixMedia1(int *X, int n, double *A)
{
    int i, j;
    double a;
    
    for (i = 0; i < n-1; i++)
    {
        a = 0;

        for (j = 0; j < i; j++)
            a += X[j];

        A[i] = a/(i+1);
    }   
}

int *prefixMedia2(int *X, int n, double *A)
{
    int i;
    double s;
    s = 0;

    for (i = 0; i < n-1; i++)
    {
        s += X[i];

        A[i] = s/(i+1);
    }
}

int main()
{
    int i, n = 25000;
    int X[n];
    double A[n], tempo_total;
    clock_t tempo1, tempo2;


    for ( i = 0; i < n; i++)
        X[i] = i;

    printf("n = %d\n", n);

/***********************************************************************************/
/*primeiro*/

    tempo1 = clock();

    prefixMedia1(X, n, A);
    
    tempo2 = clock();
    
	tempo_total = difftime(tempo2,tempo1)/CLOCKS_PER_SEC;

	printf("Tempo1 = %f s \n", tempo_total);

/***********************************************************************************/
/*segundo*/

    tempo1 = clock();

    prefixMedia2(X, n, A);

    tempo2 = clock();

	tempo_total = difftime(tempo2,tempo1)/CLOCKS_PER_SEC;

	printf("Tempo2 = %f s \n", tempo_total);

    return 0;
}