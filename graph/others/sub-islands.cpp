#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool dfs(int i, int j, vector<vector<bool>> &visited, int n, int m, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    visited[i][j] = true;
    bool check = true;
    for (auto dir : directions)
    {
        int row = i + dir.first;
        int col = j + dir.second;
        if (row >= 0 && row < n && col >= 0 && col < m && !visited[row][col] && grid2[row][col] == 1)
        {
            check = check && dfs(row, col, visited, n, m, grid1, grid2);
        }
    }
    if (grid1[i][j] != grid2[i][j])
        return false;
    return check;
}
int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{
    int n = grid1.size();
    int m = grid1[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid2[i][j] == 1 && !visited[i][j])
            {
                if (dfs(i, j, visited, n, m, grid1, grid2))
                {
                    count++;
                }
            }
        }
    }
    return count;
}


int main(){
    vector<vector<int>> grid1 = {{ 1, 0, 1, 0, 1 }, 
                                 { 1, 1, 1, 1, 1 },
                                 { 0, 0, 0, 0, 0 }, 
                                 { 1, 1, 1, 1, 1 }, 
                                 { 1, 0, 1, 0, 1 }};
    vector<vector<int>> grid2 = {{ 0, 0, 0, 0, 0 }, 
                                 { 1, 1, 1, 1, 1 }, 
                                 { 0, 1, 0, 1, 0 }, 
                                 { 0, 1, 0, 1, 0 }, 
                                 { 1, 0, 0, 0, 1 }};
    cout<<countSubIslands(grid1, grid2);
}