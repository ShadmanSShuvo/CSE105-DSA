#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    unordered_map<int, int> prefixIndex;
    int sum = 0, maxLen = 0;

    for (int i = 0; i < n; i++) {
        sum += (a[i] == 0) ? -1 : 1;

        if (sum == 0) maxLen = i + 1;
        else if (prefixIndex.count(sum))
            maxLen = max(maxLen, i - prefixIndex[sum]);
        else
            prefixIndex[sum] = i;
    }

    cout << maxLen << endl;
    return 0;
}