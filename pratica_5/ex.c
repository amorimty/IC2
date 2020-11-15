#include <stdio.h>
#include <stdlib.h>




void printmatriz_quadrada(int **A, int n);
int **transposta(int **A, int n);
int isSimetric(int **A, int n);
int **matriz_multipl(int n, int **A, int **B);
int calc_traco(int **A, int n);
void desalocMatriz(int **Matriz , int linhas);
int isSimetric_alternativa(int **A, int n);





int main(void) {
	int **A, **mat1, **mat2, **tr, n = 3, i, linha, coluna; //n =  linha e colunas
	int traco;


	// alocacando a primeira matriz
	mat1 = (int **)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		mat1[i] = (int *)malloc(n*sizeof(int));
	}
	

	//alocando a segunda matriz
	mat2 = (int **)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{		
		mat2[i] = (int *)malloc(n*sizeof(int));
	}

	
	// populando as matrizes
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mat1[i][j] = i+1;
			mat2[i][j] = i+1;
		}
	}


	// print das matrizes 1 e 2
	printf("matriz 1: \n");
	printmatriz_quadrada(mat1, n);
	printf("\n\n");

	printf("matriz 2: \n");
	printmatriz_quadrada(mat2, n);
	printf("\n\n");


	//multiplicacão e print das matrizes 1 e 2
	A = matriz_multipl(n, mat1, mat2);
	
	printf("matriz resultado da multiplicacao entre a 1 e a 2: \n");
	printmatriz_quadrada(A, n);
	printf("\n\n");


	//calculo do traco
	traco = calc_traco(A, n);
	printf("o traco d amatriz A eh: %d\n", traco);
	printf("\n\n");


	// print das matriz transposta de mat1
	tr = transposta(A, n);
	printf("matriz transposta de 1: \n");
	printmatriz_quadrada(tr, n);
	printf("\n\n");
	

	//verificacao de simetria
	if (isSimetric(mat1, n) == 1)
	{
		printf("a matriz testada eh simetrica\n");
	}
	else
	{
		printf("a matriz testada não eh simetrica\n");

	}
	
	
	desalocMatriz(mat1, n);
	desalocMatriz(mat2, n);
	desalocMatriz(A, n);
	desalocMatriz(tr, n);
	
	return 0;
}




//*******************************************************************************
//FUNCOES DO EXERCÍCIO:

//funcao que verifica se é simetrica ou não
int isSimetric(int **A, int n){
	int **transposta, i, j;

	//alocando memoria pra matriz transposta
	transposta = (int **)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		transposta[i] = (int *)malloc(n*sizeof(int));
	}

	// Preenche a transposta de A[n][n] em transposta[n][n]
	for (i = 0; i < n; i++) 
			for (j = 0; j < n; j++) 
				transposta[i][j] = A[j][i]; 

	
	//realiza a comparacão entre A e transposta
    for (i = 0; i < n; i++) 
        for (j = 0; j < n; j++) 
            if (A[i][j] != transposta[i][j]) 
                return 0; 
    return 1; 
}


//calcula o resultado da multiplicação de duas matrizes A e B
int **matriz_multipl(int n, int **A, int **B){ 
	int k, i, j, **matriz;

	//alocando memoria pra matriz resultante
	matriz = (int **)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		matriz[i] = (int *)malloc(n*sizeof(int));
	}

	//calculo da multiplicacao
	for (i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			matriz[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				matriz[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return matriz;
}

//calcula o traço de uma matriz A (soma dos elementos da diagonal principal)
int calc_traco(int **A, int n){ 
	int i, j, soma = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++){
			if (j != i) break;
			
			else if (j == i){
				soma += A[i][j];
			}
		}
	
	return soma;
}


//*******************************************************************************
//*******************************************************************************
//funcoes utilizadas:

void printmatriz_quadrada(int **A, int n){
	int linha, coluna;

	for (linha = 0; linha < n; linha++)
    {
        for(coluna = 0; coluna < n; coluna++)
        {
            printf("%d     ", A[linha][coluna]);
        }
		printf("\n");
    }
}

//*******************************************************************************-
//funcao que retorna um ponteiro para a transposta de A
int **transposta(int **A, int n){
	int **transposta, i;

	//alocando memoria pra matriz
	transposta = (int **)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		transposta[i] = (int *)malloc(n*sizeof(int));
	}

	// Preenche a transposta de A[n][n] em transposta[n][n]
	for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				transposta[i][j] = A[j][i]; 

	return transposta;
}


//*******************************************************************************
//desaloca a matriz (funcao que o professor disponibilizou para nós no arquivo sobre matrizes)
void desalocMatriz(int **Matriz , int linhas){
	int i;

	for(i=0;i<linhas;i++) {
		free(Matriz[i]);
	}
}

//isSimetric mais elegante
int isSimetric_alternativa(int **A, int n){ 
	int **mtransposta;

	mtransposta = transposta(A, n); 
	

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            if (A[i][j] != mtransposta[i][j]) 
                return 0; 
    return 1; 
}