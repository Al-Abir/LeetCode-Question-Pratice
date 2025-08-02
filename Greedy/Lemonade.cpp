#include <iostream>
#include <vector>
using namespace std;

class Solution {    
public:    
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (int bill : bills) {
            if (bill == 5) {
                five++;  // no change needed
            } 
            else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;  // can't give change
                }
            } 
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } 
                else if (five >= 3) {
                    five -= 3;
                } 
                else {
                    return false;  // can't give change
                }
            }
        }

        return true;  // able to give change to all customers
    }
};

int main() {
    Solution sol;
    vector<int> bills = {5, 5, 5, 10, 20};  // sample test case

    if (sol.lemonadeChange(bills)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}
