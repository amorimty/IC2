#include<stdio.h>



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