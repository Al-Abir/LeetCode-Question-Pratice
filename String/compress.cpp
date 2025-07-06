#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;
        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int cnt = 0;

            while (i < n && chars[i] == ch) {
                cnt++, i++;
            }

            if (cnt == 1) {
                chars[idx++] = ch;
            } else {
                chars[idx++] = ch;
                string s = to_string(cnt);
                for (char digit : s) {
                    chars[idx++] = digit;
                }
            }
            i--;  // Compensate for the for-loop increment
        }
        chars.resize(idx);
        return idx;
    }
};

int main() {
    Solution sol;

    // Sample input: ['a','a','b','b','c','c','c']
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int newLength = sol.compress(chars);

    cout << "Compressed Length: " << newLength << endl;
    cout << "Compressed Characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
