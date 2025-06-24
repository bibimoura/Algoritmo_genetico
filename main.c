#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Arquivo/arquivo.h"
#include "TSDoubleList/list.h"
#include "Stack/stack.h"
#include "Populacao/populacao.h"
#include "Mapa/mapa.h"
#include "Elitismo/elitismo.h"
#include "Selecao/selecao.h"
#include "Crossover/crossover.h"
#include "Mutacao/mutacao.h"

int main(int argc, char *argv[]){

    srand(time(NULL));

    Config *config = malloc(sizeof(Config));

    if (argc != 3){
        printf(" %s mapa.txt config.ini\n", argv[0]);
        return 1;
    }

    Labirinto mapa = labirinto_carregar(argv[1]);
    if (mapa.labirinto == NULL){
        printf("Erro ao carregar o mapa.txt: %s\n", argv[1]);
        return 1;
    }

    FILE *config_file = fopen(argv[2], "r");
    if (config_file == NULL)
    {
        printf("Erro ao abrir o config.ini: %s\n", argv[2]);
        labirinto_free(mapa);
        return 1;
    }

    ler_config_ini(config, argv[2]);

    // Labirinto
    puts("\n=-=-=-=-=-=-== Labirinto =-=-=-=-=-=-==\n");
    labirinto_print(mapa);
    printf("Posicao Inicial (S) do labirinto: (%d, %d)\n", mapa.inicio.linha, mapa.inicio.coluna);
    printf("Posicao Final (E) do labirinto: (%d, %d)\n", mapa.final.linha, mapa.final.coluna);

    // População inicial
    TSDoubleList *lista_populacao = list_create();
    Stack *pilha = Stack_create(config->max_movimentos);

    if (!populacao_create(lista_populacao, &mapa, pilha, config->tipo_geracao, config->tamanho_populacao, config->max_movimentos))
    {
        printf("Erro ao criar população\n");
        return 1;
    }
    else
    {
        printf("Populacao inicial criada com sucesso!");
    }
    printf("\n=-=-=-=-=-=-== Geracao %d =-=-=-=-=-=-==\n", 0);
    populacao_print(lista_populacao);
    arquivo_CSV(config->saida_log, lista_populacao, 0);

    // Gerações
    for (int i = 1; i < config->geracoes + 1; i++)
    {
        TSDoubleList *nova_populacao = elitismo(lista_populacao, config->taxa_elitismo, config->tamanho_populacao);
        while (nova_populacao->totalIndividuos < config->tamanho_populacao)
        {
            
            TNo *pai1 = selecao_pais(lista_populacao);
            TNo *pai2 = selecao_pais(lista_populacao);
            TGenotipo *filho = crossover(pai1, pai2, config->max_movimentos);
            if (strcmp(config->tipo_geracao, "aleatorio") == 0)
            {
                mutacao_aleatoria(filho, config->taxa_mutacao);
            }
            else
            {
                mutacao_inteligente(filho, pilha, config->taxa_mutacao);
            }
            Posicao posicao_final;
            int colisoes = simular_caminho(&mapa, filho, &posicao_final);
            filho->posicao = posicao_final;
            calcular_fitness(&mapa, filho, &posicao_final);

            list_insert(nova_populacao, filho);
        }
        lista_populacao = nova_populacao;

        printf("\n=-=-=-=-=-=-== Geracao %d =-=-=-=-=-=-==\n", i);
        populacao_print(lista_populacao);
        arquivo_CSV(config->saida_log, lista_populacao, i);
    }
}
