#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    Lista *minhaLista = criarLista(10);

    inserirElemento(minhaLista, 5);
    inserirElemento(minhaLista, 3);
    inserirElemento(minhaLista, 8);
    inserirElemento(minhaLista, 1);
    inserirElemento(minhaLista, 7);

    printf("Elementos da lista: ");
    imprimir(minhaLista);

    int valorBuscado = 3;
    int posicao = buscaBinariaRecursiva(minhaLista, valorBuscado, 0, minhaLista->tam - 1);
    if (posicao != -1) {
        printf("%d encontrado na posição %d\n", valorBuscado, posicao);
    } else {
        printf("%d não encontrado na lista\n", valorBuscado);
    }

    printf("Elementos da lista (recursivo): ");
    imprimirRecursivo(minhaLista, 0);
    printf("\n");

    int maior = buscaMaiorRecursivo(minhaLista, 0, minhaLista->n[0]);
    printf("Maior elemento: %d\n", maior);

    int menor = buscaMenorRecursivo(minhaLista, 0, minhaLista->n[0]);
    printf("Menor elemento: %d\n", menor);

    int soma = retornarSomaRecursiva(minhaLista, 0, 0);
    printf("Soma de todos os elementos: %d\n", soma);

     int produto = retornarProdutoRecursivo(minhaLista, 0, 1);
    printf("Produto de todos os elementos: %d\n", produto);

    liberaLista(minhaLista);

    return 0;
}
