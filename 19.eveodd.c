#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   // For fork(), getpid(), sleep()
#include <sys/types.h>
#include <sys/wait.h> // For wait()

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
        // Inside first child process (for even numbers)
        printf("Even Number Process (PID: %d, Parent PID: %d) is running...\n", getpid(), getppid());
        for (int i = 1; i <= 30; i++) {
            if (i % 2 == 0) {
                printf("Even Number Process (PID: %d) prints: %d\n", getpid(), i);
                sleep(1); // Pause for a second between prints
            }
        }
        exit(0); // Exit first child process
    }

    // Create second child process
    pid2 = fork();

    if (pid2 < 0) {
        // Fork failed
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) {
        // Inside second child process (for odd numbers)
        printf("Odd Number Process (PID: %d, Parent PID: %d) is running...\n", getpid(), getppid());
        for (int i = 1; i <= 30; i++) {
            if (i % 2 != 0) {
                printf("Odd Number Process (PID: %d) prints: %d\n", getpid(), i);
                sleep(1); // Pause for a second between prints
            }
        }
        exit(0); // Exit second child process
    }

    // Parent process waits for both child processes to finish
    printf("Parent Process (PID: %d) is waiting for children to finish...\n", getpid());

    // Wait for both children to finish
    wait(NULL); // Wait for the first child
    wait(NULL); // Wait for the second child

    // After both children have finished
    printf("Good Bye from Parent (PID: %d).\n", getpid());

    return 0;
}
