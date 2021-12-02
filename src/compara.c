#include "aluno.h"
#include <string.h>

#define TRUE 1
#define FALSE 0


#ifndef COMPARA_C_
#define COMPARA_C_

int cmpString(void* item, void* chave) {
    ALUNO* item_temp = (ALUNO*)item;

    // strcmp retorna 0 caso as strings sejam iguais
    if (strcmp(item_temp->nome, (char*)chave) == FALSE) {  
        return TRUE;
    }

    return FALSE;
}

int cmpInt(void* item, void* chave) {
    ALUNO* item_temp = (ALUNO*)item;

    if (item_temp->idade == *(int*)chave) {
        return  TRUE;
    }
    return FALSE;
}

int cmpFloat(void* item, void* chave) {
    ALUNO* item_temp = (ALUNO*)item;

    if (item_temp->nota == *(float*)chave) {
        return TRUE;
    }
    return FALSE;
}

#endif