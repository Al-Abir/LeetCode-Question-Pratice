#include<iostream>
#include<climits>
#include<vector>

using namespace std;
class Solution {
public:
    bool distributedPossiable(vector<int>& quantities, int stores, int maxProduct){

             int storeCount =0;

             for(int i=0; i< quantities.size(); i++){
                 storeCount+=quantities[i]/maxProduct;

                 if(quantities[i]%maxProduct !=0){
                    storeCount+=1;
                 }

                 if(storeCount>stores){
                    return false;
                 }
             }

             return true;

    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        
        int start =1;
        int end = INT_MIN;

        for(int i=0; i<quantities.size(); i++){
              if(end<quantities[i]){
                 end=quantities[i];
              }
        }

        int res=-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(distributedPossiable(quantities,n,mid)){
                  res=mid;
                  end=mid-1;
            }else{
                start = mid+1;
            }
        }
        return res;
    }
};


int main(){
     int n;
     cin>>n;
     int q;
     cin>>q;

     vector<int> quantities(q);
     for(auto &i : quantities) cin>>i;


     Solution sl;

     int ans = sl.minimizedMaximum(n, quantities);

     cout<<ans;
    
}