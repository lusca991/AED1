#include <stdio.h>
#include <stdlib.h>
#include "hash_ligada.h"

int main (){
    TB_Hash tabela;
    Paciente p, *pr;
    inicializar (tabela);

    p.cod_pac =  1291;
    p.nome = "Aguinaldo";
    p.cpf = "00000000000";    
    p.idade = 48;
    inserir (tabela, p);

    p.cod_pac =  1191;
    p.nome = "Camilly";
    p.cpf = "00000000000";    
    p.idade = 14;
    inserir (tabela, p);

    p.cod_pac =  1089;
    p.nome = "Adriano";
    p.cpf = "00000000000";    
    p.idade = 18;
    inserir (tabela, p);

    mostrarHash (tabela);


    pr = busca (tabela, 1089);
    printf ("\nNome encontrado: %s\n", pr->nome);
}