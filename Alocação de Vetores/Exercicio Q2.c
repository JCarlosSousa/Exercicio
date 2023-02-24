#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int main (void){
    int qnt_alunos = 10; //Declarando uma variavel para a quantidade de alunos = 10
    float nota[qnt_alunos]; //Declarando um vetor para guardar a nota dos alunos
    char **alunos = (char**) malloc(qnt_alunos*sizeof(char*)); //Alocacao dinamica de uma matriz para rezervar um espaço para guardar o nome dos alunos
    int n; //Numero de questões
    int i, j; //Variavel de controle
    for(i = 0; i < qnt_alunos; i++){
        alunos[i] = (char*) malloc(20*sizeof(char));
    }
    int aprovados = 0; //Variavel indicando a quantidade de alunos aprovados
    printf("Informe a quantidade de questoes: "); //Solicitando ao usuario a quantidade de questoes
    scanf("%d", &n);
    char gabarito[n], respostas[n];  //Vetor para armazenar o gabarito e as respostas
    for(i = 0; i < n; i++){
        printf("Gabarito Questao %d: ", i+1);
        gabarito[i] = getche (); //Aqui iremos guardar o gabarito da prova. A funcao 'getche' espera o usuario digitar uma letra e retorna este caractere 
        printf("\n");
    }
    for(i = 0; i < qnt_alunos; i++){
        float nota_total = 0;
        printf("Informe o nome do aluno: ");
        scanf(" %[^\n]s", alunos[i]);
        for(j = 0; j < n; j++){
            printf("Resposta Questao %d: ",j+1);
            respostas[j] = getche (); //Aqui quando o aluno "pressionar" a letra, ele ja vai pegar a letra e colocar no gabarito.
            printf("\n");
            if(gabarito[j] == respostas[j]){  //Comparando o gabarito com as respostas do aluno
                nota_total += 10;
            }        
        }
        nota[i] = nota_total/n;  //Calculando a nota do aluno
    }

    for(i = 0; i < qnt_alunos; i++){
        printf("Aluno: %s\n", alunos[i]);
        printf("Nota: %.f\n", nota[i]);
        if(nota[i] >= 6){ //Verificando se o aluno foi aprovado
            aprovados++;
        }
    }
    printf("Aprovados = %d\%% ", (aprovados * 100) / qnt_alunos);  //Exibindo a porcentagem de alunos aprovados
    return 0;
}
