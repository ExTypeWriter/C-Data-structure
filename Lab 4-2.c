#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULL 1000

struct t_node
{
    char *data;
    struct t_node *next;
};
typedef struct t_node t_node;

struct queue
{
    int count;
    t_node *front;
    t_node *rear;
};
typedef struct queue queue;

queue *fillQueue(queue *q);

void createQueue(queue *q);

int isempty(queue *q);

void enqueue(queue *q, char *value);

char *dequeue(queue *q);

void display(queue *q,int delNum);

int main()
{
    int deNum;
    queue *q;
    q = malloc(sizeof(queue));
    createQueue(q);
    fillQueue(q);
    scanf("%d",&deNum);
    display(q,deNum);
    printf("\n");
    return 0;
}

queue *fillQueue(queue *q)
{
    int input_size = 1000;
    char userInput[input_size];
    char *token;
    fgets(userInput,input_size,stdin);
    //Replace the \n with Null characters to split the word.
    if(userInput[strlen(userInput-1)] == '\n') // If last characters is \n.
    {
        userInput[strlen(userInput)-1] = '\0'; // Replace it with NULL characters.
    }	
    token = strtok(userInput," ");
    while(token != NULL)
    {
        enqueue(q,token);
        token = strtok(NULL," ");
    }
    return (q);
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
        t_node *tmp;
        tmp = malloc(sizeof(t_node));
        tmp->data = value;
        tmp->next = NULL;	
        if(!isempty(q))
        {
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else
        {
            q->front = q->rear = tmp;
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
    t_node *tmp; 
    tmp = q->front;
    char *n = q->front->data;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}

void display(queue *q,int delNum)
{
    int lastNode = 0;
    if(q->front == NULL)
    {
        printf("None\n");
        exit(0);
    }
    while(delNum != 0)
    {
        if(q->front->next == NULL && lastNode == 0)
        {
            q->front->data[strcspn(q->front->data,"\n")] = 0; // Remove newline character from last node.
            printf("%s ",q->front->data);
            lastNode += 1;
        }
        else if(lastNode >= 1)
        {
            printf("None ");
        }
        else
        {
            printf("%s ",dequeue(q));
        }
        delNum--;
    }
}