#include<iostream>
using namespace std;

// Function to compute prefix sum and store it in the output array
void prefixSum(int arr[], int prefix[], int n){
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++){
        prefix[i] = prefix[i - 1] + arr[i];
    }
}

// Function to print an array
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    int prefix[n]; // declare output array
    prefixSum(arr, prefix, n);

    cout << "Prefix sum array: ";
    printArray(prefix, n);

    return 0;
}