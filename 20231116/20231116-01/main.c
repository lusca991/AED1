#include <stdio.h>
#include "recursividade.h"

int main() {
    int numero = 2845;
    int k = 3;
    int resultado = K_esimoDigito(numero, k);

    if (resultado != -1) {
        printf("O %d-ésimo dígito de %d é: %d\n", k, numero, resultado);
    } else {
        printf("O %d-ésimo dígito não existe em %d.\n", k, numero);
    }

    return 0;
}