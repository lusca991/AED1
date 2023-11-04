#ifndef ALUNO_H
#define ALUNO_H

typedef struct {
    int codigo;
    char nome[100];
    int idade;
    float coeficiente;
} Aluno;

Aluno criarAluno(int codigo, const char *nome, int idade, float coeficiente);

#endif
