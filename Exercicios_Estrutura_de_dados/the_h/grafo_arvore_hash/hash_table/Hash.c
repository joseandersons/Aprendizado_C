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

void inicialize(LIST *list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void insert_tail(LIST *list, int element){
    NO *new_node = (NO*)malloc(sizeof(NO));

    new_node->key = element;
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

int divide(int count, int x, int max){
    if(count > max)
		return 0;

	if(x % count == 0)
		return 1;

	return divide(count+2, x, max);
}
int isprime(int x){
	if(x < 3){
		if(x < 2)
			return 0;
		return 1;
	}

	if(x % 2 == 0)
		return 0;

	if(divide(3, x, sqrt(x)))
		return 0;

	return 1;
}
int prime_next(int n){
    
    if(isprime(n) == 1)return n;

    int aux1 = n+1, aux2 = n-1;

    
    while(true){
        if(isprime(aux1) == 1)break;
        aux1++;
    }
    while(true){
        if(isprime(aux2) == 1)break;
        aux2--;
    }
    
    if((aux1 - n) >= (n - aux2)) return aux2;
    else return aux1;   
}
void impress(LIST *list){
    while(list->head){
        printf("-> %d ", list->head->key);
        list->head = list->head->next;
    }
    if(list->head == NULL)printf("-> ");
}
int r_hash(int n, int key){
    return (key % prime_next(n));
}

void hash_table(LIST *table_hash, int size_table, int quantity_elements){

    for(int i=0; i<size_table; i++){
        inicialize(&table_hash[i]);
    }
    for(int i=0; i<quantity_elements; i++){
        int element;
        scanf("%d", &element);
        insert_tail(&table_hash[element%size_table], element);
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
    inicialize(list);
}
void dell_hash(LIST *table, int size){
    for(int i=0; i<size; i++){
        destruct(&table[i]);
    }
}

int main(){

    int size_table, quantity_elements, test_case;
    scanf("%d", &test_case);
    for(int j=0; j<test_case; j++){
        scanf("%d %d", &size_table, &quantity_elements);
        LIST table_hash[size_table];
        hash_table(table_hash, size_table, quantity_elements);

        for(int i=0; i<size_table; i++){//imprimir tabela hash
            printf("%d ", i);
            impress(&table_hash[i]);
            puts("\\");
        }
        puts("");
        dell_hash(table_hash, size_table);
    }
    return 0;
}