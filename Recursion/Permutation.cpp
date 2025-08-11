#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   vector<vector<int> > ans;
        void helper (vector<int>&nums,int i){
            if(i==nums.size()-1){
                ans.push_back(nums);
                return;
            }
            for(int j =i ; j<nums.size(); j++){
                  swap(nums[i],nums[j]);
                  helper(nums, i+1);

                  //  backtraking 
                  swap(nums[i], nums[j]);

            }
        }

        vector<vector<int> >permute(vector<int>&nums){
             helper(nums,0);
             return ans;
        
    }
};

int main(){

    Solution sl;

    vector<int> nums={1,2,3};

    vector<vector<int>> allSubset = sl.permute(nums);

    for(auto &num: allSubset){
        cout<<"["<<" ";
        for(int &i: num){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    cout<<endl;



}