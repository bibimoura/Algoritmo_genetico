#ifndef MUTACAO_H
#define MUTACAO_H

#include "Individuo/individuo.h"
#include "Stack/stack.h"
#include "Arquivo/arquivo.h"

/**
 * Aplicação da mutação aleatoria no indivíduo;
 * @param TGenotipo * genotipo Ponteiro para o indivíduo;
 * @param float Taxa de mutação.
 */
void mutacao_aleatoria(TGenotipo *, float );

/**
 * Aplicação da mutação inteligente no indivíduo;
 * @param TGenotipo* genotipo Ponteiro para o indivíduo;
 * @param Stack* pilha Ponteiro para a pilha;
 * @param float Taxa mutação.
 */
void mutacao_inteligente(TGenotipo *, Stack*,  float );

#endif