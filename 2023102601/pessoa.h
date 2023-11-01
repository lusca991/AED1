#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    char nome[100];
    char dataNascimento[11]; // Formato: dd/mm/aaaa
    char cpf[12]; // Formato: xxx.xxx.xxx-xx
} Pessoa;

void preencherDados(Pessoa *pessoa, const char *nome, const char *dataNascimento, const char *cpf);
void imprimirDados(const Pessoa *pessoa);

#endif
