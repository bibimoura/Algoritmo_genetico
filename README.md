<h1 align="center">Labirintos com Algoritmos Genéticos 🧬 </h1> 

## 📁 Resumo do projeto
Este projeto acadêmico tem como objetivo implementar um algoritmo genético em linguagem C para encontrar caminhos eficientes em labirintos.

<p align="center">
   <img src="http://img.shields.io/static/v1?label=STATUS&message=FINALIZADO&color=GREEN&style=for-the-badge"/>
</p>

## 📁 Estrutura do Pojeto
<div align="center">

## 🧪 Etapas Iniciais:

| Etapa | Descrição                    |
|:-----:|:-----------------------------|
| [1]   | Modelagem do mapa            |
| [2]   | Criação do indivíduo         |
| [3]   | Simulação dos caminhos       |
| [4]   | Cálculo do fitness           |
| [5]   | Criação da população inicial |

## 🔀 Enquanto o critério de parada não for atingido:

| Etapa | Descrição              |
|:-----:|:-----------------------|
| [1]   | Seleção dos mais aptos |
| [2]   | Cruzamento (crossover) |
| [3]   | Mutação                |
| [4]   | Nova população |




</div>



> [!IMPORTANT]
> ## Compilação do programa
>
> ### Pré-requisitos
> - Compilador C (como GCC)
>
> ### Como Compilar
> -Compile o programa com o GCC:  
>    ```bash
>    gcc -I. -IArquivo -IMapa -IFitness -ISimulacao -IPopulacao -IIndividuo -ITSDoubleList -IStack -ISelecao -IMutacao -IElitismo -ICrossover main.c Arquivo/arquivo.c Mapa/mapa.c Fitness/fitness.c Simulacao/simulacao.c Populacao/populacao.c Individuo/individuo.c TSDoubleList/list.c Stack/stack.c Selecao/selecao.c Mutacao/mutacao.c Elitismo/elitismo.c Crossover/crossover.c -o labirinto
>    ```
>
> ### Como Executar
> - Execute o programa no terminal:  
>   ```bash
>   ./labirinto mapa.txt config_exp1.ini
>   ```
>   ```bash
>   ./labirinto mapa.txt config_exp2.ini
>   ```
> 

