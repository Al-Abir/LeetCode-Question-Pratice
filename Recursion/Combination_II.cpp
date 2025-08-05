#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void helper(vector<int>& candidates, int target, int start, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            // skip duplicates
            if(i > start && candidates[i] == candidates[i-1]) continue;

            if(candidates[i] > target) break;

            temp.push_back(candidates[i]);
            helper(candidates, target - candidates[i], i + 1, temp); // move to next index
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort first
        vector<int> temp;
        helper(candidates, target, 0, temp);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {1,1,2};
    int target = 3;

    vector<vector<int>> results = sol.combinationSum2(candidates, target);

    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& comb : results) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
