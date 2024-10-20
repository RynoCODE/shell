#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For fork(), getpid(), getppid()
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

    if (pid > 0) {
        // Inside the parent process
        printf("Parent process (PID: %d) is going to terminate.\n", getpid());
        sleep(2);  // Give the child time to print its message before parent exits
        printf("Parent process exiting...\n");
        exit(0);  // Parent process terminates here
    } else {
        // Inside the child process
        printf("Child process (PID: %d) started. Parent PID: %d\n", getpid(), getppid());
        sleep(5);  // Keep the child process running to observe orphan state
        printf("Child process (PID: %d) is now an orphan. New Parent PID: %d\n", getpid(), getppid());
    }

    return 0;
}
