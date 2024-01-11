#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

void inicializar(Hash tab){
    int i;
    for (i = 0; i < N; i++)
        tab[i] = NULL;
}

int m_hash(int cod_pac){
    return (cod_pac % N);
}

int inserir(Hash tab, Paciente pac) {
    int h = m_hash(pac.cod_pac);

    while (tab[h] != NULL && tab[h]->disponivel == 0) {
        h = (h + 1) % N;
    }

    if (tab[h] == NULL || tab[h]->disponivel == 1) {
        tab[h] = malloc(sizeof(Paciente));
        *tab[h] = pac;
        tab[h]->disponivel = 0;  
        return 1;  
    }

    return 0;  
}


int excluir(Hash tab, int cod_pac) {
    int h = m_hash(cod_pac);

    while (tab[h] != NULL) {
        if (tab[h]->cod_pac == cod_pac) {
            free(tab[h]);
            tab[h]->disponivel = 1;
            return 1;  
        }
        h = (h + 1) % N;
    }

    return 0; 
}


Paciente* busca(Hash tab, int cod_pac){
    int h = m_hash(cod_pac);
    
    
    while (tab[h] != NULL){
        if (tab[h]->cod_pac == cod_pac)
            return tab[h];
        h = (h + 1) % N;
    }
    
    return NULL;  
}

void imprimir(Hash tab){
    int i;
    for (i = 0; i < N; i++){
        if (tab[i] != NULL){
            printf("\nPaciente: %d\n", i);
            printf("Código do Paciente: %d\n", tab[i]->cod_pac);
            printf("Nome do Paciente: %s\n", tab[i]->nome);
            printf("CPF: %s\n", tab[i]->cpf);
            printf("Idade: %d\n", tab[i]->idade);
        }
        else
            printf("Paciente: [%d] NULL\n", i);
    }
}


//aaaaaaaaaaaaaaaaaaaaaaaaaaaa