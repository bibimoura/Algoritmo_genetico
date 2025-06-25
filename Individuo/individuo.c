#include "individuo.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

TGenotipo* TGenotipo_create(unsigned int max_movimentos){
    TGenotipo *novo = malloc(sizeof(TGenotipo));

    //Definindo o estado de uma lista vazia
    if(novo){
        novo->movimentos = calloc(max_movimentos, sizeof(char));
        if(novo->movimentos == NULL)
        {
            free(novo);
            return(NULL);
        }
        novo->tam_cromossomo = max_movimentos;
        novo->fitness = 0.0;
        novo->posicao.linha = 0;
        novo->posicao.coluna = 0;
    }
    return novo;
}

void individuo_aleatorio(TGenotipo *genotipo) {
    char direcoes[4] = {'C', 'B', 'E', 'D'};
    for(int i = 0; i < genotipo->tam_cromossomo; i++ ){
        genotipo->movimentos[i] = direcoes[rand() % 4];
    }
}

void individuo_inteligente(TGenotipo *genotipo, Labirinto *mapa, Stack *pilha) {
    individuo_aleatorio(genotipo);

    int linha = mapa->inicio.linha;
    int coluna = mapa->inicio.coluna;

    for(int i = 0; i < genotipo->tam_cromossomo; i++){

        int n_linha = linha;
        int n_coluna = coluna;

        if (genotipo->movimentos[i] == 'C') n_linha--;
        else if (genotipo->movimentos[i] == 'B') n_linha++;
        else if (genotipo->movimentos[i] == 'E') n_coluna--;
        else if (genotipo->movimentos[i] == 'D') n_coluna++;

        // Bateu na parede
        if (movimento_invalido(n_linha, n_coluna, mapa)){
            Stack_push(pilha, 'P');

        } else if (movimento_inicio(n_linha, n_coluna, mapa)){
            // Voltou para o inicío
            Stack_push(pilha, 'I');

        } else {
            Stack_push(pilha, genotipo->movimentos[i]);
            linha = n_linha;
            coluna = n_coluna;
        }
    }
}

bool movimento_invalido(int linha, int coluna, Labirinto *mapa) {

    return (
        linha < 0 || linha >= mapa->linhas ||
        coluna < 0 || coluna >= mapa->colunas ||
        mapa->labirinto[linha][coluna] == '#'
    );
}

bool movimento_inicio(int linha, int coluna, Labirinto *mapa){

    return ( linha == mapa->inicio.linha && coluna == mapa->inicio.coluna);

}