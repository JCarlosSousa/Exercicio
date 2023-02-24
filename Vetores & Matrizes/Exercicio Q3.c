#include<stdio.h>
#include<stdlib.h>

/*3. Faça um programa que recebe nomes de frutas e seu preço. A quantidade frutas deve ser informada
pelo o usuário. Utilize alocação dinâmica, especialmente a função realloc para não desperdiçar
memória.*/
  
int main(void){
	int quantidade;
	printf("Digite a quantidade de frutas: ");
	scanf("%d", &quantidade);
    	char **frutas = (char**) malloc(quantidade*sizeof(char*));
    	if(frutas == NULL){
    		exit(1);
	}
	
	int linha, coluna;
	for(linha = 0; linha < quantidade; linha++){
		frutas[linha] = (char*) malloc(50*sizeof(char));
	}
	
	float *preco = (float*) malloc(quantidade*sizeof(float));
	if (preco == NULL){
		exit(1);
	}
	
	for(linha = 0; linha < quantidade; linha++){
		fflush(stdin);
		printf("Informe o nome da fruta: \n");
		scanf("%[^\n]s", frutas[linha]);
		fflush(stdin);
		printf("Informe o valor da fruta: \n");
		scanf("%f", &preco[linha]);	
	}
	
	int nova_quantidade;
	prinft("Digite a nova quantidade de frutas: ");
	scanf("%d", &nova_quantidade);
	char **frutas = (char*) realloc(**frutas, nova_quantidade*sizeof(char*));
	
	for(linha = 0; linha < quantidade; linha++){
		free(frutas[linha]);
	}
	
	free(frutas);
	free(preco);
	return 0;
}
