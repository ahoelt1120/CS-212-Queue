#include "project3A_queue.h"
int main(int argc, char *argv[]){
	(void)argc;
	if ((argv[1] == NULL) || (argv[2] == NULL)){
		printf("Please provide a file name and a delimiter\n");
		exit(EXIT_FAILURE);
	}
	FILE *f = fopen(argv[1], "r");
	FILE *f_cpy = fopen(argv[1], "r");
	char* delim_str = argv[2];
	int buff_size;
	char *buffer;
	char *token;
	Queue *q = malloc(sizeof(Queue));

	if (q == NULL){
		printf("Failed to initialize queue");
		exit(EXIT_FAILURE);
	}

	// Reading file to buffer
	fseek(f, 0, SEEK_END);
	buff_size = ftell(f);
	fseek(f, 0, SEEK_SET);
	buffer = (char *)malloc(buff_size * sizeof(char)+1);
	buffer[buff_size] = 0;

	fread(buffer, sizeof(char), buff_size, f);
	
	if(f == NULL || f == NULL){
		printf("Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	// Tokenizing, initializing, and enqueuing
	token = strtok(buffer, delim_str);
	initialize(q);
	int count = 0;
	printf("=> First enqueuing pass\n");
	while( token != NULL ){
		
		enqueue(q, token);	
		token = strtok(NULL, delim_str);
		
		count++;
	}

	// Dequeuing
	int x = 0;
	printf("=> Dequeuing all elements\n");		
	while(x < count){
		
		 dequeue(q);
		 x++;
		

	}

	// Second file reading and second enquing
	fread(buffer, sizeof(char),buff_size,f_cpy);
	
	token = strtok(buffer, delim_str);
	printf("=> Second enqueuing pass\n");
	while( token != NULL ){
		
		enqueue(q, token);	
		token = strtok(NULL, delim_str);
		

	}

	// Printing and cleaning up queue

	printf("=> Printing queue\n");	
	printQueue(q);
	printf("\n");

	printf("=> Calling Queue cleanup\n");
	cleanup(q);

	// Freeing all additional memory

	free(q);	
	free(buffer);
	fclose(f);
	fclose(f_cpy);
	return(0);

}
