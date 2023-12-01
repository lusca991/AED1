#include "lista_aluno.h"
#include <stdio.h>

int main() {
    ListaAlunos lista;
    inicializarLista(&lista);

    printf("Inserindo elementos...\n");
    inserirElemento(&lista, 30);
    inserirElemento(&lista, 20);
    inserirElemento(&lista, 40);
    inserirElemento(&lista, 10);
    exibirLista(&lista);

    printf("\nExcluindo elemento 20...\n");
    excluirElemento(&lista, 20);
    exibirLista(&lista);

    printf("\nAlterando matrícula 30 para 25...\n");
    alterarMatricula(&lista, 30, 25);
    exibirLista(&lista);

    return 0;
}
