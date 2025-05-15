#include<iostream>
using namespace std;

void leftRotation(int arr[], int n, int d){
    d = d % n; // In case d >= n
    int temp[d];
    
    // Store the first d elements in a temporary array
    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    
    // Shift the remaining elements to the left
    for(int i = 0; i < n - d; i++){
        arr[i] = arr[i + d];
    }
    
    // Copy the temporary array back to the end of the original array
    for(int i = 0; i < d; i++){
        arr[n - d + i] = temp[i];
    }
}
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2; // Number of positions to rotate
    cout << "Original array: ";
    printArray(arr, n);
    leftRotation(arr, n, d);
    cout << "Array after left rotation: ";
    printArray(arr, n);
    return 0;
}