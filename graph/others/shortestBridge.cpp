#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int i, int j, vector<vector<bool>> &v, int n, int m, vector<vector<int>> &grid)
{
    grid[i][j] = 2;
    v[i][j] = true;
    for (auto dir : d)
    {
        int r = i + dir.first;
        int c = j + dir.second;
        if (r >= 0 && r < n && c >= 0 && c < m && !v[r][c] && grid[i][j] == 1)
        {
            dfs(r, c, v, n, m, grid);
        }
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> v(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(i, j, v, n, m, grid);
                break;
            }
        }
    }
    queue<vector<int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, i, j});
            }
        }
    }
    int ans = INT_MAX;
    while (!q.empty())
    {
        int i = q.front()[1];
        int j = q.front()[2];
        int steps = q.front()[0];
        q.pop();
        for (auto dir : d)
        {
            int r = i + dir.first;
            int c = j + dir.second;
            if (r >= 0 && r < n && c >= 0 && c < m)
            {
                if (grid[r][c] == 1)
                    return steps;
                else if (!v[r][c] && grid[r][c] == 0)
                {
                    v[r][c] = true;
                    q.push({steps + 1, r, c});
                }
            }
        }
    }
    return 0;
}

int main(){
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}};
    cout << shortestBridge(grid);
}