#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#define MAX_SIZE 100

typedef struct no_list{
    char element[10];
    struct no_list *next;

}NO;

typedef struct list{
    NO *head;
    NO *tail;
    char from[10];
    int size;

}LIST;

void impress(LIST *list){
    
    NO *atual = list->head;
    
    while(atual != NULL){
        printf("%s\n", atual->element);
        atual = atual->next;
    }
   
}
void inicialize(LIST *list){
    list->head = NULL;
    list->tail = NULL;
    strcpy(list->from, "NULL");
    list->size = 0;
}
void add(LIST *list, char *element){
    NO *new_node = (NO*)malloc(sizeof(NO));
    strcpy(new_node->element, element);
    new_node->next = NULL;

    if(list->head == NULL){
        list->head = new_node;
        list->tail = new_node;
    }
    else{
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}
void insert_short(LIST *list, char *element){
    NO *novo, *aux;
    if((novo = (NO*)malloc(sizeof(NO)))==NULL)return;
    if((aux = (NO*)malloc(sizeof(NO)))==NULL)return;

    strcpy(novo->element, element);
    if(list->head == NULL){
        novo->next = NULL;
        list->head = novo;
    }
    
    else if(strcmp(novo->element, list->head->element) < 0){
        novo->next = list->head;
        list->head = novo;
    }
    else{
        aux = list->head;
        
        while(aux->next && strcmp(novo->element, list->head->next->element) > 0){
            aux = aux->next;
        }
        novo->next = aux->next;
        aux->next = novo;
    }

}
void erase(LIST *list){
    NO *no = list->head, *aux;
    while(no != NULL){
        list->head = list->head->next;
        aux = no->next;
        free(no);
        no = aux;
    }
}
void destruct(LIST *list){ 
    erase(list);
}
void dell_hash(LIST *table){
    for(int i=0; i<MAX_SIZE; i++){
        destruct(&table[i]);
    }
}
void del_element(LIST *list, char *element){
    
    NO *aux, *node = list->head;
    int cont = 0;
    if(node){
        if(strcmp(list->head->element, element) == 0){
            aux = list->head;
            list->head = aux->next;
            cont++;
        }
        else{
            while(node->next && strcmp(node->next->element, element) != 0){
                node = node->next;
            }
            if(node->next){
                aux = node->next;
                node->next = aux->next;
                free(aux);
                cont++;         
            }
        }
        if(cont)list->size--;
    }
}
int quest(LIST *list){
    if(strcmp(list->from, "NULL") != 0)return 1;
    else return 0;
}
int funcaoHashString(char str[]){ // retorna uma kay a partir de uma string
    int i, tam = strlen(str);
    unsigned int hash = 0;

    for(i = 0; i < tam; i++)
        hash += str[i] * (i + 1); // somat�rio questdo c�digo ASCII vezes a posi��o
    return hash % MAX_SIZE;
}
void impress_leaf(LIST *grafo, int fonte){
    
    if((strcmp(grafo[fonte].from, "NULL") == 0))return;
    
    LIST *list_en = (LIST*)malloc(sizeof(LIST));
    inicialize(list_en);

    for(int i=0; i < MAX_SIZE; i++){
        if(grafo[i].size == 0 && (strcmp(grafo[i].from, "NULL") != 0)){
            char aux[10];
            strcpy(aux, grafo[i].from);
            insert_short(list_en, aux);
            strcpy(grafo[i].from, "NULL");
        }
    }
    impress(list_en);
    NO *node = list_en->head;
    while(node){
        for(int i=0; i<MAX_SIZE; i++){
            del_element(&grafo[i], node->element);
        }
        node = node->next;
    }
    destruct(list_en);
    free(list_en);
    impress_leaf(grafo, fonte);
}

int main(){
    int tam;
    while(scanf("%d", &tam) != EOF){
        LIST *grafo = (LIST*)malloc(sizeof(LIST)*MAX_SIZE);
        for(int i=0; i < MAX_SIZE; i++){
            inicialize(&grafo[i]);
        } 
        int fonte;
        for(int i=0; i<tam; i++){
            char ver_1[10], ver_2[10];
            scanf("%s %s", ver_1, ver_2);
            
            if(i == 0)fonte = funcaoHashString(ver_1);
            int p_v1 = funcaoHashString(ver_1);
            int p_v2 = funcaoHashString(ver_2);
            if(!quest(&grafo[p_v1])){
                strcpy(grafo[p_v1].from, ver_1);
                add(&grafo[p_v1], ver_2);
                strcpy(grafo[p_v2].from, ver_2);
            }
            else{
                add(&grafo[p_v1], ver_2);
                strcpy(grafo[p_v2].from, ver_2);
            }
        }
        impress_leaf(grafo, fonte);
        dell_hash(grafo);
        free(grafo);
    }
    return 0;
}

