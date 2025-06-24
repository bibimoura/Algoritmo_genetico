#include "arquivo.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


void ler_config_ini(Config *config, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o %s\n", nome_arquivo);
        return;
    }

    char linha[256];
    char secao[50] = "";

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';

        if (linha[0] == '\0' || linha[0] == ';') continue;

        char *comentario = strchr(linha, ';');
        if (comentario) *comentario = '\0';

        if (linha[0] == '[') {
            sscanf(linha, "[%[^]]", secao);
            continue;
        }

        char *igual = strchr(linha, '=');
        if (!igual) continue;

        *igual = '\0';
        char *chave = linha;
        char *valor = igual + 1;

        if (strcmp(secao, "parametros") == 0) {
            if (strcmp(chave, "taxa_elitismo") == 0)
                config->taxa_elitismo = atof(valor);
            else if (strcmp(chave, "geracoes") == 0)
                config->geracoes = atoi(valor);
            else if (strcmp(chave, "tamanho_populacao") == 0)
                config->tamanho_populacao = atoi(valor);
        } else if (strcmp(secao, "estrategias") == 0) {
            if (strcmp(chave, "tipo_geracao") == 0)
                strcpy(config->tipo_geracao, valor);
        } else if (strcmp(secao, "outros") == 0) {
            if (strcmp(chave, "max_movimentos") == 0)
                config->max_movimentos = atoi(valor);
            else if (strcmp(chave, "taxa_mutacao") == 0)
                config->taxa_mutacao = atof(valor);
        } else if (strcmp(secao, "arquivos") == 0) {
            if (strcmp(chave, "saida_log") == 0)
                strcpy(config->saida_log, valor);
        }
    }

    fclose(arquivo);
}


void arquivo_CSV(char *nome_arquivo, TSDoubleList *lista, int geracao){
    
    // a -> vai preservar os dados anteriores
    FILE *arq_genetico = fopen(nome_arquivo, "a");
    if (arq_genetico == NULL){
        printf("Erro na abertura do arquivo\n");
        return;
    }

    TNo *aux = lista->fim;

    fprintf(arq_genetico, "%d, %.2lf,", geracao, aux->genotipo.fitness);

    for(int i = 0 ; i < aux->genotipo.tam_cromossomo; i++){
        fputc(aux->genotipo.movimentos[i], arq_genetico);
    }
    fprintf(arq_genetico, "\n");
    
    fclose(arq_genetico);
}







