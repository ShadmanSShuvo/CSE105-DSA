#include <bits/stdc++.h>
using namespace std;

void genBin(int n) {
    
    for (int i = 1; i <= n; i++) {
        string s;
        
        // Get Binary Representation of i
        for (int x = i; x; x >>= 1)
            s = (x & 1 ? "1" : "0") + s;
            
        cout << s << endl;
    }
}

int main() {
    genBin(100);
    return 0;
}