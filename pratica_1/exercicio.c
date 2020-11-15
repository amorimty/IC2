//Escreva um programa em C em que tenha uma função que imprima os valores e os índices do maior elemento do vetor

#include <stdio.h>
#include <stdlib.h>

int funcao_maior(int *v, int tamanho);

int funcao_menor(int *v, int tamanho);

int funcao_media(int *v, int tamanho);

int funcao_mediana(int *v, int tamanho);

//Main


int main()
{
    int *k, n, i;

    printf("tamanho do vetor: ");
    scanf("%d", &n);

    k = (int *)malloc(n*sizeof(int)); 
    
    printf("coloque os elementos do vetor: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &k[i]);
    }
    funcao_maior(k, n);
    funcao_menor(k, n);
    funcao_media(k, n);
    funcao_mediana(k, n);


    free(k);
    return 0;
}

//*************************
//**DECLARACAO DE FUNCOES**
//*************************

int funcao_maior(int *v, int tamanho)
{
    int maior, contador, index;
    maior = 0;
    contador = 0;

    while (contador < tamanho)
    {
        if (maior <= v[contador])
        {
            maior = v[contador];
            index = contador;
        }
        contador++;
    }

    
    printf("Maior valor é: %d com Índice: %d\n", maior, index);
}

//**********************************************************************

int funcao_menor(int *v, int tamanho)
{
    int menor, contador, index;
    menor = v[0];
    contador = 0;

    while (contador < tamanho)
    {
        if (menor >= v[contador])
        {
            menor = v[contador];
            index = contador;
        }
        contador++;
    }
    printf("Menor valor: %d com Índice: %d\n", menor, index);
}

//**********************************************************************


int funcao_media(int *v, int tamanho)
{
    int i;
    float soma = 0;

    for (i = 0; i < tamanho; i++)
    {
        soma += v[i];
    }
    printf("Media: %f\n", soma/tamanho);
}

//**********************************************************************


int funcao_mediana(int *v, int tamanho)
{
    float mediana;
    int index;
    int i, j, temp;

    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < (tamanho - i - 1); j++) //vai comparar as posicoes com suas conseguintes e se forem diferentes vai troca-las entre si
        {
            if (v[j] > v[j + 1]) //se a posicao j for maior q a j+1 ele vai trocar os valores dentro dessas posicoes entre si
            {
                temp = v[j]; //variavel que armazena a posicao j pra que ela possa ser trocada 

                v[j] = v[j + 1]; //troca posicao j por j+1
                v[j + 1] = temp; //troca j+1 pela posicao j armazenada
            }
        }
    }

    if (tamanho == 0)
    {
        printf("a mediana eh 0");
    }
    else if ((tamanho % 2) != 0) //se o tamanho do vetor for ímpar        ((n-1)/2)+1
    {
        index = ((tamanho - 1) / 2); //tamanho total -1 dividido por 2 para encontrar o valor do meio
        mediana = v[index];
        printf("ímpar\n");
    }
    else if ((tamanho % 2) == 0)
    {
        index = tamanho / 2; //tamanho total dividio por 2 para achar o index do maior dos dois números consecutivos que serão somados
        mediana = (float)(v[index] + v[index-1]) / 2;
    }
    printf("a mediana é %f\n", mediana);
}
