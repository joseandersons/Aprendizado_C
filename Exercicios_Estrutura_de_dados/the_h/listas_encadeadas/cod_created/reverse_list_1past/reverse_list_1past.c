#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;

}No;

typedef struct{
    No *inicio;
    No *fim;
    int tamanho;
}Lista;
void inicializar(Lista *lista){

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    
}

void inserir_no_incio(Lista *lista, int valor){

    No *novo;

    if((novo = (No*) malloc(sizeof(No))) == NULL)return;

    novo->valor = valor;

    if(lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

void imprimir(Lista *lista){
    No *atual = lista->inicio;
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
}
int main() {
    Lista *lista;
    
    if((lista = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;
    inicializar(lista);
    int num;
    while(1){
        if(scanf("%d", &num) == EOF)break;
        inserir_no_incio(lista, num);
        
    }
    
    imprimir(lista);
	return 0;
}

