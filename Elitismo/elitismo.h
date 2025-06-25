#ifndef ELITISMO_H
#define ELITISMO_H

#include "TSDoubleList/list.h"

/**
 * Cria uma nova lista apenas com os 50 melhores;
 * @param TSDoubleList* lista Ponteiro;
 * @param int Taxa de elitismo;
 * @param int Tamanho da população;
 * @return TSDoubleList* ponteiro para a lista alocada.
 */
TSDoubleList* elitismo(TSDoubleList* , int , int );



#endif