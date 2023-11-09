#include "operacao.h"
#include <stdio.h>

//função para encontrar o elemento máximo em um vetor
int encontraMaximo(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    }

    int maxResto = encontraMaximo(vetor, tamanho - 1);
    return (vetor[tamanho - 1] > maxResto) ? vetor[tamanho - 1] : maxResto;
}

//função para encontrar o elemento mínimo em um vetor
int encontraMinimo(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    }

    int minResto = encontraMinimo(vetor, tamanho - 1);
    return (vetor[tamanho - 1] < minResto) ? vetor[tamanho - 1] : minResto;
}

//função para calcular a soma dos elementos em um vetor
int calculaSoma(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0;
    }

    return vetor[tamanho - 1] + calculaSoma(vetor, tamanho - 1);
}

//função para calcular o produto dos elementos em um vetor
int calculaProduto(int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 1;
    }

    return vetor[tamanho - 1] * calculaProduto(vetor, tamanho - 1);
}
