#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; // cycle detected
            }
        }
        return false; // no cycle
    }
};

int main() {
    // লিস্ট বানানো: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;

    // Case 1: No cycle
    cout << "Has cycle? " << (sol.hasCycle(head) ? "true" : "false") << endl;

    // Case 2: Create cycle (5 -> 2)
    head->next->next->next->next->next = head->next;
    cout << "Has cycle? " << (sol.hasCycle(head) ? "true" : "false") << endl;

    return 0;
}
