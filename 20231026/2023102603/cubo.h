#ifndef CUBO_H
#define CUBO_H

typedef struct 
{
 int lado;

}Cubo;

Cubo *criarCubo(double lado);
void destoyCubo(Cubo *cubo);
double obterLado(Cubo *cubo);
double obterArea(Cubo *cubo);
double obterVolume(Cubo *cubo);


#endif