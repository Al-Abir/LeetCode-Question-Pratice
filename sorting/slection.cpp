#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

void solve() {
    // Your code here
    vector<int> arr = {6, 3, 9, 8, 2, 5};
    // soto element first pass a font asbe;

    for(int i=0; i<arr.size(); i++){
         int min =i;
         for(int j = i+1; j<arr.size(); j++){
               if(arr[min]>arr[j]){
                   min =j;
               }
            
              
         }
          int temp = arr[min];
               arr[min]= arr[i];
               arr[i]=temp;
    }

    for(int val : arr){
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