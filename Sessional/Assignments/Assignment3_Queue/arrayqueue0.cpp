#include "queue.h"
#include <iostream>
#include <cmath>

using namespace std;
// Constructor implementation
ArrayQueue::ArrayQueue(int initial_capacity)
{
    // TODO: Initialize data members (data, capacity, front_idx, rear_idx)
    // TODO: Allocate memory for the array with the specified initial capacity
    capacity = initial_capacity;
    front_idx = rear_idx = 0;
    data = new int[capacity];
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
    if (size() == capacity - 1)
    {
        resize(capacity * 2);
    }
    
    if (empty())
    {
        front_idx = rear_idx = 0; // Initialize indices if queue is empty
    }
    else
    {
        rear_idx = (rear_idx + 1) % capacity; // Move rear index forward with wrap-around
    }
    data[rear_idx] = item;
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
        //cout << "Queue is empty!" << endl;
        return -1;
    }
    else
    {
        int item = data[front_idx];
        front_idx = (front_idx + 1) % capacity;
        // No need to reset - empty() handles the check properly
        return item;
    }
}

// Clear implementation
/**
void ArrayQueue::clear()
{
    // TODO: Reset the queue to be empty (reset capacity, front_idx, rear_idx, data)
    // delete[] data;
    // capacity = 0;
    front_idx = rear_idx = -1;
    // data = new int[2]; // Reset to a default capacity of 2
    // capacity = 2; // Reset capacity to default
    // ArrayQueue();
}
*
void ArrayQueue::clear()
{
    delete[] data;
    capacity = 2;
    data = new int[2]; // Reallocate with same capacity
    front_idx = rear_idx = 0;
}
*/
void ArrayQueue::clear()
{
    delete[] data;  // Free the old array
    capacity = 2;   // Reset capacity to default
    front_idx = rear_idx = 0;  // Just reset indices
}
// Size implementation
int ArrayQueue::size() const
{
    // TODO: Return the number of elements currently in the queue
    return (rear_idx - front_idx + capacity) % capacity;
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
    else
    {
        int item = data[front_idx];
        return item;
    }
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
    else
    {
        int item = data[rear_idx];
        return item;
    }
}

// Empty implementation
bool ArrayQueue::empty() const
{
    // TODO: Return whether the queue is empty (current_size == 0)
    return (rear_idx == front_idx) ? 1 : 0;
}

// Print implementation
string ArrayQueue::toString() const
{
    // TODO: Convert queue to a string representation in the format: <elem1, elem2, ..., elemN|
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
// void ArrayQueue::resize(int new_capacity)
// {
//     // TODO: Create a new array with the new capacity
//     // TODO: Copy elements from the old array to the new array
//     // TODO: Delete the old array
//     // TODO: Update the data pointer and capacity
//     // TODO: Update front and rear indices
//     int *new_data = new int[new_capacity];
//     for (int i = 0; i < size(); i++)
//     {
//         new_data[i] = data[(front_idx + i) % capacity];
//     }
//     delete[] data;
//     data = new_data;
//     capacity = new_capacity;
// }

void ArrayQueue::resize(int new_capacity)
{
        // TODO: Create a new array with the new capacity
//     // TODO: Copy elements from the old array to the new array
//     // TODO: Delete the old array
//     // TODO: Update the data pointer and capacity
//     // TODO: Update front and rear indices
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
    front_idx = 0;           // Reset to start
    rear_idx = old_size;     // Point to next insertion position
}

int ArrayQueue::getCapacity() const
{
    // TODO: Return the current capacity of the queue
    return capacity;
}