#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k > q.size()) return q;  // Invalid k
        
        stack<int> st;
        int n = k;
        
        // Step 1: Push first k elements into stack
        while(n--){
            st.push(q.front());
            q.pop();
        }
        
        // Step 2: Pop from stack and enqueue back to queue
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        // Step 3: Move remaining elements to back to maintain order
        int remaining = q.size() - k;
        while(remaining--){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

int main() {
    queue<int> q;
    
    // Example: Queue = {1, 2, 3, 4, 5}
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    
    int k = 3;
    
    Solution sol;
    queue<int> result = sol.reverseFirstK(q, k);
    
    // Print the resulting queue
    cout << "Reversed first " << k << " elements: ";
    while(!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    
    return 0;
}
