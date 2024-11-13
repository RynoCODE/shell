#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for ignoring SIGINT
void ignore_sigint(int sig) {
    printf("SIGINT (Ctrl+C) signal ignored.\n");
}

int main() {
    // Set up the handler to ignore SIGINT
    signal(SIGINT, ignore_sigint);
    printf("SIGINT signal is currently ignored. Press Ctrl+C and see it is not terminating the process.\n");

    // Sleep to demonstrate ignoring SIGINT
    sleep(5);

    // Restore the default handler for SIGINT
    signal(SIGINT, SIG_DFL);
    printf("SIGINT signal restored to default behavior. You can now terminate the program with Ctrl+C.\n");

    // Keep the program running to test restored behavior
    while (1) {
        printf("Running... Press Ctrl+C to terminate.\n");
        sleep(1);
    }

    return 0;
}
