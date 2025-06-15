#include "queue.h"
#include <iostream>
using namespace std;

// Constructor implementation
ListQueue::ListQueue()
{
    front_node = nullptr;
    rear_node = nullptr;
    current_size = 0;
}

// Destructor implementation
ListQueue::~ListQueue()
{
    clear();
}

// Enqueue implementation (add an item at the rear of the queue)
void ListQueue::enqueue(int item)
{
    Node* new_node = new Node(item);
    if (empty())
    {
        front_node = rear_node = new_node;
    }
    else
    {
        rear_node->next = new_node;
        rear_node = new_node;
    }
    current_size++;
}

// Dequeue implementation (remove an item from the front of the queue)
int ListQueue::dequeue()
{
    if (empty())
    {
        cout << "\nQueue is empty\n";
        return -1;
    }
    int res = front_node->data;
    Node *temp = front_node;
    front_node = front_node->next;
    if (front_node == nullptr)
    {
        rear_node = nullptr;
    }
    current_size--;
    delete temp;
    return res;
}

// Clear implementation (delete all elements)
void ListQueue::clear()
{
    Node* temp = front_node;
    while (temp != nullptr)
    {
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
    return current_size;
}

// Front implementation (get the element at the front of the queue)
int ListQueue::front() const
{
    if (empty())
    {
        cout << "\nQueue is empty\n";
        return -1;
    }
    return front_node->data;
}

// Back implementation (get the element at the back of the queue)
int ListQueue::back() const
{
    if (empty())
    {
        cout << "\nQueue is empty\n";
        return -1;
    }
    return rear_node->data;
}

// Empty implementation (check if the queue is empty)
bool ListQueue::empty() const
{
    return front_node == nullptr;
}

// Print implementation (print elements from front to rear)
string ListQueue::toString() const
{
    if (empty())
    {
        return "<|";
    }
    Node* current = front_node;
    string res = "<";
    while (current != nullptr)
    {
        res += to_string(current->data);
        if (current->next != nullptr)
        {
            res += ", ";
        }
        current = current->next;
    }
    res += "|";
    return res;
}