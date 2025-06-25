#ifndef LIST_H
#define LIST_H
#include "Individuo/individuo.h"

#include <stdbool.h>


typedef struct _no {
    TGenotipo genotipo;
    struct _no *prox, *anterior;
} TNo;


struct _list {
    TNo *inicio;
    TNo *fim;
    int totalIndividuos;
};
typedef struct _list TSDoubleList;

/**
 * Cria instâncias da lista duplamente encadeada ordenada.
 * @return TSDoubleList* ponteiro para a lista alocada.
 */
TSDoubleList* list_create();

/**
 * Gera uma população aleatória/inteligente.
 * @param TSDoubleList* ponteiro para uma instância da lista.
 * @param populacao Quantidade de indivíduos.
 * @return  bool informando o sucesso da operação.
 */
bool list_insert(TSDoubleList* , TGenotipo* );

/**
 * Cria um novo nó da lista;
 * @param TGenotipo* Ponteiro para o genótipo;
 * @return Ponteiro para o novo nó.
 */
TNo *TNo_createNFill(TGenotipo* );

#endif