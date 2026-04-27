#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

int main()
{
    int n, tq;   // n = number of processes, tq = time quantum
    cin >> n;

    int at[n];     // Arrival Time
    int bt[n];     // Burst Time
    int rt[n];     // Remaining Time
    int wt[n];     // Waiting Time
    int tat[n];    // Turnaround Time

    // Input arrival time and burst time
    for(int i = 0; i < n; i++)
    {
        cin >> at[i] >> bt[i];

        // Initially remaining time = burst time
        rt[i] = bt[i];
    }

    // Input time quantum
    cin >> tq;

    queue<int> q;               // Ready queue for Round Robin
    bool inQueue[n] = {false};  // Tracks if process is already in queue

    int currentTime = 0;   // Current CPU time
    int completed = 0;     // Number of completed processes

    float avgWT = 0, avgTAT = 0;

    // Add processes that arrive at time 0 into ready queue
    for(int i = 0; i < n; i++)
    {
        if(at[i] == 0)
        {
            q.push(i);
            inQueue[i] = true;
        }
    }

    // Continue until all processes finish
    while(completed < n)
    {
        if(q.empty())
        {
            // No process is ready, CPU stays idle
            currentTime++;

            // Add newly arrived processes
            for(int i = 0; i < n; i++)
            {
                if(at[i] <= currentTime && rt[i] > 0 && !inQueue[i])
                {
                    q.push(i);
                    inQueue[i] = true;
                }
            }

            continue;
        }

        // Get first process from queue
        int i = q.front();
        q.pop();

        // Process runs for minimum of time quantum or remaining time
        int run = min(tq, rt[i]);

        currentTime += run;
        rt[i] -= run;

        // Add newly arrived processes during execution
        for(int j = 0; j < n; j++)
        {
            if(at[j] <= currentTime && rt[j] > 0 && !inQueue[j])
            {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if(rt[i] > 0)
        {
            // If process still has remaining time, put it back in queue
            q.push(i);
        }
        else
        {
            // Process finished
            completed++;

            // Turnaround Time = Completion Time - Arrival Time
            tat[i] = currentTime - at[i];

            // Waiting Time = Turnaround Time - Burst Time
            wt[i] = tat[i] - bt[i];

            avgWT += wt[i];
            avgTAT += tat[i];
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