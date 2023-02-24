#include <stdio.h>

int main(void) {
    int x, y, *p;
    y = 0;     // y recebe 0                                                y = 0, x = ?, p = ?
    p = &y;    // p é igual ao endereço de y                                y = 0, x = ?, p = 0
    x = *p;    // x recebe o valor que p está apontando                     y = 0, x = 0, p = 0
    x = 4;     // x recebe 4                                                y = 0, x = 4, p = 0
    (*p)++;    // soma 1 no p, fazendo que aumente o valor de y             y = 1, x = 4, p = 1
    --x;       // tira 1 do x                                               y = 1, x = 3, p = 1
    (*p) += x; // soma x no p                                               y = 4, x = 3, p = 4

    //Nota-se que quando o valor do ponteiro está mudando, Y muda igualmente, pois P está apontando para o endereço Y.

    printf("Valor de x: %d\n", x);
    printf("Valor de y: %d\n", y);
    printf("Valor de p: %d\n", *p);
    //Os Valores de x,y e p são respectivamente 3, 4 e 4.
    return 0;
}
