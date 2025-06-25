#ifndef POPULACAO_H
#define POPULACAO_H

#include "Individuo/individuo.h" 
#include "TSDoubleList/list.h"
#include "Mapa/mapa.h"
#include "Fitness/fitness.h"
#include "Simulacao/simulacao.h"
#include "Stack/stack.h"
#include "Arquivo/arquivo.h"

#include <stdbool.h>

/**
 * Criação da primeira geração;
 * @param TDoubleList* ponteiro para uma instância da lista; 
 * @param Labirinto* Ponteiro para a estrutura do labirinto;
 * @param Stack* ponteiro para a pilha;
 * @param char* Tipo de geração (aleatorio, apenas_movimentos_validos)
 * @param int Tamanho da população
 * @param int Tamanho máximo dos movimentos.
 */
bool populacao_create(TSDoubleList* , Labirinto* , Stack* , char* , int, int );

/**
 * Imprime a lista com os individuos do menor para o maior.
 * @param TDoubleList* ponteiro para uma instância da lista; 
 */
void populacao_print(TSDoubleList *);

#endif