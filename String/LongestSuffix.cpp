#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0; // length of the previous longest prefix suffix

        for (int i = 1; i < n; i++) {
            while (len > 0 && s[i] != s[len]) {
                len = lps[len - 1]; // fallback
            }

            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
            }
        }

        // lps[n-1] contains the length of the longest happy prefix
        return s.substr(0, lps[n - 1]);
    }
};

int main() {
    Solution solution;

    string input1 = "ababab";
    string input2 = "level";
    string input3 = "aabcdaabc";

    cout << "Input: " << input1 << " -> Longest happy prefix: " << solution.longestPrefix(input1) << endl;
    cout << "Input: " << input2 << " -> Longest happy prefix: " << solution.longestPrefix(input2) << endl;
    cout << "Input: " << input3 << " -> Longest happy prefix: " << solution.longestPrefix(input3) << endl;

    return 0;
}
