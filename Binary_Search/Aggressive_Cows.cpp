#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
bool canWePlace(vector<int> &arr, int dis, int cows){
    int cntCows =1, last = arr[0];

    for(int i=1; i<arr.size(); i++){
          if(arr[i]-last>=dis){
             cntCows++;
             last=arr[i];
          }
          if(cntCows>=cows) return true;
    }

    return false;
}
void solve() {
    // Your code here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr) cin>>i;
    int cows;
    cin>>cows;
    sort(arr.begin(),arr.end());

    int low =0 , high = arr[n-1]-arr[0];

    while(low<=high){
        int mid = (low+high)/2;

        if(canWePlace(arr,mid,cows)==true){
            low =mid+1;
        }else{
            high=mid-1;
        }
    }

    cout<<high<<endl;
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