#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    int fd[2];
    pid_t pid;
    char msg[] = "Hello from parent process!";
    char buffer[100];

    // Create a pipe
    if (pipe(fd) == -1){
        perror("pipe error");
        return 1;
    }

    // Create a new process
    pid = fork();

    if (pid < 0) { // Error in fork
        perror("fork error");
        return 1;
    }
    else if (pid == 0) { 
        // Child process
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    }
    else { 
        // Parent process
        close(fd[0]);
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
        wait(NULL);
    }

    return 0;
}
