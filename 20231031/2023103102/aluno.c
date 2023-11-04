#include "aluno.h"
#include <string.h>

Aluno criarAluno(int codigo, const char *nome, int idade, float coeficiente) {
    Aluno aluno;
    aluno.codigo = codigo;
    strcpy(aluno.nome, nome);
    aluno.idade = idade;
    aluno.coeficiente = coeficiente;
    return aluno;
}
