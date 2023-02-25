#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char **mat; //Declarando uma matriz
    int linhas, colunas; //Declarando linhas e colunas do tipo inteiro
    int i, j; //Variaveis de controle
    int loop = 0; //Inicializando uma variavel para um loop
    int costa_externa = 0;
    while(loop==0){//Fazendo um loop e pedindo ao usuario as linhas e colunas da matriz
        printf("Digite o numero de linhas e colunas: ");
        scanf("%d %d", &linhas, &colunas); //Armazenando as linhas e colunas
        if(linhas>=1 && colunas<= 1000){//Verificando se as linhas e colunas estão dentro da restrição declarada
            loop = 1;
        } else printf("Restrição Violada\n");//Caso seja violada a restrição ira exibir esta mensagem
    }
    mat = malloc(linhas*sizeof(char*)); //Fazendo uma alocação dinamica da matriz
    for(i=0;i<linhas;i++){
        mat[i] = malloc(colunas*sizeof(char));//Alocação da matriz por linhas
    }
    //Preenchendo a matriz
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            scanf(" %c", &mat[i][j]); //Armazenando os dados da matriz
        }
        printf("\n");
    }
    printf("Valores na matriz:\n");//Exibindo os valores da matriz
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    //Calculo das costas existentes
    for(i=0;i<linhas;i++){
        for(j=0;j<colunas;j++){
            if(mat[i][j] == '#' && ( ((i==0 || j==0) || (i==linhas-1 || j==colunas-1)) ) ) costa_externa++;
                else if ( mat[i][j] == '#' && (mat[i+1][j] == '.' || mat[i-1][j] == '.' || mat[i][j+1] == '.' || mat[i][j-1] == '.')) costa_externa++;
        }
    }
    printf("Numero de costas: %d\n", costa_externa); //Exibindo o numero de costas existentes
    //Liberando o espaço da memoria
    for(i=0;i<linhas;i++){
        free(mat[i]);//Primeiro liberando as linhas
    } 
    free(mat);//E por fim liberando as colunas
    return 0;
}
