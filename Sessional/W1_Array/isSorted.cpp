#include<iostream>
using namespace std;

bool isSorted(int arr[], int n){
    bool ascending = true;
    bool descending = true;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            descending=false;
        }
        else if(arr[i] > arr[i-1]){
            ascending=false;
        }
        // else{
        //     ascending = false;
        //     descending = false;
        // }

    }
    if(ascending){
        return true;
    }
    else if(descending){
        return true;
    }
    else{
        return false;
    }
    // return (ascending || descending);
    // return (ascending && descending);
}


int main(){
    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {5,4,3,2,1};
    //int arr[] = {1,11,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << "Is sorted: " << (isSorted(arr, n) ? "Yes" : "No") << endl;

    return 0;
}