#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || head->next == nullptr || left == right) {
            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;
        int i = 1;

        // Step 1: move curr to left-th node
        while (curr != nullptr && i < left) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        // pointers to connect later
        ListNode* pointerToStart = prev;
        ListNode* start = curr;
        prev = nullptr;

        // Step 2: reverse from left to right
        while (curr != nullptr && i <= right) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        // Step 3: reconnect reversed sublist with rest
        start->next = curr;
        if (pointerToStart != nullptr) {
            pointerToStart->next = prev;
        } else {
            // if left == 1 then new head is prev
            return prev;
        }

        return head;
    }
};

// Helper function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Example: Input list = 1->2->3->4->5, left = 2, right = 4
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.reverseBetween(head, 2, 4);

    cout << "After reversing from position 2 to 4: ";
    printList(head);

    return 0;
}
