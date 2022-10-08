#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no{
    char valor;
    int quantidade;
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
        novo->proximo = lista->inicio
        ;
        lista->inicio = novo;
    }
    lista->tamanho++;
}

void imprimir(Lista *lista){
    No *atual = lista->inicio;
    while(atual != NULL){
        printf("%c ", atual->valor);
        atual = atual->proximo;
    }
}

void inserir_no_fim(char letra, Lista *lista, No *novo){
    novo->valor = letra;
        
    if(lista->inicio == NULL){
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        novo->proximo = NULL;
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho++;
}
void verificar(char frase[], Lista *lista){
    int tam = strlen(frase);
    char aux = '+';

    for(int i=0; i<tam; i++){
        if(frase[i]!= aux){
            No *novo = (No*)malloc(sizeof(No));
            inserir_no_fim(frase[i], lista, novo);
            for(int j=0; j<tam; j++){
                if(frase[i] == frase[j]){
                    novo->quantidade++;
                }
            }
            aux = frase[i];
            printf("%c %d\n", frase[i], novo->quantidade);
        }
    }
}
void deletar_lista(Lista *lista){
    while(lista->inicio != NULL){
        free(lista->inicio);
        lista->inicio = lista->inicio->proximo;
    }
}
void desordenar(char *frase){
    int tam = strlen(frase);
    char aux;
    for (int j = tam - 1; j >= 0; j--) {
        for (int i = 0; i < j; i++) {
            if (frase[i] < frase[i+1]){
                aux = frase[i];
                frase[i] = frase[i+1];
                frase[i+1] = aux;
            }
        }
    }
}
int main() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    inicializar(lista);
    
    char frase[1000];
    fgets(frase, 1000, stdin);

    desordenar(frase);
    verificar(frase, lista);
    // imprimir(lista);
    // deletar_lista(lista);
    // puts("");
    // imprimir(lista);

   
	return 0;
}