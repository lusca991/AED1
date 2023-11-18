#include <stdio.h>
#include "vetor.h"

int main (){

    vetor v1 = {2, 3, 4};
    vetor v2 = {10, 20, 30};
    vetor result_soma;

    soma(&v1, &v2, &result_soma);
    printf("Soma dos vetores: (%.2f, %.2f, %.2f)\n", result_soma.x, result_soma.y, result_soma.z);

    float resultado_escalar = produto_escalar(&v1, &v2);
    printf("Produto escalar: %.2f\n", resultado_escalar);

    return 0;
}



