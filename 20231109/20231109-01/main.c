#include <stdio.h>
#include "operacao.h"

int main() {
    int vetor[] = {10, 5, 8, 2, 14, 7, 3};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    //encontrar o elemento máximo no vetor
    int maximo = encontraMaximo(vetor, tamanho);
    printf("Elemento máximo: %d\n", maximo);

    //encontrar o elemento mínimo no vetor
    int minimo = encontraMinimo(vetor, tamanho);
    printf("Elemento mínimo: %d\n", minimo);

    //calcular a soma dos elementos no vetor
    int soma = calculaSoma(vetor, tamanho);
    printf("Soma dos elementos: %d\n", soma);

    //calcular o produto dos elementos no vetor
    int produto = calculaProduto(vetor, tamanho);
    printf("Produto dos elementos: %d\n", produto);

    return 0;
}
