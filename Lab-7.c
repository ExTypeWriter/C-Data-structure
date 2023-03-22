#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10

typedef struct node
{
  int vertex;
  struct node *next;
} t_node;

typedef struct list
{
  t_node *head;
} t_list;

void checkString(char *string);

int main()
{
  int vertices_num, i, j;
  char caught[20];
  char names[MAX_SIZE][20];
  int adj_matrix[MAX_SIZE][MAX_SIZE] = {0};
  t_list adj_list[MAX_SIZE];

  // get the number of vertices in the graph
  printf("Enter the number of vertices: ");
  scanf("%s", caught);
  checkString(caught);
  vertices_num = atoi(caught);
  // get the names of the vertices
  i = 0;
  while (i < vertices_num)
  {
    printf("Enter the name of vertex %d: ", i + 1);
    scanf("%s", names[i]);
    i++;
  }

  // get the adjacency matrix from user input
  printf("Enter the adjacency matrix:\n");
  i = 0;
  while (i < vertices_num)
  {
    j = 0;
    while (j < vertices_num)
    {
      scanf("%d", &adj_matrix[i][j]);
      j++;
    }
    i++;
  }

  // create the adjacency list from the adjacency matrix
  i = 0;
  while (i < vertices_num)
  {
    adj_list[i].head = NULL;
    j = 0;
    while (j < vertices_num)
    {
      if (adj_matrix[i][j] == 1)
      {
        t_node *new_node = (t_node *)malloc(sizeof(t_node));
        new_node->vertex = j;
        new_node->next = adj_list[i].head;
        adj_list[i].head = new_node;
      }
      j++;
    }
    i++;
  }

  // display the adjacency matrix
  printf("The adjacency matrix is:\n");
  printf("\t");
  i = 0;
  while (i < vertices_num)
  {
    printf("%s\t", names[i]);
    i++;
  }
  printf("\n");
  int underline = 0;
  while (underline < vertices_num)
  {
    printf("---------");
    underline++;
  }
  printf("\n");
  i = 0;
  while (i < vertices_num)
  {
    printf("%s     | ", names[i]);
    j = 0;
    while (j < vertices_num)
    {
      printf("%d\t", adj_matrix[i][j]);
      j++;
    }
    printf("\n");
    i++;
  }

  // display the adjacency list
  printf("The adjacency list is:\n");
  i = 0;
  while (i < vertices_num)
  {
    printf("%s -> ", names[i]);
    t_node *current = adj_list[i].head;
    while (current != NULL)
    {
      if (current->next == NULL)
      {
        printf("%s ", names[current->vertex]);
        break;
      }
      printf("%s -> ", names[current->vertex]);
      current = current->next;
    }
    printf("\n");
    i++;
  }
  return 0;
}

void checkString(char *string)
{
  int checkloop = 0;
  while (checkloop < strlen(string))
  {
    if (isdigit(string[checkloop]) == 0)
    {
      printf("That's not even a number!\n");
      exit(0);
    }
    checkloop++;
  }
}