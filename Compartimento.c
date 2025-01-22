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

void Insercao(Compartimento* lista, int tamanho){
    int i,j;

    RochaMineral aux;
    
    for (i = 1; i < tamanho; i++){
        aux = lista->ListaRochas[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux.Peso < lista[j].ListaRochas->Peso)){
            lista[j + 1] = lista[j];
            j--;
        }
    lista->ListaRochas[j + 1]= aux;
 }
}

void QuickSort(Compartimento *lista, int n){
    Ordena(0, n-1, lista);
}
void Ordena(int Esq, int Dir, Compartimento *lista){
    int i,j;
    Particao(Esq, Dir, &i, &j, lista);
    if (Esq < j){
        Ordena(Esq, j, lista);
    } 
    if (i < Dir) {
        Ordena(i, Dir, lista);
    }
}
void Particao(int Esq, int Dir,int *i, int *j, Compartimento *lista){
    RochaMineral pivo, aux;
    *i = Esq; *j = Dir;
    pivo = lista->ListaRochas[(*i + *j)/2]; 

    do
    {
        while (pivo.Peso > lista[*i].ListaRochas->Peso){
            (*i)++;
        } 
        while (pivo.Peso < lista[*j].ListaRochas->Peso){
            (*j)--;
        }
        if (*i <= *j){
            aux = lista->ListaRochas[*i]; 
            lista->ListaRochas[*i] = lista->ListaRochas[*j];
            lista->ListaRochas[*j] = aux;
            (*i)++; (*j)--;
        }
        } while (*i <= *j);
}