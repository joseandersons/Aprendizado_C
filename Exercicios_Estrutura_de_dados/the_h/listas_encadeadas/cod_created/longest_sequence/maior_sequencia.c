#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no{
    char *valor;
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

void inserir_no_fim(Lista *lista, char valor[]){
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
void imprimir(Lista *lista){
    No *atual = lista->inicio;
    while(atual != NULL){
        printf("%s ", atual->valor);
        atual = atual->proximo;
    }
}
void verifica(Lista *lista){
    No *atual = lista->inicio;
    
    while(atual!=NULL){
        char *valor = atual->valor;
        int cabeca=0, calda=0, aux_calda=0, aux_cabeca=0, contador_sequencia=0, aux_contador_sequencia=0;
        int tamanho = strlen(valor);
        for(int i=0; i<tamanho; i++){
            if(valor[i] == '0'){
                aux_contador_sequencia++;
                aux_calda++;
            }
            else if(valor[i]=='1' && aux_contador_sequencia>contador_sequencia && i >0){
                contador_sequencia = aux_contador_sequencia;
                cabeca = aux_cabeca;
                calda = aux_calda;
                aux_calda = aux_calda + 1;
                aux_cabeca = aux_calda;
                aux_contador_sequencia = 0;
            }
            else{
                aux_calda = aux_calda + 1;
                aux_cabeca = aux_calda;
                aux_contador_sequencia = 0;

            }
        }
        printf("%d %d\n", cabeca, calda-1);
        atual = atual->proximo;      
    }
}
int main() {

    char num[10000];
    int tamanho=0;

    Lista *lista;
    if((lista = (Lista*)malloc(sizeof(Lista)))==NULL)return 0;
    
    inicializar(lista);
    while(1){ //leitura  
        scanf("%s", num);
        int tam = strlen(num);
        char *string = (char*)malloc(sizeof(char)*tam);
        if(tam == 1 && num[0] == '0')break;
        strcpy(string, num);

        inserir_no_fim(lista, string);
        }
        verifica(lista);

	return 0;
}