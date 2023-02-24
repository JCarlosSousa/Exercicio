#include <stdio.h>
#include <math.h>

//Declaramos a função para calcular a area e o perimetro de um hexagono.
void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3 * pow(l, 2) * sqrt(3)) / 2;
    *perimetro = 6 * l;
}

int main(void){
    float l, area, perimetro; //Declarando variaveis do tipo float 
    printf("Digite o lado L: "); //Pedindo ao usuario para informar o lado L
    scanf("%f", &l);
    calcula_hexagono(l, &area, &perimetro); //Chamando a funcao calcula_hexagono. Como a funcao area e perimetro sao ponteiros então usamos o & para chamada da funcao.
    printf("A area do hexagono : %f\n", area); //Exibindo a area do hexagono
    printf("O perimetro do hexagono: %f\n", perimetro); //Exibindo o perimetro do hexagono
    return 0;
}
