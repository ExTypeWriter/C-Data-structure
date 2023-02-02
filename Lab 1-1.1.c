//Initialize Constant
#define M 20
#define N 5
#include <stdio.h>
//Average Score Calculation with Displaying
int findAvg(int arr[M][N]){
    float sum;
    int col = 0;
    while(col < N){
        sum =0;
        int row = 0;
        while(row < M){
            sum += arr[row][col];
            row++;
        }
        col++;
        printf("%g\n",sum/20); // Print the sum in each step in 2 decimal place.
    }
}

int main() {
    int MARKS[M][N];
    int row,col;
    row = 0;
    while(row<M){
        col = 0;
        while(col<N){
            scanf("%d",&MARKS[row][col]);
            col++;
        }
        row++;
    }
    //Find average score and display it.
    findAvg(MARKS);
    return 0;
}