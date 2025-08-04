#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;  // Sort by profit in descending order
    }

    vector<int> jobScheduling(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;

        // Step 1: Pair deadlines with profits
        for (int i = 0; i < n; ++i) {
            jobs.push_back({deadline[i], profit[i]});
        }

        // Step 2: Sort jobs by profit descending
        sort(jobs.begin(), jobs.end(), cmp);

        // Step 3: Find max deadline to determine size of slot array
        int maxDeadline = 0;
        for (auto& job : jobs) {
            maxDeadline = max(maxDeadline, job.first);
        }

        // Step 4: Create time slots array, initialized as free (false)
        vector<bool> slots(maxDeadline + 1, false);  // 1-based indexing

        int jobCount = 0, totalProfit = 0;

        // Step 5: Try placing each job
        for (auto& job : jobs) {
            int d = job.first;
            int p = job.second;

            // Find a free slot from d to 1
            for (int j = d; j > 0; --j) {
                if (!slots[j]) {
                    slots[j] = true;       // Occupy the slot
                    jobCount++;
                    totalProfit += p;
                    break;
                }
            }
        }

        return {jobCount, totalProfit};
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> deadline1 = {4, 1, 1, 1};
    vector<int> profit1 = {20, 10, 40, 30};
    vector<int> result1 = sol.jobScheduling(deadline1, profit1);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;

    vector<int> deadline2 = {2, 1, 2, 1, 1};
    vector<int> profit2 = {100, 19, 27, 25, 15};
    vector<int> result2 = sol.jobScheduling(deadline2, profit2);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;

    vector<int> deadline3 = {3, 1, 2, 2};
    vector<int> profit3 = {50, 10, 20, 30};
    vector<int> result3 = sol.jobScheduling(deadline3, profit3);
    cout << "[" << result3[0] << ", " << result3[1] << "]" << endl;

    return 0;
}
