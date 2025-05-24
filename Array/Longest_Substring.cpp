#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        set<char> si;
        int start = 0, end = 0;
        int maxlen = 0;

        while (start < s.size()) {
            if (si.find(s[start]) == si.end()) {
                si.insert(s[start]);
                maxlen = max(maxlen, start - end + 1);  
                start++;
            } else {
                si.erase(s[end]);
                end++;
            }
        }

        return maxlen;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sc;
    int ans = sc.lengthOfLongestSubstring(s);
    cout << ans << endl;

    return 0;
}
