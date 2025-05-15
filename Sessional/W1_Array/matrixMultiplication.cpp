#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    if (c1 != r2) {
        cout << "Invalid dimensions\n";
        return 0;
    }

    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));
    vector<vector<int>> C(r1, vector<int>(c2, 0));

    for (auto &row : A) for (int &x : row) cin >> x;
    for (auto &row : B) for (int &x : row) cin >> x;

    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    for (auto &row : C) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}