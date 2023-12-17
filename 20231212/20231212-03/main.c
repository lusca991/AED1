#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_dinamica3.h"

int main() {
    ListaDupla listaL;
    inicializarLista(&listaL);

    inserirElemento(&listaL, 30);
    inserirElemento(&listaL, 20);
    inserirElemento(&listaL, 40);

    printf("Lista L Desordenada:\n");
    exibirLista(&listaL);

    ListaDupla listaK;
    inicializarLista(&listaK);

    criarListaOrdenada(&listaL, &listaK);

    printf("Lista K Ordenada:\n");
    exibirLista(&listaK);

    return 0;
}
