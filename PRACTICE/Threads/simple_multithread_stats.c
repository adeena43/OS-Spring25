#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *numbers;
int count;

// Function to compute the average
void *calculate_average(void *arg) {
    double *average = (double *)malloc(sizeof(double));
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    *average = (double)sum / count;
    pthread_exit(average);
}

// Function to compute the minimum value
void *calculate_minimum(void *arg) {
    int *min_value = (int *)malloc(sizeof(int));
    *min_value = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] < *min_value) {
            *min_value = numbers[i];
        }
    }
    pthread_exit(min_value);
}

// Function to compute the maximum value
void *calculate_maximum(void *arg) {
    int *max_value = (int *)malloc(sizeof(int));
    *max_value = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] > *max_value) {
            *max_value = numbers[i];
        }
    }
    pthread_exit(max_value);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num1 num2 num3 ...\n", argv[0]);
        return 1;
    }

    count = argc - 1;
    numbers = (int *)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++) {
        numbers[i] = atoi(argv[i + 1]);
    }

    pthread_t threads[3];
    void *avg_result, *min_result, *max_result;

    // Create threads
    pthread_create(&threads[0], NULL, calculate_average, NULL);
    pthread_create(&threads[1], NULL, calculate_minimum, NULL);
    pthread_create(&threads[2], NULL, calculate_maximum, NULL);

    // Wait for threads to finish and retrieve results
    pthread_join(threads[0], &avg_result);
    pthread_join(threads[1], &min_result);
    pthread_join(threads[2], &max_result);

    // Print results
    printf("The average value is %.2f.\n", *(double *)avg_result);
    printf("The minimum value is %d.\n", *(int *)min_result);
    printf("The maximum value is %d.\n", *(int *)max_result);

    // Free allocated memory
    free(avg_result);
    free(min_result);
    free(max_result);
    free(numbers);

    return 0;
}
