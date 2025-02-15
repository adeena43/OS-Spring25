#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("Process ID: %d\n", getpid());
    printf("Parent Process ID: %d\n", getppid());
    printf("User ID: %d\n", getuid());
    return 0;
}
