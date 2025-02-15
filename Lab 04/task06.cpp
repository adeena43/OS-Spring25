#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int signum) {
    printf("\nAlarm received! Exiting program.\n");
    _exit(0);
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5); 

    while (1) {
        printf("Running...\n");
        sleep(1);
    }

    return 0;
}
