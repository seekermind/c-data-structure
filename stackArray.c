#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define EMPTY (-1)
#define STACK_LENGTH 5
#define STACK_EMPTY INT_MIN

struct node {
	int values[STACK_LENGTH];
	int top;
} node;

typedef struct node * node_p;

bool push(node_p *stack, int value){
	if((*stack)->top >= STACK_LENGTH) return false;

	(*stack)->top++;
	(*stack)->values[top] = value;
	return true;
}

int pop(node_p *stack){
	if((*stack)->top == EMPTY) return STACK_EMPTY;

	int result = (*stack)->values[top];
	(*stack)->top--;
	return result;
}

int main(void){

	node_p s1;
	push(&s1, 11);

	/*
	 *bool t=true;
	 *while (t) {
	 *        t = push(10);		
	 *        printf("%d\n",t);
	 *}
	 */
	/*bool t = push(10);*/

	/*printf("%d\n",t);*/
	int r;
	while ((r = pop(&s1)) != STACK_EMPTY) {
		printf("%d\n",r);
	}

	return 0;
}
