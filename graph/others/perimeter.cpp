#include <bits/stdc++.h>
using namespace std;


int islandPerimeter(vector<vector<int>> &grid)
{
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int pm = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int count = 0;
                for (auto it : directions)
                {
                    int row = i + it.first;
                    int col = j + it.second;
                    if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1)
                    {
                        count++;
                    }
                }
                pm += (4-count);
            }
        }
    }
    return pm;
}

int main(){
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    cout << islandPerimeter(grid);
}