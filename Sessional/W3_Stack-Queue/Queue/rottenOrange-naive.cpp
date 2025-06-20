#include <bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, int n, int m) {
    return 0 <= i && i < n && 0 <= j && j < m;
}

int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    // to check if any changes are made
    bool changed;

    // counter of elapsed time
    int elapsedTime = 0;

    // all four directions
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // iterate until changes are there
    while (true) {
        changed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // check if the cell was marked in last iteration
                if (mat[i][j] == elapsedTime + 2) {
                    // change 4-directionally connected cells
                    for (const auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        // if cell is in the matrix and the orange is fresh
                        if (isSafe(x, y, n, m) && mat[x][y] == 1) {
                            mat[x][y] = mat[i][j] + 1;
                            changed = true;
                        }
                    }
                }
            }
        }
        // if no changes are done
        if (!changed) {
            break;
        }
        elapsedTime++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // if any orange is found not rotten, return -1
            if (mat[i][j] == 1) {
                return -1;
            }
        }
    }

    return elapsedTime;
}

int main() {
    vector<vector<int>> mat = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
    cout << orangesRotting(mat) << endl;
    return 0;
}
// Time Complexity: O((n*m)^2)
// Space Complexity: O(1)