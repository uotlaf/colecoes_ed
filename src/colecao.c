#include "colecao.h"
#include <stdio.h>

#ifndef COLECAO_C_
#define COLECAO_C_

#define TRUE 1
#define FALSE 0

Colecao *colCriar(int maximoDeItens) {
    Colecao *colecao;
    
    // Tamanho da coleção deve ser sempre maior que 0
    if (maximoDeItens <= 0)
        return NULL;

    colecao = (Colecao*)malloc(sizeof(Colecao));

    if (colecao == NULL)
        return NULL;
    
    colecao->itens = (void**)malloc(sizeof(void*)*maximoDeItens);

    if (colecao->itens == NULL) {
        free(colecao);
        return NULL;
    }
    
    colecao->quantItens = 0;
    colecao->maxItens = maximoDeItens;

    return colecao;
}

int colInsert (Colecao *col, void* item) {
    if (col == NULL)
        return NULL;
    
    if (col->quantItens < col->maxItens) {
        col->itens[col->quantItens] = item;
        col->quantItens++;
        return TRUE;
    }
    return FALSE;
}

void* colRemove (Colecao *col, void* chave) {
    int data;
    if (col == NULL)
        return NULL;

    // Deve ter algo dentro da coleção pra poder tirar
    if (col->quantItens <= 0) {
        return NULL;
    }

    // Procura o primeiro valor com a chave, exclui ele da coleção e retorna ele
    for (int i = 0; i < col->quantItens; i++) {
        // Procura algum item dentro da coleção com essa chave
        if (col->itens[i] == chave) {
            // Salva ela pra retornar depois
            data = col->itens[i];
            // Pega tudo o que tem depois e reorganiza
            for (int j = i; j < col->quantItens; j++) {
                col->itens[j] = col->itens[j+1];
            }
            // Diminui a quantidade de itens do vetor
            col->quantItens--;
            return data;
        }
    }
}

void* colProcura (Colecao *col, void* chave) {
    if (col == NULL)
        return NULL;

    if (col->quantItens <= 0)
        return NULL;

    for (int i = 0; i < col->quantItens; i++) {
        if (col->itens[i] == chave) {
            return col->itens[i];
        }
    }
    return NULL;
}

void* colDestruir (Colecao *col) {
    if ( col == NULL)
        return NULL;

    if (col->quantItens != 0) // col deve estar vazio
        return FALSE;

    free(col->itens);
    free(col);
    return TRUE;
}

void* colEsvaziar (Colecao *col) {
    if (col == NULL)
        return NULL;
    
    if (col->quantItens <= 0)
        return FALSE;

    for (int i = 0; i < col->quantItens; i++) {
        colRemove(col, col->itens[i]);
    }
    colDestruir(col);
}

#endif // COLECAO_C_