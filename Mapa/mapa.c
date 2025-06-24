#include "mapa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Labirinto labirinto_carregar(const char* arquivo_labirinto){
    
    Labirinto mapa = {0};

    FILE *arquivo = fopen(arquivo_labirinto, "r");
    
    if (arquivo == NULL) {
        printf("ERRO ao abrir o arquivo %s\n", arquivo_labirinto);
        exit(1);
    }

    
    int linhas = 0; 
    int max_cols = 0;
    char linha[1024]; 

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0'; 
        int len = strlen(linha); 
        if (len > max_cols) max_cols = len;
        linhas++;
    }


    if (linhas == 0) {
        printf("Arquivo vazio.\n");
        fclose(arquivo);
        exit(1);
    }

    mapa.labirinto = (char**)malloc(linhas * sizeof(char*));
    if (!mapa.labirinto) {
        printf("Falha na alocação de memória.\n");
        fclose(arquivo);
        exit(1);
    }
    for (int i = 0; i < linhas; i++) {

        mapa.labirinto[i] = (char*)malloc(max_cols * sizeof(char));
        if (!mapa.labirinto[i]) {
            printf("Falha na alocação de memória.\n");
            fclose(arquivo);
            exit(1);
        }
    }

    rewind(arquivo);

    linhas = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(mapa.labirinto[linhas], linha);
        linhas++;
    }

    mapa.linhas = linhas;
    mapa.colunas = max_cols;

    fclose(arquivo);

    labirinto_posicoes(&mapa);

    puts("Carregando o labirinto...");
    printf("Labirinto carregado com sucesso! (%d linhas, %d colunas)\n", mapa.linhas, mapa.colunas);

    return mapa;
}

void labirinto_posicoes(Labirinto* mapa) {

    int encontrou_inicio = 0, encontrou_final = 0;

    for (int i = 0; i < mapa->linhas; i++) {
        for (int j = 0; j < mapa->colunas; j++) {

            if (mapa->labirinto[i][j] == 'S') {
                mapa->inicio.linha = i;
                mapa->inicio.coluna = j;
                encontrou_inicio = 1;

            } else if (mapa->labirinto[i][j] == 'E') {
                mapa->final.linha = i;
                mapa->final.coluna = j;
                encontrou_final = 1; 
            }
        }
    }
    

    if (!encontrou_inicio || !encontrou_final) {
        printf("ERRO: Não foi possivel encontrar as posições no labirinto");
        labirinto_free(*mapa);
        exit(1);
    }
}

void labirinto_print(Labirinto mapa) {
    if (mapa.linhas <= 0 || mapa.colunas <= 0) {
        printf("ERRO: Labirinto inválido.\n");
        return;
    }

    for (int i = 0; i < mapa.linhas; i++) {
        for (int j = 0; j < mapa.colunas; j++) {
            printf("%c", mapa.labirinto[i][j]);
        }
        printf("\n");
    }
}

void labirinto_free(Labirinto mapa) {
    for (int i = 0; i < mapa.linhas; i++) {
        free(mapa.labirinto[i]);
    }
    free(mapa.labirinto);
}
