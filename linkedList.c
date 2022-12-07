#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
};

typedef struct node node_t;

void printList(node_t *head){

	node_t *temp = head;
	while (temp != NULL){
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

node_t *creatNewNode(int value){
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}

node_t *insertAtHead(node_t **head, node_t *node){

	/*
	 *Take the pointer of the head pointer, so that head can be updated in the function.
	 */

	node->next = *head;
	*head = node;
	return node;
}

void insertAfterNode(node_t *node, node_t *newnode){
	newnode->next = node->next;
	node->next = newnode;
}

node_t *findNode(node_t *head, int value){
	node_t *tmp = head;
	while(tmp != NULL){
		if(tmp->value == value) return tmp;
		tmp = tmp->next;
	}
	return NULL;
}
void removeNode(node_t **head, node_t *node){
	if(*head == node){
		*head = node->next;	
		return;
	} else{
		node_t *tmp = *head;
		while(tmp != NULL){
			if(tmp->next == node) {
				tmp->next = node->next;
				node->next = NULL;
				break;
			}
			tmp = tmp->next;
		}
	}
}

int main(){

	node_t *tmp;
	node_t *head=NULL;
	int n=10;
	for (int i = 0; i < n; ++i) {
		tmp = creatNewNode(i);
		insertAtHead(&head, tmp);
	}

	tmp = findNode(head, 13);
	/*printf("%p\n", tmp);*/
	
	insertAfterNode(tmp, creatNewNode(999));
	
	removeNode(&head, tmp);

	printList(head);
	return 0;
}
