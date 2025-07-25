#include "fitness.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double calcular_fitness(Labirinto *mapa, TGenotipo *genotipo, Posicao *pos){

    double fitness = 100.0;

    // Distância de Manhattan
    double distancia = abs(pos->linha - mapa->final.linha) + abs(pos->coluna - mapa->final.coluna);
    fitness -= distancia;

    Posicao aux;
    int colisoes = simular_caminho(mapa, genotipo, &aux);
    fitness -= colisoes * 5;

    if (aux.linha != mapa->final.linha || aux.coluna != mapa->final.coluna) {
        fitness -= 10;
    }

    if (fitness < 0) {
        fitness = 0;
    }

    genotipo->fitness = fitness;

    return fitness;
}

