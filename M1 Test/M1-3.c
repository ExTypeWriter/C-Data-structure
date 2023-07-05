#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULL 1000

struct t_stack
{
    char *data;
    struct t_stack *next;
};
typedef struct t_stack t_stack;

struct queue
{
    int count;
    t_stack *front;
    t_stack *rear;
    int priority;
};
typedef struct queue queue;

void createQueue(queue *q);

int isempty(queue *q);

void enqueue(queue *q, char *value);

char *dequeue(queue *q);

void display(queue *q,int delNum);


int main()
{
        queue *q;
        int input_size = 1000;
		int deNum;
		char userInput[input_size];
		char *token;
        q = malloc(sizeof(queue));
		createQueue(q);
		fgets(userInput,input_size,stdin);
		//Replace the \n with Null characters to split the word.
		if(userInput[strlen(userInput-1)] == '\n')
		{
			userInput[strlen(userInput)-1] = '\0'; 
		}	
		token = strtok(userInput," ");
		while(token != NULL)
		{
			enqueue(q,token);
            // printf("Got it\n");
			token = strtok(NULL," ");
		}
    display(q);
    printf("\n");
    return 0;
}

void createQueue(queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(queue *q)
{
    return (q->rear == NULL);
}

void enqueue(queue *q, char *value)
{
    if (q->count < FULL)
    {
        t_stack *tmp;
        tmp = malloc(sizeof(t_stack));
        tmp->data = value;
        tmp->next = NULL;	
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
            q->rear->priority++;
        }
        else
        {
            q->front = q->rear = tmp;
            q->rear->priority++;
        }
        q->count++;
    }
    else
    {
        printf("LIST IS FULL\n");
    }
}

char *dequeue(queue *q)
{
    t_stack *tmp; 
    tmp = q->front;
    char *n = q->front->data;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(queue *q)
{
    int i = 0
        while(i < q->count)
        {
            q->front->data[strcspn(q->front->data,"\n")] = 0;
            printf("%s ",dequeue(q));
            i++;
        }
}