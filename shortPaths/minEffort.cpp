#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector < pair<int, int>>directions = { {-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>>distance(m, vector<int>(n, 1e9));
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({ 0,{0,0} });
    distance[0][0] = 0;
    while (!q.empty()) {
        int diff = q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();
        if (row == m - 1 && col == n - 1) {
            return diff;
        }
        for (auto dir : directions) {
            int newRow = row + dir.first;
            int newCol = col + dir.second;
            if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                int newDiff = max(abs(heights[newRow][newCol] - heights[row][col]), diff);

                if (newDiff < distance[newRow][newCol]) {
                    distance[newRow][newCol] = newDiff;
                    q.push({ newDiff,{newRow,newCol} });
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>>heights = { {1,2,3},{6,5,4},{7,8,9} };
    cout << minimumEffortPath(heights);
}