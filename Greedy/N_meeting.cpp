#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    
    // Pair up start and end times
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++) {
        meetings.push_back({end[i], start[i]});  // sort by end time
    }

    // Sort meetings by end time
    sort(meetings.begin(), meetings.end());

    int count = 0;
    int lastEnd = -1;

    for (auto m : meetings) {
        int meetingEnd = m.first;
        int meetingStart = m.second;

        if (meetingStart > lastEnd) {  // strictly greater, not >=
            count++;
            lastEnd = meetingEnd;
        }
    }

    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of meetings: " << maxMeetings(start, end) << endl;

    return 0;
}
