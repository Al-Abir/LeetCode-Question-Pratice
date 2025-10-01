#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) {
        val = _val;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr = head;

        while (curr != nullptr) {
            // যদি child থাকে
            if (curr->child != nullptr) {
                Node* next = curr->next;

                // child লিস্ট ফ্ল্যাট করে সংযুক্ত করা
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;

                // tail খুঁজে বের করা
                while (curr->next != nullptr) {
                    curr = curr->next;
                }

                // tail এর সাথে next লিঙ্ক করা
                if (next != nullptr) {
                    curr->next = next;
                    next->prev = curr;
                }
            }
            // পরের নোডে যাওয়া
            curr = curr->next;
        }
        return head;
    }
};

// লিস্ট প্রিন্ট করার ফাংশন
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

// টেস্ট করার জন্য main function
int main() {
    /*
       Example List বানানো হবে:

       1 - 2 - 3 - 4 - 5
               |
               6 - 7
                   |
                   8
    */

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // main level
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    n4->next = n5; n5->prev = n4;

    // child links
    n3->child = n6;
    n6->next = n7; n7->prev = n6;
    n7->child = n8;

    Solution sol;
    Node* flatHead = sol.flatten(n1);

    cout << "Flattened list: ";
    printList(flatHead);

    return 0;
}
