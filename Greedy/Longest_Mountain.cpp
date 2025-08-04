#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1), LDS(n, 1);

        // Step 1: Left to right - Longest Increasing Subsequence (LIS)
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    LIS[i] = max(LIS[i], LIS[j] + 1);
                }
            }
        }

        // Step 2: Right to left - Longest Decreasing Subsequence (LDS)
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    LDS[i] = max(LDS[i], LDS[j] + 1);
                }
            }
        }

        // Step 3: Find max mountain length
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (LIS[i] > 1 && LDS[i] > 1) {
                maxMountainLength = max(maxMountainLength, LIS[i] + LDS[i] - 1);
            }
        }

        return n - maxMountainLength;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    cout << "Minimum removals: " << sol.minimumMountainRemovals(nums) << endl;
    return 0;
}
