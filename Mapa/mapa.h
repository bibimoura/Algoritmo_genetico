#ifndef MAPA_H
#define MAPA_H

typedef struct {
    int linha;
    int coluna;
} Posicao;

typedef struct {
    char ** labirinto;
    int linhas;       
    int colunas;
    Posicao inicio;
    Posicao final;          
} Labirinto;

/**
 * Vai carregar um labirinto de um arquivo.txt.
 * @param const char* arquivo_labirinto.
 * @return Retorna uma estrutura do tipo Labirinto.
 */
Labirinto labirinto_carregar(const char* );

/**
 * Identifica e armazena as posições de início (S) e final (E) no labirinto.
 * @param Labirinto* Ponteiro para a estrutura do labirinto.
 */
 void labirinto_posicoes(Labirinto* );

/**
 * Imprime o labirinto.
 * @param Labirinto Estrutura do labirinto.
 */
 void labirinto_print(Labirinto );

/**
 * Libera a memória alocada dinamicamente para o labirinto.
 * @param Labirinto  Estrutura do labirinto.
 */
void labirinto_free(Labirinto );

#endif