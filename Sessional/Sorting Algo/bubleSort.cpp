#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // optimization
    }
}

int main() {
    vector<int> a = {5, 3, 8, 4, 2};
    bubbleSort(a);
    for (int x : a) cout << x << " ";
    return 0;
}