#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function: Convert array to linked list
ListNode* arrayToLinkedList(int arr[], int n) {
    if (n == 0) return NULL;  // Empty array

    ListNode* head = new ListNode(arr[0]);  // First node
    ListNode* current = head;

    for (int i = 1; i < n; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* list = arrayToLinkedList(arr, n);

    cout << "Linked List: ";
    printList(list);

    return 0;
}
