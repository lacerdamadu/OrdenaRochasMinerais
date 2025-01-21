#include "Compartimento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    printf("oi");

    Compartimento Comp;

    CriaListaRocha(&Comp);
    

    int quant;

    printf("Digita quantas:\n");
    scanf("%d", &quant);

    printf("Digite as rocha\n");

    RochaMineral Rocha; double Peso; ListaMinerais ListaMin; double Latitude; double Longitude;
    for(int i = 0; i < quant; i++){

        IniVListaM(&ListaMin);

        scanf("%lf %lf %lf", &Latitude, &Longitude, &Peso);

        char TodosMinerais[300];
        char nome[100];
        int j = 0;

        fgets(TodosMinerais, sizeof(TodosMinerais), stdin);

        for (int i = 0; i < 100; i++) {
            if ((TodosMinerais[i] == ' ') || (TodosMinerais[i] == '\n') || (TodosMinerais[i] == '\0')) {
                nome[j] = '\0'; 
                if (strlen(nome) > 0) { 
                    InsMineral(&ListaMin, nome);
                    j = 0; 
                }
                if (TodosMinerais[i] == '\n' || TodosMinerais[i] == '\0') {
                    break;
                }   
            } 
            else {
                nome[j] = TodosMinerais[i];
                j++;
            }
        }

        InicializaRocha(&Rocha, Peso, &ListaMin, Latitude, Longitude);

        InsereRocha(&Comp, &Rocha);

        EsvaziaLista(&ListaMin);

    }

    ImprimeComp(&Comp);

    return 1;
}