#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
  int data;
  int index;
  struct ListNode *next;
  struct ListNode *previous;
} LISTNODE;

void createList(LISTNODE **firstnode) {
  char buffer[100];
  int i = 0, index = 0;
  LISTNODE *ptr = *firstnode;
  ptr->data=-10001;
  fgets(buffer, 100, stdin);
  if(buffer[strlen(buffer)-1]=='\n')
  {
    buffer[strlen(buffer)-1]='\0';
  }
  while(strcmp(&buffer[i],"END") && buffer[i+1]!='\0')
    {
      if(index!=0)
      {
        ptr->next = malloc(sizeof(LISTNODE));
        ptr->next->previous = ptr;
        ptr = ptr->next;
      }
      sscanf(&buffer[i],"%d",&ptr->data);
      ptr->index = index;
      
      while(buffer[i] != ' ')
        {
          i++;
        }
      while(buffer[i] == ' ')
        {
          i++;
        }
      index++;
    }
}

void palindrome(LISTNODE *firstnode) {
  if(firstnode->data==-10001)
  {
    return;
  }
  
  if(firstnode->next==NULL)
  {
    printf("None");
    return;
  }
  int index = 0, maxIndex = 0;
  LISTNODE *selectnode = firstnode;
  LISTNODE *lastnode = firstnode;
  while (lastnode->next) {
    maxIndex++;
    lastnode = lastnode->next;
  }
  LISTNODE *tempnext = firstnode, *tempprevious = lastnode;
  int k=0;
  while (tempnext) {
    if (tempnext->data == tempprevious->data) {
      k++;
    }
      tempnext = tempnext->next;
      tempprevious = tempprevious->previous;
    }
    if (k >= maxIndex) {
      printf("None");
      return;
    }
  for (int i = 0; i <= maxIndex; i++) {
    tempnext = firstnode;
    tempprevious = lastnode;
    int j = 0;
    k=0;
    while (tempnext && tempprevious) {
      if (tempnext == selectnode && tempnext->next) {
        tempnext = tempnext->next;
      }
      if (tempprevious == selectnode && tempprevious->previous) {
        tempprevious = tempprevious->previous;
      }
      if (tempnext->data == tempprevious->data) {
        j++;
      }
      /*printf("data cmp %d %d\n",tempnext->data,tempprevious->data);*/
      if(tempnext && tempprevious)
      {
        tempnext = tempnext->next;
        tempprevious = tempprevious->previous;
      }
      
    }
    /*printf("round %d\n\n",j);*/
    if (j >= maxIndex) {
      printf("%d", selectnode->index);
      (selectnode->previous)->next=selectnode->next;
      (selectnode->next)->previous=selectnode->previous;
      free(selectnode);
      return;
    }
      selectnode = selectnode->next;
  }
  printf("None");
}

int main(void) {
  LISTNODE *data = malloc(sizeof(LISTNODE));
  createList(&data);
  palindrome(data);
  return 0;
}