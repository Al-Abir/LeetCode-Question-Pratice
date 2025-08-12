
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> fact, digits;

    void solve(string& ans, int n, int k) {
        if (n == 1) { // Base case: only one digit left
            ans += to_string(digits.back());
            return;
        }

        // Find the index for the current position
        int index = k / fact[n - 1];
        if (k % fact[n - 1] == 0) 
            index -= 1;

        ans += to_string(digits[index]); // Add digit to answer
        digits.erase(digits.begin() + index); // Remove used digit

        k -= fact[n - 1] * index; // Update k
        solve(ans, n - 1, k); // Recurse for remaining positions
    }

public:
    string getPermutation(int n, int k) {
        // Store factorial values from 0! to n!
        fact.push_back(1);
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
            fact.push_back(f);
        }

        // Fill digits array with numbers 1 to n
        for (int i = 1; i <= n; i++) 
            digits.push_back(i);

        string ans = "";
        solve(ans, n, k);
        return ans;
    }
};


int main(){
     Solution sl;
     int n,k;
     cin>>n>>k;
     string s = sl.getPermutation(n,k);
    
     cout<<s<<endl;

}