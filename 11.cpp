#include <iostream>   // For cin and cout
using namespace std;

int main()
{
    int n, frames;   // n = total number of page references, frames = memory frame count

    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];   // Stores page reference string

    // Input page reference string
    cout << "Enter page reference string: ";
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    int frame[frames];   // Stores pages currently loaded in memory frames

    // Initially all frames are empty
    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    int pageFault = 0;   // Counts total page faults
    int pageHit = 0;     // Counts total page hits

    int index = 0;       // FIFO replacement pointer

    // Process each page reference one by one
    for(int i = 0; i < n; i++)
    {
        int found = 0;   // Assume page is not found

        // Check whether current page already exists in frames
        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;     // Page found in memory
                pageHit++;     // Increase hit count
                break;
            }
        }

        // If page not found, page fault occurs
        if(found == 0)
        {
            // Replace oldest page using FIFO rule
            frame[index] = pages[i];

            // Move pointer circularly
            index = (index + 1) % frames;

            pageFault++;
        }

        // Display current frame contents
        cout << "After " << pages[i] << " : ";

        for(int j = 0; j < frames; j++)
            cout << frame[j] << " ";

        cout << endl;
    }

    // Final result
    cout << "\nTotal Page Faults = " << pageFault << endl;
    cout << "Total Page Hits = " << pageHit << endl;

    return 0;
}