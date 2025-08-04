#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
  public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int cnt = 0, mxCount = INT_MIN;
        int i = 0, j = 0;

        while (i < arr.size()) {
            if (arr[i] <= dep[j]) {
                cnt++;
                i++;
            } else {
                cnt--;
                j++;
            }
            mxCount = max(mxCount, cnt);
        }

        return mxCount;
    }
};

int main() {
    // Example input
    vector<int> arrival  = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

    Solution sol;
    int result = sol.findPlatform(arrival, departure);
    cout << "Minimum Number of Platforms Required = " << result << endl;

    return 0;
}
