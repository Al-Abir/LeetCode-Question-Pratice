#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // total rows
        int n = matrix[0].size();     // total columns

        int row = 0;                  // start from top-right
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) col--;
            else row++;
        }

        return false;
    }
};

int main(){
    Solution sl;
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n)); // ✅ Fixed here

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    bool ans = sl.searchMatrix(matrix, target);

    if(ans){
        cout << "Founded";
    } else {
        cout << "Not Founded";
    }

    return 0;
}
