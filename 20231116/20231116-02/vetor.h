#ifndef VETOR_H
#define VETOR_H

typedef struct 
{
    float x, y, z;
} vetor;

void soma(vetor *v1, vetor *v2, vetor *result);
float produto_escalar(vetor *v1, vetor *v2);

#endif