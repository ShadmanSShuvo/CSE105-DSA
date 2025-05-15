#include<iostream>
using namespace std;

void evenOddCount(int arr[], int n, int &evenCount, int &oddCount){
    evenCount = 0;
    oddCount = 0;
    for(int i=0; i<n; i++){
        if(arr[i] % 2 == 0){
            evenCount++;
        } else {
            oddCount++;
        }
    }
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int evenCount, oddCount;
    evenOddCount(arr, n, evenCount, oddCount);
    cout << "Even count: " << evenCount << endl;
    cout << "Odd count: " << oddCount << endl;
    return 0;
}