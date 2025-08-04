#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  
        sort(s.begin(), s.end());  

        int child = 0, cookie = 0;

        while (child < g.size() && cookie < s.size()) {
            if (s[cookie] >= g[child]) {
                // কুকির সাইজ যথেষ্ট, এই শিশুকে খুশি করা গেল
                child++;
            }
            cookie++;
        }

        return child;  // যতজন শিশু খুশি হলো
    }
};

int main() {
    Solution sol;

    // উদাহরণ ইনপুট
    vector<int> g = {1, 2};        // শিশুদের গ্রীড লেভেল
    vector<int> s = {1, 2, 3};     // কুকির সাইজ

    int result = sol.findContentChildren(g, s);

    cout << "Number of content children: " << result << endl;

    return 0;
}
