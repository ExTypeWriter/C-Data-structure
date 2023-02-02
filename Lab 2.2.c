#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode * next;
};
typedef struct ListNode ListNode;

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
        ListNode *lastNode = *head; // If head exists then let head be recent node.

        while(lastNode->next != NULL){ // If there is still next node ( Loop until last node).
            lastNode = lastNode->next; 
        }
        lastNode->next = newNode; // Link the last node to the newNode.
    }
 
}

ListNode* reverse(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;
    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *reverseSubList(ListNode* head, int first, int last)
{
    if (first == last)
        return head;
  
    // revs and revend is start and end respectively of the
    // portion of the linked list which need to be reversed.
    // revs_prev is previous of starting position and
    // revend_next is next of end of list to be reversed.
    ListNode *revs = NULL, *revs_prev = NULL;
    ListNode *revend = NULL, *revend_next = NULL;
  
    // Find values of above pointers.
    int i = 1;
    ListNode *curr = head;
    while (curr && i <= last) {
        if (i < first) // Node that order less than first node to reverse will be put as previous node.
            revs_prev = curr;
        if (i == first) // If current index node equal to first index set current node as first node to reverse.
            revs = curr;
        if (i == last) { // If current index node equal to last index set current node as last node to be reverse.
            revend = curr;
            revend_next = curr->next;
        }
        curr = curr->next; // Push current node to next node
        i++;
    }
    revend->next = NULL;
    // Reverse linked list starting with reverse function.
    revend = reverse(revs);
    // If starting position was not head
    if (revs_prev)
        revs_prev->next = revend;
    // If starting position was head
    else
        head = revend;
    revs->next = revend_next;
    printf("Finished\n");
    return head;
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

int main(){ 
    char value[10000];
    int endOfList = 0;
    int nodeCounter = 0;
    int first,last;
    ListNode *head , *temp;
    while(endOfList != 1){
        fgets(value, sizeof(value) ,stdin);
        if(strcmp(value,"END\n") == 0){
            endOfList = 1;
            break;
        }
        CreateNode(&head,atoi(value));
        nodeCounter++;
    }
    scanf("%d %d",&first,&last);
    printf("%d %d\n",first,last);
    reverseSubList(head,first,last);
    printfList(head);
}
