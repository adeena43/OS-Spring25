```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h> // for usleep

#define NUM_READERS 5
#define NUM_WRITERS 2
#define STRING_LENGTH 60

pthread_t readers[NUM_READERS], writers[NUM_WRITERS];
sem_t mutex, rw_mutex;
int readers_count = 0;
FILE *file;

char generateRandomChar() {
    return (char)('a' + rand() % 26); // Generating a random lowercase character
}

void *reader(void *arg) {
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&rw_mutex);
        }
        sem_post(&mutex);

        // Reading from file
        fseek(file, 0, SEEK_SET);
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            fprintf(stdout, "Reader %ld: %s", (long)arg, buffer);
        }

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&rw_mutex);
        }
        sem_post(&mutex);

        usleep(1000); // Perform other tasks (sleep a little)
    }
}

void *writer(void *arg) {
    while (1) {
        sem_wait(&rw_mutex);

        // Generate random string to be written to file
        srand(time(NULL)); // Seed for random number generator
        char randomString[STRING_LENGTH + 1]; // +1 for null terminator
        for (int i = 0; i < STRING_LENGTH; i++) {
            randomString[i] = generateRandomChar();
        }
        randomString[STRING_LENGTH] = '\0'; // Null terminate the string

        // Writing to file
        fseek(file, 0, SEEK_END);
        fprintf(file, "%s\n", randomString); // Writer to file on drive
        fprintf(stdout, "Writer %ld: %s\n", (long)arg, randomString); // Display on screen
        fflush(file);

        sem_post(&rw_mutex);

        usleep(1000); // Perform other tasks (sleep a little)
    }
}

int main() {
    file = fopen("shared_file.txt", "a+");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);

    int i;
    for (i = 0; i < NUM_WRITERS; i++)
        pthread_create(&writers[i], NULL, writer, (void *)(long)i);

    for (i = 0; i < NUM_READERS; i++)
        pthread_create(&readers[i], NULL, reader, (void *)(long)i);

    for (i = 0; i < NUM_READERS; i++)
        pthread_join(readers[i], NULL);

    for (i = 0; i < NUM_WRITERS; i++)
        pthread_join(writers[i], NULL);

    fprintf(stdout, "Reader pthread join completed\n");

    sem_destroy(&mutex);
    sem_destroy(&rw_mutex);
    fclose(file);

    return 0;
}

```

# a)
![a_ss](https://github.com/user-attachments/assets/e7b5854c-7331-4f47-9b92-6db9d9cb9d7b)
# b)
  Writers keep writing random strings to the file.
  Readers keep reading and printing whatever is in the file.
  ## outputon screen:
  ![code2](https://github.com/user-attachments/assets/c62b363d-ab27-41b6-8de3-b95ba19a21cf)
  
  ## entries in the shared_file.txt:
  ![textFileSS](https://github.com/user-attachments/assets/64bacef9-2749-4838-a5c2-1eaa8bd982b4)

# c)
![20250426_202103](https://github.com/user-attachments/assets/61240e1a-e221-47b2-87db-3a7855922d04)

# d)
![20250426_202118](https://github.com/user-attachments/assets/4edd8426-fc95-4013-b1bf-f80794a6f25a)
