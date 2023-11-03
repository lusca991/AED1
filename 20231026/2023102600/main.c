#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ponto.h"

int main (){
    
    Ponto *m_pto;
    float ext_x, ext_y;

    m_pto = criar_ponto(3.0, 2.3);

    acessa_ponto(m_pto, &ext_x, &ext_y);
    printf("\nValor de x = %f", m_pto->x);
    printf("\nValor de y = %f", m_pto->y);

    atribuir_ponto(m_pto, 5.0, 9.6);

    acessa_ponto(m_pto, &ext_x, &ext_y);

    printf("\nValor de x = %f", m_pto->x);
    printf("\nValor de y = %f\n", m_pto->y);
    
    libera_ponto(m_pto);

    printf("\nHello World!\n");
    return 0;

}