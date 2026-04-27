#include <iostream>   // For cin and cout
using namespace std;

int main()
{
    int n, m;   // n = number of processes, m = number of resource types

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    int alloc[n][m];    // Allocation matrix
    int request[n][m];  // Request matrix
    int avail[m];       // Available resources
    int work[m];        // Temporary available resources

    bool finished[n] = {false};   // Track completed processes

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> alloc[i][j];
        }
    }

    // Input Request Matrix
    cout << "\nEnter Request Matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> request[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter Available Resources:\n";
    for(int j = 0; j < m; j++)
    {
        cin >> avail[j];

        // Initially work = available resources
        work[j] = avail[j];
    }

    int completed = 0;   // Number of completed processes

    // Deadlock Detection Algorithm
    while(completed < n)
    {
        bool found = false;   // Check if any process can run

        for(int i = 0; i < n; i++)
        {
            if(!finished[i])
            {
                bool canRun = true;

                // Check if Request <= Work
                for(int j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        canRun = false;
                        break;
                    }
                }

                // If process can complete
                if(canRun)
                {
                    // Release allocated resources
                    for(int j = 0; j < m; j++)
                    {
                        work[j] += alloc[i][j];
                    }

                    // Mark process finished
                    finished[i] = true;
                    completed++;

                    found = true;
                }
            }
        }

        // No process can run = deadlock
        if(!found)
        {
            break;
        }
    }

    // Output deadlocked processes
    cout << "\nDeadlocked Processes: ";

    bool deadlock = false;

    for(int i = 0; i < n; i++)
    {
        if(!finished[i])
        {
            cout << "P" << i << " ";
            deadlock = true;
        }
    }

    if(!deadlock)
    {
        cout << "None (No Deadlock)";
    }

    cout << endl;

    return 0;   // Program ends
}