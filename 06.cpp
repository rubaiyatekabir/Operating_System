// Preemptive SJF / SRTF Scheduling
// SRTF = Shortest Remaining Time First

#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main()
{
    int n;   // Number of processes
    cin >> n;

    int at[n];     // Arrival Time
    int bt[n];     // Burst Time
    int rt[n];     // Remaining Time
    int wt[n];     // Waiting Time
    int tat[n];    // Turnaround Time

    // Input arrival time and burst time for each process
    for(int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i];

        // Initially remaining time is equal to burst time
        rt[i] = bt[i];
    }

    int currentTime = 0;   // Current CPU time
    int completed = 0;     // Number of completed processes

    float avgWT = 0, avgTAT = 0;

    // Continue until all processes are completed
    while(completed < n)
    {
        int idx = -1;        // Index of selected process
        int minRT = 100000;  // Large value to find minimum remaining time

        // Find process with shortest remaining time among arrived processes
        for(int i = 0; i < n; i++)
        {
            if(at[i] <= currentTime && rt[i] > 0 && rt[i] < minRT)
            {
                minRT = rt[i];
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
            // Run selected process for 1 time unit
            rt[idx]--;
            currentTime++;

            // If process finishes
            if(rt[idx] == 0)
            {
                completed++;

                // Turnaround Time = Completion Time - Arrival Time
                tat[idx] = currentTime - at[idx];

                // Waiting Time = Turnaround Time - Burst Time
                wt[idx] = tat[idx] - bt[idx];

                avgWT += wt[idx];
                avgTAT += tat[idx];
            }
        }
    }

    // Display result table
    cout << "\nP\tAT\tBT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    // Display averages
    cout << "\nAverage WT = " << avgWT / n;
    cout << "\nAverage TAT = " << avgTAT / n;

    return 0;   // Program ends
}