#include <iostream>
using namespace std;

// Stack Class
class Stack {
private:
    int top;
    int size;
    int* arr;

public:
    Stack(int sz) {
        size = sz;
        arr = new int[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Queue Class
class Queue {
private:
    int front, rear, size, capacity;
    int* arr;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    void dequeue() {
        if (size == 0) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        front = (front + 1) % capacity;
        size--;
    }

    int peek() {
        if (size == 0) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

// Main function to test both
int main() {
    cout << "----- Testing Stack -----" << endl;
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();

    cout << "\n----- Testing Queue -----" << endl;
    Queue q(5);
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.display();

    return 0;
}