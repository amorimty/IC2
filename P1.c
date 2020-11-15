#include <stdio.h>

// Esta função recebe um inteiro x
// e um vetor crescente v[0..n-1]
// e devolve um índice j em 0..n
// tal que v[j-1] < x <= v[j].

int buscaBinaria(int x, int n, int v[])
{
   int L = 0, R = n - 1; // atenção!

   while (L < R)
   {
      int m = (L + R) / 2;
      if (v[m] < x)
         L = m + 1;
      else
         R = m;
   }
   return R;
}

// Esta função recebe um inteiro x e um vetor
// crescente v[0..n-1] e devolve um índice j
// em 0..n tal que v[j-1] < x <= v[j].

int buscaSequencial(int x, int n, int v[])
{
   int j = 0;
   while (j < n && v[j] < x)
      ++j;
   return j;
}



int buscaElemRepet(int x, int n, int v[]) 
//A primeira parte do código é O(log_2 n) e a segunda O(n), então o programa é O(n)
{
   int L = 0, R = n - 1;
   int j, k;

   while (L < R)
   {
      int m = (L + R) / 2;

      if (v[m] < x)
         L = m + 1;
      else
         R = m;
   }

   if (v[R] != x)
   {
      printf("chave não encontrada\n");
      return -1;
   }
   else
   {
      j = R;
   }
   

   //buscar na frente
   while (j < n && v[j] == x) //se eu deixar o && v[j] == x não vou saber dizer se é O(n)
   {
      if (v[j] == x)
      {
         printf("Temos uma chave no indice %d\n", j);
      }
      ++j;
   }

   j = R;

   //buscar para trás
   while (j >= 0 && v[j] == x)
   {
      if (v[j-1] == x)
      {
         printf("Temos uma chave no indice %d\n", j);
      }
      --j;
   }
}
//numero usp 11795871

//funçao recursiva
int recF(int n)
{
   if (n == 1)
   {
      return 2;
   }
   else if (n > 1)
   {
      return(1.005*(recF(n-1) + 100));
   }
}

//função não recursiva
int F(int n)
{
   int soma = 2;

   if (n == 1)
   {
      return 2;
   }
   else if (n > 1)
   {
      for (int i = 1; i < n; i++)
      {
         soma = 1.005*(soma + 100); 
      }
      return soma;
   }
   
   
}

int main()
{
   int vetor[] = {2, 4, 5, 5, 5, 5, 10, 10};

   buscaElemRepet(5, 9, vetor);
   return 0;
}