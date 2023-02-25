#include <stdio.h>

struct Pessoa {
    char nome[50];
    int numero_documento;
    int idade;
};

//Função para preencher uma estrutura do tipo Pessoa
void preenche_pessoa(struct Pessoa *p) {
    printf("Digite o nome da pessoa: ");
    fgets(p->nome, 50, stdin);
    printf("Digite o número do documento: ");
    scanf("%d", &(p->numero_documento));
    printf("Digite a idade da pessoa: ");
    scanf("%d", &(p->idade));
    getchar(); // consumir o caractere de quebra de linha deixado pelo scanf
}

//Função para imprimir os valores dos campos de uma estrutura do tipo Pessoa
void imprime_pessoa(struct Pessoa *p) {
    printf("Nome: %s", p->nome);
    printf("Número do documento: %d\n", p->numero_documento);
    printf("Idade: %d\n", p->idade);
}

//Função para atualizar a idade de uma estrutura do tipo Pessoa
void atualiza_idade(struct Pessoa *p, int nova_idade) {
    p->idade = nova_idade;
}

//Função para imprimir o nome da Pessoa mais velha e mais nova em um vetor de estruturas do tipo Pessoa
void pessoa_mais_velha_nova(struct Pessoa *pessoas, int n) {
    struct Pessoa mais_velha = pessoas[0];
    struct Pessoa mais_nova = pessoas[0];

    for (int i = 1; i < n; i++) {
        if (pessoas[i].idade > mais_velha.idade) {
            mais_velha = pessoas[i];
        }
        if (pessoas[i].idade < mais_nova.idade) {
            mais_nova = pessoas[i];
        }
    }

    printf("Pessoa mais velha: %s", mais_velha.nome);
    printf("Pessoa mais nova: %s", mais_nova.nome);
}
