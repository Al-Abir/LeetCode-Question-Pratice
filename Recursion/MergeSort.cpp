#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int si, int mid, int ei){
        vector<int> temp;
        int i = si, j = mid + 1;

        while(i <= mid && j <= ei){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= ei){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = 0, idx = si; k < (int)temp.size(); k++, idx++){
            nums[idx] = temp[k];
        }
    }

    void mergeSort(vector<int>& nums, int si, int ei){
        if(si < ei){
            int mid = (si + ei) / 2;
            mergeSort(nums, si, mid);
            mergeSort(nums, mid + 1, ei);
            merge(nums, si, mid, ei);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2, 3, -5, 10, 0, 7};

    vector<int> sorted = sol.sortArray(nums);

    cout << "Sorted array: ";
    for(int val : sorted) {
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}
