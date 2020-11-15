#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 300

typedef struct
{
    char endereco[MAXCHAR],
        renda_mensal[MAXCHAR],
        n_ocupantes[MAXCHAR],
        n_ocupantes_idade_escolar[MAXCHAR];
} casa;

int main()
{

    int N; //numero de casas 
    int num_casa, j, i;

    FILE *arq_ogz; //arquivo a ser escrito

    casa x;

    printf("Numero de casas a serem cadastradas: ");
    scanf("%d%*c",&N);

    casa c[N + 1]; // numero de casas declaradas


    for (num_casa = 1; num_casa <= N; num_casa++)
    {
        printf("\nfamília %d ", num_casa);
        printf("\nrenda mensal: ");
        fgets(c[num_casa].renda_mensal, MAXCHAR, stdin);

        printf("\nnumero de ocupantes: ");
        fgets(c[num_casa].n_ocupantes, MAXCHAR, stdin);

        printf("\nendereco: ");
        fgets(c[num_casa].endereco, MAXCHAR, stdin);

        printf("\nnumero de ocupantes em idade escolar: ");
        fgets(c[num_casa].n_ocupantes_idade_escolar, MAXCHAR, stdin);
    }


    for (i = 2; i <= N; i++)
    {
        x = c[i];

        c[0] = x;

        j = i;

        while (strcmp(c[j - 1].endereco, x.endereco) > 0) 
        {                                                 
            c[j] = c[j - 1];
            j--;
        }
        c[j] = x;
    }

    arq_ogz = fopen("ende_ogz.txt", "w");

    if (arq_ogz == NULL)
    {
        printf("Falha ao abrir o arquivo para escrita \n");
        exit(1);
    }

    num_casa = 1;

    while (num_casa <= N)
    {
        fprintf(arq_ogz, c[num_casa].endereco);
        fprintf(arq_ogz, c[num_casa].renda_mensal);
        fprintf(arq_ogz, c[num_casa].n_ocupantes);
        fprintf(arq_ogz, c[num_casa].n_ocupantes_idade_escolar);
        num_casa++;
    }
    fclose(arq_ogz);

    return 0;
}
