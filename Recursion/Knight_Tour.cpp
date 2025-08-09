#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int row, int col, int expect) {
        int n = grid.size();
        // base case: out of bounds or value mismatch
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expect) {
            return false;
        }
        // reached the last expected number
        if (expect == n * n - 1) {
            return true;
        }

        // try all 8 knight moves
        int ans1 = isValid(grid, row - 2, col + 1, expect + 1);
        int ans2 = isValid(grid, row - 1, col + 2, expect + 1);
        int ans3 = isValid(grid, row + 1, col + 2, expect + 1);
        int ans4 = isValid(grid, row + 2, col + 1, expect + 1);
        int ans5 = isValid(grid, row + 2, col - 1, expect + 1);
        int ans6 = isValid(grid, row + 1, col - 2, expect + 1);
        int ans7 = isValid(grid, row - 1, col - 2, expect + 1);
        int ans8 = isValid(grid, row - 2, col - 1, expect + 1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, 0);
    }
};

int main() {
    Solution sol;

    // Example grid for testing (replace with your own test cases)
    vector<vector<int>> grid = {
        {0, 11, 16, 5, 20},
        {17, 4, 19, 10, 15},
        {12, 1, 8, 21, 6},
        {3, 18, 23, 14, 9},
        {24, 13, 2, 7, 22}
    };

    if (sol.checkValidGrid(grid)) {
        cout << "Valid knight tour\n";
    } else {
        cout << "Invalid knight tour\n";
    }

    return 0;
}
