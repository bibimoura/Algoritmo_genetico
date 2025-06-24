#ifndef SIMULACAO_H
#define SIMULACAO_H

#include "Mapa/mapa.h"
#include "Individuo/individuo.h"

/**
 * Simula a movimentação de um indivíduo no labirinto.
 * @param mapa Estrutura do labirinto.
 * @param genotipo Ponteiro para o genótipo.
 * @param posicao Ponteiro para armazenar a posição final do indivíduo após a simulação.
 * @return Retorna o número de colisões.
 */
int simular_caminho(Labirinto* , TGenotipo* , Posicao* );


#endif