#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Comparator to sort intervals by end time
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];  // sort by ending time (earliest first)
    }

    int MaximumNonOverlappingIntervals(vector<vector<int>>& Intervals) {
        if (Intervals.empty()) return 0;

        sort(Intervals.begin(), Intervals.end(), cmp);

        int cnt = 1;
        int lastEndingTime = Intervals[0][1];

        for (int i = 1; i < Intervals.size(); i++) {
            if (Intervals[i][0] >= lastEndingTime) {
                cnt++;
                lastEndingTime = Intervals[i][1];
            }
        }

        return Intervals.size() - cnt;  // minimum intervals to remove
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 4}, {3, 5}, {5, 6}};
    
    cout << "Minimum intervals to remove: " << sol.MaximumNonOverlappingIntervals(intervals) << endl;

    return 0;
}
