#include <bits/stdc++.h>
using namespace std;

int climbStairsMemo(int n, vector<int>& dp) {
    if (n <= 1) return 1;  // base case

    if (dp[n] != -1) return dp[n]; // already calculated

    // store result before returning
    return dp[n] = climbStairsMemo(n - 1, dp) + climbStairsMemo(n - 2, dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << climbStairsMemo(n, dp);
}
