#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans, vector<vector<bool>> &vis) {
    int n = mat.size();
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || vis[r][c]) {
        return;
    }

    if (r == n - 1 && c == n - 1) { 
        ans.push_back(path);
        return;
    }

    vis[r][c] = true;

    helper(mat, r + 1, c, path + "D", ans, vis); // down
    helper(mat, r - 1, c, path + "U", ans, vis); // up
    helper(mat, r, c - 1, path + "L", ans, vis); // left
    helper(mat, r, c + 1, path + "R", ans, vis); // right

    vis[r][c] = false; // backtrack
}

vector<string> findPath(vector<vector<int>> &mat) {
    int n = mat.size();
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    if (mat[0][0] == 0) return ans; // if start is blocked

    helper(mat, 0, 0, "", ans, vis);
    
    return ans;
}

int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPath(mat);

    if (paths.empty()) {
        cout << "No path found" << endl;
    } else {
        for (auto &p : paths) {
            cout << p << endl;
        }
    }
    return 0;
}
