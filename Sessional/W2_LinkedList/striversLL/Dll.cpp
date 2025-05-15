#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Insert at head
Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr) head->prev = newNode;
    return newNode;
}

// Insert at tail
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at position (0-based)
Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos == 0) return insertHead(head, val);

    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
        temp = temp->next;

    if (temp == nullptr) return head;  // Position out of bounds

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Delete head
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;

    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
    return head;
}

// Delete tail
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->prev->next = nullptr;
    delete temp;
    return head;
}

// Delete at position (0-based)
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos == 0) return deleteHead(head);

    Node* temp = head;
    for (int i = 0; i < pos && temp != nullptr; ++i)
        temp = temp->next;

    if (temp == nullptr) return head;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;
    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
    return head;
}

// Print forward
void printForward(Node* head) {
    cout << "Forward: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Print backward
void printBackward(Node* head) {
    if (head == nullptr) {
        cout << "Backward: NULL" << endl;
        return;
    }

    // Move to tail
    while (head->next != nullptr)
        head = head->next;

    cout << "Backward: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->prev;
    }
    cout << "NULL" << endl;
}

// Length
int length(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// Search value
bool search(Node* head, int val) {
    while (head != nullptr) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}

// Main function for testing
int main() {
    Node* head = nullptr;

    // Sample operations
    head = insertHead(head, 10);
    head = insertHead(head, 20);
    head = insertTail(head, 30);
    head = insertAtPosition(head, 25, 2); // After 20 -> 10

    printForward(head);
    printBackward(head);

    head = deleteHead(head);
    head = deleteTail(head);
    head = deleteAtPosition(head, 1); // Deletes node at position 1

    printForward(head);
    printBackward(head);

    cout << "Length: " << length(head) << endl;
    cout << "Is 10 present? " << (search(head, 10) ? "Yes" : "No") << endl;
    cout << "Is 99 present? " << (search(head, 99) ? "Yes" : "No") << endl;

    return 0;
}