#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int i = st; i < end; i++) {
        if (arr[i] < pivot) {
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quick_sort(vector<int>& arr, int st, int end) {
    if (st >= end) return;

    int pivotIdx = partition(arr, st, end);
    quick_sort(arr, st, pivotIdx - 1);   // Left half
    quick_sort(arr, pivotIdx + 1, end);  // Right half
}

void solve() {
    vector<int> arr = {6, 3, 9, 8, 2, 5};
    quick_sort(arr, 0, arr.size() - 1);

    for (int val : arr) {
        cout << val << " ";
    }
    cout << '\n';
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
