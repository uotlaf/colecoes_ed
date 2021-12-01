#ifndef COLECAO_H_
#define COLECAO_H_

typedef struct __colecao_h_ {
    int quantItens;
    int maxItens;
    int atual;
    void* *itens;
}Colecao;

Colecao *colCriar(int maximoDeItens);

int   colInsert   (Colecao *col, void* item);
void* colRemove   (Colecao *col, void* chave);
void* colProcura  (Colecao *col, void* chave);
void* colDestruir (Colecao *col);
void* colEsvaziar (Colecao *col);

#endif // COLECAO_H_