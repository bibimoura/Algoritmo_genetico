#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "TSDoubleList/list.h"

/**
 * Crossover entre os pais para criar um filho;
 * @param pai1 Ponteiro para o primeiro nó pai1;
 * @param pai2 Ponteiro para o segundo nó pai2;
 * @param config Tamanho do cromossomo;
 * @return ponteiro para o genótipo do novo filho;
 */
TGenotipo* crossover(TNo*, TNo*, int);

#endif