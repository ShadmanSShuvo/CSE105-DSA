# Stack and Queue Lab Evaluation Problems

## Easy Problems (Warm-up)

### 1. Basic Stack Operations
Write a function that takes an ArrayStack and performs the following operations:
- Push the numbers 1, 2, 3, 4, 5 onto the stack
- Pop two elements and print them
- Print the top element without removing it
- Print the current size of the stack

**Expected Output**: 5, 4, Top: 3, Size: 3

### 2. Queue Reversal
Write a function that takes a ListQueue with elements [1, 2, 3, 4, 5] and uses a stack to reverse the order of elements in the queue.

**Expected Output**: Queue should contain [5, 4, 3, 2, 1] in that order

### 3. Stack to Queue Transfer
Given an ArrayStack with elements [10, 20, 30, 40] (40 on top), transfer all elements to an ArrayQueue while maintaining the same order (10 should be at front of queue).

### 4. Palindrome Checker (Simple)
Write a function that uses a stack to check if a string is a palindrome. Only consider alphabetic characters and ignore case.
Test with: "racecar", "hello", "A man a plan a canal Panama"

## Medium Problems (Conceptual Understanding)

### 5. Balanced Parentheses Checker
Implement a function that uses a stack to check if parentheses are balanced in an expression. Consider three types: (), [], {}

```cpp
bool isBalanced(string expression);
```

Test cases:
- "((()))" → true
- "([{}])" → true
- "([)]" → false
- "{[}" → false

### 6. Queue using Two Stacks
Implement a queue class using two ArrayStack objects. Your class should support enqueue, dequeue, front, and empty operations.

```cpp
class QueueUsingStacks {
private:
    ArrayStack stack1;
    ArrayStack stack2;
public:
    void enqueue(int value);
    int dequeue();
    int front();
    bool empty();
};
```

### 7. Stack using Two Queues
Implement a stack class using two ListQueue objects. Your class should support push, pop, top, and empty operations.

```cpp
class StackUsingQueues {
private:
    ListQueue queue1;
    ListQueue queue2;
public:
    void push(int value);
    int pop();
    int top();
    bool empty();
};
```

### 8. Next Greater Element
Given an array of integers, find the next greater element for each element using a stack. If no greater element exists, return -1.

Example: [4, 5, 2, 25, 7, 8] → [5, 25, 25, -1, 8, -1]

### 9. Sliding Window Maximum
Given an array and a window size k, find the maximum element in each sliding window using a queue-based approach.

Example: arr = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]

## Hard Problems (Advanced Applications)

### 10. Expression Evaluator
Implement a calculator that evaluates postfix expressions using a stack. Support +, -, *, / operators.

```cpp
double evaluatePostfix(string expression);
```

Test cases:
- "2 3 + 4 *" → 20
- "15 7 1 1 + - / 3 * 2 1 1 + + -" → 5

### 11. Infix to Postfix Converter
Convert infix expressions to postfix notation using a stack. Handle operator precedence and parentheses.

```cpp
string infixToPostfix(string infix);
```

Test cases:
- "a+b*c" → "abc*+"
- "(a+b)*c" → "ab+c*"
- "a+b*c-d" → "abc*+d-"

### 12. Largest Rectangle in Histogram
Given heights of bars in a histogram, find the area of the largest rectangle that can be formed using a stack-based approach.

Example: heights = [2, 1, 5, 6, 2, 3] → 10

### 13. Queue Reconstruction by Height
You have a queue of people with (height, number of people in front who are taller). Reconstruct the original queue using your queue implementation.

Example: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

### 14. Design a Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

```cpp
class MinStack {
private:
    ArrayStack mainStack;
    ArrayStack minStack;
public:
    void push(int value);
    int pop();
    int top();
    int getMin();
};
```

### 15. Circular Queue Implementation
Design a circular queue using an array with the following operations. Handle edge cases properly.

```cpp
class CircularQueue {
private:
    int* data;
    int front, rear, size, capacity;
public:
    CircularQueue(int k);
    bool enQueue(int value);
    bool deQueue();
    int Front();
    int Rear();
    bool isEmpty();
    bool isFull();
};
```

### 16. Stock Span Problem
Calculate the span of stock prices using a stack. The span is the number of consecutive days before the current day where the price was less than or equal to today's price.

Example: prices = [100, 80, 60, 70, 60, 75, 85]
Output: spans = [1, 1, 1, 2, 1, 4, 6]

### 17. Implement LRU Cache
Design and implement a Least Recently Used (LRU) cache using a combination of queue and additional data structures.

```cpp
class LRUCache {
private:
    int capacity;
    // Use your queue implementation along with other structures
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);
};
```

## Bonus Challenge Problems

### 18. Multi-Stack Implementation
Implement multiple stacks in a single array efficiently. Support push, pop, and peek operations for k stacks.

### 19. Queue with Priority
Extend your queue implementation to support priority-based insertion while maintaining the queue property for elements with the same priority.

### 20. Memory-Efficient Stack
Design a stack that uses O(1) extra memory to support getMin() operation, even more efficiently than the Min Stack problem.

---

## Evaluation Criteria

**Easy Problems (20 points each)**
- Correct implementation: 15 points
- Code style and comments: 5 points

**Medium Problems (30 points each)**
- Algorithm correctness: 20 points
- Efficient use of data structures: 5 points
- Edge case handling: 5 points

**Hard Problems (50 points each)**
- Algorithm design and correctness: 30 points
- Optimal time/space complexity: 10 points
- Code quality and documentation: 10 points

**Time Limits**
- Easy: 15-20 minutes each
- Medium: 25-35 minutes each
- Hard: 45-60 minutes each

**Tips for Success**
1. Read the problem statement carefully
2. Plan your approach before coding
3. Test with the given examples
4. Consider edge cases (empty stack/queue, single element, etc.)
5. Use appropriate data structure methods from your implementation
6. Comment your code to explain the logic