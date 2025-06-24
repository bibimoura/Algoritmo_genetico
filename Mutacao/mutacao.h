#ifndef MUTACAO_H
#define MUTACAO_H

#include "Individuo/individuo.h"
#include "Stack/stack.h"
#include "Arquivo/arquivo.h"
/**
 * 
 */
void mutacao_aleatoria(TGenotipo *, float );

/**
 * 
 */
void mutacao_inteligente(TGenotipo *, Stack*,  float );

#endif