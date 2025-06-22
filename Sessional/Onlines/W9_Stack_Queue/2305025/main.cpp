#include<iostream>
#include "QueueUsingStack.hpp"

using namespace std;




int main(){
    
    MyQueue *q = new MyQueue();
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->print();
}
