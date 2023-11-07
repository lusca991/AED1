#ifndef PONTO_H
#define PONTO_H

typedef struct {
    float x;
    float y;
} Ponto;

Ponto *criar_ponto(float x, float y);
void libera_ponto (Ponto *pto);
int acessa_ponto(Ponto *pto, float *x, float *y);
int atribuir_ponto (Ponto *pto, float x, float y);
float dist_ponto (Ponto *pto1, Ponto *pto2);


#endif