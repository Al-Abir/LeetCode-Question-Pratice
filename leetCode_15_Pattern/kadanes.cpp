#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

void solve() {
    // Your code here
     int arr[5] = {-1,-3,4,6,7};
     int max =arr[0],sum=0;
     // maximum subarray sum 
     for(int i=0; i<5; i++){
         sum+= arr[i];
        if(sum>max){
            max = sum;
        }
        if(sum<0){
            sum=0;
         }
     }
     cout<<max<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t; // Uncomment for multiple test cases
    while (t--) {
        solve();
    }

    return 0;
}