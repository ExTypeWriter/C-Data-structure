#include <stdio.h>

// Define the constant number of students and subjects for creating the array
#define STDNUM 20
#define SUBJNUM 5

int main() {
  int MARKS[STDNUM][SUBJNUM], i, j;
  float sum, average;

  // Input the marks of each student in each subject
  for (i = 0; i < STDNUM; i++) {
    for (j = 0; j < SUBJNUM; j++) {
      scanf("%d", &MARKS[i][j]);
    }
  }

  // Average the marks and display
  for (i = 0; i < STDNUM; i++) {
    sum = 0; // Reset the value of sum variable for using in next student's score calculation 
    for (j = 0; j < SUBJNUM; j++) {
      sum += MARKS[i][j];
    }
    average = sum / SUBJNUM;
    printf("%g\n", average); // %g is used to print the decimal floating-point values (Example: 100.00 -> 100, 49.80 -> 49.8)
  }

  return 0;
}

100 100 100 100 100
90 90 90 90 90
80 80 80 80 80
70 70 70 70 70
60 60 60 60 60
50 50 50 50 50 
40 40 40 40 40
30 30 30 30 30 
20 20 20 20 20
10 10 10 10 10
0 0 0 0 0 0
10 10 10 10 10
20 20 20 20 20
30 30 30 30 30 
40 40 40 40 40
50 50 50 50 50 
60 60 60 60 60
70 70 70 70 70
80 80 80 80 80
90 90 90 90 90
100 100 100 100 100