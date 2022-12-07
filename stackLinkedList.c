#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define EMPTY (-1)
#define STACK_LENGTH 5
#define STACK_EMPTY INT_MIN

typedef struct node {
	int value;
	struct node *next;
} node;

typedef node * node_p;

bool push(node_p *stack, int value){
	node *newnode = malloc(sizeof(node));
	if(newnode==NULL) return false;
	newnode->value = value;
	newnode->next = *stack;
	*stack = newnode;
	return true;
}

void printList(node_p head){

	node_p temp = head;
	while (temp != NULL){
		printf("%d -> ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
int pop(node_p *stack){
	if(*stack == NULL) return STACK_EMPTY;

	int result = (*stack)->value;
	node_p tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return result;
}

int main(void){
	node_p s1 = NULL, s2 =  NULL;
	for (int i = 0; i < 10; ++i) {
		push(&s1, 11);
		/*printf("%d ---\t%d\n", i, push(&s1, 11));*/
	}
	/*
	 *int r;V
	 *while ((r = pop()) != STACK_EMPTY) {
	 *        printf("%d\n",r);
	 *}
	 */


	push(&s1, 11);
	push(&s1, 12);
	push(&s1, 13);
	int poped = pop(&s1);
	push(&s1, 14);
	printList(s1);
	return 0;
}
