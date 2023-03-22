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
  int vertices_num, row_count, column_count;
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
  row_count = 0;
  while (row_count < vertices_num)
  {
    printf("Enter the name of vertex %d: ", row_count + 1);
    scanf("%s", names[row_count]);
    row_count++;
  }

  // get the adjacency matrix from user input
  printf("Enter the adjacency matrix:\n");
  row_count = 0;
  while (row_count < vertices_num)
  {
    column_count = 0;
    while (column_count < vertices_num)
    {
      scanf("%d", &adj_matrix[row_count][column_count]);
      column_count++;
    }
    row_count++;
  }

  // create the adjacency list from the adjacency matrix
  row_count = 0;
  while (row_count < vertices_num)
  {
    adj_list[row_count].head = NULL;
    column_count = 0;
    while (column_count < vertices_num)
    {
      if (adj_matrix[row_count][column_count] == 1)
      {
        t_node *new_node = (t_node *)malloc(sizeof(t_node));
        new_node->vertex = column_count;
        new_node->next = adj_list[row_count].head;
        adj_list[row_count].head = new_node;
      }
      column_count++;
    }
    row_count++;
  }

  // display the adjacency matrix
  printf("The adjacency matrix is:\n");
  printf("\t");
  row_count = 0;
  while (row_count < vertices_num)
  {
    printf("%s\t", names[row_count]);
    row_count++;
  }
  printf("\n");
  int underline = 0;
  while (underline < vertices_num)
  {
    printf("---------");
    underline++;
  }
  printf("\n");
  row_count = 0;
  while (row_count < vertices_num)
  {
    printf("%s     | ", names[row_count]);
    column_count = 0;
    while (column_count < vertices_num)
    {
      printf("%d\t", adj_matrix[row_count][column_count]);
      column_count++;
    }
    printf("\n");
    row_count++;
  }

  // display the adjacency list
  printf("The adjacency list is:\n");
  row_count = 0;
  while (row_count < vertices_num)
  {
    printf("%s -> ", names[row_count]);
    t_node *current = adj_list[row_count].head;
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
    row_count++;
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