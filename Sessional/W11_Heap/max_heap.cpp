#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper functions to get indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Heapify up to maintain heap property after insertion
    void heapifyUp(int i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Heapify down to maintain heap property after deletion
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Extract and return the maximum element
    int extractMax() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return maxVal;
    }

    // Return the maximum element without removing it
    int peek() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Check if heap is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Get the size of the heap
    int size() {
        return heap.size();
    }

    // Build heap from an array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        for (int i = parent(heap.size() - 1); i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Heap sort: Sort the heap in ascending order
    vector<int> heapSort() {
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(extractMax());
        }
        return sorted;
    }

    // Print the heap
    void print() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    MaxHeap maxHeap;

    // Test insertion
    cout << "Inserting elements: 10, 20, 15, 30, 40" << endl;
    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    cout << "Heap after insertions: ";
    maxHeap.print(); // Expected: 40 30 15 10 20

    // Test peek
    cout << "Maximum element: " << maxHeap.peek() << endl; // Expected: 40

    // Test extract max
    cout << "Extracting max: " << maxHeap.extractMax() << endl; // Expected: 40
    cout << "Heap after extracting max: ";
    maxHeap.print(); // Expected: 30 20 15 10

    // Test building heap from array
    vector<int> arr = {4, 10, 3, 5, 1};
    cout << "\nBuilding heap from array: ";
    for (int val : arr) cout << val << " ";
    cout << endl;
    maxHeap.buildHeap(arr);
    cout << "Heap after building: ";
    maxHeap.print(); // Expected: 10 5 3 4 1

    // Test heap sort
    cout << "\nSorted array using heap sort: ";
    vector<int> sorted = maxHeap.heapSort();
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << endl; // Expected: 1 3 4 5 10

    return 0;
}