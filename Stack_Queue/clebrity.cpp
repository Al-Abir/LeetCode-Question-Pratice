#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& mat, int n) {
    int top = 0, down = n - 1;

    // Step 1: Find potential celebrity
    while (top < down) {
        if (mat[top][down] == 1) {
            // top knows down => top cannot be celebrity
            top++;
        } else if (mat[down][top] == 1) {
            // down knows top => down cannot be celebrity
            down--;
        } else {
            // both eliminate
            top++;
            down--;
        }
    }

    int candidate = top; // potential celebrity

    // Step 2: Verify candidate
    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;

        // Candidate should not know anyone
        if (mat[candidate][i] == 1) return -1;

        // Everyone must know candidate
        if (mat[i][candidate] == 0) return -1;
    }

    return candidate;
}

int main() {
    vector<vector<int>> mat = {
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, 0}
    };
    int n = mat.size();

    int ans = celebrity(mat, n);
    if (ans == -1)
        cout << "No celebrity found\n";
    else
        cout << "Celebrity is person " << ans << "\n";
}
