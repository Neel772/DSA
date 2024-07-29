#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
                q.push({0, {i, j}});
        }
    }
    cout << "main" << endl;
    int tim = INT_MIN;
    while (!q.empty())
    {
        int count = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        tim = max(tim, count);
        for (auto dir : directions)
        {
            int row = i + dir.first;
            int col = j + dir.second;
            if (row >= 0 && row < n && col >= 0 && col < m && grid[row][col] == 1)
            {
                q.push({count + 1, {row, col}});
            }
        }
    }
    return tim;
}

int main(){
    vector<vector<int>> grid = {{1, 1, 0}, {0, 1, 1}, {0, 1, 2}};
    cout << orangesRotting(grid);
}