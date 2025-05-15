#include <iostream>
#include <vector>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Convert vector to linked list
Node* convertArr2LL(const vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < arr.size(); ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Print linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Count length of linked list
int lengthOfLL(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// Check if value is present
bool checkIfPresent(Node* head, int val) {
    while (head != nullptr) {
        if (head->data == val) return true;
        head = head->next;
    }
    return false;
}

// Remove head
Node* removeHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

// Remove tail
Node* removeTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// Remove k-th node (1-based)
Node* removeK(Node* head, int k) {
    if (head == nullptr) return nullptr;
    if (k == 1) return removeHead(head);

    int cnt = 1;
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (cnt == k) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        cnt++;
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Remove by value
Node* removeEl(Node* head, int el) {
    if (head == nullptr) return nullptr;
    if (head->data == el) return removeHead(head);

    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr) {
        if (temp->data == el) {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insert at head
Node* insertHead(Node* head, int val) {
    Node* temp = new Node(val);
    temp->next = head;
    return temp;
}

// Insert at tail
Node* insertTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Insert at position k (0-based)
Node* insertPosition(Node* head, int el, int k) {
    if (head == nullptr) {
        if (k == 0) return new Node(el);
        else return nullptr;
    }
    if (k == 0) return insertHead(head, el);

    int cnt = 1;
    Node* temp = head;
    while (temp != nullptr) {
        if (cnt == k) {
            Node* newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        cnt++;
        temp = temp->next;
    }
    return head;
}

// Insert before a value
Node* insertBeforeValue(Node* head, int el, int val) {
    if (head == nullptr) return nullptr;
    if (head->data == val) return insertHead(head, el);

    Node* temp = head;
    Node* prev = nullptr;
    bool found = false;
    while (temp != nullptr) {
        if (temp->data == val) {
            found = true;
            Node* newNode = new Node(el);
            prev->next = newNode;
            newNode->next = temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!found) return nullptr;
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);

    cout << "Original list:\n";
    printList(head);

    // Example usage
    head = insertHead(head, 0);
    head = insertTail(head, 6);
    head = insertPosition(head, 99, 3); // Insert at position 3
    head = insertBeforeValue(head, 88, 5); // Insert 88 before 5
    head = removeHead(head);
    head = removeTail(head);
    head = removeK(head, 3); // Remove 3rd node
    head = removeEl(head, 88); // Remove value 88

    cout << "\nFinal list:\n";
    printList(head);

    return 0;
}
