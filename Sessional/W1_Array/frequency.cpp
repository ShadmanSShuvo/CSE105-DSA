#include<iostream>
using namespace std;

void frequency(int arr[], int n){
    int freq[100] = {0}; // Assuming the elements are in the range 0-99
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }
    cout << "Element Frequency" << endl;
    for(int i=0; i<100; i++){
        if(freq[i] > 0){
            cout << i << " " << freq[i] << endl;
        }
    }
}
int main(){
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    frequency(arr, n);
    
    return 0;
}