#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler for SIGFPE
void handle_sigfpe(int sig) {
    printf("Caught signal %d (SIGFPE): Floating point exception\n", sig);
    exit(EXIT_FAILURE); // Exit the program after handling the signal
}

int main() {
    // Set up the signal handler for SIGFPE
    signal(SIGFPE, handle_sigfpe);

    printf("Raising SIGFPE signal by performing division by zero.\n");

    // Perform division by zero to raise SIGFPE
    int a = 1;
    int b = 0;
    int c = a / b; // This will raise SIGFPE

    // This line will not be executed
    printf("Result of division: %d\n", c);

    return 0;
}