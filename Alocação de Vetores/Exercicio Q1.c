#include <stdio.h>
#include <stdlib.h>

int main(void){
    //Declarando variáveis
    int i, opiniao; // i será uma variável de controle
    int mulheres = 0;
    int homens = 0;
    float percentual_homens = 0;
    float percentual_mulheres = 0;
    char sexo;
    //Solicitando o número de entrevistados
    int n;
    printf("Informe o numero de intrevistados: ");
    scanf("%d", &n);

    //Fazendo a alocação dinâmica de vetores   
    int * sex = (int*) malloc(n*sizeof(int));
    int * opiniao_entrevistados = (int*) malloc(n*sizeof(int)); 

    //Verificando se há espaço na memoria
    if(sex == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    } 
    if(opiniao_entrevistados == NULL){
        printf("Memoria insuficiente.\n");
        exit(1);
    }  
    for(i = 0; i<n; i++){
        //Solicitando o sexo dos entrevistados
        printf("Entrevistado numero %i, informe o seu sexo\n",i+1);
        printf("M = Masculino\nF = Feminino\n"); //É necessário utilizar o M ou F maiusculo para funcionar
        scanf(" %[^\n]", &sexo);
        //Checando se a opção é válida
        if( (sexo != 'M') && (sexo != 'F')){
            printf("Opcao invalida!\n");
            exit(1);
        }else{
            //Se a opção for válida continuaremos o procedimento perguntando a sua opinião sobre o produto.
            printf("Qual sua opiniao sobre o nosso produto: Digite 0 se gostou e  1 se nao gostou\n");
            scanf("%i", &opiniao);
            //Aqui novamente checamos se a opção é válida
            if((opiniao != 0) && (opiniao !=1)){
                printf("Opcao invalida!\n");
                exit(1);
            }else{
                //Utilizando o switch para a definição dos sexos.
                switch (sexo){
                case  'F':
                    sex[i]= 1;
                    break;
                case  'M':
                    sex[i]= 0;
                    break;
                default:
                    break;
                }
                opiniao_entrevistados[i] = opiniao;
                sexo = 0;
                opiniao = 0;
            }
        }
    }
    //Exibindo os resultados
    for ( i = 0; i < n; i++){
        switch (sex[i]){
        case 0:
            printf("Masculino - ");
            break;
        case 1:
            printf("Feminino - ");
            break;
        default:
            break;
        }
        switch (opiniao_entrevistados[i]){
        case 0:
            printf("Gostou\n");
            break;
        case 1:
            printf("Nao gostou\n");
            break;
        default:
            break;
        }
    }
    //Utilizamos um laço de repetição para calcular os percentuais:
    for ( i = 0; i < n; i++){
        if (sex[i]==0){
            homens+=1;
        }
        if (sex[i]==1){
            mulheres+=1;
        }
        if ((opiniao_entrevistados[i]==0)&&(sex[i]==1)){
            percentual_homens+=1;
        }
        if ((opiniao_entrevistados[i]==1)&&(sex[i]==0)){
            percentual_mulheres+=1;
        }
    }
    //Calculo dos percentuais:
    percentual_mulheres = mulheres!= 0 ? (percentual_mulheres*100)/mulheres : 0;
    percentual_homens = homens!= 0 ? (percentual_homens*100)/homens : 0;
    //Exibindo os resultados:
    printf("Mulheres que gostaram: %.1f%%\nHomens que nao gostaram: %.1f%%", percentual_mulheres, percentual_homens);
    free(sex);
    free(opiniao_entrevistados);
    return 0;
}
