#include "lista_ligada_aluno.h"
#include <stdio.h>

int main() {
    ListaLigadaAlunos lista;
    inicializarLista(&lista);

    Aluno aluno1 = {10, "Joao", 20};
    Aluno aluno2 = {20, "Maria", 22};
    Aluno aluno3 = {15, "Carlos", 19};

    printf("Inserindo elementos...\n");
    inserirElemento(&lista, aluno1);
    inserirElemento(&lista, aluno2);
    inserirElemento(&lista, aluno3);
    exibirLista(&lista);

    printf("\nExcluindo elemento com matrícula 20...\n");
    excluirElemento(&lista, 20);
    exibirLista(&lista);

    printf("\nAlterando matrícula 15 para 25...\n");
    alterarMatricula(&lista, 15, 25);
    exibirLista(&lista);

    return 0;
}
