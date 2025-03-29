```c
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000000

int main() {
    float *A, *B, *C;
    A = (float *)malloc(SIZE * sizeof(float));
    B = (float *)malloc(SIZE * sizeof(float));
    C = (float *)malloc(SIZE * sizeof(float));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        A[i] = i * 1.0f;
        B[i] = i * 2.0f;
    }

    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] + B[i];
    }

    printf("Serial computation completed.\n");

    free(A);
    free(B);
    free(C);

    return 0;
}


```
![Q1_postlab](https://github.com/user-attachments/assets/36b0ef35-be9f-4fd8-ae9e-0e72614da6d2)
