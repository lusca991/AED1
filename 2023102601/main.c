#include <stdio.h>
#include "pessoa.h"

int main() {
    Pessoa pessoa1;
    Pessoa *ponteiroPessoa = &pessoa1;

    preencherDados(ponteiroPessoa, "Lucas Viana", "15/11/1993", "555.555.555-55");
    imprimirDados(ponteiroPessoa);

    return 0;
}
