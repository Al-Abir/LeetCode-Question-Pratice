#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> freq;
        queue<pair<char,int>> q;

        // Step 1: Build frequency + queue
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            freq[ch]++;
            q.push({ch, i});
        }

        // Step 2: Find first non-repeating
        while(!q.empty()){
            auto [ch, idx] = q.front();
            if(freq[ch] == 1) {
                return idx; // first unique char index
            }
            q.pop(); // not unique, remove
        }

        return -1;
    }
};

// ---------- Main Function ----------
int main() {
    Solution sol;

    string s1 = "leetcode";
    cout << "First unique char in \"" << s1 << "\": " << sol.firstUniqChar(s1) << endl;

    string s2 = "loveleetcode";
    cout << "First unique char in \"" << s2 << "\": " << sol.firstUniqChar(s2) << endl;

    string s3 = "aabb";
    cout << "First unique char in \"" << s3 << "\": " << sol.firstUniqChar(s3) << endl;

    return 0;
}
