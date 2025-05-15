#include<iostream>
using namespace std;

int linSearch(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        if(arr[i] == x){
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
}
int main(){
    int arr[] = {1, 2, 3, 4, 5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 7; // Element to search for
    int index = linSearch(arr, n, x);
    if(index != -1){
        cout << "Element " << x << " found at index: " << index << endl;
    } else {
        cout << "Element " << x << " not found in the array." << endl;
    }
    return 0;
}