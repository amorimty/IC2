// implementacao aula de IC2
void ordenacao_selec(int a[], int n)
{
    int indice_menor, i, j, x;

    for(i = 0; i < n-1; i++)
    {
        indice_menor = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[indice_menor])
            {
                indice_menor = i;
            }
        }
        x = a[i];
        a[i] = a[indice_menor];
        a[indice_menor] = x;
    }
}


// implementacao geek for geeks
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 

        for (j = i+1; j < n; j++) 

          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 



void selection_sort(int vetor[], int max)
{
    int i, j, min, aux;

    for (i = 0; i < (max - 1); i++)
    {
        /* O minimo é o primeiro número não ordenado ainda */
        min = i;
        for (j = i + 1; j < max; j++)
        {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (vetor[j] < vetor[min])
            {
                min = j;
            }
        }
        /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min)
        {
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
    /* Imprime o vetor ordenado */
    for (i = 0; i < max; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}