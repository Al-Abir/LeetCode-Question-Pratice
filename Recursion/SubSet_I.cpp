#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  void getAllSubset(vector<int>& nums,vector<int> ans, int i,vector<vector<int>>& allSubset){
    if(i==nums.size()){
         allSubset.push_back({ans});
         return;
    }
    //include
    ans.push_back(nums[i]);
    getAllSubset(nums, ans, i+1, allSubset);

    //backtrack
    ans.pop_back();
    getAllSubset(nums,ans, i+1,allSubset);
  }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubset;
        vector<int> ans;
         
         getAllSubset(nums,ans,0, allSubset);
        
        return allSubset;
    }
};

int main(){

    Solution sl;

    vector<int> nums={1,2,3};

    vector<vector<int>> allSubset = sl.subsets(nums);

    for(auto &num: allSubset){
        cout<<"["<<" ";
        for(int &i: num){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    cout<<endl;



}