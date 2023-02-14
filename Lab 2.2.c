#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode * next;
};
typedef struct ListNode ListNode;

void *CreateNode(ListNode **head,int Inputvalue);
ListNode *reverseSubList(ListNode *head, int first, int last,int counter);    
void printfList(ListNode *head);

int main(){ 
    char value[10000];
    int endOfList = 0;
    int nodeCounter = 0;
    int first,last;
    ListNode *head , *temp;
    while(endOfList != 1){
        scanf("%s",value);
        if(strcmp(value,"END") == 0){
            endOfList = 1;
            break;
        }
        CreateNode(&head,atoi(value));
        nodeCounter++;
    }
    if(nodeCounter!= 0){
        scanf("%d %d",&first,&last);
        reverseSubList(head,first,last,nodeCounter);
        printfList(head);
    }
    
        return(0);
}

void *CreateNode(ListNode **head,int Inputvalue)
{
    // Allocate memory for new nodes.
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->val = Inputvalue; // Assign node value
    newNode->next = NULL; // Link node to nothing.
    if(*head == NULL){ // If head doesn't exist
        *head = newNode; // Assign new node as head.
    }
    else{
        ListNode *lastNode = *head; // If head exists then let head be last node.

        while(lastNode->next != NULL){ // If there is still next node ( Loop until last node).
            lastNode = lastNode->next; 
        }
        lastNode->next = newNode; // Link the last node to the newNode.
    }
}

ListNode *reverseSubList(ListNode *head, int first, int last,int counter)
{
    if (first == last) // If first equal to last node return the list back which mean no sublist to reverse.
        return head;
    if (first<= 0 || last <= 0)
        return head;
    if (first > last)
        return head;    
    if (first > counter || last > counter)
        return head;        
    ListNode temp;
    temp.next = head; // Link temp to head
    ListNode *beforeSubList = &temp; // Set node before sublist at temp address.
    int currentPos = 1;
    while(currentPos < first){ // While first node of sublist not found
        beforeSubList = beforeSubList->next; // Point to next node.
        currentPos++;
    }
    ListNode *currentNode = beforeSubList->next;
    while(first < last){
        ListNode *extractNode = currentNode->next;
        currentNode->next = extractNode->next;
        extractNode->next = beforeSubList->next;
        beforeSubList->next = extractNode; 
        first++;
    }
    return (head);
}

void printfList(ListNode *head)
{

    while (head!= NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}