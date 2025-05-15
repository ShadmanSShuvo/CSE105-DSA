# Stack Implementations in C++

This project provides two implementations of the Stack abstract data type (ADT):
1. `ArrayStack` - Uses a dynamic array with automatic resizing
2. `ListStack` - Uses a singly linked list

## Files

1. `stack.h` - Header file containing:
   - Stack ADT interface
   - ArrayStack and ListStack class declarations
   - Documentation comments

2. `arraystack.cpp` - Implementation of ArrayStack:
   - Uses dynamic array storage
   - Automatically resizes when capacity limits are reached
   - Provides O(1) amortized time complexity for push/pop

3. `liststack.cpp` - Implementation of ListStack:
   - Uses linked list nodes
   - Constant time O(1) operations for all stack methods
   - Dynamic memory allocation per element

4. `test.cpp` - Comprehensive test suite:
   - Tests all stack operations
   - Includes edge case and stress tests
   - Provides colored output for test results

## Building and Running

1. Compile all source files:
    `g++ -std=c++11 arraystack.cpp liststack.cpp test.cpp -o stack_test`

2. Run the test program:
    ./stack_test


## Key Features

### ArrayStack
- Automatic resizing when:
- Array becomes 50% full (expands to double capacity)
- Array becomes less than 25% full (shrinks to half capacity)
- Efficient memory usage for dense stacks
- Amortized constant time operations

### ListStack
- True O(1) time complexity for all operations
- No fixed capacity limits
- Slightly higher memory overhead per element
- Clean implementation using linked nodes

## Testing

The test suite verifies:
- Basic stack operations (push, pop, top)
- Size and empty checks
- Clear functionality
- Multiple operations in sequence
- Empty stack edge cases
- ArrayStack resizing behavior
- Stress tests with large numbers of operations

All tests are run automatically against both implementations.

## Memory Management

Both implementations properly handle memory:
- ArrayStack manages dynamic array allocation
- ListStack manages individual node allocation
- Destructors ensure all memory is freed
- Clear methods properly reset the stacks

## Error Handling

Both implementations throw `std::out_of_range` exceptions for:
- pop() on empty stack
- top() on empty stack

This provides consistent error handling behavior.