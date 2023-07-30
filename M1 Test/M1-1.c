#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int value;
    int frequency;
    struct data* next;
};
typedef struct data data;

data* head = NULL;
int data_count = 0; 

void bubbleSort(data** arr, int count) { // Sort array of pointer.
    int i = 0;
    int j;
    data* temp;
    while (i < (count - 1)) {
        j = 0;  
        while (j < (count - i - 1)) {
            if (arr[j]->value > arr[j + 1]->value) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}


void InsertFront(int number) {
    data* newData = (data*)malloc(sizeof(data));
    newData->value = number;
    newData->frequency = 1;
    newData->next = head;
    head = newData;
    return;  
}

int findMaxFreq(data* pointer)
{
    pointer = head;
    data* max = (data*)malloc(sizeof(data));
    int max_freq;
    int i = 0;
    while (pointer!= NULL)
    {
        if(i == 0){
            max = pointer; // Set first node as max pointer.
        }
        else if(pointer->frequency > max->frequency && pointer->next != NULL){
            max = pointer; // Copy max pointer.
        }
        else if(pointer->frequency == max->frequency){ // If frequency are equal
            if(pointer->value < max->value){ // And it's value is less than max.
                max = pointer; // Set it as new max.
            }
        }
        pointer = pointer->next;
        i++;
    }
    max_freq = max->value;
    return max_freq;
}

int findMinFreq(data* pointer)
{
    pointer = head;
    data* min = (data*)malloc(sizeof(data));
    int min_freq;
    int i = 0;
    while (pointer!= NULL)
    {
        if(i == 0){
            min = pointer; // Set first node as max pointer.
        }
        else if(pointer->frequency < min->frequency && pointer->next != NULL){
            min = pointer; // Copy max pointer.
        }
        else if(pointer->frequency == min->frequency){ // If frequency are equal
            if(pointer->value < min->value){ // And if it's value is lower than the old min.
                // printf("%d is lower than %d\n",pointer->value,min->value);
                min = pointer; // Set it as new min.
            }
        }
            pointer = pointer->next;
        i++;
    }
    min_freq = min->value;
    return min_freq;
}

void displayData(int count) {
    data* p = head;
    printf("n: ");
    data* displayArr[count]; 
    int i = 0;
    // printf("Test input list Value: ");
    while (p != NULL && i < count) {
        displayArr[i] = p;  // Assign the pointer to each element
        // printf("%d ",p->value);
        p = p->next;
        i++;
    }
    
    bubbleSort(displayArr, count);
    int j;
    for (j = 0; j < count; j++) {
        printf("%d ", displayArr[j]->value);
    }
    printf("\n");

    printf("f: ");
    for (j = 0; j < count; j++) {
        printf("%d ", displayArr[j]->frequency);
    }
    printf("\n");
}


void FreqOrInsert(int check_val) {
    data* p = head;
    while (p != NULL) {
        if (p->value == check_val) {
            p->frequency += 1;
            return;
        }
        p = p->next;
    }
    InsertFront(check_val);
    data_count++;
}

int getData() {
    char buffer[1024];
    char* token;
    printf("Insert data: ");
    fgets(buffer, 1024, stdin);
    if (buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }
    token = strtok(buffer, " ");
    while (token != NULL) {
        FreqOrInsert(atoi(token));
        token = strtok(NULL, " ");
    }
    return 0;  
}

int main() {
    getData();
    displayData(data_count);
    int max = findMaxFreq(head);
    printf("Max = %d\n",max);
    int min = findMinFreq(head);
    printf("Min = %d\n",min);
    return 0;
}
