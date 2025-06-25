#include "list.h"
#include <stdlib.h>

TSDoubleList *list_create(){
    TSDoubleList *nova = malloc(sizeof(TSDoubleList));
    if (nova)
    {
        nova->inicio = NULL;
        nova->fim = NULL;
        nova->totalIndividuos = 0;
    }

    return nova;
}

TNo *TNo_createNFill(TGenotipo *genotipo){
    
    TNo *novo = malloc(sizeof(TNo));
    if (novo){
        novo->genotipo = *genotipo;
        novo->anterior = NULL;
        novo->prox = NULL;
    }
    return novo;
}


bool list_insert(TSDoubleList *lista, TGenotipo *genotipo){
    if (lista == NULL) return false;

    TNo *aux = TNo_createNFill(genotipo);
    if (aux == NULL) return false;

    // Lista vazia ?
    if (lista->inicio == NULL && lista->fim == NULL){
        lista->inicio = aux;
        lista->fim = aux;
    } else if (aux->genotipo.fitness <= lista->inicio->genotipo.fitness){
        aux->prox = lista->inicio;
        lista->inicio->anterior = aux;
        lista->inicio = aux;
    }else if (aux->genotipo.fitness >= lista->fim->genotipo.fitness){

        lista->fim->prox = aux;
        aux->anterior = lista->fim;
        lista->fim = aux;
    }else{
        TNo *novo = lista->inicio;
        while (novo != NULL && aux->genotipo.fitness > novo->genotipo.fitness) {
            novo = novo->prox; 
        }
        aux->prox = novo;
        aux->anterior = novo->anterior;
        novo->anterior->prox = aux;
        novo->anterior = aux;
    }
    lista->totalIndividuos++;
     return true;
}


