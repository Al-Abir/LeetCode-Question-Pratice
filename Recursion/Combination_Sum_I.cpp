#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& candidates, int target, int i, int cursum, vector<int>& temp) {
        // If current sum exceeds target, no need to proceed
        if (cursum > target) return;

        // If we've reached end of array
        if (i == candidates.size()) return;

        // If current sum matches target, store the current combination
        if (cursum == target) {
            ans.push_back(temp);
            return;
        }

        // Include current element
        temp.push_back(candidates[i]);
        helper(candidates, target, i, cursum + candidates[i], temp);
        temp.pop_back(); // backtrack

        // Exclude current element and move to next
        helper(candidates, target, i + 1, cursum, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(candidates, target, 0, 0, temp);
        return ans;
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    Solution obj;
    vector<vector<int>> result = obj.combinationSum(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
