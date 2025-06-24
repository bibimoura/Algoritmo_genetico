#include "selecao.h"

#include <stdlib.h>
#include <time.h>
// TNo = Um elemento individual da lista

TNo* selecao_pais(TSDoubleList *lista){
   double somatorio_fitness = 0.0;
   
   TNo *atual = lista->inicio;
   while (atual != NULL) {
        somatorio_fitness += atual->genotipo.fitness;
        atual = atual->prox;
    }

    double roleta = ((double)rand() / RAND_MAX) * somatorio_fitness;

    TNo *pai = lista->inicio;
    double soma = 0.0;

    while (pai != NULL) {
        soma += pai->genotipo.fitness;

        if (soma >= roleta) {
            return pai;
        }
        pai = pai->prox;
    }
    return lista->fim; //lista->inicio; 
}