#include "lista_ligada_estatica.h"
#include <stdio.h>

void inicializarLista(ListaLigadaEstatica *lista) {
    lista->quantidade = 0;
}

void exibirLista(ListaLigadaEstatica *lista) {
    printf("Lista de elementos: ");
    for (int i = 0; i < lista->quantidade; ++i) {
        printf("%d ", lista->elementos[i]);
    }
    printf("\n");
}

void percorrerListaConstruirL1a(ListaLigadaEstatica *lista) {
    if (lista->quantidade <= 1) {
        printf("A lista não possui elementos suficientes para a operação L1a.\n");
        return;
    }

    int primeiroElemento = lista->elementos[0];
    for (int i = 1; i < lista->quantidade; ++i) {
        lista->elementos[i - 1] = lista->elementos[i];
    }
    lista->elementos[lista->quantidade - 1] = primeiroElemento;
}

void percorrerListaConstruirL1b(ListaLigadaEstatica *lista) {
    if (lista->quantidade <= 1) {
        printf("A lista não possui elementos suficientes para a operação L1b.\n");
        return;
    }

    int temp[TAMANHO_MAX];
    for (int i = 0; i < lista->quantidade; ++i) {
        temp[i] = lista->elementos[i];
    }

    for (int i = 0; i < lista->quantidade; ++i) {
        lista->elementos[i] = temp[lista->quantidade - i - 1];
    }
}
