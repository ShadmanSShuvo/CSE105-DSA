#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int candidate = a[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == candidate) count++;
        else count--;
        if (count == 0) {
            candidate = a[i];
            count = 1;
        }
    }

    // Verify candidate
    count = 0;
    for (int x : a)
        if (x == candidate) count++;

    if (count > n / 2) cout << candidate << endl;
    else cout << "No majority element\n";

    return 0;
}