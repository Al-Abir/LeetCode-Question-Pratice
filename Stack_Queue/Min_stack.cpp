#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> st, mn;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mn.push(val);
            return;
        }
        int minVal = min(val, mn.top());
        mn.push(minVal);
        st.push(val);
    }

    void pop() {
        if (st.empty()) return;
        st.pop();
        mn.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mn.top();
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top element: " << ms.top() << endl;       // should print 2
    cout << "Minimum element: " << ms.getMin() << endl; // should print 2

    ms.pop(); // remove 2
    cout << "Top element after pop: " << ms.top() << endl;       // should print 7
    cout << "Minimum element after pop: " << ms.getMin() << endl; // should print 3

    ms.pop(); // remove 7
    cout << "Top element now: " << ms.top() << endl;       // should print 3
    cout << "Minimum element now: " << ms.getMin() << endl; // should print 3

    return 0;
}
