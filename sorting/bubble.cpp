#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

void solve() {
   vector<int> arr = {6, 3, 9, 8, 2, 5};

   for(int i =0; i<arr.size()-1; i++){
      for(int j=0; j<arr.size()-1-i; j++){
                if(arr[j]>arr[j+1]){
                     int temp = arr[j];
                     arr[j]= arr[j+1];
                     arr[j+1]= temp;
                }
      }
   }
   for(int val :arr){
    cout<<val<<" ";
   }
    
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