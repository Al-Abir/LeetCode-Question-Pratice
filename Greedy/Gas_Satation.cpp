#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;

        for (auto val : gas) {
            totalGas += val;
        }

        for (auto val2 : cost) {
            totalCost += val2;
        }

        if (totalGas < totalCost) {
            return -1;
        }

        int start = 0, currentGas = 0;

        for (int i = 0; i < gas.size(); i++) {
            currentGas += (gas[i] - cost[i]);

            if (currentGas < 0) {
                currentGas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};

int main() {
    Solution sol;

    // Example Input
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = sol.canCompleteCircuit(gas, cost);

    if (result == -1) {
        cout << "Not possible to complete the circuit." << endl;
    } else {
        cout << "Start at station: " << result << endl;
    }

    return 0;
}
