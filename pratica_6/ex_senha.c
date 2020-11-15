/**********************************************
	Programa: Exemplo do uso do comando verif
   			  Neste programa, o usuario 
				entra com uma senha e o 
				programa verifica se a senha 
				� correta
               
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sb[106], s[100];

int main()
{
   int n, sucesso = 0;

   printf("Entre com o tamanho da senha (maior que 1 e menor que 5): ");
   scanf("%d", &n);
   if (n < 2 || n > 5)
   {
      printf("Erro no tamanho da senha\n ");
      exit(1);
   }

   printf("Entre com a senha com %d letras maiusculas : ", n);
   scanf("%s", &s);
   ;

   sucesso = system(strcat(strcpy(sb, "verif "), s)); // verifica se s eh a senha correta
                                                      // retorna 1 em caso de sucesso
                                                      // e 0 caso contrario

   if (sucesso == 0)
      printf("Senha incorreta \n ");
   else
      printf("Sucesso! Senha: %s \n ", s);

   return (0);
}
