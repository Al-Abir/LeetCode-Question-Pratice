#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());  // Lexicographically sort
        int i = 0;

        while (i < strs[0].length() && strs[0][i] == strs[strs.size() - 1][i]) {
            ans += strs[0][i];
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sl;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter strings:\n";
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    string result = sl.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl;

    return 0;
}
