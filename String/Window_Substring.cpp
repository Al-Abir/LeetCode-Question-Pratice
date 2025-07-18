#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        int n = t.size();
        int m = s.size();
        int count = 0;
        int l = 0, r = 0, minLen = INT_MAX, startIndex = -1;

        for (char c : t) {
            map[c]++;
        }

        while (r < m) {
            if (map[s[r]] > 0) count++;
            map[s[r]]--;

            while (count == n) {
                if (r - l + 1 < minLen) {
                    startIndex = l;
                    minLen = r - l + 1;
                }

                map[s[l]]++;
                if (map[s[l]] > 0) count--;

                l++;
            }

            r++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;

    return 0;
}
