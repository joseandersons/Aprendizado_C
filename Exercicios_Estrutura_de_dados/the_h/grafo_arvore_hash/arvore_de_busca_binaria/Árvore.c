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
int main()
{
    Node_arv *arv = (Node_arv*)malloc(sizeof(Node_arv));
    arv = NULL;

    char element[1000];
    fgets(element, 1000, stdin);
    rmv(element);//remove os espa�os em branco
    
    int tam = strlen(element);
    
    int indice= 0;

    arv = insert(element, &indice, arv);
    
    //impress(arv);
    imprimirSeEArvBinBusca(arv);

   return 0;
}

