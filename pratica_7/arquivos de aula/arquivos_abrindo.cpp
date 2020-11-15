// Escrita em arquivos
# include <stdio.h>
# include <stdlib.h>  // porque usei o exit
			

main () {
	FILE *arq;   // cria ponteiro para arquivo (arq)
	
	arq = fopen("alunos.txt", "w");   // abro arquivo alunos.txt no modo escrita
									  // e associo ponteiro arq 
    // verifico se ponteiro eh nulo, ou seja, nao conseguiu criar o arquivo
	if(arq == NULL){
		printf("Falha ao abrir o arquivo \n");
		exit(1);
	}
	       

	fclose(arq);  // fecha arquivo
}


