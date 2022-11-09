#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef struct node_arv{
    int value, key;
    struct node_arv *left, *right;

}Node_arv;

typedef struct arv_b{
    Node_arv *head;
}Arv_b;

int altura_arv(Node_arv *node){
    if(node == NULL || node->right == NULL && node->left == NULL)return 1;

    else{
        int esq = 1 + altura_arv(node->left);
        int dir = 1 + altura_arv(node->right);

        if(esq > dir)return esq;
        else return dir;
    }
}

void inicialize(Arv_b *arv, int element){
    Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
    new_node->key = element;
    new_node->value = 0;
    new_node->left = NULL; 
    new_node->right = NULL;
    arv->head = new_node;
}

Node_arv* insert_node(int element){
    Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
    new_node->key = element;
    new_node->left = NULL; 
    new_node->right = NULL;
    return new_node;
}

void insert(Arv_b *arv, int i, int letf, int right, int value, Arv_b *arv1){
    
    arv1[i].head->value = value;
    
    if(letf == -1)arv->head->left = NULL;
    else arv->head->left = insert_node(letf);

    if(right == -1)arv->head->right = NULL;
    else arv->head->right = insert_node(right);

}

void impress(Node_arv *head){
    if(head){
        printf("%d ", head->value);
        impress(head->left);
        impress(head->right);
    }
    
}

void insert_arv_comp(Node_arv *node, Arv_b *arv){
    if(node){
    
        node->left = arv[node->key].head->left;
        node->right = arv[node->key].head->right;
        node->value = arv[node->key].head->value;
        
        insert_arv_comp(node->left, arv);
        insert_arv_comp(node->right, arv); 
    }
}

int quest_for_level(Node_arv *node, int nivel, int *array, int *cont, int l){
    if(node){
        quest_for_level(node->left, nivel + 1, array, cont, l);
        if(nivel == l){
            array[*cont] = node->value;
            (*cont)++;
        }
        quest_for_level(node->right, nivel + 1, array, cont, l);
    }
}

int main(){
    
    int qtd;
    scanf("%d", &qtd);
    Arv_b *arv = (Arv_b*)malloc(sizeof(Arv_b)*qtd);
    Arv_b *arv_completa = (Arv_b*)malloc(sizeof(Arv_b));
    
    for(int i = 0; i<qtd; i++){
        inicialize(&arv[i], i);
        int letf, right, value;
        scanf("%d %d %d", &value, &letf, &right);
        insert(&arv[i], i, letf, right, value, arv);
    }
    arv_completa->head = arv[0].head;
    
    insert_arv_comp(arv_completa->head, arv);    

    int altura = altura_arv(arv_completa->head);
        
    
    
    for(int l=1; l<=altura; l++){
        int c=0, *cont = &c;
        int array[10];
        quest_for_level(arv_completa->head, 1, array, cont, l);
        int maior, menor;
        for(int k=0; k<(*cont); k++){
            if(k == 0){
                maior = array[k];
                menor = array[k];
            }
            else{
                if(array[k] >= maior)maior = array[k];
                if(array[k] <= menor)menor = array[k];
            }
        }
        printf("Nivel %d: Maior = %d, Menor = %d\n", l, maior, menor);
    }

    return 0;
}