#include <stdio.h>
#include <math.h>

int recNum(int n)
{
    if (n == 0)
    {
        printf("%d \n", n);
    }
    else
    {
        printf("%d\n", n);
        recNum(n-1);
    }
    
}

int recNumInversa(int n)
{
    if (n == 0)
    {
        printf("%d \n", n);
    }
    else
    {
        recNum(n-1);
        printf("%d\n", n);
    }
    
}

int recNumSoma(int n, int soma)
{
    if(n == 1)
    {
        soma += n;
        return soma; 
    }
    else
    {
        soma += n;
        recNumSoma(n-1, soma);
    }
    
}

int recNumQuadrado(int n, int produto)
{
    if(n == 1)
    {
        produto *= pow(n, 2);
        return produto;
    }
    else
    {
        produto *= pow(n, 2);
        recNumQuadrado(n-1, produto);        
    }
    
}

char recVetInverso()
{

}

int recIsPrimo(int num, int n /*n tem que ser num-1 aqui*/)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        if (num % n == 0)
        {
            return 0;
        }
        else
        {
            recIsPrimo(num, n-1);
        }
    }
    
}

int main()
{

    return 0;
}