#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix){
    int n = matrix.size();
    if(n == 1)
        return matrix[0][0];
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}};
    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            int cell_min = INT_MAX;
            for (auto dir : directions)
            {
                int row = i + dir.first;
                int col = j + dir.second;
                if(row >=0 && row <n && col >=0 && col <n){
                    cell_min = min(cell_min, matrix[row][col] + matrix[i][j]);
                }
            }
            matrix[i][j] = cell_min;
            if(i == n-1){
                ans = min(ans, matrix[i][j]);
            }
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{1,2,10,4}, {100,3,2,1}, {1,1,20,3},{1,2,2,1}};
    cout << minFallingPathSum(matrix);
}