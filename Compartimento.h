#ifndef COMPARTIMENTO_H_
#define COMPARTIMENTO_H_
#include "RochaMineral.h"
#define TamMax 10000


typedef struct {

 RochaMineral* ListaRochas;
 int Primeiro, Ultimo;

} Compartimento;


void CriaListaRocha(Compartimento *ListaR);//Cria uma Lista de Rocha Mineral Vazia

void ImprimeComp(Compartimento *lista);//Exibe todo o conteudo do compartimento

int InsereRocha(Compartimento *lista, RochaMineral* NovaRocha);//Insere uma rocha encontrada no final da lista, seguindo as regras

void Insercao(Compartimento* lista, int tamanho);//Ordena a lista utilizando o algoritmo simples de ordenação INSERÇAO

void QuickSort(Compartimento *lista, int n);//Ordena a lista utilizando o algoritmo simples de ordenação QUICKSORT
void Ordena(int Esq, int Dir, Compartimento *lista);
void Particao(int Esq, int Dir,int *i, int *j, Compartimento *lista);

#endif