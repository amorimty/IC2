#include "stdio.h"
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

//int buscaBinaria(char x[], int n, casa v[]);
int buscaBinaria(char x[], int n, casa v[]);

int main()
{
    int o, num_casa_cad = 0, i, n, posi;
    // cria ponteiro para arquivo;
    FILE *arq;

    char string[MAXCHAR];

    printf("Coloque o numero inteiro de casas cadastradas: ");
    scanf("%d%*c", &n);

    casa c[n];

    if (n > 0)
    {
        // abrir arquivo para leitura do tipo texto
        arq = fopen("ende_ogz.txt", "rt");
        if (arq == NULL)
        {
            printf("erro na leitura do arquivo\n");
            exit(1);
        }
        while (feof(arq) == 0)
        {
            fgets(c[num_casa_cad].endereco, MAXCHAR, arq);
            fgets(c[num_casa_cad].renda_mensal, MAXCHAR, arq);
            fgets(c[num_casa_cad].n_ocupantes, MAXCHAR, arq);
            fgets(c[num_casa_cad].n_ocupantes_idade_escolar, MAXCHAR, arq);
            num_casa_cad++;
        }
        fclose(arq);
    }
    else
    {
        printf("\nnumero cadastrado invalido");
        exit(1);
    }

    do
    {
        printf("\n------ Escolha uma das opcoes ------");
        printf("\n1 - Listar domicilio.");
        printf("\n2 - Buscar dados do domicilio.");
        printf("\n3 - Sair");
        printf("\nOpcao = ");
        scanf("%d%*c", &o);

        switch (o)
        {
        case 1:
            printf("\n---- Domicilios Cadastrados ----");
            for (i = 0; i < n; i++)
            {
                printf("\n\ndomicilio %d", (i + 1));
                printf("\nendereco: %s", c[i].endereco);
                printf("renda mensal: %s", c[i].renda_mensal);
                printf("numero de ocupantes: %s", c[i].n_ocupantes);
                printf("numero de ocupantes em idade escolar: %s", c[i].n_ocupantes_idade_escolar);
                printf("\n");
            }
            break;
        case 2:
            printf("\n---- Busca de Domicilio ----");
            printf("\nDigite o endereco: ");
            fgets(string, MAXCHAR, stdin);
            
            posi = buscaBinaria(string, n, c);

            
            if (posi == -1)
            {
                printf("\nendereco nao encontrado");
            }
            else if (posi >= 0)
            {
                printf("\n\ndomicilio encontrado: \n");
                printf("endereco: %s", c[posi].endereco);
                printf("renda mensal: %s", c[posi].renda_mensal);
                printf("numero de ocupantes: %s", c[posi].n_ocupantes);
                printf("numero de ocupantes com idade escolar: %s", c[posi].n_ocupantes_idade_escolar);
                printf("\n\n");
            }
            
            break;
        }
    } while (o != 3);
    return 0;
}

/*
int buscaBinaria(char x[], int n, casa v[])
{
    int L = 0, R = n - 1, m; // atenção!

    while (L < R)
    {
        m = (L + R) / 2;

        if (strcmp(x, v[m].endereco) == 0)
        {
            return m;
        }
        else if (strcmp(x, v[m].endereco) > 0) //while(v[m].endereco < x)
        {
            L = m + 1;
        }
        else
        {
            R = m;
        }
    }
}
*/

int buscaBinaria(char x[], int n, casa v[])
{
    int L = 0, 
        R = n - 1; // atenção!

    while (L <= R)
    {
        int m = L + (R - L) / 2;

        int res;

        if (strcmp(x, v[m].endereco) == 0)
        {
            res = 0;
        }
        if (res == 0)
        {
            return m;
        }
        if (strcmp(x, v[m].endereco) > 0) //x > v[m].endereco
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    }
    return -1;
}

/*
int binarySearch(string arr[], string x, int n)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int res;
        if (x == (arr[m]))
            res = 0;

        // Check if x is present at mid
        if (res == 0)
            return m;

        // If x greater, ignore left half
        if (x > (arr[m]))
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    return -1;
}
*/



/*
int buscaBinaria2(int x, int n, int v[])
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
*/