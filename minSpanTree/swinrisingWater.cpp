#include <bits/stdc++.h>
using namespace std;

int swimInWater(vector<vector<int>> &grid){
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({grid[0][0], {0, 0}});
    visited[0][0] = true;
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int mx = INT_MIN;
    while(!pq.empty()){
        int t = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        mx = max(mx, t);
        if(x == n-1 && y == n-1)
            break;
        for (auto dir : directions)
        {
            int row = x + dir.first;
            int col = y + dir.second;
            if(row >=0 && row <n && col >=0 && col < n && !visited[row][col]){
                visited[row][col] = true;
                pq.push({grid[row][col], {row, col}});
            }
        }
    }
    return mx;
}

int main(){
    vector<vector<int>> grid = {{0,2},{1,3}};
    cout << swimInWater(grid);
}