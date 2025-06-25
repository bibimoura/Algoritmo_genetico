#include "elitismo.h"

#include <stdio.h>
#include <stdlib.h>

TSDoubleList* elitismo(TSDoubleList* lista, int taxa_elitismo, int tamanho_populacao) {

    int elitismo = (int)(taxa_elitismo * tamanho_populacao);
    
    // Cria uma nova lista
    TSDoubleList* melhores = list_create();
    if (melhores == NULL) return NULL;

    TNo* atual = lista->inicio;

    for (int i = 0; i < elitismo && atual != NULL; i++) {

        TGenotipo *novo = TGenotipo_create(atual->genotipo.tam_cromossomo);
        if (novo) {
            novo->fitness = atual->genotipo.fitness;
            novo->tam_cromossomo = atual->genotipo.tam_cromossomo;

            for (int j = 0; j < novo->tam_cromossomo; j++) {
                novo->movimentos[j] = atual->genotipo.movimentos[j];
            }
            list_insert(melhores, novo);
            free(novo);
        }
        atual = atual->prox;
    }
    return melhores;
}
