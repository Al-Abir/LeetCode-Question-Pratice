#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {  // Left half is sorted
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {  // Right half is sorted
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = sol.search(nums, target);

    if (index != -1) {
        cout << "Target " << target << " found at index " << index << endl;
    } else {
        cout << "Target " << target << " not found in array." << endl;
    }

    return 0;
}
