#include <stdio.h>
#include "recursividade.h"

int K_esimoDigito(int n, int k){
    if (k <= 0) {
        printf("Erro: k deve ser maior que 0.\n");
        return -1;
    }

    if (n == 0 && k > 0) {
        return -1;
    } 

    if (k == 1) {
        return n % 10;
    }

    return K_esimoDigito(n / 10, k - 1);
}