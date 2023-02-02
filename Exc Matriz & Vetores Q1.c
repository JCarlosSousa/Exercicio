#include<stdio.h>
#include<stdlib.h>

//1. Aloque dinamicamente um vetor de inteiros de tamanho 10 e preencha cada elemento do vetor com
o seu respectivo índice (vetor[i] = i). Em seguida, imprima o vetor.

int main(void){
    int tamanho = 10, i;
    int *vetor = (int*) malloc(tamanho*sizeof(int));
    if (vetor == NULL){
	printf("Erro! Sem memória");
	exit(1);
    }
	
    for (i = 0; i < tamanho; i++){
	vetor[i] = i; 
    }
	
    for(i = 0; i < tamanho; i++){
    printf("%d\t", vetor[i]);
    }
	
    free (vetor);
    return(0);
}
