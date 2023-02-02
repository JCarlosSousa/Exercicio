#include<stdio.h>
#include<stdlib.h>

//2. Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu
respectivo índice (matriz[i][j] = i*3 + j). Em seguida, imprima a matriz.

int main(void){
    int linhas = 3, colunas = 3;
    int **matriz = (int**) malloc(linhas*sizeof(int*));
    if(matriz == NULL){
    	printf("Erro! Sem memória");
    	exit(1);
	}
    int linha;
    for(linha =0; linha < linhas; linha++){
    	matriz[linha] = (int*) malloc(colunas*sizeof(int));
	}
	int i, j;
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			matriz[i][j] = i * 3 + j;
		}
	}
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			printf("\n Matriz[%d][%d] = %d\n", i, j, matriz[i][j]);
		}
	}
	for(linha = 0; linha < linhas; linha++){
		free(matriz[linha]);
	}
	free(matriz);
	return 0;
}
