#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string getFrequencyString(const string& str) {
    // Frequency array for 26 lowercase letters
    vector<int> freq(26, 0);
    
    // Count each character's frequency
    for (char c : str) {
        freq[c - 'a']++;
    }

    // Build the frequency string
    string frequencyString;
    for (int i = 0; i < 26; i++) {
        frequencyString += (char)('a' + i); // character
        frequencyString += to_string(freq[i]); // its count
    }

    return frequencyString;
}

vector<vector<string>> groupAnagramsCategorizeByFrequency(vector<string>& strs) {
    vector<vector<string>> result;

    // Edge case: empty input
    if (strs.empty()) return result;

    unordered_map<string, vector<string>> frequencyStringsMap;

    for (const string& str : strs) {
        string frequencyString = getFrequencyString(str);

        // Group the string under its frequency signature
        frequencyStringsMap[frequencyString].push_back(str);
    }

    // Extract the grouped anagrams from the map
    for (const auto& entry : frequencyStringsMap) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<string> str;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        str.push_back(s);
    }

 
    vector<vector<string>> ans = groupAnagramsCategorizeByFrequency(str);

    cout << '[';
    for (int i = 0; i < ans.size(); i++) {
        cout << '[';
        for (int j = 0; j < ans[i].size(); j++) {
            cout << '\"' << ans[i][j] << '\"';
            if (j != ans[i].size() - 1) cout << ',';
        }
        cout << ']';
        if (i != ans.size() - 1) cout << ',';
    }
    cout << ']';

    return 0;
}
