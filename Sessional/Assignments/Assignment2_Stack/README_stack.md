
# Stack Implementations in C++

Two C++ stack implementations:

1. **ArrayStack** – Uses a dynamic array with auto-resizing  
2. **ListStack** – Uses a singly linked list

## 📂 Files

- `stack.h`: Stack ADT interface + class declarations  
- `arraystack.cpp`: Dynamic array-based stack with resizing (O(1) amortized ops)  
- `liststack.cpp`: Linked list-based stack with true O(1) ops  
- `test.cpp`: Test suite with edge cases, stress tests, and colored output

## 🛠️ Build & Run

```bash
g++ -std=c++11 arraystack.cpp liststack.cpp test.cpp -o stack_test
./stack_test
```

## 🔑 Features

### ArrayStack
- Doubles when ≥50% full, halves when ≤25%
- Amortized O(1) push/pop

### ListStack
- True O(1) operations
- No capacity limit, per-element memory overhead

## ✅ Testing

Tests:
- All core stack ops
- Edge/stress cases
- ArrayStack resizing

Runs on both implementations.

## 🧹 Memory & Errors

- Proper dynamic memory handling + destructors
- Throws `std::out_of_range` on invalid `pop()` / `top()`
