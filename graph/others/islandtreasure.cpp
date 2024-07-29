#include <bits/stdc++.h>
using namespace std;

int INF = 2 ^ 31 - 1;

vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void islandsAndTreasure(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if(grid[i][j] == 0)
                q.push({i, j});
        }
    }
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        for(auto dir : directions){
            int row = i + dir.first;
            int col = j + dir.second;
            if (row >= 0 && row < n && col >=0 && col < m && grid[row][col] == INF){
                grid[row][col] = min(grid[row][col], 1 + grid[i][j]);
                q.push({row, col});
            }
        }
    }
}

int main(){
    vector<vector<int>> grid = {{INF, -1, 0, INF}, {INF, INF, INF, -1}, {INF, -1, INF, -1}, {0, -1, 0, 0}};
    islandsAndTreasure(grid);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}