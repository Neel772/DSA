#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void dfs(int i, int j, vector<vector<bool>> &visited, int n, int m, vector<vector<char>> &grid)
{
    visited[i][j] = true;
    for (auto dir : directions)
    {
        int row = i + dir.first;
        int col = j + dir.second;
        if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == '1' && !visited[row][col])
        {
            dfs(row, col, visited, n, m, grid);
        }
    }
}

int numIslands (vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                count++;
                dfs(i, j, visited, n, m, grid);
            }
        }
    }
    return count;
}

int main(){
    vector<vector<char>> grid = {{'1', '1', '0', '0', '1'},
                                 {'1', '1', '0', '0', '1'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};
    cout << numIslands(grid);
}