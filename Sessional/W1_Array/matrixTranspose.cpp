#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> mat(r, vector<int>(c));
    
    for (auto &row : mat)
        for (int &x : row)
            cin >> x;

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++)
            cout << mat[i][j] << " ";
        cout << endl;
    }

    return 0;
}