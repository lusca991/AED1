#include <stdio.h>
#include <stdlib.h>
#include "hash_ligada.h"

int m_hash(int cod_pac){
    return cod_pac % N;
}

void inicializar(TB_Hash tab){
    int i;
    for (i=0; i<N; i++){
        tab[i] = NULL;
    }
}


int inserir(TB_Hash tab, Paciente pac)
{
    int h = m_hash(pac.cod_pac);
    Elemento *anterior = NULL;
    Elemento *e = tab[h];

    while (e != NULL) {
        if (e->pac.cod_pac == pac.cod_pac) {
            return 0;
        }
        anterior = e;
        e = e->prox;
    }

    e = malloc(sizeof(Elemento));
    e->pac = pac;
    e->prox = NULL;

    if (anterior == NULL) {
        tab[h] = e;
    } else {
        anterior->prox = e;
    }

    return 1;
}


Paciente* busca (TB_Hash tab, int cod_pac){
    int h = m_hash(cod_pac);
    Elemento* e = tab[h];
    while (e!=NULL){
        if (e->pac.cod_pac == cod_pac){
            return &(e->pac);
        }
        e = e->prox;
    }
    return NULL;
}

void mostrarHash(TB_Hash tab)
{
    Elemento *e;

    for (int i = 0; i < N; i++) {
        if (tab[i] != NULL) {
            e = tab[i];
            printf("\nPaciente %d: ", i);
            
            while (e != NULL) {
                printf("Nome: %s --> ", e->pac.nome);
                e = e->prox;
            }
        } else {
            printf("\nPaciente %d: NULL", i);
        }
    }
    printf("\n");
}


//AAAAAAAAAAA