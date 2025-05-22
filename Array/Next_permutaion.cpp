#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;
        int n = nums.size();
        
        // Step 1: Find the first decreasing element from the end
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        
        // Step 2: If no such element found, reverse the entire array
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 3: Find the just larger element to the right of nums[i]
            for (j = n - 1; j >= 0; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            // Step 4: Swap and reverse the suffix
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    
    sol.nextPermutation(nums);
    
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
