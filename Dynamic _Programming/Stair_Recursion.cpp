#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    // Base cases
    if (n == 0) return 1;   // exactly reached the top
    if (n < 0) return 0;   // invalid path

    // Recursive relation
    return climbStairs(n - 1) + climbStairs(n - 2);
}

int main() {
    int n;
    cin >> n;

    cout << climbStairs(n);
    return 0;
}
