#include <bits/stdc++.h>
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>>directions = { {-1,0},{0,1},{1,0},{0,-1},{-1,-1},{-1,1},{1,1},{1,-1} };
    if (grid[n - 1][n - 1] == 1 || grid[0][0] == 1) {
        return -1;
    }
    vector<vector<int>>distance(n, vector<int>(n, 1e9));
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 1,{0,0} });
    distance[0][0] = 1;
    while (!pq.empty()) {
        int steps = pq.top().first;
        pair<int, int>node = pq.top().second;
        pq.pop();
        if (node == make_pair(n-1,n-1)) {
            return steps;
        }
        for (auto dir : directions) {
            int newRow = node.first + dir.first;
            int newCol = node.second + dir.second;
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && distance[newRow][newCol] > steps + 1) {
                distance[newRow][newCol] = steps + 1;
                pq.push({ steps + 1, {newRow,newCol} });
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>>grid = { {0,0,0},{1,1,0},{1,1,0} };
    cout << shortestPathBinaryMatrix(grid);
}