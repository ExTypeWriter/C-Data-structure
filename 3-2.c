#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
       char string[64];
       struct stack *next;       
};

void push(struct stack **top, char *stream);
void pop(struct stack **top);
char* peek(struct stack **top);

int main(){
    struct stack *stackForward = NULL, *stackBackward = NULL;
    char buffer[10000] = {'\0'},retVal[64] = {'\0'};
    char *token;
    
    fgets(buffer,10000,stdin);
    if(buffer[strlen(buffer)-1] == '\n'){
                buffer[strlen(buffer)-1] = '\0';                                                      
    }
    token = strtok(buffer," ");
    while(token != NULL){
                push(&stackBackward,token);
                token = strtok(NULL," ");            
    }
    
    
    while(stackBackward != NULL){
                push(&stackForward,peek(&stackBackward));  
                pop(&stackBackward);                 
    }
    while(stackForward != NULL){
                strcpy(retVal,peek(&stackForward));
                printf("%s ",retVal); 
                push(&stackBackward,retVal);
                pop(&stackForward);                  
    }
    printf("\n");
    while(stackBackward != NULL){
                printf("%s ",peek(&stackBackward));  
                pop(&stackBackward);                 
    }    
    return 0;    
}

void push(struct stack **top, char *stream){
     struct stack *newNode = (struct stack*)calloc(1,sizeof(struct stack));
     strcpy(newNode->string,stream);
     if(*top == NULL){
             newNode->next = NULL;
             *top = newNode;        
     }     
     else{
          newNode->next = *top;
          *top = newNode;     
     }
}


void pop(struct stack **top){
     struct stack *freeNode = NULL;
     if(*top == NULL){
             printf("STACK UNDERFLOW\n");
             return;        
     }
     freeNode = *top;
     *top = (*top)->next;
     free(freeNode);
}

char *peek(struct stack **top){
     char *retval = NULL;
     if(*top != NULL){
             retval = (*top)->string;        
     }
     return retval;
}

