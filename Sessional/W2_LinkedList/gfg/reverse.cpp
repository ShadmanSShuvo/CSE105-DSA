#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to reverse linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;    // Save next
        curr->next = prev;    // Reverse the link
        prev = curr;          // Move prev forward
        curr = next;          // Move curr forward
    }

    return prev;  // New head
}

// Utility function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility function to insert a new node at the beginning
Node* insertFront(Node* head, int data) {
    Node* newNode = new Node{data, head};
    return newNode;
}

int main() {
    Node* head = nullptr;

    // Creating list: 10 -> 20 -> 30 -> 40 -> 50
    head = insertFront(head, 50);
    head = insertFront(head, 40);
    head = insertFront(head, 30);
    head = insertFront(head, 20);
    head = insertFront(head, 10);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}