#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* participant_routine(void* arg) {
    int id = *((int*)arg);
    free(arg);

    printf("Participant %d: Volunteer 1 - On-day registration\n", id);
    sleep(1); // simulate time

    printf("Participant %d: Volunteer 2 - Announcements\n", id);
    sleep(1);

    printf("Participant %d: Volunteer 3 - Sponsors\n", id);
    sleep(1);

    printf("Participant %d: Volunteer 4 - Query resolution\n", id);
    sleep(1);

    printf("Participant %d: All tasks completed ✅\n\n", id);
    return NULL;
}

int main() {
    pthread_t participants[10];

    for (int i = 0; i < 10; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&participants[i], NULL, participant_routine, id);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(participants[i], NULL);
    }

    return 0;
}
