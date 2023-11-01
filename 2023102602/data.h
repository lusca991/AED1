#ifndef DATA_H
#define DATA_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

void preencherData(Data *data, int dia, int mes, int ano);
void imprimirData(Data *data);

#endif
