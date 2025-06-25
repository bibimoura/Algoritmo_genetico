#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct _stack Stack;
struct _stack{ 

    char *dado; 
    int tamanho;
    int index;
};

/**
 * Cria instâncias de pilhas;
 * @param unsigned int Tamanho fixo da pilha;
 * Retorna NULL caso não seja possível alocar memória para a pilha;
 * @return Stack* ponteiro para uma pilha
 */
Stack* Stack_create(unsigned int );
/**
 * Tenta inserir um dado na pilha;
 * @param Stack* ponteiro para a pilha;
 * @param int valor char para ser inserido na pilha;
 * @return bool informando o status da operação.
 */
bool Stack_push(Stack* , char );

/**
 * Retorna se a pilha está cheia;
 * @param Stack* ponteiro para a pilha;
 * @return bool informando se está cheia.
 */
bool Stack_is_full(Stack* );

#endif