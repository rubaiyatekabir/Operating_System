#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork(), getpid(), getppid()

int main()
{
    pid_t pid;   // Variable to store fork() return value

    pid = fork();   // Create a new child process

    if(pid < 0)
    {
        // If fork() returns negative, process creation failed
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        // This block runs in the child process
        printf("Child Process\n");

        // Print child's own Process ID
        printf("Child PID: %d\n", getpid());

        // Print Parent Process ID of child
        printf("Parent Process ID (PPID): %d\n", getppid());
    }
    else
    {
        // This block runs in the parent process
        printf("Parent Process\n");

        // Print parent's own Process ID
        printf("Parent PID: %d\n", getpid());

        // fork() returns child's PID to parent
        printf("Child PID: %d\n", pid);
    }

    return 0;   // Program ends successfully
}