#include <iostream>   // For input and output
using namespace std;

int main()
{
    int n, m;   // n = number of processes, m = number of resource types

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> m;

    // Matrices used in Banker's Algorithm
    int alloc[n][m];   // Resources currently allocated to each process
    int max[n][m];     // Maximum resources each process may need
    int need[n][m];    // Remaining resources needed to finish

    int avail[m];      // Currently available resources

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> alloc[i][j];

    // Input Maximum Need Matrix
    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> max[i][j];

    // Input Available Resources
    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < m; i++)
        cin >> avail[i];

    // Calculate Need Matrix
    // Need = Max - Allocation
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finished[n] = {false};   // Tracks completed processes
    int safeSeq[n];               // Stores safe execution order
    int count = 0;                // Number of completed processes

    // Try to find safe sequence
    while(count < n)
    {
        bool found = false;   // Checks if at least one process can run

        for(int i = 0; i < n; i++)
        {
            if(!finished[i])   // Only check unfinished processes
            {
                bool canRun = true;

                // Check if Need <= Available
                for(int j = 0; j < m; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        canRun = false;
                        break;
                    }
                }

                // If process can complete safely
                if(canRun)
                {
                    // Release allocated resources after completion
                    for(int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    // Add process to safe sequence
                    safeSeq[count++] = i;

                    // Mark process completed
                    finished[i] = true;

                    found = true;
                }
            }
        }

        // No process could run -> Unsafe state
        if(!found)
        {
            cout << "\nSystem is NOT in safe state!\n";
            return 0;
        }
    }

    // Safe state output
    cout << "\nSystem is in SAFE state.\nSafe sequence: ";

    for(int i = 0; i < n; i++)
        cout << "P" << safeSeq[i] << " ";

    cout << endl;

    return 0;   // Program ends
}