#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef struct no_list{
    int key;
    struct no_list *next;

}NO;
typedef struct list{
    NO *head;
    NO *tail;
    int size;
    
}LIST;
void impress(LIST *list){
    
    NO *atual = list->head;
    while(atual != NULL){
        printf("->%d ", atual->key);
        atual = atual->next;
    }
    if(list->head == NULL){
        printf("->");
    }
}
void inicialize(LIST *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
int add(LIST *list, int element){
    NO *no = list->head;   
    if(no != NULL){
        while(no){
            if(no->key == element){
                return 0;
            } 
            no = no->next;
        }
    }
    NO *new_node = (NO*)malloc(sizeof(NO));
    new_node->key = element;

    if(list->head == NULL){
        new_node->next = NULL;
        list->head = new_node;
    }
    else{
        new_node->next = list->head;
        list->head = new_node;
    }
    list->size++;
    return 1;
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
    inicialize(list);
}
void dell_hash(LIST *table, int size){
    for(int i=0; i<size; i++){
        destruct(&table[i]);
    }
}
void del_element(LIST *list, int element){
    NO *aux, *node = list->head;
   
    if(list->head->key == element){
        aux = list->head;
        list->head = aux->next;
    }
    else{
        while(node->next && node->next->key != element){
            node = node->next;
        }
        if(node->next){
            aux = node->next;
            node->next = aux->next;
            free(aux);          
        }
    }
    list->size--;
}
int quest(LIST *list, int element, int y){
    int cont=0;
    NO *no = NULL, *aux = list->head;
    
    while(aux && aux->key != element){
        aux = aux->next;
        cont++;
    }
    if(aux){
        cont++;
        no = aux;
        if(y)return cont;
        else return 1;
    }
    if(y)return cont;
    else return 0;
    
}
LIST* realoc(LIST *hash, int size){

    LIST *new_hash_table = (LIST*)malloc(sizeof(LIST)*size);

    for(int i=0; i<size; i++){
        inicialize(&new_hash_table[i]);
    }
    for(int i=0; i<(size+1)/2; i++){
        NO *no = hash[i].head, *aux;
        while(no){
            add(&new_hash_table[no->key%size], no->key);
            no = no->next;
        }
    }
    dell_hash(hash, (size+1)/2);
    free(hash);
    return new_hash_table;
}
int quest_large_size(LIST *hash_table, int size){
    int aux_quantidade = hash_table[0].size;
    int aux_id = 0;
    for(int i=1; i<size; i++){
        if(hash_table[i].size > aux_quantidade){
            aux_quantidade = hash_table[i].size;
            aux_id = i;
        }
    }
    return aux_quantidade;
}
void table(LIST *hash_table, int size){
    char opcao[4];
    int size_table = 0;
    int i=0;

    while(scanf("%s", opcao) != EOF){
        if(strcmp(opcao, "PRT") != 0){
            int element;
            scanf("%d", &element);
            if(strcmp(opcao, "ADD") == 0){
                printf("%d ", i);

                int c_v = quest(&hash_table[element%size], element, 1);
                
                if(quest(&hash_table[element%size], element, 0) == 0){
                    add(&hash_table[element%size], element);
                    size_table++;
                    printf("1");
                }
                else{
                    printf("0");
                }
                printf(" %d", c_v);
                if((((double)(size_table)/(double)size)) >= 0.75){
                        size*=2;
                        size-=1;
                        LIST *new_hash = realoc(hash_table, size);
                        hash_table = (LIST*)malloc(sizeof(LIST)*size);
                        hash_table = new_hash;
                    }
            }
            else if(strcmp(opcao, "DEL") == 0){
                printf("%d ", i);
                int c_v = quest(&hash_table[element%size], element, 1);
                if(quest(&hash_table[element%size], element, 0) == 1){
                    del_element(&hash_table[element%size], element);
                    size_table--;
                    printf("1");
                }
                else printf("0");
                printf(" %d", c_v);
            }
            else if(strcmp(opcao, "HAS") == 0){
                printf("%d ", i);

                int c_v = quest(&hash_table[element%size], element, 1);
                if(quest(&hash_table[element%size], element, 0) == 1){
                    printf("1");
                }
                else printf("0");
                printf(" %d", c_v);
            }
        }
        else if(strcmp(opcao, "PRT") == 0){
            int res = quest_large_size(hash_table, size);
            printf("%d %d %d %d", i, size, size_table, res);
        }
        i++;
        puts("");
    }
    // for(int j=0; j<size; j++){
    //     impress(&hash_table[j]);
    //     puts("");
    // }
}
int main(){
    int size = 7;
    LIST *hash_table = (LIST*)malloc(sizeof(LIST)*size);
    for(int i=0; i<size; i++){
        inicialize(&hash_table[i]);
    }
    table(hash_table, size);

    
    
    return 0;
}

