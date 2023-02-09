#include <stdio.h>
int main() {
    //initial variable
    float scores[5];
    int failedStudentCount = 0;
    //taking and processing input
    for (int i = 0; i < 20; i++) {
        //taking input
        scanf("%f %f %f %f %f", &scores[0], &scores[1], &scores[2], &scores[3], &scores[4]);
        float sum = 0;
        //calculate sum
        for (int k = 0; k < 5; k++) {
        sum += scores[k];
        }
        //calculate average and counting if failed
        float average = sum / 5;
        if (average < 50) {
            failedStudentCount++;
        }
  }
  //display
  printf("%d\n", failedStudentCount);
  return 0;
}

// 100 100 100 100 100
// 90 90 90 90 90
// 80 80 80 80 80
// 70 70 70 70 70
// 60 60 60 60 60
// 50 50 50 50 50 
// 40 40 40 40 40
// 30 30 30 30 30 
// 20 20 20 20 20
// 10 10 10 10 10
// 90 90 90 90 90
// 10 10 10 10 10
// 20 20 20 20 20
// 30 30 30 30 30 
// 40 40 40 40 40
// 50 50 50 50 50 
// 60 60 60 60 60
// 70 70 70 70 70
// 100 100 100 100 100
// 90 90 90 90 90