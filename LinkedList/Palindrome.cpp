#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to reverse a linked list
Node* reverseLinkedList(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list
    Node* newHead = reverseLinkedList(slow->next);

    // Compare the first half with the reversed second half
    Node* first = head;
    Node* second = newHead;

    while (second != NULL) {
        if (first->data != second->data) {
            // Restore the list before returning
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    // Restore the list
    reverseLinkedList(newHead);
    return true;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Helper function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    // Example 1: Palindrome
    Node* head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    head1->next->next->next = newNode(2);
    head1->next->next->next->next = newNode(1);

    std::cout << "Original list: ";
    printList(head1);

    if (isPalindrome(head1)) {
        std::cout << "The list is a palindrome." << std::endl;
    } else {
        std::cout << "The list is not a palindrome." << std::endl;
    }
    
    std::cout << "Restored list: ";
    printList(head1);
    
    std::cout << "\n------------------\n" << std::endl;

    // Example 2: Not a palindrome
    Node* head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = newNode(4);
    
    std::cout << "Original list: ";
    printList(head2);

    if (isPalindrome(head2)) {
        std::cout << "The list is a palindrome." << std::endl;
    } else {
        std::cout << "The list is not a palindrome." << std::endl;
    }
    
    std::cout << "Restored list: ";
    printList(head2);

    return 0;
}