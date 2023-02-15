#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define FULL 10

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
    scanf("%d",&deNum);
    display(q,deNum);
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
        printf("List is full\n");
    }
}
void reverse(queue *q , t_node** head_ref)
{
    t_node* prev = NULL;
    t_node* current = q->front;
    t_node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;
 
        // Reverse current node's pointer
        current->next = prev;
 
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    q->front = prev;
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
    if(q->front == NULL)
    {
        printf("None\n");
        exit(0);
    }
    int i = 0;
    // Begin printing
    if(delNum > q->count) // Delete number is more than number of node in queue.
    {
        // printf("It's higer!\n");
        int last_node = 0;
        while (delNum!= 0)
        {
            if(q->front->next == NULL)
            {
                if(last_node != 0)
                {
                    printf("None ");
                }  
                else
                {
                    q->front->data[strcspn(q->front->data,"\n")] = 0; // Remove newline character from last node.
                    printf("%s ",q->front->data);
                }
                last_node++;
            }
            else
            {

                printf("%s ",q->front->data);
                q->front = q->front->next;
            }
            delNum--;
        }
    }
    else if(delNum < q->count || delNum == q->count)
    {
        // printf("It's not higher\n");
        // Dequeue the node for delNum times.
        while(i < delNum)
        {
            reverse(q,&(q->front));
            // printf("Dequeing\n");
            dequeue(q);
            i++;
        }
        reverse(q,&(q->front));
        while(q->front != NULL)
        {
            printf("%s ",q->front->data);
            q->front = q->front->next;
        }
    }
}