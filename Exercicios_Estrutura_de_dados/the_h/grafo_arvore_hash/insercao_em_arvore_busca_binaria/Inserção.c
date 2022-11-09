#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>



typedef struct node_arv{
    int element;
    struct node_arv *left, *right;

}Node_arv;

typedef struct arv_b{
    Node_arv *head;
}Arv_b;

void insert_right(Node_arv *node, int element);
void insert_left(Node_arv *node, int element);

void inicialize(Arv_b *arv){
    arv->head = NULL;
}

void insert_left(Node_arv *node, int element){
    if(node->left == NULL){
        Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
        new_node->element = element;
        new_node->left = NULL;
        new_node->right = NULL;
        node->left = new_node;
    }
    else{
        if(element < node->left->element)
            insert_left(node->left, element);
        else
            insert_right(node->left, element);
    }
}

void insert_right(Node_arv *node, int element){
    if(node->right == NULL){
        Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
        new_node->element = element;
        new_node->left = NULL;
        new_node->right = NULL;
        node->right = new_node;
    }
    else{
        if(element < node->right->element)
            insert_left(node->right, element);
        else
            insert_right(node->right, element);
    }
}

void insert(Arv_b *arv, int element){
    if(arv->head == NULL){
        Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
        new_node->element = element;
        new_node->left = NULL;
        new_node->right = NULL;
        arv->head = new_node; 
    }
    else{
        if(element < arv->head->element)
            insert_left(arv->head, element);
        else
            insert_right(arv->head, element);
    }
}

void impress(Node_arv *head){
    printf("(");
    if(head){
        printf(" %d  ", head->element);
        impress(head->left);
        printf(" ");
        impress(head->right);
    }
    printf(") ");
    
}

int main(){
    Arv_b *arv = (Arv_b*)malloc(sizeof(Arv_b));
    inicialize(arv);

    int element; 
    while(scanf("%d", &element) != EOF){
        printf("\n----\n");
        insert(arv, element);
        printf("Adicionando %d\n", element);
        printf("   ");
        impress(arv->head);
    }
    printf("\n----");
    return 0;
}
