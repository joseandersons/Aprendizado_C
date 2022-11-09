#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ITEM char
#define TAM 100

typedef struct pilha {
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isfull(TPilha *p) {
    return p->topo == TAM;
}

int isempty(TPilha *p) {
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) {

    if( isfull(p) ) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

void cont() {
    
	TPilha *pilha;
    if((pilha = (TPilha*)malloc(sizeof(TPilha)))==NULL)printf("ERRO");
    create(pilha);
    
    char text[1000];
    gets(text);
    
    int i = 0;
    while(1){
        if(text[i] == '(' || text[i] == '['){
            push(pilha, text[i]);
        }
        else if(text[i] == ')' || text[i] == ']'){
            if(pilha->topo != -1){
                if(top(pilha) == '(' && text[i] == ')'){
                    pop(pilha);
                }
                else if(top(pilha) == '[' && text[i] == ']'){
                    pop(pilha);
                } 
            }
            else push(pilha, text[i]);
        }
        if(text[i] == '\0')break;
        i++;
    
               
    }
    if(pilha->topo == -1)puts("Yes");
    else puts("No");
}


int main(void) {
    int tam;

    scanf("%d ", &tam);
    
    for(int i=0; i<tam; i++){
        cont();
    }
    
    return 0;
}
