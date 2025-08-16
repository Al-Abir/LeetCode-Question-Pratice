#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s){
            if(ch=='(' || ch=='[' || ch=='{'){
                st.push(ch);
            } else {
                if(st.empty()) return false; 

                if((ch==')' && st.top()=='(') || 
                   (ch==']' && st.top()=='[') || 
                   (ch=='}' && st.top()=='{')){
                    st.pop();
                } else {
                    return false; 
                }
            }
        }
        return st.empty(); 
    }
};

// ---------- Main Function ----------
int main() {
    Solution sol;

    string s1 = "()[]{}";
    cout << s1 << " -> " << (sol.isValid(s1) ? "Valid" : "Invalid") << endl;

    string s2 = "([)]";
    cout << s2 << " -> " << (sol.isValid(s2) ? "Valid" : "Invalid") << endl;

    string s3 = "{[]}";
    cout << s3 << " -> " << (sol.isValid(s3) ? "Valid" : "Invalid") << endl;

    string s4 = "(";
    cout << s4 << " -> " << (sol.isValid(s4) ? "Valid" : "Invalid") << endl;

    return 0;
}
