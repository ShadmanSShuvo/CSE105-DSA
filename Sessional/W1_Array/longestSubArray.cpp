#include<iostream>
using namespace std;

int longestSubArray(int arr[], int n){
    int maxLength = 0;
    int currentLength = 1;

    for(int i=1; i<n; i++){
        if(arr[i] == arr[i-1]){
            currentLength++;
        } else {
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
            currentLength = 1;
        }
    }
    // Check for the last segment
    if(currentLength > maxLength){
        maxLength = currentLength;
    }

    return maxLength;
}
int main(){
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = longestSubArray(arr, n);
    cout << "Length of longest subarray with same elements: " << result << endl;
    return 0;
}