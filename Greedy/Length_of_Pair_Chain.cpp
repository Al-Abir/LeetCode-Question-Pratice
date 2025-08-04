#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int prev = 0;
        int res = 1;

        for (int i = 1; i < pairs.size(); i++) {
            if (pairs[prev][1] < pairs[i][0]) {
                prev = i;
                res++;
            }
        }

        return res;
    }
};

int main() {
    int n;
    cout << "Enter number of pairs: ";
    cin >> n;

    vector<vector<int>> pairs(n, vector<int>(2));
    cout << "Enter each pair (two integers per line):\n";
    for (int i = 0; i < n; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    Solution sol;
    cout << "Longest chain length: " << sol.findLongestChain(pairs) << endl;

    return 0;
}
