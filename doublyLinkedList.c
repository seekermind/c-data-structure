#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
	struct node* prev;
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
	result->prev = NULL;
	return result;
}

node_t *insertAtHead(node_t **head, node_t *node){

	/*
	 *Take the pointer of the head pointer, so that head can be updated in the function.
	 */

	node->next = *head;
	if(*head != NULL) (*head)->prev = node;
	*head = node;
	node->prev = NULL;
	return node;
}

void insertAfterNode(node_t *node, node_t *newnode){
	newnode->prev = node;
	newnode->next = node->next;
	if(node->next != NULL){
		node->next->prev = newnode;
	}
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
		//if this node is the only node in the list, then there should be only a NULL node, and no previous node.	
		if (*head != NULL) (*head)->prev = NULL;
		return;
	} else{
		node->prev->next = node->next;
		if(node->next != NULL) node->next->prev = node->prev;
	}
	node->next = NULL;
	node->prev = NULL;
}

int main(){

	node_t *tmp;
	node_t *head=NULL;
	int n=100;
	for (int i = 0; i < n; ++i) {
		tmp = creatNewNode(i);
		insertAtHead(&head, tmp);
	}

	tmp = findNode(head, 13);
	/*printf("%p\n", tmp);*/
	
	insertAfterNode(tmp, creatNewNode(999));
	
	removeNode(&head, tmp);
	removeNode(&head, head);

	printList(head);
	return 0;
}
