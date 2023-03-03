#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FULL 100

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
};
typedef struct queue queue;

void createQueue(queue *q);

int isempty(queue *q);

void enqueue(queue *q, char *value);

char *dequeue(queue *q);

void outMem(queue *q, int delNum, int q_count, char *buffer);

int main()
{
    int input_size = FULL;
    int loop = 0;
    int deNum, q_count;
    char userInput[input_size];
    char output1[FULL] = {'\0'}, output2[FULL] = {'\0'}, buffer[FULL] = {'\0'};
    char *token;
    while (loop != 2)
    {
        queue *q;
        q = malloc(sizeof(queue));
        createQueue(q);
        if (loop == 0)
        {
            scanf("%d", &q_count);
            getchar();
        }
        fgets(userInput, input_size, stdin);
        // Replace the \n with Null characters to split the word.
        if (userInput[strlen(userInput - 1)] == '\n')
        {
            userInput[strlen(userInput) - 1] = '\0';
        }
        if (loop == 1) // Enqueue old node when start second loop.
        {
            token = strtok(buffer, " ");
            while (token != NULL)
            {
                enqueue(q, token);
                printf("Enqueued : %s\n", q->rear->data);
                token = strtok(NULL, " ");
            }
        }
        // Slice string with strtok into token then enqueue each token in loop
        token = strtok(userInput, " ");
        while (token != NULL)
        {
            enqueue(q, token);
            // printf("Enqueued : %s\n", q->rear->data);
            token = strtok(NULL, " ");
        }
        // Show full queue when input node is over max in capacity of queue (q_count).
        if (q->count > q_count)
        {
            q->count = q_count;
            if (loop == 0)
            {
                strcat(output1, "FULLqueue");
                strcat(output1,"\n");
            }
            else
            {
                strcat(output2, "FULLqueue"),
                strcat(output2,"\n");
            }        }
        // printf("Your denum: ");
        scanf("%d", &deNum);
        getchar();
        // Store the first output
        if (loop == 0)
        {
            outMem(q, deNum, q_count, output1);
            // if(deNum - (q->count) < 0)
            // {
            //     printf("About to store node!\n");
                while (q->front != NULL) // Store old node in buffer to next queue.
                {
                    strcat(strcat(buffer, q->front->data)," ");
                    q->front = q->front->next;
                }
            // }
        }
        else
        {
            // printf("it's second!\n");
            outMem(q, deNum, q_count, output2);
        }
        // printf("Current q count : %d\n", q->count);
        loop++;
    }
    output2[strcspn(output2, "\n")] = 0; // Remove newline character from last node.
    printf("%s\n", output1);
    printf("%s\n", output2);
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
        if (!isempty(q))
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
}

char *dequeue(queue *q)
{
    t_stack *tmp;
    tmp = q->front;
    char *n = q->front->data;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (n);
}

void outMem(queue *q, int delNum, int q_count, char *buffer)
{
    int i, node_count = 0;
    // When it is about to last node.
    if (delNum > q->count) // Delete number is more than number of node in queue.
    {
        int last_node = 0;
        while (delNum != 0)
        {
            if (node_count >= q->count)
            {
                strcat(buffer, "None ");
            }
            else if (q->front->next == NULL) // It is the last node.
            {
                // printf("dequeuing last\n");
                strcat(strcat(buffer, q->front->data)," ");
            }
            else
            {
                // printf("dequeuing before last\n");
                strcat(strcat(buffer, q->front->data)," ");
                q->front = q->front->next;
            }
            buffer[strcspn(buffer, "\n")] = 0;
            // printf("Current buffer : %s\n", buffer);
            q_count--;
            node_count++;
            delNum--;
        }
    }
    // When delete node number less than or equal to queue count.
    else if (delNum < q->count || delNum == q->count)
    {
        while (i < delNum)
        {
            // printf("dequeuing\n");
            strcat(strcat(buffer, dequeue(q))," ");
            i++;
            buffer[strcspn(buffer, "\n")] = 0;
            // printf("Current buffer : %s\n", buffer);
            q_count--;
        }
    }
}