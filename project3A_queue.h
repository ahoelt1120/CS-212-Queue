//add ifndef endif define statements
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_QUEUE_SIZE 8
#define MAX_STR_LEN 256

typedef struct queue{
	char** array;
	int front;
	int rear;
	int capacity;
	int size;
}Queue;


void initialize(Queue* q);
void cleanup(Queue* q);
int isFull(Queue* q);
int isEmpty(Queue* q);
void resize(Queue* q);
void enqueue(Queue* q, char* value);
char* dequeue(Queue* q);
void printQueue(Queue* q);

#endif
