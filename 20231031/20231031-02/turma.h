#ifndef TURMA_H
#define TURMA_H
#include "aluno.h"

typedef struct {
    Aluno *alunos;
    int quantidade;
} Turma;

Turma criarTurma(int quantidade);
void inserirAluno(Turma *turma, Aluno aluno);
void liberarTurma(Turma *turma);
void buscarAlunoPorCodigo(Turma *turma, int codigo);
void imprimirCodigoENomeAlunos(Turma *turma);

#endif
