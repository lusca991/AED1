#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct 
{
   double real;
   double imaginario;

}Complexo;

Complexo* criarComplexo(double real, double imaginario);
void destroyComplexo(Complexo* complexo);
Complexo* somarComplexo(Complexo* complexo1, Complexo* complexo2);
Complexo* subtrairComplexo(Complexo* complexo1, Complexo* complexo2);
Complexo* multiplicarComplexo(Complexo* complexo1, Complexo* complexo2);
Complexo* dividirComplexo(Complexo* complexo1, Complexo* complexo2);

#endif