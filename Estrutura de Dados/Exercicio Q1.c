#include <stdio.h>
#include <stdlib.h>

//Tipo estruturado para armazenar dados de um funcionário.

//Declarando uma struct de funcionario com varios parametros dentro.
typedef struct funcionario{
    char nome[50];
    float salario;
    int identificador;
    char cargo[20];
    float novo_salario;
}Funcionario;

int main (void){
    int qnt_funcionarios; //Declarando variavel para quantidade de funcionarios
    printf("Digite a quantidade de funcionarios: "); //Solicitando ao usuario para informar a quantidade de funcionarios
    scanf("%d", &qnt_funcionarios);
    Funcionario * vetor_funcionario = (Funcionario*) malloc(qnt_funcionarios*sizeof(Funcionario)); //Fazendo a alocação dinamica de um vetor de funcionarios
    if (vetor_funcionario == NULL){ //Verificando se há espaço na memória
        printf("Memória insuficiente.");
        exit(1);
    }

    int index; //Variavel de controle
    for (index = 0; index < qnt_funcionarios; index++){
        printf("Digite o nome do funcionario: "); //Solicitando o nome do funcionario
        scanf(" [^\n]s", vetor_funcionario[index].nome); 
        printf("Digite o salario do funcionario: "); //Solicitando o salario do funcionario
        scanf("%f", &vetor_funcionario[index].salario);
        printf("Digite o identificador do funcionario: "); //Socilitando o identificador do funcionario
        scanf("%d", &vetor_funcionario[index].identificador);
        printf("Digite o cargo do funcionario: "); //Solicitando o cargo do funcionario
        scanf(" [^\n]s", vetor_funcionario->cargo);

    for (index = 0; index < qnt_funcionarios; index++){ //Imprimindo todos os dados do funcionario da empresa
        printf("Nome do funcionario: [^\n]s", vetor_funcionario[index].nome);
        printf("Salario do funcionario: %f", &vetor_funcionario[index].salario);
        printf("Identificador do funcionario: %d", &vetor_funcionario[index].identificador);
        printf("Cargo do funcionario: [^\n]s", &vetor_funcionario[index].cargo);
    }

    for (index = 0; index < qnt_funcionarios; index++){
        printf("Digite o novo salario do funcionario: "); //Aqui iremos atribuir um novo salario para o funcionario.
        scanf("%f", &vetor_funcionario[index].novo_salario);
    }
    
        

    }

    return 0;
}
