#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;  // stores indices

        // First window
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // Process rest of the windows
        for (int i = k; i < nums.size(); i++) {
            ans.push_back(nums[dq.front()]);  // push max of last window

            // Remove indices out of current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }

        // Add the maximum for the last window
        ans.push_back(nums[dq.front()]);

        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    // Print output
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
