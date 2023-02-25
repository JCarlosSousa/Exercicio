#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define MAX_VAGAS 30
#define MAX_TURMAS 3
//Definimos uma struct de alunos
typedef struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
}Aluno;
//Definimos uma struct de turma
typedef struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
}Turma;

Turma* turmas[MAX_TURMAS]; //Declarando uma variavel global do tipo struct turmas

//Função para criar uma turma
Turma* criar_turma(char id){
    int i; //Declaramos uma variavel de controle
    Turma * turma = (Turma*) malloc(sizeof(Turma)); //Alocação dinamica de vetores
    turma->id = id; //A turma->id está recebendo o id da turma
    turma->vagas = MAX_VAGAS;
    for(i=0;i<MAX_VAGAS;i++){
        turma->alunos[i] = NULL;
    }
    return turma;
}
//Funcao para imprimir as turmas
void imprime_turmas(Turma** turmas, int n){
    int i;
    printf("Listando turmas:\n");
    for(i = 0; i < n; i++){ //Laço de repetição para informar as vagas disponiveis nas turmas
        printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas); //Imprimindo todas as turmas e a quantidade de vagas disponiveis
    }
}
//Função para matricuar um aluno
void matricula_aluno(Turma* turma, int mat, char* nome){
    if(turma->vagas <= 0){ //Verificando se há vaga na turma
        printf("Turma %c lotada!\n", turma->id);
        return;
    }
    Aluno* aluno = (Aluno*)malloc(sizeof(Aluno)); //Alocação dinamica de um vetor aluno
    aluno->mat = mat; //Recebendo a matricula do aluno
    strcpy(aluno->nome, nome); //Recebendo o nome do aluno
    aluno->notas[0] = 0.0; //Atribundo 0 as notas iniciais do aluno e a media
    aluno->notas[1] = 0.0;
    aluno->notas[2] = 0.0;
    aluno->media = 0.0;
    turma->alunos[MAX_VAGAS - turma->vagas] = aluno; //Preenchendo a vaga do aluno na turma
    turma->vagas--;//Decrementando a quantidade de vagas na turma
}
//Função para lançar as notas dos alunos
void lanca_notas(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS - turma->vagas; i++) {
        Aluno* aluno = turma->alunos[i];
        float nota1, nota2, nota3; //Declarando variavel float para as 3 notas do aluno
        printf("Digite as notas do aluno %s: \n", aluno->nome); //Solicitando as notas do aluno
        scanf("%f %f %f", &nota1, &nota2, &nota3); //Recebendo as notas
        aluno->notas[0] = nota1; //Armazenando as notas do aluno
        aluno->notas[1] = nota2;
        aluno->notas[2] = nota3;
        aluno->media = (nota1 + nota2 + nota3) / 3.0; //Calculando a media das notas do aluno
        printf("Media: %1.f\n", aluno->media); //Imprimindo a media do aluno
    }
}
//Função para imprimir alunos
void imprime_alunos(Turma* turma) {
    printf("Turma %c:\n", turma->id); //Imprimindo a turma
    for (int i = 0; i < MAX_VAGAS - turma->vagas; i++) {
        Aluno* aluno = turma->alunos[i];
        printf("Matricula: %d\n", aluno->mat); //Imrpimindo a matricula do aluno
        printf("Nome: %s\n", aluno->nome); //Imprimindo o nome do aluno
        printf("Notas: %.2f %.2f %.2f\n", aluno->notas[0], aluno->notas[1], aluno->notas[2]); //Imprimindo as notas do aluno
        printf("Media: %.2f\n", aluno->media); //Imprindo a media do aluno
    }
}
//Aqui procuramos a turma e verificamos se essa turma existe ou não
Turma* procura_turma(Turma** turmas, int n, char id){
    int i;
	for(i=0;i<n;i++){
        if(turmas[i]->id == id){
            return turmas[i];
        }else{
            printf("\nTurma %c inexistente no slot %d!\n", id, i); 
            return NULL; 
        } 
    } 
}

int main(){
    //Declaração de variaveis na main
    int op, i;
    int n = 0; //Numero de turmas criadas inicializadas em 0
    char id;
    int loop = 0;
    int mat;
    char nome[50];
    Turma* turma; //Vetor auxiliar para o codigo
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\nEste programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    while(loop == 0){ //Loop para o menu
        printf("\nMENU:\n");
        printf("1- Criar turma\n");
        printf("2- Listar turmas\n");
        printf("3- Matricular aluno\n");
        printf("4- Lancar notas\n");
        printf("5- Listar alunos\n");
        printf("6- Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &op);
        switch(op){ //Utilizando um switch para as opções do menu
            case 1: //Opção para criar uma turma
                printf("Criando nova turma.\n");
                printf("Digite o ID da turma: ");
                id = toupper (getche ()); //Função getche espera o usuario retorna um caractere para o id
                turmas[n] = criar_turma(id); //Turmas recebendo um ID
                n++; //Incrementando o numero de turmas
                printf("\nTurma criada com sucesso!\n");
                break;
            case 2://Opção para imprimir as turmas
            	imprime_turmas(turmas, n); //Função para realização da opção do menu
                break;
            case 3://Opção para matricular o aluno
                printf("Matriculando aluno.\n");
                printf("Digite o ID da turma: ");
                scanf(" %c", &id);
                turma = procura_turma(&turmas, n, id); //Procurando a turma
                if(turma != NULL){ //Verificando se a turma existe
                    printf("Digite a matricula: "); //Solicitando a matricula do aluno
                    scanf("%d", &mat);
                    printf("Digite o nome: "); //Solicitando o nome do aluno
                    scanf(" %[^\n]s", nome);
                    matricula_aluno(turma, mat, nome); //Chamanda da função matricula aluno
                    break;
                }else{
                    printf("ID invalido."); //Caso o ID seja informado incorretamente ele ira exibir esta mensagem
                }
                printf("\nAluno matriculado com sucesso.\n");
                break;
            case 4: //Opção para lançar as notas
                printf("Lancando notas.\n");
                printf("Digite o ID da turma: ");
                scanf(" %c", &id);
                turma = procura_turma(&turmas, n, id);
                if(turma != NULL){
                    lanca_notas(turma); //Chamada da função lançar notas
                }else{
                    printf("ID invalido.\n");
                }
                break;
            case 5://Opção para imprimir os alunos e suas caracteristicas
                imprime_alunos(turma);//Chamanda da função imprimir alunos
                break;
            case 6://Opção de sair do programa
                printf("Obrigado por usar este programa.\n");
                exit(1);
                break;
            default:
                printf("Opcao invalida.\n"); //Caso nenhuma opção do menu seja escolhida ira exibir esta mensagem
                break;
        }
    }
    //Liberando o espaço da memoria
    for (i=0;i<MAX_TURMAS;i++){
        free(turmas[i]->alunos);
    }
    free(turmas);
    return 0;
}
