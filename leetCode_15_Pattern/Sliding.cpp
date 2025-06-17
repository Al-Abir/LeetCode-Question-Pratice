#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long

void solve() {
    vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    int n = arr.size();

    int currentSum = 0;
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    int max_sum = currentSum;

    for (int i = 1; i <= n - k; i++) {
        currentSum = currentSum - arr[i - 1] + arr[i + k - 1];
        max_sum = max(max_sum, currentSum);
    }

    cout << max_sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
