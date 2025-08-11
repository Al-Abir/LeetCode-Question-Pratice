#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getAllSubSet(vector<int>& nums, vector<int> &ans, int i, vector<vector<int>>& allsubset){
        if(i == nums.size()){
            allsubset.push_back(ans); // ✅ FIXED this line
            return; // ✅ Added missing return
        }

        // Include current element
        ans.push_back(nums[i]);
        getAllSubSet(nums, ans, i + 1, allsubset);
        ans.pop_back(); // ✅ Backtrack after include

        // Skip duplicates in exclude path
        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[i]){
            idx++;
        }

        // Exclude current element
        getAllSubSet(nums, ans, idx, allsubset); // ✅ FIXED: pass idx, not idx+1
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;
        sort(nums.begin(), nums.end()); // ✅ Sort to group duplicates
        getAllSubSet(nums, ans, 0, allsubset);
        return allsubset;
    }
};

int main(){

    Solution sl;

    vector<int> nums={1,2,3};

    vector<vector<int>> allSubset = sl.subsetsWithDup(nums);

    for(auto &num: allSubset){
        cout<<"["<<" ";
        for(int &i: num){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    cout<<endl;



}