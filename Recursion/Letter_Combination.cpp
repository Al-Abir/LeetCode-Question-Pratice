#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }

private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[]){
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';
        string value = mapping[number];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index + 1, ans, mapping);
            output.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string digits;
    cout << "Enter digits (2-9): ";
    cin >> digits;

    vector<string> combinations = sol.letterCombinations(digits);

    cout << "Combinations:\n";
    for (const string &comb : combinations) {
        cout << comb << "\n";
    }

    return 0;
}
