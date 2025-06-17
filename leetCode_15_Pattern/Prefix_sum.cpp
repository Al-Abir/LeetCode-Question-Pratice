#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long

void solve() {
       int arr[5] = {1,3,4,6,7};

       int prefix[5] ;

       prefix[0]= arr[0];

       for(int i =1; i<5; i++){
           prefix[i]= prefix[i-1]+ arr[i];
       }
       for(int num : prefix){
        cout<<num<<" ";
       }
       cout<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   
    while (t--) {
        solve();
    }

    return 0;
}