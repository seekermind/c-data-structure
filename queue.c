#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 10

typedef struct {
	int data[QUEUE_SIZE];
	int head, tail;
} Queue;

bool enqueue(Queue *q, int item){
	if ( ( (q->tail+1) % QUEUE_SIZE) == q->head ) {
		printf("Overpopulated\n");
		// array full
		return false;
	}
	q->data[q->tail] = item;
	q->tail++;
	q->tail %= QUEUE_SIZE;	
	return true;
}

int dequeue(Queue *q){
	if(q->tail == q->head){
		printf("Such a void\n");
		return -999;
	}
	int tmp = q->data[q->head];
	q->head++;
	q->head %= QUEUE_SIZE;
	return tmp;
}

void printQueue(Queue q){
	if (q.tail == q.head)
		printf("Queue is empty\n");
	else{
		int i=q.head;
		while(i != q.tail){
			printf("(%d)\t%d\n", i, q.data[i]);
			i++;
			i %= QUEUE_SIZE;
		}
	}
}

int main(int argc, char *argv[]){
	Queue q;
	q.head = 0;
	q.tail = 0;

	for (int i = 0; i < QUEUE_SIZE+2; ++i) {
		bool tmp=enqueue(&q, 45);
		printf("%d\t%d\n", tmp, q.data[q.head-1]);
	}
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	printQueue(q);

	return 0;
}
