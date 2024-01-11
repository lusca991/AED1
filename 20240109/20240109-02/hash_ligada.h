#ifndef HASH_LIGADA_H
#define HASH_LIGADA_H

#define N 101

typedef struct {
    int cod_pac;
    char* nome;
    char* cpf;
    int idade;

} Paciente;

typedef struct aux{
    Paciente pac;
    struct aux* prox;  
} Elemento; 

typedef Elemento* TB_Hash[N];

int m_hash(int cod_pac);
int inserir(TB_Hash tab, Paciente pac);
int excluir(TB_Hash tab, int cod_pac);
void inicializar(TB_Hash tab);
void mostrarHash(TB_Hash tab);
Paciente* busca(TB_Hash tab, int cod_pac);

#endif

//AAAAAAAAAAAAAAAAA