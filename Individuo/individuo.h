#ifndef INDIVIDUO_H
#define INDIVIDUO_H

#include <stdbool.h>

#include "Mapa/mapa.h"
#include "Stack/stack.h"
#include "Mapa/mapa.h"

struct _g {
    char *movimentos;
    int tam_cromossomo;
    double fitness;
    Posicao posicao;
};

typedef struct _g TGenotipo;

/**
 * Cria uma lista estática;
 * @param unsigned int Tamanho fixo da lista;
 * Retorna NULL em caso de falha na alocação;
 * @return TGenotipo* Ponteiro para a instância da lista criada.
 */
TGenotipo* TGenotipo_create(unsigned int );

/**
 * Genótipo com movimentos aleatórios;
 * @param genotipo Ponteiro para a estrutura TGenotipo.
 */
void individuo_aleatorio(TGenotipo* );

/**
 * Genótipo com movimentos inteligentes;
 * @param genotipo Ponteiro para a estrutura TGenotipo;
 * @param mapa Ponteiro para a estrutura Labirinto;
 * @param Stack* ponteiro para a pilha.
 */
void individuo_inteligente(TGenotipo* , Labirinto* , Stack* );

/**
 * Verifica se os movimentos são invalidos.
 * @param int linha 
 * @param int coluna
 * @param mapa Ponteiro para a estrutura Labirinto.
 * @return bool informando o status da operação.
 */
bool movimento_invalido(int , int , Labirinto* );

/**
 * Verifica se os movimentos são invalidos;
 * @param int linha;
 * @param int coluna;
 * @param int cont;
 * @param mapa Ponteiro para a estrutura Labirinto;
 * @return bool informando o status da operação.
 */
bool movimento_inicio(int , int , Labirinto* );

#endif