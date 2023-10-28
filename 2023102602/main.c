#include <stdio.h>
#include "data.h"

int main() {
    Data minhaData;

    preencherData(&minhaData, 26, 10, 2023);

    printf("Data: ");
    imprimirData(&minhaData);

    return 0;
}
