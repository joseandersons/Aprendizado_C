#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;

}No;
void inserir_ordenado(No **lista, char num){
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
void imprimir(No *no){
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
}

int main() {
    int tamanho_lista1, tamanho_lista2;
    No *lista1 = NULL;
    
        int valor;
        while(scanf("%d", &valor) != EOF){
            inserir_ordenado(&lista1, valor);
        }

    imprimir(lista1);
    
   
	return 0;
}