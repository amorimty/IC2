/*
Possua uma estrutura chamada aluno com os seguintes elementos
    Nome
    Numero USP
    Nota da primeira prova
    Nota da segunda prova
    Média Final 

Tenha um menu que permita realizar as seguintes operações
    Entrar com dados de um aluno
    Mostrar dados de um aluno
    Sair

OBS:
    procurar dados do aluno usando o número USP
    calcular a Média Final como a média aritmética entre as duas
    provas
    para testar, cadastrar 3 alunos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[200];
    int num_usp;
    float notap1, notap2, mediafinal;
} aluno;




int main()
{
    //declarando as variáveis
    int i; //variável do loop
    int a; //recebe a opcão escolhida pelo usuário
    int n = 0, nusp; //n é o número de alunos cadastrados, nusp é o numero usp que o usuário quer procurar
    int aluno_encontrado;
    aluno *alunos;

    alunos = (aluno *)malloc(100 * sizeof(aluno));

    //loop do programa
    do
    {
        printf("\nSelecione uma opcao: \n");
        printf("\n(1) Entrar com os dados do aluno\n");
        printf("(2) Mostrar dados de um aluno\n");
        printf("(0) Fechar o programa\n");
        printf("\nEscolha qual deseja selecionar: ");
        scanf("%d%*c", &a);
        printf("\n*****************************************\n");

        switch (a)
        {
        case 1:
            //caso para adicionar alunos novos
            printf("\nescreva o nome do aluno a ser registrado: ");
            scanf("%200[^\n]s%*c", alunos[n].nome);

            printf("\nescreva o número usp do aluno a ser registrado: ");
            scanf("%d", &alunos[n].num_usp);

            printf("\nescreva a nota P1 do aluno a ser registrado: ");
            scanf("%f", &alunos[n].notap1);

            printf("\nescreva a nota P2 do aluno a ser registrado: ");
            scanf("%f", &alunos[n].notap2);

            alunos[n].mediafinal = (alunos[n].notap1 + alunos[n].notap2) / 2;

            n++;

            printf("\n*****************************************\n");
            break;

        case 2:
            //caso para procurar os dados dos alunos existentes (se não houverem alunos cadastrados ele retorna ao menu inicial)
            if (n != 0)
            {
                printf("\nDigite o número usp do aluno que deseja visualizar: ");
                scanf("%d", &nusp);

                for (i = 0; i < n; i++)
                {
                    if (nusp == alunos[i].num_usp)
                    {
                        aluno_encontrado = i;
                        break;
                    }
                }

                printf("\nOs dados do aluno %d são:\n", alunos[aluno_encontrado].num_usp);
                printf("\nNome: %s", alunos[aluno_encontrado].nome);
                printf("\nP1: %f", alunos[aluno_encontrado].notap1);
                printf("\nP2 %f", alunos[aluno_encontrado].notap2);
                printf("\nMedia Final %f\n", alunos[aluno_encontrado].mediafinal);
                printf("\n*****************************************\n");

            }
            else
            {
                printf("\nAdicione um aluno antes\n");
            }

            break;
        case 0:
            break;
        }
    } while (a != 0);
    return 0;
}