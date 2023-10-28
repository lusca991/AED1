#include <stdio.h>
#include "pessoa.h"

int main() {
    Pessoa pessoa1;
    Pessoa *ponteiroPessoa = &pessoa1;

    preencherDados(ponteiroPessoa, "João da Silva", "15/05/1990", "123.456.789-00");
    imprimirDados(ponteiroPessoa);

    return 0;
}
