#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    for(int i=0; i<3; i++){

        pid_t pid = fork();

        if (pid < 0) { // Error in fork
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) { // Child process
            printf("Process %d: Child Process: PID = %d, Parent PID = %d\n", i+1, getpid(), getppid());
        }
        else { // Parent process
            wait(NULL);
            break;
        }
    
    }
    
    return 0;
}
