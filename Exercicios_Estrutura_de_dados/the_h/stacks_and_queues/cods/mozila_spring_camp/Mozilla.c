#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct no_stack NO_STACK;
typedef struct _stack STACK;

struct no_stack{
    int element;
    NO_STACK *next;

};

struct _stack{
    NO_STACK *head;
    int tail;
};

void create_stack(STACK *stack){
    stack->head= NULL;
}
void push(STACK *stack, int element){
    NO_STACK *new_no = (NO_STACK*)malloc(sizeof(NO_STACK));
    
    new_no->element = element;
    new_no->next = stack->head;
    stack->head = new_no;
}
int pop(STACK *stack){
    int no = stack->head->element;
    NO_STACK *x = stack->head;
    stack->head = stack->head->next;
    free(x);
    return no;
}
int top(STACK *stack){
    return stack->head->element;
}

void empty_stack(STACK *stack){
    while(stack->head != NULL){
        pop(stack);
    }
}

void ler(STACK *stack_back, STACK *stack_forward){
    char acao[10];
    
    while(scanf("%s", acao) != EOF){
        if(strcmp(acao, "ENTER") == 0){
            // create_stack(stack_forward);
            empty_stack(stack_forward);
            if(stack_back->head != NULL)push(stack_back, top(stack_back)+1);
            else push(stack_back, 0);
        }
        else if(strcmp(acao, "BACK") == 0){
            pop(stack_back);
            if(stack_forward->head != NULL)push(stack_forward, top(stack_forward)+1);
            else push(stack_forward, 1);
        }
        else{
            if(stack_forward->head != NULL){
                push(stack_forward, top(stack_forward)-1);
                push(stack_back, top(stack_back)+1);
            }
        }
    }
}

int main() {
    STACK *stack_back = (STACK*)malloc(sizeof(STACK));
    STACK *stack_forward = (STACK*)malloc(sizeof(STACK));
    create_stack(stack_back);
    create_stack(stack_forward);

    ler(stack_back, stack_forward);

    printf("BACK: %d\nFORWARD: %d", top(stack_back), top(stack_forward));
	return 0;
}

