#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork(), getpid(), getppid()

int main()
{
    pid_t child1, child2;   // Variables to store child process IDs

    child1 = fork();   // Create first child process

    if(child1 == 0)
    {
        // This block runs in first child process
        printf("First Child\n");

        // Print first child PID
        printf("PID = %d\n", getpid());

        // Print parent PID of first child
        printf("PPID = %d\n", getppid());
    }
    else
    {
        // Only parent process enters this block

        child2 = fork();   // Create second child process

        if(child2 == 0)
        {
            // This block runs in second child process
            printf("Second Child\n");

            // Print second child PID
            printf("PID = %d\n", getpid());

            // Print parent PID of second child
            printf("PPID = %d\n", getppid());
        }
        else
        {
            // This block runs in parent process
            printf("Parent Process\n");

            // Print parent PID
            printf("Parent PID = %d\n", getpid());

            // Print first child PID
            printf("Child1 PID = %d\n", child1);

            // Print second child PID
            printf("Child2 PID = %d\n", child2);
        }
    }

    return 0;   // Program ends successfully
}