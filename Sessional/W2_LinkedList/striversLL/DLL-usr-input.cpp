#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

Node* insertHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head != nullptr) head->prev = newNode;
    return newNode;
}

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

Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos == 0) return insertHead(head, val);
    Node* temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; ++i)
        temp = temp->next;
    if (temp == nullptr) return head;
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    if (head != nullptr) head->prev = nullptr;
    delete temp;
    return head;
}

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

void printForward(Node* head) {
    cout << "Forward: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void printBackward(Node* head) {
    if (head == nullptr) {
        cout << "Backward: NULL\n";
        return;
    }
    while (head->next != nullptr)
        head = head->next;
    cout << "Backward: ";
    while (head != nullptr) {
        cout << head->data << " <-> ";
        head = head->prev;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, val, pos;

    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Print Forward\n";
        cout << "8. Print Backward\n";
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
                printForward(head);
                break;
            case 8:
                printBackward(head);
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