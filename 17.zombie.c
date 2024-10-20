#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For fork(), getpid()
#include <sys/types.h>
#include <sys/wait.h>  // For wait()

int main() {
    // Create a child process using fork
    pid_t pid = fork();

    // Check if fork() failed
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        // Inside the child process
        printf("Child process (PID: %d) is running and will now exit.\n", getpid());
        exit(0);  // Child exits, becomes a zombie
    } else {
        // Inside the parent process
        printf("Parent process (PID: %d) created child (PID: %d).\n", getpid(), pid);

        // Parent process sleeps for 10 seconds to allow the child to become a zombie
        sleep(10);

        // Use 'ps' or any system monitoring tool to observe the zombie process during this sleep period

        // After sleep, parent calls wait to clean up the zombie process
        wait(NULL);
        printf("Parent process has cleaned up the zombie child (PID: %d).\n", pid);
    }

    return 0;
}
