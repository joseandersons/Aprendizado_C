#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

typedef struct no_arv{
    int element;
    struct no_arv *left, *right;
}Node_arv;

int altura_arv(Node_arv *node){
    if(node == NULL || node->right == NULL && node->left == NULL)return 1;

    else{
        int esq = 1 + altura_arv(node->left);
        int dir = 1 + altura_arv(node->right);

        if(esq > dir)return esq;
        else return dir;
    }
}

void impress(Node_arv *head){

    if(head){
        printf("%d ", head->element);
        impress(head->left);
        impress(head->right);
    }
    
}
void rmv(char *str){ 
    int count=0,i;
    for(i=0;str[i];i++){
        if(str[i]!=' '){
            str[count++]=str[i];
        }
    }
    str[count]=0;
}
bool eBinariaBusca(Node_arv *arvore)
{
    if(arvore == NULL)return true;

    if(arvore && arvore->right == NULL && arvore->left == NULL && arvore == NULL)return true;
            
    if(arvore->left && arvore->left->element >= arvore->element)return false;
        
    if(arvore->right && arvore->right->element <= arvore->element)return false;
            
    if(eBinariaBusca(arvore->right) && eBinariaBusca(arvore->left))return true;
} 
void imprimirSeEArvBinBusca(Node_arv *arv) {
   if (eBinariaBusca(arv))
      printf("VERDADEIRO");
   else
      printf("FALSO");
}

Node_arv* insert_node(int element){
    Node_arv *new_node = (Node_arv*)malloc(sizeof(Node_arv));
    new_node->element = element;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node_arv* insert(char *elements, int *i, Node_arv *arv){
	if(elements[*i] == '(') {
		(*i)++;
	}
	if(elements[*i] == ')'){
		(*i)++;
		return NULL;
	}else {
        int value = elements[*i]-48;
        if(elements[(*i)+1] != '(' && elements[(*i)+1] != ')'){
            char aux[3];
            aux[0] = elements[*i];
            aux[1] = elements[(*i)+1];
            (*i)++;
            value = atoi(aux);
        }
        (*i)++;
		arv = insert_node(value);
		arv->left = insert(elements, i, arv);
		arv->right = insert(elements, i, arv);
	}
	(*i)++;
	return arv;
}

void binary_comp(Node_arv *arv, int *i, int *cont){
    
    if(arv){
        (*cont)++;
        binary_comp(arv->left, i, cont);
        if(!(arv->left) || !(arv->right)){
            if(arv->left || arv->right){
                (*i)++;
                if(*i == 1)printf("nao completa\nnos com um filho: ");
                printf("%d ", arv->element);
                (*i) = -50;
            }
        }
        binary_comp(arv->right, i, cont);
    }
}
int main()
{
    Node_arv *arv = (Node_arv*)malloc(sizeof(Node_arv));
    arv = NULL;
    

    char element[1000];
    fgets(element, 1000, stdin);
    rmv(element);//remove os espa�os em branco
    
    int tam = strlen(element);
    
    int ind=0, *indice=&ind, c=0, *cont=&c, id=0, *i=&id;

    arv = insert(element, indice, arv);
    
    binary_comp(arv, i, cont);
    if((*i)>=0)printf("completa\ntotal de nos: %d", *cont);;


    // impress(arv);
    // imprimirSeEArvBinBusca(arv);

   return 0;
}

