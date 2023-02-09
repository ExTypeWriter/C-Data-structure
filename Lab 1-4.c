#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // initialize size
  int size;
  scanf("%d", &size);

  // allocate memory for matrix
  int **matrix = (int **)calloc(size, sizeof(int *));
  for (int i = 0; i < size; i++) {
    // allocation for mini array in the beeg array
    matrix[i] = (int *)calloc(size, sizeof(int));
  }

  // taking input for matrix
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  // summing the diagonal matrix
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += matrix[i][i];
  }

  // display
  printf("%d\n", sum);
  return 0;
}