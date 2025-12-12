#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
    int knapscak(int p[], int wt[], int W, int n){
        // Base case
        if(W == 0 || n == 0){
            return 0;
        }

        // If current item weight <= remaining weight
        if(wt[n-1] <= W){
            int ans1 = p[n-1] + knapscak(p, wt, W - wt[n-1], n - 1);
            int ans2 = knapscak(p, wt, W, n - 1);

            return max(ans1, ans2);
        }
        else{
            return knapscak(p, wt, W, n - 1);
        }
    }
};

int main() {
    int p[5] = {15, 14, 10, 45, 30};
    int wt[5] = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;

    Solution st;
    int maxProfit = st.knapscak(p, wt, W, n);

    cout << maxProfit << endl;
}
