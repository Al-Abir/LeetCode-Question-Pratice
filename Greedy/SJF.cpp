#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate average waiting time
int shortestJobFirst(vector<int>& bt) {
    sort(bt.begin(), bt.end());  // Sort burst times in ascending order

    int totalWaitingTime = 0;
    int n = bt.size();
    int waitingTime = 0;

    // Calculate total waiting time
    for (int i = 1; i < n; ++i) {
        waitingTime += bt[i - 1];        // Add previous burst time
        totalWaitingTime += waitingTime; // Accumulate waiting time
    }

    
    return totalWaitingTime / n;
}

int main() {
    vector<int> bt = {4, 1, 3, 7, 2}; // Example input
    cout << shortestJobFirst(bt) << endl; // Output: 4

    return 0;
}
