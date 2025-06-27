#include <iostream>
using namespace std;

// Heapify a subtree rooted at index i in array of size n
void heapify(int arr[], int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(int arr[], int n) {
    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root (largest) to end
        swap(arr[0], arr[i]);
        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function to test heap sort
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7,3,2,5,6,7,2,3,46,7,6,4,6,4,42,45,76,34,2,56,78,43,34,2,4,33,44,545,676,7878,798,989,93,456,76,88,8456,435,2,67,6,787,55,7,687,8,12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    heapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}