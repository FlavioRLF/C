//
//  main.c
//  exercicios_4
//
//  Created by FLAVIO LIMA FH on 30/04/23.
//

/*
 Implemente um algoritmo de ordenacao para listas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void troca(struct No *a, struct No *b){ // funcao troca valores de lugar
    int temp = a->val;  // variavel tamporaria recebe valor de a
    a->val = b->val;    // valor de a recebe valor de b
    b->val = temp;  // valor de b recebe temp
}

void ordenaLista(struct No *ini){
    struct No* ptr = ini;
    
    int trocou;
    
    if(ini == NULL){
        return;
    }
    
    do{
        trocou = 0;
        while(ptr->prox != NULL){
            if(ptr->val > ptr->prox->val){  // se valor anterior for meior que proximo valor
                troca(ptr, ptr->prox);  // troca anterior com proximo
                trocou = 1; // "trocou" recebe 1
            }
            ptr = ptr->prox;    // ptr aponta para o proximo valor da lista
        }
        
    }while(trocou!=0);  // Repete enquanto "trocou" nao for igual a 0
}


int main(int argc, const char * argv[]) {
    
    struct No *ini = NULL;
    ini = inserirVal(ini, 8);
    ini = inserirVal(ini, 5);
    ini = inserirVal(ini, 7);
    ini = inserirVal(ini, 2);
    ini = inserirVal(ini, 4);
    
    printf("Lista nao ordenada: ");
    imprimirLista(ini);
    
    printf("\n");
    
    printf("Lista ordenada: ");
    ordenaLista(ini);
    imprimirLista(ini);
    
    return 0;
}
