#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;

    MyQueue() {
    }
    
    void push(int x) {
        // s1-এর সব element s2 তে পাঠাও
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        // নতুন element s1 তে push করো
        s1.push(x);

        // s2-এর সব element ফেরত আনো s1 এ
        while(!s2.empty()){
             s1.push(s2.top());
             s2.pop();
        }
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// ---------- Main Function ----------
int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Peek: " << q.peek() << endl; // 10
    cout << "Pop: " << q.pop() << endl;   // 10
    cout << "Peek: " << q.peek() << endl; // 20

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    q.pop();  // removes 20
    q.pop();  // removes 30

    cout << "Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
