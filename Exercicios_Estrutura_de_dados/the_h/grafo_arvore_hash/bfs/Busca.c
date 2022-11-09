#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE 1000

typedef struct _node{
    int item;
    struct _node *proximo;
    struct _node *anterior;
}NODE;

typedef struct _queue{
    NODE *inicio;
    NODE *fim;
    int tamanho;
}QUEUE;

typedef struct _graph{
    short visited[MAX_SIZE];
    int distancia[MAX_SIZE];
    int ant[MAX_SIZE];
}GRAFO;


QUEUE *create_queue(){
    QUEUE *new_queue = (QUEUE*)malloc(sizeof(QUEUE));

    new_queue->inicio = NULL;
    new_queue->fim = NULL;
    new_queue->tamanho = 0;
    
    return new_queue;
}

GRAFO *criar_grafo(){

    GRAFO *graph = (GRAFO*) malloc(sizeof(GRAFO));

    for (int i = 0; i < MAX_SIZE ; i++) {
        graph->visited[i] = 0;
        graph->distancia[i] = -1;
        graph->ant[i] = -1;
    }
    return graph;
}


int vazia(QUEUE *queue){
    if(queue->tamanho==0)return 1;
    else return 0;
}

void enfilerar(QUEUE *queue, int item){
    NODE *new_node = (NODE*)malloc(sizeof(NODE));
    
    new_node->item = item;
    new_node->proximo = NULL;
    
    if(queue->inicio == NULL){
        new_node->anterior = NULL;
        queue->inicio = new_node;
        queue->fim = new_node;
    }
    else{
        new_node->anterior = queue->fim;
        queue->fim->proximo = new_node;
        queue->fim = new_node;
    }
    
    queue->tamanho++;
}

void desenfilerar(QUEUE *queue){
    NODE *aux = NULL;
    
    if(queue->inicio == queue->fim){
        aux = queue->fim;
        queue->inicio = NULL;
        queue->fim = NULL;
        free(aux);
    }
    else{
        aux = queue->inicio;
        queue->inicio = aux->proximo;
        queue->inicio->anterior = NULL;
        free(aux);
    }
    queue->tamanho--;
}
void printt(GRAFO *graph, int o, int v){
    
    puts("");
    for(int i=0; i<v; i++){
        printf("%d | ", i);
        
        if(graph->distancia[i]>=0 && i!=o)printf("%d | %d\n", graph->distancia[i], graph->ant[i]);
        else if(i == o)puts("0 | -");
        else puts("- | -");
    }
    puts("");
}
void pri(GRAFO *graph, int o, int v){
    int i;
    
    printf("\n");
    for(i=0; i<v; i++){
        printf("%d | ", i);
        
        if(graph->distancia[i]>=0 && i!=o){
            printf("%d | %d\n", graph->distancia[i], graph->ant[i]);
        }else if(i == o){
            printf("0 | -\n");
        }else{
            printf("- | -\n");
        }
    }
    printf("\n");
}
void printt2(int a[], int o, int d){
    if(a[d]==-1)printf("%d", d);
    
    else{
        printt2(a, o, a[d]);
        printf(" => %d", d);
    }
}
void bfs(GRAFO *graph, int o, int v, int array[][MAX_SIZE]){
    
    graph->distancia[o] = 0;
    
    QUEUE *queue = create_queue();
    enfilerar(queue, o);
    
    while(1){
        int aux=0;
        int prox=0;
        
        while(vazia(queue) == 0){
            prox = queue->inicio->item;
            desenfilerar(queue);
            
            if(graph->visited[prox]==0){
                graph->visited[prox] = 1;
                aux = 1;
                break;
            }
        }
        if(aux==0)break;
        
        printf("Iniciando busca em largura a partir de %d\n", prox);
        
        for(int i=0; i<v; i++){
            if(array[prox][i] && graph->visited[i] == 0 && graph->distancia[i]<=0){
                graph->distancia[i] =graph->distancia[prox]+1;
                graph->ant[i] = prox;
                enfilerar(queue, i);
            }
        }
    }
}

int main(){
    int array[MAX_SIZE][MAX_SIZE];
    
    int v, a, t, o, d;
    scanf("%d %d %d", &v, &a, &t);
    
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            array[i][j] = 0;
        }
    }
    
    for(int i=0; i<a; i++){
        scanf("%d%d", &o, &d);
        array[o][d] = 1;
    }
    
    for(int i=0; i<t; i++){
        puts("--------\n");
        scanf("%d %d", &o, &d);
        printf("Caso de Teste #%d - BFS(%d)\n\n",i+1, o);
        
        GRAFO *grafo = criar_grafo();

        bfs(grafo, o, v, array);
        printt(grafo, o, v);
        
        if(grafo->distancia[d]>=0){
            printf("Caminho entre %d e %d: ", o, d);
            printt2(grafo->ant, o, d);
        }else{
            printf("Sem caminho entre %d e %d", o, d);
        }
        puts("\n");
    }
    
    printf("--------");

    return 0;
}