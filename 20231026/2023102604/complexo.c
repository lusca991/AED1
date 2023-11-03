#include <stdio.h>
#include <stdlib.h>
#include "complexo.h"

Complexo* criarComplexo(double real, double imaginario) {
    Complexo* complexo = (Complexo*)malloc(sizeof(Complexo));
    complexo->real = real;
    complexo->imaginario = imaginario;
    return complexo;
}

void destruirComplexo(Complexo* complexo) {
    free(complexo);
}

Complexo* somarComplexo(Complexo* complexo1, Complexo* complexo2) {
    double real = complexo1->real + complexo2->real;
    double imaginario = complexo1->imaginario + complexo2->imaginario;
    return criarComplexo(real, imaginario);
}

Complexo* subtrairComplexo(Complexo* complexo1, Complexo* complexo2) {
    double real = complexo1->real - complexo2->real;
    double imaginario = complexo1->imaginario - complexo2->imaginario;
    return criarComplexo(real, imaginario);
}

Complexo* multiplicarComplexo(Complexo* complexo1, Complexo* complexo2) {
    double real = (complexo1->real * complexo2->real) - (complexo1->imaginario * complexo2->imaginario);
    double imaginario = (complexo1->real * complexo2->imaginario) + (complexo1->imaginario * complexo2->real);
    return criarComplexo(real, imaginario);
}

Complexo* dividirComplexo(Complexo* complexo1, Complexo* complexo2) {
    double divisor = (complexo2->real * complexo2->real) + (complexo2->imaginario * complexo2->imaginario);
    double real = ((complexo1->real * complexo2->real) + (complexo1->imaginario * complexo2->imaginario)) / divisor;
    double imaginario = ((complexo1->imaginario * complexo2->real) - (complexo1->real * complexo2->imaginario)) / divisor;
    return criarComplexo(real, imaginario);
}