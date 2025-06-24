#include "populacao.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool populacao_create(TSDoubleList *lista, Labirinto *mapa, Stack *pilha, char *tipo_geracao, int tam_populacao, int max_movimentos) {
    
    for (int i = 0; i < tam_populacao; i++) {
        TGenotipo *aux = TGenotipo_create(max_movimentos);
        if (aux == NULL) return false;

        if (strcmp(tipo_geracao, "aleatorio") == 0) {
            individuo_aleatorio(aux);
        } else {
            individuo_inteligente(aux, mapa, pilha);
        }

        Posicao posicao_final;
        int colisoes = simular_caminho(mapa, aux, &posicao_final);
        aux->posicao = posicao_final;
        calcular_fitness(mapa, aux, &posicao_final);

        list_insert(lista, aux);
    }

    return true;
}
 void populacao_print(TSDoubleList *lista){
    TNo *aux = lista->inicio;
    int i = 0;
    while (aux != NULL) {

        printf("\n->Individuo [%d]:", i);
        printf("(%d, %d), %.2f ", aux->genotipo.posicao.linha,
            aux->genotipo.posicao.linha , aux->genotipo.fitness);

        for (int j = 0; j < aux->genotipo.tam_cromossomo; j++) {
            printf("%c ", aux->genotipo.movimentos[j]);
        }
        
        aux = aux->prox;
        i++;
    }
}
 