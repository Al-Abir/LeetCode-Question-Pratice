#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int value;
    cin >> value;

    vector<int> ans;

 
    for (int i = coins.size() - 1; i >= 0; i--) {
        while (value >= coins[i]) {
            value -= coins[i];
            ans.push_back(coins[i]);
        }
    }

 
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
