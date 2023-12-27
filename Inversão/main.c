#include <stdio.h>
#include "prefix.h"

int main() {
	char prefixa1[50];
	char prefixa2[50];
	
//Utilizando símbolos 
	ExpressaoInfixa* express = criarExpressao("a*((b-c)/d)");
	
	imprimirExpressao(express);
	
	infixa_to_prefixa(express, prefixa1);
	

    printf("Expressao na notacao prefixa: %s\n", prefixa1);
    
//Utilizando números
  
	ExpressaoInfixa* expressao = criarExpressao("2+2");
	
	imprimirExpressao(expressao);
	
	infixa_to_prefixa(expressao, prefixa2);
	
    printf("Expressao na notacao prefixa: %s\n", prefixa2);
    
    int resultado = calcula_prefixa(prefixa2);
    
    printf("Resultado da expressao: %d", resultado);

    return 0;
}
