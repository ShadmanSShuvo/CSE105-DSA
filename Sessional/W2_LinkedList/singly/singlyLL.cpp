#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertAtBeginning(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
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
}

void deleteNode(Node*& head, int val) {
    if (!head) return;

    if (head->data == val) {
        Node* del = head;
        head = head->next;
        delete del;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data != val)
        temp = temp->next;

    if (temp->next) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insertAtEnd(head, 10);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 30);
    insertAtEnd(head, 40);

    cout << "Linked List: ";
    printList(head);

    deleteNode(head, 20);
    cout << "After Deletion: ";
    printList(head);

    return 0;
}