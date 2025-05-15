#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c, key;
    cin >> r >> c >> key;
    vector<vector<int>> mat(r, vector<int>(c));

    for (auto &row : mat)
        for (int &x : row)
            cin >> x;

    int i = 0, j = c - 1;
    while (i < r && j >= 0) {
        if (mat[i][j] == key) {
            cout << "Found at (" << i << ", " << j << ")\n";
            return 0;
        } else if (mat[i][j] > key) j--;
        else i++;
    }

    cout << "Not found\n";
    return 0;
}