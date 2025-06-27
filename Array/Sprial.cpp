#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, startCol = 0;
        int endRow = m - 1, endCol = n - 1;

        while (startRow <= endRow && startCol <= endCol) {

            // Traverse top row
            for (int j = startCol; j <= endCol; j++) {
                ans.push_back(matrix[startRow][j]);
            }
            startRow++;

            // Traverse right column
            for (int i = startRow; i <= endRow; i++) {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;

            // Traverse bottom row
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    ans.push_back(matrix[endRow][j]);
                }
                endRow--;
            }

            // Traverse left column
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sl;
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n)); // ✅ ঠিক করা

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<int> ans = sl.spiralOrder(matrix);

    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
