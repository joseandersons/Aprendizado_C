#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Armazena o primeiro item da fila
typedef struct _stack STACK;

//Armazena o conteudo do no e um ponteiro para o proximo no da fila
typedef struct _node NODE;

struct _stack
{
    NODE* head;
};
struct _node
{
    int element;
    NODE* next;
};

//Cria uma stack com o a head NULL
STACK* Create_stack();

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element);

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack);

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack);

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element);

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation);

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size);

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

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

int POP(STACK* stack){
    if(IS_EMPTY == 0){
        puts("underflow");
        abort();
    }
    NODE *no = stack->head;
    int x = stack->head->element;
    stack->head = stack->head->next;
    free(no);
    return x;
}

void PUSH(STACK* stack, int element){

    NODE *no_new = (NODE*)malloc(sizeof(NODE));
    no_new->element = element;
    no_new->next = stack->head;
    stack->head = no_new;
}
void Calculadora(STACK* calculadora, int size){
    for(int i=0; i<size; i++){
        char x[6];
        scanf("%s", x);
        if(x[0] != '/' && x[0] != '-' && x[0] != '*' && x[0] != '+'){
            int num = atoi(x);
            PUSH(calculadora, num);
        }
        else{
            switch(x[0]){
                int a, b, res;
                case '+':
                    b = POP(calculadora);
                    a = POP(calculadora);
                    res = a + b ;
                    PUSH(calculadora, res);
                    break;
                case '-':
                    b = POP(calculadora);
                    a = POP(calculadora);
                    res = a - b ;
                    PUSH(calculadora, res);
                    break;
                case '*':
                    b = POP(calculadora);
                    a = POP(calculadora);
                    res = a * b ;
                    PUSH(calculadora, res);
                    break;
                default :
                    b = POP(calculadora);
                    a = POP(calculadora);
                    res = a / b ;
                    PUSH(calculadora, res);
                    break;
            }
        }
        
    }
    

}
