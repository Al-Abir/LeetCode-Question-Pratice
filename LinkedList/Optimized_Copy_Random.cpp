#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* curr = head;

        // Step 1: Insert copy nodes after each original node
        while (curr != nullptr) {
            Node* temp = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp;
        }

        // Step 2: Assign random pointers for copy nodes
        curr = head;
        while (curr != nullptr) {
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate original and copied list
        Node* original = head;
        Node* copy = head->next;
        Node* copyHead = copy;  // store head of copied list

        while (original != nullptr) {
            original->next = original->next->next;
            if (copy->next != nullptr) {   // null check
                copy->next = copy->next->next;
            }
            original = original->next;
            copy = copy->next;
        }

        return copyHead;
    }
};

// Helper function to print list (for debugging)
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val;
        else
            cout << ", Random: NULL";
        cout << "\n";
        temp = temp->next;
    }
    cout << "-------------------\n";
}

int main() {
    // Create original list: 1 -> 2 -> 3
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    n1->next = n2;
    n2->next = n3;

    // Set random pointers
    n1->random = n3;   // 1.random = 3
    n2->random = n1;   // 2.random = 1
    n3->random = nullptr; // 3.random = NULL

    cout << "Original list:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "Copied list:\n";
    printList(copied);

    return 0;
}
