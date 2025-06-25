#ifndef SELECAO_H
#define SELECAO_H

#include "TSDoubleList/list.h"
#include "Individuo/individuo.h"

/**
 * Seleção de um indivíduo usando a roleta;
 * @param TDoubleList* ponteiro para uma instância da lista;
 * @return Ponteiro para o nó selecionado.
 */
TNo* selecao_pais(TSDoubleList *lista );

#endif