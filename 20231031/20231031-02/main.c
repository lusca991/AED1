#include <stdio.h>
#include "aluno.h"
#include "turma.h"

int main() {
    Turma minhaTurma = criarTurma(10);

    Aluno aluno1 = criarAluno(1, "João", 20, 8.5);
    Aluno aluno2 = criarAluno(2, "Maria", 21, 7.8);
    Aluno aluno3 = criarAluno(3, "Pedro", 22, 9.2);

    inserirAluno(&minhaTurma, aluno1);
    inserirAluno(&minhaTurma, aluno2);
    inserirAluno(&minhaTurma, aluno3);

    printf("Lista de Alunos:\n");
    imprimirCodigoENomeAlunos(&minhaTurma);

    int codigoBusca = 2;
    printf("\nBuscando aluno com código %d:\n", codigoBusca);
    buscarAlunoPorCodigo(&minhaTurma, codigoBusca);

    liberarTurma(&minhaTurma);

    return 0;
}
