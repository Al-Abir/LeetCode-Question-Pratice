#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int p[4] = {1, 2, 5, 6};
    int wt[4] = {2, 3, 4, 5};

    int m = 8;
    int k[5][9]; // (items+1) x (capacity+1)

    // Build DP table
    for (int item = 0; item <= 4; item++) {
        for (int w = 0; w <= m; w++) {
            if (item == 0 || w == 0) {
                k[item][w] = 0;
            } 
            else if (wt[item - 1] <= w) {
                k[item][w] = max(p[item - 1] + k[item - 1][w - wt[item - 1]], 
                                 k[item - 1][w]);
            } 
            else {
                k[item][w] = k[item - 1][w];
            }
        }
    }

    cout << "Maximum Profit: " << k[4][m] << endl;

    // Backtrack to find which items are taken
    int i = 4, j = m;
    while (i > 0 && j > 0) {
        if (k[i][j] == k[i - 1][j]) {
            cout << "Item " << i << " -> not taken (0)" << endl;
            i--;
        } else {
            cout << "Item " << i << " -> taken (1)" << endl;
            j = j - wt[i - 1];
            i--;
        }
    }
}
