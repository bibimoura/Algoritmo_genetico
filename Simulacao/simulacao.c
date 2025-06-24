#include "simulacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int simular_caminho(Labirinto *mapa, TGenotipo* genotipo, Posicao* posicao){

    Posicao atual = mapa->inicio;
    *posicao = mapa->inicio;

    
    int colisoes = 0;

    for(int i = 0; i <genotipo->tam_cromossomo; i++){
        
  
        Posicao proxima = atual; 
        char movimentos = genotipo->movimentos[i];

        if (movimentos == 'C') proxima.linha--; 
        else if (movimentos == 'B') proxima.linha++; 
        else if (movimentos == 'E') proxima.coluna--;
        else if (movimentos == 'D') proxima.coluna++; 

        if (proxima.linha < 0 || proxima.linha >= mapa->linhas || proxima.coluna < 0 || proxima.coluna >= mapa->colunas || 
            mapa->labirinto[proxima.linha][proxima.coluna] == '#'){
            colisoes++;
            break;
        }
        
        atual = proxima;
        *posicao = atual;

        if (atual.linha == mapa->final.linha && atual.coluna == mapa->final.coluna) {
            break; 
        }
    }

    return colisoes;
}
