#include "crossover.h"
#include <stdlib.h>
#include <time.h>

TGenotipo* crossover(TNo* pai1, TNo* pai2, int config){

    TGenotipo* filho = TGenotipo_create(config);

    int corte = rand() % config;
    for(int i = 0; i < corte; i++ ){
         filho->movimentos[i] = pai1->genotipo.movimentos[i];
    }
    if(corte < config){

        for(int j = corte; j < config; j++){
            filho->movimentos[j] = pai2->genotipo.movimentos[j];
        }
    }
    
    return filho;

}