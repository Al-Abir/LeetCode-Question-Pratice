#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSameFreq(int freq[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.size(); i++) {
            freq[s1[i] - 'a']++;
        }

        int window = s1.size();

        for (int i = 0; i <= s2.size() - window; i++) {
            int freq_window[26] = {0};
            for (int j = 0; j < window; j++) {
                freq_window[s2[i + j] - 'a']++;
            }

            if (isSameFreq(freq, freq_window)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if (sol.checkInclusion(s1, s2)) {
        cout << "s2 contains a permutation of s1" << endl;
    } else {
        cout << "s2 does NOT contain a permutation of s1" << endl;
    }

    return 0;
}
