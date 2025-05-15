#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c, sum = 0;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));

    for (auto &row : a)
        for (int &x : row)
            cin >> x;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1)
                sum += a[i][j];

    cout << sum << endl;
    return 0;
}