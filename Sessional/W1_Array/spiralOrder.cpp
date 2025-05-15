#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    
    for (auto &row : a)
        for (int &x : row)
            cin >> x;

    int top = 0, bottom = r - 1, left = 0, right = c - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) cout << a[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++) cout << a[i][right] << " ";
        right--;
        if (top <= bottom)
            for (int i = right; i >= left; i--) cout << a[bottom][i] << " ";
        bottom--;
        if (left <= right)
            for (int i = bottom; i >= top; i--) cout << a[i][left] << " ";
        left++;
    }

    return 0;
}