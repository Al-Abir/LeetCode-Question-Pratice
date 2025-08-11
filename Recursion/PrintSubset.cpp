#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3}; // -> we'll use {"a","b","c"} in the run
    int n = arr.size();

    // Loop through all possible subset masks
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            // Check if the i-th element is included
            if (mask & (1 << i)) {
                cout << arr[i] << " ";
            }
        }
        cout << "}" << endl;
    }

    return 0;
}


