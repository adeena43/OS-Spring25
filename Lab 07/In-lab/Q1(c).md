```c
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Thread executing...\n");
    pthread_exit((void*)42);
}

int main(int argc, char *argv[]) {
    long exit_status;
    pthread_t threadID; // Thread identifier
    pthread_attr_t attributes; // Thread attributes
    
    pthread_attr_init(&attributes); // Initialize thread attributes
    
    pthread_create(&threadID, &attributes, thread_function, NULL); // Create thread
    
    pthread_join(threadID, (void**)&exit_status);
    printf("Thread exited with status: %ld\n", exit_status);
    return 0;
}

```
