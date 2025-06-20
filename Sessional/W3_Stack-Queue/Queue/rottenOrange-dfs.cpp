// C++ Program to find the minimum time
// in which all oranges will get rotten
#include <bits/stdc++.h>
using namespace std;

// Check if i, j is within the array
// limits of row and column
bool isSafe(int i, int j, int n, int m)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// function to perform dfs and find fresh orange
void dfs(vector<vector<int>> &mat, int i, int j, int time)
{
    int n = mat.size();
    int m = mat[0].size();

    // update minimum time
    mat[i][j] = time;

    // all four directions
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    // change 4-directionally connected cells
    for (auto dir : directions)
    {
        int x = i + dir[0];
        int y = j + dir[1];

        // if cell is in the matrix and
        // the orange is fresh
        if (isSafe(x, y, n, m) && (mat[x][y] == 1 || mat[x][y] > time + 1))
        {
            dfs(mat, x, y, time + 1);
        }
    }
}

int orangesRotting(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // counter of elapsed time
    int elapsedTime = 0;

    // iterate through all the cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // if orange is initiall rotten
            if (mat[i][j] == 2)
            {
                dfs(mat, i, j, 2);
            }
        }
    }
    // iterate through all the cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            // if orange is fresh
            if (mat[i][j] == 1)
                return -1;

            // update the maximum time
            elapsedTime = max(elapsedTime, mat[i][j] - 2);
        }
    }
    return elapsedTime;
}

int main()
{   
    vector<vector<int>> mat = {{2, 1, 0, 2, 1}, {1, 0, 1, 2, 1}, {1, 0, 0, 2, 1}};
    cout << orangesRotting(mat);
    return 0;
}

// O(n x m) Time and O(1) Space
