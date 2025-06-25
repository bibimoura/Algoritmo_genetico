#include "mutacao.h"
#include <time.h>
#include <stdlib.h>

void mutacao_aleatoria(TGenotipo *filho, float taxa_mutacao)
{
    char direcoes[4] = {'C', 'B', 'E', 'D'};

    for (int i = 0; i < filho->tam_cromossomo; i++)
    {
        float aleatorio = (float)rand() / RAND_MAX;
        if (aleatorio < taxa_mutacao)
        {
            filho->movimentos[i] = direcoes[rand() % 4];
        }
    }
}

void mutacao_inteligente(TGenotipo *filho, Stack *pilha, float taxa_mutacao){
    char direcoes[4] = {'C', 'B', 'E', 'D'};
    char direcoes_inicio[2] = {'B', 'E'};

    for (int i = 0; i < filho->tam_cromossomo; i++){
        float aleatorio = (float)rand() / RAND_MAX;
        if (aleatorio < taxa_mutacao){
            if (i < pilha->index){
                if (pilha->dado[i] == 'I'){
                    filho->movimentos[i] = direcoes_inicio[rand() % 2];
                }
                else if (pilha->dado[i] == 'P'){
                    filho->movimentos[i] = direcoes[rand() % 4];
                }
            }
            else{
                filho->movimentos[i] = direcoes[rand() % 4];
            }
        }
    }
}
