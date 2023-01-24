#include <stdio.h>

int main() {
    int marks[5] = {1,2};
    printf("Array : {");
    for (int i = 0; i < 5; i++){
        if (i == 4){
            printf("%d",marks[i]);
            break;
        }
        printf("%d,",marks[i]);
    }
    printf("}\n");
}