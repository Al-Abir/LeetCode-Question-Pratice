#include <iostream>
#include <stack>
using namespace std;

class SortedStack {
public:
    stack<int> s;
    void sort();
};

// helper function (class এর বাইরে থাকবে)
void insertSorted(stack<int> &s, int x) {
    // base case
    if (s.empty() || s.top() <= x) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}

// sort function (class এর member)
void SortedStack::sort() {
    if (s.empty()) return;

    int x = s.top();
    s.pop();

    sort();  // sort remaining stack

    insertSorted(s, x); // insert popped element in sorted order
}

int main() {
    SortedStack ss;

    // unsorted stack: bottom -> [11, 2, 32, 3, 41] <- top
    ss.s.push(11);
    ss.s.push(2);
    ss.s.push(32);
    ss.s.push(3);
    ss.s.push(41);

    cout << "Before Sorting (top to bottom): ";
    stack<int> temp = ss.s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    // call sort
    ss.sort();

    cout << "After Sorting (top to bottom): ";
    temp = ss.s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}
