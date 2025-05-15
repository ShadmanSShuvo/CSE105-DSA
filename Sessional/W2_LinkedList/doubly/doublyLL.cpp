#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(Node*& head, int val) {
    Node* temp = head;

    while (temp && temp->data != val)
        temp = temp->next;

    if (!temp) return;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next)
        temp->next->prev = temp->prev;

    delete temp;
}

void printListForward(Node* head) {
    cout << "Forward: ";
    Node* last = nullptr;
    while (head) {
        cout << head->data << " <-> ";
        last = head;
        head = head->next;
    }
    cout << "NULL\n";
}

void printListBackward(Node* tail) {
    cout << "Backward: ";
    while (tail && tail->next)
        tail = tail->next;

    while (tail) {
        cout << tail->data << " <-> ";
        tail = tail->prev;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtBeginning(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 40);

    printListForward(head);
    printListBackward(head);

    deleteNode(head, 20);
    cout << "After Deletion:\n";
    printListForward(head);
    printListBackward(head);

    return 0;
}