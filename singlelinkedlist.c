#include<stdio.h>
#include<stdlib.h>

struct node{
	int data; struct node *next;
};

struct node *create_node(){
	struct node *node = (struct node *)malloc(sizeof(struct node));
	while( node == NULL)
		node = (struct node *)malloc(sizeof(struct node));

	node->data = 0;
	node->next = NULL;
	return node;
}

void insert_at_beginning(struct node **HEAD){
	struct node *new_node = create_node();
	printf("Enter data into new node - ");	scanf("%d", &(new_node->data));
	if(HEAD != NULL) 
		new_node->next = *HEAD;
	*HEAD = new_node;
	return;
}

struct node *create_list(){
	struct node *HEAD = NULL;
	insert_at_beginning(&HEAD);
	return HEAD;
}

void insert_at_end(struct node **HEAD){
	struct node *new_node = create_node();
	printf("Enter data into new node - ");	scanf("%d", &(new_node->data));
	struct node *node = *HEAD;
	if(*HEAD == NULL){
		*HEAD = new_node; return;
	}
	while(node->next != NULL)
		node = node->next;
	node->next = new_node;
	return;
}

void insert_at_n(struct node **HEAD, int n){
	//Inserts after the node with 'n'
	if(*HEAD == NULL){
		printf("Empty list"); return;
	}
	struct node *new_node = create_node();
	printf("Enter data into new node - ");	scanf("%d", &(new_node->data));
	struct node *node = *HEAD;
	while(node != NULL && node->data != n)
		node = node->next;
	if(node == NULL){
		printf("The required data doesn't exist in list"); free(new_node); return;
	}
	new_node->next = node->next;
	node->next = new_node;
	return;
}

struct node *search_list(struct node **HEAD, int n){
	//returns the node if the data exists, returns NULL else
	if(*HEAD == NULL) return NULL;
	struct node *node = *HEAD;
	while(node != NULL && node->data != n)
		node = node->next;
	if(node == NULL) return NULL;
	return node;
}



void traverse(struct node **HEAD){
	struct node *node = *HEAD;
	if(node == NULL){
		printf("Empty list"); return;
	}
	while(node != NULL){
		printf("%d\t", node->data);
		node = node->next;
	}
}

int main(){
}
