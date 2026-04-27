```cpp
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main()
{
    int n;   // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    int at[n];     // Arrival Time
    int bt[n];     // Burst Time
    int p[n];      // Priority
    int ct[n];     // Completion Time
    int wt[n];     // Waiting Time
    int tat[n];    // Turnaround Time
    int rt[n];     // Remaining Time / Status tracker

    // Input arrival time, burst time and priority
    for(int i = 0; i < n; i++)
    {
        cout << "Enter AT, BT and Priority for P" << i + 1 << ": ";
        cin >> at[i] >> bt[i] >> p[i];

        // Initially remaining time = burst time
        rt[i] = bt[i];
    }

    int currentTime = 0;   // Current CPU time
    int completed = 0;     // Number of completed processes

    // Non-Preemptive Priority Scheduling
    while(completed < n)
    {
        int idx = -1;      // Index of selected process
        int hp = INT_MAX;  // Highest priority = smallest number

        // Find highest priority process among arrived processes
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && rt[i] > 0 && p[i] < hp)
            {
                hp = p[i];
                idx = i;
            }
        }

        if(idx == -1)
        {
            // No process has arrived, CPU stays idle
            currentTime++;
        }
        else
        {
            // Run selected process completely
            currentTime += bt[idx];

            // Store completion time
            ct[idx] = currentTime;

            // Mark process finished
            rt[idx] = 0;
            completed++;

            // Turnaround Time = Completion Time - Arrival Time
            tat[idx] = ct[idx] - at[idx];

            // Waiting Time = Turnaround Time - Burst Time
            wt[idx] = tat[idx] - bt[idx];
        }
    }

    // Display result table
    cout << "\nP\tAT\tBT\tPriority\tCT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << p[i] << "\t\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    return 0;   // Program ends
}
```
