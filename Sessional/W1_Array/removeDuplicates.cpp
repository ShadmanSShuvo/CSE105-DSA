#include<iostream>
using namespace std;

void removeDuplicates(int arr[], int &n){
    if(n == 0 || n == 1){
        return;
    }
    
    int j = 0; // Index of the next unique element
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }
    n = j + 1; // Update the size of the array
}
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[] = {1, 2, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    removeDuplicates(arr, n);
    
    cout << "Array after removing duplicates: ";
    printArray(arr, n);
    
    return 0;
}
