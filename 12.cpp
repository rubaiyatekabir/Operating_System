#include <iostream>
using namespace std;

int main()
{
    int n, capacity, faults = 0;

    // Input total number of page references
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];

    // Input page reference string
    cout << "Enter page reference string: ";
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    // Input number of available frames
    cout << "Enter number of frames: ";
    cin >> capacity;

    int frames[capacity];

    int size = 0;   // Tracks how many frames are currently filled

    // Initially all frames are empty
    for(int i = 0; i < capacity; i++)
        frames[i] = -1;

    // Process each page in reference string
    for(int i = 0; i < n; i++)
    {
        int page = pages[i];
        int pos = -1;   // Stores page position if found

        // Check whether page already exists in frames
        for(int j = 0; j < size; j++)
        {
            if(frames[j] == page)
            {
                pos = j;   // Page found
                break;
            }
        }

        // If page not found = Page Fault
        if(pos == -1)
        {
            faults++;

            // If free frame available, insert page directly
            if(size < capacity)
            {
                frames[size] = page;
                size++;
            }
            else
            {
                // Remove Least Recently Used page
                // Shift all pages left
                for(int j = 0; j < capacity - 1; j++)
                    frames[j] = frames[j + 1];

                // Insert new page at end (Most Recently Used)
                frames[capacity - 1] = page;
            }
        }
        else
        {
            // Page Hit
            // Move accessed page to end (Most Recently Used)

            for(int j = pos; j < size - 1; j++)
                frames[j] = frames[j + 1];

            frames[size - 1] = page;
        }

        // Display current frame contents
        cout << "After page " << page << " : ";

        for(int j = 0; j < size; j++)
            cout << frames[j] << " ";

        cout << endl;
    }

    // Final result
    cout << "\nTotal Page Faults = " << faults << endl;

    return 0;
}