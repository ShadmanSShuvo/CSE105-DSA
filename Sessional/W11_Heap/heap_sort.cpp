#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    void heapifyDown(vector<int>& arr, int n, int i) {
        int maxIndex = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if (left < n && arr[left] > arr[maxIndex]) {
            maxIndex = left;
        }
        if (right < n && arr[right] > arr[maxIndex]) {
            maxIndex = right;
        }
        if (i != maxIndex) {
            swap(arr[i], arr[maxIndex]);
            heapifyDown(arr, n, maxIndex);
        }
    }
    
public:
    void heapSort(vector<int>& arr) {
        int n = arr.size();
        
        // Build max-heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(arr, n, i);
        }
        
        // Extract elements from heap
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapifyDown(arr, i, 0);
        }
    }
};

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    MaxHeap heap;
    heap.heapSort(arr);
    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl; // Output: 5 6 7 11 12 13
    return 0;
}