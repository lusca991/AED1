#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    int tam;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tam);

    Lista *lista1 = criarLista(tam);
    preencherValores(lista1);

    printf("Elementos da Lista 1: ");
    imprimir(lista1);

    int valorBusca;

    printf("Digite um valor para busca na Lista 1: ");
    scanf("%d", &valorBusca);

    int comparacoesSeq = 0;
    int posicaoSeq = buscarNumeroSequencial(lista1, valorBusca, &comparacoesSeq);

    if (posicaoSeq != -1) {
        printf("Elemento %d encontrado na posicao %d pela busca sequencial\n", valorBusca, posicaoSeq);
    } else {
        printf("Elemento %d não encontrado pela busca sequencial.\n", valorBusca);
    }

    Lista *lista2 = criarListaOrdenada(30);

    printf("Elementos da Lista 2: ");
    imprimir(lista2);

    printf("Digite um valor para busca na Lista 2: ");
    scanf("%d", &valorBusca);

    int comparacoesSeqOrd = 0;
    int posicaoSeqOrd = buscarNumeroSequencialOrdenada(lista2, valorBusca, &comparacoesSeqOrd);

    int comparacoesBinaria = 0;
    int posicaoBinaria = buscarNumeroBinariaIterativa(lista2, valorBusca, &comparacoesBinaria);

    if (posicaoSeqOrd != -1) {
        printf("Elemento %d encontrado na posicao %d pela busca sequencial ordenada\n", valorBusca, posicaoSeqOrd);
        printf("Comparacoes da busca sequencial ordenada: %d\n", comparacoesSeqOrd);
    } else {
        printf("Elemento %d não encontrado pela busca sequencial ordenada.\n", valorBusca);
    }

    if (posicaoBinaria != -1) {
        printf("Elemento %d encontrado na posicao %d pela busca binaria iterativa\n", valorBusca, posicaoBinaria);
        printf("Comparacoes da busca binaria iterativa: %d\n", comparacoesBinaria);
    } else {
        printf("Elemento %d não encontrado pela busca binaria iterativa.\n", valorBusca);
    }

    imprimirMaior(lista1);
    imprimirMenor(lista1);
    imprimirSoma(lista1);
    imprimirProduto(lista1);

    liberaLista(lista1);
    liberaLista(lista2);

    return 0;
}
