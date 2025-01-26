#include "RochaMineral.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CriaListaRocha(Compartimento* ListaR){
    ListaR->Primeiro = InicioArranjo;
    ListaR->Ultimo = ListaR->Primeiro;
    ListaR->ListaRochas = (RochaMineral*) malloc(sizeof(RochaMineral)*10000);
}

int VerificaListaVazia(Compartimento *ListaR){
    return(ListaR->Primeiro == ListaR->Ultimo);
}

void ImprimeComp(Compartimento *ListaR, int movimentacoes, int comparacoes, int escolha, double tempo){
    for(int i = 0; i < ListaR->Ultimo; i++){
        printf("%s %.1lf\n", ListaR->ListaRochas[i].Categoria, ListaR->ListaRochas[i].Peso);
    }
    printf("\n");
    printf("Comparacoes: %d\n", comparacoes);
    printf("Movimentacoes: %d\n", movimentacoes);
    printf("Tempo de execucao: %lf \n", tempo);
    if(escolha == 1){
        printf("Algoritmo: Insercao\n");
    }
    if(escolha == 2){
        printf("Algoritmo: QuickSort");
    }
    
}

int InsereRocha(Compartimento *ListaR, RochaMineral* NovaRocha){
    ListaR->ListaRochas[ListaR->Ultimo] = *NovaRocha;
    ListaR->Ultimo++;
    return 1;
}

void Insercao(Compartimento* lista, int tamanho, int *movimentacoes, int* comparacoes){
      int i, j;

    RochaMineral aux;
    for (i = 1; i < tamanho; i++){
        aux = lista->ListaRochas[i];
        j = i - 1;
        while ( ( j >= 0 ) && ( aux.Peso < lista->ListaRochas[j].Peso)){
            *comparacoes += 2;
            *movimentacoes += 1;
            lista->ListaRochas[j + 1] = lista->ListaRochas[j];
            j--;
        }
        *movimentacoes += 1;
        lista->ListaRochas[j + 1]= aux;
    }
}

void QuickSort(Compartimento *lista, int n, int *movimentacoes, int *comparacoes){
    Ordena(0, n-1, lista, movimentacoes, comparacoes);
}
void Ordena(int Esq, int Dir, Compartimento *lista, int *movimentacoes, int *comparacoes){
    int i,j;
    Particao(Esq, Dir, &i, &j, lista->ListaRochas, movimentacoes, comparacoes);

    *comparacoes += 1;
    if (Esq < j){
        Ordena(Esq, j, lista, movimentacoes, comparacoes);
    } 
    *comparacoes += 1;
    if (i < Dir) {
        Ordena(i, Dir, lista, movimentacoes, comparacoes);
    }
}
void Particao(int Esq, int Dir,int *i, int *j, RochaMineral* rocha, int *movimentacoes, int *comparacoes){
    RochaMineral pivo, aux;
    *i = Esq; *j = Dir;
    pivo = rocha[(*i + *j)/2]; 
    do{
        while (pivo.Peso > rocha[*i].Peso){
            *comparacoes += 1;
            (*i)++;
        } 
        while (pivo.Peso < rocha[*j].Peso){
            *comparacoes += 1;
            (*j)--;
        }
        *comparacoes += 1;
        if (*i <= *j){
            *movimentacoes += 1;

            aux = rocha[*i]; 
            rocha[*i] = rocha[*j];
            rocha[*j] = aux;
            (*i)++; 
            (*j)--;
        }
    } while (*i <= *j);
    *comparacoes += 1;
}
