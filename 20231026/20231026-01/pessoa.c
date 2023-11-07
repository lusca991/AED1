#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoa.h"

void dados(Pessoa *pessoa, const char *nome, const char nasc, const char cpf){
    strncpy(pessoa->nome, nome, sizeof(pessoa->nome));
    strncpy(pessoa->nasc, nasc, sizeof(pessoa->nasc));
    strncpy(pessoa->cpf, cpf, sizeof(pessoa->cpf));
}

void imprimir(const Pessoa *pessoa){
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de nascimento: %s\n", pessoa->nasc);
    printf("CPF: %szn", pessoa->cpf);
}
