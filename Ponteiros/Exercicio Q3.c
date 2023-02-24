#include <stdio.h>

int main(void) {
 int a, b, c, d; //Declarando variaveis do tipo inteiro, a, b, c e d.
 int *p1;        //Declarando um ponteiro do tipo inteiro.
 int *p2 = &a;   //Um ponteiro p2 do tipo inteiro recebendo o endereço de a.
 int *p3 = &c;   //Um ponteiro p3 do tipo inteiro recebendo o endereço de c.
 p1 = p2;        //P1 recebe P2.
 *p2 = 10;       //P2 recebe 10.
 b = 20;         //B recebe 20.
 int **pp;       //Declarando um ponteiro para ponteiro do tipo inteiro.
 pp = &p1;       //O ponteiro para ponteiro pp esta recebendo o endereço do ponteiro p1, logo pp = 10.
 *p3 = **pp;     //O ponteiro p3 recebendo o ponteiro para ponteiro pp, logo p3 = 10.
 int *p4 = &d;   //O ponteiro p4 recebe o endereço de d, logo p4 = 0.
 *p4 = b + (*p1)++;     //O ponteiro p4 está recebendo b + o ponteiro p1, logo p4 = 30. E incrementa +1 ao p1 = 11.
 printf("A: %d\tB: %d\tC: %d\tD: %d\n", a, b, c, d);
//Valor de A = 11, B = 20, C = 10, e D = 30.
 return 0;
}
