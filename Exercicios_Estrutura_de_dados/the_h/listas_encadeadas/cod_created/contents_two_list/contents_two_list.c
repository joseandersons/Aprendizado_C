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

void inserir_no_fim(Lista *lista, int valor){
    No *novo;

    if((novo = (No*) malloc(sizeof(No))) == NULL)return;

    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        lista->fim->proximo = novo;
        lista->fim = novo;      

    }
    lista->tamanho++;

}
int consulta(Lista *lista, int valor){
    No *inicio = lista->inicio;
    
    if(inicio->valor == valor)return 0;
    while(inicio != NULL && inicio->proximo != NULL){
        if(inicio->proximo->valor == valor)return 0;
        inicio = inicio->proximo;
    }
    
    return 1;
}
int consulta_2(Lista *lista1, Lista *lista2){
    int cont = 0;
    No *atual = lista2->inicio;
    while(atual != NULL){
        int valor = atual->valor;
        int res = consulta(lista1, valor);
        if(res == 0)cont++;
        atual = atual->proximo;
    }
    return cont;
}
void ler_inserir(Lista *list, int tam){
    for(int i=0; i<tam; i++){
        int valor;
        scanf("%d", &valor);
        inserir_no_fim(list, valor);
    }
}

int main() {
    int tamanho_lista1, tamanho_lista2;
    Lista *lista1;
    Lista *lista2;

    if((lista1 = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;
    if((lista2 = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;

    inicializar(lista1);
    inicializar(lista2);

    scanf("%d", &tamanho_lista1);
    ler_inserir(lista1, tamanho_lista1);
    
    scanf("%d", &tamanho_lista2);
    ler_inserir(lista2, tamanho_lista2);
    
    int res = consulta_2(lista1, lista2);
    if(res == tamanho_lista2)printf("1");
    else printf("0");
    
	return 0;
}