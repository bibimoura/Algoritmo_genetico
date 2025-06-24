#include "stack.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


Stack *Stack_create(unsigned int max_movimentos){
    Stack *novo = malloc(sizeof(Stack));
    if (novo){
        novo->dado = calloc(max_movimentos, sizeof(int));
        if(novo->dado == NULL){
            free(novo);
            return (NULL);
        }
        novo->tamanho = max_movimentos;
        novo->index = -1;
    }
    return novo;

}

bool Stack_push(Stack *pilha, char info){
    if (Stack_is_full(pilha))
        return false;

    pilha->index++;
    pilha->dado[pilha->index] = info;
    return true;
}

bool Stack_is_full(Stack *pilha){
    return (pilha->index == pilha->tamanho - 1);
}


