#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"


Cubo *criarCubo(double lado){
    Cubo *cubo = (Cubo*)malloc(sizeof(Cubo));
    cubo->lado = lado;
    return cubo;
}

void destruirCubo(Cubo* cubo) {
    free(cubo);
}

double obterLado(Cubo* cubo) {
    return cubo->lado;
}

double obterArea(Cubo* cubo) {
    return 6 * cubo->lado * cubo->lado;
}

double obterVolume(Cubo* cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}