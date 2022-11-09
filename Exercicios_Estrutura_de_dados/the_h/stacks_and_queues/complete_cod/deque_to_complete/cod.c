#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct _deque deque_t;
typedef struct _node   node_t;

//Guarda um ponteiro pro node anterior, para o proximo node e o valor guardado
struct _node {
	node_t *prev;
  	node_t *next;
  	int    value;
};

//Guarda um ponteiro para o primeiro node, um ponteiro para o ultimo node, e o tamanho do deque
struct _deque {
  	node_t *front;
  	node_t  *rear;
  	int      size;
};

//Cria um node que guarda os valores que s�o enfileirados no deque
node_t*  node_new     (int value);

//Cria um deque dinamicamente e retorna seu endere�o de memoria
deque_t* construct    ();
//Libera a mem�ria do conte�do e do pr�prio deque
void     destruct     (deque_t *deque);

//Retorna o tamanho do deque
int      size         (deque_t *deque);
//Retorna verdadeiro se o deque esta vazio, caso contr�rio, retorna falso
bool     empty        (deque_t *deque);

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int      front        (deque_t *deque);
//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int      rear         (deque_t *deque);

//Cria um n� que guarda um valor e o adiciona ao fim do deque
void     enqueue_rear (deque_t *deque, int value);
//Cria um n� que guarda um valor e o adiciona ao inicio do deque
void     enqueue_front(deque_t *deque, int value);
//Retira o valor do final caso n�o esteja vazia
void     dequeue_rear (deque_t *deque);
//Retira o valor da frente caso n�o esteja vazia
void     dequeue_front(deque_t *deque);
//Limpa o conteudo do deque(deixa ele vazio)
void     erase        (deque_t *deque);

//Imprime o deque em uma unica linha, com os elementos separados por um espa�o,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void     print        (deque_t *deque);

int main() {
 	int i, num;
  	scanf("%d", &num);
  
  	deque_t* deque = construct();
  
  	int vector[num];
  	for(i = 0; i < num; ++i)
      	scanf("%d", &vector[i]);
  
  	for(i = 0; i < num; ++i)
      	enqueue_rear(deque, vector[i]);
  
 	printf("%d\n", front(deque));
  	printf("%d\n", rear (deque));
  
  	if(!empty(deque))
  		printf("The size of the deque %d\n", size(deque));
  	else
       	printf("The deque is empty\n");
  	
    scanf("%d", &num);
    for(i = 0; i < num; ++i)
       enqueue_front(deque, i);
  	print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);
    
  	erase(deque);
  	for(i = 0; i < 3; ++i)
  		enqueue_rear(deque, i);
  		
  	print(deque);
    destruct(deque);
       
	return 0;
}






deque_t* construct(){
    deque_t *deque = (deque_t*)malloc(sizeof(deque_t));
    deque->front = NULL;
    deque->rear  = NULL;
    deque->size  = 0;
    return deque;
}
void enqueue_rear (deque_t *deque, int value){
    node_t *new_no = (node_t*)malloc(sizeof(node_t)), *aux;

    new_no->value = value;
    new_no->next = NULL;

    if(deque->front == NULL){
        deque->front = new_no;
        deque->rear = new_no;
        new_no->prev = NULL;
    }
    else{
        aux = deque->rear;
        deque->rear->next = new_no;
        deque->rear = new_no;
        deque->rear->prev = aux;

    }
    deque->size++;
}

int front(deque_t *deque){
    return deque->front->value;
}

int rear(deque_t *deque){
    return deque->rear->value;
}
int size(deque_t *deque){
    return deque->size;
}
bool empty(deque_t *deque){
    if(deque->front == NULL)return 1;
    else return 0;
}
void enqueue_front(deque_t *deque, int value){
    node_t *node_new = (node_t*)malloc(sizeof(node_t)), *aux;

    node_new->value = value;
    node_new->prev = NULL;

    if(deque->front == NULL){
        deque->front = node_new;
        deque->rear = node_new;
        deque->front->next = NULL;
        deque->rear->next = NULL;
    }
    else{
        aux = deque->front;
        deque->front = node_new;
        deque->front->next = aux;
        deque->front->prev = NULL;
    }
    deque->size++;
}
void dequeue_rear (deque_t *deque){
    node_t *no = deque->rear;
    
    deque->rear = deque->rear->prev;
    deque->rear->next = NULL;
    free(no);
    deque->size--;
}
void dequeue_front(deque_t *deque){
    node_t *no = deque->front, *aux = deque->front;

    deque->front = no->next;
    free(aux);
    deque->size--;
}

void print (deque_t *deque){
    node_t *no = deque->front;
    while(no != NULL){
        printf("%d", no->value);
        if(no->next != NULL)printf(" ");
        no = no->next;
    }
    printf("\n");
}
void erase(deque_t *deque){
    node_t *no = deque->front, *aux;
    while(no != NULL){
        deque->front = deque->front->next;
        aux = no->next;
        free(no);
        no = aux;
    }
}

void destruct(deque_t *deque){
    erase(deque);
    free(deque);
}
