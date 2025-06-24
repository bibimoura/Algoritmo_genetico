#ifndef ARQUIVO_H
#define ARQUIVO_H


#include "TSDoubleList/list.h"

typedef struct {
   // Parametros
    float taxa_elitismo;
    int geracoes;
    int tamanho_populacao;

    // Estrategias
    char tipo_geracao[50];

    // Outros
    int max_movimentos;
    float taxa_mutacao;


    // Arquivos
    char saida_log[100];

} Config;

/**
 * 
 */
void ler_config_ini(Config*, const char*);

/**
 * 
 */
void arquivo_CSV(char *, TSDoubleList* , int );

#endif