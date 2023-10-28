#include <stdio.h>
#include "pessoa.h"

void preencherDados(Pessoa *pessoa, const char *nome, const char *dataNascimento, const char *cpf) {
    snprintf(pessoa->nome, sizeof(pessoa->nome), "%s", nome);
    snprintf(pessoa->dataNascimento, sizeof(pessoa->dataNascimento), "%s", dataNascimento);
    snprintf(pessoa->cpf, sizeof(pessoa->cpf), "%s", cpf);
}

void imprimirDados(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s\n", pessoa->dataNascimento);
    printf("CPF: %s\n", pessoa->cpf);
}
