#include "queue.h"
#include <iostream>
using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    if (initial_capacity <= 0)
    {
        initial_capacity = 2; // Ensure valid capacity
    }
    capacity = initial_capacity;
    front_idx = 0;
    rear_idx = 0; // Start with 0 to indicate empty queue
    data = new int[capacity + 1];
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    // TODO: Free the dynamically allocated memory for the array
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    // TODO: Check if the array is full
    // TODO: If full, resize the array to double its current capacity
    // TODO: Add the new element to the rear of the queue
    if (size() == capacity)
    {
        resize(capacity * 2);
    }
    data[rear_idx] = item;
    rear_idx = (rear_idx + 1) % (capacity + 1);
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Decrement current_size and return the element at the front of the queue
    // TODO: Update front index
    // TODO: Return the dequeued element
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int item = data[front_idx];
    front_idx = (front_idx + 1) % (capacity + 1);

    int current_size = size();
    if (current_size > 0 && current_size <= capacity / 4 && capacity > 2)
    {
        resize(max(2, capacity / 2));
    }
    return item;
}

// Clear implementation
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    delete[] data;
    capacity = 2;
    front_idx = 0;
    rear_idx = 0;
    data = new int[capacity + 1];
}

// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    return (rear_idx - front_idx + (capacity + 1)) % (capacity + 1);
}

// Front implementation
int ArrayQueue::front() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the front of the queue without removing it
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return data[front_idx];
}

// Back implementation (get the element at the back of the queue)
int ArrayQueue::back() const
{
    // TODO: Check if the queue is empty, display error message if it is
    // TODO: Return the element at the back of the queue without removing it
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return data[rear_idx-1];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return front_idx == rear_idx;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
    if (empty())
    {
        return "<|";
    }
    string result = "<";
    for (int i = 0; i < size(); i++)
    {
        result.append(to_string(data[(front_idx + i) % capacity]));
        if (i < size() - 1)
        {
            result.append(", ");
        }
    }
    result.append("|");
    return result;
}

// Resize implementation
void ArrayQueue::resize(int new_capacity)
{
    // TODO: Create a new array with the new capacity
    // TODO: Copy elements from the old array to the new array
    // TODO: Delete the old array
    // TODO: Update the data pointer and capacity
    // TODO: Update front and rear indices
    int *new_data = new int[new_capacity + 1];
    int sz = size();

    for (int i = 0; i < sz; ++i)
    {
        new_data[i] = data[(front_idx + i) % (capacity + 1)];
    }

    delete[] data;
    data = new_data;
    front_idx = 0;
    rear_idx = sz;
    capacity = new_capacity;
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}