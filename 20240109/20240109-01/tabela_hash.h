#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define N 101

typedef struct {
    int cod_pac;
    char *nome;
    char *cpf;
    int idade;
} Paciente;

typedef Paciente* Hash[N];

void inicializar(Hash tab);
int m_hash(int cod_pac);
int inserir(Hash tab, Paciente pac);
Paciente* busca(Hash tab, int cod_pac);
void imprimir(Hash tab);

#endif
