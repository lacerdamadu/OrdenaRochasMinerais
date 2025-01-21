#include "RochaMineral.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CriaListaRocha(Compartimento* ListaR){
    ListaR->Primeiro = InicioArranjo;
    ListaR->Ultimo = ListaR->Primeiro;
}

int VerificaListaVazia(Compartimento *ListaR){
    return(ListaR->Primeiro == ListaR->Ultimo);
}

void ImprimeComp(Compartimento *ListaR){
    for(int i = 0; i < ListaR->Ultimo; i++){
        printf("%s %.0lf\n", ListaR->ListaRochas[i].Categoria, ListaR->ListaRochas[i].Peso);
    }
}

int InsereRocha(Compartimento *ListaR, RochaMineral* NovaRocha){
    ListaR->ListaRochas[ListaR->Ultimo] = *NovaRocha;
    ListaR->Ultimo++;
    return 1;
}