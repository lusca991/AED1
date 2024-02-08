#include <stdio.h>
#include "arvore_binaria.h"

int main() {

    ArvoreBinaria* arvore = inicializarArvore();

    inserirElemento(arvore, 24);
    inserirElemento(arvore, 10);
    inserirElemento(arvore, 32);
    inserirElemento(arvore, 5);
    inserirElemento(arvore, 12);
    inserirElemento(arvore, 29);
    inserirElemento(arvore, 35);

    printf("Arvore em ordem crescente: ");
    imprimirArvore(arvore->raiz);
    printf("\n");

    printf("Numero de elementos na arvore: %d\n", contarElementos(arvore->raiz));

    int chaveBusca = 12;
    NoArvore* resultadoBusca = buscarElemento(arvore->raiz, chaveBusca);
    if (resultadoBusca != NULL) {
        printf("Elemento %d encontrado na arvore.\n", chaveBusca);
    } else {
        printf("Elemento %d não encontrado na arvore.\n", chaveBusca);
    }

    printf("Pre-fixa: ");
    preOrdem(arvore->raiz);
    printf("\n");

    printf("Infixa: ");
    emOrdem(arvore->raiz);
    printf("\n");

    printf("Pos-fixa: ");
    posOrdem(arvore->raiz);
    printf("\n");

    free(arvore);

    return 0;
}
