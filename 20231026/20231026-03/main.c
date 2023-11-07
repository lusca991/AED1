#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"

int main(){
    Cubo *meuCubo = criarCubo(3.0);
 
    double ladoCubo = obterLado(meuCubo);
    double areaCubo = obterArea(meuCubo);
    double volumeCubo = obterVolume(meuCubo);

    printf("Tamanho do lado do cubo: %.2f\n", ladoCubo);
    printf("Área do cubo: %.2f\n", areaCubo);
    printf("Volume do cubo: %.2f\n", volumeCubo);

    destoyCubo(meuCubo);

    return 0;
}