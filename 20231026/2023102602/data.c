#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void Pdata(Data *data, int dia, int mes, int ano){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void imprimir(Data *data){
    printf("%02d/%02d/%02d\n", data->dia, data->mes, data->ano);

}
