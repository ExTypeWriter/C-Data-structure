#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 256

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
  int vertices_num, row, column;
  char caught[MAX];
  char names[MAX][20];
  int adj_matrix[MAX][MAX] = {0};
  t_list adj_list[MAX];

  // get the number of vertices in the graph
  printf("Enter the number of vertices: ");
  scanf("%s", caught);
  checkString(caught);
  vertices_num = atoi(caught);
  // get the names of the vertices
  row = 0;
  while (row < vertices_num)
  {
    printf("Enter the name of vertex %d: ", row + 1);
    scanf("%s", names[row]);
    row++;
  }

  // get the adjacency matrix from user input
  printf("Enter the adjacency matrix:\n");
  row = 0;
  while (row < vertices_num)
  {
    column = 0;
    while (column < vertices_num)
    {
      scanf("%d", &adj_matrix[row][column]);
      column++;
    }
    row++;
  }

  // create the adjacency list from the adjacency matrix
  row = 0;
  while (row < vertices_num)
  {
    adj_list[row].head = NULL;
    column = 0;
    while (column < vertices_num)
    {
      if (adj_matrix[row][column] == 1)
      {
        t_node *new_node = (t_node *)malloc(sizeof(t_node));
        new_node->vertex = column;
        new_node->next = adj_list[row].head;
        adj_list[row].head = new_node;
      }
      column++;
    }
    row++;
  }

  // display the adjacency matrix
  printf("The adjacency matrix is:\n");
  printf("\t");
  row = 0;
  while (row < vertices_num)
  {
    printf("%s\t", names[row]);
    row++;
  }
  printf("\n");
  int underline = 0;
  while (underline < vertices_num)
  {
    printf("---------");
    underline++;
  }
  printf("\n");
  row = 0;
  while (row < vertices_num)
  {
    printf("%s     | ", names[row]);
    column = 0;
    while (column < vertices_num)
    {
      printf("%d\t", adj_matrix[row][column]);
      column++;
    }
    printf("\n");
    row++;
  }

  // display the adjacency list
  printf("The adjacency list is:\n");
  row = 0;
  while (row < vertices_num)
  {
    printf("%s -> ", names[row]);
    t_node *current = adj_list[row].head;
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
    row++;
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