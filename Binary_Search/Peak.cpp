#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 1;
        int end = arr.size() - 2;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main(){
     Solution sl;
     int n;
     cin>>n;
     vector<int> arr(n);
     for(auto &i:arr) cin>>i;

     int result = sl.peakIndexInMountainArray(arr);
     cout<<result<<endl;
}