#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char *data;
    int priority;
    struct node *next;
} node;
typedef struct priority_queue {
    node *head;
} priorityqueue;


node *createnode(char *data, int priority) { //คือการสร้าง node ใหม่ เพื่อเก็บข้อมูลของ data และ priority ที่สร้างขึ้นมา
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}
priorityqueue *createpriorityqueue() { //คือการสร้าง queue ใหม่ เพื่อเก็บข้อมูลของ node ที่สร้างขึ้นมา
    priorityqueue *newqueue = (priorityqueue*)malloc(sizeof(priorityqueue));
    newqueue->head = NULL;
    return newqueue;
}

void enqueue(priorityqueue *queue, char *data, int priority) { //คือการเพิ่ม node ใหม่เข้าไปใน queue
    node *newnode = createnode(data, priority);
    if (queue->head == NULL) {
        queue->head = newnode;
    } else if (priority > queue->head->priority) { //คือการเช็คว่า priority ของ node ใหม่ที่เพิ่มเข้าไปมา มากกว่า priority ของ node ที่อยู่หน้าสุดของ queue หรือไม่
        newnode->next = queue->head;
        queue->head = newnode;
    } else {
        node* currnode = queue->head;
        while (currnode->next != NULL && priority <= currnode->next->priority) {
            currnode = currnode->next;
        }
        newnode->next = currnode->next;
        currnode->next = newnode;
    }
}

char* dequeue(priorityqueue *queue) { //คือการลบ node ที่อยู่หน้าสุดของ queue ออกไป
    if (queue->head == NULL) {
        return "None";
    }
    char *data = queue->head->data;
    node *tempnode = queue->head;
    queue->head = queue->head->next;
    free(tempnode);
   return data;
}

void printqueue(priorityqueue *queue) { //คือการ print ข้อมูลของ queue ทั้งหมดออกมา
    node *currnode = queue->head;
    while (currnode != NULL) {
        printf("%s(%d) ", currnode->data, currnode->priority);
        currnode = currnode->next;
    }
    printf("\n");
}
void enterkiller(char *str){
    if(str[strlen(str)-1] == '\n'){
        str[strlen(str)-1] = '\0';
    }
}
int main(){
    priorityqueue *queue = createpriorityqueue();
    char str[100];
    int priority;
    fgets(str,100,stdin);
    enterkiller(str);
    char *token = strtok(str, " ");
    while(token != NULL){
        char *strtoken = token;
        token = strtok(NULL, " ");
        priority = atoi(token);
        if(priority == -1){
            priority = queue->head->priority - priority;
        }
        enqueue(queue,strtoken,priority);
        token = strtok(NULL, " ");
    }
    scanf("%d",&priority);


    for (int i = 0; i < priority; i++)
    {
        char *character = dequeue(queue);
        printf("%s ",character);
    }
    
}

