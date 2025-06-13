#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> arr = {6, 3, 9, 8, 2, 5};

    for (int i = 1; i < arr.size(); i++) {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }

    for (int val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
