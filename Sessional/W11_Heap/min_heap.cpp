#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }
        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }
        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minVal;
    }

    int peek() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }

    void print() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    MinHeap minHeap;

    cout << "Inserting elements: 10, 20, 15, 5, 30" << endl;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(30);
    cout << "Min-Heap: ";
    minHeap.print(); // Expected: 5 10 15 20 30

    cout << "Minimum element: " << minHeap.peek() << endl; // Expected: 5
    cout << "Extracting min: " << minHeap.extractMin() << endl; // Expected: 5
    cout << "Min-Heap after extraction: ";
    minHeap.print(); // Expected: 10 20 15 30

    return 0;
}