//A prefeitura de uma cidade faz uma pesquisa sobre os domicílios na área urbana. Em
//cada domicilio, são coletados dados sobre renda média mensal, número total de
//ocupantes, endereço e número de ocupantes em idade escolar.

//Faça um programa que leia estes dados, faça a ordenação por inserção direta e salve
//os dados ordenados em um arquivo. Os dados devem ser ordenados de acordo
//com o endereço.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 300

void insertionSort(int arr[], int n);

int main()
{
    typedef struct
    {
        char endereco[MAXCHAR],
            renda_mensal[MAXCHAR],
            n_ocupantes[MAXCHAR],
            n_ocupantes_idade_escolar[MAXCHAR];

    } casa;

    int N = 2; //numero de casas (nesse caso, duas)
    int num_casa = 1;
    int j, i;

    FILE *arq_ogz; //arquivo a ser escrito

    casa x;
    casa c[N + 1]; // numero de casas declaradas

    //arq_ini = fopen("ende_ini.txt", "rt"); //não vai precisar desse

    arq_ogz = fopen("ende_ogz.txt", "wt+");

    if (arq_ogz == NULL)
    {
        printf("Falha ao abrir o arquivo para escrita \n");
        exit(1);
    }

    for (i = 1; i <= N; num_casa++)
    {
        printf("\nrenda mensal: ");
        scanf("%300[^\n]s%*c", c[num_casa].renda_mensal);

        printf("\nnumero de ocupantes: ");
        scanf("%300[^\n]s%*c", c[num_casa].n_ocupantes);

        printf("\nendereco: ");
        scanf("%300[^\n]s%*c", c[num_casa].endereco);

        printf("\nnumero de ocupantes em idade escolar: ");
        scanf("%300[^\n]s%*c", c[num_casa].n_ocupantes_idade_escolar);
    }

    /*
    while (num_casa <= N)
    {
        printf("\nrenda mensal: ");
        scanf("%300[^\n]s%*c", c[num_casa].renda_mensal);
        printf("\nnumero de ocupantes: ");
        scanf("%300[^\n]s%*c", c[num_casa].n_ocupantes);
        printf("\nendereco: ");
        scanf("%300[^\n]s%*c", c[num_casa].endereco);
        printf("\nnumero de ocupantes em idade escolar: ");
        scanf("%300[^\n]s%*c", c[num_casa].n_ocupantes_idade_escolar);
        num_casa++;
    }
    */

    for (i = 2; i <= N; i++)
    {
        //strcpy(x, c[i].endereco); //x = c[i].endereco;   x = a[i];
        x = c[i];

        //strcpy(c[0].endereco, x); //c[0].endereco = x; a[0] = x
        c[0] = x;

        j = i;

        while (strcmp(c[j - 1].endereco, x.endereco) > 0) //while (x < a[j - 1])
        {                                                 // strcmp(str1, str2) > 0 significa que str2 é menor que str1
            //strcpy(c[j].endereco, c[j - 1].endereco);
            c[j] = c[j - 1];
            j--;
        }
        //strcpy(c[j].endereco, x); //c[j].endereco = x;
        c[j] = x;
    }

    num_casa = 1;
    while (feof(arq_ogz) == 0)
    {
        fprintf(arq_ogz, c[num_casa].renda_mensal);
        fprintf(arq_ogz, c[num_casa].n_ocupantes);
        fprintf(arq_ogz, c[num_casa].endereco);
        fprintf(arq_ogz, c[num_casa].n_ocupantes_idade_escolar);
        num_casa++;
    }

    /*
    while (num_casa <= N + 1)
    {
        fprintf(arq_ogz, c[num_casa].renda_mensal);
        fprintf(arq_ogz, c[num_casa].n_ocupantes);
        fprintf(arq_ogz, c[num_casa].endereco);
        fprintf(arq_ogz, c[num_casa].n_ocupantes_idade_escolar);
        num_casa++;
    }
    */

    /*
    for (i = 0; i <= count; i++)
        for (j = i + 1; j <= count; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    */

    /*
    while (feof(arq_ini) == 0)
    {
        fgets(c[num_casa].renda_mensal, MAXCHAR, arq_ini);
        fgets(c[num_casa].n_ocupantes, MAXCHAR, arq_ini);
        fgets(c[num_casa].endereco, MAXCHAR, arq_ini);
        fgets(c[num_casa].n_ocupantes_idade_escolar, MAXCHAR, arq_ini);
        num_casa++;
    }
    */
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are  
            greater than key, to one position ahead  
            of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
    int i, j, N, x;
    int a[N + 1];
    for (i = 2; i <= N; i++)
    {
        x = a[i];
        a[0] = x;
        j = i;

        while (x < a[j - 1])
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = x;
*/