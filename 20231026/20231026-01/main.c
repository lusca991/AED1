#include <stdio.h>
#include "pessoa.h"

int main(){
    Pessoa pessoa1;

    dados(&pessoa1, "Lucas Viana", "15/11/1993", "000.000.000-55");
    imprimir(&pessoa1);

    return 0;
}