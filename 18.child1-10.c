#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For fork(), getpid(), sleep()
#include <sys/types.h>
#include <sys/wait.h>  // For wait()

int main() {
    pid_t pid1, pid2;

    // Create first child process
    pid1 = fork();

    if (pid1 < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) {
        // Inside first child process
        printf("First Child Process (PID: %d, Parent PID: %d) is running...\n", getpid(), getppid());
        for (int i = 1; i <= 10; i++) {
            printf("First Child (PID: %d) prints: %d\n", getpid(), i);
            sleep(1);  // Sleep for a second between numbers
        }
        exit(0);  // First child exits
    }

    // Create second child process
    pid2 = fork();

    if (pid2 < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) {
        // Inside second child process
        printf("Second Child Process (PID: %d, Parent PID: %d) is running...\n", getpid(), getppid());
        for (int i = 1; i <= 10; i++) {
            printf("Second Child (PID: %d) prints: %d\n", getpid(), i);
            sleep(1);  // Sleep for a second between numbers
        }
        exit(0);  // Second child exits
    }

    // Parent process
    printf("Parent Process (PID: %d) is waiting for children to finish...\n", getpid());

    // Wait for both children to finish
    wait(NULL);  // Wait for first child
    wait(NULL);  // Wait for second child

    // After both children have finished
    printf("Good Bye from Parent (PID: %d).\n", getpid());

    return 0;
}
