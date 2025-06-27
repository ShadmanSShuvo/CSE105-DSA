#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Heap {
private:
    vector<int> heap; // Array to store heap elements
    bool isMaxHeap;   // Flag to determine heap type: true for max-heap, false for min-heap

    // Helper functions for index calculations
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Heapify up to maintain heap property after insertion
    void heapifyUp(int i) {
        while (i > 0) {
            int p = parent(i);
            if (isMaxHeap) {
                if (heap[i] > heap[p]) {
                    swap(heap[i], heap[p]);
                    i = p;
                } else {
                    break;
                }
            } else {
                if (heap[i] < heap[p]) {
                    swap(heap[i], heap[p]);
                    i = p;
                } else {
                    break;
                }
            }
        }
    }

    // Heapify down to maintain heap property after extraction
    void heapifyDown(int i, int n) {
        int extremeIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (isMaxHeap) {
            if (left < n && heap[left] > heap[extremeIndex]) {
                extremeIndex = left;
            }
            if (right < n && heap[right] > heap[extremeIndex]) {
                extremeIndex = right;
            }
        } else {
            if (left < n && heap[left] < heap[extremeIndex]) {
                extremeIndex = left;
            }
            if (right < n && heap[right] < heap[extremeIndex]) {
                extremeIndex = right;
            }
        }

        if (i != extremeIndex) {
            swap(heap[i], heap[extremeIndex]);
            heapifyDown(extremeIndex, n);
        }
    }

public:
    // Constructor: Specify heap type (max or min)
    Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {}

    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Extract the root (max for max-heap, min for min-heap)
    int extract() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0, heap.size());
        }
        return result;
    }

    // Peek at the root without removing it
    int peek() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Check if heap is empty
    bool isEmpty() const {
        return heap.empty();
    }

    // Get the size of the heap
    int size() const {
        return heap.size();
    }

    // Build heap from an array
    void buildHeap(const vector<int>& arr) {
        heap = arr;
        for (int i = parent(heap.size() - 1); i >= 0; i--) {
            heapifyDown(i, heap.size());
        }
    }

    // Heap sort: Returns a sorted array (ascending for max-heap, descending for min-heap)
    vector<int> heapSort() {
        vector<int> originalHeap = heap; // Preserve original heap
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(extract());
        }
        heap = originalHeap; // Restore original heap
        return sorted;
    }

    // Print the heap
    void print() const {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // Test Max-Heap
    cout << "=== Max-Heap Demo ===" << endl;
    Heap maxHeap(true); // Create a max-heap
    cout << "Inserting: 10, 20, 15, 30, 40" << endl;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    cout << "Max-Heap: ";
    maxHeap.print(); // Expected: 40 30 15 10 20
    cout << "Peek: " << maxHeap.peek() << endl; // Expected: 40
    cout << "Extract: " << maxHeap.extract() << endl; // Expected: 40
    cout << "Max-Heap after extract: ";
    maxHeap.print(); // Expected: 30 20 15 10

    // Test heap sort with max-heap
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    cout << "\nBuilding max-heap from array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    maxHeap.buildHeap(arr);
    cout << "Max-Heap: ";
    maxHeap.print(); // Expected: 13 11 12 5 6 7
    vector<int> sortedMax = maxHeap.heapSort();
    cout << "Sorted (ascending): ";
    for (int val : sortedMax) {
        cout << val << " ";
    }
    cout << endl; // Expected: 5 6 7 11 12 13

    // Test Min-Heap
    cout << "\n=== Min-Heap Demo ===" << endl;
    Heap minHeap(false); // Create a min-heap
    cout << "Inserting: 10, 20, 15, 5, 30" << endl;
    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(5);
    minHeap.insert(30);
    cout << "Min-Heap: ";
    minHeap.print(); // Expected: 5 10 15 20 30
    cout << "Peek: " << minHeap.peek() << endl; // Expected: 5
    cout << "Extract: " << minHeap.extract() << endl; // Expected: 5
    cout << "Min-Heap after extract: ";
    minHeap.print(); // Expected: 10 20 15 30

    // Test heap sort with min-heap
    minHeap.buildHeap(arr);
    cout << "\nBuilding min-heap from array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    cout << "Min-Heap: ";
    minHeap.print(); // Expected: 5 6 12 11 7 13
    vector<int> sortedMin = minHeap.heapSort();
    cout << "Sorted (descending): ";
    for (int val : sortedMin) {
        cout << val << " ";
    }
    cout << endl; // Expected: 13 12 11 7 6 5

    return 0;
}