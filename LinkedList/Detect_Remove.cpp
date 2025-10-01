#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void removeLoop(Node* head) {
    if (!head || !head->next) return;

    Node *slow = head, *fast = head;

    // Detect loop
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (slow != fast) return; // no loop

    slow = head;

    if (slow == fast) {
        // Loop at head
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = nullptr;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);

    // make a loop: 4 -> 1
    head->next->next->next = head;
   
    removeLoop(head);

    printLinkedList(head);

    return 0;
}
