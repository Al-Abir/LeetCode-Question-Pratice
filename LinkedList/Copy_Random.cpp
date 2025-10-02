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
        if(head==nullptr){
            return nullptr;
        }
        unordered_map<Node*,Node*> m;

        // নতুন হেড বানাই
        Node* newHead = new Node(head->val);
        Node* oldTemp= head->next;
        Node* newTemp= newHead;
        m[head]= newHead;

        // সব next pointer copy
        while(oldTemp!=nullptr){
            Node* copyNode = new Node(oldTemp->val);
            m[oldTemp]=copyNode;
            newTemp->next = copyNode;

            oldTemp= oldTemp->next;
            newTemp = newTemp->next;
        }

        // random pointer copy
        oldTemp=head, newTemp = newHead;
        while(oldTemp!=nullptr){
            newTemp->random = m[oldTemp->random];
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }

        return newHead;
    }
};

// Print list for debugging
void printList(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << "Val: " << temp->val;
        if(temp->random)
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
    n1->random = n3; // 1.random = 3
    n2->random = n1; // 2.random = 1
    n3->random = nullptr; // 3.random = null

    cout << "Original list:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "Copied list:\n";
    printList(copied);

    return 0;
}
