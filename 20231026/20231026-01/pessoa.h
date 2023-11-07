#ifndef PESSOA_H
#define PESSOA_H

typedef struct{
    char nome[100];
    char nasc[11];
    char cpf[15];
} Pessoa;

void dados(Pessoa *pessoa, const char *nome, const char nasc, const char cpf);
void imprimir(const Pessoa *pessoa);

#endif

