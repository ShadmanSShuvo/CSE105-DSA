#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    for (int i = 0; i <= n - k; i++) {
        int maxVal = a[i];
        for (int j = 1; j < k; j++)
            maxVal = max(maxVal, a[i + j]);
        cout << maxVal << " ";
    }

    return 0;
}
