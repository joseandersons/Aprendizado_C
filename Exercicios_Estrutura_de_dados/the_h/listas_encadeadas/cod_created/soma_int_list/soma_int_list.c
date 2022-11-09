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
void inserir_no_fim(Lista *lista, char valor){
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
void soma(Lista *lista1, Lista *lista2, Lista *resultado_soma){
    No *novo = lista1->inicio;
    No *novo2 = lista2->inicio;
    int aux_resto=0;
    int valor=0, resto=0;

    while(novo!=NULL){
        valor = novo->valor + novo2->valor;
        valor = valor + resto;
 
        if(valor < 10)resto = 0;
        else if(valor>=10){
            aux_resto = valor;
            resto = valor / 10;
            valor = valor - 10;
        }
        inserir_no_incio(resultado_soma, valor);
        novo = novo->proximo;
        novo2 = novo2->proximo;
    }
    if(aux_resto>=10)inserir_no_incio(resultado_soma, resto);
}
void del_elements(Lista *lista, int elemento){
    No *atual = lista->inicio;
    No *aux = atual->proximo;

    while(atual->valor == elemento){
 
        free(atual);
        atual = aux;
        aux = atual->proximo;
    }
    lista->inicio = atual;
}
void ler_inserir(Lista *lista1, Lista *lista2){
    char valor[1];
    while(1){
        scanf("%s", valor);
        if(valor[0] == '+')break;
        int x = atoi(valor);
        inserir_no_incio(lista1, x);
    }
    while(1){                               
        scanf("%s", valor);
        if(valor[0] == '=')break;
        int x = atoi(valor);
        inserir_no_incio(lista2, x);
    }
}
void inserir_zeros(Lista *lista1, Lista *lista2){
    if(lista1->tamanho > lista2->tamanho){
        int tam = lista1->tamanho - lista2->tamanho;
        int i=0;
        while(i < tam){
            inserir_no_fim(lista2, 0);
            i++;
        }
    }
    else if(lista2->tamanho > lista1->tamanho){
        int tam = lista2->tamanho - lista1->tamanho;
        int i=0;
        while(i < tam){
            inserir_no_fim(lista1, 0);
            i++;
        }
    }
}
void delete_list(Lista *lista){
    No *atual = lista->inicio;
    No *aux = atual->proximo;

    while(1){
        free(atual);
        atual = aux;
        aux = atual->proximo;
        if(aux == NULL){
            free(atual);
            break;
        }
    }
}
int main() {
    int tamanho_lista1, tamanho_lista2;
    Lista *lista1;
    Lista *lista2;
    Lista *resultado_soma;

    if((lista1 = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;
    if((lista2 = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;
    if((resultado_soma = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;

    inicializar(lista1);
    inicializar(lista2);
    inicializar(resultado_soma);

    ler_inserir(lista1, lista2);
    inserir_zeros(lista1, lista2);
    
    soma(lista1, lista2, resultado_soma);
    // delete_list(lista1);
    // delete_list(lista2);

    if(resultado_soma->tamanho == 0){
        printf("Lista vazia!");
    }

    else{
        del_elements(resultado_soma, 0); //delta os zeros inseridos no inicio
        imprimir(resultado_soma);
    }
    

    
	return 0;
}