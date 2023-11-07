#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"


int main() {
    srand(time(0));

    Lista *minhaLista = criarLista(10);

    for (int i = 0; i < 10; i++) {
        int valor = rand() % 100; 
        inserirOrdenado(minhaLista, valor);
    }

printf("Elementos da Lista: ");
imprimir(minhaLista, 0); 
printf("\n");

    int busca = 42; 
    int posicao = buscaBinariaRecursiva(minhaLista, busca, 0, minhaLista->tam - 1);
    if (posicao != -1) {
        printf("Elemento %d encontrado na posição %d pela busca binária recursiva.\n", busca, posicao);
    } else {
        printf("Elemento %d não encontrado pela busca binária recursiva.\n", busca);
    }

    int maior = buscaMaior(minhaLista, 0, minhaLista->n[0]);
    printf("Maior elemento encontrado: %d\n", maior);

    int menor = buscaMenor(minhaLista, 0, minhaLista->n[0]);
    printf("Menor elemento encontrado: %d\n", menor);

    int soma = retornarSoma(minhaLista, 0);
    printf("A soma de todos os elementos: %d\n", soma);

    int produto = retornarProduto(minhaLista, 0);
    printf("O produto de todos os elementos: %d\n", produto);

    liberarLista(minhaLista);

    return 0;
}
