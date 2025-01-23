#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Central.h"
int CentralOrdena(Compartimento *lista){
    printf("Bem vindo ao Sistema de Ordenacao de Rochas Minerais\n"
    "Para realizar a ordenação nosso sistema possui duas opcoes de algoritmos\n"
    "(1) O algoritmo de ordenacao simples denominado Insercao\n"
    "(2) O algoritmo de ordenacao sofisticado denominado QuickSort\n");

    char nome[STRING];
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nome);
    printf("oi");
    printf("%s", nome);

    FILE* entrada;
    entrada = fopen(nome, "r");
    if(entrada == NULL){
        printf("Erro ao ler o arquivo.");
        return 0;
    }

    printf("oi");
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    //char *ptr;
    int tamanho = 0;
    char aux;

    fscanf(entrada,"%d", &tamanho);
    fscanf(entrada, "%c", &aux);//Pega o \n da linha anterior

    for(int i=0;i<tamanho;i++){

            char linha2[STRING];
            ListaMinerais listaMinerais;
            IniVListaM(&listaMinerais);
            fgets(linha2, sizeof(linha2), entrada);//A funcao fgets le uma linha inteira e armazena em um vetor de char
            //Variaveis auxiliares
            char lat[STRING], lont[STRING], pes[STRING];
            char* pt;
            int cont = 1;

            strcpy(mineral1, "NAO TEM NADA");
            strcpy(mineral2, "NAO TEM NADA");
            strcpy(mineral3, "NAO TEM NADA");

            //Separa a linha em strings de acordo com os espacos
            pt = strtok(linha2," ");
            while(pt != NULL){
                if(pt[0]=='\n'){
                    break;
                }
                if(cont==1){
                    strcpy(lat, pt);   
                }
                if(cont==2){
                    strcpy(lont, pt);
                }
                if(cont==3){
                    strcpy(pes, pt);
                }
                if(cont==4){
                    strcpy(mineral1, pt);
                }
                if(cont==5){
                    strcpy(mineral2, pt);
                }
                if(cont==6){
                    strcpy(mineral3, pt);
                }
                cont++;
                pt = strtok(NULL," ");
            }
            //Transforma as Strings que armazenam os valores de longitude, latitude e peso em double
            latrocha = atof(lat);
            longrocha = atof(lont);
            pesorocha = atof(pes);

            //Verifica se ha um nome de mineral na string, inicializa um mineral e o insere na lista de minerais
            if(strcmp(mineral1, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral1);
            }
            if(strcmp(mineral2, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral2);
            }
            if(strcmp(mineral3, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral3);
            }
            RochaMineral Rocha;
            InicializaRocha(&Rocha, pesorocha, &listaMinerais,
            latrocha, longrocha);

            EsvaziaLista(&listaMinerais);
    }
        //if(escolha == 1){
        Insercao(lista, tamanho);
            //}
        //if(escolha == 0){
        //QuickSort(lista, tamanho);
        //}
         ImprimeComp(lista);
           
    return 0;
}

/*nt CentralOrdena(Compartimento *lista){
    printf("Bem vindo ao Sistema de Ordenacao de Rochas Minerais\n"
    "Para realizar a ordenação nosso sistema possui duas opcoes de algoritmos\n"
    "(1) O algoritmo de ordenacao simples denominado Insercao\n"
    "(2) O algoritmo de ordenacao sofisticado denominado QuickSort\n");

    char nome[STRING];
    printf("Digite o nome do arquivo de entrada: ");
    printf("oi");
    scanf("%s", nome);
    printf("oi");
    printf("%s", nome);

    FILE* entrada;
    entrada = fopen(nome, "r");
    if(entrada == NULL){
        printf("Erro ao ler o arquivo.");
        return 0;
    }

    printf("oi");
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    //char *ptr;
    int tamanho = 0;
    char aux;


    fscanf(entrada,"%d", &tamanho);
    fscanf(entrada, "%c", &aux);//Pega o \n da linha anterior

    for(int i=0;i<tamanho;i++){

            char linha2[STRING];
            ListaMinerais listaMinerais;
            IniVListaM(&listaMinerais);
            fgets(linha2, sizeof(linha2), entrada);//A funcao fgets le uma linha inteira e armazena em um vetor de char

            //Variaveis auxiliares
            char lat[STRING], lont[STRING], pes[STRING];
            char* pt;
            int cont = 1;

            strcpy(mineral1, "NAO TEM NADA");
            strcpy(mineral2, "NAO TEM NADA");
            strcpy(mineral3, "NAO TEM NADA");

            //Separa a linha em strings de acordo com os espacos
            pt = strtok(linha2," ");
            while(pt != NULL){
                if(pt[0]=='\n'){
                    break;
                }
                if(cont==1){
                    strcpy(lat, pt);   
                }
                if(cont==2){
                    strcpy(lont, pt);
                }
                if(cont==3){
                    strcpy(pes, pt);
                }
                if(cont==4){
                    strcpy(mineral1, pt);
                }
                if(cont==5){
                    strcpy(mineral2, pt);
                }
                if(cont==6){
                    strcpy(mineral3, pt);
                }
                cont++;
                pt = strtok(NULL," ");
            }
            //Transforma as Strings que armazenam os valores de longitude, latitude e peso em double
            latrocha = atof(lat);
            longrocha = atof(lont);
            pesorocha = atof(pes);
           
            //Verifica se ha um nome de mineral na string, inicializa um mineral e o insere na lista de minerais
            if(strcmp(mineral1, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral1);
            }
            if(strcmp(mineral2, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral2);
            }
            if(strcmp(mineral3, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral3);
            }

            RochaMineral Rocha;
            InicializaRocha(&Rocha, pesorocha, &listaMinerais,
            latrocha, longrocha);

            EsvaziaLista(&listaMinerais); 
    }
    //if(escolha == 1){
        Insercao(lista, tamanho);
    //}
    //if(escolha == 0){
        //QuickSort(lista, tamanho);
    //}
    ImprimeComp(lista);
    
    return 1;
}*/