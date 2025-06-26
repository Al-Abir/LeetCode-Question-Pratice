#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int prefix = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;  // For subarrays starting from index 0

        for (int j = 0; j < n; j++) {
            prefix += nums[j];
            int remove = prefix - k;
            cnt += mp[remove];  // Add number of times (prefix - k) has occurred
            mp[prefix]++; 
          
        }

        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, -2, 5}; // Input array
    int k = 5; // Target sum

    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;

    return 0;
}
