#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* thread_func(void* arg) {
    int thread_num = *(int*)arg;
    printf("Thread #%d\n", thread_num);
    
    // Allocate memory for return value
    int* ret_val = malloc(sizeof(int));
    *ret_val = thread_num * 10; // arbitrary return value
    pthread_exit((void*)ret_val);
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};
    int i;

    for (i = 0; i < 3; i++) {
        int status = pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
        if (status != 0) {
            printf("Error\n");
        }
    }

    // Collect return values
    for (i = 0; i < 3; i++) {
        void* retval;
        if (pthread_join(threads[i], &retval) == 0 && retval != NULL) {
            printf("Thread #%d returned: %d\n", i + 1, *(int*)retval);
            free(retval); // Don't forget to free the allocated memory
        }
    }

    return 0;
}
