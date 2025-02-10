#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Signal handler for SIGUSR1 in child
void sigusr1_handler(int sig) {
    printf("Child received SIGTERM (signal %d).\n", sig);
}

int main() {
    pid_t pid;

    pid = fork();

    if (pid == -1) { // Error
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { 
        // Child process

        if (signal(SIGUSR1, sigusr1_handler) == SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }

        printf("Child process ID: %d. Waiting for SIGTERM...\n", getpid());

        while (1) {
            pause(); // Wait for signals
        }
    } else { 
        // Parent process

        sleep(3);

        // Terminate the child process
        printf("Parent sending SIGTERM to child.\n");
        if (kill(pid, SIGTERM) == -1) {
            perror("kill");
            exit(EXIT_FAILURE);
        }

        wait(NULL);
        printf("Child process terminated.\n");
    }

    return 0;
}
