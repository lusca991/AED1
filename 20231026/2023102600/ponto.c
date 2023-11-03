#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

Ponto *criar_ponto(float x, float y){
    Ponto *out=malloc(sizeof(Ponto));
    out->x=x;
    out->y=y;
    return out;
}

void libera_ponto (Ponto *pto){
    free(pto);
}

int acessa_ponto(Ponto *pto, float *x, float *y){
    if (pto == NULL)
        return 0;
        *x= pto->x;
        *y= pto->y;
        return 1;
}

int atribuir_ponto (Ponto *pto, float x, float y){
    if (pto == NULL)
        return 0;
    pto->x=x;
    pto->y=y;
    return 1;
}

float dist_ponto (Ponto *pto1, Ponto *pto2){
    float dx, dy, dist;
    dx = pto1->x - pto2->x;
    dy = pto1->y - pto2->y;
    dist = sqrt(dx*dx + dy*dy);
    return dist;
}

