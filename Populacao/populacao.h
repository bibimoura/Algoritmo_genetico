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


bool populacao_create(TSDoubleList* , Labirinto* , Stack* , char* , int, int );

 void populacao_print(TSDoubleList *);

#endif