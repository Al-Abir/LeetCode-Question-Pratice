#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // Palindrome checker function
    bool isPalindrome(string s , int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& partitions, string s) {
        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++) {
            if(isPalindrome(s, 0, i)) {
                string part = s.substr(0, i + 1);
                partitions.push_back(part);
                solve(ans, partitions, s.substr(i + 1));
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        solve(ans, partitions, s);
        return ans;
    }
};

// --------------------
// ✅ Main Function
// --------------------
int main() {
    Solution sol;
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    vector<vector<string>> result = sol.partition(input);

 
    for(const auto& partition : result) {
        cout << "[ ";
        for(const auto& part : partition) {
            cout << "\"" << part << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}
