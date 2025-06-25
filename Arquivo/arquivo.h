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
 * Leitura do arquivo config.ini;
 * @param const char* Nome do arquivo;
 * @return Config retorna a struct Config preenchida.
 */
Config ler_config_ini(const char *);

/**
 * Registra os dados do melhor indivíduo de cada geração;
 * @param char Nome do arquivo csv;
 * @param TDoubleList* ponteiro para uma instância da lista;
 * @param int Número da geração atual.
 */
void arquivo_CSV(char *, TSDoubleList* , int );

#endif