#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {

    FILE *fp = fopen("output.txt", "w");
    if(fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (pid < 0) { // Error in fork
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // Child process
        fprintf(fp, "Child Process: PID = %d\n", getpid());
    }
    else { // Parent process
        fprintf(fp, "Parent Process: PID = %d\n", getpid());
        wait(NULL);
    }

    if(fclose(fp) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
    }

    return 0;
}
