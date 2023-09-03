#include "project3A_queue.h"

// Initialize the queue and allocate memory

void initialize(Queue* q){
	q->capacity = INIT_QUEUE_SIZE;
	q->array = malloc(q->capacity * sizeof(char *));
	if (q->array == NULL){
		printf("mem allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < q->capacity; i++){
		q->array[i] = malloc(MAX_STR_LEN*sizeof(char));
		if (q->array[i] == NULL){
			printf("mem allocation failed\n");
			exit(EXIT_FAILURE);
		}
	
	}
	q->front = 0;
	q->rear = 0;
	q->size = 0;
	
}

// Enqueue an item

void enqueue(Queue* q, char* value){
	if(isFull(q)){	
		resize(q);
	}
	if (q->rear == q->capacity){
		q->rear = 0;
	}
	strcpy(q->array[q->rear], value);
	
	printf("Enqueued (%d): %s\n",q->rear, q->array[q->rear]);
	q->size++;
	q->rear++;
}

// Dequeue an item

char* dequeue(Queue* q){
	if(isEmpty(q)){
		printf("Queue is empty\n");
		return NULL;	
	}	
	char* value = q->array[q->front];
	printf("Dequeued (%d): %s\n", q->front, q->array[q->front]);
	q->front++;
	q->size--;
	
	
	return value;
}

// Check if the queue is empty

int isEmpty(Queue* q){
	return q->size == 0;
}

// Check if the queue is full

int isFull(Queue* q){
	return q->size >= q->capacity;

}

// Resize the queue

void resize(Queue* q){
	int org_capacity = q->capacity;
	q->capacity = org_capacity *  2;
	printf("Resizing queue to %d\n", q->capacity);
	q->array = realloc(q->array, sizeof(char*)*q->capacity);
	if (q->array == NULL){
			printf("mem allocation failed\n");
			exit(EXIT_FAILURE);
		}
	
	for(int i = org_capacity; i < q->capacity; i++){
	
		q->array[i] = malloc(MAX_STR_LEN*sizeof(char));
		if (q->array[i] == NULL){
			printf("mem allocation failed\n");
			exit(EXIT_FAILURE);
		}
		}
	
	if (q->front >= q->rear){
		for(int i = 0; i < q->front; i++){
			q->array[org_capacity] = q->array[i];
			q->array[i] = "";
			org_capacity++;
		}
	}
	
		
}

// Clean up the queue and free the memory

void cleanup(Queue* q){
	printf("Cleaning up queue\n");
	for (int i =0; i < q->capacity; i++){
		free(q->array[i]);
	}
	free(q->array);
}

// Print the queue

void printQueue(Queue* q){
	int count = 0;
	int cur = q->front;
	for (int i = 0; i < q->capacity; i++){
		printf("%d: %s\n", cur, q->array[cur]);				if (cur  == q->capacity - 1){
			cur = 0;
		}else{
			cur++;
		}
		if (count == q->size - 1){
			printf("Capacity: %d, used: %d\n", q->capacity, q->size);
			break;
		}
		count++;
	}	
	
}
