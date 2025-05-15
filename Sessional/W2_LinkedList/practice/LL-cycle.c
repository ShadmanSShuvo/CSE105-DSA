#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Print list with cycle detection
void printWithCycleDetection(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    // Detect if a cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("Cycle detected in the list. Printing stopped to avoid infinite loop.\n");
            return;
        }
    }

    // No cycle: safe to print
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    struct Node* fourth = NULL;

    // Create nodes
    head = createNode(10);
    second = createNode(20);
    third = createNode(30);
    fourth = createNode(40);

    // Connect them
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create a cycle: 40 -> 20
    fourth->next = second; // Cycle here

    // ⚠️ You should NOT try to print a list with a cycle using a normal print loop!
    // It will go into an infinite loop.
    printWithCycleDetection(head);
    printf("Linked list with a cycle created.\n");

    return 0;
}

