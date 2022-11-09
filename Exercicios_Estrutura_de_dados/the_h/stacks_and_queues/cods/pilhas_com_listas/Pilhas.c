#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _stack STACK;

typedef struct _node NODE;

typedef struct _list LISTA;

typedef struct _no_list NO_LIST;

struct _stack{
    NODE* head;
};

struct _node{

    LISTA *element;
    NODE* next;
};

struct _no_list{
    int element;
    NO_LIST *next;
};

struct _list{
    NO_LIST *inicio;
    NO_LIST *fim;
    int tamanho;
};

void inicializar(LISTA *lista){

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
    
}
void inserir_no_fim(LISTA *lista, int valor){
    NO_LIST *novo;
    if((novo = (NO_LIST*) malloc(sizeof(NO_LIST))) == NULL)return;

    novo->element = valor;
    
    novo->next = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }
    else{
        lista->fim->next = novo;
        lista->fim = novo;      

    }

    lista->tamanho++;
}

STACK* Create_stack() {
    STACK  *pilha = (STACK*)malloc(sizeof(STACK));
    pilha->head = NULL;
    return pilha;
}

int IS_EMPTY(STACK* stack){
    if(stack == NULL)return 0;
    else 1;
}

NODE* POP(STACK* stack){
    
    NODE *no = stack->head;
    NODE *x = stack->head;
    stack->head = stack->head->next;
    //free(no);
    return x;
}

void PUSH(STACK* stack, LISTA *element){

    NODE *no_new = (NODE*)malloc(sizeof(NODE));
    no_new->element = element;
    no_new->next = stack->head;
    stack->head = no_new;
    
}
void imprimir(LISTA *lista){
    NO_LIST *atual = lista->inicio;
    while(atual != NULL){
        printf("%d", atual->element);
        if(atual->next != NULL) printf(" ");
        atual = atual->next;
    }
}

void ler(STACK *stack){
    char funcao[5];
    while(scanf(" %s", funcao) != EOF){
        
        LISTA *lista;
        if((lista = (LISTA*)malloc(sizeof(LISTA)))==NULL)return;
        inicializar(lista);
    
        if(strcmp(funcao, "PUSH") == 0){
            while(1){
                
                char espaco;
                int valor;

                scanf("%d", &valor);
                scanf("%c", &espaco);
                inserir_no_fim(lista, valor);
                if(espaco == '\n')break;
            }
            PUSH(stack, lista);
        }
        if(strcmp(funcao, "POP") == 0){

            if(stack->head != NULL){
                NODE *no = POP(stack);
                imprimir(no->element);
                printf("\n");
            }
            else puts("EMPTY STACK");
        }
    }
}
int main()
{
    STACK* stack = Create_stack();  
    ler(stack);
}