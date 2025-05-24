#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans ;
      
        for(int i =0; i<n; i++){

            int start = arr[i][0];
            int end = arr[i][1];

            if(!ans.empty()&& end<=ans.back()[1]){
                 continue;
            }
            for(int j=i+1; j<n; j++){
                 if(arr[j][0]<=end){
                     end = max(end,arr[j][1]);
                 }else{
                    break;
                 }
            }
            ans.push_back({start,end});

            //time complexity minimize code
            /*for(int i =0; i<n; i++){
            if(ans.empty() || arr[i][0]> ans.back()[1]){
                 ans.push_back(arr[i]);
            }else{
                 ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
            }*/
        }
         return ans;
    }
};

int main(){
    Solution sc ;
   vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
   vector<vector<int>> merged = sc.merge(intervals);

      for(auto& interval: merged){
      cout << "[" << interval[0] << ", " << interval[1] << "] ";
      }
      cout<<endl;

}