#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find the k-th node in the list
Node* findNthNode(Node* temp, int k) {
    int cnt = 1;
    while (temp != NULL) {
        if (cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

// Function to rotate the linked list by k positions
Node* rotate(Node* head, int k) {
    if (head == NULL || k == 0) return head;

    // Find the length and last node
    Node* tail = head;
    int len = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        len++;
    }

    // If k is a multiple of length, rotation not needed
    if (k % len == 0) return head;

    k = k % len;

    // Attach the tail to the head to make it circular
    tail->next = head;

    // Find the new last node
    Node* newLastNode = findNthNode(head, len - k);

    // Set the new head and break the circular link
    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;
}

// Helper function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    head = rotate(head, k);

    printList(head);  // Output: 4 5 1 2 3

    return 0;
}
