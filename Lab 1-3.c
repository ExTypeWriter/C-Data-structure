#include <stdio.h>
#include <stdlib.h>

int main() {
  // initializing the variables.
  int size;
  scanf("%d", &size);
  int *arrayTemp = (int *)calloc(size, sizeof(int));
  int *array = (int *)calloc(size, sizeof(int));
  int *arrayindex = (int *)calloc(size, sizeof(int));
  // scanf for input array.
  for (int i = 0; i < size; i++) {
    scanf("%d", &arrayTemp[i]);
    array[i] = arrayTemp[i];
    arrayindex[i] = i;
  }
  // bubble sorting the array.
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      int breaker = 0;
      while (j + 1 < size && !breaker) {
        if (arrayTemp[j] > arrayTemp[j + 1]) {
          // sorted array part
          int temp = arrayTemp[j];
          arrayTemp[j] = arrayTemp[j + 1];
          arrayTemp[j + 1] = temp;
          // index part
          int tempIndex = arrayindex[j];
          arrayindex[j] = arrayindex[j + 1];
          arrayindex[j + 1] = tempIndex;
        } else {
          breaker = 1;
        }
      }
    }
  }
  // swaping
  int temp = array[arrayindex[1]];
  array[arrayindex[1]] = array[arrayindex[size - 2]];
  array[arrayindex[size - 2]] = temp;
  // display
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
}