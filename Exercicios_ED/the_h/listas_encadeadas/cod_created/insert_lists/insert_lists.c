#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;

}No;
void inserir_ordenado(No **lista, int num){
    No *novo, *aux;
    if((novo = (No*)malloc(sizeof(No)))==NULL)return;
    if((aux = (No*)malloc(sizeof(No)))==NULL)return;

    novo->valor = num;
    if(*lista == NULL){
        novo->proximo = NULL;
        *lista = novo;
    }
    else if(novo->valor < (*lista)->valor){
        novo->proximo = *lista;
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux->proximo && novo->valor > aux->proximo->valor){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }

}
void inserir_no_inicio(No **lista, int num){
    No *novo ;
    if((novo = (No*)malloc(sizeof(No)))==NULL)return;

    novo->valor = num;
    novo->proximo = *lista;
    *lista = novo;
}
void inserir_no_fim(No **lista, int num){
    No *novo, *aux;
    if((novo = (No*)malloc(sizeof(No)))==NULL)return;
    if((aux = (No*)malloc(sizeof(No)))==NULL)return;

    novo->valor = num;
    novo->proximo = NULL;
    
    if(*lista == NULL)*lista = novo;

    else{
        aux = *lista;
        while(aux->proximo){
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }
}
void inserir_no_meio(No **lista, int num, int anterior){
    No *novo, *aux;
    if((novo = (No*)malloc(sizeof(No)))==NULL)return;
    if((aux = (No*)malloc(sizeof(No)))==NULL)return;

    novo->valor = num;
    if(*lista == NULL){
        novo->proximo = NULL;
        *lista = novo;
    }
    else{
        aux = *lista;
        while(aux->valor != anterior && aux->proximo){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
}
void imprimir(No *no){
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
}
int consulta(No **lista, int valor){
    No *aux, *no = NULL;
    
    aux = *lista;
    if(aux->valor == valor)return 0;
    while(aux){
        if(aux->valor == valor){
            return 0;
        }
        aux = aux->proximo;
    }   
    return 1;
}
int consulta_2(No **lista1, No **lista2){
    No *atual = *lista2;
    int aux = -9999, cont=0;
    while(atual != NULL){
        int valor = atual->valor;
        int res = consulta(lista1, valor);
        if(res == 0){
            if(valor != aux){
                printf("%d\n", valor);
                cont++;
            }
            aux = valor;
        }
        atual = atual->proximo;
    }
    return cont;
}

int main() {
    int tamanho_lista1, tamanho_lista2;
    No *lista1 = NULL;
    No *lista2 = NULL;
    
    for(int i=0; i<20; i++){
        int valor;
        scanf("%d", &valor);
        inserir_ordenado(&lista1, valor);
    }
    for(int i=0; i<20; i++){
        int valor;
        scanf("%d", &valor);
        inserir_ordenado(&lista2, valor);
    }
    int res = consulta_2(&lista1, &lista2);
    if(res == 0)printf("VAZIO");
   
	return 0;
}