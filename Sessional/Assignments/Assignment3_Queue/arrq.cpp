#include <iostream>
#include <string>

class Arrq {
private:
    int* data;
    int capacity;
    int front_idx;
    int rear_idx;

    void resize(int new_capacity) {
        int* new_data = new int[new_capacity];
        int current_size = (rear_idx - front_idx + capacity) % capacity + (rear_idx >= front_idx ? 0 : 1);
        if (current_size > 0) {
            for (int i = 0; i < current_size; ++i) {
                new_data[i] = data[(front_idx + i) % capacity];
            }
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
        front_idx = (current_size > 0) ? 0 : 1;
        rear_idx = (current_size > 0) ? current_size - 1 : 0;
    }

public:
    Arrq(int capacity = 2) {
        this->capacity = (capacity < 2) ? 2 : capacity;
        data = new int[this->capacity];
        front_idx = 1;
        rear_idx = 0;
    }

    ~Arrq() {
        delete[] data;
    }

    void enqueue(int value) override {
        if ((rear_idx + 1) % capacity == front_idx) {
            resize(capacity * 2);
        }
        rear_idx = (rear_idx + 1) % capacity;
        data[rear_idx] = value;
    }

    int dequeue() override {
        if (empty()) {
            throw std::runtime_error("Queue is empty! Cannot dequeue");
        }
        int value = data[front_idx];
        front_idx = (front_idx + 1) % capacity;
        // Shrink if size is less than 1/4 of capacity and capacity > 2
        int current_size = (rear_idx - front_idx + capacity) % capacity + (rear_idx >= front_idx ? 0 : 1);
        if (current_size < capacity / 4 && capacity > 2) {
            resize(capacity / 2);
        }
        return value;
    }

    void clear() override {
        front_idx = 1;
        rear_idx = 0;
        if (capacity > 2) {
            resize(2);
        }
    }

    int front() const override {
        if (empty()) {
            throw std::runtime_error("Queue is empty! Cannot access front");
        }
        return data[front_idx];
    }

    int back() const override {
        if (empty()) {
            throw std::runtime_error("Queue is empty! Cannot access back");
        }
        return data[rear_idx];
    }

    bool empty() const override {
        return front_idx == (rear_idx + 1) % capacity;
    }

    int size() const override {
        return (rear_idx - front_idx + capacity) % capacity + (rear_idx >= front_idx ? 0 : 1);
    }

    std::string toString() const override {
        std::string result = "[";
        if (!empty()) {
            int current_size = (rear_idx - front_idx + capacity) % capacity + (rear_idx >= front_idx ? 0 : 1);
            for (int i = 0; i < current_size; ++i) {
                result += std::to_string(data[(front_idx + i) % capacity]);
                if (i < current_size - 1) {
                    result += ", ";
                }
            }
        }
        result += "]";
        return result;
    }

    int getCapacity() const {
        return capacity;
    }
};

// Example usage (same as before)
int main() {
    ArrayQueue q(2);
    q.enqueue(1);
    q.enqueue(2);
    std::cout << "Queue: " << q.toString() << ", Size: " << q.size() << ", Capacity: " << q.getCapacity() << std::endl;
    q.enqueue(3); // Triggers resize
    std::cout << "After enqueue(3): " << q.toString() << ", Size: " << q.size() << ", Capacity: " << q.getCapacity() << std::endl;
    std::cout << "Front: " << q.front() << ", Back: " << q.back() << std::endl;
    std::cout << "Dequeued: " << q.dequeue() << std::endl;
    std::cout << "Queue: " << q.toString() << ", Size: " << q.size() << ", Capacity: " << q.getCapacity() << std::endl;
    q.clear();
    std::cout << "After clear: " << q.toString() << ", Size: " << q.size() << ", Capacity: " << q.getCapacity() << std::endl;
    try {
        q.dequeue(); // Should throw exception
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
```