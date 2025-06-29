#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n, 0);  // Nearest smaller to left
    vector<int> right(n, 0); // Nearest smaller to right
    stack<int> s;

    // Right smaller
    for (int i = n - 1; i >= 0; i--) {
        while (s.size() > 0 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Clear stack before reusing
    while (!s.empty()) s.pop();

    // Left smaller
    for (int i = 0; i < n; i++) {
        while (s.size() > 0 && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Calculate max area
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int currArea = heights[i] * width;
        ans = max(ans, currArea);
    }

    return ans;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest Rectangle Area: " << largestRectangleArea(heights) << endl;
    return 0;
}
