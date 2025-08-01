#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int>& a, vector<int>& b, int n1, int n2, int k) {
    if (n1 > n2) return kthElement(b, a, n2, n1, k);  // Always binary search on smaller array

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high) {
        int mid1 = (low + high) / 2;  // a থেকে mid1 টা নিলাম
        int mid2 = k - mid1;          // b থেকে বাকি গুলো (k - mid1)

        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
        int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
        int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) {
            high = mid1 - 1;
        } else {
            low = mid1 + 1;
        }
    }
    return 0;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};
    int k = 5;

    cout << "The " << k << "th element is: " << kthElement(arr1, arr2, arr1.size(), arr2.size(), k) << endl;

    arr1 = {7, 12, 14, 15};
    arr2 = {1, 2, 3, 4, 9, 11};
    k = 5;

    cout << "The " << k << "th element is: " << kthElement(arr1, arr2, arr1.size(), arr2.size(), k) << endl;

    return 0;
}
