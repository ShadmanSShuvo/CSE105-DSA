#include<iostream>
using namespace std;
int countPairs(int arr[], int n, int k){
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == k){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8; // Target sum
    int result = countPairs(arr, n, k);
    cout << "Number of pairs with sum " << k << ": " << result << endl;
    return 0;
}