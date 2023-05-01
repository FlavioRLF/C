//
//  Lista.h
//  exercicios_4
//
//  Created by FLAVIO LIMA FH on 30/04/23.
//

#ifndef Lista_h
#define Lista_h

struct No{
    int val;
    struct No* prox;
};


struct No* inserirVal(struct No *ini, int val){
    struct No* novo_no = (struct No*)malloc(sizeof(struct No));
    novo_no -> val = val;
    
    if(ini == NULL){
        novo_no->prox = NULL;
        ini = novo_no;
    }
    else {
        novo_no->prox = ini;
        ini = novo_no;
    }
    return ini;
}


struct No* inserirFinal(struct No* ini, int val){           // Método para inserir valores no final da lista
    struct No *novo=(struct No*)malloc(sizeof(struct No));
    novo->val = val;
    novo->prox = NULL;
    
    if(ini == NULL){
        ini = novo;
        return ini;
    }
    struct No* ultimo = ini;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }
    ultimo->prox= novo;
    return ini;
}

void imprimirLista(struct No* ini){     // Método para imprimir a lista
    struct No* atual = ini;
    while (atual != NULL) {
        printf("%d ", atual->val);
        atual = atual->prox;
    }
    
}

struct No* removeElm(struct No* ini, int val){      // Remove elemento da Lista
    if( ini == NULL){   // lista vazia
        return ini;
    }
    if( ini->val==val){ // removendo o primeiro elemento
        struct No *removido = ini;
        ini = ini->prox;
        free(removido);
    }
    else{
        struct No* ant = ini;
        struct No* atual = ant->prox;
        while (atual != NULL) {
            if(atual->val == val){
                ant->prox = atual->prox;    // aponta para o proximo elemento
                free(atual);                // remove da memoria o elemento indesejado
                break;
            }
            atual = atual->prox;
            ant = ant->prox;
        }
    }
    return ini;     // retorna o inicio da lista
}


#endif /* Lista_h */
