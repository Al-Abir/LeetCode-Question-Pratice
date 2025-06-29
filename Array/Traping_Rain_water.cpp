#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // Step 1: Calculate left max for each index
        vector<int> leftmax(n);
        leftmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftmax[i] = max(height[i], leftmax[i - 1]);
        }

        // Step 2: Calculate right max for each index
        vector<int> rightmax(n);
        rightmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightmax[i] = max(height[i], rightmax[i + 1]);
        }

        // Step 3: Calculate trapped water
        int trappedWater = 0;
        for (int i = 0; i < n; i++) {
            int waterLevel = min(leftmax[i], rightmax[i]);
            trappedWater += waterLevel - height[i];
        }

        return trappedWater;
    }
};

int main() {
    Solution sol;

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result = sol.trap(height);
    cout << "Trapped Water: " << result << endl;

    return 0;
}
