#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULL 1000

struct t_stack
{
    char *data;
    int priority;
    struct t_stack *next;
};
typedef struct t_stack t_stack;

struct queue
{
    int count;
    t_stack *front;
    t_stack *rear;
};
typedef struct queue queue;

void createQueue(queue *q);
int isempty(queue *q);
void enqueue(queue *q, char *value, int priority);
char *dequeue(queue *q);
void display(queue *q);
int priorityCheck(char* string);

int main()
{
    queue *q;
    int input_size = 1000;
    char userInput[input_size];
    char *token;

    q = malloc(sizeof(queue));
    createQueue(q);

    fgets(userInput, input_size, stdin);
    if (userInput[strlen(userInput) - 1] == '\n')
    {
        userInput[strlen(userInput) - 1] = '\0';
    }

    token = strtok(userInput, "");
    while (token != NULL)
    {
        // Read the priority as well
        if(token )
        enqueue(q, token, priorityCheck(token));
        printf("enqueued %s!",token);
        token = strtok(NULL, " ");
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

void enqueue(queue *q, char *value, int priority)
{
    if (q->count < FULL)
    {
        t_stack *tmp;
        tmp = malloc(sizeof(t_stack));
        tmp->data = malloc(strlen(value) + 1);
        strcpy(tmp->data, value);
        tmp->priority = priority;
        tmp->next = NULL;

        if (isempty(q))
        {
            q->front = q->rear = tmp;
        }
        else if (priority == 2)
        {
            tmp->next = q->front;
            q->front = tmp;
        }
        else
        {
            t_stack *current = q->front;
            while (current->next != NULL && current->next->priority == 2)
            {
                current = current->next;
            }
            tmp->next = current->next;
            current->next = tmp;
            if (current == q->rear)
            {
                q->rear = tmp;
            }
        }
        q->count++;
    }
    else
    {
        printf("QUEUE IS FULL\n");
    }
}




char *dequeue(queue *q)
{
    if (isempty(q))
    {
        printf("QUEUE IS EMPTY\n");
        return NULL;
    }
    else
    {
        t_stack *tmp = q->rear;
        char *n = tmp->data;
        q->rear = q->rear->next;
        free(tmp);
        q->count--;
        return n;
    }
}

void display(queue *q)
{
    t_stack *current = q->rear;
    t_stack *stack = NULL;

    // Push elements with priority 1 onto a separate stack
    while (current != NULL && current->priority == 1)
    {
        t_stack *next = current->next;
        printf("Pushed! %s\n",current->data);
        current->next = stack;
        stack = current;
        current = next;
    }

    // Print elements with priority 2
    while (current != NULL && current->priority == 2)
    {
        printf("%s ", current->data);
        current = current->next;
    }

    // Print elements with priority 1 from the stack
    while (stack != NULL)
    {
        printf("%s ", stack->data);
        t_stack *next = stack->next;
        stack->next = current;
        current = stack;
        stack = next;
    }
}




int priorityCheck(char* string) {
    char* high_priority_dict = "aAeEiIoOuU.!";  // Updated high priority dictionary
    int i = 0;
    int priority = 1;
    
    while (string[i] != '\0') {
        if (strchr(high_priority_dict, string[i]) != NULL) {
            priority = 2;
            return priority;
        }
        i++;
    }
    
    return priority;
}

