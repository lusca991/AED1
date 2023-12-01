#include "lista_ligada_estatica.h"
#include <stdio.h>

int main() {
    ListaLigadaEstatica lista;
    inicializarLista(&lista);


    printf("Lista Original:\n");
    exibirLista(&lista);

    percorrerListaConstruirL1a(&lista);
    printf("\nLista após operação a):\n");
    exibirLista(&lista);

    percorrerListaConstruirL1b(&lista);
    printf("\nLista após operação b):\n");
    exibirLista(&lista);

    return 0;
}
