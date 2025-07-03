#include <iostream>
#include <string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') continue;

            string word = "";
            while (i < n && s[i] != ' ') {
                word += s[i++];
            }

            reverse(word.begin(), word.end());
            if (!word.empty()) {
                if (!ans.empty()) ans += " ";
                ans += word;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);  // input with spaces

    string reversed = sol.reverseWords(s);
    cout << "Reversed words: " << reversed << endl;

    return 0;
}
 