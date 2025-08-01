#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
#define ll long long

bool isPossible(vector<int> arr, int n, int m, int maxAllowedTime){

    int painters=1, time =0;
    for(int i=0; i<arr.size(); i++){
        if(time+arr[i]<=maxAllowedTime){
            time+=arr[i];
        }else{
            painters++;
            time = arr[i];
        }

    }
    return painters<=m;

}

int minmumPainter(vector<int> arr, int n, int m){
    
    int sum =0, maxValue=INT_MIN;
    for(int i=0; i<arr.size(); i++){
         sum+=arr[i];
         maxValue= max(maxValue,arr[i]);
    }

    int start = maxValue;
    int end = sum;
    int ans =-1;

    while (start<=end)
    {
        int mid = start+ (end-start)/2;
        if(isPossible(arr,n, m, mid)){
             ans =mid;
             end = mid-1;
        }else{
            start= mid+1;
        }

    }

    return ans;
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {40,30,10,20};
    int n=4,m=2;

    cout<<minmumPainter(arr,n,m)<<endl;
   

    return 0;
}