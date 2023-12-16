#include "lista_ligada_dinamica.h"
#include <stdio.h>

int main() {
    ListaLigadaDinamica lista;
    inicializarLista(&lista);

    printf("Inserindo elementos...\n");
    inserirElemento(&lista, 30, "Joao", 20);
    inserirElemento(&lista, 20, "Maria", 22);
    inserirElemento(&lista, 40, "Carlos", 19);
    exibirLista(&lista);

    printf("\nExcluindo elemento com matrícula 20...\n");
    excluirElemento(&lista, 20);
    exibirLista(&lista);

    return 0;
}
