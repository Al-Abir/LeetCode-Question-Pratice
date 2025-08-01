#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) return findMedianSortedArrays(nums2, nums1); // always binary search on smaller array

        int low = 0, high = n1;
        int total = n1 + n2;
        int half = (total + 1) / 2;

        while (low <= high) {
            int mid1 = (low + high) / 2;
            int mid2 = half - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == n2) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (total % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                high = mid1 - 1;
            } else {
                low = mid1 + 1;
            }
        }

        return 0.0; // control should never reach here
    }
};

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);

    cout << "Median of the two sorted arrays is: " << median << endl;

    return 0;
}
