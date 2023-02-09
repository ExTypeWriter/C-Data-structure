#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node t_node;
struct t_node
{
    char *data;
    t_node *next;
};

t_node *top = NULL;

void push(char *val)
{
    t_node *new_node;
    new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL) // Can't allocate new node.
    {
        printf("STACK OVERFLOW\n");
        exit(1);
    }
    new_node->data = val;
    if (top == NULL) // If stack is empty.
    {
        new_node->next = NULL;
    }
    else
    {
        new_node->next = top;
    }
    top = new_node;
    // printf("%s inserted\n",val);
}
char *pop()
{
    if (top == NULL)
    {
        printf("STACK UNDERFLOW\n");
        exit(1);
    }
    t_node *temp = top;
    char *temp_data;
    strcpy(temp_data, top->data);
    top = top->next;
    free(temp);
    return (temp_data);
}
void show(int max_display)
{
    t_node *temp = top;
    int lastCount = 0;
    while(max_display!= 0){ // Loop until set number of node.
        if(temp->next == NULL){ // If it is the last node or empty node.
            if(lastCount != 0){ // If it is the last node. ( still have data to display )
                printf("None ");
            }
            else{ // It is a empty node ( no data ).
                printf("%s ",temp->data); 
            }
            lastCount++;
        }
        else{
            printf("%s ",temp->data); // Display node.
            temp = temp->next; // Tranverse to next node.
        }
        max_display--;
    }
}

int main()
{   
    int buf_size = 100000;
    int num_shown;
    char buffer[buf_size];
    char retVal[64];
    char *token;
    
    fgets(buffer,buf_size,stdin);
    if(buffer[strlen(buffer)-1] == '\n'){
                buffer[strlen(buffer)-1] = '\0';                                                      
    }
    token = strtok(buffer," ");
    while(token != NULL){
                push(token);
                token = strtok(NULL," ");            
    }
    scanf("%d",&num_shown);
    show(num_shown);
    printf("\n");
}