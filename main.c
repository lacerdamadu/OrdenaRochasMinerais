#include "Central.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    Compartimento Comp;

    CriaListaRocha(&Comp);
    CentralOrdena(&Comp);
    
    return 1;
}