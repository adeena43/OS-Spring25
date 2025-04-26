# a)
# code:
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS]; // Global variable to store thread IDs

void signal_handler(int signum) { // Signal handler
    printf("Inside signal handler, received signal %d\n", signum);
    printf("I am thread %lu\n", pthread_self());
    printf("I am thread %lu (parent=%lu)\n", pthread_self(), pthread_self());
}

void *thread_function(void *arg) { // Thread function
    signal(SIGUSR1, signal_handler); // Thread register signal handler
    while (1) {
        sleep(1);
    }
    return NULL;
}

int main() {
    signal(SIGUSR1, signal_handler); // register signal handler
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    int t1 = getpid(), t2 = getpid(), t3 = getpid();
    printf("My IDs: main(%d) t1(%d) t2(%d) t3(%d)\n", t1, t2, t3);

    kill(t1, SIGUSR1); // Send signal to process
    pthread_kill(threads[2], SIGUSR1); // Send signal to 3rd thread

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

```
# output:
![Screenshot from 2025-04-26 22-32-56](https://github.com/user-attachments/assets/c1c782d3-b93e-4709-ab87-f108e6381980)

# b)
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

#define NUM_THREADS 4

pthread_t threads[NUM_THREADS]; // Global variable to store thread IDs

void signal_handler(int signum) { // Signal handler
    printf("Inside signal handler, received signal %d\n", signum);
    printf("I am thread %lu\n", pthread_self());
    printf("I am thread %lu (parent=%lu)\n", pthread_self(), pthread_self());
}

void *thread_function(void *arg) { // Thread function
    signal(SIGUSR1, signal_handler); // Thread register signal handler
    while (1) {
        sleep(1);
    }
    return NULL;
}

int main() {
    //signal(SIGUSR1, signal_handler); // register signal handler
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    int t1 = getpid(), t2 = getpid(), t3 = getpid();
    printf("My IDs: main(%d) t1(%d) t2(%d) t3(%d)\n", t1, t2, t3);

    kill(t1, SIGUSR1); // Send signal to process
    pthread_kill(threads[2], SIGUSR1); // Send signal to 3rd thread

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

```
# output:
![code2_modified](https://github.com/user-attachments/assets/28e2e288-95b9-4d67-b4c9-c2426b31d562)

