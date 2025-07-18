#ifndef FITNESS_H
#define FITNESS_H

#include "Mapa/mapa.h"
#include "Individuo/individuo.h"
#include "Simulacao/simulacao.h"
/**
 * Calcula o fitness de um indivíduo.
 * @param mapa Estrutura do labirinto contendo o final (E).
 * @param genotipo Ponteiro para o indivíduo cujo fitness será avaliado.
 * @param pos Posição final onde o indivíduo parou após a simulação.
 * @return double Retorna um valor de fitness como double.
 */
double calcular_fitness(Labirinto*, TGenotipo*, Posicao* );

#endif