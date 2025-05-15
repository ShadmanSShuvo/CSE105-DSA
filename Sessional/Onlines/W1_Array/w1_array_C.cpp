#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int freq[n];
    for(int i = 0; i < n; i++){
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
       freq[a[i]]++;

    int max=freq[0];
    for (int i = 1; i < n; i++){
        if (freq[i] > max)
            max = i;
        
        if (freq[i] == max){
            cout << "No Majority Candidate" << endl;
            return 0;
        }

    }
    cout << max << endl;
    
    return 0;
}