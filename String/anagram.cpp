#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        map<char, int> mp;

        for (char c : s) {
            mp[c]++;
        }

        for (char c : t) {
            mp[c]--;
        }

        for (auto [ch, count] : mp) {
            if (count != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    
    string s1 = "listen";
    string s2 = "silent";

    if (sol.isAnagram(s1, s2)) {
        cout << "Anagram!" << endl;
    } else {
        cout << "Not an Anagram!" << endl;
    }

    return 0;
}
