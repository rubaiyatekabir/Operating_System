#include <iostream>   // For cin, cout
using namespace std;

int main()
{
    int n;   // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n];     // Process IDs
    int at[n];      // Arrival Time
    int bt[n];      // Burst Time
    int ct[n];      // Completion Time
    int wt[n];      // Waiting Time
    int tat[n];     // Turnaround Time

    bool done[n] = {false};   // Track completed processes

    // Input arrival time and burst time
    for(int i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        cout << "Enter AT and BT for P" << pid[i] << ": ";
        cin >> at[i] >> bt[i];
    }

    int completed = 0;     // Number of finished processes
    int currentTime = 0;   // Current CPU time

    // Non-Preemptive SJF Scheduling
    while(completed < n)
    {
        int idx = -1;        // Index of selected process
        int minBT = 100000;  // Large number for comparison

        // Find shortest available job
        for(int i = 0; i < n; i++)
        {
            if(!done[i] && at[i] <= currentTime && bt[i] < minBT)
            {
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx == -1)
        {
            // No process has arrived yet, CPU idle
            currentTime++;
        }
        else
        {
            // Run selected process completely
            currentTime += bt[idx];

            // Store completion time
            ct[idx] = currentTime;

            // Mark process finished
            done[idx] = true;
            completed++;
        }
    }

    float avgWT = 0, avgTAT = 0;

    // Calculate WT and TAT
    for(int i = 0; i < n; i++)
    {
        // Turnaround Time = Completion Time - Arrival Time
        tat[i] = ct[i] - at[i];

        // Waiting Time = Turnaround Time - Burst Time
        wt[i] = tat[i] - bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Output table
    cout << "\nP\tAT\tBT\tCT\tWT\tTAT\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    // Average times
    cout << "\nAverage WT = " << avgWT / n;
    cout << "\nAverage TAT = " << avgTAT / n << endl;

    return 0;   // Program ends
}