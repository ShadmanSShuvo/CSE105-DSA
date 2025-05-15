#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at head
Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

// Insert at tail
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Insert at specific position (0-indexed)
Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos == 0) return insertHead(head, val);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
        temp = temp->next;
    if (temp == nullptr) return head;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete head
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
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
    while (temp->next->next != nullptr) temp = temp->next;
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Delete at position (0-indexed)
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos == 0) return deleteHead(head);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; ++i)
        temp = temp->next;
    if (temp->next == nullptr) return head;
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

// Print the linked list
void printList(Node* head) {
    cout << "List: ";
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Driver code with user menu
int main() {
    Node* head = nullptr;
    int choice, val, pos;

    do {
        cout << "\nSingly Linked List Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Print List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> val;
                head = insertHead(head, val);
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> val;
                head = insertTail(head, val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                head = insertAtPosition(head, val, pos);
                break;
            case 4:
                head = deleteHead(head);
                break;
            case 5:
                head = deleteTail(head);
                break;
            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                head = deleteAtPosition(head, pos);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}