#include <stdio.h>
#include <unistd.h>  // For fork() and getpid()
#include <sys/types.h>  // For pid_t

int main() {
    // Create a new process using fork
    pid_t pid = fork();

    // Check if fork() failed
    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    // fork() returns 0 in the child process
    if (pid == 0) {
        // Inside the child process
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());  // Get the PID of the child
        printf("Parent PID (from child): %d\n", getppid());  // Get the PID of the parent from the child
    } else {
        // Inside the parent process
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());  // Get the PID of the parent
        printf("Child PID (from parent): %d\n", pid);  // The fork() returns the child PID in the parent process
    }

    return 0;
}
