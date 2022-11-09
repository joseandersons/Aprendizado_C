#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct no_queue{
    int element;
    struct no_queue *next;
}; 
struct queue{
    struct no_queue *head;
    struct no_queue *tail;
    int size;
};
void initialize(struct queue *queue){
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}
void insert_end(struct queue *queue, int elemet){
    struct no_queue *new_no = (struct no_queue*)malloc(sizeof(struct no_queue));
    
    new_no->element = elemet;
    new_no->next = NULL;

    if(queue->head == NULL){
        queue->head = new_no;
        queue->tail = new_no;
    }
    else{
        queue->tail->next = new_no;
        queue->tail = new_no;
    }
    queue->size++;
}
void impress(struct queue *queue){
    struct no_queue *no = queue->head;
    if(queue->size != 0){
        while(no != NULL){
            printf("%d ", no->element);
            no = no->next;
        }
    }
    else puts("VAZIA");
}

void dell_queue(struct queue *queue){
    struct no_queue *no, *aux;

    no = queue->head;
    while(no != NULL){       
        aux = no->next;
        free(no);
        no = aux;
        queue->size--;
    }
}
void bluble_short(struct queue *queue){
    struct no_queue *pi, *pj, *p_end = NULL;

    for(pi = queue->head; pi->next != NULL; pi = pi->next){
        for(pj = queue->head; pj->next != p_end; pj = pj->next){
            if(pj->element < pj->next->element){
                int aux = pj->element;
                pj->element = pj->next->element;
                pj->next->element = aux;
                
            }
        }
        p_end = pj;
    }
}
int check(struct queue *queue, struct queue *queue_aux){
    int cont = 0;

    while(queue->head != NULL){
        if(queue->head->element == queue_aux->head->element)cont++;

        queue->head = queue->head->next;
        queue_aux->head = queue_aux->head->next;
    }
    return cont;
}

int main() {

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        struct queue *queue = (struct queue*)malloc(sizeof(struct queue));
        struct queue *queue_aux = (struct queue*)malloc(sizeof(struct queue));
        initialize(queue_aux);
        initialize(queue);
        int v;
        scanf("%d", &v);
        for(int j=0; j<v; j++){
            int elemnt;
            scanf("%d", &elemnt);
            insert_end(queue, elemnt);
            insert_end(queue_aux, elemnt);
        }
        bluble_short(queue);
        int cont = check(queue, queue_aux);

        printf("\n%d", cont);
        dell_queue(queue);
        dell_queue(queue_aux);
    }
    
    
    
	return 0;
}

