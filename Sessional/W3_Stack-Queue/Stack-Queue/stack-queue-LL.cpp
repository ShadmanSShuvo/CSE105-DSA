#include <iostream>
using namespace std;

class StackNode {
public:
    int data;
    StackNode* next;

    StackNode(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
private:
    StackNode* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (!isEmpty()) pop();
    }

    void push(int val) {
        StackNode* newNode = new StackNode(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (StackNode* curr = top; curr != nullptr; curr = curr->next)
            cout << curr->data << " ";
        cout << endl;
    }
};


#include <iostream>
using namespace std;

class QueueNode {
public:
    int data;
    QueueNode* next;

    QueueNode(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) dequeue();
    }

    void enqueue(int val) {
        QueueNode* newNode = new QueueNode(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (QueueNode* curr = front; curr != nullptr; curr = curr->next)
            cout << curr->data << " ";
        cout << endl;
    }
};



int main() {
    cout << "----- Stack Using Linked List -----" << endl;
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    s.display();

    cout << "\n----- Queue Using Linked List -----" << endl;
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    q.display();

    return 0;
}