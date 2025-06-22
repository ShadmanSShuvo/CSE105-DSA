#include<iostream>
#include "stack.h"

using namespace std;

class MyQueue
{
private:
    Stack *st1 = new ArrayStack(); // main queue
    Stack *st2 = new ListStack(); // helper
    // int capacity;
public:
    MyQueue(){
        
        st1 = new ArrayStack();
        st2 = new ListStack();
    }

    void enqueue(int n){
        if(st1->empty())
            st1->push(n);
        while(!st1->empty()){
            st2->push(st1->top());
            st1->pop();
        }
        
        st1->push(n);
        while (!st2->empty())
        {
            int temp = st2->top();
            st2->pop();
            while(!st2->empty()){
                int temp2 = st2->top();
                st2->pop();
                st1->push(temp2);
            }
            st1->push(temp);
            st2->pop();
        }
        
    }

    int dequeue(){
        if(st1->empty())
            return -1;
        int val = st1->top();
        st1->pop();
        return val;

    }

    // int capacity(){
    //     return capacity;
    // }
    int size(){
        return st1->size();
    }

    void print(){
        while (!st1->empty())
        {
            std::cout << st1->top() << " " << std::endl;
            st1->pop();
        }
        
    }
    ~MyQueue(){
        st1->clear();
        st2->clear();
    }
};

