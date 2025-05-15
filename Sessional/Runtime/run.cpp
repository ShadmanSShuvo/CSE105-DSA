#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int main(){
    int n=15;
    int x=1;
    for (int i = 0; i < n; i++)
    {
        for(int j=1; j<n; j=j*2){
            cout << x++ << " Hello World" << endl;
        }
    }
    
    return 0;
}