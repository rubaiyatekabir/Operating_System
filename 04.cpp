#include <iostream>   // For cin, cout
using namespace std;

int main()
{
    int n;   // Number of processes

    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n];     // Stores burst time of each process
    int wt[n];     // Stores waiting time
    int tat[n];    // Stores turnaround time

    float avgWT = 0, avgTAT = 0;

    // Input burst times for all processes
    for(int i = 0; i < n; i++)
    {
        cout << "Enter burst time for process " << i + 1 << ": ";
        cin >> bt[i];
    }

    // First process does not wait
    wt[0] = 0;

    // Calculate waiting times
    // Each process waits for all previous processes to finish
    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround times and totals
    for(int i = 0; i < n; i++)
    {
        // Turnaround Time = Waiting Time + Burst Time
        tat[i] = wt[i] + bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    // Calculate average values
    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    // Display result table
    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    // Display averages
    cout << "\nAverage Waiting Time = " << avgWT << endl;
    cout << "Average Turnaround Time = " << avgTAT << endl;

    return 0;   // Program ends
}