#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ProcurarSenha(char *senha, int n, int identificador) /*identificador começa sendo 1*/
{
    if (identificador == n)
    {
        int sucesso = 0;
        char sb[106];

        for (int i = 0; i < 26; i++)
        {
            senha[identificador - 1] = 'A' + i;
            sucesso = system(strcat(strcpy(sb, "verif "), senha));

            if (sucesso == 1)
                return 1;
        }
    }
    else
    {
        int find;

        for (int i = 0; i < 26; i++)
        {
            senha[identificador - 1] = 'A' + i;
            find = ProcurarSenha(senha, n, identificador + 1);
            if(find == 1)
            {
                return 1;
            }
        }
    }
}

int main()
{
    char sb[106], s[100];
    char senha[100];
    int n, sucesso = 0;

    n = 3;

    sucesso = ProcurarSenha(senha, n, 1);

    printf("senha: %s\n", senha);
    printf("sucesso = %d", sucesso);
    return 0;
}