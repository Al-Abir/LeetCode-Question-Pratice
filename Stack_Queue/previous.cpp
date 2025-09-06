#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> preGreaterEle(vector<int>& arr) {
    int n = arr.size();
    // initialize all PGEs as -1
    vector<int> result(n, -1); 
    
    // stack to keep track of elements
    stack<int> s; 

    // traverse the array from left to right
    for (int i = 0; i < n; i++) {
        
        // pop elements from stack which are <= current element
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // if stack is not empty, top element is PGE
        if (!s.empty()) {
            result[i] = s.top();
        }

        // push current element onto stack
        s.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {10, 4, 2, 20, 40, 12, 30};
    vector<int> pge = preGreaterEle(arr);

    for (int x : pge) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}