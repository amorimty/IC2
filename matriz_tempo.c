#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Alocacao dinamica de matriz de floats  
double **alocMatriz(int linhas , int colunas){
	int i;
	double **Matriz;

	Matriz = (double **)malloc(linhas*sizeof(double));
	for (i = 0; i < linhas; i++) {
		Matriz[i] = (double *)malloc(colunas*sizeof(double));
	}
	if (!Matriz) {
		printf("Erro de alocacao da matriz ( %d x %d )!", linhas, colunas);
		exit(1);
	}
	return Matriz;
}


// Desalocacao dinamica de matriz de doubles  
void desalocMatriz(double **Matriz , int linhas){
	int i;

	for(i=0;i<linhas;i++) {
		free(Matriz[i]);
	}
}

// calcula media da matriz (formato original)
double mediaMatriz1(double **Matriz , int linhas , int colunas){
	int i, j;
	double S=0;
	
	for(i=0; i<linhas; i++) 
	    for(j=0; j<colunas; j++) 
	     	S=S+Matriz[i][j];

	return ( S/(linhas*colunas) );
}

// calcula media da matriz (formato vetor)
double mediaMatriz2(double *VMatriz , int linhas , int colunas){
	int i;
	double S=0;
	
	for(i=0; i<linhas*colunas; i++) 
	    S=S+VMatriz[i];

	return ( S/(linhas*colunas) );
}


main(){		
	
	int i, j, l;
	double tempo_total, **Mat, *VMat;
	clock_t tempo1, tempo2;
	
	printf("Entre com o numero de linhas e colunas da matriz quadrada: ");
	scanf("%d",&l);
	
	if (l<1 || l>10000){
		printf("Tamanho incorreto!!");
		exit(1);
		
	}
	
	// Usando Matriz no formato original
	Mat = alocMatriz(l,l);
	
	for(i=0; i<l; i++) 
	    for(j=0; j<l; j++)
	     	Mat[i][j]=rand() / (double)(RAND_MAX) ;  //  numero aleatorio entre 0 e 1

	tempo1=clock();
	
	printf("Media=%f\n", mediaMatriz1(Mat,l,l) );
	
	tempo2=clock();
	
	tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
	
	printf("Tempo=%f s \n", tempo_total);
	
	// Usando Matriz no formato de vetor
	VMat=(double *)malloc((l*l)*sizeof(double));
	if (!VMat) {
		printf("Erro de alocacao da matriz ( %d x %d )!", l, l);
		exit(1);
	}
	
	for(i=0; i<l; i++) 
	    for(j=0; j<l; j++)
	     	VMat[i*l+j]=Mat[i][j];  

	tempo1=clock();

	printf("Media=%f\n", mediaMatriz2(VMat,l,l) );
	
	tempo2=clock();
	
	tempo_total=difftime(tempo2,tempo1)/CLOCKS_PER_SEC;
	
	printf("Tempo=%f s \n", tempo_total);

	
	desalocMatriz(Mat,l);
	free(VMat);
	
}

