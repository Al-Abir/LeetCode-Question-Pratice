#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to check if placing 'dig' at (row, col) is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == dig) return false;
            if (board[i][col] == dig) return false;
        }

        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[startRow + r][startCol + c] == dig) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true;
        if (col == 9) return solve(board, row + 1, 0);

        if (board[row][col] != '.') return solve(board, row, col + 1);

        for (char dig = '1'; dig <= '9'; dig++) {
            if (isSafe(board, row, col, dig)) {
                board[row][col] = dig;
                if (solve(board, row, col + 1)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solver;
    solver.solveSudoku(board);

    cout << "Solved Sudoku Board:" << endl;
    for (auto &row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
