#ifndef COMPARTIMENTO_H_
#define COMPARTIMENTO_H_
#include "RochaMineral.h"
#define TamMax 10000


typedef struct {

 RochaMineral ListaRochas[TamMax];
 int Primeiro, Ultimo;

} Compartimento;


void CriaListaRocha(Compartimento *ListaR);//Cria uma Lista de Rocha Mineral Vazia

void ImprimeComp(Compartimento *lista);//Exibe todo o conteudo do compartimento

int InsereRocha(Compartimento *lista, RochaMineral* NovaRocha);//Insere uma rocha encontrada no final da lista, seguindo as regras


#endif