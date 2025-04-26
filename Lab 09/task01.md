# a)
```c
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>

void proc_exit() {
    int wstat;
    pid_t pid;

    while (1) {
        /* Info about child process.
           WNOHANG returns immediately if there is no child to wait */
        pid = wait3(&wstat, WNOHANG, NULL);
        if (pid == 0 || pid == -1) {
            if (pid == 0)
                printf(stdout, "Return value of wait3() is %d\n", pid);
            return;
        }
        printf(stdout, "Return code: %d\n", wstat);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);
    switch (fork()) {
        case -1:
            perror("main: fork");
            exit(1);
        case 0:
            printf("I'm alive (temporarily)\n"); // child only executes this and exits
            int ret_code = rand();
            printf("Return code is %d\n", ret_code);
            exit(ret_code);
        default:
            break;
    }
    pause(); // suspends main process execution until a signal arrives
    exit(0);
}
```
# output(a):
![code1](https://github.com/user-attachments/assets/5af5782e-715d-4799-913c-e03d4d79076a)
# dry run(a):
    Dry Run of the Code
    Initial Setup:
        The parent process installs a signal handler (proc_exit) for the SIGCHLD signal.
        This means whenever a child process exits, proc_exit() will be called automatically.
    
    Execution Steps:
    1. Starting the main() function
        signal(SIGCHLD, proc_exit) is called to link the SIGCHLD signal with the proc_exit() function.
        fork() is called to create a child process:
            If fork() fails, it prints an error and exits.
            If fork() succeeds:
                The child runs the case 0: block.
                The parent skips to after the switch and calls pause() to wait for a signal.
    2. Child Process (Case 0 Execution)
        Child prints:
    I'm alive (temporarily)
    It generates a random number:
    int ret_code = rand();
    Then it prints the return code:
        Return code is <random number>
        The child exits with the random number as its exit status.
    3. Parent Process
        Parent is sleeping because of pause(), waiting for any signal.
    4. Child Exits → Signal Sent
        When the child exits, the SIGCHLD signal is sent to the parent.
        The parent wakes up and runs proc_exit().
        In proc_exit():
            wait3(WNOHANG) checks for any dead child process without blocking.
            If a child is found, it prints:
            Return code: <exit status of child>
            If no child is found, it returns from the loop.
    5. Final Step
        After handling the child process, the parent exits cleanly with exit(0).
# b)
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>

void proc_exit() {
    int wstat;
    pid_t pid;
    while (1) {
        pid = waitpid(-1, &wstat, WNOHANG);
        if (pid <= 0) {
            break;
        }
        printf("Child with PID %d terminated, return code: %d\n", pid, wstat);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);

    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) {
            // Child process
            printf("Child %d alive, PID: %d\n", i, getpid());
            int ret_code = rand() % 100; // Random exit code
            sleep(1 + rand() % 3); // Random sleep to simulate work
            exit(ret_code);
        }
    }

    // Parent process
    while (1) {
        pause(); // Wait for SIGCHLD
    }

    return 0;
}

```
# output(b):
![modified_code1](https://github.com/user-attachments/assets/0a7744a1-06ad-45b9-b698-e5d92e124105)
