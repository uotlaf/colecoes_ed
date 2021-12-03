#ifndef COLECAO_H_
#define COLECAO_H_

typedef struct _colecao_ {
    int quantItens;
    int maxItens;
    int atual;
    void**itens;
}Colecao;

Colecao *colCriar(int maximoDeItens);

int   colInserir   (Colecao *col, void* item);
void* colRemover   (Colecao *col, void* chave);
void* colProcura  (Colecao *col, void* chave, int(*cmp)(void*, void*));
void* colDestruir (Colecao *col);
void* colEsvaziar (Colecao *col);

#endif // COLECAO_H_