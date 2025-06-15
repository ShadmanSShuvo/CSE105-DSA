#include "queue.h"
#include <iostream>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    // TODO: Initialize front_node and rear_node
    // TODO: Initialize current_size to 0
    front_node = nullptr;
    rear_node = nullptr;
    current_size = 0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    // TODO: Deallocate all nodes in the linked list
    // TODO: Consider using the clear() method
    clear();
    front_node = nullptr;
    rear_node = nullptr;
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    // TODO: Create a new node with the given item
    // TODO: Link the new node to the rear
    // TODO: Update the rear_node
    // TODO: Increment the current size
    Node* new_node = new Node(item);
    rear_node->next = new_node;
    //new_node->next = rear_node;
    rear_node = new_node;
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Store the data from the front node
    // TODO: Update the front pointer to the next node
    // TODO: Update the rear pointer if the queue becomes empty
    // TODO: Delete the old front node
    // TODO: Decrement current_size
    // TODO: Return the stored data
    if (empty()){
        std::cout << "\nQueue is empty\n";
        return INT32_MIN;
    }
    int res = front_node->data;
    Node *temp = front_node;
    front_node = front_node->next;
    if (front_node == nullptr){
        rear_node = nullptr;
    }
    current_size--;
    delete temp;
    return res;
}


// Clear implementation (delete all elements)
void ListQueue::clear()
{
    // TODO: Traverse the linked list and delete each node
    // TODO: Reset front and rear pointer
    // TODO: Reset current_size to 0
    Node* temp = front_node;
    while(temp != nullptr){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    front_node = nullptr;
    rear_node = nullptr;
    current_size = 0;
}

// Size implementation (return the current number of elements)
int ListQueue::size() const
{
    // TODO: Return the current size (current_size)
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the front node without removing it
        if (empty()){
            std::cout << "\nQueue is empty\n";
            return INT32_MIN;
        }
        int res = front_node->data;
        return res;
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the data from the back node without removing it
    if (empty()){
        std::cout << "\nQueue is empty\n";
        return INT32_MIN;
    }
    int res = rear_node->data;
    return res;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    // TODO: Return whether front is nullptr
    return front_node == nullptr;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    // TODO: Traverse the linked list from front
    Node* current = front_node;
    string res = "<";
    while (current != nullptr){
        res += std::to_string(current->data) + ", ";
        current = current->next;
    }
    res.pop_back();
    res.pop_back();
    res += ">";
    return res;
}
