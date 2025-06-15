#include "queue.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    if (initial_capacity <= 0)
    {
        initial_capacity = 2; // Ensure valid capacity
    }
    capacity = initial_capacity;
    front_idx = 1;
    rear_idx = 0; // Start with 0 to indicate empty queue
    data = new int[capacity];
}

// Destructor implementation
ArrayQueue::~ArrayQueue()
{
    delete[] data;
}

// Enqueue implementation (add an item to the rear of the queue)
void ArrayQueue::enqueue(int item)
{
    if (size() == capacity)
    {
        resize(capacity * 2);
    }
    rear_idx = (rear_idx + 1) % capacity;
    data[rear_idx] = item;
}

// Dequeue implementation (remove an item from the front of the queue)
int ArrayQueue::dequeue()
{
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int item = data[front_idx];
    front_idx = (front_idx + 1) % capacity;
    if (size() > 0 && size() <= capacity / 4 && capacity > 2)
    {
        resize(max(2, capacity / 2));
    }
    return item;
}

// Clear implementation
void ArrayQueue::clear()
{
    delete[] data;
    capacity = 2;
    data = new int[2];
    front_idx = 0;
    rear_idx = -1; // Reset to empty state
}

// Size implementation
int ArrayQueue::size() const
{
    if (rear_idx < front_idx)
    {
        return (rear_idx + capacity - front_idx) % capacity;
    }
    return rear_idx - front_idx + 1;
}

// Front implementation
int ArrayQueue::front() const
{
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
    if (empty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return data[rear_idx];
}

// Empty implementation
bool ArrayQueue::empty() const
{
    return rear_idx < front_idx || (rear_idx == front_idx && front_idx == 0 && rear_idx == -1);
}

// Print implementation
string ArrayQueue::toString() const
{
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
    if (new_capacity <= 0)
    {
        cerr << "Invalid capacity. Capacity must be positive." << endl;
        return;
    }
    int old_size = size();
    int *new_data = new int[new_capacity];
    for (int i = 0; i < old_size; i++)
    {
        new_data[i] = data[(front_idx + i) % capacity];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
    front_idx = 0;
    rear_idx = old_size - 1;
    if (old_size == 0)
    {
        rear_idx = -1; // Ensure empty queue state
    }
}

int ArrayQueue::getCapacity() const
{
    return capacity;
}