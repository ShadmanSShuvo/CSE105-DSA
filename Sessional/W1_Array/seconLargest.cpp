#include<iostream>
using namespace std;

void secondLargest(int arr[], int n, int &secondLargest){
    int largest = INT_MIN;
    secondLargest = INT_MIN;
    
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int secondLargestValue;
    secondLargest(arr, n, secondLargestValue);
    cout << "Second largest element: " << secondLargestValue << endl;
    
    return 0;
}
