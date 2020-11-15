#include <stdio.h>


int busca (int x, int n, int v[]);


int pesquisa(int *v , int n , int x )
{

    int i; 

    for (i = 0; i < n; i++) 
        if (v[i] == x) 
            return i; 

    return -1; 
}

/* Análise por operacões primitivas:

pior caso:

T(n) = 1 + 1 + (2 * (n+1)) + n + 1 = 3n + 5

melhor caso:

T(n) = 1 + 1 + (1 + 1) + 1 = 5

*/

int main()
{
    int n = 50, j, indice;
    int vetor[n];

    for (j = 0; j < n; j++)
    {
        vetor[j] = j;
    }
    
    indice = busca(4, n, vetor);

    printf("indice = %d\n", indice);

    return 0;
}


int busca (int x, int n, int v[])
{
   int k;

   k = n-1;

   while (k >= 0 && v[k] != x) //(2*(n+1)) operacoes pq a n+1 vez é pra validar o fim do loop
      k -= 1;                  //n vezes

   return k;
}





