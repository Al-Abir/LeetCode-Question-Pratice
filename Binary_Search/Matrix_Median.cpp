#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // একটি row তে target এর চেয়ে ছোট বা সমান কতগুলো সংখ্যা আছে, তা বের করা
    int findSmaller(vector<vector<int>> &mat, int target) {
        int numberOfElements = 0;

        for (int i = 0; i < mat.size(); i++) {
            int start = 0;
            int end = mat[i].size() - 1;

            while (start <= end) {
                int mid = (start + end) / 2;

                if (mat[i][mid] <= target) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            numberOfElements += start; // start এখন row-এর মধ্যে কয়টা সংখ্যা ≤ target তা বোঝায়
        }
        return numberOfElements;
    }

    int median(vector<vector<int>> &mat) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 1;
        int high = 2000;

        while (low <= high) {
            int mid = (low + high) / 2;
            int count = findSmaller(mat, mid);

            if (count <= (row * col) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};

int main() {
    
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    Solution sol;
    int result = sol.median(mat);
    cout << "Median of the matrix is: " << result << endl;

    return 0;
}
