// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// A structure to represent a stack
struct t_stack {
    int top;
    unsigned capacity;
    int* array;
};
 
// function to create a stack of given capacity. It initializes size of
// stack as 0
struct t_stack* createStack(unsigned capacity)
{
    struct t_stack* stack = (struct t_stack*)malloc(sizeof(struct t_stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
// Stack is full when top is equal to the last index
int isFull(struct t_stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct t_stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct t_stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    // printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct t_stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct t_stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
 
// Driver program to test above functions
int main()
{
    char buf[10000];
    int i = 0;
    struct t_stack* stack = createStack(10000);
    fgets(buf,sizeof(int),stdin);
    while(buf!= NULL){
        if(buf[i] == '\n'){
            break;
        }
        char *tok = strtok(buf," ");
        stack->array[i] = buf[i];
        push(stack,stack->array[i]);
        i++;
        printf("Get %d\n",i);
    }
    
    pop(stack);
    printf("%d popped from stack\n", pop(stack));
    
 
    return 0;
}