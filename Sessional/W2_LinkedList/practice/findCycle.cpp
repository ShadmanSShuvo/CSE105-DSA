#include <iostream>
#include <vector>  // Include this for std::vector
using namespace std;

class Node {   
    public:
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
};
int length(Node* head); // Forward declaration
// Function to convert vector to linked list
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

// Utility function to print the linked list
void printList(Node* head) {
    // Note: Avoid infinite loop if there's a cycle!
    int safety = 20; // To prevent infinite loop for test purposes
    while (head && safety--) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to detect cycle in a linked list using Floyd's Cycle Detection Algorithm
bool detectCycle(Node* head){
    if(head == NULL || head->next == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

// Function to find the starting node of the cycle in a linked list
Node* findCycleStart(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }
    if(slow != fast) return NULL;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Function to remove the cycle in a linked list
void removeCycle(Node* head){
    if(head == NULL || head->next == NULL) return;
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) break;
    }
    if(slow != fast) return;
    slow = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

// Function to create a cycle in the linked list for testing
void createCycle(Node* head, int pos){
    if(head == NULL || pos < 0) return;
    Node* cycleStart = NULL;
    Node* current = head;
    int count = 0;
    while(current->next != NULL){
        if(count == pos) cycleStart = current;
        current = current->next;
        count++;
    }
    current->next = cycleStart;
}

// Function to test the cycle detection and removal
void testCycleDetectionAndRemoval(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = convertArr2LL(arr);
    createCycle(head, 2); // Create a cycle at position 2

    cout << "Original List (may loop due to cycle, capped at 20 nodes): ";
    printList(head);
    cout << "Length of the list (including cycle): " << length(head) << endl;
    cout << "Cycle starts at node with value: " << findCycleStart(head)->data << endl;
    cout << "Detecting cycle..." << endl;
    if(detectCycle(head)){
        cout << "Cycle detected!" << endl;
        Node* cycleStart = findCycleStart(head);
        cout << "Cycle starts at node with value: " << cycleStart->data << endl;
        removeCycle(head);
        cout << "Cycle removed." << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    cout << "List after removing cycle: ";
    printList(head);
}

int length(Node* head) {
    if (head == nullptr) return 0;

    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    // Step 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // Step 2: No cycle
    if (!hasCycle) {
        int count = 0;
        while (head != nullptr) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Step 3: Find start of the cycle
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    Node* cycleStart = slow;

    // Step 4: Count nodes before the cycle
    int countBeforeCycle = 0;
    Node* current = head;
    while (current != cycleStart) {
        countBeforeCycle++;
        current = current->next;
    }

    // Step 5: Count nodes in the cycle
    int cycleLength = 1;
    current = cycleStart->next;
    while (current != cycleStart) {
        cycleLength++;
        current = current->next;
    }

    return countBeforeCycle + cycleLength;
}

// Main function to run the test
int main(){
    testCycleDetectionAndRemoval();
    return 0;
}