#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct t_node
{
    int data;
    struct t_node *next;
};

void swap(struct t_node *a, struct t_node *b); 
void bubbleSort(struct t_node *head); // Bubble sort the Linked list.
void insertEND(struct t_node **head, int data); // Inset node at end of Linked list.
void removeDuplicates(struct t_node *head); // Remove duplicates from Linked list.
void printList(struct t_node *head);

int main()
{
    struct t_node *head = NULL;
    int n;
    char input[5];

    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "END") == 0)
        {
            break;
        }
        sscanf(input, "%d", &n);
        insertEND(&head, n);
    }
    bubbleSort(head);
    removeDuplicates(head);
    printList(head);
    printf("\n");
    return 0;
}

void swap(struct t_node *a, struct t_node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(struct t_node *head)
{
    int swapped, i;
    struct t_node *ptr1;
    struct t_node *lptr = NULL;

    /* Checking for empty list */
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to insert a new node at the end
void insertEND(struct t_node **head, int data)
{
    struct t_node *new_node = (struct t_node *)malloc(sizeof(struct t_node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        struct t_node *last = *head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
    }
}

// Function to remove duplicates
void removeDuplicates(struct t_node *head)
{
    struct t_node *current = head;

    struct t_node *next_next;  // temp pointer for next node.

    if (current == NULL) // If node is NULL then exit the function
        exit(0);

    while (current->next != NULL) // Transverse till NULL
    {
        if (current->data == current->next->data) // If next node data is equal to current node data.
        {
            next_next = current->next->next; // Set next_next node as next node's next of the current node
            // Ex. 1 -> 2 -> 3 -> 3 -> 4 now first 3 is current node then next node is 3 and it's a duplicate
            // to our current node collect the next node's next (4) in next_next and free the next node (second 3)
            // Then set the next_next as next node of current node.
            // And now we ge : 1-> 2 -> 3 -> 4.
            free(current->next);
            current->next = next_next;
        }
        else 
        {
            current = current->next; // Tranverse to next node.
        }
    }
}

void printList(struct t_node *head)
{
    if (head == NULL)
    {
        printf("None");
        return;
    }
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}