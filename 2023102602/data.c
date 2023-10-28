#include "data.h"
#include <stdio.h>

void preencherData(Data *data, int dia, int mes, int ano) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void imprimirData(Data *data) {
    printf("%02d/%02d/%d\n", data->dia, data->mes, data->ano);
}
