#ifndef DATA_H
#define DATA_H

typedef struct 
{
   int dia;
   int mes;
   int ano; 
} Data;

void Pdata(Data *data, int dia, int mes, int ano);
void imprimir(Data *data);

#endif