int buscaBinaria(int x, int n, int v[])
{
   int L = 0, R = n - 1;

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