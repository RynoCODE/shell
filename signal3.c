#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

// Signal handler for SIGCHLD
void handle_sigchld(int sig) {
    int status;
    pid_t pid;

    // Wait for the child process to terminate
    pid = wait(&status);
    if (pid > 0) {
        printf("Parent received SIGCHLD signal. Child process (PID: %d) terminated.\n", pid);
        if (WIFEXITED(status)) {
            printf("Child exited normally with status %d.\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child was terminated by signal %d.\n", WTERMSIG(status));
        }
    }
}

int main() {
    pid_t pid;

    // Set up the SIGCHLD handler
    signal(SIGCHLD, handle_sigchld);

    // Fork to create a child process
    pid = fork();

    if (pid == -1) {
        // Fork failed
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process (PID: %d) is running.\n", getpid());
        sleep(2);  // Simulate some work in the child process
        printf("Child process (PID: %d) is terminating.\n", getpid());
        exit(0);
    } else {
        // Parent process
        printf("Parent process (PID: %d) created child process (PID: %d).\n", getpid(), pid);

        // Parent waits indefinitely to keep the program running
        // and catch the SIGCHLD signal
        while (1) {
            pause();  // Wait for signals
        }
    }

    return 0;
}
