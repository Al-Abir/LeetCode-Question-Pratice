#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n = 4; // number of items
    int m = 8; // maximum bag capacity

    int wt[5] = {0, 2, 3, 4, 5}; // 1-indexed weight
    int P[5]  = {0, 1, 2, 5, 6}; // 1-indexed value

    int k[5][9]; // DP table

    // Fill DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                k[i][w] = 0;
            } else if (wt[i] <= w) {
                k[i][w] = max(P[i] + k[i-1][w - wt[i]], k[i-1][w]);
            } else {
                k[i][w] = k[i-1][w];
            }
        }
    }

    // Maximum value
    cout << "Maximum value = " << k[n][m] << endl;

    // Backtracking to find which items are taken
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (k[i][j] == k[i-1][j]) {
            cout << "Item " << i << " -> not taken (0)" << endl;
        } else {
            cout << "Item " << i << " -> taken (1)" << endl;
            j = j - wt[i]; // Corrected line
        }
        i--;
    }

    return 0;
}
