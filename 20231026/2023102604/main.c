#include <stdio.h>
#include "complexo.h"

int main() {
 
    Complexo* numero1 = criarComplexo(3.0, 2.0);
    Complexo* numero2 = criarComplexo(1.0, -1.0);

    Complexo* soma = somarComplexo(numero1, numero2);
    Complexo* subtracao = subtrairComplexo(numero1, numero2);
    Complexo* multiplicacao = multiplicarComplexo(numero1, numero2);
    Complexo* divisao = dividirComplexo(numero1, numero2);

    printf("Número 1: %.1lf + %.1lfi\n", numero1->real, numero1->imaginario);
    printf("Número 2: %.1lf + %.1lfi\n", numero2->real, numero2->imaginario);

    printf("Soma: %.1lf + %.1lfi\n", soma->real, soma->imaginario);
    printf("Subtração: %.1lf + %.1lfi\n", subtracao->real, subtracao->imaginario);
    printf("Multiplicação: %.1lf + %.1lfi\n", multiplicacao->real, multiplicacao->imaginario);
    printf("Divisão: %.1lf + %.1lfi\n", divisao->real, divisao->imaginario);

    destruirComplexo(numero1);
    destruirComplexo(numero2);
    destruirComplexo(soma);
    destruirComplexo(subtracao);
    destruirComplexo(multiplicacao);
    destruirComplexo(divisao);

    return 0;
}