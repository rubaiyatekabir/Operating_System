#include <stdio.h>      // For printf()
#include <unistd.h>     // For fork()

int main()
{
    pid_t pid;   // Variable to store return value of fork()

    pid = fork();   // Create child process

    if(pid < 0)
    {
        // If fork() fails
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        // This block runs in child process

        // Print numbers 6 to 10
        for(int i = 6; i <= 10; i++)
        {
            printf("%d ", i);
        }
    }
    else
    {
        // This block runs in parent process

        // Print numbers 1 to 5
        for(int i = 1; i <= 5; i++)
        {
            printf("%d ", i);
        }
    }

    return 0;   // Program ends
}