#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) {
                return false; 
            }
            maxIndex = max(maxIndex, i + nums[i]); 
        }

        return true; 
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};

    cout << "Test Case 1: " << (sol.canJump(nums1) ? "Can jump" : "Cannot jump") << endl;
    cout << "Test Case 2: " << (sol.canJump(nums2) ? "Can jump" : "Cannot jump") << endl;

    return 0;
}
