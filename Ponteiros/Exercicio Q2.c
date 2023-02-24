#include <stdio.h>

int main(void) {
int x, *p;
x = 100;
p = &x;
printf("Valor de p = %p\tValor de *p = %d", p, *p);
}

//a) É uma mensagem de advertencia.

//b) Por que p deveria receber o endereço de X ja que estamos falando de ponteiro, então deveria-se estar usando o &x.

//c) Não. Está sendo exibido a mensagem de advertencia.

//d) Feito.

//e) Sim.
