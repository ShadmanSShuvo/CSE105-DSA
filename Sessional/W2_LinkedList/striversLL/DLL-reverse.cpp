#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;

    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

/*
Node *reverseLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }
    return head;
}
*/

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL)
    {
        prev = current->prev;
        current->prev = current->next;
        current->next = prev;
        current = current->prev;
    }
    return prev->prev;
}

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *dummyHead = new Node(-1);
    Node *curr = dummyHead;
    Node *templ = numl;
    Node *temp2 = num2;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (templ)
            sum += templ->data;
        if (temp2)
            sum += temp2->data;
        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
        if (templ)
            templ = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        feMode = new Node(carry);
        curr->next = newNode;
    }
    return dummyHead->next;
}

Node *sortList(Node *head)
{
    if(!head || !head->next)  // Fixed condition
        return head;
    
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);  // Fixed colon to semicolon
    
    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;
    
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;  // Fixed colon to semicolon
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;  // Moved outside of else block
    }
    
    // Connect the lists
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;
    
    Node *newHead = zeroHead->next;
    
    // Free dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return newHead;
}

Node* removeKthNode (Node* head, int k){
    Node* fast = head;
    Node* slow = head;
    for (int i = 0; i < k; i++) fast = fast->next; 
    if (fast== NULL) return head->next;
    while(fast->next!= NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode); 
    return head;
}
