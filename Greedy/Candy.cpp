#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> left(n, 1);  // Step 1: Initialize with 1 candy

        // Step 2: Left to right pass
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Step 3: Right to left pass using single variable `right`
        int right = 1;
        for (int j = n - 2; j >= 0; j--) {
            if (A[j] > A[j + 1]) {
                right++;
                left[j] = max(left[j], right);
            } else {
                right = 1;
            }
        }

        // Step 4: Sum of candies
        int total = 0;
        for (int c : left) {
            total += c;
        }

        return total;
    }
};

int main() {
    Solution sol;
    vector<int> ratings = {1, 3, 2, 2, 1};  // Example input
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;
    return 0;
}
