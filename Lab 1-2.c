#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b); // Compare two elements for qsort function.
int matrixDisplay(int** matrix,int row , int col);
int OddEvenDisplaySort(int * array,int arraySize);

int main()
{
    int row,col;
    int **Input2DArray;
    int *Odd,*Even;
    int OddCount = 0;
    int EvenCount = 0;

    scanf("%d %d", &col, &row);
    Input2DArray = malloc(row * sizeof(int *));
    int c = 0;
    while (c<row)
    {
        Input2DArray[c] = malloc(col * sizeof(int));
        c++;
    }
    Odd = (int*)malloc(col*row*sizeof(int));
    Even = (int*)malloc(col*row*sizeof(int));
    int i = 0;
    while (i < row)
    {
        int j = 0;
        while (j < col)
        {
            scanf("%d", &(Input2DArray[i][j++]));
        }
        i++;
    }
    // Check input by display
    // matrixDisplay(Input2DArray,row,col);
    
    // Count Odd and Even numbers. Then stored the values in each odd and even array.
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (Input2DArray[i][j] % 2 == 0)
            {
                Even[EvenCount] = Input2DArray[i][j];
                EvenCount++;
            }
            else if (Input2DArray[i][j] % 2 != 0)
            {
                Odd[OddCount] = Input2DArray[i][j];
                OddCount++;
            }
        }
    }
    // Sort the output arrays.
    // printf("Odd %d Even %d\n", OddCount, EvenCount);

    OddEvenDisplaySort(Odd,OddCount); // Display the sorted Odd array.
    OddEvenDisplaySort(Even,EvenCount); // Display the sorted Odd array.
    free(Input2DArray);
    free(Even);
    free(Odd);
}

int matrixDisplay(int** matrix,int row , int col)
{
    printf("*****Matrix Start*****\n");
    int cRow = 0;
    while(cRow < row) {
      int cCol = 0;
      while(cCol < col) {
        printf("%d ", matrix[cRow][cCol]);
        cCol++;
      }
      cRow++;
      printf("\n");
    }
    printf("*****Matrix End*****\n");
}

int OddEvenDisplaySort(int * array,int arraySize){
    qsort(array,arraySize,sizeof(int),cmpfunc);
    int Count = 0;
    if (arraySize != 0)
    {
        while (arraySize != 0)
        {
            printf("%d ", array[Count]);
            Count++;
            arraySize--;
        }
        printf("\n");
    }
    else{
        printf("None\n");
    }
}

int cmpfunc(const void *a, const void *b){ 
    return (*(int *)a - *(int *)b); 
}