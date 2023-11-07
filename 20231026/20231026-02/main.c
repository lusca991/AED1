#include <stdio.h>
#include "data.h"

int main(){
    Data minhaData;
    Pdata(&minhaData, 26, 10, 2023);

    printf("Data: ");
    imprimir(&minhaData);

    return 0;
}